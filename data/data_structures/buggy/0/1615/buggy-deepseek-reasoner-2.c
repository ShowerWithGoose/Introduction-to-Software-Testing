#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); 
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ incorrect loop bound; does not handle last characters and can skip output
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z'))) // @@ missing check that str[i+2] > str[i] (ascending order)
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++) // @@ if m >= n, loop does nothing; should only run when valid expansion condition holds
                {
                    printf("%c",(char)j);
                }
                if(i==len-3) // @@ fragile hack; fails when expansion not at the end and leaves missing characters
                {
                    printf("%c",str[i+2]);
                }
                i=i+1; // @@ together with for loop increment, skips too many characters
            }
            else
            {
                printf("%c",str[i]);
            }
            
        }
        else
        {
            if(i==len-3)
            {
                printf("%c%c%c",str[i],str[i+1],str[i+2]);
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
    
    
    
    
    
    
    
    
    
    return 0;
}