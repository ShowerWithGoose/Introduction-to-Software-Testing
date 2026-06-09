#include<stdio.h>
#include<string.h>
int math(int a, int b, char s) {
	int result;
	if (s == '+') {
		result = a + b;
	} else if (s == '-') {
		result = a - b;
	} else if (s == '*') {
		result = a * b;
	} else if (s == '/') {
		result = a / b;
	}
	return result;
}
int main() {
	char s[10005], s1[10005],sign[10005],jiajian[10005];
	int i,j,num[10005],num0[10005],result;
	gets(s);
	int len;
	len = strlen(s);
	for ( i = 0, j = 0; i < len; i++) {
		if (s[i] != ' ') {
			s1[j] = s[i];
			j++;
		}
	}
	s1[j]='\0';
	int len1;
	len1 = strlen(s1);
	//printf("%d",len1);
	j=0;int k=0;
	//int i =0; 
	for (i = 0; i < len1; ) //存储所有的数字和符号 
	{
	   //printf("%c ",s1[i]);
	   if((s1[i]>='0')&&(s1[i]<='9'))
	    {
	   	    num[j]=s1[i]-'0';
	   	    
	   	    i++;
	   	    while((s1[i]>='0')&&(s1[i]<='9'))
	   	    {
			   	num[j]=num[j]*10+s1[i]-'0';
			   	i++;
			}
			//printf("num is :%d \n",num[j]);
			j++;
	    } else {
	   		//??????
	   		
		    sign[k]=s1[i];
		    //printf("sign is :%c \n",sign[k]);
			k++;	 
			i++;	
		}
	}
	int fuhao; 
	fuhao=k;
	k=0;
	for(i=0;i<j;i++)//算连乘除 
	{
		if((sign[i]=='*')||(sign[i]=='/'))
		{
		  num0[k]=math(num[i],num[i+1],sign[i]);
		  //printf("乘除法 result ：%d\n",num0[k]);
		  i++;
		  while((sign[i]=='*')||(sign[i]=='/'))
		  {
		  	num0[k]=math(num0[k],num[i+1],sign[i]);
		  	
		  	i++;
		  }	
		  //printf("%d\n",num0[k]);
		  k++;
		}
		else
		{
			num0[k]=num[i];
			
			k++;
		} 
		
	}
	
//	for(i=0;i<k;i++)
//	   printf("%d\n",num0[i]);
	j=0;
	for(i=0;i<fuhao;i++)//取加减号 
	{
		if((sign[i]=='+')||(sign[i]=='-'))
		{
		   	jiajian[j]=sign[i];
		   	j++;
		}
	}
	
	//for(i=0;i<j;i++) {
	//	printf("%c\n",jiajian[i]);
	//}
	
	
	result=math(0,num0[0],'+');//??? num0 应该是打错了？ 
	//printf("%d\n",result);
	for(i=0;i<k-1;i++)
	{
		//printf("%c\n",jiajian[i]);
	   //if(jiajian[i]=='-'||jiajian[i]=='+') {//加判断条件 
	   	    result=math(result,num0[i+1],jiajian[i]);
	   //}
	   	
	}
	printf("%d",result);
	return 0;
}

