#include<stdlib.h>
#include<iostream>
#include<cmath>

#ifdef __linux__
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#else
#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<GLUT/GLUT.h>
#endif

using namespace std;

#define PI 3.14

int k = 1;
static GLfloat spinAngle = 0.0;
static bool isSpinning = false;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glRotatef(spinAngle, 0.0, 0.0, 1.0);

    glColor3f(0.47, 0.35, 0.86);
    glBegin(GL_LINE_STRIP);
    for (int i = 0; i <= 360; i++) {
        float theta = PI*i / 180;
        float x = cos(k * theta) * cos(theta);
        float y = cos(k * theta) * sin(theta);
        glVertex2f(x, y);    
    }
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay() {
    spinAngle = spinAngle + 3;
    if (spinAngle > 360.0) 
        spinAngle -= 360.0;
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
}

void handleMouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) {
                k++;
                glutPostRedisplay();
            }
            break;
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN && k > 1) {
                k--;
                glutPostRedisplay();
            }
            break;
        default:
            break;
    } 
}

void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 32:
            if (isSpinning == false) {
                glutIdleFunc(spinDisplay);
            }
            else {
                glutIdleFunc(NULL);
            }
            isSpinning = !isSpinning;
            break;
        case 27:
            exit(0);
        default:
            break;
    }
}

int main(int argc, char** argv) { 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rose");

    init();
	glutMouseFunc(handleMouse); 
    glutKeyboardFunc(handleKeyboard);   
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
