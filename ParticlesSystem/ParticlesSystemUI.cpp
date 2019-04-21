#include "ParticlesSystemUI.h"
#define time_interval 50
ParticlesSystemUI::ParticlesSystemUI(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	Environment::get_instance().set_gravity(vec3(0.0, 9.8 * time_interval / 5000, 0));
	Environment::get_instance().set_wind(vec3(0.002, 0, 0));
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(timer_update()));
	// the QGLWidget update
	connect(this, SIGNAL(changed(bool)), ui.openGLWidget, SLOT(updateGL()));
	// buttons
	connect(ui.ButtonExplosion, SIGNAL(clicked()), this, SLOT(button_explosion_clicked()));
	connect(ui.ButtonFountain, SIGNAL(clicked()), this, SLOT(button_fountain_clicked()));
	connect(ui.ButtonFirework, SIGNAL(clicked()), this, SLOT(button_firework_clicked()));
	connect(ui.ButtonLeaf, SIGNAL(clicked()), this, SLOT(button_leaf_clicked()));
	connect(ui.ButtonRipple, SIGNAL(clicked()), this, SLOT(button_ripple_clicked()));
	connect(ui.ButtonStop, SIGNAL(clicked()), this, SLOT(button_stop_clicked()));
}

void ParticlesSystemUI::timer_update()
{
	if (!_ps->update())
	{
		timer->stop();
		//btn_ptr->setText("explosion");
		btn_ptr->setDisabled(false);
		ui.openGLWidget->ps_reset();
		//delete _ps;
		_ps = nullptr;
	}
	//else
	//{
	//	//printf("s: %d\n", _ps->particles_count());
	//	btn_ptr->setText(QString::number(_ps->particles_count()));
	//}
	emit changed(true);
}

void ParticlesSystemUI::button_explosion_clicked()
{
	_ps = std::make_shared<PSExplosion>(vec3(1, 50, -100), vec3(125 / 255.0, 125 / 255.0, 0));
	ui.openGLWidget->ps_init(_ps);
	if(btn_ptr)
		btn_ptr->setDisabled(false);
	btn_ptr = ui.ButtonExplosion;
	btn_ptr->setDisabled(true);
	timer->start(time_interval);
}

void ParticlesSystemUI::button_fountain_clicked()
{
	_ps = std::make_shared<PSFountain>(vec3(-50, -50, -100), vec3(202 / 255.0, 235 / 255.0, 216 / 255.0));
	ui.openGLWidget->ps_init(_ps);
	if (btn_ptr)
		btn_ptr->setDisabled(false);
	btn_ptr = ui.ButtonFountain;
	btn_ptr->setDisabled(true);
	timer->start(time_interval);
}

void ParticlesSystemUI::button_firework_clicked()
{
	_ps = std::make_shared<PSFirework>(vec3(1, -70, -100), vec3(202 / 255.0, 235 / 255.0, 216 / 255.0));
	ui.openGLWidget->ps_init(_ps);
	if (btn_ptr)
		btn_ptr->setDisabled(false);
	btn_ptr = ui.ButtonFirework;
	btn_ptr->setDisabled(true);
	timer->start(time_interval);
}

void ParticlesSystemUI::button_leaf_clicked()
{
	_ps = std::make_shared<PSLeaf>(vec3(1, 50, -50), vec3(202 / 255.0, 235 / 255.0, 216 / 255.0));
	ui.openGLWidget->ps_init(_ps);
	ui.openGLWidget->load_texture("./image/maple_leaf.png");
	if (btn_ptr)
		btn_ptr->setDisabled(false);
	btn_ptr = ui.ButtonLeaf;
	btn_ptr->setDisabled(true);
	timer->start(time_interval);
}

void ParticlesSystemUI::button_ripple_clicked()
{
	_ps = std::make_shared<PSRipple>(vec3(50, -50, -100), vec3(202 / 255.0, 235 / 255.0, 216 / 255.0));
	ui.openGLWidget->ps_init(_ps);
	if (btn_ptr)
		btn_ptr->setDisabled(false);
	btn_ptr = ui.ButtonRipple;
	btn_ptr->setDisabled(true);
	timer->start(time_interval);
}

void ParticlesSystemUI::button_stop_clicked()
{
	if(btn_ptr)
		btn_ptr->setDisabled(false);
	ui.openGLWidget->ps_reset();
	//delete _ps;
	_ps = nullptr;
	timer->stop();
	//emit changed(true);
}