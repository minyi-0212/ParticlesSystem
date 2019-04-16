#include <QPainter>
#include <QPoint>
#include "LabelExtend.h"

void LabelExtend::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event)

	// this ��ʾ��Widget�����ڲ�����
	QPainter painter(this);

	// ʹ�û��ʣ�����Ϊ����ˢ���߿����ʷ�񣬻��ʶ˵㣬�������ӷ��
	QPen pen(Qt::green, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
	painter.setPen(pen);

	// ʹ�û��ʻ���
	painter.drawLine(QPoint(0, 0), QPoint(100, 100));

	// �����Σ�������x,y,w,h
	painter.drawRect(110, 110, 100, 80);

	// ������Բ(Բ)��������x,y,w,h
	painter.drawEllipse(20, 20, 100, 80);

	// ����Բ��
	{
		QRectF rect(110.0, 80.0, 100.0, 80.0); //x,y,w,h
		int startAngle = 30 * 16; //ֵΪ��ʵ�ʽǶ� * 16
		int spanAngle = 120 * 16;
		painter.drawArc(rect, startAngle, spanAngle); // ������rect��ʾ�������ڵľ��Σ�startAngle��ʼ�Ƕȣ�spanAngle��Խ�Ƕ�
	}

	// ��������
	{
		QRectF rect_top(120.0, 20.0, 100.0, 100.0);
		int startAngle = 0 * 16;  // ������ʼ�Ƕ�
		int spanAngle = 120 * 16;  // ���θ��Ƿ�Χ��120�ȵģ�
		painter.drawPie(rect_top, startAngle, spanAngle);
	}

	// ���ƶ����
	{
		QPolygon pts;
		pts.setPoints(3, 250, 20, 300, 80, 280, 130); //��һ��������ʾ3���㣬����������������
		painter.drawConvexPolygon(pts);
	}

	// ����·��
	{
		QPainterPath path;
		path.addEllipse(400, 100, 80, 80);//���һ��Բ
		path.addRect(400, 130, 100, 100); //���һ������

		// ʹ�ñ�ˢ��������ɫ�����ģʽ
		QBrush brush(QColor(0, 0, 255), Qt::Dense4Pattern);
		painter.setBrush(brush);
		path.setFillRule(Qt::WindingFill); // �����������򣻴��⻹�� Qt::OddEventFil ��ż������

		painter.drawPath(path);
	}
}