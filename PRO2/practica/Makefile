OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: program.o idioma.o tabla_de_frecuencias.o TreeCode.o cjt_idiomas.o
	g++ -o program.exe *.o
program.o: program.cc
	g++ -c program.cc $(OPCIONS)
idioma.o: idioma.cc
	g++ -c idioma.cc $(OPCIONS)
tabla_de_frecuencias.o: tabla_de_frecuencias.cc
	g++ -c tabla_de_frecuencias.cc $(OPCIONS)
TreeCode.o: TreeCode.cc
	g++ -c TreeCode.cc $(OPCIONS)
cjt_idiomas.o: cjt_idiomas.cc
	g++ -c cjt_idiomas.cc $(OPCIONS)
practica.tar: practica.tar idioma.hh cjt_idiomas.hh tabla_de_frecuencias.hh TreeCode.hh idioma.cc cjt_idiomas.cc TreeCode.cc tabla_de_frecuencias.cc program.cc Makefile
	tar -cvf practica.tar idioma.hh cjt_idiomas.hh tabla_de_frecuencias.hh TreeCode.hh idioma.cc cjt_idiomas.cc TreeCode.cc tabla_de_frecuencias.cc program.cc Makefile
Clean:
	rm -f *.o
	rm -f *.exe
