# Interacció de disseny i avaluació.

## ------------------------------- Teoría de la información --------------------------------

  - ### La **Teoría de la información** se basa en la comunicación de información.
      - **Fuente de información** (Input, elemnto productor del mensaje)
      - **Transmisor** (Opera con el mensaje para pasarlo al canal)
      - **Canal** (Pc, teléfono, correo, es el medio de transmisión)
      - **Receptor** (Recibe el mensaje del canal y lo reconstruye)

<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/IDI/images/image12.PNG" width=60%>
</p>

  - ### Principio de incertidumbre
 
El principio de incertidumbre establece la imposibilidad de que determinados pares de magnitudes 
físicas observables y complementarias sean conocidas con precisión arbitraria.

#### Ejemplo 1: Sea *d* un dispositivo que produce un símbolo *C* (Supongamos que C es algo con probabilidad 100% de aparecer).
En este caso no tenemos incertidumbre dado que sabemos con certeza cual será el resultado. 

<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?log_2(1)%20=%200" width=10%>
</p>

#### Ejemplo 2: Sea *d* un dispositivo (una moneda) que produce dos símbolos *A* (cara) y *B* (cruz) en los que ambos
tienen la misma probabilidad de aparacer. Un 50% cada una.

Dado que A y B pueden aparecer con la misma probabilidad no sabemos con certeza qué puede aparecer por lo que tendremos una 
incertidumbre de:

<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?log_2(2)%20=%201" width=10%>
</p>

- En general cuando tenemos diversos símbolos y estos tienen la misma probabilidad o muy similar tenemos más incertidumbre.
- Cuando tenemos que una opción es más probable que la otra tenemos menos incertidumbre.

Sea M el número de símbolos y **P = 1/M** la probabilidad que que aparezca un símbolo *la sorpresa* se define tal que:

<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?-log_2(P)" width=10%>
</p>

 - ### La entropía
 
La entropía de shennon mide la cantidad de información.

Sea **N** el número de alternativas y **p** la probabilidad la alternativa i.

<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?H%20=%20-%20\sum_{1}^{N}%20(p_i%20*%20log_2(p_i))" width=30%>
</p>

Existe una posible **interferencia** la cual provoca que no se reciba correctamente el mensaje y llegue alterado.

La cantidad de información correctamente recibida es:
<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?R%20=%20H(X)%20-%20H_y(X)" width=30%>
</p>
donde Hy(X) es la equivocación o entropía adicional de x cuando y es desconocida.

## --------- Ley de Hick-Hyman : Medición del tiempo de elección-reacción -----------

 - Describe el **tiempo de decisión humano** en función del contenido de información transmitido por un estímulo visual.
 - Tardaremos más en responder a un estímulo que pertenece a un gran conjunto que a diferencia de cuando hay pocos.
 - La función de Hick es logaritmica de normal.
 - Para los usuarios más novatos la función del tiempo de reacción escala linealmente
 
Sea **a** y **b** constantes junto con **RT** (reaction time) y **Ht** la información transmitida:
<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?RT%20=%20a%20+%20b*H_t" width=30%>
</p>

#### La ley de Hick-Hyman dice que:

Siendo **n** el número de alternativas equiprobables (y no equiprobables dado que se demostró que daba igual resultado) y el **+1**
que indica la posibilidad de fallo:

<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?H_t%20=%20log_2(n+1)" width=30%>
</p>

## ------------------ Ley de Fitt : Medición del tiempo de señalización ------------------

 - La ley de Fitt establece una relación lineal entre la dificultad de una tarea y el tiempo de movimiento. Esencialmente con la mano.
 - No funciona muy bien para objetivos muy pequeños
 - La ley es válida para mouse, joysticks, dedo... pero hay algunos otros para los que no.
 - La amplitud es la distancia hasta el rectangulo que representa el target.
 - La anchura es la distancia desde el target hasta donde ha quedado mouse, dedo, mano...
 
Sea **ID** la dificultad de la tarea, A la amplitud del movimiento y W la anchura de este:

<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?ID%20=%20log_2(2A/W)" width=30%>
</p>

Sea **MT** el movement time:

<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?MT%20=%20a%20+%20b*ID" width=30%>
</p>

Una adaptación de la ley de Fitt es la de la aproximación de **MacKenzie**:

<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?MT%20=%20a%20+%20b%20*%20ID%20=%20a%20+%20b%20*%20log_2%20(D/W%20+%201)" width=50%>
</p>

## ---------------- Leyes de Crossing y Steering Laws: gestos continuos -----------------

 - La ley de crossing consiste en el movimiento continuo o discreto (con saltos) del cursor, dedo...
 - Es similar al pointing pero no es lo mismo. 
    - El pointing consiste en llegar a un objetivo como un botón.
    - El crossing consiste en pasar ese objetivo.
    - Normalmente el crossing es una alternativa para la gente que no puede o le es difícil hacer click o doble click.
    - Sigue la fórmula de Fitt
  
  - La ley de Steering es similar pero su funcionamiento consiste en la navegación por menús, nagegación 3d...
    - Sea Ts el tiempo de movimiento a través de un camino
    - ds el tamaño del camino.
    - C la longitud del camino.
    - W(s) el camino hasta el punto s.
    
<p align="center">
	<img src="https://latex.codecogs.com/svg.latex?T_s%20=%20a%20+%20b*\int_{c}%20\frac{ds}{W(s)}" width=30%>
</p>

## --------------------- Let de Fitt en un diseño UI (User Interface) ----------------------

 - Los bordes de la pantalla tienen tamaño infinitos por lo tanto es facil juntarlo.
 - Es esencial mantener las cosas que están relacionadas juntas y las opuestas lejos entre ellas.
 - Los menús pop-up reducen la distancia a recorrer pero suele usarlo gente que sabe.
 - Incrementamos la percepción si agrupamos las cosas con un vacío por medio.
 - Cuanto más grandes sean los botones más usable son.
 - Hacer las cosas destructivas como apagar el teléfono más difíciles para evitar el fallo.
    - Por ejemplo para apagar el teléfono en vez de un botón hacemos un slider como en iphone.
 - Existen los menús *Pie* (llamado así por su forma de pastél cortado por la mitad).
 
 ## -------------------------- Acelerar el tiempo de adquisición ---------------------------
 
  - Ampliación de objetos:
    - Aumentar la mida de las cosas cercanas al cursor, como el Dock en MacOS.
    - Bubble Target: Amplía la región por la que puedes seleccionar cierto target. (No recomendable).
    - Bubble cursor: Se amplía el cursor cuando hay algún objetivo cerca. Puede absorber este objetivo.
  - Movimiento del objetivo:
    - Acercar el objeto al usuario.
    - Generar texto cerca del pop-up-
  - Control-display ratio:
    - Hay un mapeo del movimiento con la mano en la vida real en el mouse (3D).
