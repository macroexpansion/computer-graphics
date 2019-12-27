#include <stdio.h>
#include <GL/glut.h>
#include <math.h>

GLfloat x_old =- 0, y_old = 0;

int n = 5;
static GLfloat spin = 0.0;
static int pressed = 0.0;

void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);    
}


void reshape(int w, int h){
    glViewport(0,0,(GLsizei) w,(GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void display() { 
    int i = 0; 
    float x,y;
    
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin,0.0,0.0,1.0);
    glColor3f(1.0,1.0,1.0);
    
    glBegin(GL_LINES);
    glVertex2f(-100,0);
    glVertex2f (100, 0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0,-100);
    glVertex2f(0,100);
    glEnd();

    glBegin(GL_POINTS);
    int radCount = 10;
    for(int i = -360*radCount;i < 360*radCount; i++){
        x = (float)i;
        x= x/180; 
        y = sin(x);
        glVertex2f(x/5,y/5);
    }
    glEnd();

    for(int i = -50 ; i < 50 ; i++){
        float x = (float)i;

        glBegin(GL_LINES);
        glVertex2f(x/10,0.02);
        glVertex2f(x/10,-0.02);
        glEnd();
    }
    for(int i = -50 ; i < 50 ; i++){
        float y = (float)i;

        glBegin(GL_LINES);
        glVertex2f(0.02,y/10);
        glVertex2f(-0.02,y/10);
        glEnd();
    }

    glPopMatrix();
    glFlush();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv); 
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);      
    glutInitWindowSize(500,500);        
    glutInitWindowPosition(0,0); 
    glutCreateWindow("rose");
    
    init();     
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}