###########################################################################################
#######Makefile pour le projet du colleur d'affiches#######################################
###########################################################################################


GPP= g++ -Wall -std=c++11 #a ajouter pour fonction to_string(int)

gsl_libs = -lgsl -lgslcblas -lm

comp_root= `root-config --incdir`

link_root= `root-config --libs`

#ajouter les nom des fichier au fur et a mesure

all: recuit_simule 2OPT

clean: 
	rm -f -v *.o

# Compilation :
PM.o : PM.cpp 
	${GPP} -c -o PM.o PM.cpp
recuit_simule.o: recuit_simule.cpp 
	${GPP} -c -o recuit_simule.o recuit_simule.cpp
#2OPT: 2OPT.cpp
#	#${GPP} -c -o 2OPT.o 2OPT.cpp

%.o : %.cpp Makefile
	${GPP}  —v Wall -c  -o $@ $<

# Edition des liens
recuit_simule: recuit_simule.o PM.o #2OPT.o
	${GPP} -o -v Voyageur_optimisé recuit_simule.o PM.o

