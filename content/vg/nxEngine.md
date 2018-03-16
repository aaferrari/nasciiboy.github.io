+++
draft = true
date = "2016-12-19T11:29:56-06:00"
categories = [ "vg" ]
tags = [ "nxEngine" ]
title = "nxEngine"
+++

![](../Dokutsu.jpg)

Dōkutsu Monogatari mejor conocido en oxidente como Cave Story (La historia de la
cueva) es un videojuego de plataformas con un toque de RPG desarrollado por una
sola persona (Daisuke Amaya, alias "pixel") a lo largo de 5 años. Originalmente
fue liberado como *freeware* para la plataforma pc de microsoft, no obstante por
su sobresaliente calidad ha sido portado a una gran cantidad de sistemas entre
las que se encuentran AROS, MorphOS, AmigaOS 4, Mac OS, PSP, Dreamcast, GP2X,
..., y por supuesto GNU/linux.

Pese a que la licencia de distribucion no es libre, se cuenta con una
implementacion del motor (en C++) bajo la licencia GNU GPL v3 llamada
[nxEngine](http://nxengine.sourceforge.net/) y un par de traducciones al español
(utilizare [esta](http://www.romhacking.net/translations/2172/))

Si bien podemos disfrutar Dōkutsu Monogatari mediante **wine** (asunto con poco
misterio) vamos a compilar una vercion nativa con nxEngine. Todo lo que
necesitas lo encontraras en este [zip](../nx.zip). Descargalo y abre un terminal

    su
    # nxEngine depende de la libreria SDL. En freidora
    dnf -y install SDL-devel SDL_ttf-devel
    exit

    unzip nx.zip -d nx
    cd nx
    make
    ./nx # luego presiona ' ' (espacio) y 'a' (letra a)
    # listo

La vercion nativa no maneja apropiadamente los acentos ni los caracteres raros
del español, aun asi puede entenderse perfectamente.

Mi amor por esta obra es proporcional a su dificultad, moriras y moriras y
moriras y volveras a morir y cuando lleges al tramo final moriras muchas veces
mas. Recuerda salvar cada ves que se presente la oportunidad o te puedes pegar
un cabreo.

El unico defecto de este magnifico titulo, es la imposibilidad de saltarse los
dialogos. Cuando apreda a programar...

La duracion ronda entre 4-8 horas, (la primer vez que lo termine tarde 6). Como
dispone de varios finales, como minimo pasatelo 2 veces.

Puedes encontrar achivos de salvamento, ports diversos y muchas cosas mas en
http://www.cavestory.org/
