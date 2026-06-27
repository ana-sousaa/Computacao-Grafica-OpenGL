#include <GL/glut.h>

float transX = 0.0;
float transY = 0.0;
float transZ = -6.0;

float rotX = 0.0;
float rotY = 0.0;
float rotZ = 0.0;

float escala = 1.0;

void desenharPiramide()
{
    // Faces
    glBegin(GL_TRIANGLES);

    glColor3f(1,0,0);
    glVertex3f(0,1,0);
    glVertex3f(-1,-1,1);
    glVertex3f(1,-1,1);

    glColor3f(0,1,0);
    glVertex3f(0,1,0);
    glVertex3f(1,-1,1);
    glVertex3f(1,-1,-1);

    glColor3f(0,0,1);
    glVertex3f(0,1,0);
    glVertex3f(1,-1,-1);
    glVertex3f(-1,-1,-1);

    glColor3f(1,1,0);
    glVertex3f(0,1,0);
    glVertex3f(-1,-1,-1);
    glVertex3f(-1,-1,1);

    glEnd();

    // Base
    glBegin(GL_QUADS);

    glColor3f(0.5,0.5,0.5);

    glVertex3f(-1,-1,1);
    glVertex3f(1,-1,1);
    glVertex3f(1,-1,-1);
    glVertex3f(-1,-1,-1);

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    glTranslatef(transX, transY, transZ);

    glRotatef(rotX,1,0,0);
    glRotatef(rotY,0,1,0);
    glRotatef(rotZ,0,0,1);

    glScalef(escala,escala,escala);

    desenharPiramide();

    glutSwapBuffers();
}

void teclado(unsigned char tecla,int x,int y)
{
    switch(tecla)
    {
        // Translação
        case 't': transX += 0.2; break;
        case 'T': transX -= 0.2; break;

        // Rotação
        case 'y': rotY += 5; break;
        case 'Y': rotY -= 5; break;

        // Escala
        case 'e': escala += 0.1; break;
        case 'E':
            if(escala > 0.2)
                escala -= 0.1;
            break;
    }

    glutPostRedisplay();
}

void reshape(int w,int h)
{
    if(h==0) h=1;

    glViewport(0,0,w,h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45,(float)w/h,1,100);

    glMatrixMode(GL_MODELVIEW);
}

void init()
{
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);

    glutInitWindowSize(700,700);

    glutCreateWindow("Modelagem Manual 3D");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}