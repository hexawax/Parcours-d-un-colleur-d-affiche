/*___    ____  ______   ____    ____  ___       _______  _______  __    __  .______
\   \  /   / /  __  \  \   \  /   / /   \     /  _____||   ____||  |  |  | |   _  \
 \   \/   / |  |  |  |  \   \/   / /  ^  \   |  |  __  |  |__   |  |  |  | |  |_)  |
  \      /  |  |  |  |   \_    _/ /  /_\  \  |  | |_ | |   __|  |  |  |  | |      /
   \    /   |  `--'  |     |  |  /  _____  \ |  |__| | |  |____ |  `--'  | |  |\  \----.
    \__/     \______/      |__| /__/     \__\ \______| |_______| \______/  | _| `._____|

                               _______   _______
                              |       \ |   ____|
                              |  .--.  ||  |__
                              |  |  |  ||   __|
                              |  '--'  ||  |____
                              |_______/ |_______|

  ______   ______   .___  ___. .___  ___.  _______ .______        ______  _______
 /      | /  __  \  |   \/   | |   \/   | |   ____||   _  \      /      ||   ____|
|  ,----'|  |  |  | |  \  /  | |  \  /  | |  |__   |  |_)  |    |  ,----'|  |__
|  |     |  |  |  | |  |\/|  | |  |\/|  | |   __|  |      /     |  |     |   __|
|  `----.|  `--'  | |  |  |  | |  |  |  | |  |____ |  |\  \----.|  `----.|  |____
 \______| \______/  |__|  |__| |__|  |__| |_______|| _| `._____| \______||_______|


                                           )
                              (   (   (  /(
                              )\  )\  )  ())
                              ((_)((_)(  (_)\
                                \ \  / /  / |
                                 \ V /    | |
                                  \_/     |_|
 changer la version lors des modification !
*/
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

void Pcirculaire (string tab[],int g, int tailletab){
  string save =tab[g];
  for (int i=g; i<tailletab-1; i++)
  {
    tab[i]=tab[i+1];
  }
  tab[tailletab-1]=save;
}

void combinaison (string nom[],int nec,int tailletab)//nec premier nombre du tableau
{
if ((tailletab-nec)<=1){

}
  else {
    for (int i =0 ;i<tailletab-nec;i++)
    {
      Pcirculaire(nom, nec, tailletab);
      combinaison(nom, nec+1,tailletab);
    }
  }
}


double bazinga() //fct de point aleatoire
{int signe =rand()%(1); //avoir un signe aleatoirement
  if (signe==0){
  return rand()%(100); //valur aleatoire du nombre entre 0 et 100
}
else return -rand()%(100);//valeur aleatoire du nombre
}

double distance (double x1, double y1, double x2, double y2)//distance entre 2 points @@@@ A1B2
{
  return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
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
/*
                         _____
                        / /\ \
                      / /|_|\ \
                    /_/  (_) \_\
    GRAVE : La methode du string ne fonctionne pas pour une adresse de tableau > 9 car 10 est 1 & 0 et il comprednra le point 1 et le point 0 il faudra ajouter un separateur
    Le voyageur ne peut pas passer deux fois par le meme point(A-@B-@A-@B) pour eviter les boucles infini A MODIFIER  car ne marche pas pour un plan en 3D
*/
string [n] S;
S[0]=to_string(0);//on part du point O a chaque fois VOIR LA NOTICE grave

for(int i=1; i<n; i++)//1 car il ya 2 0 aussi non dans s[0]+i
{S[0]=S[0]+to_string(i);} // RESOLUS archive IcI je cherche un moyen de faire toutes les possibilité de chemin entre les mpoint mais il faut les enregistrer quelque part pour l'instant je bloque
cout<<S[0];
//combinaison(S,0,n);














  return 0;
}
