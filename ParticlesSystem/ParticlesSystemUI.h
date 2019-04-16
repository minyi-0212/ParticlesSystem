#pragma once

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_ParticlesSystem.h"

class ParticlesSystemUI : public QMainWindow
{
	Q_OBJECT

public:
	ParticlesSystemUI(QWidget *parent = Q_NULLPTR);

private:
	Ui::ParticlesSystemClass ui;
	QTimer *timer;
	std::shared_ptr<ParticlesSystem> _ps;
	//ParticlesSystem* _ps;

private slots:
	void ButtonExplosion_clicked();
	void timer_update();

signals:
	void changed(bool);
};
