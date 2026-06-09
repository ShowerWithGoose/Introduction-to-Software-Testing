#include<stdio.h>

int main()
{
    //É¨ÃèÁ½±é
    int i,num[10000];
    char op[10000];
    i=0;
    scanf("%d %c",&num[i],&op[i]); // @@ [This assumes every number is followed by a space and then an operator, but the input may have multiple spaces or no space before '='. Also, when reading the last number before '=', there's no following operator to read with "%c", leading to undefined behavior.]
    while(op[i]!='='){
        i++;
        scanf("%d %c",&num[i],&op[i]); // @@ [Same issue: expects a space and a character after every number, but the expression ends with '=', which may not be preceded by a space, and trying to read past the '=' causes problems. Additionally, if input has consecutive spaces, "%c" will read a space as the operator.]
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
    printf("%d",num[i-1]); // @@ [After the loop, i equals the index of '=', so num[i-1] is the last computed value only if the expression has at least one operator. However, if the expression is just "5 =", then i=0, op[0]='=', loop doesn't run, and num[i-1] accesses num[-1], causing undefined behavior.]
    return 0;
}