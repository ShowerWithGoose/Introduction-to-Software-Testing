#include <stdio.h>


char s[10005];
int main(){
    scanf("%s",s);
    int i,pow;
    if(s[1] == '.'&&s[0] == '0'){
        for(i=2;s[i] == '0';i++);
        pow =i;
        putchar(s[i++]);
        if(s[i] != '\0'){
            printf(".");
            for(;s[i] != '\0';i++){
                putchar(s[i]);
            }
        }
        printf("e-%d",pow-1);
    }
    else{
       putchar(s[0]);
       if(s[1] != '\0'&& s[1] != '.'){
           putchar('.');
           for(i=0;s[1+i] != '\0'&& s[i+1] != '.';i++){
               putchar(s[i+1]);
           }
           pow = i;
           if(s[i+1] == '.')
           i++;
           for(;s[i+1] != '\0';i++)
           putchar(s[i+1]);
        }
        else if(s[1] == '.'){
            pow = 0;
            putchar('.');
            for(i=2;s[i] != '\0';i++)
            putchar(s[i]);
        }
        else
            pow = 0;
        
        printf("e%d",pow);

        
    }
    return 0;

}
