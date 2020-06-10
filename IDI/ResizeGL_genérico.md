# Redimensionar la escena al redimensionar la pestaña

Para poder redimensionar correctamente la escena cuando modificamos el tamaño de la pestaña hay que tener en cuenta una serie de cosas.
Lo más esencial es tener en cuenta que modificaremos el **FOV** y además necesitaremos una variable **ra** que mantenga la 
relación de aspecto correcta en cada momento.

- Lo primero que debemos hacer es declarar en el MyGLWidget.h o NouGLWidget.h (según estemos trabajando uno u otro)
una variable **float ra** (a veces se le llama **rav** (relación de aspecto de la ventana)) si no está ya creada.

- Seguidamente hay que darle un valor a **ra** por lo que en la función **iniCamera()** lo inicializaremos con un valor de
ra = 1.0 ya que esta es la relación de aspecto que se mantiene al ejecutar el programa. Es la relación de aspecto incial en la 
que no hay deformaciones al tener que la ventana es igual de X como de Y. **Ra = X/Y. Si x == y, ra = 1.0.**
  - Obviaremos lo comentado y nos fijaremos en el hecho de la inicialización de **ra = 1.0**.

```c++
 void MyGLWidget::iniCamera ()
 {
  // angleY = angleX = 0.0;
  ra = 1.0;
  // fov = float(M_PI/3.0);
  // zn = radiEsc;
  // zf = 3*radiEsc;

  // perspectiva = true;

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
   ample = w;
   alt = h;
   
   // Resize hacia arriba
   ra =  float(ample) / float(alt);

   // Resize hacia la izquierda
   float ang = asin(radiEsc/d); //Se calcula el ángulo que nos dan inicialmente
   //Destacar que este angulo podría ser perfectamente FOVinicial/2.0 si nos dicen que el fov de primeras
   if (ra < 1.0) fov = 2*(atan(tan(ang)/ra)); //Si la relación de aspecto es menor de 1 quiere decir que se ha redimensionado para hecerlo más pequeño
   else fov = float(M_PI/3.0);  //Valor para el fov que nos dicen inicialmente

   projectTransform (); //Obligatorio llamar a projectTransform()

 }

```

En el NouGLWidget() si resize es protected la idea sería heredar, llamar al padre y poner lo que falte de este código en el
resize que hemos heredado en NouGLWidget.

Si no fuese protected se podría hacer esto mismo pero en la projectTransfrom().
