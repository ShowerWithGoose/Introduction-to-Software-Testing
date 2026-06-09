#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
    char a[200],*b[100]; // @@ [b is an array of char pointers, but it's used to point into a[] which is fine; however, the logic that follows has multiple flaws]
    int i,j=0,n=0,c[100]={0},m,k;
    
    gets(a); // @@ [gets() is unsafe and deprecated; more critically, if input contains no spaces, j may not be properly bounded leading to issues later]
    
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
            b[n]=&a[i]; // @@ [b[n] stores pointer to operator, but number parsing assumes operators separate numbers correctly; fails when expression starts with negative number or has adjacent operators]
            n++;
        }
        else{
        } 
    }

    for(i=0;i<n;i++){
        if(i==0){
            m=b[i]-&a[0]; // @@ [m is length of first number string, but if expression starts with operator (e.g., "-5+3="), this logic breaks because there's no number before first operator]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [uses floating-point pow() for integer arithmetic, which can cause precision errors; also, loop direction may misalign digits]
            }
        }
        else{
            m=b[i]-b[i-1]-1; // @@ [assumes exactly one number between operators; fails if two operators are adjacent (like in "5*-3") which isn't allowed per problem but code doesn't handle edge cases robustly]
            for(;m>=1;m--){
                c[i]=(*(b[i]-m)-'0')*pow(10.,(float)(m-1))+c[i]; // @@ [same pow() precision issue; also indexing may go out of bounds if m is 0]
            }
        }
    }
    
    for(i=0,k=0;i<n;i++){
        if(*b[i]=='*'){
            c[k]=c[k]*c[i+1]; // @@ [c[i+1] may be uninitialized or incorrect because c[] was filled assuming each operator corresponds to a preceding number, but indexing mismatches occur]
            *b[k]=*b[i+1]; // @@ [modifies original string via pointer; dangerous and logically flawed since b[k] points into a[], and overwriting affects future reads]
        }
        else if(*b[i]=='/'){
            c[k]=c[k]/c[i+1]; // @@ [same issue: c[i+1] likely wrong index; also integer division is okay per spec, but operands may be incorrect]
            *b[k]=*b[i+1];
        }
        else if(*b[i]=='+'||*b[i]=='-'){
            k=k+1;
            c[k]=c[i+1]; // @@ [again uses c[i+1] which doesn't correspond to the next number due to earlier parsing errors]
        }
        else if(*b[i]=='='){
            *b[k]=*b[i];
            k=k+1;
        }
    }
    
    for(i=0;i<k;i++){
        if(*b[i]=='+'){
            c[0]=c[0]+c[i+1]; // @@ [c[i+1] is likely beyond valid range or holds wrong value; accumulation logic is broken due to prior indexing mistakes]
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