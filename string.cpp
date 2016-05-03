#include <iostream>
#include <string>
#include "PM.h"

using namespace std;


void enregistrement (int n, string S [i])
{

ifstream fichier("points.txt",ios::in);
if (fichier)
{
	string P;
		for (int i=0; i<n;i++){
			p=S [i];
			cout<<"point numero "<<i<<": ";
			getline (fichier,P);
		}

	fichier.close();
}
else cout<<"ouverture impossible"<<endl;


}
