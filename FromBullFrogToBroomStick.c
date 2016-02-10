// SLPC 2010 
// Print the smallest integer that can be formed from the given digits, with no leading zeros.  
// Beware of the zeros that appear. 

#include <stdio.h> 
#include <string.h> 

int main(){
	char x[32],T;  
	int i,j,n,len,nzeros; 
	scanf("%d\n",&n); 
	scanf("%s",x);  
	for (i = 0,j = 0; x[i] != '\0'; i++){
		if (x[i] != '0') x[j++] = x[i];  
	}
	x[j] = '\0'; 
	nzeros = n-j; 
	len = j;  
	for (i = 0; i < len-1; i++){
		for (j = 0; j < len-1-i; j++){
			if (x[j] > x[j+1]){
				T = x[j]; 
				x[j] = x[j+1];  
				x[j+1] = T; 
			}
		}
	}
	if (nzeros){
		printf("%c",x[0]); 
		for (i = 0; i < nzeros; i++) printf("0"); 
		for (i = 1; i < len; i++) printf("%c",x[i]); 
		printf("\n");  
	}else{
		printf("%s\n",x);  
	}
	return 0; 
}
