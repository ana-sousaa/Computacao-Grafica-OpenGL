#include <GL/glut.h>

float posX = 0.0;
float posY = 0.0;

void desenhar() {
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();


    glTranslatef(posX, posY, 0.0);


    glBegin(GL_QUADS);
        glVertex2f(-0.1, -0.1);
        glVertex2f( 0.1, -0.1);
        glVertex2f( 0.1,  0.1);
        glVertex2f(-0.1,  0.1);
    glEnd();

    glFlush();
}

void teclado(unsigned char tecla, int x, int y) {
    float passo = 0.05;

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
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glColor3f(0.0, 0.0, 1.0);         
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
