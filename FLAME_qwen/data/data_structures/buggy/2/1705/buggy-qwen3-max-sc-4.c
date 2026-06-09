#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; // @@ [b is an array of char pointers, but it's used to point into a, which is fine; however, the logic that follows has multiple semantic errors]
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ [gets() is unsafe and deprecated; may cause compilation error with modern compilers due to removal from standard library]
    
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
            b[n]=&a[i];
            n++;
        }
        else{
        } 
    }

    for(i=0;i<n;i++){
        if(i==0){
            m=b[i]-&a[0];
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Using pow() for integer arithmetic introduces floating-point inaccuracies and is inefficient; also, this loop assumes digits are before operator, but first token is number before first operator, yet b[0] points to first operator, so b[0]-m may go out of bounds if expression starts with number]
            }
        }
        else{
            m=b[i]-b[i-1]-1;
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Same issue: uses floating-point pow(), and indexing logic is flawed; also, c[i] corresponds to operand before operator b[i], but loop structure mismatches operand-operator alignment]
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1]; // @@ [c[i+1] may be uninitialized or incorrect because c[] was filled assuming each operator corresponds to preceding number, but indexing doesn't align; also, k not properly managed]
            *b[k]=*b[i+1]; // @@ [b[k] is a pointer into original string; overwriting its value corrupts operator tracking]
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1]; // @@ [Same indexing and initialization issues as above]
            *b[k]=*b[i+1];
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1]; // @@ [c[i+1] likely invalid; operands not correctly parsed or stored]
        }
        else if(*b[i]=='='){
            *b[k]=*b[i];
            k=k+1;
        }
    }
    
    for(i=0;i<k;i++){
        if(*b[i]=='+'){
            c[0]=c[0]+c[i+1]; // @@ [c[i+1] may be out of valid range; logic assumes c[0] accumulates result but previous step didn't ensure correct operand storage]
        }
        else if(*b[i]=='-'){
            c[0]=c[0]-c[i+1];
        }
        else if(*b[i]=='='){
            printf("%d",c[0]);
        }
    }
    
    return 0;
}