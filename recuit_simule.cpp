/////////////////////////////////////////////////////////////////////////////////////////////////// 
////////////////////////Optimisation de la methode avec le recuit simulé///////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
#include <vector> //NE PAS OUBLIER PARTOUT !!!!!!!!!!
using namespace std;


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
                





vector<int> randomsansrep (const int MAX) //fonction pour créer des points sans répétitions
{                                 //MIN toujours 1
    vector <int> value(MAX);
    for (int i=0;i<MAX;i++)
    {
        bool check; //variable pour vérifier que le nombre n'est pas déja utiliser
        int n;
        do
        {
            n=rand()%MAX;
            // vérifier que le nombre n'est pas déja utiliser
            check=true;
            for (int j=0;j<i;j++)
                if (n == value[j]) //si déja utilisé
                {
                    check=false; //alors il est déclaré comme false
                    break; //donc pas besoin de vérifier les autres valeurs
                }
        } while (!check); //on boucle jusqu'a trouver un nombre unique
        value[i]=n; //stocker le nombre générer dans le tableau
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



double baissetemp(double T)//méthode qui doit être appeler pour baisser la temperature lors du recuit
{return log(T);}





void recuit(int n, double k, const int P[][2]) //méthode pour le calcul du recuit
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





void methodecombine (int n, double k, const int P[][2]          //méthode alliant le recuit-simule et la méthode 2-opt
)
{   cout<<"RECUIT :"<<endl;
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
    vector <int> recuit (n);
    recuit=ordre;
    cout<<endl<<"resultat : ";
    for (int i=0; i<n; i++) cout << ordre[i] << "->"; cout << endl;
    cout<<"longeur : "<<lgc1<<endl;
    cout<<endl<<endl<<"///////////////////////////////////////////////////"<<endl<<endl;
    ///////////////////////////////////////////////////recuit en haut et 2opt en bas
    cout<<"2OPT :"<<endl;
    double minchange=0;
    double change;
    int save;
    do {
        minchange=0;
        for( int i=0; i<n-2; i++) {
            for(int j=i+2; j<n;j++){
                
                change= (distance (P,ordre[i],ordre[j]) + distance (P,ordre[i+1],ordre[j+1]) - distance (P,ordre[i],ordre [i+1]) -distance (P,ordre[j], ordre[j+1]));
                
                if(minchange > change) {
                    minchange=change;
                    save=ordre[j];
                    ordre[j]=ordre[i+1];
                    ordre[i+1]=save;
                    lgc(ordre, lgc1, n,P);
                    for (int i=0; i<n; i++) cout << ordre[i] << "->"; cout << endl;
                    cout<<"changement effectue est de longeur : "<<lgc1<<endl;
                }
            }
        }
        
    }while (minchange<0);
    
    lgc(recuit,lgc2,n,P);
    if (lgc1>lgc2) {
        ordre=recuit;
    }
    
    cout<<endl<<endl<<"RESULTAT FINAL : ";
    for (int i=0; i<n; i++) cout << ordre[i] << "->"; cout << endl;
    cout<<"longeur : "<<lgc1<<endl;
}

