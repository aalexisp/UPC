# Pràctica 1: Configuració d'interfícies, routing estátic i taules d'encaminament (LINUX)

`Los corchetes [ ] indican que el parámetro es opcional`

### Comandos:
 - **ifconfig**: 
 Comando para configurar una interficie de un dispositivo: Router, PC. Configurar en términos de asignar una ip, una máscara y si fuese necesario una dirección de broadcast.
 
    - **ifconfig** *interficie* *dirección_ip* **netmask** *máscara* [**broadcast** *dirección_broadcast*]
    
        > ifcconfig e0 192.168.60.1 netmask 255.255.255.0 broadcast 192.168.60.255
        
        > ifconfig e0 10.2.0.2 netmask 255.255.255.0
	
    - **ifconfig** *interficie* *up/down*
    
<p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/XC/images/image1.PNG" width=60%>
</p>

  - **route**:
  Comando para crear una entrada en la **tabla de enrutamiento/encaminamiento**. Esta tabla contiene la ruta de los nodos de nuestra red. Donde un nodo es cualquier dispositivo conectado a la red.
  
    - **route** **add|del** **-net|-host** *ip_destinación* [**netmask** *máscara*] [**gw** *gateway*] [**dev** *intf*]
	
        > route add -net 10.3.0.0 netmask 255.255.255.0 gw 10.2.0.2

        > route add default gw 10.2.0.2  // default = 0.0.0.0
	
 En este ejemplo suponemos que este comando se aplica en PC1. En la tabla de encaminamiento estariamos diciendo que mediante la interfície de nuestro PC que está conectada con 10.2.0.2 (que probablemente sea la ip de la interfície de un router u otro PC) estaríamos accediendo la ip (network) 10.3.0.0 que es la ip asignada a otra interfície de otro PC conectado necesariamente al router o PC que hace de intermediario o host.
 
 <p align="center">
	<img src="https://github.com/aalexisp/UPC/blob/master/XC/images/image2.PNG" width=60%>
</p>
 
   - **ping**: 
   Comando para enviar paquetes hacia un dispositivo (para comprobar conectividad usualmente).
   
     - **ping** *dirección_ip*
    	
		> ping 192.168.2.10
 
  - **traceroute**: 
    Comando que permite saber por qué interfícies pasan los datos al enviar paquetes.
      
     - **traceroute** *dirección_ip*
     		> traceroute 192.168.2.10
  
  - **tcpdump**: 
  Permite caprurar información sobre los paquetes que nos envian o se envian desde una interfície.
  
     - **tcpdump** **-n** **-i** *interfície*
     
  		> tcpdump -ni e0
  
