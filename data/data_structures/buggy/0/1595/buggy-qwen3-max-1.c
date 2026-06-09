#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[10000000];
int main()
{
    
    gets(str); // @@ [Using `gets` is unsafe and deprecated; it can cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to a compilation error.]
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
   puts(str);
  
    for(i=0;i<len;i++) 
    {
        if(str[i] == '*')
        {
           for(int n  =str[i-1]+1;n<str[i+1]+0;n++) // @@ [The loop condition `n < str[i+1] + 0` is equivalent to `n < str[i+1]`, which is correct logically, but the use of `int n` inside the for-loop initializer is C99 syntax. If the compiler is set to an older standard (like C89), this will cause a compilation error. Also, note that after replacing '-' with '*', the original surrounding characters are still present, so printing from `str[i-1]+1` to `str[i+1]-1` is correct, but the output includes the original endpoints twice—once from the unchanged string and once from expansion—leading to incorrect output logic, though this is a logical error, not compilation. However, the primary compilation issue is `gets`.]
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