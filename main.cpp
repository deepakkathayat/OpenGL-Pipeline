#include <GL/glut.h>
#include "sgl.h"
using namespace std;

void drawScene();
void drawTriangle();
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handleMouseclick(int button, int state, int x, int y);

//Global Variables

float tri_x = 0.0f;
float tri_y = 0.0f;
float theta = 0.0f; 
int w,h;
int main(int argc, char **argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    w = glutGet(GLUT_SCREEN_WIDTH);
    h = glutGet(GLUT_SCREEN_HEIGHT);
    int windowWidth = w;
    int windowHeight = h;

    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

    glutCreateWindow("Graphics : Assignment 3");  
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glShadeModel(GL_SMOOTH);

	glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);
    glutKeyboardFunc(handleKeypress1);
    glutSpecialFunc(handleKeypress2);
    glutMouseFunc(handleMouseclick);

    glutMainLoop();
    return 0;
}

void drawScene() {
    sglProjOrtho(0,1000, 0, 1000, 0, 1000);
    sglViewport(0, 0, 100, 100);
	
	sglModLoadIdentity();
	sglViewLoadIdentity();
	
    glMatrixMode(GL_MODELVIEW);

	sglModPushMatrix();

	sglModTranslate(tri_x,tri_y,0.0f);
    sglModRotate(theta, 0, 0, 1.0f);
    sglModScale(1.5f, 1.5f, 1.5f);
	
	drawTriangle();
	
	sglModPopMatrix();
	
	sglShow();

    glutSwapBuffers();
}

void drawTriangle() {

    sglClear(0, 0, 0);
    sglBegin(SGL_TRIANGLES);
	
	sglColour(1.0f, 0.0f, 0.0f);
    sglVertex(0.0f, 1.0f, -10.0f);
	
	sglColour(0.0f, 1.0f, 0.0f);
    sglVertex(-1.0f, -1.0f, -10.0f);
	
	sglColour(0.0f, 0.0f, 1.0f);
    sglVertex(1.0f, -1.0f, -10.0f);
	
	sglColour(1.0f, 0.5f, 1.0f);
    sglVertex(4.0f, 1.0f, -10.0f);
	
	sglColour(0.0f, 1.0f, 0.0f);
    sglVertex(-4.0f, 1.0f, -10.0f);
	
	sglColour(0.5f, 0.0f, 0.5f);
    sglVertex(0.0f, -4.0f, -10.0f);
	
	sglEnd();
}

void handleKeypress1(unsigned char key, int x, int y) {

    if (key == 27) {
        exit(0);     // escape key is pressed
    }
}

void handleKeypress2(int key, int x, int y) {

    if (key == GLUT_KEY_LEFT)
        tri_x -= 0.1;
    if (key == GLUT_KEY_RIGHT)
        tri_x += 0.1;
    if (key == GLUT_KEY_UP)
        tri_y += 0.1;
    if (key == GLUT_KEY_DOWN)
        tri_y -= 0.1;
}
void handleMouseclick(int button, int state, int x, int y) {

    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
            theta += 15;
        else if (button == GLUT_RIGHT_BUTTON)
            theta -= 15;
    }
}
