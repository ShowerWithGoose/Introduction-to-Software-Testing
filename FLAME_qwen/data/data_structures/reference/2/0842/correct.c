#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 100
typedef int DataType;
enum symbol
{
    NUM,
    OP,
    EQ,
    OTHER
}; //符号类型
enum oper
{
    EPT,
    ADD,
    MIN,
    MUL,
    DIV,
    LEFT,
    RIGHT
};                                  //运算类型及优先级，元素位置与pri匹配
int Pri[] = {-1, 0, 0, 1, 1, 2, 2}; //运算符优先级
union sym
{
    DataType num;
    enum oper op;
}; //符号值

void error(char *s);
enum symbol getSym(union sym *item);
void operate(enum oper op); //操作运算符
void compute(enum oper op); //进行运算
void pushNum(DataType num);
DataType popNum();
void pushOp(enum oper op);
enum oper popOp();
enum oper topOp();

int Ntop = -1; //数据栈指示器，初始为空栈
int Otop = -1; //运算符指示符

int main()
{
    union sym item;
    enum symbol s;
    while ((s = getSym(&item)) != EQ)
    {
        if (s == NUM)
            pushNum(item.num);
        else if (s == OP)
            operate(item.op);
        else
            error("Error in the expression!");
    }
    while (Otop >= 0) //直到操作符栈为空为止
        compute(popOp());
    if (Ntop == 0) //输出计算结果
        printf("%d\n", popNum());
    else
        error("Error in the expression!");
    return 0;
}

void error(char *s)
{
    fprintf(stderr, "%s\n", s);
    //printf("%s\n", s);
    exit(1);
}

enum symbol getSym(union sym *item)
{
    int c, n;
    while ((c = getchar()) != '=')
    {
        if (c >= '0' && c <= '9')
        {
            for (n = 0; c >= '0' && c <= '9'; c = getchar())
                n = n * 10 + c - '0';
            ungetc(c, stdin);
            item->num = n; //如存123
            return NUM;
        }
        else
            switch (c)
            {
            case '+':
                item->op = ADD;
                return OP;
            case '-':
                item->op = MIN;
                return OP;
            case '*':
                item->op = MUL;
                return OP;
            case '/':
                item->op = DIV;
                return OP;
            case '(':
                item->op = LEFT;
                return OP;
            case ')':
                item->op = RIGHT;
                return OP;
            case ' ':
            case '\t':
            case '\n':
                break;
            default:
                return OTHER;
            }
    }
    return EQ;
}

void operate(enum oper op) //优先级低的不入栈并且直接从数字栈顶层依次取两个数进行计算，提高效率
{
    //逆波兰表达式
    enum oper t;
    if (op != RIGHT)
    {
        while (Pri[op] <= Pri[topOp()] && topOp() != LEFT) //目的是将栈中所有优先级不低于当前op的都输出，即让优先级高或相等的运算符出现在表达式左侧
            compute(popOp());
        pushOp(op);
    }
    else
        while ((t = popOp()) != LEFT)
            compute(t); //直到(出栈
}

void compute(enum oper op)
{
    DataType tmp;
    switch (op)
    {
    case ADD:
        pushNum(popNum() + popNum());
        break;
    case MIN:
        tmp = popNum();
        pushNum(popNum() - tmp);
        break;
    case MUL:
        pushNum(popNum() * popNum());
        break;
    case DIV:
        tmp = popNum();
        pushNum(popNum() / tmp);
        break;
    }
}

//数据栈操作
DataType Num_stack[MAXSIZE]; //数据栈
// int Ntop = -1;               //数据栈指示器，初始为空栈
void pushNum(DataType num)
{
    if (Ntop == MAXSIZE - 1)
        error("Date stack is full");
    Num_stack[++Ntop] = num;
}
DataType popNum()
{
    if (Ntop == -1)
        error("Error in the expression!");
    return Num_stack[Ntop--];
}

//运算符栈操作
enum oper Op_stack[MAXSIZE]; //符号栈
// int Otop = -1;               //运算符指示符
void pushOp(enum oper op)
{
    if (Otop == MAXSIZE - 1)
        error("Operator stack is full!");
    Op_stack[++Otop] = op;
}

enum oper popOp() //弹出栈顶元素
{
    if (Otop != -1)
        return Op_stack[Otop--];
    return EPT;
}

enum oper topOp() //读取栈顶元素但不弹出
{
    return Op_stack[Otop];
}


