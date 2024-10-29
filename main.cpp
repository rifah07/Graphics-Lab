#include <GL/glut.h>
#include <cmath>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the green background
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_QUADS);
        glVertex2f(-0.9, -0.6);
        glVertex2f(0.9, -0.6);
        glVertex2f(0.9, 0.6);
        glVertex2f(-0.9, 0.6);
    glEnd();

    // Draw the red circle
    glColor3f(0.8, 0.0, 0.0);
    float theta;
    int num_segments = 100;
    float radius = 0.3;
    float cx = 0.0, cy = 0.0;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of circle
    for(int i = 0; i <= num_segments; i++) {
        theta = 2.0f * 3.1415926f * float(i) / float(num_segments); // Get the current angle
        float x = radius * cosf(theta); // Calculate the x component
        float y = radius * sinf(theta); // Calculate the y component
        glVertex2f(x + cx, y + cy); // Output vertex
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Bangladesh National Flag");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
