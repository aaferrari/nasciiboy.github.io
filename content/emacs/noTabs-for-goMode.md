+++
title = "no mas tabs en go-mode"
draft = true
date = "2017-02-12T21:52:24-06:00"
categories = ["emacs"]
tags = ["howto"]

+++

Go tiene una ridicula guia de estilo para formatear codigo que no me agrada, de
no seguir algunas reglas el compilador/interprete simplemente se niega a hacer
nada. Otras reglas, son menos rigurosas, como la indentacion o colocar o no
espacios, en algunos sitios.

La indentacion oficial del lenguaje, tiene tabs equivalentes a 4 espacios en
blanco y eso, eso, es algo que no puedo soportar, como tampoco tener tabs,
porque cada editor los despliega como le viene en gana.

Por eso, dentro de la configuracion de emacs tengo esta linea

``` elisp
(setq-default indent-tabs-mode nil)
```

su funcion es substituir los tabs por espacios, y en el modo go tenia esta
modificacion

``` elisp
(add-hook 'go-mode-hook
          (lambda ()
            (setq tab-width 2)))
```

para que los tabs se representen como dos espacios en blanco.

Perfecto! subo un repositorio de codigo en go a github y por curiosidad veo el
codigo ya en el repo... la indentacion es un jodido desastre! los tabs son
tabs... pero, pero, si en el jodido modo go, todo se ve perfecto, que esta
pasando es cosa de github o un problema interno?

paso a abrir el codigo en emacs y cambio a `fundamental-mode` para visualizar la
realidad, resultado, el problema esta en go-mode, en efecto los tabs se
visualizan como 2 espacios, pero en el fichero *no se substituyen por espacios,
siguen siendo tabs*, donde esta el culpable?

paso a ver el codigo de go-mode, en busca de expresiones regulares y cosas como
`\t`... no encuento el problema (y tampoco entiendo mucho de lisp)... entonces
cambio la busqueda a cosas que contengan la palabra `indent` y aparece esta linea

``` elisp
  ;; Go style
  (setq indent-tabs-mode t)
```

(commit 5737e59cbac9bc480546766c9502c527fa2be26f, linea 985)

Su funcion es dejar los tabs como tabs y no como espacios, la solucion? cambiar
`t` por `nil` directamente en el codigo de <span class="file">go-mode.el</span>
o en un *hook* en la configuracion.

``` elisp
(add-hook 'go-mode-hook
          (lambda ()
            (setq indent-tabs-mode nil)
            (setq tab-width 2)))
```

ahora, si abres tu codigo los cambios se realizan solo a las lineas que
modifiques, no a las lineas ya existentes. Es necesario reeindentar todo y no
funciona `C-x h tab`, hay que quitar la indentacion e indentar de nuevo, hice
una macro que recorria todas las lineas eliminando los espacios al inicio, luego
si seleccione todo + tab (`C-x h tab`).

Tabs y espacios en armonia!

![](../space-friend.jpg)
