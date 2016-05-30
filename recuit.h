#ifndef _RECUIT_SIMULE_
#define _RECUIT_SIMULE_

#include <vector>		
using namespace std;	
double proba0_1();//loi de proba entre 1 et 0 fonctionnelle
double unsurT(double T); //fonction T(n)=1/K or k est parametres de la fonction
double distance (const int P[][2],int i, int j);//distance entre 2 point d'un tableu double de points i = P1 & j =P2
void lgc(const vector <int> ordre, double& lg1,const int n,const int P[][2]);
vector<int> randomsansrep (const int MAX);
vector <int> intervers (vector<int> ordre, const int n);
double baissetemp(double T);
void recuit(int n, double k,const int P[][2]);
void methodecombine (int n, double k, const int P[][2]);
vector <int> doptcombine(vector <int> ordre,const int n,const int P[][2]);
#endif
