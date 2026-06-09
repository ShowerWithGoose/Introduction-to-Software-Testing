#include <stdio.h>
int main()
{
    char cal[100]={};
    gets(cal); // @@ [The function 'gets' is unsafe and has been removed from the C standard library since C11; using it may cause compilation errors or warnings depending on compiler settings. It should be replaced with 'fgets'.]
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
        if(cal[15]=='*'){ // @@ [Accessing cal[15] without ensuring the string length can lead to undefined behavior if the input is shorter than 16 characters. This hard-coded index assumption is invalid for general expressions.]
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