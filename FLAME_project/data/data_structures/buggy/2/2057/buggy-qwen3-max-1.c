#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){
        scanf("%d %c",&data[i],&op[i]);
        n++;
    } @@ [The loop condition checks op[i] before it is read for the first time, leading to undefined behavior. Also, the space in "%d %c" skips optional whitespace but may fail to correctly handle cases where multiple spaces exist or the '=' is adjacent to the last number without space. More critically, the loop does not stop immediately when '=' is read—it increments n and includes an extra invalid element.]
    for(i=0;i<n-1;i++){
        if(op[i]=='*'){
            data[i+1] = data[i] * data[i+1];
            data[i]=0;
            op[i]='+';
        }
        if(op[i]=='/'){
            data[i+1] = data[i] / data[i+1];
            data[i]=0;
            op[i]='+';
        }
    } @@ [This pass processes * and / left-to-right but modifies data[i] to 0 and op[i] to '+', which breaks correct operator precedence handling when subsequent operators depend on original values. Moreover, it doesn't skip already processed terms, so overlapping operations (e.g., a * b / c) will be miscalculated because data[i] is zeroed out prematurely.]
    result=data[0];
    for(i=0;i<n-1;i++){
        if(op[i]=='-')
        result=result - data[i+1];
        if(op[i]=='+')
        result=result + data[i+1];
    } @@ [Because earlier passes replaced '*' and '/' with '+' and set left operand to 0, expressions like "10 + 20 * 30" become "10 + 0 + 600", which incorrectly evaluates as 610 instead of 610? Wait—but expected is 602. Actually, the real issue: the first loop reads one extra term due to flawed termination, and the precedence handling is incorrect because it doesn't collapse the expression properly. Specifically, after processing * and /, the array still has zeros that interfere with addition/subtraction. For input "10 + 20 * 30 - 40 / 5 =", after * and / pass: data = [10, 0, 600, 0, 8], op = ['+', '+', '-', '+', '=']. Then evaluation: result = 10; +0 → 10; +600 → 610; -0 → 610; +8 → 618 — which is wrong. But expected is 602. Correct evaluation: 20*30=600, 40/5=8, then 10+600-8=602. The bug is that during * and / processing, the code should eliminate the used operand (like setting it to neutral or skipping), but by setting data[i]=0 and changing op[i] to '+', it introduces spurious zeros into the sum. Instead, it should shift or mark terms to be skipped.]
    printf("%d",result);
}