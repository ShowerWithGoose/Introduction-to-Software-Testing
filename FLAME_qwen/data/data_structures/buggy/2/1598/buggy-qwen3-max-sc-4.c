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
    
    gets(a); // @@ [Using `gets` is unsafe and deprecated; however, the primary error causing failure is uninitialized `num` array leading to incorrect parsing and computation]
    
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
                    num[k]=num[k]*10+(b[j]-'0'); // @@ [The `num` array is not initialized to zero, so `num[k]` starts with garbage values, leading to incorrect number parsing]
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
            num[i+1]=num[i]*num[i+1]; // @@ [This logic incorrectly modifies `num[i+1]` without preserving original values needed for later operations; also assumes left-to-right evaluation without respecting operator precedence correctly in context of stored numbers]
        }
        else if(sign[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue as above; overwrites `num[i+1]`, corrupting data needed for subsequent steps]
        }
    }
    for(i=0;i<=len_sign;i++){
        if(sign[i]=='+'||sign[i]=='-'){
            sign1[m]=sign[i];
            num1[m]=num[i]; // @@ [Does not account for modified `num` array from previous multiplication/division step correctly; misses the last operand in some cases]
            len_sum=m;
            m++;
        }
        
    }
    num1[len_sum+1]=num[len_num];
    result=num1[0];
    printf("%d\n",result); // @@ [Premature output of intermediate value (likely garbage or partial result), which is not required by problem statement]
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