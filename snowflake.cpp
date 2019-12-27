// #include <windows.h>
#include <cmath>
#include <GL/glut.h>

#define PI 3.14

GLfloat x_old = 0;
GLfloat y_old = 0;
int n = 0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void drawKoch(GLfloat degree, GLfloat length, GLfloat n) {
    GLfloat theta = PI * degree / 180;
    GLfloat x_new = x_old + length * cos(theta);
    GLfloat y_new = y_old + length * sin(theta);
    
    if (n == 0) {
        glVertex2f(x_old, y_old);
        glVertex2f(x_new, y_new);
        
        x_old = x_new;
        y_old = y_new;
    } else {
        n--;
        length /= 3;
        drawKoch(degree, length, n);
        
        degree += 60;
        drawKoch(degree, length, n);
        
        degree -= 120;
        drawKoch(degree,length, n);
        
        degree += 60;
        drawKoch(degree, length, n);
    }
}

void display() {
    int i = 0;
    i++;
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    glBegin(GL_LINES);
        x_old = -1;
        y_old = 0;
        drawKoch(0, 1, n);
        x_old = -0.5;
        y_old = -sqrt(3) / 2;
        drawKoch(120, 1, n);
        x_old = 0;
        y_old = 0;
        drawKoch(240, 1, n);
    glEnd();

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 1, -1, 1, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
        default:
            break;
    }
}

void handleMouse(int button, int state, int x, int y) {
    switch (button) {
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN) {
                n++;
                glutPostRedisplay();
            }
            break;
        case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN && n > 0) {
                n--;
                glutPostRedisplay();
            }
            break;
        default:
            break;
    } 
}

int main(int argc, char** argv) { 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(650, 450);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Snowflake");

    init();
	glutMouseFunc(handleMouse);    
    glutKeyboardFunc(handleKeyboard);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

    return 0;
}
