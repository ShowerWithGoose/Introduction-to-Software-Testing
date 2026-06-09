#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define  MAXSIZE 100
typedef int;  //can be easily extended to floating point type @@ [Syntax error: typedef requires a type alias name, e.g., 'typedef int DataType;']
enum symbol {NUM, OP, EQ,OTHER};//symbol type
enum oper {EPT,ADD, MIN, MUL, DIV,  LEFT, RIGHT}; //operators, treat parentheses and equals as operators
int Pri[]={-1,0,0,1,1,2,2}; //operator precedence
union sym {
    int num;
    enum oper op;
} ; //symbols are of two types: numbers and operators
int Num_stack[MAXSIZE]; //data stack
enum oper Op_stack[MAXSIZE]; //operator stack
int Ntop=-1; //data stack top pointer, initially empty stack
int  Otop=-1; //operator stack top pointer, initially empty stack
enum symbol getSym( union sym *item);
void operate(enum oper op );
void compute(enum oper op );
void pushNum(double num); @@ [Type mismatch: function declared to take double but stack is int array; also inconsistent with popNum returning int]
int popNum();
void pushOp(enum oper op);
enum oper popOp();
enum oper topOp();
int main()
{
    union sym item;
    enum symbol s;        //read operands and operators before '=' below
    while( (s = getSym(&item)) != EQ){
        if(s == NUM)
            pushNum(item.num);
        else if(s == OP) // handle operators case by case
            operate(item.op);
        else {                 // not operator, operand, or equals; input error
            printf("Error in the expression!\n");
            return 1;
        } 
    }
    while(Otop >=0)             //pop and compute all remaining operators in stack
        compute(popOp());
    if(Ntop == 0)  //normally, operator stack is empty, data stack has one value
        printf("%.2f\n", popNum());   // data stack has only final result @@ [Format specifier %.2f expects double/float, but popNum returns int]
    else                                        // otherwise input error
        printf("Error in the expression!\n");
    return 0;
}
enum symbol getSym( union sym *item){
    int c, n;
    while((c = getchar()) != '=') {
        if(c >= '0' && c <= '9'){
            for(n=0; c >= '0' && c <= '9'; c= getchar())
                n = n*10 + c-'0'; 
            ungetc(c, stdin);   //push back to buffer
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
            tmp = popNum();         //first popped is right operand
            pushNum(popNum() - tmp); break;
        case  MUL: 
            pushNum(popNum() * popNum()); break;
        case DIV: 
            tmp = popNum();        // second popped is left operand
            pushNum(popNum() / tmp); break;
    }
}
void operate(enum oper op ){
    enum oper t;
    if(op != RIGHT){  // not right parenthesis
        while(Pri[op] <= Pri[topOp()] && topOp() != LEFT)
            compute(popOp());
        pushOp(op);
    }
    else  // read right parenthesis
        while((t = popOp()) != LEFT)     // no operation when popping left parenthesis
            compute(t);
}
void pushNum(double num){ @@ [Function defined to take double, but Num_stack is int array; causes implicit conversion and potential data loss]
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
    if(Ntop == MAXSIZE -1) { @@ [Bug: should check Otop, not Ntop, for operator stack overflow]
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