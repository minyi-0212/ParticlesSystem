#pragma once
#include "ParticlesSystem.h"
class PSRipple :
	public ParticlesSystem
{
public:
	PSRipple();
	PSRipple(vec3& postion, vec3& color);
	~PSRipple();
	virtual bool update() override;
	
protected:
	virtual Particle generate_particle() override;

private:
	static const int DEFAULT_NUM_PARTICLES = 500;
};