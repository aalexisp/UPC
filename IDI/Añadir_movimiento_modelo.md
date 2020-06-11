# Añadir movimiento a un modelo

Para añadir movimiento a un modelo, en nuestro caso un Patricio deberemos crear una variable privada movimiento para cada componente que queremos moverque representará el movimiento del patricio.
Además para añadir este movimiento usaremos la función **KeyPressEvent()**.

 - Lo primero que haremos será acceder a MyGLWidget.h para declarar la variable de movimiento.
 ```c++ 
  private:
  //Variable de movimiento de Pat
  float movx;
  float movz;
 ```
 - Lo siguiente es inicializar el valor de esta variable en el **initializeGL()**:
 ```c++
  void NouGLWidget::initializeGL() {
    movx = 4.0;
    movz = 6.0;
  }

 ```
 
 - Una vez le hemos dado valor a la variable de movimiento hay que implementarla en la función de translate del modelo en el **modelTransform()**.
 
 ```c++
  void NouGLWidget::modelTransformPatricio2 ()
  {
    glm::mat4 patTG = glm::mat4(1.0f);

    patTG = glm::translate(patTG, glm::vec3(movx, 0.0, movz)); 
    patTG = glm::translate(patTG, -centreBasePat);
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &patTG[0][0]);

  }

 ```
 - Para terminar hay que aumentar o disminuir las coordenadas pertinentes de la variable de movimiento en la función *KeyPressEvent()**

 ```c++
  void NouGLWidget::keyPressEvent(QKeyEvent* event)
  {
    makeCurrent();
    switch (event->key()) {
      case Qt::Key_S: {
          movP2[2] = movP[2] + 0.5;
        break;
      }
      case Qt::Key_W: {
          movP[2] = movP[2] + 0.5;
        break;
      }
      case Qt::Key_A: {
          movP[0] = movP[0] - 0.5;
        break;
      }
      case Qt::Key_D: {
          movP[0] += movP[0] + 0.5;
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
 
 
 
 
 
 
