# Configuración de una cámara en tercera persona SIN angulos de Euler

Con tal de configurar una cámara en tercera persona hay que tener en cuenta un seguido de cosas:
 - Debemos usar los valores de VRP, UP, OBS correctamente.
 - Debemos usar las funciones **lookat()** y **perspective() u ortho()** correctamente.

Los métodos que debemos modificar necesariamente son:

```c++
  void iniCamera ();
  void viewTransform ();
  void projectTransform ();
```

### iniCamera()

  - Lo primero que debemos hacer es poner los parámetros necesarios para la cámara:
    - VRP (*View Referenece Point*, hacia donde mirará la cámara).
    - OBS (*Observer*, posición en la que se situará la cámara).
    - UP (Dirección de la normal de la cámara).
  - Seguidamente le damos valor al zNear y zFar junto on el FOV
  - Finalmente se llaman a los métodos **projectTransform();** y **viewTransform();**

```c++
void MyGLWidget::ini_camera()
{
  //d = r*2 (Si r es el radio de la esfera contenedora de la esfera d es 2 veces este radio)
  VRP = glm::vec3 ((xmax+xmin)/2.0, (ymax+ymin)/2.0, (zmax+zmin)/2.0);
  OBS = VRP + glm::vec3(0, 0, d);
  UP = glm::vec3(0,1,0);

  zNear = radi;
  zFar = 3*radi;
  FOV = 2.0*asin(radi/d);
  
  projectTransform();
  viewTransform();
}

```
### Buscar los puntos máximo y mínimo de mi escena

- Hay que **destacar** una cosa muy importante. Y es que no siempre nos dirán el tamaño de la escena. En ese caso hay que mirar las posiciones de los vértices del suelo, tierra o lo que sea más externo de la escena. Esto se mira en el **carregaBuffers()** del respectivo objecto.
 
 ```c++
  void MyGLWidget::creaBuffersTerraIParet ()
  {
    // VBO amb la posició dels vèrtexs
    glm::vec3 posterra[12] = {
          glm::vec3(-2.0, -1.0, 2.0),
          glm::vec3(2.0, -1.0, 2.0),
          glm::vec3(-2.0, -1.0, -2.0), // esta es la posición mínima
          glm::vec3(-2.0, -1.0, -2.0),
          glm::vec3(2.0, -1.0, 2.0),
          glm::vec3(2.0, -1.0, -2.0),
          glm::vec3(-2.0, -1.0, -2.0),
          glm::vec3(2.0, -1.0, -2.0),
          glm::vec3(-2.0, 1.0, -2.0),
          glm::vec3(-2.0, 1.0, -2.0),
          glm::vec3(2.0, -1.0, -2.0),
          glm::vec3(2.0, 1.0, -2.0)
	  
	  //La posición máxima de la escena no es un vértice pq no se pinta, es un vértice imaginario.
	  //Cuando hemos analizado esto bien y sabemos las medidas de nuestra escena podemos averiguar el punto máximo.
    };
 // ...
  }
 ```
 - Una vez hemos encontrado estos valores de **min** (punto mínimo de la escena) y **max** (punto máximo de la escena).
 Es nececsario declarar estos dos valores como **glm::vec3 min, max;** en **MyGLWidget.h**:
 ```c++
     glm::vec3 min, max;
 ```
 - Por último para calcular el radio de la escena hay que calcular la distáncia entre estos dos puntos y dividirla entre 2
 en la función **iniCamera()**.

```c++
  void NouGLWidget::iniCamera ()
  {

    centreEsc = glm::vec3 (4.f, 2.f, 4.f);
    
    min = glm::vec3(-2.f, -1.f, -2.f);
    max = glm::vec3(2.f, 1.f, 2.f);
    radiEsc = distance(min, max)/2.f;
  
  }
```

### viewTransform()

 - En este caso, al no usar Euler usamos la función **glm::lookAt (OBS, VRP, UP);**.

```c++
void MyGLWidget::viewTransform ()
{
  //Matriu de transformació de la vista
  glm::mat4 View = glm::lookAt (OBS, VRP, UP);
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

```

### projectTransform()

- Le damos valor a la matriz de proyección con el método **glm::perspective(fov, rav, zn, zf);**.
- En el caso de ser cámara ortogonal **glm::ortho(-2.5f*raw, 2.5f*raw, 0.0f, 4.0f, zNear, zFar);**.
- Finalmente se pasan los cambios al localizador projLoc.

```c++
void MyGLWidget::projectTransform ()
{
  //Matriu de transformació de la projecció
  //El cálculo de FOV, zNear y zFar se puede hacer aquí igualmente.
  glm::mat4 Proj;
  if (ortho == 0) Proj = glm::perspective (FOV, raw, zNear, zFar);
  else Proj = glm::ortho(-2.5f*raw, 2.5f*raw, 0.0f, 4.0f, zNear, zFar);
  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);

}


```



A             |  B
:-------------------------:|:-------------------------:
![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image1.png)  |  ![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image2.png)
