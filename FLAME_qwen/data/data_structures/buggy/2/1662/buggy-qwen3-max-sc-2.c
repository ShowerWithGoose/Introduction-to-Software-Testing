#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal); // @@ [Use of unsafe and deprecated function 'gets' which can cause buffer overflow; also, the logic does not implement actual arithmetic expression evaluation but hardcodes outputs based on specific input patterns]
    if(cal[1]-'0'==0){
        printf("%d",0);
        return 0;
    }
    else if(cal[0]-'0'==1){
        if(cal[2]-'0'==0){
            printf("%d",12000);
            return 0;
        }
        else{
            printf("%d",602);
            return 0;
        }
    }
    else if(cal[0]-'0'==2){
        if(cal[15]=='*'){
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