#include<stdio.h>
#include<string.h>
int main(){
	FILE *in=fopen("article.txt","r");
	char s[10000][100],c[10000],s1[100]={0},ch;
	int i=0,j=0,k=0,t=0,n,a[10000]={0};
	while((ch=fgetc(in))!=EOF){
		c[k++]=ch;
		if(((c[k-2]>='a'&&c[k-2]<='z')||(c[k-2]>='A'&&c[k-2]<='Z'))&&((ch >= 'z' || (ch < 'a' && ch > 'Z') || ch < 'A'))){
			i++;
			j=0;
		}
		if(ch>='A'&&ch<='Z')
	    s[i][j++]=ch+32;
	    if(ch>='a'&&ch<='z')
	    s[i][j++]=ch;
	}
	n=i-1;
	for(i=n+1;i>0;i--){
		for(j=0;j<i-1;j++){
			if(strcmp(s[j+1],s[j])<0){
                strcpy(s1,s[j+1]);
                strcpy(s[j+1],s[j]);
                strcpy(s[j],s1);
			}
		}
	}
	k=1;
	for(i=0;i<=n;i++){
		if(strcmp(s[i+1],s[i])==0){
			k++;
		}
		else{
			printf("%s %d\n",s[i],k);
			k=1;
		}
	}
} 

