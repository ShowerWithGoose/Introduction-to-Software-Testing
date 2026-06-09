#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); // @@ gets is deprecated and unsafe, may cause compilation errors in modern C standards; use fgets instead.
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ Loop condition i<len-2 incorrectly skips the last two characters, causing incomplete output for strings longer than 3 characters.
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z'))) // @@ Missing condition to verify str[i] < str[i+2] as required by the problem statement.
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++)
                {
                    printf("%c",(char)j);
                }
                if(i==len-3) // @@ Incorrectly restricts printing the expansion's end character only when it's the last triplet; should always print str[i+2] after the loop.
                {
                    printf("%c",str[i+2]);
                }
                i=i+1;
            }
            else
            {
                printf("%c",str[i]); // @@ When expansion conditions fail, only str[i] is printed, leaving '-' and str[i+2] unhandled, resulting in missing output.
            }
            
        }
        else
        {
            if(i==len-3) // @@ Incorrect condition for handling the end of the string; fails to properly output remaining characters for longer strings.
            {
                printf("%c%c%c",str[i],str[i+1],str[i+2]);
            }
            else
            {
                printf("%c",str[i]); // @@ Only prints current character, skipping subsequent characters that should be processed or printed in later iterations.
            }
        }
    }
     
    
    
    
    
    
    
    
    
    
    return 0;
}