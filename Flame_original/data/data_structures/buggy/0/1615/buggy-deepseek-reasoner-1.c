#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); 
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ for loop condition should use i<=len-3 or similar, but main issue is index handling
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z'))) // @@ missing check: str[i] < str[i+2] to ensure expansion is increasing
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++)
                {
                    printf("%c",(char)j);
                }
                if(i==len-3) // @@ this condition only works for the last dash; fails for multiple dashes
                {
                    printf("%c",str[i+2]);
                }
                i=i+1; // @@ i is incremented again by the loop, causing skip of characters after dash
            }
            else
            {
                printf("%c",str[i]);
            }
            
        }
        else
        {
            if(i==len-3) // @@ incorrect logic: prints three characters even when no dash present
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