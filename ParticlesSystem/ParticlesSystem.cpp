#include "ParticlesSystem.h"

Particle::Particle() :
	_position(vec3(0)), _velocity(vec3(0)),_color(vec3(0)), _life(0) {}

Particle::Particle(const vec3& pos, const vec3& velocity, const vec3& color, int life) :
_position(pos), _velocity(velocity), _color(color), _life(__max(life, 0)) {}

void Particle::update(bool need_gravity)
{
	// Update particle's movement according to environment
	if(need_gravity)
	 _velocity = _velocity - Environment::get_instance().get_gravity() + Environment::get_instance().get_wind();
	else
		_velocity = _velocity + Environment::get_instance().get_wind();
	 //printf("%f, %f, %f\n", _velocity[0], _velocity[1], _velocity[2]);

	// Update particle's position according to movement
	_position += _velocity;
	// Update particle's age
	_life++;
}


ParticlesSystem::ParticlesSystem()
{
}


ParticlesSystem::~ParticlesSystem()
{
}
