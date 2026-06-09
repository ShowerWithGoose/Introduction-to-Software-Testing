#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#define Div 1000000007
#define E 2.71828
#define Pi 3.1415926
#define eps 1e-7
#define ElementType int
#define WeightType int
#define MAXSIZE 10000
char in[MAXSIZE];
int num[MAXSIZE],l,flag=0,t=0,size,wei=0,o=0,p=0; 
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i;
	scanf("%s",in);
	l=strlen(in);
	if(in[0]=='-')
	flag=1;
	for(i=flag;i<l;i++)
	{
		if(in[i]!='0'&&in[i]!='.'){
			t=1;
			if(!p){
				wei=i;
				p=1;
			}
		}
		if(in[i]=='.')o=i;
		if(t&&in[i]!='.'){
			num[++size]=in[i]-'0';
		}
	}
	wei=o-wei-1;
	if(wei<0)
	wei++;
	for(i=1;i<=size;i++)
	if(i==1&&size!=1)
	printf("%d.",num[i]);
	else printf("%d",num[i]);printf("e%d",wei);
	return 0;
}


