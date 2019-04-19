All: program.exe

program.exe: main.o idioma.o tabla_de_frecuencias.o TreeCode.o cjt_idiomas.o
	g++ -o program.exe main.o idioma.o tabla_de_frecuencias.o TreeCode.o cjt_idiomas.o
main.o: main.cc
	g++ -c main.cc
idioma.o: idioma.cc
	g++ -c idioma.cc
tabla_de_frecuencias.o: tabla_de_frecuencias.cc
	g++ -c tabla_de_frecuencias.cc
TreeCode.o: TreeCode.cc
	g++ -c TreeCode.cc
cjt_idiomas.o: cjt_idiomas.cc
	g++ -c cjt_idiomas.cc
Clean:
	rm -f *.o
UltraClean:
	rm -f program.exe
