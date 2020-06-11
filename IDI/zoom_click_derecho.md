# Modificación del FOV para simular un zoom aplicado al movimiento del ratón + click derecho

La idea detrás de la creación del zoom consiste en la modificación del FOV en función del desplazamiento que realiza el mouse
al pulsar el botón derecho.

 - Lo esencial es modificar las funciones de movimiento del mouse.
 
  ### mousePressEvent()
 
 ```c++
  void MyGLWidget::mousePressEvent (QMouseEvent *e)
  {
    xClick = e->x();
    yClick = e->y();
    
    if (e->button() & Qt::RightButton &&
        ! (e->modifiers() & (Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
    {
      DoingInteractive == ZOOM
    }
  }
 ```
  ### mouseReleaseEvent()
 
 ```c++
 void MyGLWidget::mouseReleaseEvent( QMouseEvent *)
{
  DoingInteractive == NONE;
}
```

 ### mouseMoveEvent()

```c++
void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
{
  makeCurrent();

    if(DoingInteractive == ZOOM){
     float FOVauxiliar = FOV + (e->y() - yClick)/10.0;

     if(FOVauxiliar < (float) M_PI && FOVauxiliar > 0.0) {
         FOV = FOVauxiliar;

         emit actualitzaBarra((FOV/ float(M_PI))*100.0);
     }

  xClick = e->x();
  yClick = e->y();

  update ();
}
 ```
