#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define N 1005
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
//scanf记得变量要加&，循环变量记得初始化，break语句写在最后，读清题意，看看变量开int还是longlong
typedef long long ll;
int read();
char Cen[100000];
int isnum(char a,char c){
	return isdigit(a)&&isdigit(c);
}
int isupp(char a,char c){
	return isupper(a)&&isupper(c);
}
int islow(char a,char c){
	return islower(a)&&islower(c); 
}
int main()
{
    scanf("%s",Cen);
   int i=0;
   while(Cen[i]!='\0'){
       if(Cen[i]!='-'){
           printf("%c",Cen[i]);
       }
       else
        if(islow(Cen[i-1],Cen[i+1])||isupp(Cen[i-1],Cen[i+1])){
		int j=1;
		while(Cen[i+1]-Cen[i-1]>j){
			printf("%c",Cen[i-1]+j);
            j++;
		}
	}
	else if(isnum(Cen[i-1],Cen[i+1])) {
		int j=1;
		while(Cen[i+1]-Cen[i-1]>j){
			printf("%d",Cen[i-1]+j-'0');
			j++;
		}
	}
	else{
        printf("%c",Cen[i]);
	}
    i++;
   }
return 0;
}
int read(){
int x=0,f=1,c=getchar();
while(c<'0'||c>'9')(c=='-')?(f=-1):0,c=getchar();
while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
return x*f;
}
