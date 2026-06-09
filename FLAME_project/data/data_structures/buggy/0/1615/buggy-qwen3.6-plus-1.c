#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); 
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ The loop condition `i<len-2` causes the loop to terminate before processing the last few characters correctly in all cases, specifically failing to output the trailing part of the string when no expansion happens at the end or when the string ends without a valid expansion pattern involving the last characters. For input "B-e", len is 3. The loop runs for i < 1, so only i=0. Inside, str[1] is '-'. The types don't match ('B' is upper, 'e' is lower). It goes to else, prints 'B'. Then i becomes 1. Loop condition 1 < 1 fails. The characters '-' and 'e' are never printed.
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z')))
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
                printf("%c",str[i]); // @@ When expansion conditions are not met, only the current character `str[i]` is printed. The hyphen `str[i+1]` and the next character `str[i+2]` are skipped in this iteration and not handled correctly in subsequent iterations due to the loop structure and index incrementing, leading to missing output.
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