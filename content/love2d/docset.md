+++
categories = ["love2d"]
date = "2017-07-22T09:06:44-05:00"
draft = true
tags = ["apt"]
title = "Love, Emacs & Docs"

+++

*Love2d* es un framework "open source" para crear videojuegos 2D multiplataforma
con el lenguaje de programacion Lua y que aparentemente es muy facil de
utilizar, al menos tan facil como para practicamente no tener documentacion mas alla de
las funciones que proporciona el framework

Y bueno, para los que no tenemos una memoria privilegiada para memorisar cientos
de funciones y sus parametros, deberiamos contar con un medio practico para consultar dicha
documentacion

Desde la pagina ofrecen una wiki... tambien disponible en modo offline, asi que
en un ataque de creatividad, abri dos emacs en modo eww uno en cada monitor,
grabe un marcador y a triunfar

![](/img/love-wiki.png)

luego de un rato... fue obvio que no era la mejor forma de consultar la
documentacion, y como no hay un maldito estandar para hacer documentacion
decente (hasta ahora) recurri a un viejo conocido

## zeal

![](/img/zeal.png)

que es [Zeal](https://zealdocs.org/)? es la implentacion libre y sin un tema
obscuro de dash, que aunque a primera vista pareciera ser el nombre de un shell,
mas bien es una *app* visual para gestionar documentacion. En realidad es
un visor web, con un buscador integrado que trabaja con bases de datos
sqlite3... o eso creo entender

Confirmando mis suposiciones de que tener abierto el navegador para leer de
internet la documentacion es lento y doloroso, una buena persona hiso un
*docset* de las funciones de love2d, que es el formato con el que trabaja zeal

instalamos zeal (en freidora)

    dnf -y install zeal

abrimos zeal y agregamos el feed de la documentacion ([no oficial](https://github.com/ChrisJan00/love2d_docset)) de love2d

con el raton *Tools -> Docsets -> Add feed* y pegamos

    dash-feed://http%3A%2F%2Fchrisjan00.github.io%2Flove2d_docset%2FLove2d.xml


por degracia, dicha documentacion corresponde a la version 0.9.1. Para
no dejar de estar a la moda, vamos a crean nuestra propia documentacion, para
esto necesitamos tener instado sqlite (no estoy seguro si 3, ya lo tenia
instalado asi que no hice nada) y seguir
[esta](https://kapeli.com/docsets#setUpFolderStructure) guia (en ingles) o
basado en (lo que entendi de) ella seguir la sugiente receta y tener instalado
Go (vee aceptandolo, ese lenguaje va a ser muy popular) para instalar
[dashing](https://github.com/technosophos/dashing) que hara un poco mas sencilla
la tarea. Empecemos


```
mv /tmp                           # para evitar "limpiar" al terminar
wget https://love2d.org/docs.zip  # optenemos la "wiki" offline
unzip docs.zip                    # descomprimir
cd wiki                           # ir al directorio descomprimido

go get -u github.com/technosophos/dashing  # optener dashing
dashing create                             # crea una "plantilla"
emacs -nw -q dashing.json                  # editamos la plantilla
```

Modificamos la plantilla para que se paresca a esto:

```
{
    "name": "love2d",
    "package": "love2d",
    "index": "index.html",
    "selectors": {
        "h1": "firstHeading"
    },
    "ignore": [
        "ABOUT"
    ],
    "icon32x32": "favicon.png",
    "allowJS": false,
    "ExternalURL": "https://love2d.org/wiki/Main_Page"
}
```

- `name` == nombre
- `package` == paquete
- `index` == tiene que apuntar al inicio de la wiki
- `selectors` == etiuetas y atributos html que seran agregados a la base de
  datos. No encontre una estructura clara en el html y tampoco entiendo las
  posibilidades de esta etiqueta. En el resultado se repiten 2 veces algunas
  cosas, pero es funcional
- `icon32x32` == el icono de la documentacion. La wiki ya trae un icono de love2d asi
  que ponemos el nombre del fichero
- `ExternalURL` == pense en abrir un repo con la documentacion actualizada, pero
  no...

```
dashing build # crear docset
```

esto crea la carpeta love2d.docset, la movemos a donde zeal tiene su
documentacion (en freidora seria):

```
mv love2d.docset  ~/.local/share/Zeal/Zeal/docsets/
```

abrimos zeal y buscamos si aparece la documentacion

![](/img/zeal-love.png)

zeal funciona como el navegador, con C-k buscamos cosas (poner prefijo de la
documentocion, en este caso `love2d:`), tiene un bonito autocompletado, nos movemos
con las flechas arriba, abajo, C-u para borrar. Con C-f podemos buscar dentro de la "pagina" con
la documentacion

## Soporte de Lua en Emacs

Podemos instalar *lua-mode* desde la paqueteria, si desconfias de las cosas
automagicas clonamos el repositorio a donde tenemos nuestras extenciones, por
ejemplo

```
cd ~/.emacs.d/plugins/
git clone https://github.com/immerrr/lua-mode.git
```

abrimos el init.el y copiamos lo suguiente en algun lugar

```
;; source: git clone https://github.com/immerrr/lua-mode.git
(add-to-list 'load-path "~/.emacs.d/plugins/lua-mode")
(autoload 'lua-mode "lua-mode" "Lua editing mode." t)
(add-to-list 'auto-mode-alist '("\\.lua$" . lua-mode))
(add-to-list 'interpreter-mode-alist '("lua" . lua-mode))
(setq lua-indent-level 2)
```

listo tenemos el lua-mode, para el autocompletado... esperar a que sepa programar en
elisp y extender company... si quereis adelantarme [uno](https://github.com/company-mode/company-mode/wiki/Writing-backends) y [dos](http://sixty-north.com/blog/writing-the-simplest-emacs-company-mode-backend) links

## + Enlaces

https://love2d.org/wiki/examples.love, ejemplos basicos-practicos y sin
consideracion para los deviles de voluntad

https://github.com/love2d-community/awesome-love2d, recopilacion de recursos
para programacion

http://sheepolution.com/learn/book/contents, un tutorial con obejas, desde las
bases hasta lo basico

https://github.com/SSYGEA/blog/, no lo he leido, parace interesante

http://www.lua.org/manual/5.1/es/manual.html, el manual de lua en español, no te
dejes engañar, es mas extenso de lo que aparenta

Eso es todo por esta sesion, happy hacking!
