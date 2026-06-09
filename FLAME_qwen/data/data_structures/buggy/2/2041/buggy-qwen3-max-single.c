#include<stdio.h>

int main()
{
    //É¨ÃèÁ½±é
    int i,num[10000];
    char op[10000];
    i=0;
    scanf("%d %c",&num[i],&op[i]); // @@ [This assumes every number is immediately followed by an operator with a space, but input may have multiple spaces or no space before '='. Also fails when expression ends with '=', as it tries to read a char after the last number which might be '=' without a following number.]
    while(op[i]!='='){
        i++;
        scanf("%d %c",&num[i],&op[i]); // @@ [Same issue: expects a number and then a char (operator or '=') with a space in between. If input has trailing spaces or irregular spacing, this will fail. Also, after reading '=', there's no next number to read, leading to undefined behavior.]
    }
    for(i=0;op[i]!='=';i++){//µÚÒ»±éÉ¨Ãè 
        if(op[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=0;
            if(i>0){//´«µÝ¼õºÅ 
                op[i]=op[i-1];
            }else{
                op[i]='+';
            } 
        }else if(op[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Division uses current num[i], but if previous operations set num[i] to 0 (e.g., from earlier * or / handling), this leads to incorrect results or division by zero. Also, integer division is required, but logic flow is flawed due to overwriting values prematurely.]
            num[i]=0;
            if(i>0){//´«µÝ¼õºÅ 
                op[i]=op[i-1];
            }else{
                op[i]='+';
            }
        }
    }
    for(i=0;op[i]!='=';i++){
        if(op[i]=='+'){
            num[i+1]=num[i]+num[i+1];
        }else if(op[i]=='-'){
            num[i+1]=num[i]-num[i+1]; // @@ [This left-to-right evaluation ignores operator precedence correctly only if * and / were fully resolved, but due to flawed first pass (setting num[i]=0 and altering op[i]), the second pass operates on corrupted data.]
        }
    }
    printf("%d",num[i-1]); // @@ [Indexing is off: after loop, i equals position of '=', so num[i-1] may not hold final result if expression has only one number or due to incorrect accumulation during passes.]
    return 0;
}