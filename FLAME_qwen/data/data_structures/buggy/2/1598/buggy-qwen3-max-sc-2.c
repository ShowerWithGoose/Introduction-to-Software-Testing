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
    
    gets(a); // @@ [Using `gets` is unsafe and deprecated; may cause compilation error with modern compilers due to removal from C11 standard]
    
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
            num[i+1]=num[i]*num[i+1]; // @@ [Incorrectly modifies `num[i+1]` using unprocessed `num[i]`; should process multiplication/division in left-to-right order without overwriting operands needed later]
        }
        else if(sign[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue as above; also, integer division is correct per problem, but operand order and overwriting breaks expression evaluation]
        }
    }
    for(i=0;i<=len_sign;i++){
        if(sign[i]=='+'||sign[i]=='-'){
            sign1[m]=sign[i];
            num1[m]=num[i];
            len_sum=m;
            m++;
        }
        
    }
    num1[len_sum+1]=num[len_num];
    result=num1[0];
    printf("%d\n",result); // @@ [Premature output of intermediate value; problem requires only final result]
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