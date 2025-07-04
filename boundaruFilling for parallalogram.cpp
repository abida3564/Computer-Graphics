//Boundary Filling


#include<bits/stdc++.h>﻿
#include <GL/gl.h>
#include <GL/glut.h>
#define pi 3.14159
using namespace std;
double h=-9,k=9;
map<pair<int,int>,int > mp;
int r[]={0,0,-1,1};
int c[]={-1,1,0,0};


void bfs(int x,int y)
{
    int i,x1,y1;
    map<pair<int,int> ,int > vis;
    queue<pair<int,int> > q;
    q.push({x,y});
    vis[{x,y}]=1;
    glVertex3f(x,y,0);
    while(!q.empty())
    {
        x=q.front().first;
        y=q.front().second;
        q.pop();
        for(i=0;i<4;i++)
        {
            x1=x+r[i];
            y1=y+c[i];
            if(vis[{x1,y1}]==0&&mp[{x1,y1}]==0)
            {
                q.push({x1,y1});
                vis[{x1,y1}]=1;
                glVertex3f(x1,y1,0);
            }
        }

    }
}



void display(void)
{
/* clear all pixels */
    glClear (GL_COLOR_BUFFER_BIT);
/* draw white polygon (rectangle) with corners at
* (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
*/


        glColor3f (1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        glColor3f(1,1,0);
        //glVertex3f(0,0,0);
        int i,j;
        for(i=1;i<=5;i++)
        {
            for(j=1;j<=10;j++)
            {
                if(i==1||i==5)
                {
                    mp[{i,i+j}]=1;
                    glVertex3f(i,i+j,0);
                }
                if(j==1||j==10)
                {
                    mp[{i,i+j}]=1;
                    glVertex3f(i,i+j,0);
                }
            }
        }
        glColor3f(1,0,0);
        bfs(2,7);

        glEnd(); //End quadrilateral coordinates


        glFlush ();
}

void init (void)
{
/* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-40.0,40.0, -40.0, 40.0, -10.0, 10.0);
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
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Demo");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}