# Configuración de una cámara en tercera persona con angulos de Euler

Con tal de configurar una cámara en tercera persona hay que tener en cuenta un seguido de cosas:
 - Dado que tenemos que tener en cuenta **psi (Ψ)** y **theta (Θ)** (angleY, angleX) sabemos que usamos Euler.

Los métodos que debemos modificar necesariamente son:

```c++
  void iniCamera ();
  void iniEscena ();
  void viewTransform ();
  void projectTransform ();
```

### iniEscena()

 - Dado que tenemos que inicializar la escena y que usamos Euler solo ponemos el centro de la escena y el radio.
 - Lo primero de todo consiste en inicializar el valor del centro de la escena. Es decir, hacia donde va a mirar la cámara, el "VRP".

```c++
  void NouGLWidget::iniEscena ()
  {

    centreEsc = //coord
    radiEsc = 6;
  
  }
```


### Encontrar centro escena

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
 en la función **iniEscena()**.

```c++
  void NouGLWidget::iniEscena ()
  {

    centreEsc = glm::vec3 (4, 2, 4);
    
    min = glm::vec3(-2.f, -1.f, -2.f);
    max = glm::vec3(2.f, 1.f, 2.f);
    radiEsc = distance(min, max)/2.f;
  
  }
```

### iniCamera()

  - Lo primero que debemos hacer es poner los angulos de rotación **psi (Ψ)** y **theta (Θ)** correspondientes.
  - En esta función es donde inicializaremos las variables **zNear, zFar, FOV** de primeras.
  - **Fov = 2*arcsin(radiEscena/distància);**
- zNear será el valor del radio de la escena
- zFar será el valor valor del radio de la escena multiplicado por un valor lo suficientemente grande para visualizar la escena correctamente.
  - Finalmente se llaman a los métodos **projectTransform();** y **viewTransform();**

```c++
void NouGLWidget::iniCamera ()
{

  angleY = angleX = 0;
  
  fov = float(M_PI/3.0);
  zn = radiEsc;
  zf = 3*radiEsc;

  projectTransform();
  viewTransform();

}
```

### viewTransform()

 - Como ya se sabe las transformaciones se aplican de abajo hacia arriba.
 - Así pues primero se centra la cámara en el origen. 
 - Luego se rota según psi y theta. 
 - Finalmente se translada la cámara a la posición donde queremos situarla que es sobre la esfera contenedora de la escena.

```c++
void NouGLWidget::viewTransform() {

  float d = 2*radiEsc;
  // Matriu de posició i orientació
  View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -d));
  View = glm::rotate(View, angleX, glm::vec3(1.f, 0.f, 0.f));
  View = glm::rotate(View, -angleY, glm::vec3(0, 1, 0));
  View = glm::translate(View, -centreEsc);

  glUniformMatrix4fv (viewLoc, 1, GL_FALSE, &View[0][0]);

}
```

En la foto siguiente aparece explicado.

<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/IDI/images/image3.png" width=80%>
</p>

### projectTransform()

- Le damos valor a la matriz de proyección con el método **glm::perspective(fov, rav, zn, zf);**
- Finalmente se pasan los cambios al localizador projLoc.

```c++
void NouGLWidget::projectTransform() {

  float fov, zn, zf;
  glm::mat4 Proj;  // Matriu de projecció

  Proj = glm::perspective(fov, rav, zn, zf);

  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);

}

```

A             |  B
:-------------------------:|:-------------------------:
![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image1.png)  |  ![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image2.png)
