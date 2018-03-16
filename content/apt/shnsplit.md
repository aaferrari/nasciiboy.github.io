+++
tags = ["fonos", "shntool", "flac", "howto"]
title = "Como dividir un album contenido en una sola pista flac"
date = "2016-12-22T09:56:05-06:00"
categories = ["apt"]
+++

En este mundo existen algunos seres extraños con tanto amor (libros, musica,
series, peliculas, porno, ...) que no les cabe en su disco duro y tienen que
compartirlo.

Si el amor viene en forma de **una sola pista flac**, no hagas como yo y la
mandes a la mierda, toda muestra de afecto merece respeto... exepto si proviene
de un degenerado que graba viniles en digital a maxima calidad, si formas parte
de este grupo no mereces tener oidos.

Bueno, podemos optener las pistas individuales siempre y cuando la pista este
acompañada de un fichero con terminacion **.cue**. Primero necesitamos instalar
unas cuantas herramientas, tanto en debian como en freidora son las siguientes

    gestor-de-paquetes install cuetools shntool flac

luego vamos hasta la carpeta que tiene la pista a dividir y ejecutamos el
siguiente comando

    shnsplit -f pista.cue -o flac pista.flac

modificando `pista`, por el nombre especifico de **tu** pista. Luego de ejecutar
esto tendremos pistas independientes con el formato `split-track01.flac`,
`split-track02.flac`, `split-track`...

para colocar los metadatos (titulo, autor) en las pistas invocamos lo siguiente

    cuetag.sh pista.cue split-track*

en ocaciones, este comando puede informarnos que el numero de pistas no
coincide, si se presenta dicha circunstancia revisa si tienes una pista con
nombre `split-track00.flac`, te la cargas y vuelves a intentar.

Pero... y todo esto aun nos deja las pistas con nombre `split-track*`, para eso
no conosco una solucion elegante desde linea de comandos. La solucion que
utilizo es abrir moc (**Music On Console**) copiar todos las nombres de las
pistas (el titulo se muestra a partir de los metadatos) y con Emacs cambiar los
nombres "a mano" en `wdired-change-to-wdired-mode`
