#include<stdbool.h>//写在前面：这个版本加了while1方便使用，记得删掉 
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<strings.h>
#include<stdlib.h>
#ifndef stack_h 
#define stack_h
#include <stddef.h> // for size_t

typedef char ele;//栈的类型 

// 定义栈结构体，包含栈顶指针、容量和当前元素数量等信息
typedef struct {
    ele* data;     // 栈内存储数据的数组
    size_t capacity; // 栈的总容量
    size_t count;   // 当前栈内元素数量
}zhan;
// 初始化栈，分配指定容量的内存空间
zhan space(size_t capacity) {
    zhan stack = {0};
    stack.capacity = capacity;
    stack.data = malloc(capacity * sizeof(*stack.data));
    return stack;
}
// 压一个元素进栈
void in(zhan* stack, ele element) {
    stack->data[stack->count++] = element;
}
// 判断栈是否为空
int iskong(const zhan* stack) {
    return stack->count == 0;
}
// 从栈中弹出一个元素
ele out(zhan* stack) {
    // 保存即将弹出的栈顶元素的值
    char top_element = stack->data[stack->count - 1];
    // 弹出操作：减少计数并将栈顶元素置为 '\0'
    stack->data[--stack->count] = '\0';
    // 返回栈顶元素的原值
    return top_element;
}
// 获取栈顶元素（但不弹出）
ele gettop(const zhan* stack) {
    return stack->data[stack->count - 1];
}
#endif // stack_h
char s[100];
int cmp(char a, char b){
    // 定义运算符优先级映射表
    const int priority[] = {
        ['+'] = 1,
        ['-'] = 1,
        ['*'] = 2,
        ['/'] = 2,
    };
    // 比较优先级值
    if(priority[a] >= priority[b]){
        return 1;
    }
    else{
        return 0;
    }
}
double cal(double a, double b, char c) {
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
    }
}
int main(){
    char tmpa;
    int n=0;
    while(scanf("%c",&tmpa)){
        if(tmpa=='='){
            s[n]='=';
            goto next;
        }
        if(tmpa!=' '){
            s[n]=tmpa;
            n++;
        }
    }
    next:;
    s[n+1]='\0';//输入式 
    int a[100];//储存数字 
    char b[100];//储存运算符 
    int num_count = 0;
    int op_count = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (isdigit(s[i])) { // 遇到数字
            int j = i;
            while (isdigit(s[j]) && j < sizeof(s) - 1) { // 扩展到整个数字
                ++j;
            }
            char num_str[j - i + 1];
            strncpy(num_str, &s[i], j - i);
            num_str[j - i] = '\0';
            a[num_count++] = atoi(num_str); // 将数字字符串转换为整数并存入数组
            i = j - 1; // 跳过已处理的数字字符
        } else{ // 遇到运算符
            a[num_count++] = -1; // 在a数组中用-1标记运算符位置
            b[op_count++] = s[i]; // 存储运算符到数组
        }
    }
    a[num_count]=-2;
    //现在已经完成输入，开始改变为后缀运算式
    zhan op=space(100);//操作栈 
    int abac[100];
    char bbac[100];
    int bbac1=0,abac1=0;
    char rubbish;//你不会再用到我的 
    int j=0,bcnt=0;
    while(a[j]!=-2){
        if(a[j]!=-1){
            abac[abac1++]=a[j];//数字进入 
            j++;
        }
        else{
            if(b[bcnt]!=')'){//不是右括号，判断优先级，栈内如果大出栈，直到小或空，栈内小则入栈 
                if(iskong(&op)!=0){//空栈，直接进入 
                    in(&op,b[bcnt++]);//录入当前操作到栈 ，注意这里不用标记 
                    j++;
                    goto again;
                }else{
                    if(b[bcnt]=='('){//左括号，直接进入 
                        in(&op,b[bcnt++]);//录入当前操作到栈 ，注意这里不用标记 
                        j++;
                        goto again;
                    }        
                     else{
                         top:
                        if(cmp(gettop(&op),b[bcnt])>0&&iskong(&op)==0){//栈内优先，出栈（不为空）
                            bbac[bbac1++]=out(&op);//弹出到字符串 
                            abac[abac1++]=-1;//标记运算符 
                            if(iskong(&op)>0||cmp(gettop(&op),b[bcnt])==0){
                                goto fuck;//空栈或优先级高，录入 
                            }
                            goto top;//循环 
                        }
                        fuck:;
                        in(&op,b[bcnt++]);//录入当前操作到栈 ，注意这里不用标记 
                        j++;
                        goto again;
                    }
                        
                }
            }
            else{//右括号，弹出，直到左括号 
                bcnt++; 
                while(gettop(&op)!='('){
                    bbac[bbac1++]=out(&op);//弹出到字符串 
                    abac[abac1++]=-1;//标记运算符 
                }
                rubbish=out(&op);//销毁栈中括号 
                j++;
                goto again;
            }
        }
        again:;
    }
    while(iskong(&op)==0){//栈没清干净
        if(gettop(&op)!='('&&gettop(&op)!='='){
            bbac[bbac1++]=out(&op);//弹出到字符串 
            abac[abac1++]=-1;//标记运算符
        }
        else{
            rubbish=out(&op);
        }
    }//这之后所有的后缀数据记录在了abac和bbac中
    abac[abac1]=-2;//总得有个结尾吧 
    double tmp1,tmp2;
    double num[1000];
    int i=0,num1=0;
    bbac1=0;
    char tre[4];
    while(abac[i]!=-2){
        if(abac[i]!=-1){
            num[num1]=(double)abac[i];//入栈 
            num1++;
            i++;
        }
        else{
            tmp2=num[num1-1];
            num1--;
            tmp1=num[num1-1];
            num1--;//最上面两个出栈 
            num[num1]=cal(tmp1,tmp2,bbac[bbac1]);//计算，结果储存到栈中 
            i++;
            bbac1++;
            num1++;
        }
    }
    printf("%d\n\n",num[0]);//最后栈中只剩下一个结果数据 
    return 0;
}