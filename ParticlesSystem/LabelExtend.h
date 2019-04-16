#pragma once
#include <qwidget.h>
class LabelExtend :
	public QWidget
{
public:
	LabelExtend(QWidget *parent = 0) : QWidget(parent) {}
	~LabelExtend() {}

protected:
	void paintEvent(QPaintEvent *event);
};

