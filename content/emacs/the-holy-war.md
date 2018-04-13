+++
title      = "The Holy War"
tags       = [ "trl" ]
categories = [ "emacs" ]
date       = 2018-04-08T10:35:54-05:00
+++

Post original (04/12/2001) -> https://www.linux.com/news/emacs-vs-vi-endless-geek-holy-war

<div class="hBody-1" >
<p><b>Author:</b> <a href="mailto:jtsmith@brunswickwdi.com" >JT Smith</a></p>
<p>Ahí van de nuevo. El presidente de nuestro grupo local de usuarios de Linux envió el mensaje de que el tutorial de la semana sería cancelado. El hecho de que el tutorial fuera sobre el uso del editor de texto vi fue suficiente para iniciar una nueva ronda de tiros de última hora.</p>
<p>Greg Menke disparó la primera salva. Usar vi? ¿Qué tan difícil puede ser? Envió por correo electrónico sus propios pasos para usar vi. Fueron estos:</p>
<ol class="num" >
<li>
<p>Adquirir un pecado, de cualquier tipo, longitud &gt; 30 cm</p>
</li>
<li>
<p>Congelarlo durante la noche</p>
</li>
<li>
<p>Siéntese frente a la PC, ejecute vi</p>
</li>
<li>
<p>Sosteniendo el pez por la cola, golpéelo repetidamente contra su frente hasta que decida darle una oportunidad a EMACS porque las escamas de pescado están volando alrededor de su cabeza y comienza a doler.</p>
</li>
</ol>
<p>Menke, por supuesto, insinuaba que no sólo vi era insensatamente obstinado sino que los usuarios de vi también lo eran por negarse a admitir cómo se estaban infligiendo a sí mismos brutales golpes en la cabeza con un pescado congelado.</p>
<p>No tardó mucho para que los amantes de vi devolvieran el fuego. Uno sugirió a Menke que agregara esta línea a sus instrucciones: <q>Escriba &#39;emacs&#39; antes del paso 1, para que cuando el paso 4 esté hecho, finalmente haya terminado de cargarse</q>.</p>
<p>¿Intentaba decir que EMACS es lento?</p>
<p>Al igual que los batallones fatigados por la lucha llegan a una tregua temporal pero se niegan a abandonar la guerra, los usuarios de vi y EMACS mantienen un intranquilo punto muerto en GNU/Linux, <a href="http://www.usenix.org/sage/" >SAGE</a> y muchas comunidades virtuales relacionadas con computadoras. Es el tipo de empate que puede permanecer inactivo durante meses, pero sólo se necesita una pizca de vaguedad de un lado para que una vez más las llamas se propaguen por los grupos de noticias y las listas de correo. Porque justo por debajo de su conducta civilizada, cada bando siente que el editor que usa es el mejor de todos los editores posibles y aquellos que usan cualquier otro editor, particularmente ese otro editor, son tontos que se daran cuenta de su erronea forma de pensar aunque sólo sea posible a base de muchas burlas.</p>
<p>Ahora, una escision sobre cual editor de texto en Unix es una construccion del mismisimo Dios puede no parecer significativa dados todos los problemas del mundo, un empate de Coca-Cola vs. Pepsi sin consecuencias, sin motivaciones más allá de la simple unión grupal (<q>¡Vamos Equipo!</q>).</p>
<p>Pero, ¿por qué esta diferencia de puntos de vista ha seguido siendo un divisor de la cultura de los programadores durante más de dos décadas? ¿Por qué ha permanecido intacta en el PC, luego de que las interfaces gráficas de usuario, el ratón, Internet y el código abierto han alteraron el panorama computacional?</p>
<p><q>Desde que tengo uso de razon, la población de hackers se ha dividido 50/50 [entre] EMACS [y] vi,</q> escribe en un email Eric Raymond, quien tiene varios roles en las comunidades de software de código abierto y hackers como antropólogo observador y participante desde hace mucho tiempo. <q>Pico, Joe, MicroEmacs, y otros editores han estado básicamente abajo en el ruido estadístico durante todo el período</q>. Raymond puede datar personalmente la división vi/EMACS en 1985 y estipula que, con toda probabilidad, fue mucho antes de eso.</p>
<p>Ya en 1991, Raymond registro la <q>guerra santa</q> vi vs. EMACS en el <a href="http://www.tuxedo.org/jargon/" >Jargon File</a>, quizás la colección definitiva de la terminología hacker.</p>
<p>Cuando se presiona, la mayoría de la gente familiarizada con ambos editores dirá que la diferencia entre los dos es de velocidad vs. flexibilidad, con los usuarios de vi señalando lo rápido que pueden moverse y los amantes de EMACS pregonando su inmenso número de opciones. Los usuarios de vi se burlan de EMACS por ser innecesariamente ostentosos; los usuarios de EMACS se burlan de vi por ser difícil de aprender y tener un alcance limitado.</p>
<p>Así que el gran debate del editor de textos de nuestro tiempo se reduce al equivalente técnico del gustos <q>menos/o-mas relleno</q>. Bueno, sí, más o menos. Pero como en todos los asuntos relacionados con la religion ––o la guerra––, cuanto más se profundiza, más oscuros se vuelven los temas.</p>
<p>Pero aqui hay algo significativo. Estos editores son la tabula rasa sobre la que se ha construido gran parte del ciberespacio. El hecho de que estas herramientas, cada una diseñada para ser transparente para el usuario final, estén sujetas a lealtades tan feroces y competitivas, revela algo acerca de algunas suposiciones primordiales que la gente tiene acerca de las mejores maneras de hacer las cosas.</p>
</div>
<h3 id="vi:-¿el-editor-que-el-tiempo-olvidó?" >Vi: ¿El editor que el tiempo olvidó?</h3>
<div class="hBody-3" >
<p>A primera vista, los forasteros podrían ver a vi como el editor que el tiempo olvidó. No es sólo que tienes que abrir una ventana de terminal sólo para usar la cosa. Esa también es la mejor manera de conseguir EMACS. Pero incluso con VIM, la versión actualizada que la mayoría de los usuarios de vi emplean hoy en día, uno no puede evitar maravillarse (o frustrarse) por la falta de intuición sobre su funcionamiento.</p>
<p>Incluso el webmaster de la <a href="http://www.thomer.com/thomer/vi/vi.html" >página de inicio de los Amantes de VI</a> admite que la curva de aprendizaje es empinada. <q>Vi no es mas veloz antes de conocer 25 comandos más o menos</q>, escribe Thomer Gil, oriundo de Ámsterdam, que actualmente trabaja en un doctorado en ciencias de la computación en el Instituto Tecnológico de Massachusetts.</p>
<p>Gil ha sido comparado por sus compañeros de oficina con un <q>cavernícola que blandía un hacha y un garrote</q> por su uso de VIM.</p>
<p>De todas las deficiencias percibidas en vi, tal vez la más notable sea la necesidad de ingresar la tecla de inserción sólo para escribir cualquier cosa en la pantalla. Vi tiene dos modos: Uno es el modo <q>insertar</q> en el que se puede introducir texto. Se accede a este modo pulsando la tecla <q>insertar</q> del teclado. Pero también existe el modo de comando en el que no se puede introducir texto, sino comandos relevantes. Desde el modo de inserción puede llegar a este ultimo pulsando la tecla de escape.</p>
<p>Así que imagínese al usuario desprevenido escribiendo por primera vez y que accidentalmente presiona la tecla de escape, sólo para descubrir que no sólo no puede ingresar más texto, sino que sus pulsaciones envian extrañas instrucciones al programa .</p>
<p>El Jargon File <a href="http://www.techfak.uni-bielefeld.de/~joern/jargon/vi.HTML" >observa secamente</a> que esta característica de vi <q>tiende a frustrar infinitamente a los nuevos usuarios, ya que no toma comandos mientras espera texto de entrada ni viceversa, y la configuración predeterminada no proporciona ninguna indicación del modo en el que se encuentra el editor</q>.</p>
<p><q>Los múltiples modos asustan a la gente</q>, admite Gil.</p>
<p>Vi fue escrito por Bill Joy en 1976, quien lo forjó a partir de dos herramientas de edición aún más primitivas, ed y ex. Vi significaba <q>interfaz visual</q>, que en 1976 estaba en la vanguardia de la informática, según una <a href="http://www.linux-mag.com/1999-11/joy_04.html" >entrevista</a> a Joy en la <i>Linux Magazine</i>.</p>
<p><q>Intentaba hacerlo utilizable con un módem de 300 baudios. Esa también es la razón por la que tienes todos estos comandos divertidos. Apenas funcionaba usar un editor de pantalla sobre un módem</q>, dijo Joy, <q>Así que el editor estaba optimizado para que pudieras editar y sentirte productivo cuando pintaba más lento de lo que pensabas</q>.</p>
<p>En esa entrevista, Joy contrastó el entorno de desarrollo de vi con el de EMACS, dijo que fue escrito para sistemas con enlaces de canales de fibra y un monstruo PDP-10.</p>
<p><q>Así que podrían tener comandos divertidos con la pantalla brillando y todo eso, y mientras tanto, estoy sentado en casa en una especie de vivienda excedente de la Segunda Guerra Mundial en Berkeley con un módem y un terminal que apenas puede sacar el cursor de la línea de fondo</q>, dijo Joy, tal vez sonando un poco envidioso. <q>La gente no sabe que vi fue escrito para un mundo que ya no existe.</q></p>
<p>Sin embargo, aunque vi debería haber desaparecido a principios de los años 80 a medida que aumentaba la velocidad de la red y del procesador, ha florecido. Las <a href="http://www.math.fu-berlin.de/~guckes/vi/" >VI Pages</a> listan cerca de 30 clones vi desde elvis y VIM hasta obscuridades tales como WinVi y vigor.</p>
<p>Tim O&#39;Reilly, autor intelectual de la editorial O&#39;Reilly &amp; Associates, señaló en la columna <i><a href="http://www.oreilly.com/ask_tim/unix_editor.html" >Ask Tim</a></i> de su empresa, que su empresa vende el doble de libros de vi que de EMACS. Además, O&#39;Reilly apoya un juego de pintura de vi vs. EMACS en alguna convención, invariablemente el doble de voluntarios se inscriben para defender el honor de vi sobre EMACS.</p>
<p>Entonces, ¿cuál es el atractivo? Esto se describe mejor en el <a href="http://www.splange.freeserve.co.uk/misc/vi.html" >Culto de VI</a>, en el que John Arundel escribe: <q>Al ver a un gurú de vi haciendo una edición intensa en un archivo, mientras sus dedos sobrevuelan las teclas y las transformaciones textuales barren la pantalla, uno podría creer que está en presencia de poderes sobrenaturales</q>.</p>
<p>Gil publica algunos ejemplos de esta magia en su sitio web. <q>Un concepto clave en vi es combinar una determinada acción (borrar, copiar a búfer, escribir en mayúsculas, etc.</q> con un movimiento (ir a la línea 25, ir al final del documento, ir a la siguiente coincidencia de &#39;foo&#39;, ir a la segunda coincidencia del carácter &#39;x&#39; en esta línea, etc.)).</p>
<p><q>¿Eh?</q> Le envié un correo electrónico.</p>
<p>Gil devuelve un ejemplo: <q>Si, por ejemplo, un documento contiene las líneas: &#39;a b c d e f g h&#39; y el cursor está situado en &#39;b&#39;, luego puedo escribir <code>d/f</code></q>.</p>
<p>La primer <code>d</code> significa borrar, la <code>/</code> es una función de búsqueda, así que lo que hará este comando es borrar de b a f.</p>
<p><q>No se requieren circunstancias especiales para usar esto... Borrar palabras, oraciones. Vuelve a donde estaba antes. Oh, no, salta de nuevo. Deshacer lo que hice, rehacerlo</q>, escribe Gil.</p>
<p>Gil estipula que también puedes hacer trucos como este en EMACS. Sin embargo, se requiere memorizar <q>combinaciones de teclas apestosas Ctrl-X Ctrl-c Alt-F4</q> para su ejecución.</p>
<p>Otro truco que Gil revela es cómo VI permite a los usuarios moverse dentro de los ficheros. <q>La manera estúpida es usar las teclas de flecha; hay muchas otras maneras más avanzadas de moverse</q>, escribe Gil. Entre las formas avanzadas de movimiento que ofrece vi se encuentra la opción de saltar a los últimos saltos del cursor, o a la siguiente ocurrencia de una palabra en particular, o a la siguiente oración o párrafo.</p>
<p>Incluso la <q>característica</q> de modo dual se vuelve transparente para los usuarios. Hace un año entrevisté a Jon Lasser para escribir sobre su entonces reciente libro <i><a href="http://www.tux.org/~lasser/think-unix/" >Think Unix</a></i>, (cuyo manuscrito, me dijo, fue compuesto enteramente en vi). La conversación finalmente llegó a vi, y me quejé de los dos modos.</p>
<p>Lasser explicó que no veía ninguna diferencia entre trabajar en vi y en procesadores de texto como StarOffice o Microsoft Word. En Word, cuando mueve el puntero fuera del área de pantalla, no puede escribir texto. De hecho, pasar del modo de inserción al modo de comando. <q>Es lo mismo</q>, explica.</p>
<p>Como O&#39;Reilly escribió sobre vi: <q>Como muchas cosas sobre UNIX, sólo <b>parece</b> difícil</q>.</p>
</div>
<h3 id="más-es-más-con-emacs?" >Más es más con EMACS?</h3>
<div class="hBody-3" >
<p>Cuando el lealista de vi O&#39;Reilly escribió en <i>Ask Tim</i> que primero cambió de EMACS a vi sólo después de que su perfil personalizado de EMACS fue destrozado, fue uno de esos jabs sutiles que a los usuarios de vi les gusta usar en contra de EMACS.</p>
<p>EMACS contrasta con la prístina limitación de comandos de vi, con su personalización casi infinita. Sin embargo, dado que la naturaleza humana es lo que es, tal poder en manos de los usuarios puede no ser siempre lo mejor.</p>
<p>Como dice el <a href="http://family.zawodny.com/jzawodn/emacs/" >Emacs-Beginner-HOWTO</a>, EMACS puede ser un editor de texto, un cliente de correo, un lector de noticias, un procesador de texto, un editor de scripts y un entorno de desarrollo integrado para lenguajes de programación.</p>
<p>La clave para esto son los múltiples modos, cada uno con un conjunto de comandos único, que EMACS ofrece. ¿Quieres comprobar el correo electrónico? Sólo tienes que pasar al modo de correo electrónico. ¿Quieres escribir un programa en C++? Utiliza el modo C++. ¿Necesita crear algunas páginas Web? Salta dentro del modo html-helper.</p>
<p>Y además de todo esto, también puedes personalizar EMACS e incluso añadir nuevas funciones, normalmente modificando su código en Lisp.</p>
<p>Es por todo esto que muchos usuarios de vi lo ven como terriblemente presuntuoso para lo que se supone que es un simple editor de texto, sin mencionar que distrae al usuario. La broma en curso sobre EMACS es que es un sistema operativo con un editor de texto adjunto.</p>
<p><q>EMACS como tal comenzó como un proyecto de estándares</q>, escribe Guy Steele, uno de los creadores de EMACS, junto con Richard Stallman, quien más tarde fundó la Free Software Foundation.</p>
<p>Tal y como recuerda Steele, Stallman mantuvo un primer editor para el PDP-10 llamado TECO, que significaba <q>Text Editor and COrrector</q>. A pesar de que ciertas pulsaciones de teclas realizaban comandos de edicion, Stallman creo una tabla programable por el usuario, <q>de manera que cada pulsación de tecla realizaba una búsqueda en la tabla que describía qué hacer para esa pulsación</q>, según dice Steele. <q>Una opción era ejecutar una macro TECO especificada por el usuario.</q></p>
<p>Usando esta funcionalidad de macros, los usuarios estaban programando conjuntos personalizados de macros para ser vinculados a varias pulsaciones de teclas, pero esto se volvió problemático cuando los programadores comenzaron a colaborar en programas y descubrieron que tenían pocas pulsaciones de teclas comunes entre ellos.</p>
<p><q>La comunidad de usuarios se había fragmentado con respecto a las habilidades de edición de textos (y programas)</q>, escribe Steele. Así que Steele, junto con David Moon y Stallman, asumió el proyecto de integrar todas las ideas en un conjunto de comandos unificado.</p>
<p><q>Inventé una matriz en papel y corrí mucho de un lado a otro entre los implementadores y usuarios de los distintos paquetes de macros,</q> dice Steele en un correo electrónico.</p>
<p><q>Recuerdo esto muy bien</q>, recuerda Dan Weinreb, quien fue uno de los primeros alfa testers de EMACS. <q>El tipo tenía un portapapeles con un pedazo de papel que mostraba todas los atajos, y recogió cuidadosa y diplomáticamente los comentarios de todo el mundo para unificarlos, en atajos estándar</q>.</p>
<p>Después de unos meses, Steele, ocupado tratando de terminar su tesis de maestría, entregó la obra a Stallman. Y el resto es historia.</p>
<p>El hecho de que la flexibilidad se horneara desde el inicio le da a EMACS su ventaja, dicen los usuarios hardcore.</p>
<p><q>Pienso en EMACS como la navaja suiza de los editores</q>, menciona en un correo electrónico a Debra Cameron, coautora de Learning GNU Emacs y presidenta de Cameron Consulting. <q>Es un ambiente de trabajo completo, un microcosmos. Si piensas en algo que desearías que hiciera, probablemente descubrirás (después de mirar a tu alrededor) que ya lo hace. Si no lo hace, puedes extenderlo y hacer que haga lo que quieras que haga</q>.</p>
</div>
<h3 id="¿no-podemos-llevarnos-todos-bien?" >¿No podemos llevarnos todos bien?</h3>
<div class="hBody-3" >
<p>Entonces, ¿cómo difiere EMACS de vi?</p>
<p><q>He visto a usuarios de vi muy hábiles hacer algunos trucos bastante ingeniosos, pero sigo pensando que vi es (sólo) un editor, incluso si para algunos es un gran editor</q>, menciona Cameron. <q>Siempre, siempre funciona de la misma manera. En este sentido, vi es como McDonald&#39;s; no importa a donde vayas, es exactamente lo mismo.</q></p>
<p><q>¿Quieres un editor que se adapte a tus necesidades y peculiaridades y que haga muchas, muchas cosas o simplemente quieres ser capaz de editar archivos rápidamente en cualquier máquina?</q> pregunta ella. <q>Para la gente que tiene que moverse de un ordenador a otro constantemente, esta consistencia puede ser una ventaja real.</q></p>
<p>En otras palabras, EMACS = flexibilidad, mientras que vi = uniformidad?</p>
<p>Aquí es donde las cosas se ponen turbias.</p>
<p><q>EMACS es ciertamente más complejo que vi, pero no creo que sea más poderoso de ninguna manera útil, porque vi fue diseñado para ser parte de un sistema UNIX e interactuar con esas herramientas</q>, replica Jon Lasser.</p>
<p>Tenga en cuenta que, para Lasser, <q>útil</q> significa la forma en que vi le permite leer documentos directamente desde una tubería UNIX desde otro proceso, <q>como lo haría en cualquier otra aplicación UNIX</q>, explica. Así, la cadena arcana de pulsaciones de teclas <code>&lt;esc&gt; :r !ls&lt;enter&gt;</code> introducidas en vi (en modo comando, recuerde) lee en el búfer la salida del programa <code class="command" >ls</code>, o una lista de archivos del directorio actual. Y una tubería de cualquier otro programa UNIX también funcionaría.</p>
<p>En cuanto a la edición automática de un gran número de archivos en vi, Lasser dice que es por eso que tenemos <q>sed, awk, y todas las demás herramientas de procesamiento de texto UNIX</q>.</p>
<p><q>El procesamiento de texto es para lo que UNIX fue diseñado, y vi fue diseñado para ser parte de ese sistema</q>, escribe Lasser.</p>
<p>Tal vez el problema subyacente entre EMACS y vi no es el de la uniformidad frente a la flexibilidad en absoluto. Después de todo, ambos editores ofrecen flexibilidad, es sólo que con vi, lo hace a través del propio UNIX, mientras que EMACS lo logra construyendo sobre el sistema.</p>
<p>Y, para el caso, el único punto de la flexibilidad es hacer que el trabajo vaya más rápido. Si desea un procesamiento de texto sencillo y sin complicaciones, puede optar por Pico, que ofrece sólo una pantalla en blanco y ninguna de las características de vi o EMACS que confunden a los novatos. Lo que ambos editores ofrecen son formas avanzadas de reducir la distancia entre la velocidad de los dedos en el teclado y la velocidad del cerebro del programador.</p>
<p>En otras palabras, ¿podría ser que estos editores ofrezcan lo mismo, pero exijan diferentes maneras de pensar a sus usuarios? Vi requiere la paciencia para aprender sus extravagantes formas, aunque una vez que las dominas, eres libre de llevar tu acto a cualquier sistema UNIX. EMACS te da la libertad de personalizar tu configuración como mejor te parezca, aunque si no eres cuidadoso, te convertirás en prisionero de tu propia configuración.</p>
<p>En algún momento durante la gran caminata de mejora de la auto-eficiencia que todos los buenos programadores toman, los usuarios de vi y EMACS se cruzan, cada uno viniendo de una dirección diferente. Y cuando se encuentran, normalmente se tiran piedras unos a otros.</p>
<p>Pero todo está bien.</p>
<p><q>No creo que haya una gran diferencia en la funcionalidad. Ambos editores hacen un buen trabajo y todo se reduce a lo que la gente aprende primero</q>, escribe Gil. <q>Ya que la mayoría de las personas conocen EMACS, les enseñarán a otros EMACS. Por lo tanto, la mayoría de la gente usa EMACS, etc.</q></p>
<p>Y así la disputa continuará...</p>
<div class="italic" >
<p>(Nota: Las mayúsculas de EMACS, UNIX y vi pueden haber sido cambiadas en comillas a sus formas originales, excepto en los títulos directos de libros y páginas Web).</p>
</div>
</div>
