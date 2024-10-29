#include <GL/glut.h>

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Set the background color to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0); // Set the coordinate system
}

void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3) {
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

void drawHouse() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the base of the house
    glColor3f(1.82, 0.86, 0.62); // Light beige color
    drawRectangle(300, 200, 200, 200);

    // Draw the roof of the house
    glColor3f(0.8, 0.3, 0.3); // Red color
    drawTriangle(270, 400, 400, 500, 530, 400);

    // Draw the door
    glColor3f(0.5, 0.3, 0.1); // Brown color
    drawRectangle(375, 200, 50, 100);

    // Draw the door knob
    glColor3f(0.0, 0.0, 0.0); // Black color
    glPointSize(8.0);
    glBegin(GL_POINTS);
    glVertex2f(415, 250);
    glEnd();

    // Draw the windows
    glColor3f(0.6, 0.8, 1.0); // Light blue color
    // Left window
    drawRectangle(320, 300, 50, 50);
    // Right window
    drawRectangle(430, 300, 50, 50);

    // Draw window frames
    glColor3f(0.0, 0.0, 0.0); // Black color
    glLineWidth(2);
    glBegin(GL_LINES);
    // Left window frame
    glVertex2f(345, 300);
    glVertex2f(345, 350);
    glVertex2f(320, 325);
    glVertex2f(370, 325);
    // Right window frame
    glVertex2f(455, 300);
    glVertex2f(455, 350);
    glVertex2f(430, 325);
    glVertex2f(480, 325);
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Simple House_by_B190305004");
    init();
    glutDisplayFunc(drawHouse);
    glutMainLoop();
    return 0;
}
