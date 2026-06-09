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
                temp=calculate(temp,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){
                left=calculate(left,temp,formerOp); // @@ Incorrect: computes the previous addition/subtraction too early, before processing any multiplication/division after the new operator.
                sscanf(str+i+1,"%d",&right); // @@ Incorrect: reads the number after the new operator, but this number should become the start of a new term, not be used immediately in a subtraction.
                left=calculate(left,right,str[i]); // @@ Incorrect: applies the new operator immediately, ignoring that the right operand may have higher‑precedence operators following.
                cnt=0; // @@ Incorrect: resets the state, causing the next operator to be treated as a first operator, losing the ability to accumulate multiplications/divisions on the current term.
            }
        }

    }

    if(cnt!=0){
        left=calculate(left,temp,formerOp);
    }

    printf("%d\n",left);
    return 0;
}