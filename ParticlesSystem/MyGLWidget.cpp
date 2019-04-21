#include "myglwidget.h"
#include <GL/glu.h>

MyGLWidget::MyGLWidget(QWidget *parent) : QGLWidget(parent)
{

}

void MyGLWidget::initializeGL()
{
	//gluLookAt(10, 0, 0, 0, 0, 0, 0, 1, 0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_BLEND);
}

void MyGLWidget::resizeGL(int w, int h) //glutReshapeFunc
{
	GLfloat fRatio = (GLfloat)w / (GLfloat)h;
	GLfloat nRange = 10.0f;
	glViewport(0, 0, (GLint)w, (GLint)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(85, (GLfloat)w / (GLfloat)h, 0.1, 200);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void MyGLWidget::paintGL() //glutDisplayFunc
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glPointSize(10.f);
	if (_ps!= nullptr)
	{
		if (_ps->need_texuture)
		{
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture);
			for (auto p : _ps->_particles)
			{
				glLoadIdentity();
				glTranslatef(p.get_position()[0], p.get_position()[1], p.get_position()[2]);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
				glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
				glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
				glEnd();
			}
			glDisable(GL_TEXTURE_2D);
		}
		else
		{
			/*glBegin(GL_POINTS);
			for (auto p : _ps->_particles)
			{
				glVertex3f(p.get_position()[0], p.get_position()[1], p.get_position()[2]);
			}
			glEnd();*/

			float x, y, z;
			for (auto p : _ps->_particles)
			{
				//printf("%f, %f, %f\n", p.get_position()[0], p.get_position()[1], p.get_position()[2]);
				glColor3f(p.get_color()[0], p.get_color()[1], p.get_color()[2]);
				glBegin(GL_TRIANGLE_STRIP);
				x = p.get_position()[0], y = p.get_position()[1], z = p.get_position()[2];
				glTexCoord2d(1, 1); glVertex3f(x + 0.5f, y + 0.5f, z);
				glTexCoord2d(0, 1); glVertex3f(x - 0.5f, y + 0.5f, z);
				glTexCoord2d(1, 0); glVertex3f(x + 0.5f, y - 0.5f, z);
				glTexCoord2d(0, 0); glVertex3f(x - 0.5f, y - 0.5f, z);
				glEnd();
			}
		}
	}

	/*glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, -50.0f);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, -1.0f, 1.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, 1.0f, 1.0f);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, 1.0f, 1.0f);
	glEnd();
	glDisable(GL_TEXTURE_2D);*/

	glFlush();
}

#include "SOIL.h"
bool MyGLWidget::load_texture(const char* pic)
{
	texture = SOIL_load_OGL_texture
	(
		pic,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_INVERT_Y
	);
	if (texture == 0)
	{
		printf("load texture failed.\n");
		return false;
	}
	else
	{
		//printf("load texture success.\n");
		return true;
	}
}