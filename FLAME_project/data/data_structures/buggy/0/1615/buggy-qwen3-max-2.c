#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the loop logic fails to handle cases where '-' is not part of a valid expansion pattern correctly]
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ [Loop only goes to len-3, so last two characters are not processed properly in many cases, especially when no '-' is involved or at the end]
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z')))
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++) // @@ [This prints from str[i] to str[i+2]-1, but should print from str[i]+1 to str[i+2]-1; also, it fails to print str[i] again because the outer loop already printed it, but then overwrites intended behavior by printing extra chars including possibly wrong start]
                {
                    printf("%c",(char)j);
                }
                if(i==len-3)
                {
                    printf("%c",str[i+2]); // @@ [Only prints the last character in specific case, but inconsistent with general logic; leads to missing characters in other positions]
                }
                i=i+1;
            }
            else
            {
                printf("%c",str[i]); // @@ [When '-' is found but expansion condition fails, this prints str[i], but str[i] was already printed in previous iteration or will be missed later; causes duplication or omission]
            }
            
        }
        else
        {
            if(i==len-3)
            {
                printf("%c%c%c",str[i],str[i+1],str[i+2]); // @@ [This special case tries to print last three chars, but interferes with normal flow and causes duplication or incorrect output when '-' appears near end]
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
     
    
    
    
    
    
    
    
    
    
    return 0;
}