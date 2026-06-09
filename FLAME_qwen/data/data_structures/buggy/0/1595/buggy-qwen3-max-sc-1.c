#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[10000000];
int main()
{
    
    gets(str); // @@ [Using gets() is unsafe and deprecated; it can cause buffer overflow. Also, in many modern environments, gets() is not available, which may lead to compilation errors.]
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
   puts(str); // @@ [This prints the modified string with '*' before expansion, which is incorrect output format. The problem requires only the final expanded string to be printed.]
  
    for(i=0;i<len;i++) 
    {
        if(str[i] == '*')
        {
           for(int n  =str[i-1]+1;n<str[i+1]+0;n++) // @@ [The loop condition should be n <= str[i+1] to include the end character. Also, using 'n<str[i+1]+0' is equivalent to 'n<str[i+1]', which excludes the upper bound, leading to incomplete expansion (e.g., a-d becomes abc instead of abcd).]
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