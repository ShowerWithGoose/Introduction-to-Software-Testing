#include<stdio.h>

int main()
{
    //É¨ÃèÁ½±é
    int i,num[10000];
    char op[10000];
    i=0;
    scanf("%d %c",&num[i],&op[i]);
    while(op[i]!='='){
        i++;
        scanf("%d %c",&num[i],&op[i]);
    }
    for(i=0;op[i]!='=';i++){//µÚÒ»±éÉ¨Ãè
        if(op[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=0; // @@ Setting the left operand to 0 causes incorrect results when the preceding operator is '-', as it changes the operation to '0 - x' instead of preserving the value.
            if(i>0){//´«µÝ¼õºÅ
                op[i]=op[i-1]; // @@ Propagating the previous operator is incorrect; after multiplication/division, the operator should be set to '+' to correctly accumulate the result in the next pass.
            }else{
                op[i]='+';
            }
        }else if(op[i]=='/'){
            num[i+1]=num[i]/num[i+1];
            num[i]=0; // @@ Same as above, zeroing the left operand breaks subsequent subtraction operations.
            if(i>0){//´«µÝ¼õºÅ
                op[i]=op[i-1]; // @@ Same as above, should be set to '+' instead of copying the previous operator.
            }else{
                op[i]='+';
            }
        }
    }
    for(i=0;op[i]!='=';i++){
        if(op[i]=='+'){
            num[i+1]=num[i]+num[i+1];
        }else if(op[i]=='-'){
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[i-1]); // @@ Potential out-of-bounds access if i=0 (e.g., input "5 ="), and due to flawed accumulation logic, it may not print the correct final result.
    return 0;
}