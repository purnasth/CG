#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <windows.h>
#include <GL/glut.h>
#endif
#include <stdio.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

void display(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glLineWidth(3);
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 1.0);
    glVertex2f(0.2, 0.7);
    glVertex2f(0.2, -0.5);
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(10, 10);
    glutInitWindowSize(500, 500);
    glutCreateWindow("****Purna Shrestha****");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}