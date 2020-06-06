# Configuración de una cámara en tercera persona SIN angulos de Euler

Con tal de configurar una cámara en tercera persona hay que tener en cuenta un seguido de cosas:
 - Debemos usar los valores de VRP, UP, OBS correctamente.
 - Debemos usar las funciones **lookat()** y **perspective() u ortho()** correctamente.

Supongamos una posición inicial de la cámara incorrecta o inexistente.
Los métodos que debemos modificar necesariamente son:

```c++
  void iniCamera ();
  void viewTransform ();
  void projectTransform ();
```

### iniCamera()

  - Este método sirve para inicializar la cámara.
  - Lo primero que debemos hacer es poner los parámetros necesarios para la cámara:
    - VRP (*View Referenece Point*, hacia donde mirará la cámara).
    - OBS (*Observer*, posición en la que se situará la cámara).
    - UP (Dirección de la normal de la cámara).
  - Seguidamente le damos valor al zNear y zFar junto on el FOV (fórmula en el código).
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

Para calcular el radio de la escena debemos hacer pitágoras.

<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/IDI/images/image4.jpeg" width=60%>
</p>

### viewTransform()

 - En la transformación para la View Matrix tendremos en cuenta las transformaciones geométricas pertinentes para situar
 la cámara correctamente.
 - En este caso, al no usar Euler usamos la función **glm::lookAt (OBS, VRP, UP);**. Función que hace internamente estas transformaciones.
 - Finalmente se translada la cámara a la posición donde queremos situarla que es sobre la esfera contenedora de la escena.

```c++
void MyGLWidget::viewTransform ()
{
  //Matriu de transformació de la vista
  glm::mat4 View = glm::lookAt (OBS, VRP, UP);
  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);
}

```

### projectTransform()

- En la projectTransform de configuran los parámetros de la cámara.
- Podriamos inicializar aqui FOV, zNear y zFar pero creo que da igual donde se haga.
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
