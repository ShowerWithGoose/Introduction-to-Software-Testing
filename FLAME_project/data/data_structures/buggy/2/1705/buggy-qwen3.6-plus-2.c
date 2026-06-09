#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100];
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ [The function 'gets' is deprecated and removed in C11/C17 standards, causing compilation warnings or errors. It should be replaced with 'fgets'. Additionally, the linker error indicates missing math library linkage, but the primary source code issue here is the unsafe/removed function.]
    
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
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [The use of 'pow' requires linking the math library (-lm). While logically this parses numbers, using floating point pow for integer parsing is inefficient and prone to precision issues, but the immediate compilation/linker error is due to the missing link flag for math.h functions. In many strict environments, this causes an undefined reference error as seen in the problem description.]
            }
        }
        else{
            m=b[i]-b[i-1]-1;
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [Same as above: undefined reference to 'pow' if the math library is not linked during compilation.]
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1];
            *b[k]=*b[i+1];
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1];
            *b[k]=*b[i+1];
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1];
        }
        else if(*b[i]=='='){
            *b[k]=*b[i];
            k=k+1;
        }
    }
    
    for(i=0;i<k;i++){
        if(*b[i]=='+'){
            c[0]=c[0]+c[i+1];
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