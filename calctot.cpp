//sert à calculer la distance parcouru pour chaque chemin
#include <iostream>
#include "PM.h"
using namespace std;

 double calcul (double dist,int m,int n)//m est le point de départ voulut et n le point de fin
{
double dist=0;
do {cout<<"donner valeur de départ: "<<endl;
	cin>>m;}
while{m>n};

	for (int i=m; i<n; i++){		
		/*cout<<"la distance entre le point "<<i<<" et le point "<<i+1<<" est de: "<<distance(P[i][1],P[i][2],P[i+1][1],P[i+1][2])<<endl;*/ //si besoin de savoir distance entre chaque points
		dist=dist+distance(P[i][1],P[i][2],P[i+1][1],P[i+1][2])
	}
cout<<"la distance totale est de: "<<dist<<endl;

}





















































