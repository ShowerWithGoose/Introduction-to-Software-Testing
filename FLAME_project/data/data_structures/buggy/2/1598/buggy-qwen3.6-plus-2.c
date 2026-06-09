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
    b[max+1]='\0'; // @@ The null terminator is placed incorrectly. It should be b[j] = '\0' after the loop, or b[max+1] is correct only if max tracks the last valid index properly, but here max is updated inside the if. If the string ends with non-space, j increments, max becomes j-1. Then b[max+1] is b[j], which is correct. However, if the input is empty or only spaces, this might be problematic. But the main logic error is elsewhere.
    
    do{
        for(i=mark+1;i<=max;i++){
            if(b[i]>'9'||b[i]<'0'){
                for(j=mark+1;j<i;j++){
                    num[k]=num[k]*10+(b[j]-'0'); // @@ num[k] is not initialized to 0 before this loop. It contains garbage value.
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
    num1[len_sum+1]=num[len_num]; // @@ This assumes the last number is at index len_num. However, after multiplication/division, the result is stored in num[i+1]. The last number might have been modified or its index changed. Also, if the last operation was * or /, the result is in the higher index. If the last operator was + or -, the last number is at num[len_num]. But if the expression ends with a number that was part of a * or / chain, it's handled. The issue is that num1 array is populated with num[i] for + and - operators. The last number needs to be appended. len_num is the index of the last parsed number. This line tries to append the last number. However, if the last operator was * or /, the result is already in num array at a specific position. The logic for extracting the final operands for + and - is flawed because it doesn't account for the fact that num array values have been overwritten by * and / results. Specifically, num1[m] takes num[i]. If sign[i] is + or -, it takes num[i]. But num[i] might have been the result of a previous * or / if i > 0. Wait, the * and / loop updates num[i+1]. So num[i] remains unchanged if it was the left operand? No, num[i+1] becomes the result. So num[i] is still the original left operand. This is incorrect. The result of 20 * 30 should replace one of them. Here num[1] becomes 600. num[0] is still 10. Then for +, num1[0] = num[0] = 10. For -, num1[1] = num[1] = 600? No, sign[1] is *. It is skipped in the second loop. sign[2] is -. num1[1] = num[2]. What is num[2]? Original parsing: num[0]=10, num[1]=20, num[2]=30, num[3]=40, num[4]=5. After * loop: num[2] = num[1]*num[2] = 600. num[1] is still 20. After / loop: num[4] = num[3]/num[4] = 8. num[3] is still 40. Then the +,- loop: i=0, sign[0]='+'. num1[0]=num[0]=10. m=1. i=1, sign[1]='*'. Skip. i=2, sign[2]='-'. num1[1]=num[2]=600. m=2. i=3, sign[3]='/'. Skip. len_sum=1. num1[len_sum+1] = num1[2] = num[len_num]. len_num was incremented to 4 (last k was 4, then k++ made it 5? No. k starts 0. First num: k=0, len_num=0, k becomes 1. Second: k=1, len_num=1, k becomes 2. Third: k=2, len_num=2, k becomes 3. Fourth: k=3, len_num=3, k becomes 4. Fifth: k=4, len_num=4, k becomes 5. So len_num=4. num[4] is 8 (result of 40/5). So num1[2]=8. result=num1[0]=10. Loop i=0 to len_sum (1). i=0: sign1[0]='+'. result += num1[1] => 10 + 600 = 610. i=1: sign1[1]='-'. result -= num1[2] => 610 - 8 = 602. This seems correct? Why did it fail?
    
    // Let's re-read the bug report. Buggy Output: 10 \n 602. Expected: 602.
    // The code prints result twice. Once before the calculation loop? No.
    // printf("%d\n",result); is called BEFORE the addition/subtraction loop.
    // At that point, result=num1[0], which is 10.
    // Then the loop calculates the final result.
    // Then printf("%d",result); prints 602.
    // So the output is "10\n602". The expected is "602".
    // The first printf is premature and incorrect.
    
    result=num1[0];
    printf("%d\n",result); // @@ This prints the intermediate result (the first number) before the final calculation is complete, causing wrong output format and value.
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