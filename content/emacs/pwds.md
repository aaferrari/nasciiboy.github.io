+++
title      = "pwds"
tags       = [ "ag" ]
categories = [ "emacs" ]
date       = 2018-04-26T16:07:39-05:00
draft      = false
+++

![](/img/kn1u1lt5t0dz.jpg)

Por lo habitual, mi uso de Emacs va emparejado con una terminal y auxiliado por
el navegador de ficheros (y firefox). Asi que lo mas conveniente seria poder
sincronizar las rutas de trabajo entre Emacs, Tilix (terminal) y
Nautilus (navegador grafico de ficheros) sin tener que escribir cada vez la ruta
entera, o andar pinchando con el raton en botones visuales

la solucion (quitando el glamour de la frace "sincronizar las rutas de
trabajo de ...") consiste simplemente en copiar la ruta actual de cada programa
al portapapeles

## tilix

la eleccion de este emulador de terminal (ademas de por su gnomero estilo y su
personalizacion de atajos profunda) se encuentra fundamentada en incorporar
marcadores de fabrica. Sin embargo, optener la ruta actual y copiarla
directamente al portapapeles no es una de sus caracteristicas... y por ello
la solucion puede aplicarse a cualquier emulador de terminal.

para saldar la limitacion usaremos el programa `xclip` (buscar
en el repositorio de su distribucion), en conjuncion con `pwd` y `tr` (para
eliminar el salto de linea producido por `pwd`)

    pwd | tr -d '\n' | xclip -sel clip

el comando se explica por si mismo...

otro comando que tambien suelo utilizar habitualmente para "ajustar" las fechas
en los post de este blog:

    date --iso-8601=seconds | tr -d '\n' | xclip -sel clip

si bien, el recordar estos comandos a primera vista parece (y lo es) una meta
imposible, ya que utilizo `fish` como interprete y como este se encuentra en
modo historial permanentemente, solo tengo que ingresar o `pwd` o `data` y el
solito se encarga de completar el comando. De esa forma evito crear un script
especifico para copiar cosas entre el terminal y el resto del entorno grafico

## nautilus

pues nada, aunque tiene sus marcadores, si se presiona la combinacion `C-l` nos
muestra y selecciona la ruta actual... Copiar, modificar o pegar!

## Emacs

los marcadores en emacs, ademas de diferenciarlo del resto de la "competencia"
lo convierten en un asistente muy potente. La cuestion es como comunicar las
rutas de trabajo con el portapapeles del entorno

La solucion mas sencilla es entrar en modo `direc` para seleccionar y matar la
ruta actual, y como la ultima entrada en el anillo de la muerte tiene
comunicacion directa con el cortapapeles, tendriamos resuelto el
problema... pero, ya que emacs se puede adaptar a nuestras necesidades,
extendamos su funcionalidad para que copie directamente en el clipboard tanto la ruta
de trabajo, como la ruta del buffer actual


```
(defun pwd-to-kill-ring ()
  "Agrega la ruta actual al kill-ring."
  (interactive)
  (kill-new default-directory))

(defun buffer-path-to-kill-ring ()
  "Agrega la ruta del buffer actual al kill-ring."
  (interactive)
  (if (buffer-file-name)
      (kill-new (buffer-file-name))
    (message "El buffer actual no esta ligado a un fichero")))

(global-set-key "\C-cp" 'pwd-to-kill-ring)
(global-set-key "\C-cf" 'buffer-path-to-kill-ring)
```

listo! con unas modificaciones minusculas tenemos nuevas funcionalidades y
atajos vinculados a estas. `C-c p` para optener el `pwd` y `C-c f` (si el
buffer actual esta vinculado a un fichero) para optener la ruta absoluta a la
fuente del buffer, o en su defecto un amigable mensaje *"El buffer actual no esta ligado a un fichero"*

(mencionar que emacs posee el comando `cd` con el que podemos modificar
manualmente el pwd al que apunta, como tambien un comando nativo
`pwd`. Este *pwd* cambia automagicamente segun el buffer en el que estemos)

### ido-mode

como el shell `fish` tiene un sistema de autocompletado de rutas automagico (fusionado con
el historial), emacs no podia ser menos y deberia proveernos ayuda con
el autocompletado de las rutas.

el modo `ido` nos proporciona autocompletado con "busqueda difusa" de patrones y
esta disponible para la busqueda de ficheros, directorios y buffers

de inicio, es un poco lioso y si presionas `tap` sin antes ver que es lo que
hace `ido` puedes verte creando ficheros en rutas inesperadas. Uno llega a
cogerle el truco, pero en ultima instancia es posible desactivar sus "ayudas"

`ido` forma parte de la distribucion estandar, asi que no tenemos que instalar
nada, solo configurarlo un poco

```
(require 'ido)                    ; invocar a ido
(setq ido-enable-flex-matching t) ; activar busqueda difusa
(ido-mode t)                      ; activar ido
```

con esto (hasta donde he podido percatarme) **ido** usurpara el lugar de los
comandos vinculados a `C-x C-f`, `C-x d`, `C-x C-d`, `C-x i`, `C-x C-w` y `C-x b`.

Para utilizarlo basta con escribir `tap` para completar automagicamente y usar
las flechas derecha e izquierda para navegar entre las opciones.

No hara falta escribir el nombre preciso del siguiente elemento en la ruta, con
escribir algunos caracteres, por ejemplo la extencion de lo que buscamos, seguramente
sea suficente.

en caso de que queramos desactivar **ido** y regresar temporalmente al comando
que este suplantando, basta con presionar `C-f`. Si con esto no es suficiente y
se desea apagar ido pues `M-x ido-mode`, o siendo mas radical, (mientras nos
habituamos) podemos vincular su activacion/desactivacion a un atajo

```
(global-set-key (kbd "C-c .") 'ido-mode)
```

### compile

la mayoria de los programas que realizan algun tipo de inspeccion en un fichero,
como pueden ser compiladores, exportadores de formatos o programas de busqueda
de patrones, suelen lanzar resultados con el formato

```
ruta-de-fichero:linea: "cosas"
```
o

```
ruta-de-fichero:linea:columna: "cosas"
```

el comando `compile` de emacs, se aprovecha de esta convencion para permitirnos
navegar entre los ficheros que indique nuestro programa, de una forma
mas comoda de lo que seria buscar directamente a mano el fichero, su linea y columna.

cuando se invoca al comando `compile` (`M-x compile`) nos pedira un comando (del
sistema) a ejecutar, este podria ser por ejemplo `gcc mis-cosas.c`, `make` o por
que no, `grep`!

Para buscar todas las coincidencias en una ruta!

```
M-x compile RET grep -Rn patron [ruta-opcional]
```

(`M-x compile RET grep -Rn package ~/nconf/emacsRocks/`)

![](/img/emacs-grep.png)

sorprendente!

para navegar, entre las coincidencias podemos cambiar entre ventanas (`C-x o`) y dar enters en las
lineas resaltadas, o, presionar `C-h m` y averiguar que combinaciones trae por
defecto `compile`.

ja, ja, ja, aunque la utilidad del comando es evidente, a los peresosos emacsers les
da mas por laborar una vez y descanzar eternamente. Por ello tenemos dos modos
disponibles para hacer busquedas "a lo grep".

El primero viene incorporado y se llama `occur`, vinculado a `M-s
o`. El inconveniente es que las busquedas se limitan al buffer actual.

El segundo, basa su funcionalidad en un (nuevo) comando del sistema llamado `ag` ([The Silver Searcher](https://github.com/ggreer/the_silver_searcher))
que es algo asi como un grep super rapido, configurado para actuar
recursivamente por defecto

hay un modo para unir en armonia tanto a `compile` como a `ag` para ello (como
recomiendan en su repositorio) tendriamos que clonar el fuente y agregar lo
siguiente a nuestro init:

```
;; source: git clone https://github.com/philsnow/ag.el
(add-to-list 'load-path "~/ruta/a/carpeta/ag.el")
(require 'ag)
(setq ag-highlight-search t)
```

para utilizar el comando: `M-x ag RET patron RET ruta`

... y eso es todo, happy hacking!
