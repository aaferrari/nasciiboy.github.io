+++
title      = "Morg Mirror"
tags       = [ "morg" ]
categories = [ "prog" ]
date       = 2017-12-08T21:52:22-06:00
+++

<blockquote>
Una buena documentación es invaluable. Ya que cada uno tiene su propia definición de "bueno", aquí está la mía:

<ul>
<li><p>Los buenos documentos no me hacen buscar en la web</p></li>
<li><p>Los buenos documentos tienen ejemplos de trabajo con los que puedo empezar</p></li>
<li><p>Los buenos documentos siguen convenciones claras que fomentan hábitos de lectura</p></li>
</ul>

para mí, comenzar un nuevo proyecto significa escribir algo de código para poder
entender el problema que estoy tratando de resolver mejor. Hay mucha carga
cognitiva, porque es un territorio inexplorado: tengo que pensar mucho en
nombrar y en las dependencias entre partes.
</blockquote>

(lo lamento, pero no anote la direccion del post en ingles de donde extraje
estas perlas literarias, era sobre algo de golang vs xxx)

Y... de que va este post? son algunas reflexiones que considero interesantes
surgidas de la experimentacion al intentar dar cara y ojos a ese formato de
documentacion imaginario llamado morg

Sucede esto, el formato cuenta con enfasis del tipo `@e(enfasis)`, bien, esto
aplicaria enfasis al texto "enfasis". Da la casualidad que tambien para evitar
hacer cosas como `(@e(texto-con-enfasis-entre-parentesis))` y como permito la
*concatenacion de "comandos"* esto podria substituirse por
`@%e(texto-con-enfasis-entre-parentesis)`, donde el "comando" `%` significaria
"entre parentesis"... y resulta que tambien podria substuirse algo similar al
caso `“@c(codigo)”` por `@"c(codigo)` y fue entonces donde me cuestione, *¿son
estas construcciones lo suficientemente claras para quien desconosca tal
sintaxis?* por que, el proposito de formato es ser claro ante todo, tanto en su version
exportada, como directamente del *texto fuente*

pero vallamos mas alla, que tal si en *todo* texto se substitulle cualquier
texto entre parentesis, como entre comillas, por su equivalente a sistaxis `@x()`, es
decir todo `(texto entre parentesis)` pasaria a ser `@%(texto entre parentesis)`
y todo `“cita o algo”` como `@"(cita o algo)`

ignorando lo en principio absurdo de la propuesta, la segunda opcion, presenta
conveniencias a considerar

- se puede *aplicar un estilo* tanto de color, fuente e incluso modificar los
  signos de "contecion" (`()` y `“”`) por cualquier otra cosa, en toda aparicion
  y en solo una instruccion (de estilo)

- podria aplicarse un analisis al texto... por algun motivo que no alcanso a visualizar

- el texto resaltado seria inconfundible y evidente, sin lugar
  a dudas de lo que se desea transmitir mediante esta... supongo

- ... y no se me ocurre nada mas



entonces, aparecio una revelacion aun mas extraña, que significan exactamente
estas marcas "invisibles" que rodean al texto, y pasaron desapersividas hasta
este momento, de hecho, cuantas construcciones de este tipo hay en la escritura
y, si de forma simplificada (y mas o menos comoda) se permitiese una mayor
cantidad de estas construcciones, (como la de codigo `@c()`, atajos de teclado
`@k()`, definiciones `@:()` etc), que tanto podria desarrollarse el lenguaje?
podria presindirse con este (conveniente) resaltado de la necesidad de una
exportacion visual (ya que contendria toda la informacion)?

momento, algo se me escapa, algo importante que no habia contemplado pero
supongo existe por alguna parte, simplemente no tuve necesidad de conocerlo,
razon por la cual paso desapersivido, mas ahora necesito conocerlo e ignoro su
nombre, *estructura logica del lenguaje*?

y que es esto, te preguntaras, pues la forma logica sobre la que se estructura
el lenguaje, es decir parrafos, secciones(?), listas, listas numeradas, tablas,
citas, bloques(?) y demas elementos comunes del lenguaje escrito. Digo, considerando que
cualquiera que lea esto los ha utilizado o almenos los reconoce en la lectura,
seria extraño que no estubiese definido de forma precisa como, cuando, porque y
las implicaciones de utilizar cada uno de estos... y sus distintas
implementaciones en otros lenguajes, o es que acaso que en otras lenguas estos
no tienen su equivalente? tienen otros? porque, si en lugar de inventar bloques
arbitrarios (o etiquetas) para situaciones variadas, cuento con todas las
variaciones disponibles y sus casos de uso, quiza lo mas conveniente es aplicar
una sintaxis especifica para la mayoria de ellos, simplificarlos o incluso tras
un analisis crear nuevos

y si existe este analisas, hay propuestas para nuevas construccones del
lenguaje escrito o incluso propuestas alternativo-experimentales mas eficientes?

y asi acudi a reddit y a la wikipedia, mas, continuo sin respuesta, no dudo que
este tema *cuenta* con convenciones y tesis, pero no he acudido al lugar
indicado, pues al igual que en la programacion, la mayoria o toca
superficilmante un tema para apenas saber nada de el, o se especializa en
una pequeña seccion de su interes y desconoce el resto, como me atreveria a
decir que ocurre en los temas de mi interes, donde dichos temas especificos
parecen conjuros obscuros que nadie apenas conoce, menos entiende, y si existe
informacion, se encuentra en un plano academico al que tardare en acceder, del
cual seguramente me entere por mera casualidad escudriñando en algun manual olvidado

en fin, a grandes rangos aqui se contienen las inquietudes, el resto seria la
forma de trabajar con un fichero de traduccion *porg*, la forma de modificarlo y
transferir los cambios tanto a la traduccion como al fichero fuente

las letras serian mas si hablara sobre metodologias de adaptacion de un libro impreso a
su equivalente digital no pensado para impresion, traduccion y otros topicos,
pero eso sera mas tarde
