///////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////fichier principal du programme//////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
#include <iomanip>
#include <vector>
#include "recuit.h"
#include <algorithm>

using namespace std;



long double factorielle(int n)//fct factoriel pour calculer le nb de possibilité
{
  return (n ==1||n== 0) ? 1 :factorielle(n - 1) * n;
}




void PauseFor( double seconds) //fonction pour faire une pause pendant X seconde
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

						//selection du nombre de points voulut

    int limitept=500;//limite nb de point
    int n;
    cout<<endl<<"Entrez premierement le nombre de point (limite entre 5 et "<<limitept<<") : ";
    do{ cin>>n;}while (n>limitept||n<5);
    cout<<endl<<"la position des points est genere aleatoirement entre -100 et 100"<<endl;
    int P[n][2];
    for (int i=0; i<=n; i++)// je sais plus si c'est < ou <= pour faire n case de du tabeau
    {
        P[i][0]=bazinga();
        P[i][1]=bazinga();//positionnement aleatoire des points dans le plan
    }
    
    long double nombrepos = (factorielle(n-1));
  



   int menu;  //on a ici un switch qui va permettre de choisir la méthode qui l'on souhaite ou voir les points créer
    do
    {
        cout<<endl<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
        cout<<"1. Methode classique"<<endl;
        PauseFor(0.1);
        cout<<"2. Methode du recuit simulé"<<endl;
        PauseFor(0.1);
        cout<<"3. Methode 2opt"<<endl;
        PauseFor(0.2);
        cout<<"4. Methode combiné 2OPT et recuit"<<endl;
        PauseFor(0.2);
        cout<<"5. Afficher le detail des points"<<endl;
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

                //Pour permettre à l'utilisateur de se rendre compte du temps de calcul aproximatif

                cout<<endl<<"La methode classique peut etre trés longue pour un nombre de possibilité superieur a 10 , elle n'est pas optimisée : il y a "<<nombrepos<<" possibilitées (dans les deux sens), il faudra environ "<<nombrepos*0.000015<<" secondes pour resoudre le probleme pour "<<n<<" points. (approximation : un temps 1μs par possibilitée"<<endl;
                int Choix=0;
                PauseFor(0.5);
                cout<<endl<<"Voulez vous continuer ? "<<endl<<"1. OUI"<<endl<<"0. NON";
                do{ cout<<endl<<endl<<">";cin>>Choix;}while (Choix>1||Choix<0);
                if (Choix==0) {
                    break;
                }
                vector <int> ordre (n);
                for(int i=0; i<n; i++)ordre[i]=i;  //initialisation du premier chemin
                double lg;	double best;	vector <int> bestvect (n);		bestvect=ordre;    lgc(ordre,best,n,P); long double iter=0; //calcul du premier chemin
                
                do{
                    ++iter;
                    for(int i=0; i<n; i++){
                        cout<< "->"<<ordre[i];
                    }
                    lgc(ordre,lg,n,P);
                    if(lg<best){best=lg; bestvect=ordre;}
                    cout<<"     distance : "<<lg;
                    cout<<"             "<<(iter*100)/nombrepos<<"%"<<endl;
                    if (iter>=nombrepos) {            //optimisation de la methode classique, permet de sortir de la boucle quand
                        break;                       //toutes les possibilité de trajet circulaire sont etablie.
                                         }                                // les trajet qui suivent sont des repetitions car le trajet de notre colleur
                                                     // est circulaire.
                }while (next_permutation(ordre.begin(),ordre.end())); //POUR AVOIR TOUTES LES POSSIBILITÉES AVEC REPETITION POUR VERIFIER DESACTIVER LE BREAK !!!
                
                cout << endl <<" Le meilleur chemin est : ";
                for(int i=0; i<n; i++)cout<<bestvect[i]<<"->";
                cout<<"avec une distance de : "<<best;

                
                ///////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 2 s."<<endl<<endl;
                PauseFor(2);

                cout<<endl;
            }
                break;






            case 2 :                 cout<<"2. Methode du recuit simulé"<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////
			recuit(n,P);//appel de la méthode du recuit (via le header)

                ////////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 2 s."<<endl<<endl;
                PauseFor(2);

                cout<<endl;
            }
                break;





		//choix de programmer la méthode 2-opt dans le main

            case 3 :                 cout<<"3. Methode 2opt"<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////
                if (n<7) {
                    cout<<endl<<"/!\\ le resultat n'est pas garantie pour un nombre de point <=6 avec cette methode";
                }
                vector <int> ordre (n);

                ordre=randomsansrep (n);

                double lg1;
                double lg2;
                lgc(ordre,lg1,n,P);

                for (int i=0; i<1000;i++) {
                vector <int> ordre2 (n);
                    ordre2=randomsansrep(n);
                    lgc(ordre2,lg2,n,P);
                    
                    if(lg2<lg1) 
                    {
                        ordre=ordre2;
                        lg1=lg2;
                    }
                }

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
                                lgc(ordre, lg1, n,P);
                                cout<<"changement effectuer longeur de : "<<lg1<<endl;
                            }
                        }
                    }
                    
                }while (minchange<0);
                cout << endl <<" Le meilleur chemin est : ";
                double lgd; lgc(ordre,lgd,n,P);
                for(int i=0; i<n; i++)cout<<ordre[i]<<"->";
                cout<<"avec une distance de : "<<lgd;
                ////////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 2 s."<<endl<<endl;
                PauseFor(2);

                cout<<endl;
            }
                break;







            case 4 :                 cout<<"4. Methode combiné 2OPT et recuit"<<endl;
            {
                clock_t t0;
                t0=clock();
                ////////
                methodecombine (n,P);//cette méthode se trouve dans le fichier recuit_simule.cpp et est appelé via le header

                ////////
                t0=clock()-t0;
                cout<<endl<<endl<<"TEMPS D'EXECUTION : "<<((double)t0)/(CLOCKS_PER_SEC)<<" s"<<endl;

                cout<<endl<<"FIN du programme, retour au menu dans 2 s."<<endl<<endl;
                PauseFor(2);

                cout<<endl;
            }
                break;









            case 5 :                cout<<"5. Afficher le detail des points"<<endl<<endl;
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

                cout<<endl<<"FIN du programme, retour au menu dans 2 s."<<endl<<endl;
                PauseFor(2);

                cout<<endl;
            }
                break;

        }

    }while (menu!=0);





    return 0;
}
