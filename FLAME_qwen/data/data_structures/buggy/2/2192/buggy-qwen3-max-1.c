#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main()  {           
    char s[100000]={"0"};
    int digit[100000]={0};
    char symbol[100000]={"0"};
    gets(s); // @@ [Using `gets()` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments (like those with GCC >= 7), `gets` is removed entirely, leading to a compilation error: "implicit declaration of function ‘gets’" or "‘gets’ was not declared in this scope". This matches the observed error "/bin/sh: 1: gcc: not found" indirectly—though that message usually indicates missing compiler, the actual issue during compilation would be failure due to `gets`. However, note: the shell error suggests environment issue, but per problem context, the real bug is use of `gets` which causes compilation failure in standard C11+ environments.]
    int i, k,b,l,j=0,a=0;
    int sum;
    for(i=0; s[i]!='\0'; i++){
        if(isdigit(s[i])){
        a=a*10+(s[i]-'0');    }            
            
        else if(s[i]!=32){
            digit[j]=a;
            a=0;
            symbol[j]=s[i];
            j++;b=j;}
    }    
    
    for(k=0;k<j;k++){
        if(symbol[k]=='*'){
        digit[k+1]=digit[k]*digit[k+1];    
        }
        else if(symbol[k]=='/'){
        digit[k+1]=digit[k]/digit[k+1];    
        }
    }
    sum=digit[0];
    for(k=0;k<j;k++){
        
        if(symbol[k]=='+'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++);
        //printf("l=%d ", l);
        //printf("%d ", digit[l]);
        sum+=digit[l];b--; 
            
            //printf("%d\n", sum);
        }
        else if(symbol[k]=='-'){
            for(l=k+1;symbol[l]!='+'&&symbol[l]!='-'&&symbol[l]!='=';l++);
        //printf("l=%d ", l);
        sum-=digit[l];    b--;
        
            //printf("%d\n", sum);    
        }
        
    }    
    if(b==j){
        sum=digit[j-1];
    }
    printf("%d", sum);
    return 0;}