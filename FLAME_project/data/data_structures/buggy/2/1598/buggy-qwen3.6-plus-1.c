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
    b[max+1]='\0'; // @@ The logic for removing spaces and terminating the string is flawed. `max` tracks the last index written, but `j` is the next available index. If the last character is not a space, `j` is correct for length, but `max+1` might be out of bounds or incorrect if the last char was a space (though problem says valid expr). More critically, the parsing loop below relies on `max` as the upper bound of valid characters in `b`, but `b` contains the cleaned string. The termination condition `b[max+1]='\0'` is risky. However, the major logical error is in the number parsing.
    
    do{
        for(i=mark+1;i<=max;i++){
            if(b[i]>'9'||b[i]<'0'){
                for(j=mark+1;j<i;j++){
                    num[k]=num[k]*10+(b[j]-'0'); // @@ `num[k]` is not initialized to 0 before this loop. It contains garbage value. It should be `num[k] = 0;` before the inner for loop, or use a temporary variable.
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
            num[i+1]=num[i]*num[i+1];
        }
        else if(sign[i]=='/'){
            num[i+1]=num[i]/num[i+1];
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
    printf("%d\n",result); // @@ The problem requires outputting only the integer result. This line prints an intermediate result or debug info, causing Wrong Answer due to extra output.
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