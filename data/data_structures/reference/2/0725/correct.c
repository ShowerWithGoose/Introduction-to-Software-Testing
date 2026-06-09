#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
char s[10000],a[10000],b[10000];
int c[10000],d[10000];
int main()
{
	int j=0,k=0,u=1,v=1,w=0;
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]==' '){
			continue;
		}
		a[j]=s[i];
		j++;
	}
	for(int i=0;i<strlen(a);i++){
		if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='='){
			c[k]=i;
			k++;
		}
	}
	if(c[0]==1){
		d[c[0]]=a[0]-'0';
	}
	else{
		for(int i=0;i<c[0];i++){
			d[c[0]]=d[c[0]]*10+a[i]-'0';
		}
	}
	for(int i=1;i<k;i++){
		if(c[i]-c[i-1]==2){
			d[c[i]]=a[c[i]-1]-'0';
		}
		else{
			for(int z=c[i-1]+1;z<c[i];z++){
				d[c[i]]=d[c[i]]*10+a[z]-'0';
			}
		}
	}
	for(int i=0;i<k;i++){
		if(a[c[i]]=='*'){
			d[c[i+1]]=d[c[i]]*d[c[i+1]];
		}
		if(a[c[i]]=='/'){
			d[c[i+1]]=d[c[i]]/d[c[i+1]];
		}
	}
	
	for(int i=0;i<k;i++){
		if(a[c[i]]=='+'){
			while(a[c[i+u]]=='*'||a[c[i+u]]=='/'){
				u++;
			}
			d[c[i+u]]=d[c[i]]+d[c[i+u]];
		}
		if(a[c[i]]=='-'){
			while(a[c[i+v]]=='*'||a[c[i+v]]=='/')
			{
				v++;
			}
			d[c[i+v]]=d[c[i]]-d[c[i+v]];
		}
	}
	printf("%d",d[c[k-1]]);
	return 0;
}


