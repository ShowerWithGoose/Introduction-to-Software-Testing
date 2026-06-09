#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define  MAXSIZE 100
typedef int;  //can be easily extended to floating point // @@ incomplete typedef; should be `typedef int DataType;` (not used, but syntactically invalid)
enum symbol {NUM, OP, EQ,OTHER};//symbol type
enum oper {EPT,ADD, MIN, MUL, DIV,  LEFT, RIGHT}; //operators, treat brackets and equal sign as operators
int Pri[]={-1,0,0,1,1,2,2}; //operator priority
union sym {
    int num;
    enum oper op;
} ; //two types of symbols: operands and operators
int Num_stack[MAXSIZE]; //data stack
enum oper Op_stack[MAXSIZE]; //operator stack
int Ntop=-1; //data stack top indicator, initially empty
int  Otop=-1; //operator stack top indicator, initially empty
enum symbol getSym( union sym *item);
void operate(enum oper op );
void compute(enum oper op );
void pushNum(double num);
int popNum();
void pushOp(enum oper op);
enum oper popOp();
enum oper topOp();
int main()
{
    union sym item;
    enum symbol s;        //read the operands and operators before the equal sign
    while( (s = getSym(&item)) != EQ){
        if(s == NUM)
            pushNum(item.num);
        else if(s == OP) // handle operators separately
            operate(item.op);
        else {                 // not operator, operand, or equal sign, input error
            printf("Error in the expression!\n");
            return 1;
        } 
    }
    while(Otop >=0)             //pop all operators in the stack and compute
        compute(popOp());
    if(Ntop == 0)  //normally, operator stack empty, data stack has one value
        printf("%.2f\n", popNum());   // data stack has only the final result // @@ popNum() returns int but %f expects double; should use %d for integer output
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
            ungetc(c, stdin);   //return to buffer
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
            tmp = popNum();         //the first popped is the right operand
            pushNum(popNum() - tmp); break;
        case  MUL: 
            pushNum(popNum() * popNum()); break;
        case DIV: 
            tmp = popNum();        // the later popped is the left operand
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
    else  // read a right parenthesis
        while((t = popOp()) != LEFT)     // popping left parenthesis does nothing
            compute(t);
}
void pushNum(double num){ // @@ function parameter double but stack is int; truncation occurs, but main issue is mismatched printf
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
    if(Ntop == MAXSIZE -1) { // @@ should check Otop instead of Ntop; using Ntop is incorrect
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