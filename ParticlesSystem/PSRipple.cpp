#define _USE_MATH_DEFINES
#include <windows.h>
#include <time.h> 
#include "PSRipple.h"

PSRipple::PSRipple()
{
	srand((unsigned)time(NULL));
	_center_position = vec3(0);
	_default_color = vec3(0);
	_particle_max_life = 200;
	generate_particle();
}

PSRipple::PSRipple(vec3& postion, vec3& color)
{
	srand((unsigned)time(NULL));
	_center_position = postion;
	_default_color = color;
	_particle_max_life = 200;
	generate_particle();
}

PSRipple::~PSRipple()
{
}

static int count = 0;
bool PSRipple::update()
{
	// For each particle
	count++;
	for (auto& iter = _particles.begin(); iter != _particles.end();)
	{
		// Update particle and check age
		(*iter).update(false);
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
	if (count % 10 == 0 && count < 10 * 10)
	{
		generate_particle();
	}
	// If there are no more particles in the system
	if (_particles.size() <= 0)
		return false;
	return true;
}

Particle PSRipple::generate_particle()
{
	// Generate random direction & speed for new particle:
	Particle part;
	int NUM_PARTICLES = 25 + rand() % 10;
	for (int i = 0; i < NUM_PARTICLES; i++)
	{
		float theta = i % NUM_PARTICLES * 1.0 / NUM_PARTICLES,
			rndX = 2 * (cos(M_PI * 2 * theta) - 0.7),
			rndY = sin(M_PI * 2 * theta),
			rndZ = 0;
		//printf("%f, %f, %f\n", rndX, rndY, rndZ);

		// Create new particle at system's starting position
		part = Particle(_center_position,
			// With generated direction and speed
			vec3(rndX, rndY, rndZ), _default_color,
			// And a random starting life
			rand() % (_particle_max_life / 4));
		_particles.push_back(part);
	}
	
	// Return newly created particle
	return part;
}