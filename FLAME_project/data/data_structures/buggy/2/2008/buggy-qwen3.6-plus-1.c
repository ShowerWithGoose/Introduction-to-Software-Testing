#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define  MAXSIZE 100
typedef int;  // @@ [Syntax error: typedef requires a name, e.g., typedef int DataType;. This causes compilation failure or undefined behavior for types.]
enum symbol {NUM, OP, EQ,OTHER};//符号类型
enum oper {EPT,ADD, MIN, MUL, DIV,  LEFT, RIGHT}; //运算符，把括号和等号视为运算符
int Pri[]={-1,0,0,1,1,2,2}; //运算符优先级
union sym {
    int num;
    enum oper op;
} ; //符号有两类：运算数和运算符
int Num_stack[MAXSIZE]; //数据栈
enum oper Op_stack[MAXSIZE]; //符号栈
int Ntop=-1; //数据栈顶指示器，初始为空栈
int  Otop=-1; //运算符栈顶指示器，初始为空栈
enum symbol getSym( union sym *item);
void operate(enum oper op );
void compute(enum oper op );
void pushNum(double num); // @@ [Type mismatch: Declaration says double, but definition and usage imply int. Should be void pushNum(int num);]
int popNum();
void pushOp(enum oper op);
enum oper popOp();
enum oper topOp();
int main()
{
    union sym item;
    enum symbol s;        //下面读入等号前的运算数和运算符
    while( (s = getSym(&item)) != EQ){
        if(s == NUM)
            pushNum(item.num);
        else if(s == OP) // 对运算符分情况分别处理
            operate(item.op);
        else {                 // 不是运算符、运算数和等号，输入有问题
            printf("Error in the expression!\n");
            return 1;
        } 
    }
    while(Otop >=0)             //将栈中所有运算符弹出计算
        compute(popOp());
    if(Ntop == 0)  //正常情况下，运算符栈为空，数据栈有一个数据
        printf("%.2f\n", popNum());   // @@ [Format specifier error: popNum returns int, but %.2f expects double. Also problem requires integer output. Should be printf("%d\n", popNum());]
    else                                        // 不然就是输入出问题啦
        printf("Error in the expression!\n");
    return 0;
}
enum symbol getSym( union sym *item){
    int c, n;
    while((c = getchar()) != '=') {
        if(c >= '0' && c <= '9'){
            for(n=0; c >= '0' && c <= '9'; c= getchar())
                n = n*10 + c-'0'; 
            ungetc(c, stdin);   //回退到缓冲区
            item->num = n;
            return NUM;
        }
        else 
            switch(c)  {
                case '+': item->op = ADD; return OP;
                case '-': item->op = MIN; return OP;
                case '*': item->op = MUL; return OP;
                case '/': item->op = DIV; return OP;
                case '(': item->op = LEFT; return OP;
                case ')': item->op = RIGHT; return OP;
                case ' ': case '\t': case'\n': break;
                default: return OTHER;
            }          
    }
    return EQ;
}
void compute(enum oper op ){
    int tmp;
    switch(op) {
        case ADD:
            pushNum(popNum() + popNum()); break;
        case MIN: 
            tmp = popNum();         //先出栈的是右运算数
            pushNum(popNum() - tmp); break;
        case  MUL: 
            pushNum(popNum() * popNum()); break;
        case DIV: 
            tmp = popNum();        // 后出栈的是左运算数
            pushNum(popNum() / tmp); break;
    }
}
void operate(enum oper op ){
    enum oper t;
    if(op != RIGHT){  // 不是右括号
        while(Pri[op] <= Pri[topOp()] && topOp() != LEFT)
            compute(popOp());
        pushOp(op);
    }
    else  // 读入的是右括号
        while((t = popOp()) != LEFT)     // 出栈的是左括号无操作
            compute(t);
}
void pushNum(double num){ // @@ [Type mismatch: Parameter is double, but Num_stack is int array. Implicit conversion truncates. Should be void pushNum(int num)]
    if(Ntop == MAXSIZE -1) {
        printf("Data stack is full!\n");
        exit(1);
    }
    Num_stack[++Ntop] = num;
}
int popNum(){
    if(Ntop == -1) {
        printf("Error in the expression!\n");
        exit(1);
    }
    return Num_stack[Ntop--] ;
}
void pushOp(enum oper op){
    if(Ntop == MAXSIZE -1) { // @@ [Logic error: Checking Ntop (number stack top) instead of Otop (operator stack top) for operator stack overflow.]
        printf("operator stack is full!\n");
        exit(1);
    }
    Op_stack[++Otop] = op;
}
enum oper popOp(){
    if(Otop != -1){ 
        return Op_stack[Otop--] ;
        } 
    return EPT;
}
enum oper topOp(){
    return Op_stack[Otop];
}