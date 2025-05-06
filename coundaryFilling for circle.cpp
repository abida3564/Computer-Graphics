#include<bits/stdc++.h>
#include <GL/gl.h>
#include <GL/glut.h>
#define pi 3.14159
using namespace std;

int radius = 8;  // Set the radius of the circle
int centerX = 0, centerY = 0;  // Center of the circle
map<pair<int, int>, int> mp;
int r[] = {0, 0, -1, 1};  // Directions for BFS
int c[] = {-1, 1, 0, 0};

// Function to draw a circle boundary
void drawCircleBoundary(int x0, int y0, int r) {
    for (int angle = 0; angle < 360; ++angle) {
        float rad = angle * pi / 180.0;
        int x = round(x0 + r * cos(rad));
        int y = round(y0 + r * sin(rad));
        mp[{x, y}] = 1;
        glVertex3f(x, y, 0);
    }
}

// Boundary Fill using BFS
void bfs(int x, int y) {
    int i, x1, y1;
    map<pair<int, int>, int> vis;
    queue<pair<int, int>> q;
    q.push({x, y});
    vis[{x, y}] = 1;
    glVertex3f(x, y, 0);

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (i = 0; i < 4; i++) {
            x1 = x + r[i];
            y1 = y + c[i];

            if (vis[{x1, y1}] == 0 && mp[{x1, y1}] == 0) {
                q.push({x1, y1});
                vis[{x1, y1}] = 1;
                glVertex3f(x1, y1, 0);
            }
        }
    }
}

// Display function to render the scene
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2);
    glBegin(GL_POINTS);

    // Draw the boundary of the circle
    glColor3f(1, 1, 1);  // White color for the boundary
    drawCircleBoundary(centerX, centerY, radius);

    // Fill the circle using boundary fill algorithm (Red color)
    glColor3f(1, 0, 0);  // Red color for filling
    bfs(centerX, centerY);  // Start BFS from the center of the circle

    glEnd();
    glFlush();
}

// Initialization of the OpenGL environment
void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);  // Background color
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-40.0, 40.0, -40.0, 40.0, -10.0, 10.0);
}

// Main function to set up the OpenGL window and loop
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle Boundary Fill");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
