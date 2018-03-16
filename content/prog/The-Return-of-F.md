+++
title      = "The Return Of F"
tags       = [ "howto" ]
categories = [ "prog" ]
date       = 2017-11-16T13:24:08-06:00
+++

<center>![](/img/F.jpg)</center>

Siguiendo esa bonita tradicion de las entradas **"que hacer despues de instalar
*X*"**, llega el turno de hacer un:  "que hacer despues de instalar... *Fedora*..."

y, es que el tour por antergos fue un encanto mientras duro, pero cuando las
cosas se pusieron feas, la ultima opcion que quedaba fue regresar a las frias y
perversas garras (~~reptili~~|fedori)anas.

Jo, jo, jo, no todo es tan malo, creo, freidora tambien tiene de lo ultimo y por ahora el
unico problema es que el equipo no se apaga si no es con un reinicio y cortando
el switch de la fuente en el interludio.... ja, ja, ja, es eso o hacerse de un
par de monitores con entrada no vga, o, conseguir un adaptador dvi->vga, ya sera
para navidad...

La siguiente agrupacion de aplicaciones es la condensacion de varias
instalaciones condensadas en forma de "lista" (en texto plano) donde convive con
su equvalente para debian y arch, comentando a grandes rangos para que es cada
programa y anotando otros que aunque no utilizo son interesantes. Obviamente
cambia segun la distro y las aplicaciones disponibles en los repos

pero bueno, este compendio esta probado en freidora 27. Cierto es que el
nucleo duro en la personalizacion de mi sistema se encuentra en `$HOME`, una
particion permanente, y en futuras instalaciones tambien tendre una particion
para *root*, para disminuir aun mas las configuraciones. Asi que la instalacion
de todas estas herramientas no deja de ser el paso mas sencillo. Si deseas
utilizar la configuracion tal cual, tendras que investigar como configurar
varias de estas, por ejemplo `surfraw` o variables de entorno como en el caso de
instalar java.

dividire los pasos en bloques con una pequeña explicacion de algunas cosas y al
final todos los comandos juntos en un solo bloque.


```
dnf -y install https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm
dnf -y install https://download1.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm
dnf -y install mg emacs moc htop fish tilix util-linux-user gnome-tweak-tool
```

lo primero es instalar los repos rpmfusion para tener aun mas programas como
`moc`. Los nonfree estan por los codecs, aunque creo que no sirve de nada
tenerlos si utilizas vlc. Es curioso, pero aparentemente todo lo que existe en
los repos de fedora tiene que ser solo y unicamente software libre, aunque esto
no incluye (supongo por motivos "practicos") eliminar los blobs del kernel e
incluir algunos controladores de wifis.

luego a instalar los programas indispensables antes de hacer otra cosa mas,

- como editor `emacs` y `mg` como opcion ligera y para casos de desastre, que
  utilizar `vi` es algo incomodo

- `moc` para poner musica, que sin ruido no se va a ninguna parte.

- `htop` para ver el rendimiento del sistema o matar procesos reveldes

- `tilix` por que es la terminal que mola de verdad y por que la tengo
  supertuneada

- `fish` como interprete y `util-linux-user` por que trae el comando `chsh` para
  colocar fish como shell por defecto

- finalmente `gnome-tweak-tool` para las 3 extensiones que uso

luego de esto, aprovecho para compilar `ckb` (no incluido en los repos), que se
encarga de controlar el teclado [aqui voz de gamer >] RGB [<], tambien muy
tuneado.

```
# desarrollo
dnf -y groupinstall "Development Tools"
dnf -y groupinstall "Development Libraries"
dnf -y install kernel-headers kernel-devel
dnf -y install svn subversion git mercurial bzr valgrind gource
```

esto instala librerias y herramientas de desarrollo, la ultima instruccion es
para obtener todos los sistemas de control de versiones populares

- `valgrind` para ver el rendimiendo de aplicaciones y otras cosas de
  programadores

- `gource` te hace una visualizacion grafica y kool de los comits en un repo

