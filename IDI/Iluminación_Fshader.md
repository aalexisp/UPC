
# Iluminación de Phong en el Fragment Shader

### Lo primero a tener en cuenta es el hecho de saber en qué posición queremos el foco de luz. En este ejercicio se hará en coordenadas del observador (Posteriormente en otras coordenadas).

(RECOMENDADO MIRAR iluminación_Vshader)

La diferencia entre poner el foco en un sistema de coordenadas u otro como se ve en la siguiente foto depende de por qué multiplicamos la posición del foco.
 - Si queremos **el foco en la posición de la cámara** debemos tener en cuenta que las coordenadas de normal están en **SCO** (coordenadas del observador, la cámara) por lo que no hay que tocar nada.
 - Si queremos en cambio tener **el foco de luz respecto la escena**, es decir en **SCA** (sistema de coordenadas de la escena) habrá que multiplicar la posición del foco (posFocus) por la viewMatrix tal que **posFocus = View * glm::vec3(coord);** (View a la izquierda).
 - Finalmente si queremos **el foco de luz encima del modelo** tendremos que mutliplicar por la **View y por la matríz de transformaciones geométricas**.

A             |  B
:-------------------------:|:-------------------------:
![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image5.png)  |  ![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image7.png)

Tendremos en cuenta que hacemos la aplicación de la iluminación en MyGLWidget y luego en NouGLWidget.
 - Lo primero a tener en cuenta es si las variables **posFocus, colorFocus y llumAmbient** la pasaremos como uniform o no.
 - En nuestro caso el único **uniform será posFocus** y las otras dos estarán inicializadas en el **vertex shader**.
 - Al tener posFocus como uniform necesitaremos un uniform por lo que en el **MyGLWidget.h** tendremos:
  ```c++
    // uniform locations
    GLuint posFocusLoc;
    // variable a la que le daremos valor localmente en el initializeGL y luego linkearemos con el localizador
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
    // Cal inicialitzar l'ús de les funcions d'OpenGL
    initializeOpenGLFunctions();  

    glClearColor(0.05, 0.3, 0.1, 1.0); // defineix color de fons (d'esborrat)
    glEnable(GL_DEPTH_TEST);
    carregaShaders();
    iniEscena ();
    iniCamera ();  
  
    //Se le da valor al PosFocus, al estar en coordenadas del obervador (SCO, cámara) debemos poner x = y = z = 0
    posFocus = glm::vec3(0.0, 0.0, 0.0);
    //SI LO QUEREMOS EN SCA
    //posFocus = View* glm::vec4(X, Y, Z, 1.0); //X, Y, Z son valores que tu le pones manualmente según lo que te pidan.
    //SI LO QUEREMOS ENCIMA DEL MODELO
    //posFocus = View*TG*glm::vec4(X, Y, Z, 1.0); //El 1 es para normalizar el vector ya que al multiplicar por la VIEW es necsario un vector de 4 valores.
    
  
    // Linkeamos los parámetros con los localizadores
    glUniform3fv(posFocusLoc, 1, &posFocus[0]);
  
}

  ```
 - **SI LO QUEREMOS EN SCO**
 ```c++ 
 posFocus = glm::vec3(0.0, 0.0, 0.0);
 ```
 - **SI LO QUEREMOS EN SCA**
 ```c++ 
 posFocus =  View* glm::vec4(X, Y, Z, 1.0)
 ```
 - **SI LO QUEREMOS ENCIMA DEL MODELO**
 ```c++
 posFocus = View*TG*glm::vec4(X, Y, Z, 1.0);
 ```
 - La parte importante empieza cuando hay que modificar el **vertex shader**:
  - Al haber pasado el cálculo de la iluminación al fragment shader debemos cambiar las variables de entrada y salida junto con los uniforms que se declararán en el fragment shader. 
  - Las variables que antes eran de entrada ahora **también** son de salida.
  - Los uniforms se pasan al fragment shader.
  
  ```c++  
  in vec3 vertex;
  in vec3 normal;

  in vec3 matamb;
  in vec3 matdiff;
  in vec3 matspec;
  in float matshin;

  uniform mat4 proj;
  uniform mat4 view;
  uniform mat4 TG;


  out vec3 vertexF;
  out vec3 normalF;

  out vec3 matambF;
  out vec3 matdiffF;
  out vec3 matspecF;
  out float matshinF;
  ``` 
  - Ahora las funciones de Phong y lambert no se van a usar aqui por lo que se pueden comentar.
  - Seguidamente hay que modificar el **main()** del vertex shader
    - Dado que todas las variables que nos pasan hay que pasarlas al fragment shader a las variables out se les guarda el valor que tienen las variables in:
    - Debemos tener en cuenta también que hay algunas bariables que se tienen que normalizar en en vertex shader antes de pasarlas al fragment como **vertex**, **NormalMatrix** y **normal**
    
    ```c++
    void main() {
      //fcolor = matdiff;

      //paràmetres que cal passar al fragment shader
      vertexF = (view * TG * vec4(vertex, 1.0)).xyz;

      //passar vector normal a SCO
      mat3 NormalMatrix = (inverse(transpose(mat3(view * TG))));
      normalF = NormalMatrix * normal;

      matambF = matamb;
      matdiffF = matdiff;
      matspecF = matspec;
      matshinF = matshin;

      gl_Position = proj * view * TG * vec4 (vertex, 1.0);
    }

    ```
    
    
    
  - Por consiguiente hay que modificar el **fragment shader**
    - Lo primero de todo es pasar las variables como in y declarar los uniform
    ```c++
    //in vec3 fcolor;
    out vec4 FragColor;

    in vec3 vertexF;
    in vec3 normalF;

    in vec3 matambF;
    in vec3 matdiffF;
    in vec3 matspecF;
    in float matshinF;

    // Valors per als components que necessitem dels focus de llum
    vec3 colFocus = vec3(0.8, 0.8, 0.8);
    vec3 llumAmbient = vec3(0.2, 0.2, 0.2);

    //uniform vec3 llumAmbient; //No uniform en este ejercicio
    //uniform vec3 colFocus; //No uniform en este ejercicio
    uniform vec3 posFocus;
    ```
    - Lo siguiente que hay que hacer es declarar las funciones de Phong y Lambert aunque normalmente te las dan:
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

    vec3 Phong (vec3 NormSCO, vec3 L, vec4 vertSCO)
    {
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
    
    - Para ir acabando hay que declarar el **main()**
      - Aqui es basicamente donde normalizaremos lo que no normalizamos en el vertex shader y le aplicamos la función de Phong. Aqui FragColor es el valor que se pasa a la GPU para computar el color por lo que aqui no es fcolor.
    
    ```c++
    void main()
    {
        //Direcció de la llum
        vec3 L = normalize(posFocus - vertexF.xyz);
        vec3 NM = normalize(normalF);
        vec3 color = Phong(NM, L, vec4(vertexF, 1));

        FragColor = vec4(color,1);
      }

    ```

A             |  B
:-------------------------:|:-------------------------:
![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image8.png)  |  ![](https://github.com/aalexisp/UPC/blob/master/IDI/images/image9.png)
