+++
title      = "Miscelanea Emacs"
tags       = [ "elisp" ]
categories = [ "emacs" ]
date       = 2018-03-06T18:00:06-06:00
+++

aqui una serie de pequeños trucos y apaños recientes

primero, sin buscarlo intencionalmente he estado utilizando emacs en modo
consola, en un terminal grafico, pasado por ssh y filtrado bajo gnu
screen.

Acostumbrado a la version grafica de emacs y al no tener interferencia en
practicamente ninguna combinacion de teclas. Al toparme de lleno primero con la
interferencia del terminal y luego la de screen, me descoloque bastante, pero ya
empiezo a acostumbrarme e ingresar algunos comandos por su nombre y asignar
rutas alternativas a algunos comandos, ademas de explorar modos que
por lo general no uso extensivamente, como por ejemplo **`*eshell*`** donde
descubro estupefacto que de vez en cuando company-mode (autocompletado) interfiere ingresando
espacios al azar y/o borrando caracteres... ja, ja, ja, la solucion a este mal es desactivar company en
ese modo en especifico

    (setq company-global-modes '(not eshell-mode))

el segundo truco suculento esta relacionado con el lenguaje de marcas imaginaria
morg al que ni en un futuro cercano, medio (y tal vez lejano) creo contar con la
habilidad de programarle un modo propio, asi que sigo ultrajando a org-mode y
sus facilidades. Una caracteristica que hechaba mucho en falta es el resaltado
de la sintaxis "en linea" de comandos "arroba" asi que cada vez que visitaba un
texto, lo unico que se me ocurria era resaltar dicha sintaxis mediante el
comando `highlight-regexp` con una regexp esoterica.

Recientemente le agregue un gancho al emacs para que lance una serie de
highlights que automaticen el resaltado. No es perfecto, ya que aveces se
resaltan cosas aleatoriamente y otras la regexp es incapas de encajar con la
sintaxis, pero de momento sirve de apaño

```
;; cargar ficheros .morg en modo org
(add-to-list 'auto-mode-alist '("\\.morg\\'" . org-mode))

;; resaltar "cosas"
(add-hook 'org-mode-hook
          (lambda ()
            (highlight-regexp "@[^[<({]+[[<({][^]>})]+[]>})]" 'hi-green-b)
            (highlight-regexp "@[[<({][^]>})]+[]>})]" 'hi-red-b)
            (highlight-regexp "@[^[<({]+[[<({][]>})]" 'hi-red-b)
            (highlight-regexp "[[:space:]]@[[:space:]]" 'hi-yellow)
            (highlight-regexp "@[a-zA-Z]+[[:space:]]" 'hi-yellow)
            (highlight-regexp "^ *@ +.*" 'hi-pink)
            )
          )
```

y finalmente, la primer funcion en emacs lisp (`shell-region-insert-for-markdow`) que programo "por ver si
funcionaba". Un poco de corta y pega, un algo de lo traducido del manual de
introduccion a emacs lisp y un tanto de prueba y herror (con h)

```
(defun shell-region (start end)
  "execute region in an inferior shell"
  (interactive "r")
  (shell-command  (buffer-substring-no-properties start end)))

(defun shell-region-insert-for-markdown (start end)
  "execute region in an inferior shell and insert output with markdown sintax"
  (interactive "r")
  (save-excursion
    (goto-char end)
    (insert "\n")
    (dolist (line
             (split-string
              (shell-command-to-string (buffer-substring-no-properties start end))
              "[\n]")
             t)
      (insert "\n" "    " line))
    )
  )

(global-set-key (kbd "C-c x") 'shell-region)
(global-set-key (kbd "C-c i") 'shell-region-insert-for-markdown)
```

la primer funcion ejecuta la region activa en una shell mostrando la salida en
un buffer (si la hay). La segunda funcion hace lo mismo pero agrega el salto
mortal de insertar la salida del comando dentro del mismo buffer con el formato
de (cuatro espacios al inicio de) markdown. Je, je, a que mola!

por supuesto con las respectivas combinaciones de teclado para parecer aun mas
pro. En cuanto a (e)lisp en si, pues esta curioso, sigo creyendo que ajustar
todo a listas es un bonito truco academico pero incomodo en el uso diario. No
contar con tipado aun si las funciones tienen nombres (medio) claros poco ayuda
y desconocer que demonios devuelve una funcion hasta leerse la documentacion a
detalle tampoco es motivante, acaso seguimos en los 70's?

Aun asi curioso, estimulante y esoterico programar para emacs es, de a poco le
estoy encontrando el gusto...

este par de comandos los hice un poco pensando en
[xiki](http://xiki.org/screencasts/) aquella shell montada en emacs con una
ambicion desmedida que cerro su codigo una vez (creo) y luego termino en
naahhh. Hubiera sido un buen modo, seeh hubiera sido un buen modo... mmm, no
parece muy dificil de implementar, no lo habra hecho ya algien (de buen corazon
y espiritu GPL hippie)?

**actualizacion**: si existe un modo que imita a xiki, no muy logrado pero se puede
usar y se llama [elxiki](https://github.com/lahorichargha/elxiki). Gracias a la
gente de [r/emacs](https://redd.it/82k4ym)!.

luego de cargar el modo

```
$ git clone https://github.com/lahorichargha/elxiki
(add-to-list 'load-path "ruta-a-directorio-elxiki")
(require 'elxiki)
```

para enterarse de como usarlo visitar
`ruta-a-directorio-elxiki/menu/elxiki.menu` y ejecutar `M-x elxiki-mode`


happy hacking!

# fuentes

- https://stackoverflow.com/questions/6286579/emacs-shell-mode-how-to-send-region-to-shell
- https://emacs.stackexchange.com/questions/21042/disable-minor-mode-in-major-mode
