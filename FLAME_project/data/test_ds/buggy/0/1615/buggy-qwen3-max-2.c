#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); // @@ [Using 'gets' is unsafe and deprecated; more critically, it may cause undefined behavior, but the main logic errors are elsewhere.]
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ [Loop only goes to 'len-3', so last two characters are not properly handled in many cases, causing missing output like in "B-e".]
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z')))
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++) // @@ [This prints from 'm' to 'n-1', but should print from 'm+1' to 'n-1'; also, original character 'str[i]' was already printed before the loop starts, leading to duplication or incorrect sequence.]
                {
                    printf("%c",(char)j);
                }
                if(i==len-3)
                {
                    printf("%c",str[i+2]); // @@ [Only prints the last character in specific case, but logic is inconsistent with general case.]
                }
                i=i+1;
            }
            else
            {
                printf("%c",str[i]); // @@ [When '-' is not expandable (like in "B-e"), this prints only the current char, but doesn't print the '-' and next char, leading to incomplete output.]
            }
            
        }
        else
        {
            if(i==len-3)
            {
                printf("%c%c%c",str[i],str[i+1],str[i+2]); // @@ [This special handling for last three chars is inconsistent and causes duplication or omission depending on context.]
            }
            else
            {
                printf("%c",str[i]);
            }
        }
    }
     
    
    
    
    
    
    
    
    
    
    return 0;
}