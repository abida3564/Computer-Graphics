#include <GL/glut.h>
#include <math.h>

float x_pos = -0.8f; // Initial x position of the circle
float step = 0.01f; // Step size for translation

void drawCircle(float cx, float cy, float r, int num_segments) {
 glBegin(GL_POLYGON);
 for (int i = 0; i < num_segments; i++) {
 float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
 float x = r * cosf(theta);
 float y = r * sinf(theta);
 glVertex2f(x + cx, y + cy);
 }
 glEnd();
}

void display() {
 glClear(GL_COLOR_BUFFER_BIT);

 glColor3f(0.0f, 0.5f, 1.0f); // Blue circle
 drawCircle(x_pos, 0.0f, 0.1f, 100);

 glutSwapBuffers();
}

void update(int value) {
 x_pos += step;
 if (x_pos > 1.0f) x_pos = -1.0f; // Reset to left side once it reaches the right

 glutPostRedisplay(); // Redraw the scene
 glutTimerFunc(16, update, 0); // Approx. 60 FPS
}

int main(int argc, char** argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
 glutInitWindowSize(600, 600);
 glutCreateWindow("Circle Translation");

 glClearColor(1.0, 1.0, 1.0, 1.0); // White background
 gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 2D orthographic projection

 glutDisplayFunc(display);
 glutTimerFunc(0, update, 0);

 glutMainLoop();
 return 0;
}
