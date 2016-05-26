###########################################################################################
#######Makefile pour le projet du colleur d'affiches#######################################
###########################################################################################


GPP= g++ -Wall -std=c++11 #a ajouter pour fonction to_string(int)

gsl_libs = -lgsl -lgslcblas -lm

root= '../root-config --libs --cflags'

#ajouter les nom des fichier au fur et a mesure

all: recuit_simule 2OPT

clean: 
	rm -f -v *.o



# Compilation :
PM.o : PM.cpp 
	${GPP} -I/usr/include/root -c -o PM.o PM.cpp

recuit_simule.o: recuit_simule.cpp 
	${GPP} -I/usr/include/root -c -o recuit_simule.o recuit_simule.cpp


%.o : %.cpp Makefile
	${GPP}  -Wall -c -o $@ $< `../root-config --libs --cflags`

# Edition des liens
recuit_simule: recuit_simule.o PM.o
	${GPP} -L/usr/include/root -o recuit_simule recuit_simule.o PM.o
