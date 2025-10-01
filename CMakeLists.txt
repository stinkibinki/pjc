cmake_minimum_required(VERSION 4.0)
project(code C)

set(CMAKE_C_STANDARD 99)

add_executable(code
        main.c
        src/01_izpis.c
        src/01_fibo.c
        src/02_pretvorba.c
        src/02_obratno.c
        src/00_zapiski.c
        src/03_stevke.c
        src/03_igra.c
        src/04_bitki.c
        src/04_wc.c
        src/05_tocke.c
        src/05_histogram.c
        src/06_sklad.c
        src/06_testSklada.c
        src/07_imenik.c
        src/08_seznam.c)
