# Configuración de una cámara en tercera persona con angulos de Euler

Con tal de configurar una cámara en tercera persona hay que tener en cuenta un seguido de cosas:
 - Debemos mirar si estamos usando angulos de Euler para configurar esta cámara.
 - Dado que tenemos que tener en cuenta **psi (Ψ)** y **theta (Θ)** (angleY, angleX) sabemos que usamos Euler.

Supongamos una posición inicial de la cámara incorrecta o inexistente.
Los métodos que debemos modificar necesariamente son:

```c++
  void iniCamera ();
  void iniEscena ();
  void viewTransform ();
  void projectTransform ();
```

### iniCamera()

  - Este método sirve para inicializar la cámara. Al llevar angulos de Euler solo se inicializan estos.
  - Lo primero que debemos hacer es poner los angulos de rotación **psi (Ψ)** y **theta (Θ)** correspondientes.
  - Si no nos dan ningún valor se inicializan en 0 tal que **angleX = angleY = 0;**
  - Finalmente se llaman a los métodos **projectTransform();** y **viewTransform();**

```c++
void NouGLWidget::iniCamera ()
{

  rav = 1.0; //Necesario para el RESIZE()
  angleY = 0;
  angleX = M_PI/6.0;

  projectTransform();
  viewTransform();

}
```

### iniEscena()

 - Dado que tenemos que inicializar la escena y que usamos Euler solo ponemos el centro de la escena y el radio.
 - Lo primero de todo consiste en inicializar el valor del centro de la escena. Es decir, hacia donde va a mirar la cámara, el VRP.
 - La segunda cosa a tener en cuenta es el radio de la escena ya que lo usaremos posteriormente para el zNear y zFar en la projectTransform.

```c++
void NouGLWidget::iniEscena ()
{

  centreEsc = glm::vec3 (4, 2, 4);
  radiEsc = 6;
  
}
```
Para calcular el radio de la escena debemos hacer pitágoras.

<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/IDI/images/image4.jpeg" width=60%>
</p>

### viewTransform()

 - En la transformación para la View Matrix tendremos en cuenta las transformaciones geométricas pertinentes para situar
 la cámara correctamente.
 - Como ya se sabe las transformaciones se aplican de abajo hacia arriba.
 - Así pues primero se centra la cámara en el origen. 
 - Luego se rota según psi y theta. 
 - Finalmente se translada la cámara a la posición donde queremos situarla que es sobre la esfera contenedora de la escena.

```c++
void NouGLWidget::viewTransform() {

  // Matriu de posició i orientació
  View = glm::translate(glm::mat4(1.f), glm::vec3(0, 0, -2*radiEsc));
  View = glm::rotate(View, angleX, glm::vec3(1.0, 0.0, 0.0));
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

- En la projectTransform de configuran los parámetros de la cámara. Al usar Euler no definimos OBS y otros parámetros.
- Lo primero de todo consiste en declarar el FOV, el zNear, el zFar y la matriz de proyección.
- Para calcular el valor del FOV necesitamos el radio. 
  - **Fov = 2*arcsin(radiEscena/distància);**
  - **distància = 2*radiEscena;**
- zNear será el valor del radio de la escena
- zFar será el valor valor del radio de la escena multiplicado por un valor lo suficientemente grande para visualizar la escena correctamente.
- Le damos valor a la matriz de proyección con el método **glm::perspective(fov, rav, zn, zf);**
- Finalmente se pasan los cambios al localizador projLoc.

```c++
void NouGLWidget::projectTransform() {

  float fov, zn, zf;
  glm::mat4 Proj;  // Matriu de projecció

  fov = float(M_PI/3.0);
  zn = radiEsc;
  zf = 3*radiEsc;

  Proj = glm::perspective(fov, rav, zn, zf);

  glUniformMatrix4fv (projLoc, 1, GL_FALSE, &Proj[0][0]);

}

```



A             |  B
:-------------------------:|:-------------------------:
![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image1.png)  |  ![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image2.png)
