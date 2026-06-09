#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define tolower(c) (c>='A'&&c<='Z'?c-'A'+'a':c)
#define N 1024
int main(){
	int i,j,n=0,k,l=0,q,a1[500],b1;
	FILE *in;
	char a[500]={0},s[N]={0},t[N][50]={0},b[50]={0}; 
	in=fopen("article.txt","r");
	memset(s,0,sizeof(s));
	memset(a1,0,sizeof(a1));
	while(fgets(s,N-1,in)!=NULL){
		for(i=0;i<strlen(s);i++){
			l=0;
			memset(a,0,sizeof(a));
			for(j=i;j<strlen(s);j++){
				if((s[j]>='a'&&s[j]<='z')||(s[j]>='A'&&s[j]<='Z')){
					a[l]=tolower(s[j]);
					l++;
				}
				else{
					break;
				}
			}	
			i+=strlen(a);
			q=0;
			for(k=0;k<n;k++){
				if(strcmp(a,t[k])==0){
					a1[k]++;
					q=1;
					break;
				}
			}
			if(q==0){
				strcpy(t[n],a);
				a1[n]++;
				n++;
			}
		}
	}
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			if(strcmp(t[i],t[j])>0){
				strcpy(b,t[i]);
				strcpy(t[i],t[j]);
				strcpy(t[j],b);
				b1=a1[i];
				a1[i]=a1[j];
				a1[j]=b1;
			}
		}
	for(i=1;i<n;i++){
		printf("%s %d\n",t[i],a1[i]);
	}	
	return 0;
}


