#include <time.h> 
#include "PSExplosion.h"

PSExplosion::PSExplosion()
{
	srand((unsigned)time(NULL));
	_center_position = vec3(0);
	_default_color = vec3(0);
	_particle_max_life = 40;
	for (int i = 0; i < DEFAULT_NUM_PARTICLES; i++)
	{
		_particles.push_back(generate_particle());
	}
}

PSExplosion::PSExplosion(vec3& postion, vec3& color)
{
	srand((unsigned)time(NULL));
	_center_position = postion;
	_default_color = color;
	_particle_max_life = 40;
	for (int i = 0; i < DEFAULT_NUM_PARTICLES; i++)
	{
		_particles.push_back(generate_particle());
	}
}

PSExplosion::~PSExplosion()
{
}

bool PSExplosion::update()
{
	// For each particle
	for (auto iter = _particles.begin(); iter!= _particles.end();)
	{
		// Update particle and check age
		(*iter).update();
		//printf("life: %d\n", (*iter).get_life());
		if ((*iter).get_life() > _particle_max_life)
		{
			// Remove old particles
			_particles.erase(iter++);
		}
		else
		{
			iter++;
		}
	}
	// If there are no more particles in the system
	if (_particles.size() <= 0)
		return false;
	return true;
}

Particle PSExplosion::generate_particle()
{
	// Generate random direction & speed for new particle: ([-1 ~ 1], [-1 ~ 1], [-1 ~ 1])
	float rndX = 2 * (rand_double - 0.5f),
		rndY = 2 * (rand_double - 0.5f),
		rndZ = 2 * (rand_double - 0.5f);
	//printf("%f, %f, %f\n", rndX, rndY, rndZ);

	// Create new particle at system's starting position
	Particle part(_center_position+ vec3(rand_double/10, rand_double/10, rand_double/10),
		// With generated direction and speed
		vec3(rndX, rndY, rndZ), /*vec3(rand_double, rand_double, rand_double)*/ _default_color,
		// And a random starting life
		rand() % _particle_max_life);

	// Return newly created particle
	return part;
}