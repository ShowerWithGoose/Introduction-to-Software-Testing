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
        scanf("%d %c",&num[i],&op[i]); // @@ [Same issue: expects a space between number and next token; if input ends like "5=", this will fail to read correctly because "%d %c" requires a non-whitespace char after optional spaces, but '=' might not be preceded by space. Also, if there are extra spaces, it may skip tokens incorrectly.]
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
    printf("%d",num[i-1]); // @@ [After the loop, i is the index of '=', so num[i-1] is the last computed value only if all operations were applied correctly. However, due to incorrect parsing and overwriting in first pass, the final result may be wrong. Also, if expression has only one number (e.g., "5 ="), then i=0, op[0]='=', loop doesn't run, and num[i-1] accesses num[-1] → undefined behavior.]
    return 0;
}