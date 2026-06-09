#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); // @@ gets() is removed in C11 standard, causing compilation error; use fgets() instead.
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ Loop condition i < len - 2 prevents processing the last two characters correctly and causes missed output.
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z'))) // @@ Missing condition to check if str[i+2] > str[i] as required by the problem.
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++)
                {
                    printf("%c",(char)j);
                }
                if(i==len-3)
                {
                    printf("%c",str[i+2]);
                }
                i=i+1;
            }
            else
            {
                printf("%c",str[i]); // @@ Only prints str[i], failing to output the '-' and the following character when expansion conditions are not met.
            }
            
        }
        else
        {
            if(i==len-3) // @@ Incorrect boundary handling; this condition causes duplicate printing or out-of-bounds access.
            {
                printf("%c%c%c",str[i],str[i+1],str[i+2]); // @@ Unconditionally prints three characters, which is logically flawed and may access memory out of bounds.
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
     
    
    
    
    
    
    
    
    
    
    return 0;
}