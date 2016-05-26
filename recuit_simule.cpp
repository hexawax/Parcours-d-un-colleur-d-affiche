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
-un faffhichage du resultat
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


void lgc(const vector <int> ordre, double& lg1,const int n,
						 const int P[][2] )
{
    lg1=0;
    for (int i=0; i<n-1; i++) //plus petit que n
                              //refaire les verifier la boucle
    {
        
        lg1+=distance(P,ordre[i],ordre[i+1]);
    }                                                   ////////////////////////////////////////
    lg1+=distance(P,ordre[0],ordre[n-1]); //ajout du dernier trait pour fermer la boucle !!!!!!!!!
}                                                       ///////////////////////////////////////
                



vector<int> randomsansrep (const int MAX) //COPIER COLLER !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{                                                                 //MIN toujours 1
    vector <int> value(MAX);
    for (int i=0;i<MAX;i++)
    {
        bool check; //variable to check or number is already used
        int n; //variable to store the number in
        do
        {
            n=rand()%MAX;
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

vector <int> intervers (vector<int> ordre, const int n)
{
	vector <int> ordre2 (n);
	int all2=0;
	int all1=0;
	do{all1=rand()%n;
	   all2=rand()%n;}while(all1==all2);
	ordre2=ordre;
	ordre2[all1]=ordre[all2];
	ordre2[all2]=ordre[all1];	
return ordre2;
}

double baissetemp(double T)
{return log(T);}



void recuit(//a completer
int n, double k, const int P[][2])
{
    srand(time(0));
    int iter=0;
    double T=40;
    double lgc1;
    double lgc2;
    int B=0;
    vector <int> ordre (n);
    ordre=randomsansrep(n);
   vector <int> ordre2(n);
    lgc(ordre, lgc1,n,P);
    double proba;//pour que palier soit plus qurand que iter des le debut
    do{
       do {
           ordre2=intervers(ordre,n);
           lgc(ordre2, lgc2,n,P);
            bool change=false;
            if (lgc2<lgc1) change=true;
            if(lgc1<lgc2){ 
                   proba=exp(-(lgc2-lgc1)/(k*T));//kT doit etre de l'ordre du delta lgc
                   if(proba0_1()<proba) change=true;
            }
            if (change)
               {
               ordre=ordre2;
               lgc1=lgc2;
                B=0;
               }
            else B++;

        iter++;
        cout << lgc1 << " ";
       }while (B<3);
       cout << " fin palier T=" << T << endl; 
      B=0; T=baissetemp(T);
    }while(T>0.1);

cout<<endl<<"resultat : ";
for (int i=0; i<n; i++) cout << ordre[i] << "->"; cout << endl;
cout<<"longeur : "<<lgc1<<endl;
}


