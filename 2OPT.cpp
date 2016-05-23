//METHODE 2OPT
#include<iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
#include <vector> //NE PAS OUBLIER PARTOUT !!!!!!!!!!
#include "recuit.h"
#include "PM.h"
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



void Tswap(int i, int k,const int & n,vector <int> ordre,vector <int> ordre2 )
{
    int dec=0;
    for ( int c = i; c <= k; ++c )
    {ordre2 [i]=ordre [k-dec];
        dec++;
    } //version modifier dans ordre 2
    cout<<endl<<"resultat 1 : ";
    for (int i=0; i<n; i++) cout << ordre[i] << "->"; cout << endl;
    cout<<endl<<"resultat 2 : ";
    for (int i=0; i<n; i++) cout << ordre2[i] << "->"; cout << endl;

}





void dopt(const int P[][2] , const int& n //a completer
          )
{
    vector <int> ordre (n);
    vector <int> ordre2 (n);
	ordre=ordre2;
    ordre=initiordre(n);
    double lgc1=0;
    double lgc2=0;
    int amelioration=0;
    while (amelioration<20) {
        lgc(ordre,lgc1,n);
        for ( int i = 0; i < n - 1; i++ )
        {
            for ( int k = i + 1; k < n; k++)
            {
                Tswap( i, k,n,ordre, ordre2 );

                lgc(ordre2,lgc2,n);

                if ( lgc1 < lgc2 )
                {
                    // amelioration trouvé alors on reset
                    amelioration = 0;
                    lgc1 = lgc2;
                }
            }
        }

        amelioration ++;
    }
}







*/
