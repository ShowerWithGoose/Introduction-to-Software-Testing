#include <stdio.h>
#include <string.h>
int main()
{
    char str[20000];
    int sum,i,len;
     gets(str); // @@ [Using gets() is unsafe and deprecated; more critically, it may cause undefined behavior, but the main logic errors are elsewhere.]
     len = strlen(str);  // 获取字符串长度
     for(i=0;i<len-2;i++) // @@ [Loop only goes to len-3, so last two characters are not handled properly in many cases.]
     {
         if(str[i+1]=='-')
         {
             if(((str[i]>='0')&&(str[i]<='9')&&(str[i+2]>='0')&&(str[i+2]<='9'))||((str[i]>='a')&&(str[i]<='z')&&(str[i+2]>='a')&&(str[i+2]<='z'))||((str[i]>='A')&&(str[i]<='Z')&&(str[i+2]>='A')&&(str[i+2]<='Z')))
             {
                 int m,n;
                m=(int)str[i];
                n=(int)str[i+2];
                int j;
                for(j=m;j<n;j++) // @@ [This prints from str[i] to str[i+2]-1, but should start from str[i]+1 to str[i+2]-1; also misses printing str[i+2] in general cases.]
                {
                    printf("%c",(char)j);
                }
                if(i==len-3)
                {
                    printf("%c",str[i+2]); // @@ [Only prints str[i+2] when at end of string, but should always print it after expansion.]
                }
                i=i+1; // @@ [Skips next character, but logic doesn't account for proper output flow; also, str[i] was never printed before expansion.]
            }
            else
            {
                printf("%c",str[i]); // @@ [Only prints str[i], but doesn't print the '-' or str[i+2]; leads to missing characters.]
            }
            
        }
        else
        {
            if(i==len-3)
            {
                printf("%c%c%c",str[i],str[i+1],str[i+2]); // @@ [Only handles last three chars specially, but this causes duplication or omission in other cases.]
            }
            else
            {
                printf("%c",str[i]); // @@ [Doesn't handle cases where '-' appears later; overall control flow misses many characters.]
            }
        }
    }
     
    
    
    
    
    
    
    
    
    
    return 0;
}