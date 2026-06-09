#include<stdio.h>

int main()
{
    //É¨ÃèÁ½±é
    int i,num[10000];
    char op[10000];
    i=0;
    scanf("%d %c",&num[i],&op[i]);
    while(op[i]!='='){
        i++;
        scanf("%d %c",&num[i],&op[i]);
    }
    for(i=0;op[i]!='=';i++){//µÚÒ»±éÉ¨Ãè 
        if(op[i]=='*'){
            num[i+1]=num[i]*num[i+1];
            num[i]=0;
            if(i>0){//´«µÝ¼õºÅ 
                op[i]=op[i-1];
            }else{
                op[i]='+';
            } 
        }else if(op[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Division is performed as num[i]/num[i+1], but it should be integer division with correct left-to-right associativity; however, the main issue is that this modifies num[i+1] and sets num[i]=0, which breaks expression structure when followed by another * or /]
            num[i]=0;
            if(i>0){//´«µÝ¼õºÅ 
                op[i]=op[i-1];
            }else{
                op[i]='+';
            }
        }
    }
    for(i=0;op[i]!='=';i++){
        if(op[i]=='+'){
            num[i+1]=num[i]+num[i+1];
        }else if(op[i]=='-'){
            num[i+1]=num[i]-num[i+1]; // @@ [This processes subtraction left-to-right correctly in isolation, but because the first pass incorrectly handles operator precedence and overwrites values, the operands here are already corrupted]
        }
    }
    printf("%d",num[i-1]); // @@ [The final result is taken from num[i-1], but after the loops, i points to the position of '=', so i-1 is the last number index. However, due to incorrect propagation of operators and zeroing out intermediate results, the accumulated value is wrong]
    return 0;
}