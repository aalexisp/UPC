# Configuración de una cámara en primera persona (encima de un modelo) que se mueve si el modelo se mueve.

Con tal de configurar una cámara en tercera persona hay que tener en cuenta un seguido de cosas:
 - Debemos usar los valores de VRP, UP, OBS correctamente.
 - Debemos usar las funciones **lookat()** y **perspective() u ortho()** correctamente.

Los métodos que debemos modificar necesariamente son:

```c++
  void iniCamera ();
  void viewTransform ();
  void projectTransform ();
```

- Además en el NouGLWidget.h hay que declarar ciertas cosas:

```c++

  //Variables de la nueva cámara
  glm::vec3 OBS;
  glm::vec3 UP;
  glm::vec3 VRP;

```


### iniCamera()

  - También debemos declarar una variale que nos servirá para el movimiento del patricio y la cámara en primera persona.
  - Finalmente se llaman a los métodos **projectTransform();** y **viewTransform();**

```c++
void MyGLWidget::ini_camera()
{
   
  movP2 = glm::vec3(4.f, 0.f, 6.f); //Variable de movimiento del patricio y la cámara a la vez ya que se puede reutilizar

  projectTransform();
  viewTransform();
  
}

```

### viewTransform()

 - En este caso, al no usar Euler usamos la función **glm::lookAt (OBS, VRP, UP);**.
 - El valor de **OBS** será la posición del modelo más la altura a la que queremos poner la cámara.
 - El valor de **VRP** será la dirección hacia donde mirá la cámara.
 - El valor de **UP** indica la normal de la cámara.
 - Finalmente se aplica lookAt() que modifica la View correctamente.

```c++
void NouGLWidget::viewTransform() {
   OBS = glm::vec3(glm::vec3(movP2[0], 5.f, movP2[2]));
   UP = glm::vec3(0, 1, 0);  
   VRP = obs + glm::vec3(0.f, 0.f, 2.f);
   View = glm::lookAt (obs, vrp, up);

  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);

}
```

### projectTransform()

- Le damos valor a la matriz de proyección con el método **glm::perspective(fov, rav, zn, zf);**.
- Finalmente se pasan los cambios al localizador projLoc.

```c++
void NouGLWidget::projectTransform() {
  glm::mat4 Proj;  // Matriu de projecció

  rav = 1.f;
  zn = 0.1;
  zf = 10.f;
  fov = float(M_PI/2.f);

  Proj = glm::perspective(fov, rav, zn, zf);
  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);

}
```
