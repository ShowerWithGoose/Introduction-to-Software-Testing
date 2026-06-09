#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); 
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ Loop bound is i < len-2, which only processes indices 0 to len-3. For input "B-e" (len=3), the loop runs only for i=0, missing the '-' and 'e'. Should be i < len to cover all characters.
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z'))) // @@ Missing condition to check that str[i] < str[i+2]. The problem requires expansion only when the left character is less than the right character. Without this check, invalid expansions like "B-A" would be processed.
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++)
                {
                    printf("%c",(char)j);
                }
                if(i==len-3) // @@ This condition only prints str[i+2] when the expansion is exactly at the end of the string. However, due to the loop bound and increment logic, characters after an expansion that is not at the end may be lost. A better approach is to let the main loop handle printing the right character.
                {
                    printf("%c",str[i+2]);
                }
                i=i+1;
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