#include <GL/glut.h>
#include <iostream>
#include <string>

float posX = 0.0f;
float posY = 0.0f;

void desenhar() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Translação
    glTranslatef(posX, posY, 0.0f);

    // Desenha um quadrado
    glBegin(GL_QUADS);
        glVertex2f(-0.1f, -0.1f);
        glVertex2f( 0.1f, -0.1f);
        glVertex2f( 0.1f,  0.1f);
        glVertex2f(-0.1f,  0.1f);
    glEnd();

    glFlush();
}

void teclado(unsigned char tecla, int x, int y) {
    float passo = 0.05f;

    switch (tecla) {
        case 'w':
            posY += passo;
            break;
        case 's':
            posY -= passo;
            break;
        case 'a':
            posX -= passo;
            break;
        case 'd':
            posX += passo;
            break;
    }

    glutPostRedisplay();
}

void inicializar() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Fundo branco
    glColor3f(0.0, 0.0, 1.0);         // Quadrado azul
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Translacao");

    inicializar();

    glutDisplayFunc(desenhar);
    glutKeyboardFunc(teclado);

    glutMainLoop();

    return 0;
}