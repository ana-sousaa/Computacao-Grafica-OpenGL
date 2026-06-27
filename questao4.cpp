#include <GL/glut.h>

float esc1=1;
float esc2=1;
float esc3=1;

void desenhar()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glLoadIdentity();

    // Quadrado
    glPushMatrix();
        glTranslatef(-0.6,0,0);
        glScalef(esc1,esc1,1);
        glColor3f(1,0,0);

        glBegin(GL_QUADS);
        glVertex2f(-0.1,-0.1);
        glVertex2f(0.1,-0.1);
        glVertex2f(0.1,0.1);
        glVertex2f(-0.1,0.1);
        glEnd();
    glPopMatrix();

    // Triângulo
    glPushMatrix();
        glScalef(esc2,esc2,1);
        glColor3f(0,1,0);

        glBegin(GL_TRIANGLES);
        glVertex2f(0,0.15);
        glVertex2f(-0.15,-0.15);
        glVertex2f(0.15,-0.15);
        glEnd();
    glPopMatrix();

    // Losango
    glPushMatrix();
        glTranslatef(0.6, 0, 0);
        glScalef(esc3, esc3, 1);
        glColor3f(0,0,1);

        glBegin(GL_QUADS);
        glVertex2f(0.0, 0.15);
        glVertex2f(0.15, 0.0);
        glVertex2f(0.0, -0.15);
        glVertex2f(-0.15, 0.0);
    glEnd();

glPopMatrix();

    glutSwapBuffers();
}

void teclado(unsigned char tecla,int x,int y)
{
    switch(tecla)
    {
        case '1':
            esc1+=0.1;
            break;

        case '2':
            esc2+=0.1;
            break;

        case '3':
            esc3+=0.1;
            break;
    }

    glutPostRedisplay();
}

void init()
{
    glClearColor(1,1,1,1);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(600,600);
    glutCreateWindow("Missao 4");

    init();

    glutDisplayFunc(desenhar);
    glutKeyboardFunc(teclado);

    glutMainLoop();
}