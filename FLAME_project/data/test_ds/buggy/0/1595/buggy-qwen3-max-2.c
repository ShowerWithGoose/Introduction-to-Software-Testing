#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[10000000];
int main()
{
    
    gets(str); // @@ [Using gets() is unsafe and may cause buffer overflow; also, the problem expects to read a single string possibly with spaces? But more critically, the logic below assumes '-' is always between two valid chars, but input like "a-uB-F" has '-' at position 1 and 4, which this loop processes, but the output format is wrong due to printing original string first]
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
   puts(str); // @@ [This prints the modified string with '*' before expanding it, which causes extra output (like "a*uB*F") before the correct expansion. The problem expects only the final expanded string, not intermediate representation.]

  
    for(i=0;i<len;i++) 
    {
        if(str[i] == '*')
        {
           for(int n  =str[i-1]+1;n<str[i+1]+0;n++) // @@ [Loop condition should be n <= str[i+1] to include the end character. Current condition stops before str[i+1], so expansion is incomplete (e.g., a-d becomes abc instead of abcd). Also, note that in the reference program, it prints from str[i] to str[i+2]-1, then skips ahead. Here, the logic is different and flawed.]
           {
                printf("%c",n);
           }
           
        
         }
        else 
        {
            printf("%c",str[i]);
        }
        
        
    }
    return 0 ;
    
}