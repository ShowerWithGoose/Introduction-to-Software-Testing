#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int s[10000][5];
int t[10000][5];
int main() {
int i=0,j=0,n=0,k=0,f=0,max=0;
scanf("%d",&n);
for (i=1;i<=n;i++){
scanf("%d%d%d%d",&s[i][0],&s[i][1],&s[i][2],&s[i][3]);
t[i][0]=s[i][0];t[i][1]=s[i][1];t[i][2]=s[i][2];t[i][3]=s[i][3];t[i][4]=1;
}
for (i=1;i<=n;i++){
	for(k=1;k<=n;k++){for(j=1;j<=n;j++){
			
		if(s[i][2]==t[j][0]&&s[i][3]==t[j][1]){
			t[i][4]++;s[i][2]=t[j][2];s[i][3]=t[j][3];break;
		}
			}
		

			}
	}for(i=1;i<=n;i++){
		if(t[i][4]>max){
			f=i;
			max=t[i][4];
		}
	}
printf("%d %d %d",max,t[f][0],t[f][1]);

	return 0;
}

