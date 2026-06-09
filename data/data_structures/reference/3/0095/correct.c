#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    char num[100];
    char result[110];    		 
	int i,j=0;
    int s1,s2;//小数点位置，字符串首个非零数位置  
    int op1=0,op2=0;                
    //op1:小数点位置，op2:首个非零数位置，0：未找到 
    int ex; 
                 
    scanf("%s",num);       
    for(i=0;i<strlen(num);i++)//寻找原小数点与首个非零数的位置 
    {
        if(op1!=0&&op2!=0)
            break;
             
        else if(num[i]=='.')
		{           
            op1=1;
            s1=i;
        }  
        else if(num[i]!='0'&&op2==0)
		{
            op2=1;
            s2=i;
        }  
    }
    //printf("%d %d\n",s1,s2); 
    if(s1-s2>0)//求指数 
        ex=s1-s2-1;
    else if(s2>s1)
        ex=s1-s2;          
 
    for(i=s2;i<strlen(num);++i)//求底数 
    {
        if(num[i]=='.')    
            continue;
        else if(i==s2)//底数小数点位置  
		{                   
            result[j++]=num[i];
			if(num[i+1]!=0)
			{
                //result[j++]=num[i];
                result[j++]='.';   
            }
            //else
                //result[j++]=num[i];
        }
        else
            result[j++]=num[i]; 
    }
    result[j]='\0';
     
    printf("%se%d",result,ex);
    return 0; 
}

