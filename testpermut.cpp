// next_permutation example
#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <cmath> //sqrt
#include <cstdlib> //rand
#include <ctime> //intialisatn de rand
#include <string>
void permutation (int n, double S[], double *Trajet){

  std::sort (S,S+n);
 Trajet=new int [factorielle(n)][n]
  std::cout << "The n! possible permutations with n elements:\n";
int i=0;
  do {
		for (int j=0; j<n; j++)
			{
				Trajet[i][j]=S[j];
		}
	i++;

  } while ( std::next_permutation(myints,myints+n) );

cout<<"cout de la mort";

  return 0;
}