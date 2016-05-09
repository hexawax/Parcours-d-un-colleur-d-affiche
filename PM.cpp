
#include <iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
#include <vector>
using namespace std;

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
int main(){
intro();
srand(time(NULL));
    
    int limitept=10;//limite nb de point
    int n;
    cout<<endl<<"Entrez premierement le mombre de point (limite a "<<limitept<<") : ";
    do{ cin>>n;}while (n>limitept||n<0);
    cout<<endl<<"la position des points est genere aleatoirement entre -100 et 100"<<endl;
    double* P[n];//creation d'un tableau avec les diferents points
    for (int i=0; i<n; i++)// je sais plus si c'est < ou <= pour faire n case de du tabeau
    {
        P[i]=new double [2];//tableau des coordonnées des points dans un  plan
        P[i][1]=bazinga();
        P[i][2]=bazinga();//positionnement aleatoire des points dans le plan
    }
    
    int menu;
    do
    {
        cout<<endl<<endl<<" ----------------------- MENU -----------------------"<<endl<<endl;
        cout<<"1. Methode classique"<<endl;
        PauseFor(0.2);
        cout<<"2. Methode du recuit simulé"<<endl;
        PauseFor(0.2);
        cout<<"3. Methode 2opt"<<endl;
        PauseFor(0.2);
        cout<<"4. Methode génétique"<<endl;
        PauseFor(0.2);
        cout<<"5. Voir les temps"<<endl;
        PauseFor(0.2);
        cout<<"6. Le bouton 6"<<endl;
        PauseFor(0.2);
        cout<<"0. Quitter"<<endl<<endl;
        PauseFor(0.2);
        cout<<"Choix : ";
        cin>>menu;
        cout<<endl;
        
        switch(menu)
        {
            case 0 : break;
                
            case 1 :                 cout<<"1. Methode classique"<<endl;
                
                
                cout<<endl<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);
                break;
                
            case 2 :                 cout<<"2. Methode du recuit simulé"<<endl;
                
                
                cout<<endl<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);
                break;

            case 3 :                 cout<<"3. Methode 2opt"<<endl;
                
                
                cout<<endl<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                break;
                
            case 4 :                 cout<<"4. Methode génétique"<<endl;
                
                
                cout<<endl<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);


                break;
                
            case 5 :                 cout<<"5. Voir les temps"<<endl;
                
                
                cout<<endl<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                break;
                
            case 6 :                cout<<"6. Le bouton 6"<<endl;
                
                for(int i =0; i<n ; i++)//verification des valeurs des points
                { cout<<"Point "<<i<<endl;
                    cout<<P[i][1]<<endl;
                    cout<<P[i][2]<<endl; 
                }
                
                cout<<endl<<endl<<"FIN du programme, retour au menu dans 5 s."<<endl<<endl;
                PauseFor(5);

                cout<<endl;
                break;
                
        }
        
    }while (menu!=0);
    

    


    return 0;
}
