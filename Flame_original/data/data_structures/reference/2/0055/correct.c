#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main()
{
    int n1,n2,n3;
    char s1,s2,s3;
    n1=0;
    s1='+';
    
    scanf("%d %c",&n2,&s2);//读入
    
    while (1)
    {
        
        if(s2=='*'||s2=='/') 
        {
            
            scanf("%d %c",&n3,&s3);
            
            if(s2=='*') {
	n2=n2*n3;
}
            else if(s2=='/') {
	n2=n2/n3;
}
            s2=s3;           
        }
        
        if(s2=='+'||s2=='-')//加减更新第一个数n1
        {
            if(s1=='+') n1=n1+n2;
            else if(s1=='-') n1=n1-n2;
            
            
            s1=s2;
            scanf("%d %c",&n2,&s2);//读入
            
        }
        
        if(s2=='=')
        {
            if(s1=='+') n1=n1+n2;
            else if(s1=='-') n1=n1-n2;
            
            printf("%d\n",n1);
            break;
            
        }
    }
    
    return 0 ;
}

