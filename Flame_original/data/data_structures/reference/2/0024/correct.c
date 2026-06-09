#include<stdio.h>
#include<stdio.h>

int Delete(char [], int, int);
int priority(char a);

int main(){
    char a[200];
    int num[200];
    char op[200];
    int numTop, opTop;
    int temp = 0;
    //保证第0个一定不是符号
    op[0] = 'a';
    gets(a);
    int i, position;    //position—>'='的位置
    for(position = 0; a[position] != '='; ++position){
        ;
    }

    for(i = 0; a[i] != '=';){   //删去所有空格
        if(a[i] == ' ')
            position = Delete(a, i, position);
        else
            i++;
    }

//printf("%s\n", a);


    //int j = 0, k = 0;
    char opTemp;
    int sign = 0;
    for(i = 0, opTop = 0, numTop = 0; a[i] != '='; ++i){
        if('0' <= a[i] && a[i] <= '9'){     /*读入数字*/
            temp = 0;
            while('0' <= a[i] && a[i] <= '9'){
                temp = 10*temp + a[i] - '0';
                ++i;
            }
            --i;
            num[++numTop] = temp;     /*从numTop = 1开始，始终指向栈顶*/
//printf("numTop = %d, num[] = %d\n", numTop, num[numTop]);
        }
        else{       /*判断符号*/
            opTemp = a[i];

            //20 + 500 / 100 * 5 + 5
            /*栈顶符号！！！！*/
            if(op[opTop] == '*' || op[opTop] == '/') /* && numTop >= 2 */{     /*判断符号栈栈顶是否为乘除，先计算乘除，将结果压入数字栈栈顶*/
                if(op[opTop] == '*'){      /*乘法*/
                    temp = num[numTop]*num[numTop-1];
                    //numTop下移一位至numTop-1（新栈顶），计算结果压入栈顶，利用覆盖删除num[numTop]
                    num[--numTop] = temp;
                    op[opTop] = opTemp;
                    //printf("* numTop = %d, num[] = %d, opTop = %d\n", numTop, num[numTop], opTop);
                }
                else{       /*除法*/
                    temp = num[numTop-1]/num[numTop];
                    num[--numTop] = temp;
                    op[opTop] = opTemp;
                    //printf("/ numTop = %d, num[] = %d, opTop = %d\n", numTop, num[numTop], opTop);
                }

            }
            else{       /*把符号压入符号栈中*/
                op[++opTop] = opTemp;      //从opTop = 1开始，指向符号栈栈顶
//printf("%d %c\n", opTop, op[opTop]);
            }
        }
    }
    /*最后可能读入*和/单独考虑*/
    if((opTemp == '*' || opTemp == '/') /* && numTop >= 2 */){     /*判断是否为乘除，先计算乘除，将结果压入栈内*/
        if(opTemp == '*'){      /*乘法*/
            temp = num[numTop]*num[numTop-1];
            num[--numTop] = temp;       //numTop下移一位至numTop-1，计算结果压入numTop-1中，利用覆盖删除num[numTop]
        }
        else{       /*除法*/
            temp = num[numTop-1]/num[numTop];
            num[--numTop] = temp;
        }
    }
    /*如果读入+-则压入栈*/
    else{
        op[++opTop] = opTemp;
    }




    op[++opTop] = '=';  //极限情况时也能保证opTop = 1
//printf("end: %d %c\n", opTop, op[opTop]);


    /*把+-弹出栈，并弹出2个数字运算，结果保存在sum中*/
    int sum = 0, numBase = 1;
    sum = num[1];

//printf("before sum = %d\n", sum);

    for(i = 1; op[i] != '='; ++i){
        if(op[i] == '+'){
            sum += num[i+1];
        }
        else if(op[i] == '-'){
            sum -= num[i+1];
        }
    }
    printf("%d", sum);


    return 0;
}




int Delete(char a[], int i, int mark){
    int j;
    for(j = i; j <= mark; ++j){
        a[j] = a[j + 1];
    }
    mark--;
    //printf("mark = %d\n", mark);
    return mark;
}

int priority(char a){
    if(a == '+' || a == '-'){
        return 0;
    }
    else if(a == '*' || a == '/'){
        return 1;
    }
}


