#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char fh[10000];
int num[10000];
int j=1;

int main(){
	fh[0]='+';
    int cnt=0;
    while(fh[j-1]!='='){
    	scanf("%d",&num[cnt++]);
    	char tmp;
	    scanf("%c",&tmp);
    	while(tmp==' ') scanf("%c",&tmp);
	    fh[j++]=tmp;
	}

	int jj=0;
	int b[1000];
	int i;
	for(i=0;i<j;i++){
		if(fh[i]=='+'||fh[i]=='-')
            b[jj++]=i;
	}
	b[jj]=j-1;

	int sum=0;
	int h;
	for(h=0;h<jj;h++){
		int a;
		a=num[b[h]];
		for(i=b[h]+1;i<b[h+1];i++){
			if(fh[i]=='*')
                a*=num[i];
			else if(fh[i]=='/')
                a/=num[i];
		}
		if(fh[b[h]]=='+')
            sum+=a;
		else if(fh[b[h]]=='-')
            sum-=a;
	}
	printf("%d",sum);
	return 0;

}

