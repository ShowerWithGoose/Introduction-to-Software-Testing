#include <stdio.h>
#include <string.h> 
 
char number[110];
char result[110];
int str; 
   
int main()
{
    int i,j;
    int s1,s2;  
    int f1 = 0;                
    int f2 = 0;
    int index; 
                 
    scanf("%s",number);
    str = strlen(number);
     
    for(i = 0;i < str;++i) 
    {
        if(f1 && f2)
            break;
             
        if(number[i] == '.'){
            s1 = i;
            f1 = 1;
        }  
        else if(number[i] != '0' && !f2){
            f2 = 1;
            s2 = i;
        }  
    }
     
    if(s1-s2 > 0)  
        index = s1-s2-1;
    else if(s2 > s1)
        index = s1-s2;          
 
    j = 0;
    for(i = s2;i < str;++i) 
    {
        if(number[i] == '.')    
            continue;
        else if(i == s2) 
		{
             
            if(number[i+1]){
                result[j++] = number[i];
                result[j++] = '.';   
            }
            else
                result[j++] = number[i];
        }
        else
            result[j++] = number[i]; 
    }
    result[j] = '\0';
     
    printf("%se%d\n",result,index);
    return 0; 
}

