#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
char s[100];
int a[100],b[100];
int main()
{
	int br=1,j=0,k=0,ans=0;
	gets(s);
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-'0'+a[j]*br;
			br=10;
		}
		if(s[i]==' '||s[i]=='=') continue;
		if(s[i]=='+'){
			br=1;
			a[++j]=-1;j++;
		}
		if(s[i]=='-'){
			br=1;
			a[++j]=-2;j++;
		}
		if(s[i]=='*'){
			br=1;
			a[++j]=-3;j++;
		}
		if(s[i]=='/'){
			br=1;
			a[++j]=-4;j++;
		}
	}
	//for(int i=0;i<=j;i++) printf("%d ",a[i]);
	//printf("\n");
	for(int i=0;i<=j;i++){
		if(a[i]>=0||a[i]==-1||a[i]==-2) b[k++]=a[i];
		if(a[i]==-3){
			b[k-1]*=a[i+1];
			i++;
		}
		if(a[i]==-4){
			b[k-1]/=a[i+1];
			i++;
		}
	}
	ans=b[0];
	for(int i=1;i<k;i++){
		if(b[i]==-1){
			ans+=b[i+1];
			i++;
		}
		if(b[i]==-2){
			ans-=b[i+1];
			i++;
		}
	}
	printf("%d",ans);
	return 0;
}


