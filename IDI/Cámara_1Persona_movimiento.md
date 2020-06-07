# Configuración de una cámara en primera persona (encima de un modelo) que se mueve si el modelo se mueve.

Con tal de configurar una cámara en tercera persona hay que tener en cuenta un seguido de cosas:
 - Debemos usar los valores de VRP, UP, OBS correctamente.
 - Debemos usar las funciones **lookat()** y **perspective() u ortho()** correctamente.
 - Debemos situal OBS encima del modelo y VRP = OBS + glm::vec3(dirección_donde_mira_patricio);

Supongamos una posición inicial de la cámara incorrecta o inexistente.
Los métodos que debemos modificar necesariamente son:

```c++
  void iniCamera ();
  void viewTransform ();
  void projectTransform ();
```
- Además en el NouGLWidget.h hay que declarar ciertas cosas:
```c++
  bool goPro;

  //Variables de la nueva cámara
  glm::vec3 obs;
  glm::vec3 up;
  glm::vec3 vrp;

```


### iniCamera()

  - Este método sirve para inicializar la cámara.
  - Lo primero que debemos hacer es poner una variable **bool** que sirve para intercambiar entre una cámara u otra.
  - También debemos declarar una variale que nos servirá para el movimiento del patricio y la cámara en primera persona.
  - Si solo utilizamos una cámara en tercera persona podemos declarar e inicializar en esta función los parámetros zNear, zFar, FOV ...
  pero en este ejercicio tendremos en cuenta que tendremos dos cámaras, una con angulos de Euler en tercera persona y la otra la nuestra 
  en primera persona.
  - Finalmente se llaman a los métodos **projectTransform();** y **viewTransform();**
  
  Solo tendremos en cuenta el valor q le otorgramos a la variable de movimiento de la cámara y patricio movP2 y el valor
  del bool que nos cambia entre primera y tercera persona.
  
Remarcar que esto se podría hacer en el initializeGL pero para nuestro examen nos han cambiado el esqueleto y nos han puesto
un esqueleto heredado de MyGLWidget.cpp por lo que se hace en el iniCamera pero de normal va al initializeGL().

```c++
void MyGLWidget::ini_camera()
{

  posFocus = glm::vec3(0.0, 0.0, 0.0); //código irrelevante para la cámara
   
  movP2 = glm::vec3(4.0, 0.0, 6.0); //Variable de movimiento del patricio y la cámara a la vez ya que se puede reutilizar
  primeraTerceraPersona = false; //Bool de elección de cámara, si false estamos en tercera persona
  
  //Valores de la cámara en tercera persona y Euler que no debemos tener en cuenta
  rav = 1.0; 
  angleY = 0;
  angleX = M_PI/6.0;
  
  projectTransform();
  viewTransform();
  
}

```

### viewTransform()

 - En la transformación para la View Matrix tendremos en cuenta las transformaciones geométricas pertinentes para situar
 la cámara correctamente en caso de la cámara en tercera persona con Euler.
 - En este caso, al no usar Euler usamos la función **glm::lookAt (OBS, VRP, UP);**. Función que hace internamente estas transformaciones.
 - El valor de **OBS** será la posición del modelo más la altura a la que queremos poner la cámara.
 - El valor de **VRP** será la dirección hacia donde mirá la cámara. En nuestro caso será **obs + glm::vec3(0, 0, -1)** para mirar a -Z.
 - El valor de **UP** indica la normal de la cámara.
 - Finalmente se aplica llokAt() que modifica la View correctamente.

```c++
void NouGLWidget::viewTransform() {
  //MyGLWidget::viewTransform();

  if (not goPro){
    // Transformaciones de la view para
    // Matriu de posició i orientació
    View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -2*radiEsc));
    View = glm::rotate(View, angleX, glm::vec3(1.0, 0.0, 0.0));
    View = glm::rotate(View, -angleY, glm::vec3(0, 1, 0));
    View = glm::translate(View, -centreEsc);
  } else {
    //Parámetros de la cámara en primera persona sin Euler
    obs = glm::vec3(movP2) + glm::vec3(0.0, 3.5, 0.0);
    vrp = obs + glm::vec3(0.0, 0.0, -1.0);
    up = glm::vec3(0, 1, 0);
    View = glm::lookAt (obs, vrp, up);
  }
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);

}
```

### projectTransform()

- En la projectTransform de configuran los parámetros de la cámara.
- Podriamos inicializar aqui FOV, zNear y zFar pero creo que da igual donde se haga.
- En este caso usamos el bool para diferenciar entre los parámetros de la cámara en primera o tercera persona.
- Le damos valor a la matriz de proyección con el método **glm::perspective(fov, rav, zn, zf);**.
- En el caso de ser cámara ortogonal **glm::ortho(-2.5f*raw, 2.5f*raw, 0.0f, 4.0f, zNear, zFar);**.
- Finalmente se pasan los cambios al localizador projLoc.

```c++
void NouGLWidget::projectTransform() {
  //MyGLWidget::projectTransform();

  float fov, zn, zf;
  glm::mat4 Proj;  // Matriu de projecció

  if (not goPro){
    fov = float(M_PI/3.0);
    zn = radiEsc;
    zf = 3*radiEsc;
  } else {
    zn = 0.1;
    zf = 10.0;
    fov = float(M_PI/2.0);
  }

  Proj = glm::perspective(fov, rav, zn, zf);
  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);

}
```

- Finalmente tendremos en cuenta que el movimiento de la cámara es el mismo que para el patricio por lo tanto el valor es el mismo.
```c++
  void NouGLWidget::keyPressEvent(QKeyEvent* event)
  {
    makeCurrent();
    switch (event->key()) {
      case Qt::Key_S: {
          if (movP2.z < 7.5) movP2.z += 0.5;
        break;
      }
      case Qt::Key_W: {
          if (movP2.z > 0.5) movP2.z -= 0.5;
        break;
      }
      case Qt::Key_A: {
          if (movP2.x > 0.5) movP2.x -= 0.5;
        break;
      }
      case Qt::Key_D: {
          if (movP2.x < 7.5) movP2.x += 0.5;
        break;
      }
      case Qt::Key_C: {
          goPro = !goPro;
        break;
      }
      default: {
        MyGLWidget::keyPressEvent(event);
        break;
      }
    }
    viewTransform();
    projectTransform();
    update();
  }
```

