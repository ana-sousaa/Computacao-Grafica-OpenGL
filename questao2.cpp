#include <GL/glut.h>


float angX = 0.0, angY = 0.0, angZ = 0.0;

void desenho() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

   
    glRotatef(angX, 1.0, 0.0, 0.0);
    glRotatef(angY, 0.0, 1.0, 0.0);
    glRotatef(angZ, 0.0, 0.0, 1.0);

   
    glColor3f(0.0, 1.0, 0.0); 
    glutWireCube(1.0);

    glutSwapBuffers();
}

void teclado(unsigned char tecla, int x, int y) {
   
    switch (tecla) {
        case 'x': angX += 5.0f; 
        break; 
        case 'X': angX -= 5.0f; 
        break; 
        
        case 'y': angY += 5.0f;
        break; 
        case 'Y': angY -= 5.0f; 
        break; 
        
        case 'z': angZ += 5.0f; 
        break;
        case 'Z': angZ -= 5.0f; 
        break; 
    }
    glutPostRedisplay(); 
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotacao GLUT Simples");

    // Registra apenas o essencial
    glutDisplayFunc(desenho);
    glutKeyboardFunc(teclado);

    glutMainLoop();
    return 0;
}