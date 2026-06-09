#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; // @@ [b is an array of char pointers, but it's used to point into a which is modified in-place; however, the bigger issue is that b[n] stores pointers to operator positions, but later logic assumes numbers are between these operators without correctly parsing multi-digit numbers in all cases]
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ [gets() is unsafe and deprecated; more critically, if input has no spaces, j may not be properly bounded leading to potential buffer issues, but main logic errors are elsewhere]
    
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
            b[n]=&a[i]; // @@ [b[n] stores pointer to operator, but the number parsing logic that follows assumes that the first number starts at a[0], and subsequent numbers are between operators. However, if the expression starts with a negative number (not in spec, but even so), or more critically, the last token before '=' is not handled as a number correctly because b only stores operators, so number count becomes n, but there are n+1 numbers]
            n++;
        }
        else{
        } 
    }

    for(i=0;i<n;i++){ // @@ [This loop tries to parse n numbers, but there are actually n+1 numbers in an expression with n operators (including '=')]
        if(i==0){
            m=b[i]-&a[0]; // @@ [m is the length of the first number, but if the first token is a number followed by operator at b[0], this works only if the number is before the first operator. However, if the expression is like "123=", then b[0] points to '=', and m = index of '=' which is correct. But the loop runs only n times, missing the last number if '=' is counted as an operator]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Using pow() for integer powers introduces floating-point inaccuracies; e.g., pow(10,2) might be 99.999... leading to truncation error when cast to int]
            }
        }
        else{
            m=b[i]-b[i-1]-1; // @@ [Distance between two operators, assumed to be a number. But if there are consecutive operators (not allowed per problem, but still), or if the last number is after the last operator before '=', this may fail. Also, if '=' is the last operator, the number before it is parsed here, but what about expressions ending with '='? It should work, but combined with loop bound i<n, and n includes '=', it might parse one less number]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Same floating-point inaccuracy issue with pow()]
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){ // @@ [n includes the '=' as an operator, so i goes from 0 to n-1, where b[n-1] is '='. The logic processes operators including '*', '/', '+', '-', and '='. However, when *b[i] is '=', it sets *b[k]='=' and increments k, but then in the next loop, it uses *b[i] for i<k, and expects to find '=' to print. But the handling of '=' here disrupts operator precedence processing]
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1]; // @@ [c[i+1] accesses beyond parsed numbers: since only n numbers were parsed (in previous loop), but i+1 can be up to n, which is out of bounds because c has indices 0..n-1]
            *b[k]=*b[i+1]; // @@ [*b[i+1] may be out of bounds if i+1 >= n]
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1]; // @@ [Same out-of-bounds access: c[i+1] when i = n-1 (if last operator is '/') would access c[n], which was never initialized]
            *b[k]=*b[i+1]; // @@ [Same pointer out-of-bounds]
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1]; // @@ [Again, c[i+1] may be out of bounds]
        }
        else if(*b[i]=='='){
            *b[k]=*b[i];
            k=k+1;
        }
    }
    
    for(i=0;i<k;i++){ // @@ [k may be less than the number of operators processed, but the main issue is that c[0] is updated cumulatively, but if there was a '-' at the beginning, it's not handled. Also, the '=' case prints inside the loop, but if '=' is not encountered (though it should be), nothing prints. More critically, the loop condition i<k, but b[k-1] might be '=', so when i=k-1, *b[i]=='=', and it prints c[0]. However, if there are multiple '+'/'-' after precedence handling, the accumulation may be incorrect due to earlier out-of-bound reads]
        if(*b[i]=='+'){
            c[0]=c[0]+c[i+1]; // @@ [c[i+1] again may be out of bounds; also, after precedence processing, the c array should have been compacted, but the indexing assumes original structure]
        }
        else if(*b[i]=='-'){
            c[0]=c[0]-c[i+1]; // @@ [Same out-of-bounds risk]
        }
        else if(*b[i]=='='){
            printf("%d",c[0]);
        }
    }
    
    return 0;
}