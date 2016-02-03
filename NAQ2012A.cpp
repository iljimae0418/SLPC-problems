// https://www.acmicpc.net/problem/10491
#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream> 
#include <algorithm> 
using namespace std;

int main(){
	string s; 
	while (getline(cin,s)){
		bool flag = true;  
		istringstream iss (s); 
		string word;
		while (iss >> word){
			transform(word.begin(),word.end(),word.begin(),::tolower);  
			if (word.find("problem") != string::npos){
				flag = false;  
				cout << "yes" << endl; 
				break; 
			}
		}
		if (flag) cout << "no" << endl; 
	}
	return 0; 
} 

