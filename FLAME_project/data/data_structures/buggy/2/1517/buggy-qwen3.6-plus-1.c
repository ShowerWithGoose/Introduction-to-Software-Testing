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
    // The last number is not stored in the loop above because the string ends with '=' or null, not a digit followed by a non-digit in the way expected if '=' is present. 
    // However, looking at the logic: if the expression ends with '=', the last char is '='.
    // The loop condition `bdstrue[x]>='0'...` fails for '='. So it goes to else.
    // It stores `number` into `numall[g]`. This seems correct for the last number before '='.
    
    // But wait, `shu_geshu` is initialized to 0 and never updated before use in the next loop.
    for(int x=0;x<shu_geshu;x++) // @@ [Error: shu_geshu is 0 here, so this loop never executes. Even if it did, yuanben is not properly populated for all numbers. This block is logically flawed and unused effectively.]
    {
        if(numall[x]==0)
        {
            yuanben[x]=1;
        }        
    }
    shu_geshu=strlen(fuhao)+1; // @@ [Error: strlen(fuhao) relies on fuhao being null-terminated. fuhao is filled with chars but never null-terminated. This leads to undefined behavior/incorrect length.]
    fuhao_geshu=strlen(fuhao); // @@ [Error: Same as above, fuhao is not null-terminated, so strlen may read beyond bounds.]
    
    // To fix the termination issue properly, we should have set fuhao[k] = '\0' after the first loop.
    // Also, the logic for handling division/multiplication sequentially is flawed for left-associativity if not careful, but let's look at the specific failure.
    
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
    // fuhao_later is also not null-terminated here.
    int cishu=strlen(fuhao_later); // @@ [Error: fuhao_later is not null-terminated, leading to incorrect length calculation.]
//puts(fuhao_later);///
    int q=0;
    for(int x=0;x<shu_geshu;x++)//留下加减的数字
    {
        if(numall[x]!=0)
        {
            numall_later[q]=numall[x];
            q++;
        }
        if(numall[x]==0&&yuanben[x]==1)
        {
            numall_later[q]=numall[x];
            q++;
        }
    }
    // The logic for filtering out zeros (results of consumed operands in mul/div) is fragile. 
    // If an intermediate result is legitimately 0, it might be skipped unless yuanben marks it. 
    // But yuanben was never properly set because the loop using it was skipped/empty.
    
    //for(int x=0;x<cishu+1;x++)   ///
//    {
//        printf("%d",numall_later[x]);
//    }
    int answer=0;
    int temp=0;
//    printf("%d",cishu);
    for(int x=0;x<cishu;x++)
    {
        if(fuhao_later[x]=='+')
        {
            temp=numall_later[x]+numall_later[x+1];
            numall_later[x]=0;
            numall_later[x+1]=temp;
        //    printf("1");
        //printf("%d",temp);
        }
        else if(fuhao_later[x]=='-')
        {
            temp=numall_later[x]-numall_later[x+1];
            numall_later[x]=0;
            numall_later[x+1]=temp;
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