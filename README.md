Descripción del programa

Supóngase que usted es una persona que accedió a la terminal de vuelos desde la comodidad de su casa y quiere comprar boletes para usted y su novia para viajara a algún país externo, entonces aquí es donde entra el uso de este programa.

Si bien el programa no tiene todas las funciones que tiene una terminal, me pareció que como lo dejé está correcto para una proyecto final, hubo veces en las que tuve que FORZAR EL USO de algunas “HERRAMIENTAS de POO” para que cumpliera con todos los puntos solicitados COMPLICANDO ASÍ el programa, pero el resultado final si cumple con su función, estaba mejor estructurado con relaciones de agregación (como lo tenía de inicio), pero al FORZAR la herencia quedó un producto más complicado de entender, pero esta es la explicación.

*Lo primero es mi clase Aeropuerto que es abstracta, no hay mucho que comentar sobre ello.

*Se deriva mi clase Vuelos, en vuelos solo tendré la información de cada vuelo junto con un método que me ayuda a mostrar los datos de vuelo.

*De Vuelos se deriva Clientes, Clientes es la clase que más funciones tiene ya que es a través de la cual accedo a los métodos de las demás clases, cada método está comentando para su comprensión, Cliente tiene la información de cada Cliente, pero todo se trabaja con constructores, ya que como dije anteriormente tenía que cumplir con todos los puntos dados y eso COMPLICÓ muchísimo el código, por lo que el constructor necesita los atributos de Cliente y los de Vuelo.

Con consulta se muestran los datos de Cliente, dependiendo de si ya está lleno, de si tiene datos en vuelos o de si solo tiene datos de Cliente.

Los operadores sobrecargados -,< sirve para crear una cuenta nueva y sirven para validar que la información sea correcta para entrar a una cuenta respectivamente.

Los métodos muestra son netamente para mostrar los datos de los vuelos disponibles ya sea ordenados o no, si quiere saber como se ordenó puede revisar los comentarios de cada método muestra.

setAsiento sirve para que el o los asientos escogidos por el cliente se guarden en mi nuevo objeto de cliente.

Por último compra, como todo se accede a través de la clase Cliente entonces lo que se hace con compra es recibir 2 objetos Cliente, los cuales además de tener sus propios datos entonces se complementarán entre si y así tener un objeto Cliente lleno (con datos de Vuelo y Cliente).

*Assi y AsiPol son Clases que netamente solo incluí para cumplir con la cuota de polimorfismo, así se ve que hubo cosas que tuve que FORZAR para poder usar y COMPLIQUÉ todo mi código.
Conclusión: creo yo que no debí forzar nada para cumplir con todos los puntos señalados para la práctica pero mi falta de experiencia me limitó al momento de hacer el diagrama de clases ya que lo tuve que estar cambiando constantemente a través de las veces que tuve que incluir alguno de los puntos nuevos, ya que originalmente solo cumplía con operadores, sobrecarga y clase abstracta.

Nota: Si quiere acceder a los datos de mi mini base de datos (pensaba hacerla con ficheros, pero la terminé haciendo con puros objetos de clase y constructores) solo tengo 2 cuentas asociadas.

1)correo: guadalup123@gmail.com
 contraseña: Papas*2
2) correo: beniLoco17@hotmail.com
 contraseña: sacAtemop4n

