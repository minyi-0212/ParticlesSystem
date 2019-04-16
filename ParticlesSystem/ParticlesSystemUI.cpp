#include "ParticlesSystemUI.h"

ParticlesSystemUI::ParticlesSystemUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timer_update()));
	connect(this, SIGNAL(changed(bool)), ui.openGLWidget, SLOT(update_particles()));
	connect(ui.ButtonExplosion, SIGNAL(clicked()), this, SLOT(ButtonExplosion_clicked()));
}

void ParticlesSystemUI::timer_update()
{
	ui.ButtonExplosion->setText("T");
	if (!_ps->update())
	{
		timer->stop();
		ui.ButtonExplosion->setText("explosion");
		ui.ButtonExplosion->setDisabled(false);
		ui.openGLWidget->paintGL();
		//delete _ps;
		_ps = nullptr;
	}
	else
	{
		//emit changed(true);
		//printf("s: %d\n", _ps->particles_count());
		ui.ButtonExplosion->setText(QString::number(_ps->particles_count()));
	}
}

void ParticlesSystemUI::ButtonExplosion_clicked()
{
	//_ps = new PSExplosion(vec3(650 / 2, 470 / 2, 0), vec3(0, 0, 255));
	_ps = std::make_shared<PSExplosion>(vec3(650 / 2, 470 / 2, 0), vec3(0, 0, 255));
	ui.openGLWidget->ps_init(_ps);
	timer->start(1000);
	ui.ButtonExplosion->setDisabled(true);
}