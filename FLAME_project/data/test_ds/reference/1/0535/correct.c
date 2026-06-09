#include<stdio.h>
#include<string.h>
char in[500];
int main(){
	scanf("%s",&in);
	int leng=strlen(in),i,j;
	for(i=0;i<leng;i++){
		if(in[i]!='-')printf("%c",in[i]);
		else{
			if(in[i+1]<=in[i-1]||((in[i-1]<=57)&&in[i+1]>57)||((in[i-1]<=90)&&in[i+1]>90))
			printf("-"); 
			else if(in[i-1]<=57&&in[i-1]>=48&&in[i+1]<=57&&in[i+1]>=48)
		    for(j=in[i-1]+1;j<in[i+1];j++)printf("%c",j);
		    
		    else if(in[i-1]<=90&&in[i-1]>=65&&in[i+1]<=90&&in[i+1]>=65)
		    for(j=in[i-1]+1;j<in[i+1];j++)printf("%c",j);
		    
		    else if(in[i-1]<=122&&in[i-1]>=97&&in[i+1]<=122&&in[i+1]>=97)
		    for(j=in[i-1]+1;j<in[i+1];j++)printf("%c",j);
		}
	}
	return 0;
}



