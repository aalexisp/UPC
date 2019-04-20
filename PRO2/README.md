# PRO2 FILES

Here you'll find c++ programming files

## Getting Started

The only thing you can check in here is my first project in this university

### Prerequisites

You should install g++ using some specific flags

```
[For MAC] sudo brew install g++
[For linux] $ sudo apt install g++
```

### Installing

Open the terminal and type that commands

An example would be:
```
- sudo brew install g++
- type password (as you're using sudo)
- wait unit the download is complete
(In some OS X your mac will ask you to download XCODE tools which will install you g++ in a moment)
```

## Compiling

```
g++ -c program.cc (this will make a program.o object)
g++ -o program.exe program.cc (or program.o if compiling with other objects)
```

## Running programs

```
./program.exe
./program.exe <sample.inp >sample.out (if want you want a .txt input and a .txt output)

If in linux: kompare sample.out sample.cor (sample.cor is the correct answer of the program) (this will compare the files and tell the diff)
```
