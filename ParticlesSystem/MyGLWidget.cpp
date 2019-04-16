#include "myglwidget.h"
#include <GL/glu.h>

MyGLWidget::MyGLWidget(QWidget *parent) : QGLWidget(parent)
{

}

void MyGLWidget::initializeGL()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
}

void MyGLWidget::resizeGL(int w, int h) //glutReshapeFunc
{
	glViewport(0, 0, (GLint)w, (GLint)h);
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 0.1, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/
}

void MyGLWidget::paintGL() //glutDisplayFunc
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/*glLoadIdentity();

	glTranslatef(-2.0, 0.0, -6.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(0.0, -1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glEnd();

	glTranslatef(4.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex3f(-1.0, 1.0, 0.0);
	glVertex3f(-1.0, -1.0, 0.0);
	glVertex3f(1.0, -1.0, 0.0);
	glVertex3f(1.0, 1.0, 0.0);
	glEnd();*/

	glLoadIdentity();
	glPointSize(10.f);
	glColor3f(10,0,0);
	if (_ps!= nullptr)
	{
		printf("tt\n");
		glBegin(GL_POINTS);
		for (auto p : _ps->_particles) 
		{
			printf("%f, %f, %f", p.get_position()[0], p.get_position()[1], p.get_position()[2]);
			glVertex3f(p.get_position()[0], p.get_position()[1], p.get_position()[2]);
		}
		glEnd();
	}

	glColor3f(0, 10, 0);
	glBegin(GL_POINTS);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glFlush();
}
