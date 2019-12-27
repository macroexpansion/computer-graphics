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

static GLfloat spinAngle = 0.0;
static bool isSpinning = false;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glRotatef(spinAngle, 0.0, 0.0, 1.0);
    glRectf(-25, -25, 25, 25);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.47, 0.35, 0.86);
    glBegin(GL_TRIANGLES);
    glVertex3f(-10, 5, 0);
    glVertex3f(10, 5, 0);
    glVertex3f(0, 15, 0);
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

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        case 32:
            if (isSpinning == false) {
                glutIdleFunc(spinDisplay);
            }
            else {
                glutIdleFunc(NULL);
            }
            isSpinning = !isSpinning;
            break;
        default:
            break;
    }
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
}

void handleMouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN) 
                glutIdleFunc(spinDisplay);
            break;

        case GLUT_MIDDLE_BUTTON:
            if (state == GLUT_DOWN) {
                glutIdleFunc(NULL);
            }
            break;

        default:
            break;
    }
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(650, 450);
    glutCreateWindow("Rectangle");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutReshapeFunc(reshape);
    glutMouseFunc(handleMouse);

    glutMainLoop();

    return 0;
}
