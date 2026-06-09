//
//  main.c
//  表达式计算
//
//  Created by  on 2022/3/5.
////思路：首先分别存入数字到num数组里以及运算符号到op数组里
//然后定义指针分别用来判断加减号是否存在以及做一个循环（目前看不太现实）
//定位加减号后计算中间的乘除法(目前来看应该再开一个result数组记录乘除法的结果)
//定义一个数来表示最后的结果并输出
//目前卡的地方在于最后一个加减号后如果有乘除，就无法输出，目前已经编了一个计算最后一个加减号到最后的乘除法，但是无法加起来。
//目前的问题在于第一个加减号之前的乘除法

#include<stdio.h>
#include <string.h>
int num[500] = {0};
char op[500];
int position[500];//用来存储加减号的位置
int main(int argc, const char *argv[])
{
    int i=0, j=0, k=0, l=0, m=0, n=0;
    int length = 0;
    char *p_add;
    char *p_minus;
    char *p;
    p = op;
    char c = '+';//用来跳过空格并存入字符
    int sum = 0;//代表着总和
    int final_sum = 0;
    int first_sum = 0;
    int result = 0;//最后一个加减法到等于号之间的总和
    while (c!='=')//数据读入
    {
        scanf("%d",&num[length]);
        scanf("%c",&c);
        if (c==' ')
        {
            scanf("%c",&c);
            op[length]=c;
        }
        else op[length]=c;
        length++;
    }
    //printf("length = %d\n",length-1);
//    for (i=0; i<length; i++)
//    {
//        printf("%d ",num[i]);
//    }
//    printf("\n");
//    for (i=0; i<length-1; i++)
//    {
//        printf("%c ",op[i]);
//    }
//    printf("\n");
    if ((p_add=strchr(p, '+'))==NULL && (p_minus=strchr(p, '-'))==NULL)
    {
        final_sum = num[0];
        printf("%d\n",final_sum);
        return 0;
    }//没有的话直接输出那个数就行
    else//用position数组存储加减号的位置
    {
        for (i=0; i<=length-1; i++)
        {
            if (op[i]=='+' || op[i]=='-')
            {
                position[j]=i;
                j++;
            }
        }
        //printf("j = %d\n",j);
        //printf("最后一个加减号的位置是：%d\n",position[j-1]);
        //让sum等于第一个加/减号右边的那个数字
        //printf("%d\n",position[1]);
        if (position[0]>0)
        {
            first_sum = num[0];
            for (i=0; i<position[0]; i++)
            {
                switch (op[i])
                {
                    case '*':
                        first_sum*=num[i+1];
                        break;
                        
                    case '/':
                        first_sum/=num[i+1];
                        break;
                }
            }
            //printf("%d\n",first_sum);
        }
        else first_sum = num[position[0]];
        if (position[1]==0)//如果只有一个加号或者减号
        {
            result = num[position[0]+1];
            //printf("result = %d\n",result);
            for (k=position[0]; k<length; k++)
            {
                switch (op[k])
                {
                    case '*':
                        result=result*num[k+1];
                        break;

                    case '/':
                        result=result/num[k+1];
                        break;
                }
                //printf("result = %d ",result);
            }
            switch (op[position[0]])
            {
                case '+':
                    final_sum=first_sum+result;
                    break;
                    
                case '-':
                    final_sum=first_sum-result;
                    break;
            }
            printf("%d\n",final_sum);
            return 0;
        }
        for (i=0; i<=j-1; i++)//i用来记录position里面加减号对应的位置
        {
            //printf("i = %d ",i);
            result = num[position[i]+1];
            if (i==j-1)
            {
                break;
            }
            //printf("result = %d\n",result);
            //printf("position[%d]+1 = %d, position[%d] = %d\n",i,position[i]+1,i+1,position[i+1]);
            for (k=position[i]+1; k<=position[i+1]; k++)//这块注意等号
            {
                //printf("k = %d\n",k);
                switch (op[k])
                {
                    case '*':
                        result=result*num[k+1];
                        break;
                        
                    case '/':
                        result=result/num[k+1];
                        break;
                }
                //printf("result = %d ",result);
            }//计算中间的乘除法
            if (i==0)
            {
                switch (op[position[i]])
                {
                    case '+':
                        sum=first_sum+result;
                        break;
                        
                    case '-':
                        sum=first_sum-result;
                        break;
                }
                final_sum+=sum;
                //printf("sum = %d final_sum = %d\n",sum,final_sum);
            }
            else
            {
                switch (op[position[i]])
                {
                    case '+':
                        sum=final_sum+result;
                        break;
                        
                    case '-':
                        sum=final_sum-result;
                        break;
                }
                final_sum = sum;
                //printf("sum = %d final_sum = %d\n",sum,final_sum);
            }
        }
    }
    //printf("\n");
    //result = num[position[j-1]+1];
    if (j-1<length)//解决最后一个加减号到结尾的乘除法
    {
        for (k=position[j-1]; k<length; k++)
        {
            switch (op[k])
            {
                case '*':
                    result=result*num[k+1];
                    break;

                case '/':
                    result=result/num[k+1];
                    break;
            }
            //printf("result = %d ",result);
        }
    }
    switch (op[position[j-1]])
    {
        case '+':
            result+=final_sum;
            break;
            
        case '-':
            result=final_sum-result;
            break;
    }
    final_sum = result;
    printf("%d\n",final_sum);
    return 0;
}

