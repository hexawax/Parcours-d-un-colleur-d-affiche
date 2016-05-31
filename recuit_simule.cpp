/////////////////////////////////////////////////////////////////////////////////////////////////// 
////////////////////////Optimisation de la methode avec le recuit simulé///////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <vector>
using namespace std;


double proba0_1()//loi de proba entre 1 et 0 fonctionnelle
{
  return ((double)rand())/(RAND_MAX); //valeur aleatoire du nombre entre 0 et 1
}






double distance (const int P[][2],int i, int j)//distance entre 2 point d'un tableu double de points : i = Point 1 & j =Point 2
{
    return sqrt( (P[j][0]-P[i][0]) * (P[j][0]-P[i][0])
                + (P[j][1]-P[i][1]) * (P[j][1]-P[i][1]) ); //retourne le distance
}




void lgc(const vector <int> ordre, double& lg1,const int n, //methode calcul la distance totale du parcours dans un double
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
                





vector<int> randomsansrep (const int MAX){ //fonction pour créer un ordre de point sans répétitions et aleatoire
    vector <int> value(MAX);
    for (int i=0;i<MAX;i++)
    {
        bool check; //variable pour vérifier que le nombre n'est pas déja utiliser
        int n; //different du nombre de point ici
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




vector <int> intervers (vector<int> ordre, const int n) //methode pour trouver un chemin voisin, proche d'un ordre
{
	vector <int> ordre2 (n);
	int all2=0;
	int all1=0;
	do{all1=rand()%n;
	   all2=rand()%n;}while(all1==all2); //on intervertie des points au hazard
	ordre2=ordre;
	ordre2[all1]=ordre[all2];
	ordre2[all2]=ordre[all1];	
return ordre2;
}



double baissetemp(double T)//méthode qui doit être appeler pour baisser la temperature lors du recuit mais elle est moins
                            //efficace que la loi 0.99*T
{return log(T);}            //a utiliser pour des tests





void recuit(int n, const int P[][2]) //méthode principale pour le calcul du recuit
{
    srand(time(NULL));
    int iter=0;
    double T=10; //initiaisation de la temperature a 10
    double lgc1;
    double lgc2;
    int B=0; //B est le compteur d'echec d'amelioration
    vector <int> ordre (n);
    ordre=randomsansrep(n); //on donne un ordre aleatoire
   vector <int> ordre2(n);
    lgc(ordre, lgc1,n,P); //on calcul une premiere distance
    double proba;//pour que palier soit plus qurand que iter des le debut
    do{
       do {
           ordre2=intervers(ordre,n); //on fait une intervertion
           lgc(ordre2, lgc2,n,P); //nouvelle distance
            bool change=false;
            if (lgc2<lgc1) change=true; //si la nouvelle distance est plus courte on garde
            if(lgc1<lgc2){ 
                   proba=exp(-(lgc2-lgc1)/(T));//on exprime l'energie du systeme et sa probabilitée
                   if(proba0_1()<proba) change=true; //meme si la nouvelle longeur est plus longue on accepete le changement enfonction de proba
                        }                             // c'est la force du recuit ce qui permet de passer les minimums locaux
                    if (change)
                       {
                       ordre=ordre2;
                       lgc1=lgc2;
                        B=0;
                       }
                    else B++;

        iter++;
        cout << lgc1 << " ";
       }while (B<70);                               // au bout de 70 echec d'ameloiration on sort de la boucle car cela veut dire qu'il faut baisser la temperature,
       cout << " fin palier T=" << T << endl;                                       // on est proche d'un minimum
      B=0; T=0.99*(T); //on peut utiliser ici soit la loi lineaire ou le log meme si la loi lineaire est plus efficace pour nos autres parametres
    }while(T>0.000000001); //condition de sortie la temperature dois baisser jusqua cette valeur cela permet de stabiuliser l'algorithme

cout<<endl<<"resultat : ";
for (int i=0; i<n; i++) cout << ordre[i] << "->"; cout << endl;
cout<<"longeur : "<<lgc1<<endl;
}




vector <int> doptcombine(vector <int> ordre, const int n,const int P[][2]) //methode light de 2opt pour la mehtode combiné
{   double lgc1=0;
    double minchange=0;
    double change;
    int save;
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
        
                }
            }
        }
                            //nous avons supprimer le do while pour de meilleur performance
    
    return ordre; //retourne le vecteur avec moins de croisement (avec une seule passe il peut en rester ) mais cest plus rapide que la methode complete pour des n grands.
    
}




void methodecombine (int n,const int P[][2]          //méthode alliant le recuit-simule et la méthode 2-opt
)
{   cout<<"Methode combiné :"<<endl;
    srand(time(NULL));
    int iter=0;
    double T=10;                        //Il ya les meme parametres que pour le recuit
    double lgc1;
    double lgc2;
    int B=0;
    vector <int> ordre (n);             //la difference est l'utilisation de 2opt pour le calcul du nouvelle ordre
    ordre=randomsansrep(n);
    vector <int> ordre2(n);
    lgc(ordre, lgc1,n,P);               // nous avons remarque que si nous utilision 2opt periodiquement et pas a chaque fois cela accelerai la methode sans trop modifier le resultat
    double proba;
    do{                                 // Pour de tres quand nombre de point, 2 opt est lent. contre cela nous avons utilisé une vertion light de 2opt qui fais les calculs une seule fois
        do {
                                        // et nous avons decider d'alternet entre 2opt pour supprimer des croisement et l'intervertion pour trouver de meilleur chemin.
            
                                        // la periodicite est arbitraire et joue sur le nombre de calcul et le temps d'execution .
            
            if (iter % 5 == 0){ordre2=doptcombine(ordre,n,P);} //utilisation de 2opt pour enlever les intervertion qui crerait des croisements
                                                // pour accelerer, on utilise une version light de 2opt tous les 5 intervertions pour enlever les croisement
                                                 //     5 est un bon compromis cela ralenti l'algorythme par rapport au recuit, mais le rend plus performant
            else {ordre2=intervers(ordre,n);} //utilisation de l'intervertion aussi non
            lgc(ordre2, lgc2,n,P);
            bool change=false;
            if (lgc2<lgc1) change=true;
            if(lgc1<lgc2){
                proba=exp(-(lgc2-lgc1)/(T));//kT doit etre de l'ordre du delta lgc
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
        }while (B<70);
        cout << " fin palier T=" << T << endl;
        B=0; T=0.99*(T);
    }while(T>0.00000001);
    cout<<endl<<"resultat : ";
    for (int i=0; i<n; i++) cout << ordre[i] << "->"; cout << endl;
    cout<<"longeur : "<<lgc1<<endl;
    cout<<endl<<endl<<"/////////////////////////////////////////////////////////////////"<<endl<<endl;
    
    cout<<endl<<endl<<"RESULTAT FINAL : ";
    for (int i=0; i<n; i++) cout << ordre[i] << "->"; cout << endl; //affichage du resultat final
    cout<<"longeur : "<<lgc1<<endl;
}
