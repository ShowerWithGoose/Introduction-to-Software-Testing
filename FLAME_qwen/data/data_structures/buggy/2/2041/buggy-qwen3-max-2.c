#include<stdio.h>

int main()
{
    //É¨ÃèÁ½±é
    int i,num[10000];
    char op[10000];
    i=0;
    scanf("%d %c",&num[i],&op[i]); // @@ [This assumes every number is immediately followed by an operator with a space, but input may have multiple spaces or no space before '='. Also fails to handle cases where '=' directly follows a number without a space.]
    while(op[i]!='='){
        i++;
        scanf("%d %c",&num[i],&op[i]); // @@ [Same issue: assumes consistent spacing and that every token pair is "number space operator", which may not hold near the '=' or with irregular spacing.]
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
            num[i+1]=num[i]/num[i+1];
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
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[i-1]); // @@ [After the loop, i equals the index of '=', so num[i-1] is the last computed value only if the expression ends correctly. However, due to incorrect parsing and handling of operators (especially precedence and propagation), the final result may be wrong. Also, if the expression has only one number, i=0 and op[0]='=', then the first while loop doesn't run, but the second for-loop also doesn't run, and i remains 0, so num[-1] would be accessed — but actually in that case, the first scanf reads the number and '=', so i=0, op[0]='=', so the while loop is skipped, then the for loops are skipped, and printf prints num[-1] → undefined behavior.]
    return 0;
}