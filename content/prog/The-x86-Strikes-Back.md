+++
title      = "The X86 Strikes Back"
tags       = [ "howto" ]
categories = [ "prog" ]
date       = 2017-10-14T12:38:00-05:00
+++

![](/img/kool.jpg)

bueno, la imagen es mas de 8bits que por ahora son los equipos
retro-nostalgicos de moda, ya le llegara su momento a x86.

Esta historia trata de como pase (sin querer) de considerar obsoleto el hardware
x86, pidiendo que todos esos equipos entregasen su silicio al mundo, a creer que
aun son equipos potables para su uso diario o en el peor de las casos para
utilizarlos como instrumentos de iniciacion en el heretico culto de Emacs, las
ttys y la "verdadera" programacion

pero bueno, no es que fuera un modernillo con urgensias obsesivas por la
renovacion de equipos, en este cuerpo hay hamor (he, he, e) para todo el
hardware, considero artisticos los pcbs, sus colores, pistas, componentes y en
ocaciones olores y carcasas, la fusion perfecta entre el mundo de las ideas igenieriles y
la materia. Aun asi, el hardware es perecedero, aparece la corrosion, pilas con
"esporas", capacitores inchados y tarde o temprano sus componentes terminan por
perecer, por lo que como cualquier obra fisica (manga, pintura, cine, musica, etc),
una ves cumplida su mision, creo que lo mejor es conservar toda su informacion
posible como bits y especificaciones

## acer aspire 3600

Hace dos semanas mi tio "el licensiado", me trajo un presente, una laptop con el
marco (y soporte de la pantalla) roto cerca de las bisagras, ademas el display
emanava olores perfumados, tenia una sustancia mielosa desagradable y algo de
corrosion en los fierros, je, je, no hay nada mas bonito que ver la sonrisa de
un adulto con vermuda, melenudo y barbon mientras destripa un equipo

luego de desmontar todo, limpiar un poco y dejar la base como lo unico
rescatable, monte un transformador con 4 tristes diodos y dos capacitoderes que
entregaban 20V y lo conecte al equipo, para sopresa mia y ajena funciono, no sin
lanzar unos beeps incesantes durante el arranque y ejecucion de su OS ventanas XD

daba por mala la placa, aunque aun tenia ilusion de verla andar, comenzo asi una
encrusijada mental entre gastar unos donativos en un adaptador de corriente
apropiado para el equipo (que consideraba con su motherboard supuestamente
dañada) o subsistir con un poco de dignidad durante un mes. Tras refrenar las
ansias de comprar un adaptador, revolvi mis pertenencias tegnologicas y voala,
aparecio la fuente de laptop como por obra de magia, fantastico!

Al probar el adaptador comprobe que la causa de los beeps de la placa, eran la
fuente improvisada que habia utilizado

### hardware porno

- Intel Celeron M 380 0KB L1 cache 1MB L2 cache, 1.60 GHz, 400MHz FSB (bus)
- 2x256MB DIMM DDR2 (expandible a 2GB)
- Grafica Intel GMA 900 (con 128MB de memoria compartida)
- Puerto VGA
- 4 puertos USB 2.0
- Unidad DVD, con "quemador"
- HDD 40GB ATA/100
- Ethernet 10/100 (RJ-45) y entrada de modem (RJ-11)
- wifi 802.11b/g Atheros AR2413
- Bateria de 2000ma muerta
- Monitor 15' con las bisagras corroidas, soportes rotos y el LCD recubierdo
  con una subtansia gel-osa con olor a perfume y textura desagradable

lo parte superior del equipo no tuvo salvacion, aparecian nubes en el display y
luego de unos segundos salio humo del balastro de la lampara fluoresente

