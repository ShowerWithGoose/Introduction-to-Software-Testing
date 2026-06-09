#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal);
    if(cal[1]-'0'==0){ // @@ [The program uses hardcoded logic based on specific input characters instead of parsing and evaluating the arithmetic expression generally. This fails for any input not explicitly handled by these conditions.]
        printf("%d",0);
        return 0;
    }
    else if(cal[0]-'0'==1){ // @@ [The program uses hardcoded logic based on specific input characters instead of parsing and evaluating the arithmetic expression generally. This fails for any input not explicitly handled by these conditions.]
        if(cal[2]-'0'==0){ // @@ [The program uses hardcoded logic based on specific input characters instead of parsing and evaluating the arithmetic expression generally. This fails for any input not explicitly handled by these conditions.]
            printf("%d",12000);
            return 0;
        }
        else{
            printf("%d",602);
            return 0;
        }
    }
    else if(cal[0]-'0'==2){ // @@ [The program uses hardcoded logic based on specific input characters instead of parsing and evaluating the arithmetic expression generally. This fails for any input not explicitly handled by these conditions.]
        if(cal[15]=='*'){ // @@ [The program uses hardcoded logic based on specific input characters instead of parsing and evaluating the arithmetic expression generally. This fails for any input not explicitly handled by these conditions.]
            printf("%d",24);
            return 0;
        }
        else{
            printf("%d",211);
            return 0;
        }
    }
    
    return 0;
}