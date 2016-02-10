/* Stanford Local Programming Contest 2010 
Input: The first line contains an integer n representing the length of the string s. 
The second line contains the given string s. 
Output: Print a single integer representing the highest number of characters that appear consecutively.   

e.g. 
Input: 
3 
aab 
Output: 
2 


Input: 
10 
abbb12333 
Output: 
3
*/

#include <stdio.h> 
#include <string.h> 

int main(){
	char x[32];  
	int i,count,max=0;  
	scanf("%s",x);  
	for (i = 0,count = 1; x[i+1] != '\0'; i++){
		if (x[i] == x[i+1]) count++; 
		else{
			if (count > max){
				max = count; 
				count = 1;  
			}
		}
	}
	if (count > max){
		max = count; 
		//count = 1; 
	}
	printf("%d\n",max);  
	return 0; 
}



