#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

GLint winWidth = 800, winHeight = 600;//tamano ventana
GLfloat x0 = 100.0, y0 = 70.0, z0 = 70.0; // Origen coordenadas de visual.
GLfloat xref = 70.0, yref = 70.0, zref = 0.0; // Punto observado.
GLfloat Vx = 0.0, Vy = 1.0, Vz = 0.0; // Vector vertical.

/* Establecer límites de coordenadas para ventana de recorte: */
GLfloat xwMin = -40.0, ywMin = -60.0, xwMax = 40.0, ywMax = 60.0;
/* Establecer posición de los planos de recorte próximo y lejano: */
GLfloat dnear = 25.0, dfar = 125.0;

float valor_x=0.0;
float valor_y=0.0;
float x=0.0;
float y=0.0;

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glMatrixMode (GL_MODELVIEW);
    gluLookAt (x0, y0, z0, xref, yref, zref, Vx, Vy, Vz);
    glMatrixMode (GL_PROJECTION);
    glFrustum (xwMin, xwMax, ywMin, ywMax, dnear, dfar);
}
void cuadrado (void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (1.0, 0.0, 0.0); //
    glPolygonMode (GL_FRONT, GL_FILL);
    glPolygonMode (GL_BACK, GL_LINE); // Cara posterior alámbrica.
    glTranslatef(valor_x,valor_y,0);
    glBegin (GL_QUADS);
    glVertex3f (0.0, 0.0, 0.0);
    glVertex3f (100.0, 0.0, 0.0);
    glVertex3f (100.0, 100.0, 0.0);
    glVertex3f (0.0, 100.0, 0.0);
    glEnd ( );
    glFlush ( );
}
void reshapeFcn (GLint newWidth, GLint newHeight)
{
    glViewport (valor_x, valor_y, newWidth, newHeight);
    winWidth = newWidth;
    winHeight = newHeight;
}

void teclado(int key,int x,int y){
    if(key == GLUT_KEY_DOWN){
        valor_y=valor_y-0.1;
    }
    if(key == GLUT_KEY_LEFT){
        valor_x=valor_x-0.1;
    }
    if(key == GLUT_KEY_UP){
        valor_y=valor_y+0.1;
    }
    if(key == GLUT_KEY_RIGHT){

        valor_x=valor_x+0.1;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 50);
    glutInitWindowSize (winWidth, winHeight);
    glutCreateWindow ("Perspective de un Cuadrado");
    init ( );
    glutDisplayFunc (cuadrado);
    glutReshapeFunc (reshapeFcn);
    glutSpecialFunc(teclado);
    glutMainLoop ( );
    return 0;
}
