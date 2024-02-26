#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

#define WINDOW_W 800
#define WINDOW_H 600

void render(void) {
    glClearColor(1.0, 1.0, 1.0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-0.5, -0.5);
        glVertex2f(0.0, 0.5);
        glVertex2f(0.5, -0.5);
    glEnd();

    glFlush();
}

void keyboard(unsigned char key, int x, int y) {
    if (key == 27)
        exit(0);
}


int main(int argc, char*argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_W, WINDOW_H);
    glutCreateWindow("GLUT Window");
    glutDisplayFunc(render);
    glutKeyboardFunc(keyboard);

    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);

    glutMainLoop();

    return 0;
}