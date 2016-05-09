// Optimisation de la methode avec le recuit simulé
#include<iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
#include <vector> //NE PAS OUBLIER PARTOUT !!!!!!!!!!
using namespace std;
/*
                         NOTES
 -penser au "const" et "&" si possible
 - fautil declerer matrice dand lgc ????
 
                        A FAIRE
                                    -Mehtode ordre DONE A VERIFIER
                                    -creer la matrice distance DONE IN THE PM.CPP

-→→➤☛☞➠➲➫➫➜➜UNE BONNE GENERATION DE h
 
 
                        A FINIR
- mthode lgc longeur du circuit
-methiode recuit
-ATTENTION copier coller
-distance les declaration sont peut etre fausse
-verifier lgc
-verifier le SI et else dans le recuit
                        UTILE ?
 -methode unsurT pas tres utilie a voir
 -utiliser memset ?
 -matrice distance pas utilise donc suppression
*/

double proba0_1()//loi de proba entre 1 et 0 fonctionnelle
{
  return ((double)rand())/(RAND_MAX); //valeur aleatoire du nombre entre 0 et 1
}


double unsurT(double T) //fonction T(n)=1/K or k est parametres de la fonction
{
    return 1/T;
}

double distance (const int P[][2],int i, int j)//distance entre 2 point d'un tableu double de points i = P1 & j =P2
{
    return sqrt( (P[j][0]-P[i][0]) * (P[j][0]-P[i][0])
                + (P[j][1]-P[i][1]) * (P[j][1]-P[i][1]) );
}
                
/*
void Matricedistance(int n, const double *Matricedistance [], const int* P[])//ne pas oublier de verifier la correspondance du P & CREER la matrice distance *
{
    //double * Matricedistance=new double [n][n]; //a voir si il y aen a vraiment besoin normalement non
    
    for (int i=0; i<n;i++)
    {
        for (int j=0; j<n; j++){
            Matricedistance [i][j]=distance(P, i, j); //ajouter la methode de distance
        }
    }
}

*/


void lgc(const vector <int> ordre, double& lg1,const int n)
{
    lg1=0; int x,y;
    for (int i=0; i<n-1; i++) //plus petit que n
                              //refaire les verifier la boucle
    {
        
        lg1+=distance(P,ordre[i],ordre[i+1]);
    }                                                   ////////////////////////////////////////
    lg1+=distance(P,ordre[0],ordre[n-1]); //ajout du dernier trait pour fermer la boucle !!!!!!!!!
}                                                       ///////////////////////////////////////
                



vector<int> randomsansrep (vector<int> value,const int MAX) //COPIER COLLER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{                                                                 //MIN toujours 1
    srand(time(NULL));
    for (int i=0;i<MAX;i++)
    {
        bool check; //variable to check or number is already used
        int n; //variable to store the number in
        do
        {
            n=rand()%(MAX-1)+MAX;
            //check or number is already used:
            check=true;
            for (int j=0;j<i;j++)
                if (n == value[j]) //if number is already used
                {
                    check=false; //set check to false
                    break; //no need to check the other elements of value[]
                }
        } while (!check); //loop until new, unique number is found
        value[i]=n; //store the generated number in the array
    }
    return value;
}


void recuit(//a completer
int n, double h)
{
    int iter=0;
    double unsurT=0;
    double lgc1;
    double lgc2;
    vector <int> ordre (n);
    ordre=randomsansrep(ordre,n);
    vector <int> ordre2(n);
    lgc(ordre, lgc1,n);
    double palier=1;//pour que palier soit plus qurand que iter des le debut
    double proba;
    
    
    do{
        unsurT++;
        palier=exp(unsurT*h); //ne pas oublier la generation de h
       do {
           ordre2=randomsansrep(ordre,n);
           lgc(ordre2, lgc2,n);
           
           if (lgc2<=lgc1)
               {
               ordre=ordre2;
               lgc1=lgc2;
                }
           else{proba=exp((lgc1-lgc2)*unsurT);
                
                    if(proba0_1()<proba)
                    {
                        ordre=ordre2;
                        lgc1=lgc2;
                    }
                }//end else
        iter++;
       }while (iter<=palier);
        }while(unsurT>10000//condition arret a specifier
               );
}


