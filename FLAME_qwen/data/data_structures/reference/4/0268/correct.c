#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#define fr(i,l,n) for(i=l;i<n;i++)
#define ll long long
#define pc putchar
#define gc getchar()
#define sc scanf
#define in(n) scanf("%d",&n)
#define pr printf
#define pn putchar('\n')
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define st struct
char wor[1000][100];
int num[1000];
char tem[1000];
void swap(int t){
	int i;
	fr(i,0,100) tem[i]=wor[t][i];
	fr(i,0,100) wor[t][i]=wor[t+1][i];
	fr(i,0,100) wor[t+1][i]=tem[i];
	i=num[t];
	num[t]=num[t+1];
	num[t+1]=i;
}
void bubSort(int n){
	int i,j,jud;
	for(i=0;i<n-1;i++){
			jud=0;
		for(j=0;j<n-i-1;j++){
		if(strcmp(&wor[j][0],&wor[j+1][0])>0){
			swap(j);
			jud=1; 
		}
		}
		if(jud==0) break;
		}
return ;
}
int rep(int n){
	int i;
	fr(i,0,n){
		if(strcmp(&wor[i][0],&wor[n][0])==0){
			return i;
		}
	}
	return -1;
}
int main(){
	int i,cntw=-1,cntc=0,jud=1,tem=0;
	char c;
	FILE* fp;
	fp=fopen("article.txt","r");
	while(c=fgetc(fp),c!=EOF){
		if(c>='A'&&c<='Z'){
			c-='A';
			c+='a';
		}
		if(isalpha(c)==0){
			jud=1;
		}else{
			if(jud){
				jud=0;
				tem=rep(cntw);
				if(tem+1){
					num[tem]++;
					memset(&wor[cntw][0],0,100);
					cntw--;
				}
				cntw++;
				cntc=0;
				wor[cntw][cntc]=c;
			}else{
				jud=0;
				cntc++;
				wor[cntw][cntc]=c;
			}
		}
	}
	tem=rep(cntw);
	if(tem+1){
		num[tem]++;
		memset(&wor[cntw][0],0,100);
		cntw--;
	}
 	bubSort(cntw+1);
	fr(i,0,cntw+1){
		pr("%s %d\n",&wor[i][0],num[i]+1);
	}
return 0;
}

