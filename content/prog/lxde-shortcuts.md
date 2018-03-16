+++
title      = "lxde shortcuts"
tags       = [ "howto", "lxde" ]
categories = [ "prog" ]
date       = 2017-10-22T12:36:18-05:00
+++

![](/img/clouds_battle_by_arsenixc.png)

A Gnome ♥ lo que pida! Mas, si el equipo es incapas de cumplir sus exigencias
para una experiencia completa (contar con un procesador con 2 nucleos,
2 monitores y 3GB de ram), mejor optar por un entorno poco exigente en sus
recursos

asi pues en una laptop limitada con 10 años en su historia (32bits con 512MB
ram) el balance ideal (segun varias prubas) fue debian 9 con lxde, que, no solo
consigue regresar de la vida al equipo, tiene la potencia suficiente como para
ejecutar un navegador *consumista* moderno, varias terminales, editor, fluidez
con los videos e incluso ejecutar varios emuladores, todo con un sistema
actualizado, moderno y libre

Pero bueno, Gnome, con su elegancia y minimalismo ha influido bastante en la
forma como interactuo con el pc, que es basicamente estar con los dedos pegados
al teclado, con atajos para cualquier cosa precindiendo perfectamente del
raton, exepto, claro esta, cuando se utiliza el navegador o aplicaciones
graficas para aficionados... como dirian en la guia de parabola o gentoo, ya no
recuerdo cual era

Sobra (aunque tengo necesidad de) decir que desprecio los docks, widgets y
barras, razon fundamental por la que nunca me he sentido comodo con KDE, o dicho
de otro modo los temas ni cambiar el fondo de pantalla (una vez colocada la
imagen de portada con la que llebo 3 años) son relevantes

Otro aspecto que ha influido bastante en la interaccion con el entorno grafico
es contar con un teclado de 105 teclas y el mapeo en programmer dvorak
(en).

En la mayoria de mapeos del teclado los numeros se encuentra en la "primer
fila" (sobre las letras) y al presionar shift se accede a los "simbolos". En
cambio en programmer dvorak, los simbolos tienen el protagonismo y los numeros
se acceden con el shift, uno u otro pero no ambos... y... un teclado con con pad
numerico sienta perfectamente a tal distribucion, pues, por un sitio protagonizan
los simbolos y en el lateral tenemos los numeros cuando es necesario
dedicarse a ellos, encima se puede hacer perfectamente con una sola mano.

Para no subutilizar el pad a una sola mision, en este he establecido la
interaccion con los escritorios: mover a un espacio, mover una ventana a un
espacio, maximizar o minimizar ventanas.

Toda esta personalizacion me convienten en un *memo* fuera de mis equipos, mas
dentro de ellos fluyo libremente, como ningun otro usuario en otros sistemas
podria hacerlo

Entonces pues, es posible transaladar la experienca gnomera a lxde?

**no**, pero se aproxima. No, por que no cuenta con la vista **overview**, que
es marca distintiva del nomo, ni tampoco por rendimiento convendria utilizar
todas las aplicaciones nome en lxde, aunque al menos puedo emular mi
configuracion de atajos maestros en este e imaginar que su lanzador de
aplicaciones es como el lanzador con la tecla Super

## Shortcuts

