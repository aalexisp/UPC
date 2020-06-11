  # Inspeccionar con el MOUSE una escena rotando la cámara con angulos de EULER
  
 La idea principal acerca de la inspección de la escena con la rotación de la cámara se hace con angulos de EULER.
 - Primero se crea una cámara en tercera persona con los ángulos de EULER. Ver [camara_3Persona_Euler](https://github.com/aalexisp/UPC/blob/master/IDI/camara_3Persona_Euler.md)
 
 - Lo primero es lo primero, declarar las vairables en **MyGLWidget.h**:
 ```c++
    int xClick, yClick;
    float angleY, angleX;
 ```
 
 - A continuación aparece la implementación de la función **mousePressEvent()** ya que tendremos en cuenta cuando y
 donde se pulsa por última vez con el ratón.
 ```c++
  void MyGLWidget::mousePressEvent (QMouseEvent *e)
  {
    xClick = e->x(); //Almacenamos en la variable xClick el valor del pixel en X donde hemos clicacado
    yClick = e->y(); //Almacenamos en la variable yClick el valor del pixel en Y donde hemos clicacado

    //Implementación para que se pueda también rotar con shift, control etc...
    
    if (e->button() & Qt::LeftButton &&
        ! (e->modifiers() & (Qt::ShiftModifier|Qt::AltModifier|Qt::ControlModifier)))
    {
      DoingInteractive = ROTATE;
    }
  }
```
   - Seguidamente aparece la implementación de la función **mouseReleaseEvent()** ya que tendremos en cuenta cuando se suelta
   el botón izquierdo aunque creo que no hace nada. No lo tengo claro.
  
```c++
  void MyGLWidget::mouseReleaseEvent( QMouseEvent *)
  {
    DoingInteractive = NONE;
  }
```

 - Por último la parte más importante. En esta función **mouseMoveEvent()** guardaremos y operaremos con la información 
 de movimiento del ratón.
    - La idea principal es que le añadimos al ángulo de EULER **psi** y **theta** el desplazamiento que ha tenido el ratón
    desde la última vez que se pulsó el click izquierdo en nuestro caso.
    - Se llama a **viewTransform()** dado que si no la cámara no cambiaría de sitio al no aplicar las transformaciones con
    los nuevos ángulos.

```c++
  void MyGLWidget::mouseMoveEvent(QMouseEvent *e)
  {
    makeCurrent();
    // Aqui cal que es calculi i s'apliqui la rotacio o el zoom com s'escaigui...
    if (DoingInteractive == ROTATE)
    {
      // Fem la rotació
      angleY += (e->x() - xClick) * M_PI / 180.f;
      angleX += (yClick - e->y()) * M_PI / 180.f;
      viewTransform ();
    }

    xClick = e->x();
    yClick = e->y();

    update ();
  }
```

  - Por último se aplica en la **viewTransform()** los angulos pertinentes.
  
```c++
  void MyGLWidget::viewTransform ()
  {
    glm::mat4 View(1.f);  // Matriu de posició i orientació
    //...
    View = glm::rotate(View, angleX, glm::vec3(1.0, 0.0, 0.0)); //angleX
    View = glm::rotate(View, -angleY, glm::vec3(0, 1, 0)); //angleY
    //...

    glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
  }
```

