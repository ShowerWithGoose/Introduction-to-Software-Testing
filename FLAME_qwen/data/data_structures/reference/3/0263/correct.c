#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int main(){
	char str[120],*find=NULL;
	int i,n,k=0,hold;
	gets(str);
	find=strchr(str,'.');
	n=strlen(str);//总长度（带小数点） 
	if(find==NULL)
	{
		if(n==1)//无小数点：一位整数
			{printf("%c",str[0]);
			printf("e0");}
		else//无小数点：多位整数
		{printf("%c",str[0]);
		printf(".");
		for(i=1;i<n;i++)
		printf("%c",str[i]);
		printf("e%d",n-1); 
		}	
	} 
	else{
		if(str[0]=='0')//有小数点：整数为0，小数有0 
		{if(str[2]=='0'){
		for(i=3;i<n;i++) 
		if(str[i]!='0'){
			k=i-1;
			break;
		}
			if(n-k-2==0)//输出一位
			{
				printf("%c",str[k+1]);
				printf("e-%d",k);
			}
			else if(n-k-2!=0)//输出多位 
			{
				printf("%c",str[k+1]);
				printf(".");
				for(i=k+2;i<n;i++)
				printf("%c",str[i]);
				printf("e-%d",k);
			}}
		else//有小数点：整数为0，小数无0
			{
				if(n==3)
				printf("%c",str[2]);
				else{
				printf("%c",str[2]);
				printf(".");
				for(i=3;i<n;i++)
				printf("%c",str[i]);}
				printf("e-1"); 
			}
		}
		else//有小数点：整数不为零
		{
			if(str[1]=='.')//一位整数 
				{
				for(i=0;i<n;i++)
				printf("%c",str[i]);
				printf("e0"); }
			else//多位整数 
			{
				for(i=0;str[i]!='.';i++)
				hold=i;
				k=hold;
				printf("%c",str[0]);
				printf(".");
				for(i=1;i<=hold;i++)
				printf("%c",str[i]);
				for(i=hold+2;i<n;i++)
				printf("%c",str[i]);
				printf("e%d",k); }
		} 
	}
	return 0; 
}
//无小数点：
//			一位整数：输出原字符串*e0 
//			多位整数：输出一位整数的小数*ek k=长度-1
//有小数点： 
	//整数为0：小数有0：输出非0数*e-k k=0的数量+1（输出一位数or多位数） 
	//         小数无0：输出非0数*e-1 
	//整数不为零：一位整数：输出原字符串*e0
	//			  多位整数：输出一位整数的小数*ek k=小数点的位置-1 

