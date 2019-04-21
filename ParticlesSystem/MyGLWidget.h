#pragma once
#include <QWidget>
#include <QGLWidget>
#include <memory.h>
#include "PSExplosion.h"
#include "PSFountain.h"

class MyGLWidget : public QGLWidget
{
	Q_OBJECT
public:
	explicit MyGLWidget(QWidget *parent = 0);
	void ps_init(std::shared_ptr<ParticlesSystem> ps) { _ps = ps; }
	void ps_reset() { _ps = nullptr; }
	//void ps_init(ParticlesSystem* ps) {_ps = ps;}
	void paintGL();

signals:

protected:
	void initializeGL();
	void resizeGL(int w, int h);
	std::shared_ptr<ParticlesSystem> _ps;
	//ParticlesSystem* _ps;

public slots:
	void update_particles() { printf("test\n"); }
};