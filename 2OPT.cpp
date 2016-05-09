//METHODE 2OPT
#include<iostream>
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
#include <vector> //NE PAS OUBLIER PARTOUT !!!!!!!!!!
using namespace std;
/*
                 NOTES
ne fonctionne pas pour moins de 4 points !!!!
 
                A FAIRE
methode de distance
 
                A FINIR
 
 http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/http://www.technical-recipes.com/2012/applying-c-implementations-of-2-opt-to-travelling-salesman-problems/
*/

vector <int> initiordre( )
{



}
                        
                        
                        
vector <int> amelioration(vector<int> ordre, int n )
                        
{
    for (int i=0; i<new; i++) {
        distance(ordre[i],ordre[i+1]
    }



}
                        
                        
void 2opt(int P[][2] , int n //a completer
          )
{
    vector <int> ordre (n);
    vector <int> ordre2 (n);
    ordre=initiordre();
    bool B=true;
        do{
            ordre2=amelioration();
            if (lgc1==lgc2) {
                B=false
            }
            if (lgc1<lgc2) {
                ordre=ordre2;
                lgc1=lgc2;
            }
        
        
        }while(B!=false);
}