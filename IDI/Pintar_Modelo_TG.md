### PINTAR UN MODELO EN LA ESCENA CON SUS TRANSFORMACIONES PERTITENTES


Para poder modificar un modelo, en este caso un Patricio hay que tener una serie de cosas en cuenta.
 - Las transformaciones que realmente hacemos van de abajo hacia arriba.
 - La primera transformación es la de **TG = glm::translate(TG, -centreBasePatricio);** que envia el patricio al origen de coordenadas.
 - Para poder rotar y escalar el patricio hay que tenerlo posicionado en el origen de coordenadas.
 - La función rotate funciona tal que:
    - "angulo" es un float que indica el angulo con el que vamos a rotar el modelo.
    - el **glm::vec3(0.0, 1.0, 0.0)** indica sobre que eje queremos rotar el patricio. En este caso el patricio rota sobre si mismo porque el eje que pusimos es el Y.
 - La función scale escala el patricio según un vec3. En este caso queremos tener un patricio de altura 2 y nos pasan un float que pondremos multiplicado por la altura que quremos en un vec3.
 - La función translate posiciona el patricio según el vec3 pos.
 - Finalmente hay que pasarle al localizador transLoc la matriz de transformaciones geométricas que acabamos de hacer con **glUniformMatrix4fv(nombreLoc, 1, GL_FALSE, &TG[0][0]).**

```c++
void MyGLWidget::modelTransformPatricio(){

  //Primero se declara una matriz de 4x4 inicializada como la matriz identidad para hacer las transformaciones sobre esta.
  glm::mat4 TG(1.0f);
  
  TG = glm::translate(TG, pos); //<---- última transformación que se aplica al modelo.
  TG = glm::scale(TG, glm::vec3(escalaPat*2));
  TG = glm::rotate(TG, angulo, glm::vec3(0.0, 1.0, 0.0));
  TG = glm::translate(TG, -centreBasePatricio); //<---- primera transformación que se aplica al modelo.

  glUniformMatrix4fv (transLoc, 1, GL_FALSE, &TG[0][0]);

}
```

También debemos tener en cuenta el hecho de que no solo podemos aplicar las transformaciones y pensar que ya estamos.
Hay que activar el VAO del patricio, aplicar la matriz de transformación geométrica y luego pintar con el método **glDrawArrays(forma_de_pintar, 0, numero_de_vértices)**.

```c++
void NouGLWidget::paintGL() {

  glBindVertexArray (VAO_Pat);
  modelTransformPatricio2();
  glDrawArrays(GL_TRIANGLES, 0, patModel.faces().size()*3);

}
```


<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/IDI/images/image.png" width=60%>
</p>
