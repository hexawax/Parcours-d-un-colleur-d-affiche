
#include <iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
#include <vector>
//#include "graph.h"
#include "recuit.h"
#include "2OPT.h"

using namespace std;

//voir kes limites de l'algorytimle


double factorielle(int n)//fct factoriel pour calculer le nb de possibilité
{
  return (n ==1||n== 0) ? 1 :factorielle(n - 1) * n;
}

void PauseFor( double seconds) //fonction pour faire une pausen pendant X seconde
{
    clock_t temp;                               ///
    temp = clock () + seconds * CLOCKS_PER_SEC ;/// ATTENTION COPIER COLLER
    while (clock() < temp) {}                   ///

}

double bazinga() //fct de point aleatoire
{int signe =rand()%(1); //avoir un signe aleatoirement
  if (signe==0){
  return rand()%(100); //valur aleatoire du nombre entre 0 et 100
}
else return -rand()%(100);//valeur aleatoire du nombre
}

void anagramme(vector <int> ordre, const int n,const int P[][2])
{
    vector <int> save; double lgc2 ;double lgc1=10000000000;//grand nombre pour qu'il soit toujours desous la permiere doistance de la boucle
    for (int k=0; k<n; k++)
    { int i=1; int tempo=0;
        while ((n-i)>0) {
            ordre[n-i]=tempo;
            ordre[n-i-1]=ordre[n-1];
            ordre[n-i-1]=tempo;
            i++;
            lgc(ordre,lgc2,n,P);

	    if(lgc2<lgc2){
            save=ordre;
                lgc1=lgc2;}

        }
    }
}





void intro (){
  cout<<"___    ____  ______   ____    ____  ___       _______  _______  __    __  .______    "<<endl;
  cout<<"\\   \\  /   / /  __  \\  \\   \\  /   / /   \\     /  _____||   ____||  |  |  | |   _  \\     "<<endl;
  cout<<" \\   \\/   / |  |  |  |  \\   \\/   / /  ^  \\   |  |  __  |  |__   |  |  |  | |  |_)  |"    <<endl;
  cout<<"  \\      /  |  |  |  |   \\_    _/ /  /_\\  \\  |  | |_ | |   __|  |  |  |  | |      /     "<<endl;
  cout<<"   \\    /   |  `--'  |     |  |  /  _____  \\ |  |__| | |  |____ |  `--'  | |  |\\  \\--."<<endl;
  cout<<"    \\__/     \\______/      |__| /__/     \\__\\ \\______| |_______| \\______/  | _| `.___| "<<endl;
  cout<<"                                                                                            "<<endl;
  cout<<"                               _______   _______                                        "<<endl;
  cout<<"                              |       \\ |   ____|                                      "<<endl;
  cout<<"                              |  .--.  ||  |__                                         "<<endl;
  cout<<"                              |  |  |  ||   __|                                        "<<endl;
  cout<<"                              |  '--'  ||  |____                                       "<<endl;
  cout<<"                              |_______/ |_______|                                      "<<endl;
  cout<<"                                                                                      "<<endl;
  cout<<"  ______   ______   .___  ___. .___  ___.  _______ .______        ______  _______      "<<endl;
  cout<<" /      | /  __  \\  |   \\/   | |   \\/   | |   ____||   _  \\      /      ||   ____|      "<<endl;
  cout<<"|  ,----'|  |  |  | |  \\  /  | |  \\  /  | |  |__   |  |_)  |    |  ,----'|  |__       " <<endl;
  cout<<"|  |     |  |  |  | |  |\\/|  | |  |\\/|  | |   __|  |      /     |  |     |   __|       "<<endl;
  cout<<"|  `----.|  `--'  | |  |  |  | |  |  |  | |  |____ |  |\\  \\----.|  `----.|  |____   "   <<endl;
  cout<<" \\______| \\______/  |__|  |__| |__|  |__| |_______|| _| `._____| \\______||_______|   "   <<endl<<endl;

}
///////////////////////////////////////////////////////////==========MAIN===========///////////////////////////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv)
{
intro();
unsigned int seed=time(NULL);

cout << "seed=" << seed << endl;
srand(seed);

    int limitept=50;//limite nb de point
    int n;
    cout<<endl<<"Entrez premierement le nombre de point (limite a "<<limitept<<") : ";
    do{ cin>>n;}while (n>limitept||n<0);
    cout<<endl<<"la position des points est genere aleatoirement entre -100 et 100"<<endl;
    int P[n][2];
    for (int i=0; i<=n; i++)// je sais plus si c'est < ou <= pour faire n case de du tabeau
    {
        P[i][0]=bazinga();
        P[i][1]=bazinga();//positionnement aleatoire des points dans le plan
    }
	int k=2;

    int menu;
    do
    {
        cout<<endl<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
        cout<<"1. Methode classique"<<endl;
        PauseFor(0.1);
        cout<<"2. Methode du recuit simulé"<<endl;
        PauseFor(0.1);
        cout<<"3. Methode 2opt"<<endl;
        PauseFor(0.1);
        cout<<"4. Afficher ROOT"<<endl;
        PauseFor(0.1);
        cout<<"5. Voir les temps"<<endl;
        PauseFor(0.1);
        cout<<"6. Le bouton 6"<<endl;
        PauseFor(0.1);
        cout<<"0. Quitter"<<endl<<endl;
        PauseFor(0.1);
        cout<<"Choix : ";
        cin>>menu;
        cout<<endl;

        switch(menu)                    /// NE PAS OUBLIER LES {} POUR NE PAS REDEFINIR LES CLOCKS T0
        {
            case 0 : break;

            case 1 :                 cout<<"1. Methode classique"<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////
                vector <int> ordre (n);
                anagramme(ordre,n,P);



                ///////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                cout<<endl;
            }
                break;

            case 2 :                 cout<<"2. Methode du recuit simulé"<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////
			recuit(n,k,P);

                ////////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                cout<<endl;
            }
                break;

            case 3 :                 cout<<"3. Methode 2opt"<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////
                //dopt(P,n);

                ////////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                cout<<endl;
            }
                break;

            case 4 :                 cout<<"4. Afficher ROOT"<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////
                //vector <int> ordre (n);
                //anagramme(ordre,n,P);
                //graph (P, ordre);
                ////////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                cout<<endl;
            }
                break;

            case 5 :                 cout<<"5. Voir les temps"<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////

                ////////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                cout<<endl;
            }
                break;

            case 6 :                cout<<"6. Le bouton 6"<<endl<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////

                    for(int i =0; i<n ; i++)//verification des valeurs des points
                    { cout<<"Point "<<i<<endl;
                        cout<<P[i][1]<<endl;
                        cout<<P[i][2]<<endl;
                    }
                ////////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                cout<<endl;
            }
                break;

        }

    }while (menu!=0);





    return 0;
}
