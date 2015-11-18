/*
Problem Link: https://open.kattis.com/problems/secretmessage
2015 SLPC Problem H
This is just an implementation problem. There may be a nicer way to implement, 
but my following code works 
*/
#include <iostream>
#include <string>
#include <algorithm> 
#include <cmath>
#include <string.h> 
using namespace std; 

#define MAXLEN 101 

char a[MAXLEN][MAXLEN]; 
char b[MAXLEN][MAXLEN]; 


bool isPerfectSq(int n){
	return sqrt(n) == floor(sqrt(n)); 
}

int main(){
	string s; 
	int n; 
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> s; 
		int len = (int)s.length(); 
		int N; 
		if (isPerfectSq(len)){
			N = sqrt(len); 
			// process 
			for (int j = 0; j < N; j++){
				for (int k = 0; k < N; k++){
					a[j][k] = s[N*j + k]; 
				}
			}
			// swapping
			for (int j = 0; j < N; j++){
				for (int k = 0; k < N; k++){
					b[k][N-j-1] = a[j][k]; 
				}
			}
		}
		else{
			//cout << (int)sqrt(len) << endl;
			for (int j = (int)sqrt(len);;j++){
				if (j*j >= len){
					N = j;  
					break; 
				}
			}
			//cout << N << endl;
			int diff = N*N - len; 
			for (int j = 0; j < diff; j++){
				s += '*'; 
			}
			// process
			for (int j = 0; j < N; j++){
				for (int k = 0; k < N; k++){
					a[j][k] = s[N*j+k]; 
				}
			}
			// swapping 
			for (int j = 0; j < N; j++){
				for (int k = 0; k < N; k++){
					b[k][N-j-1] = a[j][k]; 
				}
			}
		}
		//print message 
		for (int j = 0; j < N; j++){
			for (int k = 0; k < N; k++){
				if (b[j][k] == '*') continue; 
				else cout << b[j][k]; 
			}
		}
		cout << endl; 
	}
	return 0; 
}
