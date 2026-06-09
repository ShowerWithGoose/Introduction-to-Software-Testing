#include <stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    char ch1,ch2;
    int sum=0,a,b=1,flat=1;
    while(1){
        while(1){
            scanf("%c",&ch1);
            printf("%c",ch1); // @@ [The program outputs characters during input processing, which violates the output format requirement of only printing the final result. This causes "Buggy output too long" errors.]
            if(ch1!=' '){
                a=ch1-'0'; // @@ [This logic assumes numbers are single-digit or handles multi-digit numbers incorrectly by initializing 'a' with just the first digit's value without proper accumulation logic for the start of a number. While the subsequent loop accumulates, this initialization is fragile and incorrect if spaces aren't handled perfectly before every number. More critically, it fails to handle multi-digit numbers correctly if the first character read is part of a larger number, but the main issue is the next line.]
                break;
            }
        }
        while(1){
            scanf("%c",&ch2);
            printf("%c",ch2); // @@ [The program outputs characters during input processing, which violates the output format requirement of only printing the final result.]
            if(ch2>='0'&&ch2<='9'){
                a*=10;a+=ch2-'0';
            }
            if(ch2=='+'||ch2=='-'||ch2=='*'||ch2=='/'||ch2=='='){
                break;
            }
        }
        if(ch2=='+'||ch2=='-'||ch2=='='){
            if(flat==1){
                b*=a;
            }else if(flat==2){
                b=b/a;
            }
            flat=1;
            sum+=b;
            b=1; // @@ [Resetting b to 1 is incorrect when the next operator is '-'. If the next operator is '-', b should be initialized to -1 later, but here it resets to 1. The logic below sets b=-1 if ch2 is '-', but this happens AFTER sum+=b. The variable b is used to accumulate the current term. When we encounter + or -, we finalize the previous term. Then we prepare for the next term. If the current operator is '-', the next term should be subtracted. The code sets b=-1, but then in the next iteration, if the next operator is *, it does b*=a. If b is -1 and a is 5, b becomes -5. This part is actually logically okay for sign handling IF b starts as 1 or -1. However, look at the initialization: b=1. Then if ch2=='-', b=-1. This means the NEXT number will be multiplied by -1. This seems correct for sign. BUT, there is a major logical error in how 'b' is accumulated across * and /. See below.]
            if(ch2=='-'){
                b=-1;
            }
        }else if(ch2=='*'||ch2=='/'){
            if(ch2=='*'){
                if(flat==1){
                b*=a;
            }else if(flat==2){
                b=b/a;
            }
                flat=1;
            }else if(ch2=='/'){
                if(flat==1){
                b*=a;
            }else if(flat==2){
                b=b/a;
            }
                flat=2;
            }
        }
        if(ch2=='='){
            break;
        }
    }
    printf("\n");
    printf("%d",sum);
    return 0;
}