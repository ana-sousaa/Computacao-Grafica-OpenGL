#include <GL/glut.h>

float s = 0.0;

void desenharCubo()
{
    glBegin(GL_QUADS);

    // Frente
    glColor3f(1,0,0);
    glVertex3f(-1 + s, -1,  1);
    glVertex3f( 1 + s, -1,  1);
    glVertex3f( 1 - s,  1,  1);
    glVertex3f(-1 - s,  1,  1);

    // Trás
    glColor3f(0,1,0);
    glVertex3f(-1 + s, -1, -1);
    glVertex3f( 1 + s, -1, -1);
    glVertex3f( 1 - s,  1, -1);
    glVertex3f(-1 - s,  1, -1);

    // Esquerda
    glColor3f(0,0,1);
    glVertex3f(-1 + s, -1, -1);
    glVertex3f(-1 + s, -1,  1);
    glVertex3f(-1 - s,  1,  1);
    glVertex3f(-1 - s,  1, -1);

    // Direita
    glColor3f(1,1,0);
    glVertex3f(1 + s, -1, -1);
    glVertex3f(1 + s, -1,  1);
    glVertex3f(1 - s,  1,  1);
    glVertex3f(1 - s,  1, -1);

    // Topo
    glColor3f(0,1,1);
    glVertex3f(-1 - s, 1,  1);
    glVertex3f( 1 - s, 1,  1);
    glVertex3f( 1 - s, 1, -1);
    glVertex3f(-1 - s, 1, -1);

    // Base
    glColor3f(1,0,1);
    glVertex3f(-1 + s,-1, 1);
    glVertex3f( 1 + s,-1, 1);
    glVertex3f( 1 + s,-1,-1);
    glVertex3f(-1 + s,-1,-1);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(0,0,-6);

    desenharCubo();

    glutSwapBuffers();
}

void teclado(unsigned char tecla, int x, int y)
{
    switch(tecla)
    {
        case 'h':
            s += 0.1;
            break;

        case 'H':
            s -= 0.1;
            break;

        case 'z':
            s = 0.0;
            break;
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45,1,1,100);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Cisalhamento");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);

    glutMainLoop();

    return 0;
}