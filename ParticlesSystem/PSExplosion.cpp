#include <time.h> 
#include "PSExplosion.h"

PSExplosion::PSExplosion()
{
	srand((unsigned)time(NULL));
	_center_position = vec3(0);
	_default_color = vec3(0);
	for (int i = 0; i < DEFAULT_NUM_PARTICLES; i++)
	{
		_particles.push_back(GenerateParticle());
	}
}

PSExplosion::PSExplosion(vec3& postion, vec3& color)
{
	srand((unsigned)time(NULL));
	_center_position = postion;
	_default_color = color;
	for (int i = 0; i < DEFAULT_NUM_PARTICLES; i++)
	{
		_particles.push_back(GenerateParticle());
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
		printf("life: %d\n", (*iter).get_life());
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

Particle PSExplosion::GenerateParticle()
{
	// Generate random direction & speed for new particle
	float rndX = 2 * (rand() % 10 / 10.0 - 0.5f),
		rndY = 2 * (rand() % 10 / 10.0 - 0.5f),
		rndZ = 2 * (rand() % 10 / 10.0 - 0.5f);
	printf("%f, %f, %f", rndX, rndY, rndZ);

	// Create new particle at system's starting position
	Particle part(_center_position,
		// With generated direction and speed
		vec3(rndX, rndY, rndZ), _default_color,
		// And a random starting life
		rand() % _particle_max_life);

	// Return newly created particle
	return part;
}