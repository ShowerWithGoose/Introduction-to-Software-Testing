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
    
    gets(a); // @@ [Using `gets` is unsafe and deprecated; however, the real issue is that `max` is used uninitialized if the input string is empty or only spaces, leading to undefined behavior. Also, `gets` may not be available in some environments causing compilation error.]
    
    for(i=0;i<strlen(a);i++){
        if(a[i]!=' '){
            max=j; // @@ [If the input contains only spaces or is empty, this block never runs, leaving `max` uninitialized. Later use of `max` leads to undefined behavior.]
            b[j++]=a[i];
        }
    }
    b[max+1]='\0'; // @@ [`max` may be uninitialized if input is empty or all spaces, causing undefined behavior when accessing `b[max+1]`.]
    
    do{
        for(i=mark+1;i<=max;i++){ // @@ [If `max` is uninitialized (e.g., empty input), this loop has undefined behavior. Also, the logic for parsing numbers is flawed: it doesn't handle the last number correctly because the loop breaks on non-digit but the final number after last operator isn't processed properly in all cases.]
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
    
    for(i=0;i<=len_sign;i++){ // @@ [This loop incorrectly assumes that multiplication/division can be applied left-to-right without considering operator precedence relative to addition/subtraction. However, the bigger issue is that it modifies `num[i+1]` but doesn't remove or skip the consumed operand, leading to incorrect results when multiple * or / are present. Also, `len_sign` may be uninitialized if no operators exist.]
        if(sign[i]=='*'){
            num[i+1]=num[i]*num[i+1];
        }
        else if(sign[i]=='/'){
            num[i+1]=num[i]/num[i+1];
        }
    }
    for(i=0;i<=len_sign;i++){
        if(sign[i]=='+'||sign[i]=='-'){
            sign1[m]=sign[i];
            num1[m]=num[i]; // @@ [This misses the fact that after processing * and /, the `num` array has been altered in place, but the indices for addition/subtraction operands are not aligned correctly. Specifically, `num[i]` may have been overwritten by prior * or / operations, and the last number (`num[len_num]`) is handled separately but inconsistently.]
            len_sum=m;
            m++;
        }
        
    }
    num1[len_sum+1]=num[len_num]; // @@ [`len_num` may be uninitialized if there are no operators (single number input), leading to undefined behavior. Also, the indexing logic is inconsistent with how many numbers were actually parsed.]
    result=num1[0];
    printf("%d\n",result); // @@ [Unnecessary intermediate print; but more critically, if there's only one number and no operators, `num1[0]` may not have been set because the prior loop only sets `num1` for '+' or '-' signs. So for input like "5 =", `num1[0]` is uninitialized.]
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