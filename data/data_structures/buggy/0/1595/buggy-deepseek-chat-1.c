#include <stdio.h>
#include <string.h>
#include <ctype.h>
char str[10000000];
int main()
{
    
    gets(str);
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
           for(int n  =str[i-1]+1;n<str[i+1]+0;n++) // @@ The loop condition should be n < str[i+1] (not str[i+1]+0), and the loop should include the last character. Also, the expansion logic is incorrect: it should print characters from str[i-1]+1 to str[i+1]-1, but the condition n < str[i+1] will stop before str[i+1], which is correct, but the +0 is unnecessary and confusing. However, the main issue is that the loop does not handle the case where str[i+1] is a digit correctly (it prints characters, not digits). Additionally, the loop should be n <= str[i+1]-1 or n < str[i+1] to include all intermediate characters.
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