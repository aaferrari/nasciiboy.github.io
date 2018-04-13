+++
title      = "Keep Regexp"
tags       = [ "regexp" ]
categories = [ "emacs" ]
date       = 2018-04-08T11:50:44-05:00
+++

es muy vergonZoSo sentirse capaz y al enfrentar un reto quedarse congelado al
borde del fracaso

El asunto es el siguiente, tenemos [un fichero](/data/lista_correos.txt) con
correos (muchos correos, 79 exactamente). El fichero ademas de los correos
incluye nombres y comas y la meta es obtener unicamene los correos.

Empece el reto substituyendo comas por saltos de linea, luego probe una
complicada regexp para buscar los correos, pero tras muchos fallidos intentos,
abandone la idea... ademas, que esperaba encontrando la regexp? no es como si la
coincidencia colocara la region en la coincidencia y luego se pudiera "cortar" y
"pegar"

Lo siguiente, fue utilizar el comando `flush-lines` para borrar las lineas que
no coincidieran con el patron `[^@]`, "obviamente" no funciono, auque en mi ignorancia
culpe al patron... (risa histerica) y bueno, sucede que no te aclaras y hasta se
te olvida utilizar la ayuda del emacs

un par de intentos mas tarde, termine por utilizar una poco elegante macro, que
cumplia el objetivo chapuceramente

luego, tras ver la primer solucion, mas simple, conpacta, no del todo "segura", pero para el
caso efectiva

    cat lista_correos.txt | tr " " '\n' | grep @ | xargs

e inmediatamente despues un **vi**-liever solucionaba el asunto con

```
:%s/  */^M/g
:v/@/d
:%join
```

como podia evitar la inminente culpa y herida en el orgullo klingon-emacsero?

intetentando superar la frustracion, dio inicio un aprendizage formal y profundo
de las regexes en emacs y alguno que otro comando mas. Pero antes de pasar a
ello, fue nesesario aminorar el trauma implementando una solucion en awk y otra
en C....


```
# esto a un fichero, por ejemplo a.awk
1 {
    for( i=1; i<=NF; i++ )
        if( $i ~ /@/ ){
            printf( "%s\n", $i)
        }
}

# y luego ejecutar con:
# $ awk -f a.awk lista_correos.txt
```

[aca](/data/emailtor.zip) la solucion con C. Compilar con `gcc a.c
regexp4.c` y ejecutar con `$ a.out lista_correos.txt`

Un dia despues, con la agonia mental aun fresca, llego la solucion en emacs

```
M-<
M-x replace-regexp RET " +\|," RET C-o RET
M-<
M-x keep-lines RET "@" RET
```

(no conocia `keep-lines` si tu tampoco, te la presento. Ignorar las comillas son
para delimitar la cadena de entrada)

ciertamente mas extensa que vi, pero consideremos que emacs no tiene una
simbiosis con el comando sed, ni tampoco una implementacion de sus comandos de
tal forma que puedan ejecutarse "en bloques". No esta tan mal, supongo.

aqui es donde se podria iniciar una "guerra santa". Pero bueno, la naturaleza
extensible e ilimitada de emacs para un tema concreto puede ser menos eficiente,
es cierto... aunque, nada impide que se implemente un comando
<q><i>interprete</i></q> tipo sed e incluso otro para aplicar acciones por
lineas y de manera global (sin recurrir a macros)

Supongo que los usuarios del modo maligno, han hecho algo asi, mas profanar emacs con
tales paganismos, ni utilizar "modos" que fuerzan a presionar ESC de forma
inconciente, son algo a contemplar por mi parte, las cosas "modales" son un
dolor, ya es suficientemente modal tener que usar el firefox, o el navegador de
ficheros y andar presionando ahi teclas de otros "modos"

o, por aca un semi-equivalente en elisp de la solucion

```
(defun emailtor ()
  "Separa los correos en lista_correos.txt"
  (interactive)
  (goto-char (point-min))
  (while (re-search-forward " +\\|," nil t)
    (replace-match "\n" nil nil))
  (goto-char (point-min))
  (delete-non-matching-lines "@"))
```

ha, no es lo mas fino, pero para el caso cumple

## regexp

- Conjunto `[]`. Conjunto inverso `[^]`. Dentro de los conjuntos (con la
  syntaxis completa `[[:clase:]]`) se permiten las clases


  - `[:alnum:]` caracter alfanumerico
  - `[:alpha:]` una letra, incluidos caracteres unicode
  - `[:blank:]` espacio y tabulacion
  - `[:cntrl:]` caracteres ASCII de control
  - `[:digit:]` numeros ascii del 0 al 9
  - `[:graph:]` cualquier caracter visible, exepto espacios en blanco
  - `[:print:]` cualquier caracter visible, incluidos espacios en blanco
  - `[:lower:]` caracteres en minusculas
  - `[:upper:]` caracteres en mayusculas
  - `[:punct:]` signos de puntuacion
  - `[:space:]` espacios en blanco
  - `[:word:]`caracteres que formen parte de las palabras
  - `[:xdigit:]` caracteres hexadecimales (0-9, a-f y A-F)
  - `[:ascii:]` caracter ASCII
  - `[:nonascii:]` cualquier caracter no ASCII
  - `[:multibyte:]` caracteres unicode multibyte
  - `[:unibyte:]` caracteres codificados en un solo byte (basicamente todo ASCII)

