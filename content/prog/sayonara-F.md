+++
title      = "Sayonara F"
tags       = [ "install" ]
categories = [ "prog" ]
date       = 2017-09-14T16:16:26-05:00
+++

![](/img/sayonara-F.jpg)

## fedora -> antergos (dos pantalas y un adios)

aaah, compras un disco duro, optienes dos semanas de depresion y terminas
cambiando de distribucion...

en mi aldea, diria que solo hay un sitio rasonable para comprar hardware, que no
por ello con variedad o siquiera stock, asi que cuando logre ahorrar para un
hdd de 2TB y no encontre existencias, fui a otro sitio y compre el hdd y termine
con un disco de servidor con miles de horas, crujidos y un mal historial del
smart, mas eso ocurrio luego de haber pasado casi toda mi coleccion de
libros y perderlos en el limbo...

luego de varias vueltas por el establecimiento, cambios y mas tarde amenasas, el hdd se
convirtio en un monitor lcd de la peor calidad, aunque por ser un poco mas amplio
que el que tenia termino relegando al otro a un ricon.

tiempo despues, una brillante idea surgio, o si! conectar los dos monitores a la
placa! Mas al ser ambos vga dificil era (aunque no pocas preguntas y confusas
respuestas de foros hablaban de como lograr tal exotica configuracion).

Pues bien, una targeta de video (asus nvidea 220) y modificaciones a el
(esoterico) `xorg.conf` mas tarde, ademas de mensajes en foros que aseguraban que hacer
funcionar los graficos integrados del procesador (primer monitor vga) en
conjunto con los graficos de la placa de video dedicada (segundo monitor vga) era
imposible.

la idea, convertida en necesidad de ver a ambos monitores funcionar fueron tan
fuertes como para abandonar la alegria ofrecida por debian 7. Inicio "la
busqueda" de la distribucion prometida que hiciera funcionar el invento sin mas.

## el caso de fedora

pasaron open suse, manjaro, linux mint y alguna mas que no recuerdo, hasta
llegar a Fedora 23 que cual shaman hacia funcionar ambos monitores desde que se
iniciaba el instalador, wooow!

fin del cuento

bueno... no, fuuuhhhh f-e-d-o-r-a, como decirlo, es e-s-p-e-c-i-a-l, un dia le
da por cambiarte el nombre de los directorios, al siguiente por no producir
ningun sonido, otro por desaparecer mapeos de teclado, luego por ignorar el
tercer nivel de las teclas, por comportamientos erraticos en los programas, o
simplemente dejar de arrancar con un kernel, no es una exageracion comentar que
cada actualzacion es como una ruleta rusa.

Por que actualizar entonces? pues por la esperansa en que algun cambio resolviera
sus comportamientos extraños

al poco tiempo llego fedora 24 y di un tour por las otras hijas de red hat, centos y mageia, en la
primera su aspecto viejuno me echo hacia atras y en la segunda la magia
multimonitor no se presento

fedora 24 fue una dura prueba, aun asi tener el doble de espacio justificaba el
sufrimiento, y en fedora 25 muchos comportamientos extraños fueron corregidos

el anelo por regesar a debian o probar arch, nunca desaparecio, pero con el
tiempo llegue a aceptar a fedora, debo reconocer que la idea de regresar a una
distro con X11 era desagradable, aunque la verdad sea dicha con wayland no es
que las cosas fueran apresiablemente distintas, aaahh fedora, no se si eres
puntera o el peor laboratorio de pruebas que existe

(no tan) recientemente aparecio fedora 26 y en ningun intento la actualizacion
fue posible, el instalador jamas llego al modo grafico, asi, por mera curiosadad
y luego de haber cacharreado (por encargo) con una laptop, llego antergos he instale sin
esperar nada y tras el reinicio **hu-ha-ho** los dos monitores a pleno
rendimiento

## el caso de antergos

imitando a Mel Gibson grite, libertaaaaaaad!

ilusion o engaño? haber, un reebot... ... ... ...nop, sigue funsionando, veamos
como se instalan cosas en esta distro, huum, pues no lo tengo claro, pero tieno
algo como synaptic

y asi instale la mayoria de cosas que hacian falta, creo que para la siguiente
ocasion intentare con una lista a medida desde consola con pacman y yaour, aqui la dejo
por si quieren jusgar

```
yaour  -Sy ckb-next-git
pacman -Sy emacs fish tilix moc

pacman -Sy svn subversion git mercurial bzr vlc shntool cuetools flac ffmpeg asciidoc pandoc htop dfc valgrind youtube-dl zeal gource
pacman -Sy kdeconnect kde-cli-tools sshfs chrome-gnome-shell
ufw allow 1714:1764/udp
ufw allow 1714:1764/tcp
ufw reload

pacman -Sy clisp ghc clang guile rust rust-docs ldc nasm cargo racket racket-docs
pacman -Sy thunderbird blender inkscape dia gimp mypaint tiled mtpaint gpick pinta synfigstudio subdownloader qbittorrent simple-scan
pacman -Sy unp unrar zip unzip poppler libcaca asciidoc pandoc id3v2 smartmontools testdisk foremost gparted rsync ghostscript texinfo arduino avr-libc ripgrep speedcrunch
pacman -Sy love ppsspp fceux higan snes9x zsnes dosbox
pacman -Sy aircrack-ng macchanger

yaour  -Sy dtrx fritzing scid_vs_pc gscan2pdf

pacman -Sy python-pip
pip install pygments subliminal
```

