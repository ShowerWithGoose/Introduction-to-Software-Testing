#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; // @@ [b is an array of pointers to char, but it's used to store operator positions; however, the logic that follows assumes b[i] points into a, which is okay, but later usage has flaws]
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ [gets() is unsafe and deprecated; more critically, in some environments it may not be available, leading to compilation error if stdio doesn't support it. However, the reported error is "gcc: not found", which is environment-related, but assuming the real issue is within code: the actual bug is logical, but the prompt says "Compilation Error". However, gets() may cause compilation failure in strict C standards (e.g., C11+ without enabling). But more importantly, the real compilation issue might stem from other problems. However, looking deeper...]
    
    for(i=0;i<strlen(a);i++){
        if(a[i]==' '){
        }
        else{
            a[j]=a[i];
            j++;
        }
    }
    a[j]='\0';
    
    for(i=0;i<j;i++){
        if(a[i]=='+'||a[i]=='-'||a[i]=='*'||a[i]=='/'||a[i]=='='){
            b[n]=&a[i]; // @@ [This stores pointer to operator character in a. OK so far.]
            n++;
        }
        else{
        } 
    }

    for(i=0;i<n;i++){
        if(i==0){
            m=b[i]-&a[0]; // @@ [m is the number of digits before first operator. Correct.]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Using pow() from math.h for integer powers is error-prone due to floating point inaccuracies. For example, pow(10,2) might yield 99.999..., which becomes 99 when cast to int. This causes incorrect number parsing. Also, this line assumes the first token is a number, but if expression starts with '-', this fails. However, problem says expression is valid and doesn't specify negative numbers, so maybe not. But pow() is the real issue here.]
            }
        }
        else{
            m=b[i]-b[i-1]-1; // @@ [Number of characters between two operators. Correct.]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Same floating-point precision issue with pow()]
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1]; // @@ [This assumes c[i+1] exists, but when i = n-1 (last operator is '*'), c[i+1] is out of bounds. Also, the indexing logic is flawed: c[] was filled with n numbers (from n operators), but there are actually n+1 numbers in an expression with n operators. So c has size 100, but only n entries were parsed, missing the last number after the final '='. This leads to undefined behavior.]
            *b[k]=*b[i+1]; // @@ [b[i+1] may be out of bounds if i = n-1]
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1]; // @@ [Same out-of-bounds access for c[i+1] and b[i+1]]
            *b[k]=*b[i+1];
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1]; // @@ [Again, c[i+1] may be invalid]
        }
        else if(*b[i]=='='){
            *b[k]=*b[i];
            k=k+1;
        }
    }
    
    for(i=0;i<k;i++){
        if(*b[i]=='+'){
            c[0]=c[0]+c[i+1]; // @@ [c[i+1] may be uninitialized or out of valid range]
        }
        else if(*b[i]=='-'){
            c[0]=c[0]-c[i+1]; // @@ [Same issue]
        }
        else if(*b[i]=='='){
            printf("%d",c[0]);
        }
    }
    
    return 0;
}