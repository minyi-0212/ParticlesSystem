#pragma once
#include <list>
#include <glm/glm.hpp>
#include "Environment.h"
#define rand_double (float)rand() / RAND_MAX
using std::list;
using glm::vec3;


class Particle
{
public:
	Particle();
	Particle(const vec3& pos, const vec3& velocity, const vec3& color, int life);
	vec3 get_position() { return _position; }
	vec3 get_velocity() { return _velocity; }
	vec3 get_color() { return _color; }
	int get_life() { return _life; }
	virtual void update();

private:
	vec3 _position, _velocity, _color;
	int _life;
};

class ParticlesSystem
{
public:
	ParticlesSystem();
	~ParticlesSystem();
	virtual bool update() = 0;
	int particles_count() const {
		return _particles.size();
	};
	list<Particle> _particles;

protected:
	virtual Particle generate_particle() = 0;

	bool _need_regenerate;
	vec3 _center_position, _default_color;
	int _particle_max_life = 100;
};

