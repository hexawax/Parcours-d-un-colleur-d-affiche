###########################################################################################
#######Makefile pour le projet du colleur d'affiches#######################################
###########################################################################################

GPP= g++ -Wall -std=c++11 #a ajouter pour fonction to_string(int)

all: recuit_simule

clean: 
	rm -f -v *.o

# Compilation :


PM.o : PM.cpp 
	${GPP} -c -o PM.o PM.cpp

recuit_simule.o: recuit_simule.cpp 
	${GPP} -c -o recuit_simule.o recuit_simule.cpp

# Edition des liens

recuit_simule: recuit_simule.o PM.o
	${GPP} -o Voyageur recuit_simule.o PM.o