# Añadir movimiento a un modelo

Para añadir movimiento a un modelo, en nuestro caso un Patricio deberemos crear una variable privada glm::vec3 movimiento 
que representa el movimiento del patricio.
Además para añadir este movimiento usaremos la función **KeyPressEvent()**.

 - Lo primero que haremos será acceder a MyGLWidget.h para declarar la variable de movimiento.
 ```c++ 
  private:
  //Variable de movimiento de Pat2
  glm::vec3 movP2;
 ```
 - Lo siguiente es inicializar el valor de esta variable en el **initializeGL()**:
 ```c++
  void NouGLWidget::initializeGL() {
    MyGLWidget::initializeGL();
    posFocus = glm::vec3(0.0, 0.0, 0.0);
    movP2 = glm::vec3(4.0, 0.0, 6.0); //<-----------------
    // Linkeamos los parámetros con los localizadores
    glUniform3fv(posFocusLoc, 1, &posFocus[0]);
  }

 ```
 - (NECESARIO ANTERIORMENTE) Antes de nada es preciso llamar en el **paintGL()** a la función **modelTransform()** que vamos a crear. Esto es obligatorio siempre y cuando el modelo no esté pintado. Se explica en [Pintar_Modelo_TG](https://github.com/aalexisp/UPC/blob/master/IDI/Pintar_Modelo_TG.md):
 
 ```c++
  void NouGLWidget::paintGL() {
   MyGLWidget::paintGL(); //<------------- Llamada al padre porque usamos NouGLWidget (otro esquema)
                  
   //Obligatorio ponerlo
   glBindVertexArray (VAO_Pat); // Activamos el VAO para poder añadir la transformación
   modelTransformPatricio2(); //<-------------- ModelTransform nueva
   glDrawArrays(GL_TRIANGLES, 0, patModel.faces().size()*3); // Pintamos cada uno de los vértices
 }
 ```
 
 - Una vez le hemos dado valor a la variable de movimiento hay que implementarla en la función de translate del modelo en el **modelTransform()**.
 ```c++
  void NouGLWidget::modelTransformPatricio2 ()
  {
    glm::mat4 patTG = glm::mat4(1.0f);

    patTG = glm::translate(patTG, movP2); <----------------------
    float rot = M_PI;
    //Rotar el patricio 90 grados para que mire a x positivo
    patTG = glm::rotate(patTG, rot, glm::vec3(0.0, 1.0, 0.0));
    //Escalar el Patricio para que tenga altura 2
    patTG = glm::scale(patTG, glm::vec3(escalaPat*3));
    //Transladar al origen de coordenadas
    patTG = glm::translate(patTG, -centreBasePat);
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &patTG[0][0]);

  }

 ```
 - Para terminar hay que aumentar o disminuir las coordenadas pertinentes de la variable de movimiento en la función *KeyPressEvent()**
 - En este ejercicio hay que comprovar el Patricio no se salga del suelo ni atraviese paredes por lo que se comprueba con ifs.
 - Para ello aumentaremos o disminuiremos esta variable tal que:
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
      default: {
        MyGLWidget::keyPressEvent(event);
        break;
      }
    }
    update();
  }

 ```
 
 
 
 
 
 