por aclarar `ckb-next-git`, es para que funcione mi extrabagante teclado
mecanico (regalo de un camello empresarial) que ensima de estar en programmer
dvorak tiene 7 teclas cambiadas de lugar, si, si que vale la pena el pequeño
disturbio mental cuando hay que instalar una nueva distro.

Lo de `ufw` se debe a que durante la instalacion marque (por probar) la casilla de
firewall, todavia no lo tengo claro, pero es necesario abrir esos puertos para
que kde-connect funcione

un hecho curioso del "synaptic" de antergos, es que no pide la contraseña de
root, asi que luego de looguear como su: `passwd`... pero aun asi la contraseñå
del usuario de calle sigue siendo la que manda en el instalador de software
grafico y creo que todo lo que se hace en la secion grafica... b-u-e-n-o, la
perfeccion no existe

hablando de perfeccion, el instalador de la distro, no es vistoso, mas si
consiso, exepto por el *enorme* detalle de configurar el wifi, dependiente
casi del azar

una vez mas encogiendo los hombros "b-u-e-n-o, la perfeccion no existe"

## lightdm

y asi, con una sonrisa me fui a dormir...

la, la, la, la, encender, bienvenida, y, *no funsiona el teclado?*,
haber, toquetear, leer, reinstalar, nop no funsiona, uhm reinicio? oh, ya
funciona, mmmmm, haber, bloquear-pantalla/desblouear-pantalla... **lightdm**,
comorrr? y el gdm? jo, si funciona que mas da, dije para mis adertros, pero que?
cuando lightdm esta activo pasa del mapeo del teclado y se pone en english,
juar, juar juar, que gracioso, que mas da, igual y hasta agrega "seguridad"

la, la, la, la, bloqueo y regreso unas horas despues y... lightdm se queda
colgado, pero que es esto? a la mierda, si vas a poner gnome poner el puto gdm,
para que jodidos quiero cambiar fondos de pantalla dentro del gestor de secion, he,
para que?

es sencillo, el cambio, decian varios blogs de internet, instalas gdm, eliminas
lightdm, deteren, desabilitar, y encender... pero algo raro paso y con gdm se
jodio el asunto un logueo infinito que no lleva a ningun lugar, maldicion, regreso a
lightdm y no bloqueare secion nunca mas... un confuso proceso de instalaciones y
eliminaciones despues entre gdm-lightdm, que no documente pero puede que sea en
este orden (aceptar el riesgo y hacerlo desde una ttty)

```
pacman -Rcns lightdm
systemctl stop lightdm
systemctl disable lightdm
pacman -Sy gdm
systemctl enable lightdm
systemctl start lightdm
```

si ademas tienen una distribucion de teclado no convencional, antes de ir a un tty
establecer el mapeo pertinente o sufrir

    echo 'KEYMAP=dvorak-programmer' > /etc/vconsole.conf

luego de manocear un poco y cambiar en gdm a *gnome classico* se logro el
regreso al entorno grafico, que tambien se podia con un `startx`.

Je, el plan era estar una semana en antergos, si, como no, probemos manjaro... no
arranca, bueno, regresemos a fedora, ya la conosco, no, no funsiona, he, he, he
(tick nervioso). Haber calma, puedo vivir con gnome classico con su molesta
barra al fondo e iconos en el escritorio

Y asi fue como aprendi a poner el firefox en pantalla completa sin esconder la
barra de pestañas: `about:confing` -> `browser.fullscreen.autohide` ->
`false`. Linda configuracion, a juego con las terminales y el emacs!


y asi sin esperanza en el corazon, aunque el resto del sitema funcionaba bien,
antes de ofreser la maquina al fuego y asumir el rol de un sin techo,
suiguiendo los consejos de un [poeta](https://totaki.com/poesiabinaria/2017/08/configuracion-nvidia-optimus-driver-privativo-bumblebee/)
para arreglar el problema del logueo con gdm agregue una opcion al arranque de grub (`emacs /etc/default/grub`)
`acpi_osi=! acpi_osi=\"Windows 2009\"`

para actualizar los valores del grub (no hay update-grub en arch), con:

    grub-mkconfig -o /boot/grub/grub.cfg

antes de loguearse en gdm, colocar la secion en *gnome xorg*...

fin

## Don't Let Me Down (epilogo)

pasaron los dias (2) y el escritorio de nasciiboy suguio funcionando en aparente
perfeccion

el pc nunca fue ofresido al fuego (concientemente)

y la llegada de wayland fue .......
