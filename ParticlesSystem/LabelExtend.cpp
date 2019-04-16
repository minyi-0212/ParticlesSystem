#include <QPainter>
#include <QPoint>
#include "LabelExtend.h"

void LabelExtend::paintEvent(QPaintEvent *event)
{
	Q_UNUSED(event)

	// this 表示在Widget部件内部绘制
	QPainter painter(this);

	// 使用画笔，参数为：画刷，线宽，画笔风格，画笔端点，画笔连接风格
	QPen pen(Qt::green, 5, Qt::DotLine, Qt::RoundCap, Qt::RoundJoin);
	painter.setPen(pen);

	// 使用画笔画线
	painter.drawLine(QPoint(0, 0), QPoint(100, 100));

	// 画矩形，参数：x,y,w,h
	painter.drawRect(110, 110, 100, 80);

	// 绘制椭圆(圆)，参数：x,y,w,h
	painter.drawEllipse(20, 20, 100, 80);

	// 绘制圆弧
	{
		QRectF rect(110.0, 80.0, 100.0, 80.0); //x,y,w,h
		int startAngle = 30 * 16; //值为，实际角度 * 16
		int spanAngle = 120 * 16;
		painter.drawArc(rect, startAngle, spanAngle); // 参数：rect表示弧线所在的矩形，startAngle起始角度，spanAngle跨越角度
	}

	// 绘制扇形
	{
		QRectF rect_top(120.0, 20.0, 100.0, 100.0);
		int startAngle = 0 * 16;  // 扇形起始角度
		int spanAngle = 120 * 16;  // 扇形覆盖范围（120度的）
		painter.drawPie(rect_top, startAngle, spanAngle);
	}

	// 绘制多边形
	{
		QPolygon pts;
		pts.setPoints(3, 250, 20, 300, 80, 280, 130); //第一个参数表示3个点，后面是三个点坐标
		painter.drawConvexPolygon(pts);
	}

	// 绘制路径
	{
		QPainterPath path;
		path.addEllipse(400, 100, 80, 80);//添加一个圆
		path.addRect(400, 130, 100, 100); //添加一个矩形

		// 使用笔刷，设置颜色和填充模式
		QBrush brush(QColor(0, 0, 255), Qt::Dense4Pattern);
		painter.setBrush(brush);
		path.setFillRule(Qt::WindingFill); // 非零弯曲规则；此外还有 Qt::OddEventFil 奇偶填充规则

		painter.drawPath(path);
	}
}