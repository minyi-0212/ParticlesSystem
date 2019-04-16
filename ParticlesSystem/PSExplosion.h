#pragma once
#include "ParticlesSystem.h"
class PSExplosion :
	public ParticlesSystem
{
public:
	PSExplosion();
	PSExplosion(vec3& postion, vec3& color);
	~PSExplosion();
	virtual bool update() override;
	
protected:
	virtual Particle GenerateParticle() override;

private:
	static const int DEFAULT_NUM_PARTICLES = 1;
};