#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h> 
void creatsequence(int i,int s[]){
	int j=0;
	for(j=0;j<=i-1;j++){
		s[j] = j+1;
	}
}
void printsequence(int i , int s[]){
	 for(int j =0;j<=i-1;j++ ){
		printf("%d ",s[j]);
	}
	printf("\n");
}
void change(int i, int j,int s[]){
	int temp;
	temp = s[i];
	s[i] = s[j];
	s[j] = temp;
}
int findfirst(int i,int s[]){
	int j = 0;
	for(j = i-1;j>=1;j--){
		if(s[j]>s[j-1]){
			 return j - 1;
			}
		}
	
	return -1;
}
int findsmallest(int i,int number , int s[]){
	for(int j = i-1;j>=1;j--){
		if(s[j]>number){
			return j;
		}
	}
}
void reverse(int n,int i,int s[]){
	int j = 0;
	n = n-1;
	i = i+1;
	for(;n-j>i+j;j++){
		change(n-j,j+i,s);
	} 
}
int main(){
	int n;
	scanf("%d",&n);
	int s[11] = {0};
	creatsequence(n,s);
	while(findfirst(n,s)!=-1){
		printsequence(n,s);
		int i = findfirst(n,s);
		int j = findsmallest(n,s[i],s);
		change(i,j,s);
		reverse(n,i,s);
	}
	printsequence(n,s);
	
	
	
	return 0;
}

