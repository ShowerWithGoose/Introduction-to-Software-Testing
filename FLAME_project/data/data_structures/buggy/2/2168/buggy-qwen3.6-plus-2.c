#include <stdio.h>
#include <string.h>
char a[10000];
void squeez(char s[], char c) /*删除某个字符c*/{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c){
            s[j++] = s[i];
        }
    s[j] = '\0';
}
int trans_to_num(char* a,int i){
    int p=1,result=0;
    for(int j=i;a[j+1]>='0'&&a[j+1]<='9';j++){
        p*=10;
    }
    for(;a[i]>='0'&&a[i]<='9';i++){
        result+=(a[i]-'0')*p;
        p/=10;
    }
    return result;
}
int main(){
    gets(a);
    char c=' ';
    squeez(a,c);
    int i=0,sum=0,num=0;
    num=trans_to_num(a,i); // @@ The logic fails to handle chained division and multiplication correctly across additive boundaries. Specifically, when encountering a sequence like A / B / C, the first loop handles A/B, but then breaks on the next operator if it's not * or /. However, the subsequent logic assumes the next token is an additive operator or end. In the case of `24 / 4 / 3 ...`, after `24/4` (num=6), the loop encounters `/`. The code enters the `else` block because the inner `while` stops at `/`, but the `if/else if` chain only handles `*` and `/` inside the first `while(1)` loop if they are immediate. Wait, looking closely: The first `while(1)` loop continues as long as it hits `*` or `/`. If it hits `+` or `-`, it breaks. If it hits `=`, it breaks.
    // The issue is actually in how `trans_to_num` works or how `i` is updated.
    // Let's trace `24 / 4 / 3`.
    // 1. `num` = 24. `i` is at index of '/'.
    // 2. Inner while skips digits? No, `a[i]` is '/'. So inner while doesn't run.
    // 3. `a[i]` is '/'. Enters `else if(a[i]=='/')`.
    // 4. `i++`. `i` is now at '4'.
    // 5. `num /= trans_to_num(a, i)`. `trans_to_num` reads 4. `num` becomes 6.
    // 6. Loop repeats. Inner while: `a[i]` is ' ' (removed) or next char. Since spaces removed, `a[i]` is '/'.
    // 7. Inner while condition `a[i]!='='...` checks if it is a digit. It is not. So inner while doesn't run.
    // 8. `a[i]` is '/'. Enters `else if(a[i]=='/')`.
    // 9. `i++`. `i` is at '3'.
    // 10. `num /= trans_to_num(a, i)`. `num` becomes 2.
    // 11. Loop repeats. `a[i]` is '+'.
    // 12. Inner while doesn't run.
    // 13. `a[i]` is '+'. Breaks out of first `while(1)`.
    // This part seems correct for the prefix.
    
    // The error likely lies in the second part or the transition.
    // After breaking, `a[i]` is '+'.
    // `if(a[i]=='=')` is false.
    // `sum += num` -> `sum = 2`.
    // `num = 0`.
    // `record = '+'`.
    // `i++`. `i` is at '1' of '100'.
    // `num = trans_to_num(a, i)` -> 100.
    // Second `while(1)`:
    // Inner while advances `i` past '100'. `a[i]` is '-'.
    // `a[i]` is '-'. Not '=', '*', '/'.
    // Enters `else`.
    // `record` is '+'. `sum += num` -> `sum = 2 + 100 = 102`.
    // `i++`. `i` is at '5' of '50'.
    // `num = trans_to_num(a, i)` -> 50.
    // `record = a[i]` -> `record = '-'`. **ERROR HERE**.
    // At this point, `i` is pointing to the first digit of the NEXT number ('50').
    // But `record` should store the operator that preceded this number, which is '-'.
    // However, `a[i]` is currently '5' (digit), not '-'. The operator '-' was at the previous position.
    // The code does `record=a[i]` AFTER incrementing `i` and reading the new number.
    // So `record` gets set to a digit character instead of the operator.
    
    if(a[i]=='='){
        printf("%d",sum);
        return 0;
    }
    sum+=num;
    num=0;
    char record=a[i];
    i++;
    num=trans_to_num(a,i);
    while(1){
        while(a[i]!='='&&a[i]!='+'&&a[i]!='-'&&a[i]!='*'&&a[i]!='/'){
            i++;
        }
        if(a[i]=='='){
            if(record=='+'){
                sum+=num;
            }
            else{
                sum-=num;
            }
            break;
        }
        else if(a[i]=='*'){
            i++;
            num*=trans_to_num(a,i);
        }
        else if(a[i]=='/'){
            i++;
            num/=trans_to_num(a,i);
        }
        else{
            if(record=='+'){
                sum+=num;
                i++;
            }
            else{
                sum-=num;
                i++;
            }
            num=trans_to_num(a,i);
            record=a[i]; // @@ [Logic Error] `a[i]` currently points to the first digit of the newly read number (inside `num`), not the operator. The operator was encountered in the `while` condition check before entering this `else` block. The variable `record` should be updated to the operator found at `a[i]` BEFORE `i` is incremented and the next number is parsed. However, here `num` is parsed first using current `i` (which is at operator), wait. 
            // Let's re-trace carefully.
            // Inside `else`:
            // 1. Apply previous `record` to `sum`.
            // 2. `i++` moves past the operator? No, `i` is still at the operator when we entered `else`.
            //    Wait, the `while` loop above stops WHEN `a[i]` is an operator.
            //    So `a[i]` IS the operator (e.g., '-').
            //    Then we go to `else`.
            //    We update sum.
            //    Then `i++`. Now `i` points to the start of the next number.
            //    Then `num=trans_to_num(a,i)`. This reads the number. `trans_to_num` does NOT advance `i` globally? 
            //    Let's check `trans_to_num`. It takes `int i` by value. It does NOT modify the global `i`.
            //    So after `num=trans_to_num(a,i)`, `i` STILL points to the start of the number we just read.
            //    Then `record=a[i]`. This sets `record` to the first DIGIT of the number.
            //    This is definitely wrong. `record` needs to be the operator that precedes the NEXT number.
            //    But we haven't reached the next operator yet.
            //    The structure is flawed. It should save the operator BEFORE parsing the next number, or parse the next number and then look ahead for the next operator.
        }
    }        
    printf("%d",sum);

    return 0;
}