```
# programacion
dnf -y install clisp gdb ghc clang guile rust rust-doc ldc nasm cargo qt-devel qt-doc qt-creator kf5-kirigami arduino avr-libc fritzing

## java
dnf -y install java-9-openjdk java-9-openjdk-devel maven
update-alternatives --config java
update-alternatives --config javac
java -version
javac -version
```

basicamente compiladres e interpretes, para C/C++, lisp, scheme, haskell, rust, ensamblador,
cosas de qt, arduino y java. No las utilizo todas, pero si llega el
apocalipsis de internet, tendre que hacer.

Hace falta incluir `racket` (no viene en repos), pero eso ya lo busco y bajo si hace falta

```
# algunas librerias
dnf -y builddep emacs dosbox moc love supertuxkart tilix firefox inkscape
```

esto es para "poblar" el sistema con algunas librerias y no tener que buscar. En
la mayoria de los casos es mas que suficiente

```
# monitores
dnf -y install glances inxi ncdu
```

- `glances` e `inxi` para informacion del sistema
- `ncdu` para ver el uso de disco

(para instalar `dfc` ("uso de disco"), necesario es compilar desde el [repo](https://github.com/Rolinh/dfc))

```
# documentacion
dnf -y install zeal asciidoc pandoc poppler-utils caca-utils texinfo ghostscript pdfshuffle
dnf -y install tesseract tesseract-langpack-spa
dnf -y install elinks surfraw
```
- `zeal` visor visual de documentacion offline para cosas de programacion, en
  nome con el tema obscuro global (tweaks) tiene un aspecto agradable,
- `asciidoc` un formato de documentacion
- `pandoc` coversor de distintos formatos de documentacion
- `poppler-utils` creo que trae cosas para manipular pdf's
- `caca-utils` no me acuerdo que es...
- `texinfo` otro formato viejuno de documentacion
- `ghostscript` cosas de PostScript y PDF
- `pdfshuffle` manipular pdfs
- `tesseract`, `tesseract-langpack-spa` ocr
- `elinks`, `surfraw` para hacer busquedas por interne desde cli

```
# media
dnf -y install vlc blender inkscape dia gimp tiled pinta synfigstudio mypaint mtpaint gpick subdownloader
dnf -y install python-pip python3-pip
pip install subliminal
```

paquetes para ver y crear cosas graficas y `vlc`

- `subliminal` y `subdownloader` para conseguir subtitulos


```
# utilidades o algo...
dnf -y install thunderbird simple-scan gscan2pdf speedcrunch
```

- `thunderbird` cliente de correo
- `simple-scan` y `gscan2pdf` para que sirva de algo el scanner
- `speedcrunch` una calculadora... emacs ya trae `calc` que es mas util, pero
  esta, esta curiosa

```
# data
dnf -y install qbittorrent amule youtube-dl
dnf -y install dtrx unp unar zip unzip id3v2 cuetools shntool flac ffmpeg
```

- `qbittorrent`, `amule` clientes p2p
- `youtube-dl` bajar video|audio del yutu
- `dtrx`, `unp`, `unar`, `zip`, `unzip` (des|com)presion de archivos
- `id3v2` metadatos de audio
- `cuetools`, `shntool`, `flac`, `ffmpeg` para cortar y transformar flacs


```
# emergencia... y cosas
dnf -y install smartmontools testdisk foremost gparted rsync
dnf -y install aircrack-ng macchanger
```
las primeras son herramientas para comprobar y reparar discos, crear particiones
y sincronizar datos

las segundas para romper wifis, aunque aun no he tenido oportunidad (o
necesidad) de probar

```
# extra
dnf copr enable carlwgeorge/ripgrep
dnf -y install ripgrep
```

una alternativa|complmento a `grep`

los repos `copr` son el equivalente a un *ppa* ubunteroso, asi que precaucion,
ser cautelosos


```
# codecs
dnf -y install gstreamer1-plugins-base gstreamer1-plugins-good gstreamer1-plugins-ugly gstreamer1-plugins-bad-free gstreamer1-plugins-bad-free gstreamer1-plugins-bad-freeworld gstreamer1-plugins-bad-free-extras ffmpeg
```

con `vlc` como reproductor de videos y `moc` por parte de los audios, no los he
necesitado y creo que tampoco hace diferencia instalarlos o no, pero hay estan

```
# eliminar cosas inecesarias
dnf -y remove evolution gnome-calendar gnome-contacts gnome-maps gnome-terminal gnome-text-editor
```

borrar algunas cosas que no ocupo

y finalmente instalar `boinc` para colaborar aunque sea anecdoticamente con **la
ciencia**. Para esto no tengo los pasos concretos, sera en otra ocacion, pero
[este](https://fedoraproject.org/wiki/Installing_and_running_BOINC_client_in_Fedora_21)
post fue la clave para poder echarlo a andar, aunque es molesto tener ficheros
"de mas" en el home, sea por **la ciencia**

## el final

```
dnf -y install https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm
dnf -y install https://download1.rpmfusion.org/nonfree/fedora/rpmfusion-nonfree-release-$(rpm -E %fedora).noarch.rpm
dnf -y install mg emacs moc htop fish tilix util-linux-user gnome-tweak-tool

# desarrollo
dnf -y groupinstall "Development Tools"
dnf -y groupinstall "Development Libraries"
dnf -y install kernel-headers kernel-devel
dnf -y install svn subversion git mercurial bzr valgrind gource

# programacion
dnf -y install clisp gdb ghc clang guile rust rust-doc ldc nasm cargo qt-devel qt-doc qt-creator kf5-kirigami arduino avr-libc fritzing

## java
dnf -y install java-9-openjdk java-9-openjdk-devel maven
update-alternatives --config java
update-alternatives --config javac
java -version
javac -version

# algunas librerias
dnf -y builddep emacs dosbox moc love supertuxkart tilix firefox inkscape

# monitores
dnf -y install glances inxi ncdu

# documentacion
dnf -y install zeal asciidoc pandoc poppler-utils caca-utils texinfo ghostscript pdfshuffle
dnf -y install tesseract tesseract-langpack-spa
dnf -y install elinks surfraw

# media
dnf -y install vlc blender inkscape dia gimp tiled pinta synfigstudio mypaint mtpaint gpick subdownloader
dnf -y install python-pip python3-pip
pip install subliminal

# utilidades o algo...
dnf -y install thunderbird simple-scan gscan2pdf speedcrunch

# data
dnf -y install qbittorrent amule youtube-dl
dnf -y install dtrx unp unar zip unzip id3v2 cuetools shntool flac ffmpeg

# emergencia... y cosas
dnf -y install smartmontools testdisk foremost gparted rsync
dnf -y install aircrack-ng macchanger

# extra
dnf copr enable carlwgeorge/ripgrep
dnf -y install ripgrep

# codecs
dnf -y install gstreamer1-plugins-base gstreamer1-plugins-good gstreamer1-plugins-ugly gstreamer1-plugins-bad-free gstreamer1-plugins-bad-free gstreamer1-plugins-bad-freeworld gstreamer1-plugins-bad-free-extras ffmpeg

# eliminar cosas inecesarias
dnf -y remove evolution gnome-calendar gnome-contacts gnome-maps gnome-terminal gnome-text-editor
```

lol, tener cuidado siempre que utilicen `remove` con la opcion `-y` y el comodin
`*`, lo he aprendido de forma inmisericorde, al eliminar `evolution*` e irse con
el todo `gnome` y el servidor de audio (pipewire), ja, ja, ja, el sistema (grafico) funciono lo
suficiente para reinstalar `gnome` y luego quedarse colgado de forma
irremediable... aunque ahora ya no inicia el entorno grafico, aparece el login,
luego abro una terminal y desde hay lanzo el entonro grafico con `startx`, cual sera el
equivalente en wayland? `startw`, `startg`?
