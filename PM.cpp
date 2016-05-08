
#include <iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
using namespace std;

double factorielle(int n)//fct factoriel pour calculer le nb de possibilité
{
  return (n ==1||n== 0) ? 1 :factorielle(n - 1) * n;
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
do{ cin>>n;}while (n>10||n<0);
cout<<endl<<"la position des points est genere aleatoirement entre -100 et 100"<<endl;
double* P[n];//creation d'un tableau avec les diferents points
for (int i=0; i<=n; i++)// je sais plus si c'est < ou <= pour faire n case de du tabeau
{
  P[i]=new double [2];//tableau des coordonnées des points dans un  plan
  P[i][1]=bazinga();
  P[i][2]=bazinga();//positionnement aleatoire des points dans le plan
}

for(int i =0; i<n ; i++)//verification des valeurs des points
{ cout<<"Point "<<i<<endl;
  cout<<P[i][1]<<endl;
  cout<<P[i][2]<<endl;
}

////////////////////////////////CHOIX DU CHEMIN////////////////////////////////////

    string [n] S ;
S[0]=to_string(0);//on part du point O a chaque fois VOIR LA NOTICE grave

for(int i=1; i<n; i++)//1 car il ya 2 0 aussi non dans s[0]+i
{S[0]=S[0]+to_string(i);} // RESOLUS archive IcI je cherche un moyen de faire toutes les possibilité de chemin entre les mpoint mais il faut les enregistrer quelque part pour l'instant je bloque
cout<<S[0];
//combinaison(S,0,n);




  return 0;
}
