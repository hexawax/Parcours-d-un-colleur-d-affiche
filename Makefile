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
	${GPP} -c -I ${comp_root} -o PM.o PM.cpp ${link_root}

recuit_simule.o: recuit_simule.cpp 
	${GPP} -c -I ${comp_root} -o recuit_simule.o recuit_simule.cpp ${link_root}


%.o : %.cpp Makefile
	${GPP}  -Wall -c -I ${comp_root} -o $@ $< ${link_root}

# Edition des liens
recuit_simule: recuit_simule.o PM.o
	${GPP} -o recuit_simule recuit_simule.o PM.o ${link_root}

