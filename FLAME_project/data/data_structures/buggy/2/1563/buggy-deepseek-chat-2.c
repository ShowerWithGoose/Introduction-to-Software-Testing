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
            op_stack[on]=c;
            num_stack[on]=num;
            on++;
            num=0;
        }
    }    
    for(int k=0;k<on;k++){
        if(op_stack[k]=='*'||op_stack[k]=='/'){
            op1[opnum]=on; // @@ [错误：这里应该存储当前运算符的索引k，而不是on。on是运算符总数，导致后续访问op_stack[op1[k]]时越界或错误]
            opnum++;
        }
        else if(op_stack[k]=='-'){
            num_stack[k+1]=-(num_stack[k+1]); // @@ [错误：将减法转换为加法时，应该改变当前运算符后的数字符号，但这里改变了num_stack[k+1]的符号，而后续乘除运算会覆盖这个修改，且加法求和时未正确处理负号]
        }
    }//记录乘除算符的下标,并将减法变为加法运算
    for(int k=0;k<opnum;k++){
        if(op_stack[op1[k]]=='*'){
            num_stack[op1[k]+1]*=num_stack[op1[k]]; // @@ [错误：由于op1[k]存储的是on（越界值），这里访问op_stack[op1[k]]和num_stack[op1[k]]都是错误的]
        }
        else if(op_stack[op1[k]]=='/'){
            num_stack[op1[k]+1]=num_stack[op1[k]]/num_stack[op1[k]+1]; // @@ [错误：同上，索引错误；且除法顺序错误，应该是num_stack[op1[k]] / num_stack[op1[k]+1]]
        }
        num_stack[op1[k]]=0;
    }//合并乘除号两侧的数，运算符前的数置0
    for(int k=0;k<on;k++){
        sum+=num_stack[k];
    }//求和计算
    printf("%d",sum);

    
    
    return 0;
}