Al principio por alguna incoherencia mental, creia que el procesador era de
400MHz (por no contar con pasta termica, no llege a verlo desnudo), pero no, eso
es su bus de datos, asi pues ya que el equipo tiene una potencia considerable,
"cegarlo" a un uso exclusivo con ttys, me parecio un desperdicio. Por otra
parte, ni el procesador, ni la memoria disponibles son suficientes para ejecutar
un entrorno grafico como Gnome y menos aun KDE, asi que como criterio de
instalacion las opciones fueron tirar de xfce para abajo, y en el peor de los
casos, directamente con un manejador de ventanas

tambien paso la idea de probar con puppy linux, pero las ultimas versiones que
encontre son del año pasado, asi que esa opcion la descarte, luego vi un
proyecto de un sistema operativo hecho en ensamblador de nombre *minuet os*,
je, y este tambien detuvo su desarrollo hace mas de un año.

Asi que la siguente opcion fue probar con una vieja conocida

## 1er Distro – Debian 9.1 (xfce)

l-a-a-a-a-a-a-a-g-g-g-r-r-h-h-h-h-h-h, desconosco la razon, el escritorio
simplemente se arrastraba

## 2da Distro – Raspbian (lxde)

tras la decepcion de debian con xfce, dije, ohh las raspberry son equipos con
512MB de ram y un procesador arm de juguete, seguro que el intel (auque con mas
de 10 años de antiguedad) puede comportarse dignamente

instale una version para PCs y asi fue, ligeresa en forma de 70mb de ram, con
escritorio lxde, y con chrome corriendo (su navegador preinstalado) apenas llegan
a 220mb de ram, bastante fluido con el yutu abierto, sorprendente!

actualice e instale todo lo necesario para utilizarla, pero encontre dos pegas
que no pude dejar pasar, primero es estar basado en debian 8 y la segunda fue
que su lxde no tenia escritorios, por vishnu un solo espacio de trabajo! sin escritorios
no hay fiesta

## 3ra Distro – Debian 9.1 (mate)

regrabe la iso (version dvd) de Debian un usb y reistale esta ves escogiendo
Mate, tras el primer reinicio solo aparecia una pantalla en negro, y al loguear
en un tty vi que el consumo era de 180MB, que limitaba bantante el posible uso
de un navegador

desde el mismo tty, ejecutando `startx`, mate iniciava sin inconvenientes y
luego de hacer eso y con otro reinicio, desaparecieron los problemas
graficos... pero el consumo de memoria me asusto y pase a otra cosa

## 4ta Distro – GNU GUIX (0.13.0)

hace un tiempo GNU habia presentado su propio sistema de paquetes... como para
estandarisar la cosa o algo asi, y cuando lei de esta distro me llamo la
atencion por (creo) ser la unica en utilizarlo

