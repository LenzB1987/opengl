// TriangularPrism.cpp : Defines the entry point for the console application.
//
// Writen by Lenz B 
// The traiangular prism
#include "stdafx.h"
#include <gl\glut.h>
float thetaY = 0;
void triangularPrism() {
 // front
 glBegin(GL_POLYGON);
 glColor3f(1, 0, 0);
 glVertex3f(0.0, 0.5, 0.5);
 glVertex3f(-0.5, -0.5, 0.5);
 glVertex3f(0.5, -0.5, 0.5);
 glEnd();
 // side
 glBegin(GL_POLYGON);
 glColor3f(0, 1, 0);
 glVertex3f(0.0, 0.5, 0.5);
 glVertex3f(0.5, -0.5, 0.5);
 glVertex3f(0.5, -0.5, -0.5);
 glVertex3f(0.0, 0.5, -0.5);
 glEnd();
 // back
 glBegin(GL_POLYGON);
 glColor3f(0, 0, 1);
 glVertex3f(0.0, 0.5, -0.5);
 glVertex3f(-0.5, -0.5, -0.5);
 glVertex3f(0.5, -0.5, -0.5);
 glEnd();
}
void display() {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
 // TRS go here
 glRotatef(thetaY, 0, 1, 0);
 triangularPrism();
 glFlush();
}
void keyboard(unsigned char key, int x, int y) {
 if (key == 'y')
 thetaY = thetaY + 5;
 else if (key == 'Y')
 thetaY = thetaY - 5;
 glutPostRedisplay();
}
int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitWindowSize(600, 400);
 glutInitWindowPosition(100, 100); 
 glutCreateWindow("Triangular Prism");
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH ); 
 glEnable(GL_DEPTH_TEST);
 glMatrixMode(GL_PROJECTION);
 glOrtho(1, 1, 1, 1, 0, 2);
 glutDisplayFunc( display );
 glutKeyboardFunc( keyboard );
 glutMainLoop();
 return 0;
}