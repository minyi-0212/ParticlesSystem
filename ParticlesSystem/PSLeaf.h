#pragma once
#include "ParticlesSystem.h"
class PSLeaf :
	public ParticlesSystem
{
public:
	PSLeaf();
	PSLeaf(vec3& postion, vec3& color);
	~PSLeaf();
	virtual bool update() override;
protected:
	virtual Particle generate_particle() override;

private:
	static const int DEFAULT_NUM_PARTICLES = 100;
};