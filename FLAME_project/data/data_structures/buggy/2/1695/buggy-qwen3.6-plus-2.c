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
        s1=s2;//产生循环，连续加减  // @@ [The loop condition checks s1 != '=', but s1 is updated to s2. If the input ends with '=', s2 becomes '='. However, the inner while loop for * / consumes tokens. The main issue causing TLE is likely that when s2 is '=', the outer loop terminates correctly in logic, but if spaces are present or parsing fails, it might hang. More critically, if the input format has spaces, "%d%c" might read space into c. But the primary logical error leading to potential infinite loops or incorrect state is that if s2 is '=', the loop should break. The current code updates s1=s2 at the end. If s2 is '=', s1 becomes '=', and the while loop terminates. This seems logically okay for valid input. However, looking at the reference program, it handles spaces explicitly or relies on scanf skipping whitespace for %d but not for %c. The format "%d%c" will read the integer, then the very next character. If there is a space after the number, s2 becomes ' '. Then s2 is not '*' or '/', so it goes to the if/else block. s1 is '+' or '-'. It updates a1. Then s1 becomes ' ' (space). The next iteration, s1 is ' ', which is not '='. It tries to scanf "%d%c". If the next token is a number, it reads it. But s1 is space, so it falls through to the else if (s1=='-')? No, s1 is space. So it does nothing to a1? No, it checks s1=='+' (false) and s1=='-' (false). Then s1=s2. This logic is flawed because it doesn't handle the operator stored in s2 correctly if s2 was a space. The operator was skipped or misinterpreted. Actually, the bug is that `scanf("%d%c", &a2, &s2)` reads the character immediately following the integer. If the input is "10 + 20", after reading 10, s2 reads ' '. Then the code treats ' ' as the operator s1 for the NEXT iteration? No, s1 is updated to s2 (' '). Then in the next loop, it reads 20 into a2, and '+' into s2. Then it processes a2 (20) with s1 (' '). Since s1 is not '+' or '-', it does nothing. Then s1 becomes '+'. This delays the operation. Eventually, when '=' is read, it might work out or fail. But the TLE suggests an infinite loop. If the input ends with '=', s2 becomes '='. s1 becomes '='. Loop ends. Why TLE? Perhaps if the input has trailing spaces or newlines? Or maybe `scanf` fails? If `scanf` fails, it returns EOF, but the variables remain unchanged, leading to an infinite loop if s1 never becomes '='. A robust fix is to check the return value of scanf or use " %c" to skip whitespace. Using " %c" instead of "%c" would skip spaces and read the actual operator. Without the space in format string, spaces are read as operators, messing up the logic and potentially causing unexpected behavior or infinite loops if the state doesn't progress towards '='. Specifically, if s2 reads a space, and that space is assigned to s1, the next scanf might read the actual operator into s2, but the previous number a2 was already processed (or not processed correctly). The logic `s1=s2` assigns the space to s1. The next iteration reads the next number and the next char. The operator that was supposed to be applied to the previous number is now in s2, but the previous number's operation was skipped because s1 was space. This desynchronization can lead to errors. To fix TLE and logic, we should skip whitespace. Changing `%c` to ` %c` ensures spaces are skipped.]
    }
    printf("%d",a1);
    return 0;
}