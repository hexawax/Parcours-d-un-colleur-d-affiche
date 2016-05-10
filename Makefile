GPP= g++ -Wall -std=c++11 #a ajouter pour fonction to_string(int)

gsl_libs = -lgsl -lgslcblas -lm

#ajouter les nom des fichier au fur et a mesure

all: recuit_simule root

clean: rm -f -v *.o



# Compilation :
root.o : root.cpp
	${GPP}  -c -o root.o root.cpp

PM.o : PM.cpp 
	${GPP}  -c -o PM.o PM.cpp

recuit_simule.o: recuit_simule.cpp 
	${GPP} -c -o recuit_simule.o recuit_simule.cpp
%.o:%.cpp 
	${GPP} -c -o $@ -I `root-config --incdir`  $<
# Edition des liens
recuit_simule: recuit_simule.o PM.o
	${GPP} -o recuit_simule recuit_simule.o PM.o

root:root.o
	${GPP} -o root root.o  `root-config --libs`
	
:.o
	${GPP} -o  .o  `root-config --libs`

