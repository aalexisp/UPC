OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o Idioma.o Tabla_de_frecuencias.o TreeCode.o Cjt_idiomas.o
	g++ -o program.exe *.o
program.o: program.cc
	g++ -c program.cc $(OPCIONS)
Idioma.o: Idioma.cc
	g++ -c Idioma.cc $(OPCIONS)
Tabla_de_frecuencias.o: Tabla_de_frecuencias.cc
	g++ -c Tabla_de_frecuencias.cc $(OPCIONS)
TreeCode.o: TreeCode.cc
	g++ -c TreeCode.cc $(OPCIONS)
Cjt_idiomas.o: Cjt_idiomas.cc
	g++ -c Cjt_idiomas.cc $(OPCIONS)
practica.tar: practica.tar Idioma.hh Cjt_idiomas.hh Tabla_de_frecuencias.hh TreeCode.hh Idioma.cc Cjt_idiomas.cc TreeCode.cc Tabla_de_frecuencias.cc program.cc Makefile html.zip jp_alexis.peralta.zip
	tar -cvf practica.tar Idioma.hh Cjt_idiomas.hh Tabla_de_frecuencias.hh TreeCode.hh Idioma.cc Cjt_idiomas.cc TreeCode.cc Tabla_de_frecuencias.cc program.cc Makefile html.zip jp_alexis.peralta.zip
Clean:
	rm -f *.o
UltraClean:
	rm -f *.o
	rm -f *.exe
SuperClean:
	rm -f *.o
	rm -f *.exe
	rm -f *.tar
