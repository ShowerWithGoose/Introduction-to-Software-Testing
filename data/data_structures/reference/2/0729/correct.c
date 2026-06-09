#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ll long long
int stack[50000];
int symjudg(int,int);
int numget(int ,int);
char s[50000];

int main(){
	
	int i=0;
	do{
		scanf("%c",&s[i]);
		if(s[i]!=' ') i++;
	}while(s[i-1]!='\n');
	int len=i-1;
	int z=0;
	//i of stack
	i=0;
	int j;
	i=numget(0,0);
	z++;
	while(i<len-1){
		j=i;
		//maintain the place of sym
		i++;
		i=numget(i,z);
		z=symjudg(j,z);
	}
	int ans=0;
	for(int k=0;k<=z;k++){
		ans+=stack[k];
	}
	printf("%d",ans);
	return 0;
}

int numget(int x,int y){
	//y = z, x = i;
	do{
		stack[y]=stack[y]*10+(s[x]-'0');
		x++;
	}while(s[x]<='9'&&s[x]>='0');
	
	return x;
}

int symjudg(int x,int y){
	//x = j,y =z of stack
	if(s[x]=='+'){
		y++;
	}
	else if(s[x]=='-') {
		stack[y]*=-1;
		y++;
	}
	else if(s[x]=='*'){
		stack[y-1]*=stack[y];
		stack[y]=0;
	}
	else if(s[x]=='/'){
		stack[y-1]/=stack[y];
		stack[y]=0;
	}
	return y;
}

