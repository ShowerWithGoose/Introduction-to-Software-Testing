#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char a[100],b[100],sign[50],sign1[50];
int num[100],num1[100];

int main()
{
    int i,j=0,k=0,l=0,max;
    int mark=-1,m=0;
    int len_num,len_sign,len_sum=0; // @@ len_sign is uninitialized; if there are no operators, it remains garbage, leading to undefined behavior in loops.
    int result;
    
    gets(a);
    
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
            len_sign=l; // @@ If no operators exist, this line is never executed, leaving len_sign uninitialized.
            l++;
        }
    }
    
    for(i=0;i<=len_sign;i++){ // @@ Using uninitialized len_sign when no operators, causing out-of-bounds access.
        if(sign[i]=='*'){
            num[i+1]=num[i]*num[i+1];
        }
        else if(sign[i]=='/'){
            num[i+1]=num[i]/num[i+1];
        }
    }
    for(i=0;i<=len_sign;i++){ // @@ Using uninitialized len_sign again; same issue.
        if(sign[i]=='+'||sign[i]=='-'){
            sign1[m]=sign[i];
            num1[m]=num[i];
            len_sum=m;
            m++;
        }
        
    }
    num1[len_sum+1]=num[len_num];
    result=num1[0];
    printf("%d\n",result); // @@ Extra output line that is not part of the expected result; should not print intermediate value.
    for(i=0;i<=len_sum;i++){
        if(sign1[i]=='+'){ // @@ If no '+' or '-' operators, sign1[0] is uninitialized; accessing it causes undefined behavior.
            result=result+num1[i+1];
        }
        else if(sign1[i]=='-'){ // @@ Same issue: sign1[0] may be garbage.
            result=result-num1[i+1];
        }
    }
    
    printf("%d",result);
    
    return 0;
}