#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); // @@ [Using 'gets' is unsafe and deprecated; more importantly, it may cause undefined behavior, but the main logic errors are elsewhere.]
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ [Loop only goes to 'len-3', so last two characters may not be processed correctly if no '-' is involved. Also, when a '-' expansion occurs near the end, handling is inconsistent.]
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z')))
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++) // @@ [This prints from str[i] to str[i+2]-1, but should print from str[i]+1 to str[i+2]-1. It incorrectly reprints the starting character which was already printed before the loop.]
                {
                    printf("%c",(char)j);
                }
                if(i==len-3)
                {
                    printf("%c",str[i+2]); // @@ [Only prints the ending character if at the very end of string, but in general, the ending character should always be printed after expansion, unless handled elsewhere. However, due to flawed control flow, this leads to missing or duplicated characters.]
                }
                i=i+1; // @@ [Skips the '-' character, but the next character (str[i+2]) may not be printed unless in special case above, leading to omission of the end character in many cases.]
            }
            else
            {
                printf("%c",str[i]); // @@ [If '-' is not expandable, we print str[i], but then the '-' and next char are not handled properly in this branch, causing missing output.]
            }
            
        }
        else
        {
            if(i==len-3)
            {
                printf("%c%c%c",str[i],str[i+1],str[i+2]); // @@ [This tries to handle the last three chars, but if the loop ends early (e.g., len<3), or if previous iterations skipped chars, this causes duplication or incorrect output. Also, if the string has exactly 3 chars and no '-', it works, but overall logic is fragile.]
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
     
    
    
    
    
    
    
    
    
    
    return 0;
}