segui la guia de su [pagina oficial](https://www.gnu.org/software/guix/), aunque
al llegar al ultimo paso, algo debi hacer mal, pues regresaba un error

me llamo la atencion que en su pagina lo consideran un sistema GNU (sin el
linux), cosa que me agrado bastante, aunque no encontre si es que utilizan HURD
como nucleo.

otra cosa que encontre interesante es que durante la instalacion utilizan el
editor [zile](https://www.gnu.org/software/zile/), no lo conocia, pero esta
basado en Emacs, solo que sin las extensiones, escrito en C y ocupa un espacio
ridiculo. Exelente si no puedes tirar de **el** editor, o para ediciones menores
con un arranque instantaneo, por supuesto, zile, es otro de los tantos proyectos
del proyecto GNU

## 5ta Opcion – FreeBSD 11.1

jemmm, cuando bajen la imagen, si van a grabarla a un usb, prestar atencion a
que la descarga termine con **memstick.img**, las que terminan con *disk* o
*dvd* no arrancan si se graban en bruto con `dd` a la usb. Por habito/despiste
intente con la imagen *disc* y efectivamente no funciono

para la instalacion segui la [guia de linuxito](https://www.linuxito.com/21-nix/435-como-instalar-freebsd-10)
por desgracia, algun tipo de problema hubo con el wifi atheros y ya que
necesitava la red para bajar unos paquetes, la instalacion no fue posible,

al siguiente dia intente de nuevo con el cable de red, aun concluyendo la
instalacion el problema de la red o algo extraño sobre un buffer saturado seguia
lanzando amenazas. cuando descubri que en el sistema del demonio tenemos Gnome,
kde, y xfce, decidi abandonar el mundo BSD

me quedo con la belleza del instalador, es muy bonico, tras el primer arranque tenia
422MB de ram libres, 1.3GB disco en uso

## 6to Intento – GNU GUIX (de nuevo)

luego de bsd, no pude resistirme a intertar de nuevo, ahora siguiendo la [guia ochobits](https://www.ochobitshacenunbyte.com/2015/09/09/guixsd-la-distro-gnu-del-futuro/),
en conjunto con la oficial

hemmn, puede enterder algo mejor y esta ocacion si monte y etiquete las
particiones correctamente (ahora lo se), aunque nuevamente llego el fracaso al
momento de ejecutar `guix system`.

Una lastima

## 7ta Distro Parabola

aqui tenemos el instalador mas chulo de todos, por nivel de chuleria los
ordenaria como

- parabola
- debian (por utilidad con su modo de rescante y ser identico el modo texto al grafico)
- freeBSD

llegando al paso de instalar el sistema base

    acstrap -i /mnt base base-devel

aparecian varios problemas con llaves gpg, luego de varias busquedas, el comando
`pacman-key --refresh-key` (un `pacman-key --populate archlinux` en algun
momento), luego `pacman -Scc`, mas `pacman -Syyu`... y, naahh, seguan los
preblemas con las llaves, solo se redujo el conflicto con un solo paquete, chan
chan char, el kernel

tenia dos opciones, desactivar la verificacion de llaves instalando un kernel no
firmado, o pasar al siguiente intento. Por supuesto la respuesta no es obvia,
por un lado la verguenza de no instalar parabola y por el otro la inconciencia
de instalar **el** paquete inseguro, la dificil desicion tuvo solucion al
considerar un kernel panic y el incomodo proceso de tener que buscar informacion
adicional con infructifero resultado: terminar la instalacion por orgullo y
pasar con la siguiente... o no, un nuevo kernel panic, **next**

en serio, lo intento, parece que simplemente las particulas del universo
comspiran en mi contra

## 8va Prueba Debian 9.2 lxde (net install)

la idea fue instalar debian sin nada, y haci fue. Sin saber ni que, ni como
me quede sin red inalambrica o alambrica, no podia actualizar paquetes ni hacer
pings, durante la instalacion el wifi iba como un campeon y al reinicio se
olvido de contraseñas, al prabar con ethernet tampoco funcionaba. Debian es
especial con la configuracion y no contaba con `ifconfig`, lo que encontre en
internete tampoco lo entendi muy bien

una instalacion mas tarde, escogiendo lxde durante esta, y con red por ethernet,
los problemas desaparacieron, incluso se configuro el sources.list
correctamente. Desde el modo grafico configurar la red, fue solo poner la
contraseña y ya

ocurrioseme un error epico mientras cambiaba bash por fish, al hacer `chsh` con
una ruta erronea y me quede sin poder acceder como root, la solucion
paso por arrancar con la usb de instalacion en modo rescate y modificar
en `/etc/passwd` la ruta erronea, corregir y reiniciar. fuuhhh, sude por mi
estupides, reinstalar debian une vez mas me daba una pereza enorme

je, je, se supone que chsh primero verifica la ruta a la shell (en `/etc/shells`)
antes de hacer el cambio. En el pasado varias veces me ha impedido
cagarla, pero ahora estava en "modo experto" o algo

Esta ves el consumo de inicio fue de ~100MB de ram, mas que en raspbian, pero no
demaciado y con escritorios, yeee! ahora a configurar unas cosillas

### dvorak programmer

no encontre en el menu de lxde una opcion de idiomas, y una
[fuente de internet](https://superuser.com/questions/119018/changing-keyboard-layout-to-dvorak-in-ubuntu-server)
me revelo el secreto para configurar el teclado

    dpkg-reconfigure keyboard-configuration

tambien instalando el paquete `console-data` se puede configurar el teclado,
pero si con `keyboard-configuration` te funciona, como en mi caso, mejor no
tocar nada mas

### inicio de secion automatico

con ayuda de un viejo conocido (unilateralmente) pude configurar el inicio de
secion automatico siguendo este [post](http://unbrutocondebian.blogspot.mx/2012/10/inicio-de-sesion-automatico-sin.html)

resumiendo basta con modificar `/etc/lightdm/lightdm.conf` agregando `autologin-user=mi-usuario`

prestar atencion, por que en la referencia de el post mencionan que lxdm
utiliza lxdm, mas en el debian 9.2, el gestor pasa a ser lightdm.

### backports (tilix y firefox)

primero a erradicar libreoffice que no lo ocupo para nada

    apt remove --purge libreoffice*

luego modificamos la lista de repositorios (`/etc/apt/sources.list`) y agregamos los
backports, copiando y pegando

    deb http://deb.debian.org/debian stretch-backports main
    deb-src http://deb.debian.org/debian stretch-backports main

esto es para optener el glorioso y suculento tilix que no viene en los repos
estandar, la idea tambien era  hacerse con firefox 56, parece que de momento el
backport de firefox no esta disponible en stretch

```
apt update
apt upgrade
apt -t stretch-backports install tilix
```

lo importante es tener la terminal mas koool de todas (todas!) y por que *lxterminal* captura
muchos atajos de emacs y no se pueden moficar (creo) lo que es un fastidio en
toda regla

### atajos

ja, ja, creia que lxde no tenia atajos,
[aqui](https://daveden.wordpress.com/2012/09/21/lubuntu-keyboard-shortcuts-cheat-sheet/)
una lista con ellos

pero lo sabroso esta en configurarlos a gusto para ello segui este [otro post](https://monstruosoft.wordpress.com/2016/01/25/configurar-atajos-lxde/)

en resumen el "truco" es modificar un fichero en nuestro home ==> `~/.config/openbox/lxde-rc.xml`

y una vez listo, llamar como usuario de a pie a openbox con `openbox --reconfigure`

como nota y para no investigar demasiado

- `Prior` == RePage
- `Next` == UpPage
- `KP_[0-9]` == pad numerico
- `KP_Subtract` == el "menos" del pad numerico
- `KP_Multiply` == el "asterisco" del pad numerico
- `space` == barra espaciadora
- `Return` == enter
- `S` == Shift
- `C` == Control
- `A` == Alt
- `W` == Super
- `M` == Meta
- `H` == Hyper

una gozada ese fichero de configuracion de lxde, aunque algunos cambios como
agregar 10 escritorios, solo surgieron efecto al reiniciar

## next

en la bandeja de distros dejo **Uruk** y **Gentoo**, (por fin con dos equipos
intentar con gentoo o arch carese de riesgo), aunque de momento no pienso mover
mas

quedan pendientes hacer una modificacion al mapeo de teclado del sistema para lo
que hay que hacer una investigacion de donde demonios toma las mapeos debian,
pues en esta ocacion no los encontre en su localizacion habitual

el consumo final inicial de ram, con tilix corriendo, ronda los 140MB y con un
navegador y algunas pestañas los 260-320MB, algo por demas expectacular

el ultimo inconveniente pendiente es un "ruido de lineas" que aparece en el
video, probablemente sea cosa de hardware, no lo se, y mientras funcione o no me
ponga ocioso, hay se queda

larga vida y prosperidad, a ese (medio) portatil que funciona con el kernel libre y sin
pedir nada para la wifi!
