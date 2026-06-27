#include <GL/glut.h>

float escalaX = 1.0;
float escalaY = 1.0;

void desenharEixos()
{
    glColor3f(0.0, 0.0, 0.0);

    glBegin(GL_LINES);

        // Eixo X
        glVertex2f(-1.0, 0.0);
        glVertex2f( 1.0, 0.0);

        // Eixo Y
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0,  1.0);

    glEnd();
}

void desenharObjeto()
{
    glColor3f(1.0, 0.0, 0.0);

    // Barra vertical
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, -0.20f);
        glVertex2f( 0.05f, -0.20f);
        glVertex2f( 0.05f,  0.20f);
        glVertex2f(-0.05f,  0.20f);
    glEnd();

    // Barra horizontal
    glBegin(GL_QUADS);
        glVertex2f(-0.05f, -0.20f);
        glVertex2f( 0.20f, -0.20f);
        glVertex2f( 0.20f, -0.10f);
        glVertex2f(-0.05f, -0.10f);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

  
    desenharEixos();

    
    glPushMatrix();

        
        glScalef(escalaX, escalaY, 1.0f);

        glTranslatef(0.4, 0.3, 0.0);

        desenharObjeto();

    glPopMatrix();

    glutSwapBuffers();
}

void teclado(unsigned char tecla, int x, int y)
{
    switch(tecla)
    {
        // Espelhamento no eixo X
        case 'x':
            escalaY *= -1;
            break;

        // Espelhamento no eixo Y
        case 'y':
            escalaX *= -1;
            break;

        // Volta ao normal
        case 'r':
            escalaX = 1.0f;
            escalaY = 1.0f;
            break;
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1, 1, -1, 1);

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(600, 600);

    glutCreateWindow("Espelhamento");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);

    glutMainLoop();

    return 0;
}