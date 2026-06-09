#include <stdio.h>
char op[10000];
int data[10000];
int main(){
    int i,n=0,result;
    for(i=0;op[i] != '=';i++){ // @@ The loop condition checks uninitialized global array 'op' before any input is read. Although global arrays are zero-initialized (so op[0] is '\0'), the logic relies on reading into op[i] inside the loop. The critical error is that `scanf("%d %c", ...)` with the space in format string consumes whitespace, but if the input ends with '=', the previous scanf might have left it or handled it incorrectly depending on spacing. More importantly, the loop termination condition `op[i] != '='` is checked *before* reading the current token. For the first iteration, op[0] is 0, so it enters. It reads data[0] and op[0]. If op[0] is '=', the loop should stop. However, the increment happens at the end of the loop. The real issue is that `scanf` with `%d %c` skips leading whitespace for `%d`, then skips whitespace for the space in format, then reads one char for `%c`. If the input is `10 + 20 ... =`, it works. But if the input has spaces around `=`, e.g., `... 5 =`, scanf reads 5 into data, then skips space, then reads `=` into op. Then `i` increments. Next iteration: check `op[1] != '='`. If op[1] was not set yet (uninitialized/zero), it continues. But wait, `op` is global, so it's zeroed. The loop condition `op[i] != '='` uses the value of `op` at index `i` which hasn't been read into yet for the current iteration? No, `i` is the index we are about to read into. We check `op[i]` before reading. Since `op` is global, `op[i]` is 0 for all unread indices. So `0 != '='` is true. We enter loop. We `scanf` into `data[i]` and `op[i]`. If we read `=`, `op[i]` becomes `=`. Loop body finishes. `i++`. Next iteration: check `op[i]` (next index, still 0). It continues. This means the loop doesn't break immediately when `=` is read into `op[i]`. It breaks only when it encounters an index `i` where `op[i]` was previously set to `=`. But `op[i]` is only set once. So if `op[k] = '='`, the loop will break at the start of iteration `k+1`? No, it checks `op[i]` at start. If `i=k`, `op[k]` is `=` (set in previous iteration? No, set in current iteration `k-1`? Let's trace. i=0. Check op[0]==0. Enter. Scanf into data[0], op[0]. Suppose op[0] is '+'. i becomes 1. Check op[1]==0. Enter. Scanf into data[1], op[1]. ... Suppose at i=m, we read '=' into op[m]. i becomes m+1. Check op[m+1]==0. Enter. Scanf tries to read another int. But there is no more input (or just newline). This causes scanf to fail or wait. This is a logical error in loop control. The check should be after reading, or the structure should be do-while or check the read operator.
        scanf("%d %c",&data[i],&op[i]);
        n++;
    }
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
    }
    result=data[0];
    for(i=0;i<n-1;i++){
        if(op[i]=='-')
        result=result - data[i+1];
        if(op[i]=='+')
        result=result + data[i+1];
    }
    printf("%d",result);
}