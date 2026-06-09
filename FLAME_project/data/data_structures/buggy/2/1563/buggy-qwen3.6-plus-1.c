#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 去除字符串中的空格
void remove_spaces(char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != ' ') {
            str[count++] = str[i];
        }
    }
    str[count] = '\0';
}



int main() {
    char expression[1000];
    char op_stack[500];
    int num_stack[500];
    int op1[500]={0};
    int on=0;
    int opnum=0,sum=0;
    int len=0;
    int num=0;
    // 从标准输入读入整数算术运算表达式
    gets(expression);
    remove_spaces(expression);
    len = strlen(expression);
    for(int t=0;t<len;t++){
        char c=expression[t];
        if (c >= '0' && c <= '9') {
            num = 10*num+(c - '0');
            
    }
        else if(c == '+' || c == '-' || c == '*' || c == '/'||c == '='){
            op_stack[on]=c; // @@ The operator is stored at index 'on', but the number associated with this operator should be the one parsed *before* it. However, the logic here stores the current accumulated 'num' into num_stack[on]. For the first number, there is no preceding operator in op_stack at index 0 if we consider standard infix notation mapping. More critically, when c is '=', the loop stores '=' in op_stack and the last number in num_stack. This mixes operators and operands in parallel arrays indexed by 'on'.
            num_stack[on]=num; // @@ Storing the number at the same index as the operator that follows it (or '='). This creates a structure where op_stack[i] is the operator after num_stack[i].
            on++;
            num=0;
        }
    }    
    for(int k=0;k<on;k++){
        if(op_stack[k]=='*'||op_stack[k]=='/'){
            op1[opnum]=on; // @@ Error: It stores 'on' (the total count) instead of 'k' (the current index of the operator). This causes out-of-bounds access or incorrect index references later.
            opnum++;
        }
        else if(op_stack[k]=='-'){
            num_stack[k+1]=-(num_stack[k+1]); // @@ This handles subtraction by negating the next operand. This is valid for simple left-to-right addition/subtraction if multiplication/division are handled separately, but relies on correct indexing.
        }
    }//记录乘除算符的下标,并将减法变为加法运算
    for(int k=0;k<opnum;k++){
        if(op_stack[op1[k]]=='*'){ // @@ Since op1[k] was incorrectly set to 'on', this accesses op_stack out of bounds or at wrong positions. Even if op1[k] was 'k', the logic below modifies num_stack in place.
            num_stack[op1[k]+1]*=num_stack[op1[k]];
        }
        else if(op_stack[op1[k]]=='/'){
            num_stack[op1[k]+1]=num_stack[op1[k]]/num_stack[op1[k]+1]; // @@ Integer division order: num_stack[op1[k]] is the left operand, num_stack[op1[k]+1] is the right. This is correct for A/B if op is at index of A.
        }
        num_stack[op1[k]]=0; // @@ Zero out the left operand after combining.
    }//合并乘除号两侧的数，运算符前的数置0
    for(int k=0;k<on;k++){
        sum+=num_stack[k];
    }//求和计算
    printf("%d",sum);

    
    
    return 0;
}