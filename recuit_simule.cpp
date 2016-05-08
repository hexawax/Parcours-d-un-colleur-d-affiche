// Optimisation de la methode avec le recuit simulé
#include<iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
using namespace std;
/*
                        A FAIRE
-Mehtode ordre

-UNE BONNE GENERATION DE h
 
                        A FINIR
- mthode lgc longeur du circuit
-methiode recuit
 
                        UTILE ?
 -methode unsurT pas tres utilie a voir
 
*/

double proba0_1()//loi de proba entre 1 et 0 fonctionnelle
{
  return (double)rand()%(RAND_MAX); //valeur aleatoire du nombre entre 0 et 1
}


double unsurT(double T) //fonction T(n)=1/K or k est parametres de la fonction
{
    double k;
    return k=1/T;
}

void Matricedistance(int n,    double * Matricedistance=new double [n][n], int P[][])//ne pas oublier de verifier la correspondance du P & CREER la matrice distance *
{
    //double * Matricedistance=new double [n][n]; //a voir si il y aen a vraiment besoin normalement non
    
    for (int i=0; i<n;i++)
    {
        for (int j=0; j<n; j++){
            Matricedistance [i][j]=distance(P[i][j]); //ajouter la methode de distance
        }
    }
}

void lgc(ordre, double* lg1,int n)//ajouter un moyen de lire le ordre
{
    lg1=0;
    for (int i=0; i<n; i++)//verifier les initialisation en 0 et n
    {
        ordre //lecture de l'ordre et affectation de l'ordre a chaque point dans la matrice.
        lg1+=Matricedistance[][];
    }
}



void recuit(//acompleter
)
{
    int iter=0;
    double unsurT=0;
    double* lgc1,lcg2;
    //definir de quoi contenir un ordre 1 et un ordre 2
    //permuter ordre
    //faire lgc1 sur le premier ordre
    double* palier=1;//pour que palier soit plus qurand que iter des le debut
    double proba;
    do{
        unsurT++;
        palier=exp(unsurT*h) //ne pas oublier la generation de h
       do {
        //ordre 2 permutation de l'ordre 1
        //lgc2
        if (lgc2<=lgc1) //ordre1=ordre2; lgc1=lgc2;
            else{proba=exp((lgc1-lcg2)*unsurT);
                
                if(proba0_1()<proba){//ordre1=ordre2; lgc1=lgc2;
                                    }
                }//end else
        inter++;
           }while (iter<=palier)
        }while(//condition arret a specifier
       )
       
}


