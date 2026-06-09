#include<stdio.h>

int main()
{
    //É¨ÃèÁ½±é
    int i,num[10000];
    char op[10000];
    i=0;
    scanf("%d %c",&num[i],&op[i]); // @@ [This assumes every number is immediately followed by an operator with a space, but the input may have multiple spaces or no space before '=', leading to incorrect parsing. Also, it reads '=' as an operator into op[i], which breaks logic.]
    while(op[i]!='='){
        i++;
        scanf("%d %c",&num[i],&op[i]); // @@ [Same issue: assumes consistent spacing and that every token pair is "number space operator", which fails when spaces are irregular or at end near '='.]
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
    printf("%d",num[i-1]); // @@ [After the loop, i equals the index of '=', so num[i-1] is the last number, but due to flawed parsing and transformation in first pass, the accumulated result may not be correctly stored here. Also, if expression has only one number (e.g., "5 ="), this prints num[-1] which is undefined behavior.]
    return 0;
}