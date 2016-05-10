//METHODE 2OPT
#include<iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
#include <vector> //NE PAS OUBLIER PARTOUT !!!!!!!!!!
#include "recuit.h"
using namespace std;
/*
                 NOTES
ne fonctionne pas pour moins de 4 points !!!!
 
                A FAIRE
methode de distance
 
                A FINIR
 
 http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/
*/

vector <int> initiordre(const int n )
{
vector<int> ordre (n);
for (int i=0; i<n; i++)
{
	ordre[i]=i;
}
return ordre;
}
                        
 /*                       
                        
vector <int> amelioration(vector<int> ordre, int n, int a, int b )
                        
{
    for (int i=0; i<n; i++) {
        distance(ordre[i],ordre[i+1]
    }



}
  */                      







                        
void dopt(int P[][2] , const int n //a completer
          )
{
    vector <int> ordre (n);
    vector <int> ordre2 (n);
	ordre=ordre2;
    ordre=initiordre(n);
    bool amelioration=true;
        do{ amelioration=false;
		for (int i=0; i<n-1;i++)
		{
			for(int j=i+1; j<n; j++)
			{
				if((distance(P,i,i+1)+distance(P,j,j+1))>
					(distance(P,i,j)+distance(P,i+1,j+1)))
				{ordre2[i+1]=ordre[j];
				 ordre2[j]=ordre[i+1];		
				}}
		}
        
        
        }while(amelioration==true);

cout<<endl<<"resultat : ";
for (int i=0; i<n; i++) cout << ordre2[i] << "->"; cout << endl;
}























