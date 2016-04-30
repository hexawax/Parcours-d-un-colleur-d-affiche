#include <iostream>
#include <string>
#include "PM.h"
using namespace std;


void init_nom(vecteur &genet) 
{
	for(int j=0;j<n;j++)
	{
		genet.nom=j;//crée le nom
	}
}


void calcul_chemin (int n,string nom){

	double dist;
	
	for(int i=0;i<n;i++){
		dist=0;
		
			for(int j=0;j<n;j++){
				dist=dist+distance(P[i][1],P[i][2],P[i+1][1],P[i+1][2]);	//distance totale du parcours et nom (numéro donné)
				int (genet[i].nom[j]);
			}
		genet[i]=dist;
	}
}

bool tri (structure x,structure y){
return (x.genet<y.genet)//retourne vrai si le premier chemin est plus court que le deuxième
}


