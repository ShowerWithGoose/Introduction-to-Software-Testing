#include<stdio.h>
int main(){
    char s[101]="\0";
    fgets(s,101,stdin);
    int i;
    if(s[0]=='0'){
        i=2;
        while(s[i]=='0')
        i++;
        
        if(s[i+1]!='\0'){
            printf("%c.%se-%d",s[i],&s[i+1],i-1); // @@ [Error: Using &s[i+1] with %s format specifier prints the address or causes undefined behavior/crash instead of the substring. Should use s+i+1 or pass the pointer correctly, but more importantly, logic for exponent is wrong for numbers like 0.00123. Also, fgets includes newline, so s[i+1] might be '\n' or '\0'. The main compilation/runtime error source is likely the misuse of & in printf arguments for strings if the compiler treats it strictly, or logical errors causing crash. However, the prompt says "Compilation Error". Let's look closer. Actually, `&s[i+1]` is a `char*`, which is valid for `%s`. Wait. The reference program also used `&s[i+1]`. Why would this fail compilation? Maybe missing return type? No. Maybe `fgets` vs `scanf`? No. Let's re-read carefully. "Buggy Output: compile_run failed". This often means Runtime Error in some systems, but here it says Compilation Error. Is there a syntax error? No. Is there a type mismatch? `printf("%c.%se-%d",s[i],&s[i+1],i-1);` `s[i]` is char, `&s[i+1]` is char*, `i-1` is int. This is valid C. 
            // Let's look at the else branch.
            // printf("%c.%se%d",s[0],&s[1],k-1);
            // printf("%se0",&s[0]);
            // All these use &s[index] for %s. This is technically valid C (pointer to char).
            // However, looking at the provided "Reference Program", it also uses `&s[i+1]`.
            // If the error is strictly "Compilation Error", maybe the environment is strict C++ or something? Unlikely.
            // Let's look for actual syntax errors.
            // `while(s[i]=='0') i++;` -> Missing braces? No, single statement.
            // `if(s[i+1]!='\0'){ ... } else ...` -> Valid.
            // `while(s[i]!='.'){ i++; }` -> Valid.
            // `int k=i;` -> Valid C99.
            // `while(s[i]!='\0'){ s[i]=s[i+1]; i++; }` -> Valid.
            
            // Is it possible the error is not in syntax but the system reports "compile_run failed" for runtime crashes (segfault) due to bad string handling?
            // Or is there a subtle error?
            // Ah, look at line 1: `#include<stdio.h>`. Space missing? No, that's fine.
            
            // Let's reconsider the "Compilation Error" label. Sometimes this label is applied loosely to "Failed to run".
            // If I must find a compilation error, I don't see one in standard C.
            // However, if I look at the `printf` arguments:
            // `printf("%c.%se-%d",s[i],&s[i+1],i-1);`
            // If `s[i+1]` is the newline character `\n` from fgets, `%s` will print it and potentially garbage if not null-terminated properly? No, `s` is initialized to `\0` and `fgets` null-terminates.
            
            // Let's look at the `else` block again.
            // `printf("%se0",&s[0]);` -> If input is "5.0", s[0]='5', s[1]='.'. The code goes to `else` (s[0]!='0'). Then `if(s[1]!='.')` is false. So it goes to inner `else`. Prints "5.0e0"? No, `%s` on `&s[0]` prints "5.0\n" (if newline is there) or "5.0". The expected output for 5.0 is likely `5e0` or `5.0e0`? Problem says: "If it’s an integer, it contains only one significant digit without a decimal point." But input has digits after decimal. "all digits are significant". So 5.0 is not a valid input per "no trailing zeros"? "input data ... no trailing zeros after the decimal point". So 5.0 is invalid input? Or does it mean 5.1?
            // If input is 5.1, s[1] is '.', so inner else is taken? No, s[1]=='.', so `if(s[1]!='.')` is false. Inner else taken. Prints `5.1e0`. Correct format? Base 5.1. Exponent 0. Yes.
            
            // What if the "Compilation Error" is due to `int k=i;` inside the block in older C standards (C89)? Many online judges use C89/C90 where variables must be declared at the beginning of the block.
            // Line 23: `int k=i;` is declared after executable statements (`while` loop). This is a C99 feature. If the compiler is C89, this is a compilation error.
            
            // Let's assume the error is C89 compatibility.
        }
        else{
            printf("%se0",&s[0]);
        }
    }
    return 0;
}