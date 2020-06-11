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
    movx = 4.f;
    movz = 6.f;
  }

 ```
 
 - Una vez le hemos dado valor a la variable de movimiento hay que implementarla en la función de translate del modelo en el **modelTransform()**.
 
 ```c++
  void NouGLWidget::modelTransformPatricio2 ()
  {
    glm::mat4 patTG = glm::mat4(1.0f);

    patTG = glm::translate(patTG, glm::vec3(movx, 0.f, movz)); 
    patTG = glm::translate(patTG, -centreBasePat);
    glUniformMatrix4fv(transLoc, 1, GL_FALSE, &patTG[0][0]);

  }

 ```
 - Para terminar hay que aumentar o disminuir las coordenadas pertinentes de la variable de movimiento en la función *
 **KeyPressEvent()**

 ```c++
  void NouGLWidget::keyPressEvent(QKeyEvent* event)
  {
    makeCurrent();
    switch (event->key()) {
      case Qt::Key_S: {
          movz = movz + 0.5f;
        break;
      }
      case Qt::Key_W: {
          movz = movz + 0.5f;
        break;
      }
      case Qt::Key_A: {
          movx = movx - 0.5f;
        break;
      }
      case Qt::Key_D: {
          movx += movx + 0.5f;
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
 
 
 
 
 
 
