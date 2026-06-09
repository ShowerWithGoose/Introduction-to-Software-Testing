#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[10000000];
int main()
{
    
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; also, it's deprecated. More importantly, the logic below assumes that '-' is replaced with '*' only when valid expansion applies, but original characters around '-' are still printed later, causing duplication.]
    int i,len;
    len = strlen(str);

    for(i=1;i<len-1;i++)    //  0[1  ~len-2]  len-1
    {
       if(str[i]=='-')
       {
       
           
            if(islower(str[i-1]) && islower(str[i+1]) &&str[i-1] - 'a' < str[i+1] -'a')
            {
                
                str[i] = '*';     
         }
         
         if(isupper(str[i-1]) && isupper(str[i+1]) && str[i-1] - 'A' < str[i+1] -'A')
            {
                    str[i] = '*';         
         }
        
         
         if(isdigit(str[i-1]) && isdigit(str[i+1]) &&str[i-1] - '0' < str[i+1] -'0')
            {
                str[i] = '*';         
         }
       }
    
    }
   puts(str); // @@ [This prints the modified string with '*' in place of '-', which is not part of expected output. The problem requires only the final expanded string to be printed, not intermediate representation.]

  
    for(i=0;i<len;i++) 
    {
        if(str[i] == '*')
        {
           for(int n  =str[i-1]+1;n<str[i+1]+0;n++) // @@ [Loop condition should be n <= str[i+1] to include the ending character. Current condition stops before str[i+1], so expansion is incomplete (e.g., a-d becomes abc instead of abcd). Also, using str[i+1]+0 is redundant and misleading.]
           {
                printf("%c",n);
           }
           
        
         }
        else 
        {
            printf("%c",str[i]); // @@ [This prints the original characters including those adjacent to '-', leading to duplication. For example, in "a-u", after replacing '-' with '*', the loop prints 'a', then expands from 'a'+1 to 'u'-1, but 'u' is printed again when i reaches its position. So 'a' and 'u' appear twice.]
        }
        
        
    }
    return 0 ;
    
}