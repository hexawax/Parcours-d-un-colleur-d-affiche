GPP= g++ -Wall -std=c++11 #a ajouter pour fonction to_string(int)

gsl_libs = -lgsl -lgslcblas -lm

#ajouter les nom des fichier au fur et a mesure

all: PM recuit_simule

clean: rm -f -v *.o



# Compilation :
PM.o : PM.cpp Makefile
	${GPP}  -c -o PM.o PM.cpp

recuit_simule.o: recuit_simule.cpp Makefile
	${GPP} -c -o recuit_simule.o recuit_simule.cpp

# Edition des liens
PM : PM.o
	${GPP} -o test PM.o
recuit_simule: recuit_simule.o
	${GPP} -o recuit_simule recuit_simule.o