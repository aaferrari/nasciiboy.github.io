+++
title      = "Run Scheme"
tags       = [ "scheme" ]
categories = [ "emacs" ]
date       = 2017-08-20T18:42:53-05:00
+++

En el [anterior](https://nasciiboy.github.io/prog/ischeme/) post (cronologico del blog) comente algunos interpretes de
Scheme. Ya que en Emacs tenemos un interprete de elisp nativo, supuse que habria un
metodo sencillo, para correr Scheme, pero, por que correr todo un interprete
cuando se puede echar mano del interprete del sistema de turno y powerizarlo con el
incomparable **Emacs**, o si, hasta Gulie que en terminal era insipido, se
vuelve Sexi! Todos los interpretes adquieren historial, hasta los que no lo tenian!

... o eso es lo que aprendi en [este](http://community.schemewiki.org/?emacs-tutorial)
post, que me limito a traducir y alterar parcialmente (pues supongo al estar en una wiki
es permitido)

(nota: el post original, hablan de un modo "quack", pero viendo que mensionan
emacs-goodies, asumo que es algo "antiguo", viniendo de ejecutar los interpretes
en consola salvajemente, con lo que ofrece emacs por defecto tengo suficiente!
(por ahora...))

## Configuracion Basica

Coloque el codigo a continuacion en su fichero `init.el`, para configurar su uso
con Scheme

``` elisp
;;; Siempre con resaltado de sintaxis
(global-font-lock-mode 1)

;;; tambien con resaltado de parentesis
(setq show-paren-delay 0
      show-paren-style 'parenthesis)
(show-paren-mode 1)

;;; Este es el nombre binario de mi implementacion de Scheme
(setq scheme-program-name "scm")
```

Asegurese de remplazar **`"scm"`** con el nombre de la implementacion de Scheme
que este utilizando en su sistema

(resaltar que ya tenia activo `show-parent-mode`, la instruccion `setq show-paren-delay 0`
hace que no halla retraso al momento del resaltado, que por el uso que le daba,
presuponia estaba asignado en 1 segundo... correccion segun `C-h v
show-parent-delay` era de 0.125 segundos, maravilloso!)

## Trabajando con Scheme

Cuando abre un archivo, los nombres de los archivos que terminan en `.scm` o
`.ss` seran asumidos como archivos de Scheme, y se abriran con el modo scheme de
Emacs, que proporciona resaltado de sitaxis e indentacion automatica cuando
pulse `TAB`, y por spuesto resaltado de parentesis coincidentes.

### Ejecutar Scheme en Emacs

Puede ejecutar un interprete de Scheme en Emacs. Esto le permite controlar el
envio de los datos de entrada a su interprete desde emacs.

En primer lugar, crearemos una ventana para correr el proceso de Scheme
presionando `C-x 2`, seguido por `C-x o` para ir a esta. Ahora podemos
ejecutar un proceso de Scheme ingresando `M-x run-scheme`.  Esto ejecutara el
proceso que configuro anteriormente en su `.init.el`

Si esta realizando una prueba temporal, escriba en un buffer cualquiera `(setq
scheme-program-name "scm")` (remplazar *scm*), coloque el cursor en el parentesis de cierre y
pulse `C-x C-e`, de esta forma puede probar un interprete distinto, luego de
cerrar la secion previa escribiendo `(exit)`

![](/img/ischeme.png)

Para volver a la ventana inicial, presione `C-x o`.

Puede utilizar `C-x C-e` para enviar una expresion. Tambien puede enviar una
region, un comando previo o incluso el buffer entero, para consultar el resto de
atajos activos y disponibles (no vinculados con ninguna combinacion de teclado)
presione `C-h m`

### Comandos basicos

Algunos comandos basicos de movimiento del cursor:

- `C-a`: Inicio de linea.
- `C-e`: Fin de linea.
- `C-p`: Linea previa.
- `C-n`: Linea suguiente.
- `C-f`: Avarzar un caracter.
- `C-b`: Retroceder un caracter.
- `C-x delback`: Matar hasta el inicio de linea
- `M-p`: Retroceder por el historial.
- `M-n`: Avanzar por el historial.
