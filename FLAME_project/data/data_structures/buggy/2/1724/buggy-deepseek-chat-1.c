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
                left=calculate(left,temp,formerOp);
                sscanf(str+i+1,"%d",&right);
                left=calculate(left,right,str[i]); // @@ [Error: When encountering a '+' or '-' after already processing a previous '+' or '-', this code incorrectly combines the new operator with the previous left value, but it fails to reset the state properly for subsequent operators. For example, in "10+20*30-40/5", after processing '+', it sets cnt=1 and stores temp=20. Then it processes '*', updating temp to 600. When it encounters '-', it calculates left=10+600=610, then reads right=40, and calculates left=610-40=570. Then it continues the loop and encounters '/', but since cnt is now 0, it treats '/' as a high-priority operator and calculates left=570/5=114, which is wrong because the division should have been done before the subtraction. The algorithm fails to correctly handle the order of operations when multiple low-priority operators are present.]
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