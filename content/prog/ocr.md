+++
title      = "OCR"
tags       = [ "howto" ]
categories = [ "prog" ]
date       = 2017-11-09T17:10:40-06:00
+++

![](/img/padesoor.png)

sucede que tenia un libro que aprecio muchisimo, pero mucho mucho mucho, aunque
no lo habia leido y lo escaneeehee para convertirlo en otra cobaya del proyecto
morg, y para leerlo... y por que supongo que lo voy a necesitar con inmediates y
de forma reiterativa en el futuro.

asi que en un acto de benevolencia, pereza y mayor exactitud (o no), paso por mi
mente darle otra oportunidad al ocr y ver si con el paso del tiempo la cosa habia
ido a mejor o en definitiva hay que esperar la aparicion de inteligencias
artificiales reales, para la titanica tarea de digitalizar todo el conocimento

pero bueno, el asunto tiene un grado superior de complejidad por que el scan (en
pdf) contiene dos paginas por pagina, je, je, y al generar las imagenes (para
que las tome el ocr) estas tienen una orientacion equivoca

ademas y aunque el ocr es capaz de reconocer tal aberracion y generar un texto
correctamente organizado, preferi cortar cada imagen y luego mandarsela al
ocr para disminuirle complejidad

asi pues, pese a mi ignorancia con bash aqui esta el cutre-script
resultado... creo que hubiera tardado menos programando directamente en Go...

``` sh
#! /bin/bash

# esto "corta" el pdf en imagenes png, pato es el sufijo del resultado
pdfimages -png "$1" pato

# cargo las imagenes en una variable para iterar sobre ellas
patoPng=$(ls -1 *.png)

# una varible para poner nombres distintos
declare -i pata=0

for quak in $patoPng
do
    # rotar imagen a posicion apropiada
    convert -rotate -90 $quak $quak
    # cortar primer mitad de la imagen
    # espacio extra por que la imagen esta muy movida [finXfinY+inicioX+inicioY]
    convert -crop 1517x1965+0+0 $quak $(printf "pata-%04i.png" $pata)
    pata+=1
    # cortar segunda mitad de la imagen
    convert -crop 2939x1965+1469+0 $quak $(printf "pata-%04i.png" $pata)
done

# cargo las imagenes "recortadas"
pataPng=$(ls -1 pata-*.png)

# restablesco la variable de los nombres distintos
pata=0

for quak in $pataPng
do
    # el ocr de cada imagen
    tesseract $quak $(printf "patax-%04i" $pata) -l spa+eng
    pata+=1
done

# concatenar todos los textos a un fichero unico
cat patax* > ocr.txt
```

para llamar al script copiar y pasar a un fichero que se llame `cutre.sh` y
llamar con

    $ ./cutre.sh mi.pdf

obviamente hay que cambiar lo de la rotacion (si es que se necesita) y quitar lo
de los cortes, todo segun sea el caso

el ocr (`tesseract`) de linea de comandos esta en los repos, en freidora lo optienen con

    dnf -y install tesseract tesseract-langpack-spa

necesario instalar los paquetes del lenguaje que se va a digitalizar (el ingles
venia includo, por que todo mundo habla ingles...). El programa `pdfimages` no
me acuerdo de que paquete forma parte, investigar por vuestra cuenta! `convert`
creo que es parte del paquete `imagemagic`

y bueno... el ocr me sigue pareciendo un truño, si, es verdad que el texto
puesto esta bastante jodido, pero el resultado tiene tantos defectos, que me
sale mas a cuenta mecanografiarlo artesanalmente, ademas tenia ganas de
mecanografiar, es algo que me desestresa, tambien me ayuda a sertirme
"productivo" y a enfocarme (o distraerme). Ultimamente los pdf que encuentro
traen oceerres buenos y le quita la emocion, para esos casos basta con

    pdftotext mi-pdf miSalida.txt

`pdftotext` tambien tiene una opcion `-layout` que puede ser bastante util (a veces)

happy typing!
