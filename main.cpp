#include <stdlib.h>

#ifdef __linux__
#include<iostream>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#else
#include<OpenGL/gl.h>
#include<OpenGL/glu.h>
#include<GLUT/GLUT.h>
#endif

using namespace std;

#define WIDTH 640
#define HEIGHT 480

void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
    }
}

void awesomeInit() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void awesomeDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);
    glColor4f(1.0, 0.0, 0.0, 0.5);
    glVertex3f(0.35, 0.88, 0.0);
    glVertex3f(0.5, 0.3, 0.0);
    glVertex3f(0.18, 0.28, 0.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor4f(0.1063213, 0.824, 0.255, 0.5);
    glVertex3f(0.4, 0.23, 0.0);
    glVertex3f(0.8, 0.23, 0.0);
    glVertex3f(0.6, 0.8, 0.0);
    
    glVertex3f(0.4, 0.23, 0.0);
    glVertex3f(0.6, 0.8, 0.0);
    glVertex3f(0.2, 0.7, 0.0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("main");

    awesomeInit();
    glutDisplayFunc(awesomeDisplay);
    glutKeyboardFunc(handleKeypress);

    const unsigned char* glVer = glGetString(GL_VERSION);
    cout << glVer << endl;
    
    glutMainLoop();

    return 0;
}
