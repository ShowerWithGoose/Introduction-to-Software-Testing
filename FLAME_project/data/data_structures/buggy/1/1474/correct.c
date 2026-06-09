#include<stdio.h>
int n;
int ma[10]={0};
char s[22];
void math(int g);
int main(){
	scanf("%d",&n);
	math(0);
	return 0;
}
void math(int g){
	int i;
	if(g==2*n)
	{
	    s[g]='\0';
	    puts(s);
	    return;
	}
	for(i=1;i<=n;i++){
		if(ma[i]==0){
			ma[i]=1;
			s[g]='0'+i;
			s[g+1]=' ';
			math(g+2);
			ma[i]=0;

		}
	}
}

