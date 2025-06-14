#include <GL/gl.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
void display(void)
{
/* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/
   // glPointSize(7);
    glColor3f (1.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    double a=0,b=0,r=8,x,y;
    int theta;
    for(theta = 0;theta<=360;theta++){
       x= r*cos(theta*3.1416/180.0);
       y= r*sin(theta*3.1416/180.0);
        glVertex2f(x,y);
    }
    glEnd();
    glFlush ();
}
void init (void)
{
/* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10, 10, -10.0, 10.0, -10.0, 10.0);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (600, 600);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Demo");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
