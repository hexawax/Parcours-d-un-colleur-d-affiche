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

%.o : %.cpp %.h Makefile
	${GPP}  -Wall -c -o $@ $<


%.o : %.cpp Makefile
	${GPP}  -Wall -c -o $@ $< `../root-config --libs --cflags`

# Edition des liens

recuit_simule: recuit_simule.o
	${GPP} -o $@ $^ ${gsl_libs}
