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
            op_stack[on]=c; // @@ The operator is stored at index 'on', but the number associated with this operator should logically be the one parsed *before* it. However, the current structure stores num_stack[on] = num. For the first number, there is no preceding operator in op_stack[0] in a standard infix sense if we align them this way. More critically, when processing `10 + 20`, `num` becomes 10, then `+` is encountered. `op_stack[0]='+'`, `num_stack[0]=10`. Then `num` resets. Next `20` is parsed. Then `*` or `-` or `=` is encountered. If `=`, `op_stack[1]='='`, `num_stack[1]=20`. This alignment is tricky. Let's look at the calculation logic.
            num_stack[on]=num;
            on++;
            num=0;
        }
    }    
    for(int k=0;k<on;k++){
        if(op_stack[k]=='*'||op_stack[k]=='/'){
            op1[opnum]=on; // @@ Error: It stores 'on' (the total count of operators/numbers pairs) instead of 'k' (the current index of the operator). This causes out-of-bounds access or incorrect index references later. It should be op1[opnum] = k;
            opnum++;
        }
        else if(op_stack[k]=='-'){
            num_stack[k+1]=-(num_stack[k+1]); // @@ Logic Error: This attempts to handle subtraction by negating the next number. This works for simple cases like A - B if treated as A + (-B), but fails if the next operation is multiplication/division due to precedence, or if it's the last number. Also, if op_stack[k] is '-', num_stack[k] is the left operand and num_stack[k+1] is the right operand. Negating num_stack[k+1] effectively turns A - B into A + (-B). This part might be logically intended for converting subtraction to addition, but it interacts poorly with the subsequent sum loop if not all operators are '+'. However, the primary bug causing the wrong answer here is likely the index error above and how division/multiplication results are accumulated.
        }
    }//记录乘除算符的下标,并将减法变为加法运算
    for(int k=0;k<opnum;k++){
        if(op_stack[op1[k]]=='*'){
            num_stack[op1[k]+1]*=num_stack[op1[k]];
        }
        else if(op_stack[op1[k]]=='/'){
            num_stack[op1[k]+1]=num_stack[op1[k]]/num_stack[op1[k]+1];
        }
        num_stack[op1[k]]=0;
    }//合并乘除号两侧的数，运算符前的数置0
    for(int k=0;k<on;k++){
        sum+=num_stack[k];
    }//求和计算
    printf("%d",sum);

    
    
    return 0;
}