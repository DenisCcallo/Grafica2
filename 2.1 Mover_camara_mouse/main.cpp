#include<windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

float mouseX = 0.0;
float mouseY = 0.0;
float camaraX = 0.0f;
float camaraY = 0.0f;
bool mouseLeftDown = false;
bool mouseRightDown = false;

void init(void)
{
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glShadeModel (GL_FLAT);
}
void triangulo()
{
    glColor3f(.0,1.0,0.0);
    glBegin(GL_LINE_STRIP);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 0.0f, 0.0f);
    glVertex3f(2.0f, 2.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);
    glEnd();
}

void display(void)
{
  glClear (GL_COLOR_BUFFER_BIT);
  glColor3f (1.0, 1.0, 1.0);
  glLoadIdentity ();
  glTranslatef(0, 0, -10.0f);
  glRotatef(camaraX, 1, 0, 0);
  glRotatef(camaraY, 0, 1, 0);
  glScalef (1.0, 2.0, 1.0);
  triangulo();
  glFlush();
}

void mouse_llamada(int button, int state, int x, int y)
{
    mouseX = x;
    mouseY = y;

    if(button == GLUT_LEFT_BUTTON)
    {
        if(state == GLUT_DOWN)
        {
            mouseLeftDown = true;
        }
        else if(state == GLUT_UP)
            mouseLeftDown = false;
    }
}

void mouse_movimiento(int x, int y)
{
    if(mouseLeftDown)
    {
        camaraY += (x - mouseX);
        camaraX += (y - mouseY);
        mouseX = x;
        mouseY = y;
    }
}

void idleCallback()
{
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize (900, 600);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutIdleFunc(idleCallback);
  glutMouseFunc(mouse_llamada);
  glutMotionFunc(mouse_movimiento);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
  glMatrixMode (GL_MODELVIEW);
  glutMainLoop();
  return 0;
}
