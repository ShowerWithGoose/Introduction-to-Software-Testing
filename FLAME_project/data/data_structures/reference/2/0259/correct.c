#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int main()
{
int n1=0,n2,n3;
char f1='+',f2,f3;

while(f1!='=')
{
	scanf("%d %c",&n2,&f2);
	while((f2=='/')||(f2=='*'))
	{
	scanf("%d %c",&n3,&f3);
		if(f2=='/')
		n2/=n3;
		else
		n2*=n3;
	f2=f3;
	n3=0;
	}
	if(f1=='-')
	{
	n1-=n2;	
	}
	else
	{
	n1+=n2;	
	}
	f1=f2;
 } 
printf("%d",n1);
return 0;
}

//#include<stdio.h>
//#include<string.h>
//#include<math.h>
//#include<ctype.h>

//int main()
//{
//char a[100]={},b[100]={},c[100]={},d[100]={};
//int i,j,k,number,fuhao,a0=0;
//gets(a);
//for(i=j=k=1;i<=strlen(a);i++)
//{
//	if(a[i]!=NULL)
//	{
//	if(isdigit(a[i]))
//	{
//	b[j]=a[i];
//	j++		;
//	}
//	else
//	{c[k]=a[i];
//	k++;}
//	}//所有数字存在b里，所有符号存在c里 
//a[100]={};
///for	(i=j=k=0;k<=strlen(c);j++)
//{
//	if(c[k]!='*'&&c[j]!='/')
//    a[i]=b[j];
//    else if(c[k]=='*')
//    {
    
//    a[i]=(b[j]-'0')*(b[j+1]-'0')+'0';	
//	}
 
 
 ////} 
	
//}






