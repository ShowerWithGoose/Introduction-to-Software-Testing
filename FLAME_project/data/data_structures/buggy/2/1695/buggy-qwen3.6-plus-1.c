#include<stdio.h>

int main() {
    int a1=0,a2,a3;
    char s1='+',s2,s3;
    while (s1!='='){
        scanf("%d%c",&a2,&s2);//一个数一个运算符 
        while (s2=='*'||s2=='/'){
            scanf("%d%c",&a3,&s3);
            if (s2=='*')
                a2=a2*a3;
            else if (s2=='/')
                a2=a2/a3;
            s2=s3;//产生循环，连续乘除 
        }
        if (s1=='+'){
            a1+=a2;
        }
        else if (s1=='-'){
            a1-=a2;
        }
        s1=s2;//产生循环，连续加减  @@ The loop condition checks s1, but if the last operator read into s2 is not '=', s1 becomes that operator. If the input ends with '=', s2 becomes '='. However, if there are spaces in the input like "10 + 20", scanf("%d%c") might read the space into s2 instead of the operator, or fail to parse correctly if spaces are present between numbers and operators as described in the problem ("The expression may contain spaces"). The primary issue causing TLE or incorrect behavior here is likely how `scanf` handles spaces. `%c` reads any character including spaces. If the input is `10 + 20`, `scanf("%d%c", &a2, &s2)` reads `10` into `a2` and ` ` (space) into `s2`. Then `s2` is not `*` or `/`, so it proceeds. `s1` is `+`, so `a1 += a2`. Then `s1` becomes ` ` (space). The next iteration `scanf` reads `+`? No, `scanf("%d%c")` expects an integer first. It will skip leading whitespace for `%d`, so it reads `20` into `a2`, then ` ` (space after 20) or `\n` into `s2`. This logic fails to correctly parse operators when spaces are present because `%c` does not skip whitespace. The reference program uses `scanf("%d %c")` which skips whitespace before the character. The buggy code uses `scanf("%d%c")` which does not. This leads to parsing errors. Specifically, if `s2` reads a space, it doesn't match `*` or `/`, falls through to addition/subtraction logic using previous `s1`, then updates `s1` to space. Next loop, `scanf` skips whitespace for `%d`, reads number, then reads next char. If the structure is `num op num`, and `op` is surrounded by spaces, `s2` often captures a space. This desynchronizes the parser. Eventually, it may not read `=` correctly or enter an infinite loop if parsing gets stuck or misinterprets data. To fix TLE/WA, `scanf` format should be `"%d %c"` to skip spaces.
    }
    printf("%d",a1);
    return 0;
}