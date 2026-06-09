#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
int main()
{
 char a[1005],b; 
 int i,j,p,m,k;
 gets(a);//读a 
 k=strlen(a);
for(i=0;i<k;i++,j++)
{
if(a[i]=='-')
{
    if(((isupper(a[i+1])&&isupper(a[i-1]))||(islower(a[i+1])&&islower(a[i-1]))||(isdigit(a[i+1])&&isdigit(a[i-1])))&&(a[i+1]>a[i-1]))//如果满足条件 
 	{
 	for(b=a[i-1]+1;b<a[i+1];b++)
    printf("%c",b);
	}
	else{
	b=a[i];
	printf("%c",b);	
	}
}
else {
	b=a[i];
	printf("%c",b);	
	}
 }
 return 0;
}
	



