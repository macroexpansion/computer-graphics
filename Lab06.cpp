#define GL_SILENCE_DEPRECATION
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <cmath>
#include <windows.h>

using namespace std;


float** A;
float** B;
float** wheel01;
float** wheel02;
float** window01;
float** window02;
const int MAX_N = 8;
const int MAX_M = 24;
const float deltat = 0.001;

void init ( void ) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	int numberOfVertexs = 8;
	
	A = new float*[8];
	B = new float*[8];
	
	for (int i = 0; i < MAX_N ; ++i) {
		A[i] = new float[2];
		B[i] = new float[2];
	}
	wheel01 = new float*[MAX_M+1];
	wheel02 = new float*[MAX_M+1];
	window01 = new float*[MAX_M+1];
	window02 = new float*[MAX_M+1];
	
	for (int i = 0; i <= MAX_M ; ++i) {
		wheel01[i] = new float[2];
		wheel02[i] = new float[2];
		window01[i] = new float[2];
		window02[i] = new float[2];
	}

	
	A[0][0] = 600.0; A[0][1] = 300.0;
	A[1][0] = 500.0; A[1][1] = 335.0;
	A[2][0] = 310.0; A[2][1] = 400.0;
	A[3][0] = 310.0; A[3][1] = 400.0;
	A[4][0] = 185.0; A[4][1] = 350.0;
	A[5][0] = 040.0; A[5][1] = 300.0;
	A[6][0] = 040.0; A[6][1] = 040.0;
	A[7][0] = 600.0; A[7][1] = 040.0;
	
	
	B[0][0] = 600.0; B[0][1] = 300.0;
	B[1][0] = 450.0; B[1][1] = 300.0;
	B[2][0] = 400.0; B[2][1] = 350.0;
	B[3][0] = 200.0; B[3][1] = 350.0;
	B[4][0] = 150.0; B[4][1] = 300.0;
	B[5][0] = 040.0; B[5][1] = 300.0;
	B[6][0] = 040.0; B[6][1] = 200.0;
	B[7][0] = 600.0; B[7][1] = 200.0;
	
	
	for (int i =0; i <= 24; i++) {
		float angle =  2 * M_PI * i / (24);
		wheel01[i][0] = 75 * cos(angle) + 200;
		wheel01[i][1] = 75 * sin(angle) + 200;
		wheel02[i][0] = 75 * cos(angle) + 450;
		wheel02[i][1] = 75 * sin(angle) + 200;
	}
	
	
    window01[ 0][0] = 275.0; window01[ 0][1] = 200.0;
    window01[ 1][0] = 275.0; window01[ 1][1] = 225.0;
    window01[ 2][0] = 275.0; window01[ 2][1] = 250.0;
    window01[ 3][0] = 275.0; window01[ 3][1] = 275.0;
    window01[ 4][0] = 250.0; window01[ 4][1] = 275.0;
    window01[ 5][0] = 225.0; window01[ 5][1] = 275.0;
    window01[ 6][0] = 200.0; window01[ 6][1] = 275.0;
    window01[ 7][0] = 175.0; window01[ 7][1] = 275.0;
    window01[ 8][0] = 150.0; window01[ 8][1] = 275.0;
    window01[ 9][0] = 125.0; window01[ 9][1] = 275.0;
    window01[10][0] = 125.0; window01[10][1] = 250.0;
    window01[11][0] = 125.0; window01[11][1] = 225.0;
    window01[12][0] = 125.0; window01[12][1] = 200.0;
    window01[13][0] = 125.0; window01[13][1] = 175.0;
    window01[14][0] = 125.0; window01[14][1] = 150.0;
    window01[15][0] = 125.0; window01[15][1] = 125.0;
    window01[16][0] = 150.0; window01[16][1] = 125.0;
    window01[17][0] = 175.0; window01[17][1] = 125.0;
    window01[18][0] = 200.0; window01[18][1] = 125.0;
    window01[19][0] = 225.0; window01[19][1] = 125.0;
    window01[20][0] = 250.0; window01[20][1] = 125.0;
    window01[21][0] = 275.0; window01[21][1] = 125.0;
    window01[22][0] = 275.0; window01[22][1] = 150.0;
    window01[23][0] = 275.0; window01[23][1] = 175.0;
    window01[24][0] = 275.0; window01[24][1] = 200.0;
    
    window02[ 0][0] = 275 + 250; window02[ 0][1] = 200;
    window02[ 1][0] = 275 + 250; window02[ 1][1] = 225;
    window02[ 2][0] = 275 + 250; window02[ 2][1] = 250;
    window02[ 3][0] = 275 + 250; window02[ 3][1] = 275;
    window02[ 4][0] = 250 + 250; window02[ 4][1] = 275;
    window02[ 5][0] = 225 + 250; window02[ 5][1] = 275;
    window02[ 6][0] = 200 + 250; window02[ 6][1] = 275;
    window02[ 7][0] = 175 + 250; window02[ 7][1] = 275;
    window02[ 8][0] = 150 + 250; window02[ 8][1] = 275;
    window02[ 9][0] = 125 + 250; window02[ 9][1] = 275;
    window02[10][0] = 125 + 250; window02[10][1] = 250;
    window02[11][0] = 125 + 250; window02[11][1] = 225;
    window02[12][0] = 125 + 250; window02[12][1] = 200;
    window02[13][0] = 125 + 250; window02[13][1] = 175;
    window02[14][0] = 125 + 250; window02[14][1] = 150;
    window02[15][0] = 125 + 250; window02[15][1] = 125;
    window02[16][0] = 150 + 250; window02[16][1] = 125;
    window02[17][0] = 175 + 250; window02[17][1] = 125;
    window02[18][0] = 200 + 250; window02[18][1] = 125;
    window02[19][0] = 225 + 250; window02[19][1] = 125;
    window02[20][0] = 250 + 250; window02[20][1] = 125;
    window02[21][0] = 275 + 250; window02[21][1] = 125;
    window02[22][0] = 275 + 250; window02[22][1] = 150;
    window02[23][0] = 275 + 250; window02[23][1] = 175;
    window02[24][0] = 275 + 250; window02[24][1] = 200;
	
	
	float StartShape[9][2]={{0,10},{-25,10},{-25,0},{-5,0},{-5,-20},{5,-20},{5,0},{25,0},{25,10}};    
	float EndShape[9][2]={{-25,10},{-25,-20},{-5,-20},{-5,-10},{5,-10},{5,-20},{25,-20},{25,10},{0,20}};
	float IntermediateShape[9][2];
	float WindowToWheelShape01[24][2];
	float WindowToWheelShape02[24][2];
	float VertexColors[24][3]={{1,0,0},{1,0,0},{1,0,0},{0,1,0},{0,1,0},{0,1,0},{0,0,1},{0,0,1},{0,0,1},
								{1,1,0},{1,1,0},{1,1,0},{0,1,1},{0,1,1},{0,1,1},{1,0,1},{1,0,1},{1,0,1},
								{1,0,0},{0,1,0},{0,0,1},{1,1,0},{0,1,1},{1,0,1}};
	
	static float Tween = 0.0 - deltat; 
	if (Tween < 1) {
		Tween += deltat;	
	}
	
	for (int Vtx=0; Vtx < 24; Vtx++) {
		IntermediateShape[Vtx/3][0] = (1.0 - Tween)*A[Vtx/3][0] + Tween*B[Vtx/3][0];
		IntermediateShape[Vtx/3][1] = (1.0 - Tween)*A[Vtx/3][1] + Tween*B[Vtx/3][1];
		WindowToWheelShape01[Vtx][0] = (1.0 - Tween)*window01[Vtx][0] + Tween*wheel01[Vtx][0];
		WindowToWheelShape01[Vtx][1] = (1.0 - Tween)*window01[Vtx][1] + Tween*wheel01[Vtx][1];
		WindowToWheelShape02[Vtx][0] = (1.0 - Tween)*window02[Vtx][0] + Tween*wheel02[Vtx][0];
		WindowToWheelShape02[Vtx][1] = (1.0 - Tween)*window02[Vtx][1] + Tween*wheel02[Vtx][1];
	}
	
	glColorPointer(3,GL_FLOAT,0,VertexColors);
	glVertexPointer(2,GL_FLOAT,0,IntermediateShape);
	glDrawArrays(GL_LINE_LOOP,0,MAX_N);

	glVertexPointer(2,GL_FLOAT,0,WindowToWheelShape01);
	glDrawArrays(GL_LINE_LOOP,0,MAX_M);
	glVertexPointer(2,GL_FLOAT,0,WindowToWheelShape02);
	glDrawArrays(GL_LINE_LOOP,0,MAX_M);
	
	Sleep(2);

	glutSwapBuffers();
	glutPostRedisplay();
}


void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glOrtho(-100.0, 700.0, -100.0, 700.0, -1.0, 1.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyboard (unsigned char key, int x, int y) {
	switch (key) {
		case 27:
			exit(0);
			break;
		default:
			break;
	}
}

void InitGL() {
	glEnableClientState (GL_VERTEX_ARRAY);
	glEnableClientState (GL_COLOR_ARRAY);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    
    InitGL();
    
    glutMainLoop();
    return 0;
}
