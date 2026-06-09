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
            len_sign=l;
            l++;
        }
    }
    
    for(i=0;i<=len_sign;i++){
        if(sign[i]=='*'){
            num[i+1]=num[i]*num[i+1]; // @@ [This overwrites num[i+1] but does not zero out or skip num[i], causing it to be reused in later addition/subtraction. Also, multiplication/division should be evaluated left-to-right with precedence, but this approach doesn't handle chained * and / correctly because it modifies operands in place without adjusting the operator list.]
        }
        else if(sign[i]=='/'){
            num[i+1]=num[i]/num[i+1]; // @@ [Same issue as above: modifies num[i+1] in place without removing the consumed operand/operator, leading to incorrect reuse of values during the addition/subtraction pass.]
        }
    }
    for(i=0;i<=len_sign;i++){
        if(sign[i]=='+'||sign[i]=='-'){
            sign1[m]=sign[i];
            num1[m]=num[i]; // @@ [num[i] may have been overwritten by prior multiplication/division steps, but more critically, after handling * and /, the array `num` is not compacted, so indices no longer align with remaining operators. For example, in "10 + 20 * 30", after computing 20*30=600 into num[2], num[1] is still 20, and then num1[0] = num[0] = 10, but num1[1] = num[1] = 20 (not 600), causing wrong result.]
            len_sum=m;
            m++;
        }
        
    }
    num1[len_sum+1]=num[len_num]; // @@ [This assumes the last number is at num[len_num], but due to in-place updates during * and /, the final effective numbers are not properly collected. The logic fails to build a new list of terms after processing * and /.]
    result=num1[0];
    printf("%d\n",result); // @@ [This prints an intermediate value (num1[0]) which is not part of the required output; the problem only expects the final result. This causes extra output ("10") before the correct answer ("602"), matching the buggy output shown.]
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