#pragma once
#include "ParticlesSystem.h"
class PSFountain :
	public ParticlesSystem
{
public:
	PSFountain();
	PSFountain(vec3& postion, vec3& color);
	~PSFountain();
	virtual bool update() override;
	
protected:
	virtual Particle generate_particle() override;

private:
	static const int DEFAULT_NUM_PARTICLES = 5000;
};