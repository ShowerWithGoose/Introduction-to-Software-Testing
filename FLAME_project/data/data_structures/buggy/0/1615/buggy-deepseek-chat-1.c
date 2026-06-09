#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); 
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++)
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
                printf("%c",str[i]); // @@ This prints str[i] when expansion is invalid, but the logic for handling non-expansion cases is flawed. For input "B-e", when i=0, str[0]='B', str[1]='-', str[2]='e', the condition fails because types differ, so it prints 'B'. However, the loop then increments i to 1, and the next iteration (i=1) prints str[1]='-', but the loop condition i<len-2 (i<1) fails, so str[2]='e' is never printed. The expected output is "B-e", meaning all three characters should be printed when expansion is invalid.
            }
            
        }
        else
        {
            if(i==len-3)
            {
                printf("%c%c%c",str[i],str[i+1],str[i+2]); // @@ This condition only handles the last three characters when there is no dash at position i+1, but it does not correctly handle cases where a dash exists but expansion is invalid. For "B-e", when i=0, str[1] is '-', so this else branch is not taken. The logic fails to output the full string when expansion is not performed.
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
     
    
    
    
    
    
    
    
    
    
    return 0;
}