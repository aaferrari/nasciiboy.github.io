+++
title = "Definir atajos en Emacs"
draft = true
date = "2017-01-07T09:38:46-06:00"
categories = ["emacs"]
tags = ["howto"]
+++

![](../kara.jpg)

En emacs, tu puedes crear cualquier atajo de teclado para cualquier comando

Por ejemplo, si deseas [F7] para el calendario, coloca en tu archivo de
configuracion de emacs

``` elisp
(global-set-key (kbd "<f7>") 'calendar)
```

Si estas experimentando y no deseas reiniciar emacs cada vez que intentas
definir un nuevo atajo, puedes colocar el cursor al final del ultimo parantesis
e invocar a (`M-x`) `eval-last-sexp` (comando ligado a `C-x C-e`). El atajo se
activa de inmediato. Para salir del buffer calendario presiona `q`.

Si cometes algun error y necesitas iniciar emacs sin cargar el archivo de
configuracion, puedes iniciar emacs desde el terminal con este comando:

``` bash
emacs --no-init-file
```

## sintaxis

La funcion para definir atajos es

``` elisp
(define-key map COMBINACION 'FUNCION)
```

donde `map` es un mapa de combinaciones, o por decirlo de alguna forma, un
prefijo que precede a la combinacion en si

- `ctl-x-map` con prefijo `C-x`
- `ctl-x-4-map` con prefijo `C-x 4`
- `ctl-x-5-map` con prefijo `C-x 5`
- `ctl-x-r-map` con prefijo `C-x r`
- `esc-map`  con prefijo `ESC`
- `help-map`  con prefijo `C-h`
- `global-map` (sin prefijo) para cualquier combinacion. Esta ultima tiene una
  funcion dedicada y en ella centraremos la explicacion

``` elisp
(global-set-key COMBINACION 'FUNCION)
```

La `COMBINACION` de teclas puede ser cualquiera de estas 3 formas

- `"letra"`. Una unica letra de a-z o 1-9 dentro de comillas

- `[nombre]`. `nombre`, se substiye por el nombre interno o por el codigo que
  emacs asigna a cada tecla, la combinacion puede contener mas de una tecla pero
  siempre se efectua en un solo paso, por ejemplo `[s-left]` es presionar la
  tecla super + la tecla fecha izquierda, `[s-kp-5]` es presionar la
  tecla super + la tecla 5 del pad numerico.

- `(kbd "sequencia")`. `sequencia` es cualquier combinacion del teclado colocada
  entre parentesis, esta puede separarse en varios pasos si se coloca un espacio
  en blanco entre los nombres de las teclas. Dentro de la cadena, para hacer
  referencia a la tecla control, colocamos `C`, para meta/esc `M`, y para
  super `s`, las tres siempre van en conjunto con alguna otra tecla siguiendo el
  formato `C-tecla`, `M-tecla` o `s-tecla`. Finalmente podemos hacer referencia
  al nombre interno de una tecla, al colocarlo entre mayor que y menor que, por
  ejemplo `(kbd "<f8>")` sera la tecla F8


este es el nombre interno de algunas teclas

- `backspace` retroceso
- `return` enter
- `delete` suprimir
- `up` flecha arriba
- `down` flecha abajo
- `right` flecha derecha
- `left` flecha izquierda
- `f1`..`f35`tecla de funcion de F1 a F35
- `home` Inicio
- `end` Fin
- `help` Ayuda
- `kp-0`.. `kp-9` numeros del pad numerico
- `kp-subtract` menos del pad numerico
- `kp-add` mas del pad numerico
- `kp-enter` enter del teclado numérico
- `kp-decimal` punto decimal del teclado numérico
- `next` AvPag
- `prior` RePag

## ejemplos

``` elisp
(global-set-key [s-left]  'windmove-left)
(global-set-key [s-right] 'windmove-right)
(global-set-key [s-up]    'windmove-up)
(global-set-key [s-down]  'windmove-down)

(global-set-key (kbd "C-c <left>")  'windmove-left)
(global-set-key (kbd "C-c <right>") 'windmove-right)
(global-set-key (kbd "C-c <up>")    'windmove-up)
(global-set-key (kbd "C-c <down>")  'windmove-down)

(global-set-key (kbd "C-c o") 'recentf-open-files)
(global-set-key (kbd "C-x C-b") 'ibuffer)

(global-set-key [return] 'backward-char)
(global-set-key (kbd "<return>") 'backward-char)
(global-set-key (kbd "<f7> <f8>") 'calendar)
```

## Conocer el comando ligado a un atajo

Si invocamos a `describe-key` (`C-h k`) y, a continuacion, se presiona un atajo,
emacs mostrara el comando al que esta ligado.

Por ejemplo, supongamos que deseamos conocer el comando ligado a
`C-M-g`. Primero se llama a `describe-key`, luego se presiona la combinacion de
teclado, entonces emacs imprimira `C-M-g is undefined`. Esto significa que
puedes utilizar `(kbd "C-M-g")` para representar una combinacion de teclas en
codigo lisp.

## Combinaciones a evitar

Emacs tiene sus caprichos. Es mejor no definir las siguientes combinaciones, a
menos que sepas lo que estas haciendo.

- `C-cualquierLetra`. Dada la forma en que emacs esta implementado utiliza la
  sintaxis "C-letra" para un monton de atajos preestablecidos

- `F1` o `C-h`. Emacs utiliza esta combinacion para el sistema de ayuda de emacs
  y tiene un estado especial en el sistema de comandos de emacs.

- `ESC` o `C-[`. Esta combinacion por si misma tiene un significado complicado,
  dependiendo de cauntas veces se presione

- `C-Shift-letra`. Algunos terminales no pueben dintingur las versiones de la
  combinacion con Shift de la version sin Shift

## Buenas opciones

Emacs tiene unos siete mill comandos. De forma predeterminada, 800 de ellos
tiene un atajo. Si defines tus propios atajos sin cuidado es posible que muchos
modos primarios o secundarios anulen tus combinaciones, ya que estas tiene
prioridad.

En la documentacion oficial de emacs, Las combinaciones libres para el usuario
son de F5 a F9 y `C-c letra`.

Las siguientes combinaciones son buenos puntos de partida para tus propias
definiciones, y no causan ningun problema en la practica

- `F5`, `F6`, `F7`, `F8`, `F9`, `F12`. Puden combinarse sin problemas con
  Ctrl. Asegurate que no los utilize el sistema operativo.

- Super o Hyper. Cualquier combinacion con estas es buena, pero es posible que
  el terminal no reconosca las teclas Super o Hyper.

## fuentes

buena parte del articulo es una pseudo-traduccion de

http://ergoemacs.org/emacs/keyboard_shortcuts.html

otra, es una invencion no contrastada con el manual
