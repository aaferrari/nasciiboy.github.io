+++
draft = true
date = "2016-12-16T20:22:03-06:00"
categories = [ "prog" ]
tags = ["regexp" ]
title = "Performance comparison of regular expression engines"
+++

Hola gente, hace unos meses tome el codigo de **dark100** "Performance
comparison of regular expression engines" (pueden ver el orginal
[aqui](http://sljit.sourceforge.net/regex_perf.html)) para hacer algunas pruebas
a un pequeño [motor regexp](https://github.com/nasciiboy/RecursiveRegexpRaptor)
que programe en mi tiempo *libre?*, bueno ... acabo de actualizar la prueba
([aqui](https://github.com/nasciiboy/RecursiveRegexpRaptor-vs-Benchmarks))

El proceso fue el siguiente

1. Optener el codigo fuente de cada motor (PCRE2, RE2, tre, oniguruma)

2. Compilar cada motor localmente (intel x86-64 celeron 847), es
   decir

   * `./autogen`
   * `./configure` (para PCRE con alguna consideracion especifica)
   * `make`

3. Copiar el código fuente al entorno

4. Intentar con el makefile existente hasta que se logro compilar

5. Modificar levemente el ambiente (no se si compilara en un sistema no GNU)


En realidad no tengo ni idea si este es el proceso adecuado para actualizar el
entorno, pero funciona ¯\_(ツ)_/¯. Si conoces una mejor configuracion o como
optimizar alguna prueba sera bien recibida, siempre y cuando los makefiles se
mantengan KISS (aunque solo compile en x86-64)

Para leer la prueba cómodamente tienes que descagar el fichero `readme.html` del
repositorio y visualizarlo en tu navegador.

por cierto la exprecion:

    "^( )*"

genera un bucle infinito en pcre, tre, oniguruma, re2. En principio esta fue la
motivacion principal para actualizar el codigo de cada prueba... alguna pista?
