#include <time.h> 
#include "PSFountain.h"

PSFountain::PSFountain()
{
	srand((unsigned)time(NULL));
	_center_position = vec3(0);
	_default_color = vec3(0);
	_particle_max_life = 80;
	for (int i = 0; i < DEFAULT_NUM_PARTICLES; i++)
	{
		_particles.push_back(generate_particle());
	}
}

PSFountain::PSFountain(vec3& postion, vec3& color)
{
	srand((unsigned)time(NULL));
	_center_position = postion;
	_default_color = color;
	_particle_max_life = 80;
	for (int i = 0; i < DEFAULT_NUM_PARTICLES; i++)
	{
		_particles.push_back(generate_particle());
	}
}

PSFountain::~PSFountain()
{
}

bool PSFountain::update()
{
	// For each particle
	for (auto& iter = _particles.begin(); iter!= _particles.end();)
	{
		// Update particle and check age
		(*iter).update();
		//printf("life: %d\n", (*iter).get_life());
		if ((*iter).get_life() > _particle_max_life)
		{
			// Remove old particles
			//_particles.erase(iter++);
			*iter = generate_particle();
		}
		else
		{
			iter++;
		}
	}
	// If there are no more particles in the system
	/*printf("%d\n", _particles.size());
	if (_particles.size() <= DEFAULT_NUM_PARTICLES)
		_particles.push_back(generate_particle());*/

	return true;
}

Particle PSFountain::generate_particle()
{
	// Generate random direction & speed for new particle: ([-0.2 ~ 0.3](the width), [0 ~ 0.5], [-0.4 ~ 0.6])
	float rndX = 1 + 0.5 * (rand_double - 0.4f),
		rndY = 3 + rand_double,
		rndZ = 2 *(rand_double - 0.4f);
	//printf("%f, %f, %f\n", rndX, rndY, rndZ);

	// Create new particle at system's starting position
	Particle part(_center_position + vec3(rand_double, rand_double, rand_double),
		// With generated direction and speed
		vec3(rndX, rndY, rndZ), /*vec3(rand_double, rand_double, rand_double)*/ _default_color,
		// And a random starting life
		rand() % _particle_max_life);

	// Return newly created particle
	return part;
}