por motivos internos de lxde (en debian 9) que desconosco, utiliza openbox,
que sugun su [wiki](http://openbox.org/wiki/Main_Page):

> Openbox es un administrador de ventanas altamente configurable. Le permite
> cambiar casi todos los aspectos de su interacción con su escritorio e inventar
> formas completamente nuevas de usarlo y controlarlo. Puede ser como un
> videojuego para controlar ventanas. Pero Openbox también se puede mantener
> extremadamente simple, ya que está en la configuración predeterminada, lo que
> significa que puede adaptarse a casi cualquier persona. Openbox te da el control
> sin obligarte a hacer todo.

y (asta donde entiendo) se encarga de administrar donde aparecen, como y el
aspecto de las ventadas

para personalizar el teclado y algunas funciones mas, debemos modificar el
fichero `~/.config/openbox/lxde-rc.xml`, una vez realizados los cambios se
aplican ejecutando como usuario `openbox --reconfigure`.

el fichero en cuestion, como puede deducirse por su extension, es solo un xml
especializado, donde cada etiqueta tiene un significado predefinido, y debe
aparecer en un orden concreto. En su wiki tenemos una lista de [acciones
disponibles](http://openbox.org/wiki/Help:Actions) y tambien nombes de (algunos)
"[eventos](http://openbox.org/wiki/Help:Bindings)" del raton y teclado

de momento mi fichero de configuracion es [este](/data/lxde-rc.xml), aqui los
aspectos mas revelantes

```
  <desktops>
    <number>10</number>
    <firstdesk>1</firstdesk>
    <names>
      <name>A</name>
      <name>B</name>
      <name>C</name>
      <name>D</name>
      <name>E</name>
      <name>F</name>
      <name>G</name>
      <name>H</name>
      <name>I</name>
      <name>J</name>
      <name>K</name>
      <name>L</name>
    </names>
    <popupTime>875</popupTime>
    <!-- The number of milliseconds to show the popup for when switching
       desktops.  Set this to 0 to disable the popup. -->
  </desktops>
```

esto viene a decir, que quiero tener 10 escritorios, a cada uno le he puesto un
nombre que es una letra del abecedario y que el primer escritorio es el
primero...

mas adelante el fichero cuenta con una etiqueta `<keyboard>` donde se colocan
todos los atajos que vallamos a definir

```
<keybind key="W-Prior">
  <action name="DesktopLeft">
    <dialog>no</dialog>
    <wrap>no</wrap>
  </action>
</keybind>
<keybind key="W-Next">
  <action name="DesktopRight">
    <dialog>no</dialog>
    <wrap>no</wrap>
  </action>
</keybind>
<keybind key="W-A-Prior">
  <action name="SendToDesktopLeft">
    <dialog>no</dialog>
    <wrap>no</wrap>
  </action>
</keybind>
<keybind key="W-A-Next">
  <action name="SendToDesktopRight">
    <dialog>no</dialog>
    <wrap>no</wrap>
  </action>
</keybind>
```

esta seccion es para moverme "secuencialmente" entre los escritorios con *Super*
y *Page Up/Down*. En caso de querer enviar una ventana a el escritorio
sugiente/anterior la combinacion se repite pero agregrando la tecla *Alt*

```
<keybind key="W-KP_7"><action name="Desktop"><desktop>1</desktop></action></keybind>
<keybind key="W-KP_8"><action name="Desktop"><desktop>2</desktop></action></keybind>
<keybind key="W-KP_9"><action name="Desktop"><desktop>3</desktop></action></keybind>
<keybind key="W-KP_4"><action name="Desktop"><desktop>4</desktop></action></keybind>
<keybind key="W-KP_5"><action name="Desktop"><desktop>5</desktop></action></keybind>
<keybind key="W-KP_6"><action name="Desktop"><desktop>6</desktop></action></keybind>
<keybind key="W-KP_1"><action name="Desktop"><desktop>7</desktop></action></keybind>
<keybind key="W-KP_2"><action name="Desktop"><desktop>8</desktop></action></keybind>
<keybind key="W-KP_3"><action name="Desktop"><desktop>9</desktop></action></keybind>
<keybind key="W-KP_0"><action name="Desktop"><desktop>10</desktop></action></keybind>
<keybind key="W-A-KP_7"><action name="SendToDesktop"><to>1</to></action></keybind>
<keybind key="W-A-KP_8"><action name="SendToDesktop"><to>2</to></action></keybind>
<keybind key="W-A-KP_9"><action name="SendToDesktop"><to>3</to></action></keybind>
<keybind key="W-A-KP_4"><action name="SendToDesktop"><to>4</to></action></keybind>
<keybind key="W-A-KP_5"><action name="SendToDesktop"><to>5</to></action></keybind>
<keybind key="W-A-KP_6"><action name="SendToDesktop"><to>6</to></action></keybind>
<keybind key="W-A-KP_1"><action name="SendToDesktop"><to>7</to></action></keybind>
<keybind key="W-A-KP_2"><action name="SendToDesktop"><to>8</to></action></keybind>
<keybind key="W-A-KP_3"><action name="SendToDesktop"><to>9</to></action></keybind>
<keybind key="W-A-KP_0"><action name="SendToDesktop"><to>10</to></action></keybind>
```

aqui se ha definido una combinacion especifica para cada uno de los 10
escritorios, conseptualmente el primero esta en la tecla **7** del pad numerico,
y se deciente de izquierda derecha hasta llegar al 0. La combinacion para ir a
un escritorio es *Super* + su numero del pad numerico. Para enviar una ventana a
un escritorio se agrega la tecla *Alt*


```
<keybind key="W-d"><action name="ToggleShowDesktop"/></keybind>
<keybind key="W-q"><action name="Close"            /></keybind>
<keybind key="W-f"><action name="ToggleFullscreen" /></keybind>
<keybind key="W-KP_Subtract">
  <action name="Lower"/>
  <action name="FocusToBottom"/>
  <action name="Unfocus"/>
</keybind>
<keybind key="W-KP_Multiply">
  <action name="ToggleMaximizeFull"/>
</keybind>
```

- Super + d, para ocultar/mostrar todas las ventanas
- Super + q, cerrar ventana
- Super + f, ventana a pantalla completa
- Super + `*` (pad numerico), maximizar ventana
- Super + `-` (pad numerico), minimizar ventana


```
<keybind key="W-space"    ><action name="NextWindow"/></keybind>
<keybind key="W-BackSpace"><action name="NextWindow"/></keybind>
<keybind key="A-Tab"      ><action name="NextWindow"/></keybind>
<keybind key="W-Return"   ><action name="PreviousWindow"/></keybind>
```

he, he, esto son cuatro combinaciones distintas para cambiar entre ventanas,
Super + espacio (la preferida), Super + Enter, Super + Retroceso y el clasico Alt + tab...
para que? para que sin importar la posicion del teclado o cual mano tengo
ocupada (heee? ｢(ﾟﾍﾟ)), pueda hacer el cambio entre ventanas, no se, lo veo
indispensable!

```
<keybind key="A-F2">
  <action name="Execute">
    <command>lxpanelctl run</command>
  </action>
</keybind>
<keybind key="C-Escape">
  <action name="Execute">
    <command>lxpanelctl menu</command>
  </action>
</keybind>
    <keybind key="A-F1">
      <action name="ShowMenu">
        <menu>client-menu</menu>
      </action>
    </keybind>
<keybind key="A-C-Delete">
  <action name="Execute">
    <command>lxsession-logout</command>
  </action>
</keybind>
```

basicamente abrir el lanzador de comandos de lxde, como un substituto al
**Super** gnomero, abrir el (desfasado) menu de apliciones, el menu de las
ventanas y que aparesca el menu de sesion con Ctrl + Alt + Suprimir

```
<keybind key="W-h">
  <action name="Execute">
    <command>tilix</command>
  </action>
</keybind>
<!-- Keybindings for running applications -->
<keybind key="W-e">
  <action name="Execute">
    <command>emacs</command>
  </action>
</keybind>
<keybind key="W-u">
  <action name="Execute">
    <command>emacs</command>
  </action>
</keybind>
<!-- Keybindings for finding files -->
<keybind key="W-x">
  <action name="Execute">
    <command>pcmanfm</command>
  </action>
</keybind>
<!--keybindings for LXPanel -->
<keybind key="W-z">
  <action name="Execute">
    <command>firefox</command>
  </action>
</keybind>
```

y finalmente atajos para emacs, tilix, el navegador de ficheros y firefox, que
es lo basico del dia a dia, jo, olvide el evince para los documentos (Super +
v) y ahora que lo veo de nuevo, revisar si los dos super se llaman super o uno
es Super derecho, je, je, el teclado de "asuntos emergentes" no tiene dos super,
comprobacion pendiente.

El archivo cuenta con configuraciones extra que pueden ejecutarse incluso segun
"el contexto" (ventana) actual y tambien define las acciones del raton y el
aspecto de ventanas, aunque esos parametros los deje tal cual.

Y esto es todo, aun queda pendiente personalizar el mapeo de teclado, aunque eso
aun no descubro como se realiza apropiadamente, Sayonara!
