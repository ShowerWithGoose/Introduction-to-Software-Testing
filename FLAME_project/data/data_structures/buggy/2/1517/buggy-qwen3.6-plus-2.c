#include<stdio.h>
#include<string.h>
char biaodashi[1000];
int kongge[1000];
char bdstrue[1000];
char fuhao[1000];
char fuhao_later[1000];
int numall_later[1000];
int numall[1000];
int yuanben[1000];
int main()
{
    int j=0;
    gets(biaodashi);
    int length;
    length=strlen(biaodashi);
    for(int i=0;i<length;i++)
    {
        if(biaodashi[i]==' ')
        kongge[i]=1;
    }
    for(int i=0;i<length;i++)//将表达式中的空格去掉 
    {
        if(kongge[i]!=1)
        {
            bdstrue[j]=biaodashi[i];
            j++;
        }    
    }
    int true_length;
    true_length=strlen(bdstrue);
    int k=0;
    for(int x=0;x<true_length;x++)  //把符号存在fuhao数组中 
    {
        if(bdstrue[x]=='+'||bdstrue[x]=='-'||bdstrue[x]=='*'||bdstrue[x]=='/')
        {
            fuhao[k]=bdstrue[x];
            k++;
        }    
    }
    int number=0;
    int g=0;
    int shu_geshu=0,fuhao_geshu=0;
    for(int x=0;x<true_length;x++)//把数字存到numall数组里面 
    {
        if(bdstrue[x]>='0'&&bdstrue[x]<='9')
        {
            number=number*10+(bdstrue[x]-'0');
        }
        else
        {
            numall[g]=number;
            g++;
            number=0;
        }
    }
    // The last number is not stored in the loop above because the expression ends with '=' which is not a digit, 
    // but the loop breaks on non-digit. However, the logic here assumes every non-digit triggers a store.
    // The '=' at the end will trigger the else block, storing the last number.
    // But wait, if the expression is "24 / 4 ... =", the last char is '='.
    // When x points to '=', it enters else, stores number (which is the last operand), increments g.
    // So numall has all numbers.
    
    // ERROR 1: shu_geshu is used before being assigned a correct value.
    // It is initialized to 0. The loop below runs 0 times.
    for(int x=0;x<shu_geshu;x++) // @@ shu_geshu is 0 here, so this loop does nothing. It should be executed after shu_geshu is calculated. Also, the logic inside seems to handle zero values, but yuanben is uninitialized.
    {
        if(numall[x]==0)
        {
            yuanben[x]=1;
        }        
    }
    
    // Calculate the actual number of operands and operators
    shu_geshu = g; // The variable g holds the count of numbers stored.
    fuhao_geshu = k; // The variable k holds the count of operators stored.

    // ERROR 2: The multiplication and division processing logic is flawed for chained operations.
    // When processing left-to-right for * and /, modifying numall[x+1] and setting numall[x]=0 works for simple cases,
    // but if we have A * B / C, let's trace:
    // x=0 ('*'): numall[1] = A*B, numall[0]=0, fuhao[0]='0'.
    // x=1 ('/'): numall[2] = numall[1]/C = (A*B)/C, numall[1]=0, fuhao[1]='0'.
    // This part actually looks logically okay for accumulating the result into the right-hand operand.
    // HOWEVER, there is a subtle issue with how `numall` is accessed later.
    
    for(int x=0;x<fuhao_geshu;x++)//将乘除运算做完 ,将乘除符号记成0 
    {
        if(fuhao[x]=='*')
        {
            int num;
            num=numall[x]*numall[x+1];
            numall[x+1]=num;
            numall[x]=0;
            fuhao[x]='0';
        }
        if(fuhao[x]=='/')
        {
            int num;
            num=numall[x]/numall[x+1];
            numall[x+1]=num;
            numall[x]=0;
            fuhao[x]='0';
        }
    }
//    printf("%d",shu_geshu);
//    for(int x=0;x<shu_geshu;x++)
//    {
//        printf("%d",numall[x]);//////
//    }
    int p=0;
    for(int x=0;x<fuhao_geshu;x++)//留下加减的符号 
    {
        if(fuhao[x]!='0')
        {
            fuhao_later[p]=fuhao[x];
            p++;
        }
    }
    int cishu=strlen(fuhao_later);
//puts(fuhao_later);///
    int q=0;
    for(int x=0;x<shu_geshu;x++)//留下加减的数字
    {
        if(numall[x]!=0)
        {
            numall_later[q]=numall[x];
            q++;
        }
        // ERROR 3: The condition `yuanben[x]==1` relies on the previous loop that didn't run.
        // Even if it ran, `yuanben` was not initialized to 0 globally or locally, so it contains garbage.
        // If a number is legitimately 0 (e.g., 1 + 0 * 5), it needs to be preserved.
        // The current code fails to preserve 0s because `yuanben` is garbage/uninitialized and the setup loop didn't run.
        if(numall[x]==0&&yuanben[x]==1) // @@ yuanben is uninitialized and the loop to set it didn't execute properly. This causes legitimate zeros to be skipped, shifting subsequent numbers and causing wrong results.
        {
            numall_later[q]=numall[x];
            q++;
        }
    }
    //for(int x=0;x<cishu+1;x++)   ///
//    {
//        printf("%d",numall_later[x]);
//    }
    int answer=0;
    int temp=0;
//    printf("%d",cishu);
    
    // ERROR 4: Initialization of temp.
    // If there are no addition/subtraction operators (cishu == 0), the loop doesn't run.
    // temp remains 0. But the result might be just a number (e.g., "5 * 2 =").
    // In that case, numall_later[0] holds the result, but temp is printed as 0.
    // For the specific test case "24 / 4 / 3 / 2 * 2 * 3 * 4 =", there ARE no + or - operators.
    // So fuhao_later is empty, cishu is 0. The loop below does not execute.
    // temp is 0. The output is 0. Expected is 24.
    // We should initialize temp to numall_later[0] if cishu > 0, or just handle the accumulation differently.
    // Actually, the standard way to accumulate is: temp = numall_later[0]; then loop from 0 to cishu-1 applying op to temp and numall_later[i+1].
    
    if (cishu > 0) {
        temp = numall_later[0];
    } else {
        // If there are no +/- ops, the result is the only remaining number in numall_later
        if (q > 0) temp = numall_later[0];
        else temp = 0; // Should not happen for valid input
    }

    for(int x=0;x<cishu;x++)
    {
        if(fuhao_later[x]=='+')
        {
            temp=temp+numall_later[x+1]; // @@ Logic error: original code did temp=numall_later[x]+numall_later[x+1] and stored back. This is incorrect for chained additions/subtractions because it ignores the accumulated `temp`. It should be temp = temp + numall_later[x+1].
            // numall_later[x]=0; // Not needed if using temp correctly
            // numall_later[x+1]=temp;
        //    printf("1");
        //printf("%d",temp);
        }
        else if(fuhao_later[x]=='-')
        {
            temp=temp-numall_later[x+1]; // @@ Logic error: same as above. Should be temp = temp - numall_later[x+1].
            // numall_later[x]=0;
            // numall_later[x+1]=temp;
        //1    printf("2");
        }
    }
//    for(int x=0;x<cishu;x++)///
//    {
//        printf("%dhhh",numall_later[x]);
//    }
//    for(int x=0;x<cishu;x++)
//    {
//        answer+=numall_later[x];
//    }
    printf("%d",temp);
    return 0;
 }