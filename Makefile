GPP= g++ -Wall -std=c++11 #a ajouter pour fonction to_string(int)

gsl_libs = -lgsl -lgslcblas -lm

root= 'root-config --libs'

#ajouter les nom des fichier au fur et a mesure

all: recuit_simule

clean: rm -f -v *.o



# Compilation :
PM.o : PM.cpp 
	${GPP}  -c -o PM.o PM.cpp
graph.o: graph.cpp
	${GPP}  -c -o graph.o graph.cpp

2OPT.o: 2OPT.cpp 
	${GPP} -c -o 2OPT.o 2OPT.cpp

recuit_simule.o: recuit_simule.cpp 
	${GPP} -c -o recuit_simule.o recuit_simule.cpp

# Edition des liens
recuit_simule: recuit_simule.o PM.o 2OPT.o graph.o
	${GPP} -o recuit_simule recuit_simule.o PM.o 2OPT.o ${root}