- punto `.`
- metacaracter `\`
- agrupacion y captura `\(\)`
- coincidencia con la anterior captura `\d`. (Substituir `d` por el numero de captura)
- agrupacion sin captura `\(?:\)`
- alternativa `\|`
- cuantificadores
  - `?` cero o uno
  - `*` cero o mas
  - `+` uno o mas
  - `\{n\}` exactamente n
  - `\{n,\}` n o mas
  - `\{n,m\}` entre n y m
- modificadores
  - `$` coincidencia al fin de linea
  - `^` coincidencia al inicio de linea
  - `\=` coincidencia en la posicion del punto
  - `\'` coincidencia al final del buffer
  - <code>\\`</code> coincidencia al inicio del buffer
- fin o inicio de palabra `\b`
- (deacuerdo al modo) un caracter que forme palabras `\w` o `\sw`
- (deacuerdo al modo) un carac,ter que no forme palabras `\w` o `\Sw` o `\sW`
- espacios `\s-` o `\s ` ("`\s `")
- symbolos `\s_`
- delimitador de apertura `\s(`
- delimitador de cierre `\s)`
- caracteres de puntuacion `\s.`


### comandos de utilidad

- (search-forward)  busqueda de texto hacia adelante
- (search-backward) busqueda de texto hacia atras

- `C-s` (isearch-forward)  busqueda de texto de forma interactiva hacia adelante
- `C-r` (isearch-backward) busqueda de texto de forma interactiva hacia atras

- (search-forward-regexp)  busqueda de regexp hacia adelante
- (search-backward-regexp) busqueda de regexp hacia atras
- `C-M-s` (isearch-forward-regexp)  busqueda de regexp de forma interactiva hacia adelante
- `C-M-r` (isearch-backward-regexp) busqueda de regexp de forma interactiva hacia atras

- (replace-string) substitucion de texto
- (replace-regexp) substitucion de regexp
- `M-%`   (query-replace)        substitucion interactiva de texto
- `C-M-%` (query-replace-regexp) substitucion interactiva de regexp

- (highlight-lines-matching-regexp) resaltar cualquier linea que coincida con una regexp
- (highlight-regexp) resaltar una regexp
- (unhighlight-regexp) des-resaltar regexp

- (flush-lines) eliminar lineas que coincidan con la regexp. (el patron `^$` eliminara todas las lineas en blanco)
- (keep-lines) se eliminan las lineas que no coincidan con la regexp
- (align-regexp) alinea (verticalmente la parte en varias lineas que coincida con la regexp

## re-builder, isearch, isearch+

De entre las muchas cosas relacionadas con regexes, el modo `re-builder` es uno
muy interesante, pues nos permite escribir y editar una regexp con suma
facilidad y luego copiar el resultado.

Supongo que este modo, es una facilidad para los programadores de emacs,
basandome en que la expresion esta entrecomillada y al copiar la regexp con el
comando `reb-copy` (C-c C-w) incluye las comillas y ademas el formato de escape
de caracteres esta dispuesto a la forma que requiere el codigo fuente en elisp.

Dicho escape de caracteres y metacaracteres, se debe a la naturaleza de las
cadenas en C de hay que las cosas suelan requerir escapes para los escapes. Por
defecto re-builder viene en modo de syntaxis `read` que es de la que hablo, pero
tambien podemos cambiar a sintaxis `string` (la que utiliza isearch), bien
presionando la combinacion `C-c TAB` y escribiendo `string` o directamente colocando
lo siguiente en nuestra configuracion

```
;; re-builder
(setq reb-re-syntax 'string)
```

pese a la facilidad de edicion y creacion de regexes, me pregunto la razon de no
vincular este modo con isearch. Mas adelante (o no) una posible razon y un par de
soluciones.

los comandos basicos de utilidad

- `C-c C-w` copiar regexp (comillas incluidas)
- `C-c C-q` salir del modo
- `C-c TAP` cambiar syntaxis de entrada
- `C-c C-r` ir a coincidencia previa
- `C-c C-s` ir a coincidencia siguiente


**isearch** en sus modalidades mas conocidas `isearch-forward-regexp` (C-M-s) e
`isearch-backward-regexp` nos permiten buscar expresiones regulares hacia
adelante y hacia atras del punto interactivamente, mas no dejeis que os engañen
las funciones basicas de estos comandos, pues no son simples comandos, son modos
por si mismos, podemos averiguar sus muchas posibilidades (ya dentro de isearch)
presionando `C-h m` o con la documentacion de la funcion `C-h f
isearch-forward-regexp`

quiza el comando mas conocido de las busquedas interactivas sea `C-w` que toma
la entrada sobre y delante del punto como texto de entrada (dividida por
palabras). Pero ademas de esa combinacion tenemos otras muy interesantes

- `M-s e` para editar "con papeles" la regexp, aunque no interactivamente
- `C-M-y` ingresar a la regexp el caracter del buffer sobre el que esta el punto
- `C-M-w` borrar el ultimo caracter de la regexp
- `M-s C-e` ingresar a la regexp el resto de la linea apartir de la posicion del punto
- `C-y` traer ultima cadena del anillo de la muerte
- `M-y` iterar sobre el contenido del anillo de la muerte
- `M-c` cambiar la sensivilidad a las mayusculas-minusculas
- `C-s` siguiente coincidencia
- `C-r` anterior coincidencia

y muchas otras cosas misticas y confusas mas trae el modo. La cuestion
problematica tiene que ver con la forma en que isearch incorpora el contenido
del anillo de la muerte a la busqueda, pues si por ejemplo matamos la cadena
`\(group\)[set]` al hacer el yank (C-y) en lugan de ingresar `\(group\)[set]`
escapara los caracteres significativos en la regexp, dejando `\\(group\\)\[set]`
lo que obligaria a editar de forma penosa la expresion

preguntando en [reddit](https://www.reddit.com/r/emacs/comments/8aepnk/yank_text_in_isearch_without_escape_character/), el unico lugar donde aparecen respuestas prontas y en
ociones con feliz resultado, oantolin proporcionaba el siguiente comando
alternativo para hacer el yank con su contenido tal cual dentro de la expresion

```
(defun isearch-yank-kill-literally ()
  "Pull string from kill ring into search string literally."
  (interactive)
  (setq isearch-yank-flag t)
  (let ((string (current-kill 0)))
    (isearch-process-search-string
     string
     (mapconcat 'isearch-text-char-description string ""))))

(define-key isearch-mode-map (kbd "C-S-y") #'isearch-yank-kill-literally)
```

como puede verse, se sugiere la vinculacion al atajo Control-Super-y, pero en
mi caso me es incompatible con otro comando... lo que sirvio fue suplantar
directamente el comando yank de isearch dejando como nombre de la nueva
definicion solamente `isearch-yank-kill`

cabe aclarar, que la copia tal cual del contenido del anillo de la muerte, no es
una caracteristica considerada de inicio en isearch, por lo que al hacer un `M-y`,
el demas contenido del anillo seguira siendo modificado con escapes. De hay que
otro colega, 00-11, suguiriera el uso del modo isearch+, que si considero esta
necesidad en su base

**isearch+** (supongo) es una capa sobre el modo isearch que ademas de agregar
la posivilidad de hacer yanks sin modificar el contenido, nos colorear la
busqueda en secciones y proporciona varios comandos de utilidad extra. Todo esto
manteniendo los atajos de isearch (casi) intactos

isearch+, no viene en el repositorio melpa, para instalarlo deberemos copiar
directamente su codigo desde emacswiki a un fichero, y luego cargarlo "a mano".

https://www.emacswiki.org/emacs/download/isearch%2b.el

En el mismo fichero proponen cargar el modo con el comando

```
(eval-after-load "isearch" '(require 'isearch+))
```
pero he preferido agregar lo siguiente en mi init

```
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; PACKAGE*: isearch+            ;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;; source: https://www.emacswiki.org/emacs/download/isearch%2b.el
(load-file "~/.emacs.d/plugins/isearch+.el")
```

vamos con la justificacion de utilizar isearch+, que era poder hacer yanks.

En la linea 2547, tenemos la variable customizable
`isearchp-regexp-quote-yank-flag` que si la ponemos a `nil`, asi

```
    (defcustom isearchp-regexp-quote-yank-flag nil
```

nos dara el resultado que buscamos.

Si, se puede hacer el cambio de la varible en el init, pero ya que tenemos y
vamos a cargar el codigo directamente, mejor dejarse de historias y hacer el
cambio in-situ

(**nota:** al cargar isearch+ substituye automaticamente a isearch. He probado el
modo con emacs 25 sin ninguna extencion y funciona sin problemas)

ahora si, despues de tener isearch+ configurado, podemos escribir nuestra
funcion en **`re-builder`** (modo de syntaxis `string`) y copiar la regexp
(manualmente) ignorando los parentesis, para luego "pegarlo" directamente en
isearch(+) con un yank

## Enlaces, fuentes y otras cosas

- http://ergoemacs.org/emacs/emacs_regex.html
- https://ondahostil.wordpress.com/2017/10/21/lo-que-he-aprendido-expresiones-regulares-en-emacs/
- https://www.emacswiki.org/emacs/RegularExpression
- https://www.gnu.org/software/emacs/manual/html_node/elisp/Syntax-Class-Table.html#Syntax-Class-Table
- https://www.gnu.org/software/emacs/manual/html_node/emacs/Search.html#Search
- https://www.reddit.com/r/emacs/comments/8aepnk/yank_text_in_isearch_without_escape_character/
