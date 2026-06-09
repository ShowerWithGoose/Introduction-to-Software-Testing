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
    gets(expression); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. However, the immediate error in logic is elsewhere.]
    remove_spaces(expression);
    len = strlen(expression);
    for(int t=0;t<len;t++){
        char c=expression[t];
        if (c >= '0' && c <= '9') {
            num = 10*num+(c - '0');
            
    }
        else if(c == '+' || c == '-' || c == '*' || c == '/'||c == '='){
            op_stack[on]=c;
            num_stack[on]=num;
            on++;
            num=0;
        }
    }    
    for(int k=0;k<on;k++){
        if(op_stack[k]=='*'||op_stack[k]=='/'){
            op1[opnum]=on; // @@ [This should store `k`, not `on`. Storing `on` (which is the total count) leads to out-of-bound access later.]
            opnum++;
        }
        else if(op_stack[k]=='-'){
            num_stack[k+1]=-(num_stack[k+1]); // @@ [This modifies `num_stack[k+1]` before it's guaranteed to exist; also, this approach fails when '-' is at the end or followed by '='.]
        }
    }//记录乘除算符的下标,并将减法变为加法运算
    for(int k=0;k<opnum;k++){
        if(op_stack[op1[k]]=='*'){
            num_stack[op1[k]+1]*=num_stack[op1[k]]; // @@ [Because `op1[k]` was incorrectly set to `on`, this accesses invalid indices in `op_stack` and `num_stack`.]
        }
        else if(op_stack[op1[k]]=='/'){
            num_stack[op1[k]+1]=num_stack[op1[k]]/num_stack[op1[k]+1]; // @@ [Same indexing error due to wrong value stored in `op1[k]`. Also, division order is reversed: should be left / right, but here it's right = left / right, which is correct only if operands are in correct positions—but they aren't due to earlier errors.]
        }
        num_stack[op1[k]]=0;
    }//合并乘除号两侧的数，运算符前的数置0
    for(int k=0;k<on;k++){
        sum+=num_stack[k];
    }//求和计算
    printf("%d",sum);

    
    
    return 0;
}