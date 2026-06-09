#include<stdio.h>
#include<string.h>
#include<malloc.h>
typedef struct node{
	char Data[50];
	int count ;
} Node;
Node s[100000];

int luru(char str[],int k){
	int i,j;
	for(i=0;i<k;i++){
		if(strcmp(str,s[i].Data )==0){
			s[i].count ++;
			return 0;
		}
	}
	s[k].count =1;
	strcpy(s[k].Data ,str);
	return 1;
}

void bubblesort(Node s[],int n){
 	int i,j,flag,hold1;
 	char hold[100];
 	for(i=0;i<n-1;i++){
 		flag=0;
 		for(j=0;j<n-1-i;j++){
 			if(strcmp(s[j].Data,s[j+1].Data ) >0){
 				strcpy(hold,s[j].Data );
 				strcpy(s[j].Data ,s[j+1].Data );
 				strcpy(s[j+1].Data ,hold);
 				hold1=s[j].count ;
 				s[j].count =s[j+1].count ;
 				s[j+1].count =hold1;
 				flag=1;
			 }
		 }
		if(flag==0){
			break;
		}	 
	 }
 } 
 
int main()
{
	FILE * fp;
	fp=fopen("article.txt","r");
	int i,j,k;
	int m,n;
	char ch=' ',str[100];
	j=0;k=0;
	int mark=0;
	while(EOF!=(ch=fgetc(fp))){
		if(ch>='a'&&ch<='z'){
			str[j++]=ch;
			mark=1;	
		}
		else if(ch>='A'&&ch<='Z'){
			str[j++]=ch+('a'-'A');
			mark=1;
		}
		else{
			if(mark==1){
				str[j]='\0';
				if(luru(str,k)) k++;
				mark=0;j=0;
				memset(str,0,sizeof(str));
			}
		}
	}n=k;
	bubblesort(s,n);
	for(i=0;i<n;i++){
		printf("%s",s[i].Data );
		printf(" %d\n",s[i].count );
	}
	return 0;
 } 

