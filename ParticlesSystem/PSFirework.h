#pragma once
#include "ParticlesSystem.h"
class PSFirework :
	public ParticlesSystem
{
public:
	PSFirework();
	PSFirework(vec3& postion, vec3& color);
	~PSFirework();
	virtual bool update() override;
	
protected:
	virtual Particle generate_particle() override;
	Particle generate_boom_particle(vec3& pos, vec3& color, float r, float theta);

private:
	static const int DEFAULT_NUM_PARTICLES = 1000;
	list<list<Particle>::iterator> _particles_fire;
};