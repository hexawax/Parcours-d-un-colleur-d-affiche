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
 
 
                        A FAIRE
-Mehtode ordre
-creer la matrice distance

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

double distance (const & int P[i][], const & int D[i][])//distance entre 2 point d'un tableu double de points
{
    return sqrt( (D[i][1]-P[i][1]) * (D[i][1]-P[i][1])
                + (D[i][2]-P[i][2]) * (D[i][2]-P[i][2] );
}

void Matricedistance(int n, const double & Matricedistance[n], const int & P[][])//ne pas oublier de verifier la correspondance du P & CREER la matrice distance *
{
    //double * Matricedistance=new double [n][n]; //a voir si il y aen a vraiment besoin normalement non
    
    for (int i=0; i<n;i++)
    {
        for (int j=0; j<n; j++){
            Matricedistance [i][j]=distance(P[i],P[j]); //ajouter la methode de distance
        }
    }
}




void lgc(vector <int> ordre, double* lg1,const & int n)
{
    lg1=0;
    for (int i=0; i<n-1; i++) //plus petit que n
                              //refaire les verifier la boucle
    {
        lg1+=Matricedistance[ordre[i]][ordre[i+1]];
    }
}




vector<int> randomsansrep (vector<int> value,const& int MAX) //COPIER COLLER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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


void recuit(//acompleter
)
{
    int iter=0;
    double unsurT=0;
    double* lgc1,lcg2;
    vector <int> ordre (n)=randomsansrep(ordre,n)
    Vector <int> ordre2(n);
    lgc1=lgc(vector<int>ordre, lgc1,n)
    double* palier=1;//pour que palier soit plus qurand que iter des le debut
    double proba;
    
    
    do{
        unsurT++;
        palier=exp(unsurT*h) //ne pas oublier la generation de h
       do {
           vector <int> ordre2==randomsansrep(ordre,n);
           lgc2=lgc(vector<int>ordre2, lgc2,n);
           
           if (lgc2<=lgc1)
               {
               vector<int>ordre=vector <int> ordre2;
               lgc1=lgc2;
                }
           else{proba=exp((lgc1-lcg2)*unsurT);
                
                    if(proba0_1()<proba)
                    {
                        vector<int>ordre=vector <int> ordre2;
                        lgc1=lgc2;
                    }
                }//end else
        inter++;
           }while (iter<=palier)
        }while(//condition arret a specifier
       )
       
}


