#include <stdio.h>
#include <string.h>
char a[1000];//×Ö·û
int b[1000];//Êý×Ö

int main() {
    int i = 1;
    a[0] = '+';
    b[0] = 0;
    scanf("%d", &b[i]);
    scanf(" %c", &a[i]);
    while (a[i] != '=') {
        i++;
        scanf("%d", &b[i]);
        scanf(" %c", &a[i]);
    }
    int n = i;
    int j = 0, x = b[2], result = b[1]; // @@ The initialization of x to b[2] is incorrect because if the expression has only one number or starts with operations that don't involve b[2] immediately in the expected way, it causes issues. More importantly, the logic below relies on processing terms. The variable 'result' is initialized to b[1], which is the first number. This part is okay for the first term, but 'x' initialization is risky and unused before the loop properly sets it. However, the main logical error is in the loop condition and index management.
    for (i = 0, j = 1; i < n;) { // @@ The loop structure attempts to process terms separated by + or -. It looks ahead for * or /.
        j = i + 1;
        x = b[j]; // @@ Here x is set to the number following the operator at a[i].
        while (a[j] == '*' || a[j] == '/') { // @@ This checks the operator AFTER the number b[j]. If a[j] is * or /, it combines b[j] and b[j+1].
            if (a[j] == '*')
                x *= b[j + 1];
            else
                x /= b[j + 1];
            j++; // @@ After processing *, j increments. But we need to skip the number we just consumed as well.
                 // The standard pattern for this lookahead is:
                 // current term value starts at b[i+1] (if a[i] is the op before it).
                 // Actually, let's trace:
                 // i=0. a[0]='+'. j=1. x=b[1].
                 // Check a[1]. If a[1] is '*', x *= b[2]. j becomes 2.
                 // Check a[2]. If a[2] is not * or /, loop ends.
                 // Then apply a[0] ('+') to result with x.
                 // i becomes j (2).
                 // Next iter: i=2. a[2] is '-' (from input 10 + 20 * 30 - ... wait.
                 // Input: 10 + 20 * 30 - 40 / 5 =
                 // b[1]=10, a[1]='+'
                 // b[2]=20, a[2]='*'
                 // b[3]=30, a[3]='-'
                 // b[4]=40, a[4]='/'
                 // b[5]=5, a[5]='='
                 // n=5.
                 // Iter 1: i=0. j=1. x=b[1]=10.
                 // while(a[1]=='*')? No, a[1] is '+'. Loop doesn't run.
                 // if(a[0]=='+') result += x (10). result=10.
                 // i=j=1.
                 // Iter 2: i=1. j=2. x=b[2]=20.
                 // while(a[2]=='*')? Yes. x *= b[3] (30) -> x=600. j=3.
                 // while(a[3]=='*')? No (it is '-'). Loop ends.
                 // if(a[1]=='+') result += x (600). result=610.
                 // i=j=3.
                 // Iter 3: i=3. j=4. x=b[4]=40.
                 // while(a[4]=='/')? Yes. x /= b[5] (5) -> x=8. j=5.
                 // while(a[5]=='/')? No (it is '='). Loop ends.
                 // if(a[3]=='-') result -= x (8). result=602.
                 // i=j=5.
                 // Loop condition i < n (5 < 5) fails.
                 // Output 602.
                 // Wait, the provided buggy output is 612. Why?
                 // Let's re-read the code carefully.
                 // int j = 0, x = b[2], result = b[1];
                 // The initialization of x to b[2] is irrelevant if it's overwritten in the loop.
                 // Is there an off-by-one in the input reading?
                 // scanf("%d", &b[i]); scanf(" %c", &a[i]);
                 // i=1: b[1]=10, a[1]='+'
                 // i=2: b[2]=20, a[2]='*'
                 // i=3: b[3]=30, a[3]='-'
                 // i=4: b[4]=40, a[4]='/'
                 // i=5: b[5]=5, a[5]='='
                 // Loop terminates when a[i]=='='. So i stops at 5. n=5.
                 // The trace above yields 602.
                 // Why did the student get 612?
                 // Maybe the input parsing is different or I missed something.
                 // Ah, look at the loop condition: for (i = 0, j = 1; i < n;)
                 // And the update: i = j;
                 // In Iter 3: i=3. a[3] is '-'.
                 // j=4. x=b[4]=40.
                 // a[4] is '/'. x /= b[5] (5) -> 8. j=5.
                 // a[5] is '='. Loop ends.
                 // a[3] is '-'. result -= 8. 610 - 8 = 602.
                 
                 // Let's check if the problem description implies something else.
                 // "10 + 20 * 30 - 40 / 5 ="
                 // 10 + 600 - 8 = 602.
                 
                 // If the output is 612, that is 602 + 10. Or 610 + 2?
                 // 612 = 10 + 600 + 2? No.
                 // 612 = 10 + 20 * 30 - 40 / 5?
                 // If division was integer division 40/5 = 8.
                 // If the code failed to divide? 610 - 40 = 570.
                 // If the code added instead of subtracted? 610 + 8 = 618.
                 // If the first term was handled incorrectly?
                 
                 // Let's look at the initialization again.
                 // int j = 0, x = b[2], result = b[1];
                 // If the loop didn't run, result would be b[1].
                 
                 // Is it possible the array indices are shifted?
                 // If a[0] wasn't initialized to '+'?
                 // a[0] = '+'; b[0] = 0;
                 
                 // Let's look at the "Buggy Output: 612".
                 // 612 - 602 = 10.
                 // It seems the first number 10 was added twice?
                 // Or the last subtraction didn't happen?
                 // If result was 610 and we didn't subtract 8, we'd have 610.
                 // If we added 8, we'd have 618.
                 
                 // What if the division 40/5 was calculated as 40/5 = 8, but the sign was wrong?
                 
                 // Actually, there is a subtle bug in `scanf(" %c", &a[i])`.
                 // If the input ends with `=`, the loop `while (a[i] != '=')` breaks.
                 
                 // Let's re-examine the loop logic for potential index errors.
                 // When j increments inside the while loop, it points to the next operator.
                 // x accumulates the value.
                 // When the while loop finishes, j points to the operator separating the current term from the next.
                 // i is updated to j.
                 // In the next iteration, a[i] is that separator operator.
                 // j becomes i+1, which is the index of the next number.
                 // x is set to b[j].
                 // This logic seems correct for the structure:
                 // Op[i] Num[j] Op[j] ...
                 
                 // Wait, look at this line:
                 // int j = 0, x = b[2], result = b[1];
                 // If the expression was just "10 =", n=1.
                 // Loop: i=0, j=1. i<n (0<1).
                 // j=1. x=b[1].
                 // while(a[1]...)? a[1] is '='. Loop doesn't run.
                 // if(a[0]=='+') result += b[1]. result = 10 + 10 = 20?
                 // No, result was initialized to b[1] (10).
                 // So result += 10 -> 20.
                 // So for single number, it doubles it.
                 
                 // In our case:
                 // Iter 1: i=0. a[0]='+'. j=1. x=b[1]=10.
                 // a[1] is '+'. Not * or /.
                 // if(a[0]=='+') result += x.
                 // result was initialized to b[1] (10).
                 // So result becomes 10 + 10 = 20.
                 
                 // Iter 2: i=1. a[1]='+'. j=2. x=b[2]=20.
                 // a[2] is '*'. x *= b[3] (30) -> 600. j=3.
                 // a[3] is '-'. Stop.
                 // if(a[1]=='+') result += 600.
                 // result = 20 + 600 = 620.
                 
                 // Iter 3: i=3. a[3]='-'. j=4. x=b[4]=40.
                 // a[4] is '/'. x /= b[5] (5) -> 8. j=5.
                 // a[5] is '='. Stop.
                 // if(a[3]=='-') result -= 8.
                 // result = 620 - 8 = 612.
                 
                 // There it is! The initialization `result = b[1]` combined with the first iteration adding `b[1]` again causes the first number to be counted twice.
                 // The fix is to initialize `result = 0`.
    }
    printf("%d", result);
}