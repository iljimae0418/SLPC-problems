/*
SLPC 2015 Problem B 
Problem Link: https://open.kattis.com/problems/bobby
By Minsuk Kim (Luke) 
For each case, output "yes" if Bobby's expected return is greater than his bet, 
or "no" otherwise. Bobby is somewhat risk averse and does not bet if his expected return is equal to his bet. 
LOL don't know why I couldn't solve this during the contest. We simply calculate the probability that Bobby achieves 
what Betty proposed and multiply that value by W and check if that value is STRICTLY greater than 1. 
*/
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std; 

int b[11][11]; 
// calculate binomial coefficient using dynamic programming. 
int binom(int n, int m){
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= min(i,m); j++){
			if (i == 0 || j == 0) b[i][j] = 1;  
			else b[i][j] = b[i-1][j-1] + b[i-1][j]; 
		}
	}
	return b[n][m];  
}

int main(){
	int t,R,S,X,Y,W; 
	cin >> t; 
	for (int i = 0; i < t; i++){
		cin >> R >> S >> X >> Y >> W; 
		double probSat = (double)(S-R+1)/S; 
		double probNsat = 1.0 - probSat;  
		double total = 0.0; 
		for (int j = X; j <= Y; j++){
			double prod = 1.0; 
			for (int k = 0; k < j; k++){
				prod *= probSat; 
			}
			for (int k = 0; k < Y-j; k++){
				prod *= probNsat;  
			}
 			prod *= binom(Y,Y-j);  
			total += prod; 
		}
		total *= W; 
		if (total > 1) cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0; 
}
