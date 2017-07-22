+++
categories = ["apt"]
date = "2017-06-24T20:28:51-05:00"
draft = true
tags = ["apt","install"]
title = "Konsole Warrior"

+++


![](/img/tilix-a.png)

Dentro de <q><em>El camino del Heroe</em></q> (que algunos dicen que esta
conformado por doce estadios, otros por 7, 17, 13, ...) antes de acudir al
llamado, debemos preparar nuestras herramientas sobrenaturales
<em>lenguaje</em>, <em><s>Emacs</s> Editor</em> y <em>Emulador de terminal</em>
(intreprete incluido).

Para las dos elecciones (lenguaje y emulador de terminal) tenemos un amplio
abanico de posibilidades, hoy les hablare del emulador de terminal y las razones
de su eleccion

## Konsole

Salida del mundo de reino de KDE, donde sus habitantes priorisan la
configuracion y el cambio constante de temas (iconos, wallpapers, doks y otra
extensa variadad) de cambios neon, **Konsole** es la aplicacion con K que mas
aprecio, por un solo aspecto, su alta configuracion de atajos del teclado, no es
que necesite demasiado, solo tener la ventana sin ninguna distraccion, ni barra,
ni nada, algunos atajos de desplazamiento por pagina y linea, mas poder cambiar entre
"tabs"(?, seciones? lo que el la tty haces con Alt+Flecha derecha/izquierda) y
poco mas.

No estoy seguro si konsole, tiene incluida la caracteristica de dividir ventanas,
(si la tiene la desactive) pues no la necesito)

Por varios años he permanecido fiel a Konsole, mi katana demoniaca obscura,
varias han sido las ocaciones que he mirado en alguna herreria para conseguir
otra arma secundaria (terminator y tmux) sin llegar a sentirme a gusto con estas,
hasta que hace medio año (o algo asi) estube a punto de cambiar por terminix, por
incorporar el **overview** de Gnome, mas luego de unos dias, desisti y continue
con la K

## Tilix (antes terminix)

Aunque el autocompletado-automagico de fish, es bueno, queria tener marcadores,
para los 5 o 6 directorios "de trabajo" que mas utilso. Con esto en mente dio
inicio una pequeña busqueda de internet, pero tras encontrar cosas de python y otras
utilidades que no me daba confiansa instalar, di otra oportunidad a tilix,
pues incorpora de serie marcadores y el amado **overview** Gnomero!!!


![](/img/tilix-b.png)

la razon por la que antes no hice la transicion se debio a no incorporar la
configuracion del desplazamiento por linea, pero estimados colegas, un pequeño
[issue](https://github.com/gnunn1/tilix/issues/698), aun con engrish de
traductor, es capas de conmover a nuetros forjadores

Si bien la peticion fue escuchada con prontedad, tilix, tiene (o tenia) un
complejo proceso de compilacion que no fui capaz de realizar, tras unos meses de
espera, y descubrir como incorporar la ultima version a mi distribucion, fue
posible el *upgrade* (o no) de equipamiento

Al igual que konsole, tilix tambien es altamente customizable en sus atajos,
colores, desplazamientos, codificacion, apariencia, fuente y paleta de colores,
etc

pero lo que mas me interesaba era el tema de los bookmarks. Dentro de la
configuracion trae dicho apartado, peeeero, no fui capaz de entender como
guardar una ruta y que luego funcionara, asi que cambie el atajo de teclado para
ya dentro del directorio, invocar el menu y establecer el marcador

![](/img/tilix-c.png)

y...? **funciono!**, solo pones el nombre del marcador y al abrir los marcadores
ya puedes hacer el cambio

![](/img/tilix-d.png)

tambien, tube que ajustar un poco el esquema de colores, tipografia y cursor,
hasta lograr mi ambiente ideal

si bien hasta el momento no utilzo el modo Gnomero (F12), hay esta para cuando
lo necesite... o para impresionar a la plebe...

## keybindings

complejo es establecer unos atajos medianamiente razonables sin exigir la
presion de mas de tres teclas simultaneas, sin que estas sean capturadas por el
entorno grafico, o entren en conflicto con el interprete y llegen a salvo hasta
el programa en ejecucion

- Ctrl + Shift + d :: añadir marcador

- Ctrl + Shift + m :: seleccionar marcador

- Ctrl + Shift + t :: el clasico para abrir una nueva secion/terminal

- Ctrl + Shift + w :: el clasico para cerrar la secion/terminal

- Shift + Flecha derecha/izquierda :: esta combinacion puede ser polemica, pero
     como el interprete no la utiliza para seleccionar texto, pues la ocupo para
     cambiar entre seciones (1, 2, 3, ... 1, 2 (y viceversa))

- Shift + Flecha arriba/abajo :: desplazar texto por linea

- Shift + Re/Av Pag :: desplazar texto por pagina

- F12 :: overview

- Shift + F9 :: preferencias

- Shift + F10 :: mostrar atajos

- Ctrl + Shift + / :: añadir terminal abajo

- Ctrl + Shift + * :: añadir terminal a la derecha

- Shift + Alt + Flechas :: redimencionar terminal

- Alt + flechas :: cambiar entre terminal

- Ctrl + 9 :: (en mi teclado esto es Ctrl + Shift + =) sincronizar entrada

basicamente estos son los atajos que mas utilizo (auque en verdad no necesito
dividir, ni sincronizar terminales)

ademas, con dos terminales y once escritorios, no necesito distracciones
inutiles como menus o docks, asi que la ventana aparece directamente a
pantalla completa, para lograr esto en los atajos de gnome, en los atajos
personales, vincule `Super + h` a tilix (mapeo dvorak customizado) a la ruta
`/usr/bin/tilix --full-screen`, algo similar tenia con konsole, que paso a estar
es `Super + t`

## instalacion

fedora me atormenta, y es muy rara, y es un rollo...

ya mencione que compilar tilix me resulto imposible, la primer vez que probe
este terminal, lo obtube de un servicio(?) llamado corp, que no tengo mucha idea
que es, pero parace que es parte de fedora. Bien, en esta ocacion preste
atencion a una linea en la parte derecha de esa web que era nada mas y nada
menos que la receta para incluir tilix en los repos, en efecto, algo muy raro

```
dnf copr enable heikoada/terminix
dnf -y install tilix
```

para otras distros, buscar en repositorios, o buscarse la vida... o ver
directamente el repo https://github.com/gnunn1/tilix
