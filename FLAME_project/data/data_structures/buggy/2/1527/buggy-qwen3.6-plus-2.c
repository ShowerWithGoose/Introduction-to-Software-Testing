#include <stdio.h>
#include <string.h>
char array[6000]={0};
int zhengshu(int *a)
{
    int x=0,y=*a;
    for(;array[y]>='0'&&array[y]<='9';y++)
        x=10*x+array[y]-'0';
    *a=y;
    return x;
}
int chengchu(int *a)
{
    int x1=1,y1=*a;
    if(array[y1]=='-')    x1=-1; // @@ The logic for handling negative numbers and subtraction is flawed. It treats a '-' as a sign for the following number regardless of context (e.g., binary subtraction vs unary negation), and consumes the character without distinguishing between operator and sign correctly in the main loop's context.
    *a=*a+1;
    x1*=zhengshu(a);
    while(array[*a]=='*'||array[*a]=='/')
    {
        switch(array[*a])
        {
            case'*':*a=*a+1;x1*=zhengshu(a);break;
            case'/':*a=*a+1;x1/=zhengshu(a);break;
        }
    }
    return x1;
}
int main()
{
    gets(array);
    int b=0;
    int i,j;
    for(i=0,j=0;array[i]!=0;i++)
    {
        if(array[i]!=' ')    array[j++]=array[i]; 
    }
    array[j]=0;
    int sum=zhengshu(&b);
    while(array[b]!='=')
        {sum+=chengchu(&b); // @@ The main loop assumes all terms separated by '+' or '-' are added to the sum. However, chengchu() handles '-' as a negative sign for the term itself. If the expression is "A - B", zhengshu reads A, then chengchu sees '-', sets x1=-1, reads B, returns -B. sum += (-B) works for subtraction. BUT, if the expression starts with a negative number or has complex interactions, this simple additive model fails if chengchu doesn't correctly consume the operator preceding the term. More critically, chengchu consumes the '-' but the main loop doesn't know if it was a binary operator or unary. In "24 / 4 ...", the first term is read by zhengshu. Then chengchu is called. If the next char is '/', it's not handled by chengchu's initial check. Wait, zhengshu reads "24". b points to '/'. chengchu is called. array[b] is '/'. It is not '-'. x1=1. *a increments to point to '4'. x1 *= 4. Then while loop handles subsequent * or /. This seems okay for the first term if it's just a number. But wait, the first term "24" is read by `sum=zhengshu(&b)`. Then `chengchu` is called. `chengchu` expects to read a term that might start with a minus. But the operator between terms (+ or -) is NOT consumed by `zhengshu`. So when `chengchu` is entered, `array[b]` is the operator (e.g., '/'). The code `if(array[y1]=='-')` checks if the operator is '-'. If it is '/', it skips. Then `*a=*a+1` advances past the '/'. Then `x1*=zhengshu(a)` reads the next number. This effectively treats '/' as a multiplier/divider for the NEXT term? No, `chengchu` is supposed to handle multiplication and division chains. The structure `sum += chengchu()` implies that `chengchu` returns a value that should be added to the sum. This works if `chengchu` handles the leading operator. If the operator is '+', `chengchu` sees '+', doesn't match '-', increments pointer, reads number, returns positive number. Sum adds it. Correct. If operator is '-', `chengchu` sees '-', sets x1=-1, increments, reads number, returns negative number. Sum adds it (subtracts). Correct. If operator is '*', `chengchu` sees '*', doesn't match '-', increments, reads number. But wait, the previous term was already added to `sum`. Multiplication has higher precedence. The current architecture `sum = first_term; while(...) sum += chengchu()` is fundamentally wrong for mixed precedence because `chengchu` only looks ahead for * and / within its own scope, but the separation of terms by + and - is done by the while loop. The issue is that `zhengshu` reads the FIRST number. Then `chengchu` is called. `chengchu` does NOT see the operator BEFORE the term it is parsing, it sees the operator AFTER the previous term? No. `zhengshu` stops at the first non-digit. So if input is "24/4...", `zhengshu` reads 24, b points to '/'. `chengchu` is called. It sees '/'. It is not '-'. It increments b (now points to '4'). It reads 4. It returns 4. `sum` becomes 24+4=28. This is WRONG. It should be 24/4=6. The function `chengchu` is designed to parse a term starting with an optional sign, followed by a number, followed by * or / operations. It does NOT handle the case where the term itself is part of a division chain starting immediately after the previous number without an intervening + or -. The parser structure is broken: it reads the first number, then treats every subsequent sequence as a new term to be added, but fails to account for the operator connecting the previous accumulated value to the new term if that operator is * or /. Actually, looking closer: `zhengshu` reads "24". `b` is at '/'. `chengchu` is called. Inside `chengchu`, `array[*a]` is '/'. It is not '-'. `*a` becomes index of '4'. `x1` becomes 4. While loop checks `array[*a]` which is now after '4' (likely another '/'). It processes the chain. It returns the result of the chain starting with 4. So it returns 4/3/2 = 0 (integer division). Sum = 24 + 0 = 24. This is incorrect. The operator '/' between 24 and 4 was skipped/consumed incorrectly. The code assumes that `chengchu` handles the operator preceding the number, but it only handles '-'. It ignores '+' '*' '/' as preceding operators, just skipping them. This breaks the precedence and connectivity.
        }
    printf("%d",sum);
    return 0;
}