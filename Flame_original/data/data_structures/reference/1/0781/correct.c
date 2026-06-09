#include<stdio.h>
#include<math.h>
#include<string.h>
void quanpai(int a,int b);
int used[15];
char ch[30];
int main(){
	int n;
	scanf("%d",&n);
	quanpai(1,n);
}
void quanpai(int a,int b){
	int i;
	if (a==b){
		for(i=1;i<=b;i++){
			if(used[i]==0){
				printf("%s%d\n",ch,i);return;
			}
		}
	}
	for(i=1;i<=b;i++){
		if(used[i]==0){
			ch[2*a-2]=i+'0';
			ch[2*a-1]=' ';
			used[i]=1;
			quanpai(a+1,b);
			used[i]=0;
		}
	}	
}

