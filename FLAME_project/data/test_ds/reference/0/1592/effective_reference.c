#include<stdio.h>
int main()  
{
	int i=0,j=0,k,m=0,flag=0;
	char ch[100000],s[1000000]; //ch是用于输入的数组   s是用于输出的数组 
	j=i;
	scanf("%s",ch);
		for(i=0;ch[i]!='\0';i++)
		{
			if(ch[i]!='-') 
			s[j]=ch[i];
			if(ch[i]=='-')
		    {
				if((ch[i-1]>='0'&&ch[i-1]<='9'&&ch[i+1]>='0'&&ch[i+1]<='9'&&ch[i-1]<ch[i+1])||(ch[i-1]>='a'&&ch[i-1]<='z'&&ch[i+1]>='a'&&ch[i+1]<='z'&&ch[i-1]<ch[i+1])||(ch[i-1]>='A'&&ch[i-1]<='Z'&&ch[i+1]>='A'&&ch[i+1]<='Z'&&ch[i-1]<ch[i+1]))
				{
					k=ch[i+1]-ch[i-1];//计算两个ASCII码差值，得到循环次数 
				    for(m=0;m<k;m++)
				    {
					s[j]=s[j-1]+1;
					j++;
					flag=1;
				    } 
				    if(flag==1)
				    j=j-1;
				    continue;
				    }
			    else
				s[j]=ch[i];		
		    }
		    j++;//无论是哪种情况，都可以继续下次循环		   		    
		}	
	 printf("%s",s);
	 return 0; 
}

