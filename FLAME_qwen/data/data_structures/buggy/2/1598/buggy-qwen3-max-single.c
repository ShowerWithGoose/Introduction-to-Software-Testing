#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char a[100],b[100],sign[50],sign1[50];
int num[100],num1[100];

int main()
{
    int i,j=0,k=0,l=0,max;
    int mark=-1,m=0;
    int len_num,len_sign,len_sum=0;
    int result;
    
    gets(a); // @@ [Using `gets` is unsafe and deprecated; it may cause buffer overflow. More critically, in many modern environments, `gets` is not available, leading to compilation errors. Use `fgets` instead.]
    
    for(i=0;i<strlen(a);i++){
        if(a[i]!=' '){
            max=j;
            b[j++]=a[i];
        }
    }
    b[max+1]='\0';
    
    do{
        for(i=mark+1;i<=max;i++){
            if(b[i]>'9'||b[i]<'0'){
                for(j=mark+1;j<i;j++){
                    num[k]=num[k]*10+(b[j]-'0');
                }
                len_num=k;
                k++;
                mark=i;
                break;
                }
        }
    }while(mark<=max-1);
    
    for(i=0;i<=max;i++){
        if(b[i]=='+'||b[i]=='-'||b[i]=='*'||b[i]=='/'){
            sign[l]=b[i];
            len_sign=l;
            l++;
        }
    }
    
    for(i=0;i<=len_sign;i++){
        if(sign[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [Incorrectly modifies `num[i+1]` using `num[i]`, but `num[i]` might have already been altered by a previous operation (e.g., if there are consecutive * or /). This breaks operator precedence handling because it doesn't isolate multiplication/division groups properly.]
        }
        else if(sign[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue as above: uses `num[i]` which may have been overwritten, and integer division truncation is correct per problem, but logic is flawed due to in-place modification without preserving original values.]
        }
    }
    for(i=0;i<=len_sign;i++){
        if(sign[i]=='+'||sign[i]=='-'){
            sign1[m]=sign[i];
            num1[m]=num[i]; // @@ [This captures `num[i]` after it may have been modified by prior * or / operations, but misses the last number in sequences like "a*b+c" because it only stores `num[i]` at operator positions, not the final term correctly.]
            len_sum=m;
            m++;
        }
        
    }
    num1[len_sum+1]=num[len_num];
    result=num1[0];
    printf("%d\n",result); // @@ [Premature output of intermediate value; problem requires only final result. Also, extra newline may cause format mismatch.]
    for(i=0;i<=len_sum;i++){
        if(sign1[i]=='+'){
            result=result+num1[i+1];
        }
        else if(sign1[i]=='-'){
            result=result-num1[i+1];
        }
    }
    
    printf("%d",result);
    
    return 0;
}