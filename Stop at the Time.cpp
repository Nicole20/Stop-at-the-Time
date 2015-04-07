// atTime at the Time.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<glut.h>
#include<freeglut.h>
#include<ctime>

using namespace std;

void initialize();
void draw();
void drawLedgend();
void drawTime();
void mouse(int button, int state, int x, int y);

char *numbers = { "0123456789" };
char *atTime = { "Stop at  seconds.:" };
char *stop = { "Stop" };
char *start = { "Start" };
char *reset = { "Reset" };

clock_t time_b = 0;
clock_t time_e = 0;
int sec = 0;
int milli = 0;
int time_rand;

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Stop at the Time");

	initialize();

	glutDisplayFunc(draw);
	glutMouseFunc(mouse);

	glutMainLoop();

	return 0;
}

void initialize()
{
	glClearColor(1, 1, 1, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, 6, 0, 3);
}

void draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0, 0);
	glLineWidth(1);

	drawLedgend();
	drawTime();

	glBegin(GL_LINE_LOOP);
	glVertex2f(2.5, 1.9);
	glVertex2f(2.5, 2.3);
	glVertex2f(3.4, 2.3);
	glVertex2f(3.4, 1.9);
	glEnd();

	glLineWidth(5);

	glColor3f(0, 0.8, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(1.6, 0.9);
	glVertex2f(1.6, 1.3);
	glVertex2f(2.3, 1.3);
	glVertex2f(2.3, 0.9);
	glEnd();

	glColor3f(0.8, 0, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(2.6, 0.9);
	glVertex2f(2.6, 1.3);
	glVertex2f(3.25, 1.3);
	glVertex2f(3.25, 0.9);
	glEnd();

	glColor3f(0, 0, 0.8);
	glBegin(GL_LINE_LOOP);
	glVertex2f(3.6, 0.9);
	glVertex2f(3.6, 1.3);
	glVertex2f(4.35, 1.3);
	glVertex2f(4.35, 0.9);
	glEnd();

	glutPostRedisplay();
	glFlush();
}

void drawLedgend()
{
	glRasterPos2f(2.2, 2.5);

	for (int i = 0; i < 8; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, atTime[i]);
	}

	if (time_rand < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[time_rand]);
	}
	else
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[time_rand / 10]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[time_rand % 10]);
	}

	for (int i = 8; i < 17; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, atTime[i]);
	}

	glRasterPos2f(1.7, 1);

	for (int i = 0; i < 5; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, start[i]);
	}

	glRasterPos2f(2.7, 1);

	for (int i = 0; i < 4; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, stop[i]);
	}

	glRasterPos2f(3.7, 1);

	for (int i = 0; i < 5; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, reset[i]);
	}
}

void drawTime()
{
	glRasterPos2f(2.7, 2);

	if (sec < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[0]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[sec]);
	}
	else
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[sec / 10]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[sec % 10]);
	}

	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, atTime[17]);

	if (milli < 10)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[0]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[milli]);
	}
	else
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[milli / 10]);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, numbers[milli % 10]);
	}
}

void mouse(int button, int state, int x, int y)
{
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			if (y > 170 && y < 210)
			{
				if (x > 160 && x < 230)  //Start
				{
					time_b = clock();
				}
				else if (x > 260 && x < 330)  //Stop
				{
					time_e = clock();
					sec = (time_e - time_b)/1000;
					milli = time_e - time_b - sec*1000;
					milli = milli / 10;
					cout << time_b << " " << time_e << " " << sec<< " "<< milli << endl;
				}
				else if (x > 360 && x < 435)  //Reset
				{
					srand(time(NULL));
					time_rand = rand() % 10 + 1;
					time_b = 0;
					time_e = 0;
					sec = 0;
					milli = 0;
				}
			}
		}
	}
}
