#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <time.h>
#define MAX(x,y) x>y?x:y
#define MIN(x,y) x<y?x:y
#define MAXN 1009
//define mst(s) memset(s,0,sizeof(s))
char s[MAXN],c[MAXN];
int i,j,k,n,m,result=0,number=0,cntnum=0,cntop=1,a[MAXN],b[MAXN];
int op[MAXN];
int fun(int a,int b,char op);
/*int getnum(char *p){
	int i=0,_result=0;
	if(!isdigit(p[i])){
		i++;
	}else;
	for(;p[i]!='\0'&&p[i]!='='&&p[i]!='+'&&p[i]!='-'&&p[i]!='*'&&p[i]!='/';i++){
		if(isdigit(p[i])){
			_result=_result*10+p[i]-'0';
		}else;
	}
	return _result;
}*/
int main(void)
{
	//freopen("in.example1c.txt","r",stdin);
	gets(s);
	for(i=0,j=0; s[i]!='\0'; i++) {
		if(s[i]==' ') {
			;
		} else {
			c[j++]=s[i];
		}
	}
	c[j]='\0';
	op[0]=1;
	for(i=0; c[i]!='='; i++) {
		if(c[i]=='+'||c[i]=='-') {
			if(c[i]=='+'){
				op[cntop++]=1;
			}else{
				op[cntop++]=-1;
			}
		} else if(c[i]=='*'||c[i]=='/') {
			int temp1=a[cntnum-1],temp2=0;
			char tempop=c[i];
			for(j=1; c[i+j]!='+'&&c[i+j]!='-'&&c[i+j]!='='; j++) {
				if(isdigit(c[i+j])){
					while(isdigit(c[i+j])){
						temp2=temp2*10+c[i+j]-'0';
						j++;
					}
					temp1=fun(temp1,temp2,tempop);
					temp2=0;
					j--;
				}else{
					tempop=c[i+j];
				}
			}
			a[cntnum-1]=temp1;
			i=i+j-1;
		} else {
			while(isdigit(c[i])) {
				number=number*10+c[i++]-'0';
			}
			a[cntnum++]=number;
			number=0;
			i--;
		}
	}
	cntnum--;
	cntop--;
	for(i=0; i<=cntnum; i++) {
		result+=op[i]*a[i];
	}
	printf("%d",result);

	return 0;
}

int fun(int a,int b,char op)
{
	if(op=='+') {
		return a+b;
	} else if(op=='-') {
		return a-b;
	} else if(op=='*') {
		return a*b;
	} else {
		return a/b;
	}
}


