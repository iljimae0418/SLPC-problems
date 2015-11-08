// By Minsuk Kim (Luke)
// Code that solves 2015 Stanford Local Programming Contest Problem G  
// Problem link: https://open.kattis.com/contests/onyyqy/problems/safepassage 
// Variation of the Bridge and Torch problem. 
// Refer to this link for a theoretical treatment of this problem: 
// http://page.mi.fu-berlin.de/rote/Papers/pdf/Crossing+the+bridge+at+night.pdf
// Maximum input size is only 15 so no need to worry about TLE. 
#include <iostream>
#include <cstdlib>
#include <vector> 
#include <algorithm> 
#include <climits>
using namespace std;  

vector<int> storeInfo; 
vector<int> storeVal; 
int ans = INT_MAX; 

void calc(){
	int N = storeInfo.size(); 
	for (int i = 0; i <= N/2 - 1; i++){
		int val = 0; 
		val += (N-2-i)*storeInfo[0] + (2*i+1)*storeInfo[1]; 
		for (int j = 3; j <= N; j++){
			val += storeInfo[j-1]; 
		}
		for (int j = 1; j <= i; j++){
			val -= storeInfo[N+1-2*j-1]; 
		}
		storeVal.push_back(val); 
	}
	return; 	
}

void findMin(){
	for (vector<int>::size_type i = 0; i < storeVal.size(); i++){
		ans = min(ans,storeVal[i]); 
	}	
}

int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		int num; 
		cin >> num; 
		storeInfo.push_back(num);
	}
	sort(storeInfo.begin(),storeInfo.end());
	calc(); 
	findMin();
	cout << ans << endl;
	return 0; 
}
