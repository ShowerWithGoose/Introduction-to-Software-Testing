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
            num[i+1]=num[i]/num[i+1];
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
            num[i+1]=num[i]-num[i+1];
        }
    }
    printf("%d",num[i-1]); // @@ The loop terminates when op[i] is '=', so i points to the index of '='. The final result is accumulated in num[i], but since the loop condition checks op[i] before entering, and the accumulation happens into num[i+1], the last valid accumulation is into num[i] where op[i] was the last operator. However, looking at the logic: if the expression is "1 + 2 =", num[0]=1, op[0]='+', num[1]=2, op[1]='='. Loop i=0: op[0]=='+', num[1] = 1+2=3. i becomes 1. op[1]=='=', loop ends. We want num[1]. The code prints num[i-1] which is num[0]. This is incorrect. It should print num[i] or adjust the index. Actually, let's trace carefully.
    // Trace: 10 + 20 * 30 - 40 / 5 =
    // Initial: num[0]=10, op[0]='+', num[1]=20, op[1]='*', num[2]=30, op[2]='-', num[3]=40, op[3]='/', num[4]=5, op[4]='='
    // Pass 1 (* and /):
    // i=0: op[0]='+'. Skip.
    // i=1: op[1]='*'. num[2] = 20*30=600. num[1]=0. op[1] becomes op[0] which is '+'.
    // State: num[0]=10, op[0]='+', num[1]=0, op[1]='+', num[2]=600, op[2]='-', num[3]=40, op[3]='/', num[4]=5, op[4]='='
    // i=2: op[2]='-'. Skip.
    // i=3: op[3]='/'. num[4] = 40/5=8. num[3]=0. op[3] becomes op[2] which is '-'.
    // State: num[0]=10, op[0]='+', num[1]=0, op[1]='+', num[2]=600, op[2]='-', num[3]=0, op[3]='-', num[4]=8, op[4]='='
    // Pass 2 (+ and -):
    // i=0: op[0]='+'. num[1] = 10+0=10.
    // i=1: op[1]='+'. num[2] = 0+600=600.
    // i=2: op[2]='-'. num[3] = 600-0=600.
    // i=3: op[3]='-'. num[4] = 600-8=592.
    // i=4: op[4]='='. Loop ends.
    // Result should be num[4] which is 592? Wait. 10 + 600 - 8 = 602.
    // Let's re-trace pass 2.
    // i=0: op[0]='+'. num[1] = num[0]+num[1] = 10+0=10.
    // i=1: op[1]='+'. num[2] = num[1]+num[2] = 10+600=610.
    // i=2: op[2]='-'. num[3] = num[2]-num[3] = 610-0=610.
    // i=3: op[3]='-'. num[4] = num[3]-num[4] = 610-8=602.
    // i=4: op[4]='='. Loop ends.
    // The correct answer is in num[4].
    // The variable i is 4.
    // The code prints num[i-1] which is num[3] (610). This is wrong.
    // It should print num[i].
    return 0;
}