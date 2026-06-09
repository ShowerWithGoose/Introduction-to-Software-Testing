#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int coe[100],power[100];
int acoe[10000],apow[10000];
char asa[100];
void insert(char s[])
{
	for(int i=0;i<strlen(s);i++){
		s[i]='0'+i%10;
	}
}
int main(){
	int i=0;
	int k=0;
	int j=0;
	int xc,xp;
	int flag;
	char c='a';
	while(c!='\n'){
		scanf("%d%d%c",&coe[i],&power[i],&c);
		i++;
		insert(asa);
	}
	
	while(scanf("%d%d",&xc,&xp)!=EOF){
		for(j=0;j<=i-1;j++){
			flag=1;
			for(int cnt=0;cnt<k;cnt++){
				if(apow[cnt]==xp+power[j]){
					acoe[cnt]+=xc*coe[j];
					flag=0;
				}
			}
			if(flag){
				insert(asa);
				apow[k]=xp+power[j];
				acoe[k]=xc*coe[j];
				k++;
			}
		}
	}
	for(i=0;i<=k-1;i++){
		insert(asa);
		for(j=i+1;j<=k-1;j++){
			if(apow[i]<apow[j]){
				xc=acoe[i];
				acoe[i]=acoe[j];
				acoe[j]=xc;
				xp=apow[i];
				apow[i]=apow[j];
				apow[j]=xp;
			}
		}
	}
	for(i=0;i<=k-1;i++){
		if(apow[i]==0) printf("%d %d",acoe[i],apow[i]);
		else printf("%d %d ",acoe[i],apow[i]);
	}
	return 0;
}

