#include <math.h>
#include <cstdlib>
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>

using namespace std;

void plot(int ix, int iy) {
	glPointSize(1);
	glBegin(GL_POINTS);
	glVertex2i(ix, iy);
	glEnd();
}

void circuloPtoMedio(int x0, int y0, int r) {
	int hm, x, y;
	hm = 5 / 4 - r; x = 0;
	y = -r;
	plot(x0, y0 + r);
	plot(x0, y0 - r);
	plot(x0 + r, y0);
	plot(x0 - r, y0);
	while (x < -(y + 1)) {
		if (hm < 0)
			hm = hm + 2 * x + 3;
		else {
			hm = hm + 2 * x + 2 * y + 5;
			y = y + 1;
		}
		x = x + 1;
		plot(x0 + x, y0 + y);
		plot(x0 + x, y0 - y);
		plot(x0 - x, y0 + y);
		plot(x0 - x, y0 - y);
		plot(x0 + y, y0 + x);
		plot(x0 + y, y0 - x);
		plot(x0 - y, y0 + x);
		plot(x0 - y, y0 - x);
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	circuloPtoMedio(250, 250, 50);
	

	glBegin(GL_LINES);
	glVertex2f(250, 250);
	glVertex2f(336.6, 198.97059667);
	glEnd();
	glFlush();
}
void myinit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 499.0, 0.0, 499.0);
}
void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(44, 44);
	glutCreateWindow("Algoritmo de circulo");
	glutDisplayFunc(display);
	myinit();
	glutMainLoop();
}