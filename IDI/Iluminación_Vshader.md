# Iluminación de Phong en el Vertex Shader

### Lo primero a tener en cuenta es el hecho de saber en qué posición queremos el foco de luz.

La diferencia entre poner el foco en un sistema de coordenadas u otro como se ve en la siguiente foto depende de por qué multiplicamos la posición del foco.
 - Si queremos **el foco en la posición de la cámara** debemos tener en cuenta que las coordenadas de normal están en **SCO** (coordenadas del observador, la cámara) por lo que no hay que tocar nada.
 - Si queremos en cambio tener **el foco de luz respecto la escena**, es decir en **SCA** (sistema de coordenadas de la escena) habrá que multiplicar la posición del foco (posFocus) por la viewMatrix tal que **posFocus = View * glm::vec3(coord);** (View a la izquierda).
 - Finalmente si queremos **el foco de luz encima del modelo** tendremos que mutliplicar por la **View y por la matríz de transformaciones geométricas**.

A             |  B
:-------------------------:|:-------------------------:
![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image5.png)  |  ![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image7.png)

<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/IDI/images/image10.png" width=60%>
</p>

 - Lo primero a tener en cuenta es si las variables **posFocus, colorFocus y llumAmbient** la pasaremos como uniform o no.
 - Al tener posFocus como uniform necesitaremos un uniform por lo que en el **MyGLWidget.h** tendremos:

```c++
    GLuint posFocusLoc;
    glm::vec3 posFocus
  ```
  
  - Seguidamente en el **carregashaders()** hay que iniciar el localizador al final de la función tal que:
  ```c++
    posFocusLoc = glGetUniformLocation (program->programId(), "posFocus");
  ```
  - Una vez hecho esto hay que ir al **initializeGL()** e inicializar el posFocus y luego pasarlo al localizador.
  ```c++
  void MyGLWidget::initializeGL ()
  {
    //Se le da valor al PosFocus, al estar en coordenadas del obervador (SCO, cámara) debemos poner x = y = z = 0
    posFocus = glm::vec3(0.f, 0.f, 0.f);
  
    glUniform3fv(posFocusLoc, 1, &posFocus[0]);
   }

  ```
 - **SI LO QUEREMOS EN SCO**
 ```c++ 
 posFocus = glm::vec3(0.f, 0.f, 0.f);
 ```
 - **SI LO QUEREMOS EN SCA**
 ```c++ 
 posFocus =  View* coord
 ```
 - **SI LO QUEREMOS ENCIMA DEL MODELO**
 ```c++
 posFocus = View*TG*coord
 ```
 
 - Por último hay que modificar el **vertex shader**:
  - Lo primero que debemos hacer es declarar como uniform las variables que nos piden, en este caso posFocus
  ```c++
#version 330 core

in vec3 vertex;
in vec3 normal;

in vec3 matamb;
in vec3 matdiff;
in vec3 matspec;
in float matshin;

uniform mat4 proj;
uniform mat4 view;
uniform mat4 TG;

uniform vec3 posFocus;

// Valors per als components que necessitem dels focus de llum
vec3 colFocus = vec3(0.8, 0.8, 0.8);
vec3 llumAmbient = vec3(0.2, 0.2, 0.2);

out vec3 fcolor;
  ```
  - Una vez declarados habría que guardar las funciones de Lambert y Phong pero normalmente te las dan:
  ```c++
vec3 Lambert (vec3 NormSCO, vec3 L) 
{
    // S'assumeix que els vectors que es reben com a paràmetres estan normalitzats

    // Inicialitzem color a component ambient
    vec3 colRes = llumAmbient * matamb;

    // Afegim component difusa, si n'hi ha
    if (dot (L, NormSCO) > 0)
      colRes = colRes + colFocus * matdiff * dot (L, NormSCO);
    return (colRes);
}

vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO) {
    // Els vectors estan normalitzats

    // Inicialitzem color a Lambert
    vec3 colRes = Lambert (NormSCO, L);

    // Calculem R i V
    if (dot(NormSCO,L) < 0)
      return colRes;  // no hi ha component especular

    vec3 R = reflect(-L, NormSCO); // equival a: normalize (2.0*dot(NormSCO,L)*NormSCO - L);
    vec3 V = normalize(-vertSCO.xyz);

    if ((dot(R, V) < 0) || (matshin == 0))
      return colRes;  // no hi ha component especular
    
    // Afegim la component especular
    float shine = pow(max(0.0, dot(R, V)), matshin);
    return (colRes + matspec * colFocus * shine); 
}
  ```
  
  - Por último declarar y operar todo lo necesario en el **main()**
    - Después debemos aplicar la inversa de la transpuesta a de la VIEW por TG para tener la NormMatrix
    - Hay que pasar la normal a SCO empezando por normalizar la normal usando normalize(NormalMatrix*normal)
    - También hay que pasar el vertex a SCO por lo que se multiplica por la view y por la TG
    - Aqui podemos hacer dos cosas:
      - Necesitamos el posFocus para luego pasarlo a la función de Phong.
      - Podemos declararlo aqui multiplicando por la view o la TG pero es mejor hacerlo en el .cpp como hemos visto antes
      - Se podría hacer aqui igualmente pero es mejor en el .cpp
     - Necesitamos el vector L normalizado y pasado a SCO por lo que se restan las componentes xyz del posFocus y vertex
     - Finalmente se usa la función que aplicaremos y pasaremos al fragmentshader haciendo fcolor = función()
      
  ```c++
  void main()
{
//    fcolor = matdiff; 

    vec4 vertSCO = view * TG * vec4 (vertex, 1.0);
    mat3 normalMatrix = inverse (transpose (mat3 (view * TG)));
    vec3 normalSCO = normalize (normalMatrix * normal);
    vec4 focusSCO = view * vec4 (posFocus, 1.0);
    vec3 L = normalize (focusSCO.xyz - vertSCO.xyz);
    fcolor = Phong(normalSCO, L, vertSCO);
    gl_Position = proj * view * TG * vec4 (vertex, 1.0);

}
  ```


<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/IDI/images/image6.png" width=60%>
</p>

<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/IDI/images/image11.png" width=60%>
</p>

