#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[10000000];
int main()
{
    
    gets(str); // @@ gets is removed in the C11 standard and causes compilation errors in modern compilers; use scanf("%s", str) or fgets instead.
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
   puts(str); // @@ This line outputs the intermediate string containing '*' characters, which violates the output format requirement and should be removed.
  
    for(i=0;i<len;i++) 
    {
        if(str[i] == '*')
        {
           for(int n  =str[i-1]+1;n<str[i+1]+0;n++)
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