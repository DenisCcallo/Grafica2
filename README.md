# Computación Grafica-practica2
Mover camara, Perspectiva y mover objeto.


**Tabla de Contenido**
- Mover camara con el mouse
- Mover objeto con el teclado



**Mover camara con el mouse**
Para mover la camara se usa el mouse, con las coordenadas X,Y,Z un triangulo gracias a las funciones   glutMouseFunc(mouse_llamada) y 
  glutMotionFunc(mouse_movimiento);


```c++
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
```

![Mover camara](https://github.com/DenisCcallo/Grafica2/blob/master/2%20imagenes/camaramouse.gif "Mover camara")


**Mover objeto con el teclado**
Se crea un cuadrado para que se visualize con una determinada perspectiva, se usa las flechas de direccionamiento para mover el objeto

```c++
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
```c++

![Mocer Objeto](https://github.com/DenisCcallo/Grafica2/blob/master/2%20imagenes/moveobjteclado.gif "Mover objeto")
