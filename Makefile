GPP= g++ -Wall -std=c++11 #a ajouter pour fonction to_string(int)

gsl_libs = -lgsl -lgslcblas -lm

#ajouter les nom des fichier au fur et a mesure

all: PM

clean: rm -f -v *.o


# Compilation :
PM.o : PM.cpp Makefile
	${GPP}  -c -o PM.o PM.cpp

# Edition des liens
PM : PM.o
	${GPP} -o test PM.o