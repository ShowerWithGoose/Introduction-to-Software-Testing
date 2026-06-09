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
            printf("%c.%se-%d",s[i],&s[i+1],i-1); // @@ [Error: Using &s[i+1] with %s format specifier prints the address or causes undefined behavior/crash instead of the substring. Should use s+i+1 or pass the pointer correctly, but more importantly, logic for exponent is wrong for numbers like 0.00123. Also, fgets includes newline, so s[i+1] might be '\n' or '\0'. The main compilation/runtime error source is likely the misuse of & in printf arguments for strings.]
        }
        else
        printf("%ce-%d",s[i],i-1);
    }
    else{
        if(s[1]!='.'){
        i=1;
        while(s[i]!='.'){
            i++;
        }
        int k=i;
        while(s[i]!='\0'){
            s[i]=s[i+1];
            i++;
        }
        printf("%c.%se%d",s[0],&s[1],k-1); // @@ [Error: Using &s[1] with %s format specifier is incorrect syntax for passing a string substring in this context if intended as a pointer, it should be s+1. However, &s[1] is technically a char*, so it might compile but the logic is fragile. The primary issue reported is Compilation Error, which often stems from mismatched format specifiers or types in stricter compilers, or potentially the previous line. But looking closely, &s[i+1] and &s[1] are char pointers, so they are valid for %s. The "Compilation Error" might be due to something else or a specific environment. Wait, the prompt says "Compilation Error". Let's look for syntax errors. There are no obvious syntax errors. However, using &array[index] is valid C for getting a pointer. Is there a missing header? No. Maybe the error is logical but reported as compile/run fail? The prompt asks to identify location of errors. If it's a compilation error, it might be due to variable declaration inside block in older C standards (C89). `int k=i;` is declared inside the else block. If compiled as C89, this is an error.]
        }
        else{
            printf("%se0",&s[0]); // @@ [Error: Similar to above, &s[0] is used for %s. While technically a pointer, standard practice is s. If the compiler is strict or C89, the mixed declarations/code or internal declaration might be the issue. But the most likely "Compilation Error" in student environments for this code structure is declaring `int k` in the middle of the block if C89 mode is enforced, or potentially warnings treated as errors. However, looking at the previous printf calls, they all use &s[...] for %s. This is syntactically valid in C. Let's re-read carefully. "Compilation Error". In C89, variables must be declared at the beginning of the block. `int k=i;` is declared after executable statements `while...`. This is invalid in C89/C90.]
        }
    }
    return 0;
}