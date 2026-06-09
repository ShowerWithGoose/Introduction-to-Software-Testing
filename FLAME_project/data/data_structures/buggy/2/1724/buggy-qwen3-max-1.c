#include <stdio.h>

void remove_spaces(char str[]){
    int i=0;
    int j=0;
    while(str[i]!='\0'){
        if(str[i]!=' '){
            str[j]=str[i];
            j++;
        }
        i++;
    }
    str[j]='\0';
}

int calculate( int left, int right, char op){
    if(op=='+'){
        return left+right;
    }
    if(op=='-'){
        return left-right;
    }
    if(op=='*'){
        return left*right;
    }
    if(op=='/'){
        return left/right;
    }
    return 0;
}

int main(){
    char str[10000];
    gets(str);

    remove_spaces(str);

    int cnt=0;
    int left,right,temp;
    char formerOp;

    sscanf(str,"%d",&left);

    for(int i=0;str[i]!='=';i++){

        if(cnt==0){
            if(str[i]=='*'||str[i]=='/'){
                sscanf(str+i+1,"%d",&right);
                left=calculate(left,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){
                sscanf(str+i+1,"%d",&temp);
                formerOp=str[i];
                cnt++;
            }
        }else{
            if(str[i]=='*'||str[i]=='/'){
                sscanf(str+i+1,"%d",&right);
                temp=calculate(temp,right,str[i]); // @@ [This line incorrectly assumes that the next number starts immediately after the operator, but it may have already been consumed or overwritten in previous iterations. Also, the parsing logic does not correctly handle multi-digit numbers following operators when scanning from arbitrary positions.]
            }
            if(str[i]=='+'||str[i]=='-'){
                left=calculate(left,temp,formerOp);
                sscanf(str+i+1,"%d",&right); // @@ [Same issue: sscanf reads from str+i+1, but the string hasn't been updated to reflect prior calculations, so it may read stale or incorrect values. The algorithm fails to properly tokenize or update the expression as it evaluates.]
                left=calculate(left,right,str[i]);
                cnt=0;
            }
        }

    }

    if(cnt!=0){
        left=calculate(left,temp,formerOp);
    }

    printf("%d\n",left);
    return 0;
}