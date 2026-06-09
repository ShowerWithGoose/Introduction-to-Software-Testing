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
    gets(str); // @@ [gets() is unsafe and deprecated; it can cause buffer overflow and is not standard C. Use fgets() instead.]

    remove_spaces(str);

    int cnt=0;
    int left,right,temp;
    char formerOp;

    sscanf(str,"%d",&left); // @@ [This only reads the first number; if the expression starts with a negative number (e.g., -5+3), it will fail because sscanf with %d will not consume the '-' sign as part of the number correctly in this context.]

    for(int i=0;str[i]!='=';i++){ // @@ [The loop iterates over characters, but the logic for parsing numbers and operators is flawed. It does not properly skip over digits after reading them, leading to incorrect operator detection and potential out-of-bounds access.]

        if(cnt==0){
            if(str[i]=='*'||str[i]=='/'){
                sscanf(str+i+1,"%d",&right); // @@ [sscanf may read more than one number if there are multiple digits, but the loop index i is not updated to skip the digits, causing the same digits to be processed again as operators.]
                left=calculate(left,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){
                sscanf(str+i+1,"%d",&temp); // @@ [Same issue: sscanf reads the next number but i is not advanced past the digits, so the loop will try to interpret digits as operators.]
                formerOp=str[i];
                cnt++;
            }
        }else{
            if(str[i]=='*'||str[i]=='/'){
                sscanf(str+i+1,"%d",&right); // @@ [Same issue: i not updated after reading number.]
                temp=calculate(temp,right,str[i]);
            }
            if(str[i]=='+'||str[i]=='-'){
                left=calculate(left,temp,formerOp);
                sscanf(str+i+1,"%d",&right); // @@ [Same issue: i not updated.]
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