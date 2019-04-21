#define _USE_MATH_DEFINES
#include <windows.h>
#include <time.h> 
#include "PSFirework.h"

PSFirework::PSFirework()
{
	srand((unsigned)time(NULL));
	_center_position = vec3(0);
	_default_color = vec3(0);
	_particle_max_life = 20;
}

PSFirework::PSFirework(vec3& postion, vec3& color)
{
	srand((unsigned)time(NULL));
	_center_position = postion;
	_default_color = color;
	_particle_max_life = 20;
}

PSFirework::~PSFirework()
{
}

bool PSFirework::update()
{
	// For each particle
	for (auto& iter = _particles.begin(); iter!= _particles.end();)
	{
		// Update particle and check age
		(*iter).update();
		// find the origin_fire
		auto fire_iter = std::find(_particles_fire.begin(), _particles_fire.end(), iter);
		if (fire_iter != _particles_fire.end() && ((*iter).get_life() > _particle_max_life || (*iter).get_position()[1] > 50))
		{
			int NUM_PARTICLES = 250 + rand() % 10 * 10;
			for (int i = 0; i < DEFAULT_NUM_PARTICLES; i++)
			{
				_particles.push_back(generate_boom_particle(iter->get_position(), iter->get_color(), i / NUM_PARTICLES, i % NUM_PARTICLES * 1.0 / NUM_PARTICLES));
			}
			_particles.erase(iter++);
			_particles_fire.erase(fire_iter);
		}
		// not the origin_fire
		else if ((*iter).get_life() > _particle_max_life)
			_particles.erase(iter++);
		else
		{
			iter++;
		}
	}
	// If there are no more particles in the system
	/*printf("%d\n", _particles.size());*/
	if (_particles.size() <= 4 && rand() % 100 > 80)
	{
		_particles.push_back(generate_particle());
		_particles_fire.push_back(--_particles.end());
	}

	return true;
}

Particle PSFirework::generate_particle()
{
	// Generate random direction & speed for new particle:
	float rndX = 10 * (rand_double - 0.5f),
		rndY = 5 + 2 * rand_double,
		rndZ = 2 * (rand_double - 0.5f);
	//printf("%f, %f, %f\n", rndX, rndY, rndZ);

	// Create new particle at system's starting position
	Particle part(_center_position + vec3(rand_double, rand_double, rand_double),
		// With generated direction and speed
		vec3(rndX, rndY, rndZ), vec3(rand_double, rand_double, rand_double),
		// And a random starting life
		rand() % (_particle_max_life/4));

	// Return newly created particle
	return part;
}

Particle PSFirework::generate_boom_particle(vec3& pos, vec3& color, float r, float theta)
{
	// Generate random direction & speed for new particle: ([-1 ~ 1], [-1 ~ 1], [-1 ~ 1])
	float rndX = r * cos(M_PI * 2 * theta) + rand_double,
		rndY = r * sin(M_PI * 2 * theta) + rand_double,
		rndZ = rand_double;
	/*float rndX = 2 * (rand_double - 0.5f),
		rndY = 2 * (rand_double - 0.5f),
		rndZ = 2 * (rand_double - 0.5f);*/
	//printf("%f, %f, %f\n", rndX, rndY, rndZ);

	// Create new particle at system's starting position
	Particle part(pos + vec3(rand_double, rand_double, rand_double),
		// With generated direction and speed
		vec3(rndX, rndY, rndZ), /*vec3(rand_double, rand_double, rand_double)*/ color,
		// And a random starting life
		rand() % _particle_max_life);

	// Return newly created particle
	return part;
}