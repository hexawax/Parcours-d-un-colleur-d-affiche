###########################################################################################
#######Makefile pour le projet du colleur d'affiches#######################################
###########################################################################################


GPP= g++ -Wall -std=c++11 #a ajouter pour fonction to_string(int)

gsl_libs = -lgsl -lgslcblas -lm

comp_root= `root-config --incdir`

link_root= `root-config --libs`

#ajouter les nom des fichier au fur et a mesure

%.o:%.cpp
	${GPP} -c -o $@ -I `root-config --incdir`  $<

all: recuit_simule #DLexp

clean: 
	rm -f -v *.o

# Compilation :
PM.o : PM.cpp 
	${GPP} -c -o PM.o PM.cpp
recuit_simule.o: recuit_simule.cpp 
	${GPP} -c -o recuit_simule.o recuit_simule.cpp
#MC.o: MC.cpp
	#${GPP} -c -o MC.o MC.cpp

# Edition des liens
recuit_simule: recuit_simule.o PM.o
	${GPP} -o Voyageur recuit_simule.o PM.o # `root-config --libs`
#DLexp:DLexp.o
	#${GPP} -o DLexp DLexp.o  `root-config --libs`