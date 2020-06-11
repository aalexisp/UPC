# Redimensionar la escena al redimensionar la pestaña

Para poder redimensionar correctamente la escena cuando modificamos el tamaño de la pestaña hay que tener en cuenta una serie de cosas.
Lo más esencial es tener en cuenta que modificaremos el **FOV** y además necesitaremos una variable **ra** que mantenga la 
relación de aspecto correcta en cada momento.

- Lo primero que debemos hacer es declarar en el MyGLWidget.h o NouGLWidget.h (según estemos trabajando uno u otro)
una variable **float ra** (a veces se le llama **rav** (relación de aspecto de la ventana)) si no está ya creada.

- Seguidamente hay que darle un valor a **ra** por lo que en la función **iniCamera()** lo inicializaremos con un valor de
ra = 1.0 ya que esta es la relación de aspecto que se mantiene al ejecutar el programa. Es la relación de aspecto incial en la que no hay deformaciones al tener que la ventana es igual de X como de Y. **Ra = X/Y. Si x == y, ra = 1.f.**
  - Obviaremos lo comentado y nos fijaremos en el hecho de la inicialización de **ra = 1.f**.

```c++
 void MyGLWidget::iniCamera ()
 {
 
  ra = 1.f;
  FOVini = fov;

   projectTransform ();
   viewTransform ();
 }
```

- A continuación se modifica la función **resizeGL()** que es la que se llama cada vez que se redimensiona la pestaña 
(normalmente con el mouse).
  - Cabe destacar que no es la única implementación posible. Hay diversas variantes pero la idea principal es tener en cuenta
  el hecho de que necesitaremos el fov o angulo anterior a la redimensión.

```c++
 void MyGLWidget::resizeGL (int w, int h)
 {
   // Resize hacia arriba
   ra =  float(ample) / float(alt);

   // Resize hacia la izquierda
  if (ra < 1.f) FOV = 2.f*atan(tan(FOVini/2.f)/ra); //Si la relación de aspecto es menor de 1 quiere decir que se ha      redimensionado para hecerlo más pequeño
   else if (ra > 1.f) fov = float(M_PI/3.f);  //Valor para el fov que nos dicen inicialmente

   projectTransform (); //Obligatorio llamar a projectTransform()

 }

```
