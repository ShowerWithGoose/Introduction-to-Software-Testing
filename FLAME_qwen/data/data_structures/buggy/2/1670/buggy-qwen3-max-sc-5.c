#include<stdio.h>
#include<string.h>
int main()
{
    int num[10005],num1[10005]={0};
    int i=0,sum=0,m;
    char str[10005];
    while(1){
        scanf("%d %c",&num[i],&str[i]);
        if(str[i]=='='){
            break;
        }
        i++;
    }
    m=strlen(str); // @@ [strlen counts up to the null terminator, but str may not be null-terminated because it's filled via %c reads without adding '\0'. This leads to undefined behavior.]
    for(i=0;i<m;i++){
        num1[i]=num[i];
        if(str[i-1]=='*'){ // @@ [On the first iteration (i=0), str[i-1] accesses str[-1], which is out-of-bounds memory access — undefined behavior.]
            num1[i]=num1[i-1]*num[i];
            num1[i-1]=0;
        }
        else if(str[i-1]=='/'){ // @@ [Same as above: when i=0, str[-1] is accessed — invalid memory access.]
            num1[i]=num[i]/num1[i-1]; // @@ [Division order is reversed: should be num1[i-1]/num[i], not num[i]/num1[i-1]. Also, num1[i-1] might be 0 due to prior zeroing, causing division by zero or incorrect logic.]
            num1[i-1]=0;
        }
    }
    for(i=0;i<m;i++){
        if(str[0]=='*'||str[0]=='/'){
            str[0]='+'; // @@ [This only fixes the first operator, but doesn't handle general precedence correctly. Also, modifying str[0] here doesn't align with later logic that assumes original operators.]
        }
        if(i>0){
            if(str[i-1]=='+'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='+'; // @@ [This uses == (comparison) instead of = (assignment). So it does nothing. Should be str[i] = '+'. Same issue below.]
            }
            else if(str[i-1]=='-'&&(str[i]=='*'||str[i]=='/')){
                str[i]=='-'; // @@ [Same error: == instead of =, so no assignment occurs.]
            }
        }
    }
    for(i=1;i<m;i++){
        sum=num1[0]; // @@ [sum is reset to num1[0] in every iteration, so previous accumulations are lost. Should initialize sum once before the loop.]
        if(str[i-1]=='+'){
            sum=sum+num1[i];    
        }
        else if(str[i-1]=='-'){
            sum=sum-num1[i];
        }
        if(str[i]=='='){ // @@ [The '=' is at index i where the loop breaks during input, but m = strlen(str) may not include it properly due to missing null terminator. Also, this check inside the loop may never trigger if '=' isn't at position i during this pass.]
            printf("%d",sum);
        }
    }
    return 0;
}