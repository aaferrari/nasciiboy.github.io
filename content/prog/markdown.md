+++
title      = "Markdown"
tags       = [ "txt" ]
categories = [ "prog" ]
date       = 2018-03-18T13:17:26-06:00
+++

pues resulta que los humanos nos diferenciamos de las demas creaturas por que
podemos depositar y almacenar **el conocimiento** en medios externos a nuestro
propio cuerpo mediante un formato de codificacion (grafica o "tactil")
particular, sea como [pictogramas](https://es.wikipedia.org/wiki/Pictograma) o
[logogramas](https://es.wikipedia.org/wiki/Logograma), (o representaciones
intangibles digitales de ceros y unos).

Ya que como especie nos dispersamos por el globo y como volar, el
teletransporte ni la telepatia forman parte de nuestras habilidades, se formaron
grupusculos aislados que terminaron por inventarse y/o adaptar y/o diverger
dialectos y metolodogias para preservar y difundir su informacion...
y asi hemos estado con cambios minusculos durente miles de años  ¯\\\_(ツ)_/¯ limitados a la
subsistencia, hasta que con la imprenta (supongo) el motor de vapor y luego las
cable-comunicaciones dio inicio la transmicion masiva (no sexual) de informacion

Desde entonces, la poblacion ha crecido aun mas, los limites de las comunidades
se hacen cada vez menos obvios y en general la cantidad de procesadores
biologicos dedicados a labores puramente intelectuales se incrementa.

En los ultimos 200 años la produccion de informacion junto a su intercambio han
modificado nuestra forma de interactuar con el ambiente, al grado de transformar
a la especie misma, sus costumbres, metas inconcientes y batallas por la
egemonia. Como un divulgador cientifico dijo alguna vez

> la vida es una guerra de informacion

la aparicion de la informatica a traido nuevas batallas, pongamos como ejemplo
la representacion misma del lenguaje. En los incipientes albores de las
computadoras, limitadas en capaciad de calculo y almacenamiento, cual fue la
forma de representar y almacenar los caracteres con mas o menos eficiencia? 2
bits? 4 bits? alguien dijo 8? o 16? El ganador de aquella primer
confrontacion fue [ASCII](https://es.wikipedia.org/wiki/ASCII),
un simbolo de identidad entre los informaticos. Traducido, el acronimo vendria a
ser "Código Estándar Estadounidense para el Intercambio de Información" y se
basa en asignar un codigo numerico para cada caracter del ingles moderno, en un
rango decimal que va del 0 a 127, conteniendo numeros, letras en minuscula, mayusculas,
signos de puntuacion y ademas algunos codigos especificos de control (Fin de
transmision, salto de linea, retroceso, Escape, etc)

La construccion misma de los procesadores, que estandariso los buses de datos
en multiplos de 8 bits (16, 32, 64, 128, 256, ....) junto a la llegada de
ordenadores a mercados no angloparlantes, obligaron a los fabricantes a
aprovechar el octavo bit libre en la codificacion ASCII, para adaptarlo a los
distintos sistemas de escritura... y en otros casos, para enriqueser los
simbolos graficos desplegados por los equipos

Con el tiempo, aquellos primeros equipos comenzaron a intercomunicarse, viendo
la inminente necesidad de acordar un nuevo estardar de codificacion, donde
tuvieran cabida todos los caracteres de escritura. Dicho acuerdo recivio el
nombre de [UNICODE](https://es.wikipedia.org/wiki/Unicode) asignando un
codigo y nombre a cada caracter dentro los valores almacenables en 32 bits (que
pueden codificarse en secuencias de 8 (UTF-8), 16 (UTF-16) y 32 (UTF-32) bits)

De forma paralela mientras se encontraba la forma de representar el lenguaje escrito,
tambien se buscaron maneras para transladar el contenido de los libros
tradicionales impresos en papel a los monitores digitales, y viceversa, es decir,
mediante la informacion almacenada digitalmente, poder facilitar la
creacion de libros impresos.

Dicho enfoque inicialmente ignoro la naturaleza del nuevo medio, mas rico,
interactivo, interconectado e inmediato. Apenas se limito a emular la
representacion tradicional en papel, agregando una complejidad innecesaria para
la creacion de documentacion. Entre los varios formatos que tomaron esta
vision, encontrariamos como representante principal a [TeX](https://es.wikipedia.org/wiki/tex) y en
menor medida a [roff](https://es.wikipedia.org/wiki/Roff), junto a sus
respectivas variaciones como LaTeX, Texinfo, nroff o groff. Sin embargo, el
formato que se termino por imponerse fue HTML (un derivado del lenguaje de marcas
extensible [XML](https://es.wikipedia.org/wiki/xml))

Lamentablemente en el caso de TeX al estar ideado paro *hacer libros* complicaba
el proceso de la escritura, lo que termino por limitarlo casi en exclusiva al
ambito academico. Por su parte HTML contaba con un engorroso
sistema de marcas de apertura, cierre, estructura del documento, enfasis e
instrucciones para la representacion visual, que puesto en manos humanas
eran casi imposible de escribir, muy engorroso y complicado,
situacion que desencadeno en la imposibilidad de formalizarlo y adaptarlo para la
creacion de documentacion academica y literal

Ante este sin sentido de formatos, aparecieron nuevas visiones centradas en la
sencilles, abandonando la idea del papel como fin ultimo. En esta ocacion,
el proposito fue una escritura sencilla, entendible por humanos sin necesidad de un
programa especial y exportable a los "viejos" formatos.

La transicion a este pensamiento apenas empieza, habiendo una vasta variedad de
contendientes, todos incompletos y mediocres, limitados en su concepcion a ser
simples facilitadores para los formatos HTML y Latex.

Dentro de algunos exponentes de esta vision denominada *Lenguajes de marcado
ligejo* tenemos a
[org-mode](https://es.wikipedia.org/wiki/org-mode),
[wikitext](https://es.wikipedia.org/wiki/wikitext),
[ReStructured Text](https://es.wikipedia.org/wiki/ReStructuredText) y
[Markdown](https://es.wikipedia.org/wiki/markdown)

La incognita ahora es: alguno de estos lograra suplantar a sus predecesores?
veremos una nueva concepcion de la documentacion? apareceran otros contendientes?

## Que es markdown?

Un lenguaje de marcas ligero que no cuenta con una estandarizacion ni en
sintaxis, ni en implementacion. Su sintaxis de resaltado es ambigua y pobre, pero
intenta cubrir su mediocridad insertando directamente marcas XML en el
texto "humanamente legible"... diluyendo asi su proposito, pero convirtiendolo en
un "buen" facilitador para la escritura de HTML

### Syntaxis
### Encabezados

``` markdown
# Encabezado principal
## Segundo nivel
### 3er. nivel
algo de texto
### 3er. nivel
mas texto

# Otro encabezado principal
```

Toda linea que inicia con uno o varios `#` seguido por al menos un espacio en
blanco, es un encabezado.

El texto (en la misma linea) donde esta el o los `#` sera el titulo del encabezado.

El nivel del encabezado depende del numero de `#` al inicio de la linea, es
decir

- `#` == `h1`
- `##` == `h2`
- `###` == `h3`
- `####` == `h4`
- `#####` == `h5`

A que encabezado pertenece el texto? al primero que aparezca por encima de
el

### Listas

Disponemos de dos tipos de listas, ordenadas (numeradas) y no
ordenadas, para las primeras colocamos un numero (el que sea) seguido de un
punto y comenzamos a escribir

listas ordenadas

``` markdown
1. elemento uno
2. elemento dos
3. elemento tres
```

para las segundas (listas no ordenadas) simplemente un guion al inicio

``` markdown
- elemento uno
- elemento dos
- elemento tres
```

markdown no permite que un elemento tenga mas de un parrafo, por ejemplo

``` markdown
1. primer elemento de la lista
2. segundo elemento de la lista
3. tercer elemento de la lista
   con una linea adicional

   este texto, a pesar de estar indentado, no forma parte
   del tercer elemento, es un parrafo independiente

igual de independiente que este
```

para hacer esto tendriamos que recurrrir a a html en si, convirtiendo lo
anterior en

``` markdown
<ul>
    <li><p>primer elemento de la lista</p></li>
    <li><p>segundo elemento de la lista</p></li>
    <li><p>tercer elemento de la lista con una linea adicional</p>
        <p>la linea adicional</p></li>
</ul>
```

### Citas

``` markdown
> esto es una cita

> esto tambien
> es una
> cita
```

### Resaltado

```
**bold**          ==> <b>bold</b>
__bold__          ==> <b>bold</b>
*italic*          ==> <i>italic</i>
_italic_          ==> <i>italic</i>
***bold&italic*** ==> <b><i>bold&italic</i></b>
___bold&italic___ ==> <b><i>bold&italic</i></b>
`code`            ==> <code>code</code>
~~strike~~        ==> <s>strike</s>
```

### Enlaces

cualquier texto que cumpla con la regexp `(https?|ftp|file)://\S+` (o algo asi) se
convierte en un enlace

tambien se puede colocar un texto alternativo como "fachada" del enlace, con la sintaxis

``` markdown
[texto-alternativo](enlace)
```

### imagenes

```
![texto-alternativo](enlace)
```

### Bloques de Codigo

hay dos sintaxis para esto, primero envolver una region con tres comillas
invertidas ``` contenidas en una linea propia, sin espacios al inicio. Colocar el nombre del lenguaje en el que se supone esta escrito
el codigo es opcional

<pre><code>
``` lenguaje
mi codigo
+ codigo
y + codigo
```
</code></pre>

tiene el mismo efecto, dejar cuatro espacios en blanco al inicio de
cada linea, separando el texto con una linea en blanco al inicio y al final

```
texto estandar

    esto es codigo
    y esto tambien es codigo
    y tambien esto

+ texto estandar
```

## enlaces

- https://es.wikipedia.org/wiki/Markdown
- http://joedicastro.com/pages/markdown.html
- http://joedicastro.com/markdown-la-mejor-opcion-para-crear-contenidos-web.html
- http://joedicastro.com/comparativa-de-lenguajes-de-marcado-ligero.html
- https://nasciiboy.github.io/emacs/org-mode/
