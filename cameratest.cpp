#include<windows.h>
#include<cstdio>
#include<cmath>
#include<GL/glut.h>
#include "pcamera.h"

using namespace std;
Camera cam;
int drawaxes=1,drawgrid=1;
double delta=1.0;
void myKeyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case '1':
            cam.yaw(-delta);
            break; /// lookleft
        case '2':
            cam.yaw(delta);
            break; /// lookright
        case '3':
            cam.pitch(-delta);
            break; /// lookup
        case '4':
            cam.pitch(delta);
            break; /// lookdown
        case '5':
            cam.roll(delta);
            break; /// twistleft
        case '6':
            cam.roll(-delta);
            break; /// twistright
    }
    glutPostRedisplay();
}
void specialKeyListener(int key, int x,int y)
{
    //head rotations about axes
    //use INSERT key instead of PAGE_DOWN, mine not working
	switch(key)
	{
		case GLUT_KEY_UP:
		    cam.slide(0,0,-delta);
		    break; /// forward
		case GLUT_KEY_DOWN:
		    cam.slide(0,0,delta);
		    break; /// backward
		case GLUT_KEY_LEFT:
		    cam.slide(-delta,0,0);
		    break; /// left
		case GLUT_KEY_RIGHT:
		    cam.slide(delta,0,0);
		    break; /// right
		case GLUT_KEY_PAGE_UP:
		    cam.slide(0,delta,0);
		    break; /// up
		case GLUT_KEY_INSERT:
		    cam.slide(0,-delta,0);
		    break; /// down
	}
	glutPostRedisplay();
}
void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
		    glColor3f(1.0,0,0);//X-axis RED
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);
			glColor3f(0,1.0,0);//Y-axis GREEN
			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);
			glColor3f(0,0,1.0);//Z-axis BLUE
			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}
void drawGrid()
{
	int i;
	if(drawgrid==1)
	{
		glColor3f(0.6, 0.6, 0.6);	//grey
		glBegin(GL_LINES);{
			for(i=-8;i<=8;i++){

				if(i==0)
					continue;	//SKIP the MAIN axes

				//lines parallel to Y-axis
				glVertex3f(i*10, -90, 0);
				glVertex3f(i*10,  90, 0);

				//lines parallel to X-axis
				glVertex3f(-90, i*10, 0);
				glVertex3f( 90, i*10, 0);
			}
		}glEnd();
	}
}
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    drawAxes();
    drawGrid();
    glColor3f(0.5,0.5,0.5);
    glutWireSphere(10,20,20);
    glFlush();
    glutSwapBuffers();
}

void initCamera()
{
    glViewport(0,0,640,480);
    Vector3 up(0,0,1);
    Point3 eye(150.0f,150.0f,150.0f);
    Point3 look(0.0f,0.0f,0.0f);
    cam.set(eye,look,up);
    cam.setShape(30.0f,64.0f/48.0f,0.5f,500.0f);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("fly a camera around a teapot");

    glMatrixMode(GL_PROJECTION);
    glutKeyboardFunc(myKeyboard);
    glutSpecialFunc(specialKeyListener);
    glutDisplayFunc(myDisplay);
    glClearColor(0,0,0,0);
    glColor3f(0,0,0);

    initCamera();
    glutMainLoop();
    return 0;
}
