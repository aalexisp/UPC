OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: main.o idioma.o tabla_de_frecuencias.o TreeCode.o cjt_idiomas.o
	g++ -o program.exe main.o idioma.o tabla_de_frecuencias.o TreeCode.o cjt_idiomas.o $(OPCIONS)
	rm *.o
main.o: main.cc
	g++ -c main.cc $(OPCIONS)
idioma.o: idioma.cc
	g++ -c idioma.cc $(OPCIONS)
tabla_de_frecuencias.o: tabla_de_frecuencias.cc
	g++ -c tabla_de_frecuencias.cc $(OPCIONS)
TreeCode.o: TreeCode.cc
	g++ -c TreeCode.cc $(OPCIONS)
cjt_idiomas.o: cjt_idiomas.cc
	g++ -c cjt_idiomas.cc $(OPCIONS)
Clean:
	rm -f *.o
	rm *.exe
