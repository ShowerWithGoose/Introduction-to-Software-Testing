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
    gets(str); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow. Use fgets() instead.]

    remove_spaces(str);

    int cnt=0;
    int left,right,temp;
    char formerOp;

    sscanf(str,"%d",&left); // @@ [This only reads the first number; if the expression starts with a negative number (e.g., -5+3), it will fail because sscanf with %d will not consume the '-' as part of the number correctly in this context.]

    for(int i=0;str[i]!='=';i++){ // @@ [The loop iterates over characters, but the logic for handling operators and numbers is flawed. It does not correctly skip over digits after reading them, leading to incorrect processing of multi-digit numbers and operator precedence.]

        if(cnt==0){
            if(str[i]=='*'||str[i]=='/'){
                sscanf(str+i+1,"%d",&right); // @@ [sscanf here may read the same number multiple times or skip characters incorrectly because the loop index i is not advanced past the digits read.]
                left=calculate(left,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){
                sscanf(str+i+1,"%d",&temp); // @@ [Same issue as above; sscanf does not advance i, so the loop will re-process the same digits.]
                formerOp=str[i];
                cnt++;
            }
        }else{
            if(str[i]=='*'||str[i]=='/'){
                sscanf(str+i+1,"%d",&right); // @@ [Same sscanf issue; also, the logic for handling * and / after a + or - is incomplete—it does not correctly handle multiple consecutive * or / operations.]
                temp=calculate(temp,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){
                left=calculate(left,temp,formerOp);
                sscanf(str+i+1,"%d",&right); // @@ [Same sscanf issue; also, this resets cnt to 0 but does not properly handle the new operator and number, potentially losing the right operand.]
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