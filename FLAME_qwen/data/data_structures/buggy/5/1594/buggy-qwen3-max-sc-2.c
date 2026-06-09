#include<stdio.h>

#define MAXLENGTH 10000

int coefficient1[MAXLENGTH];
int index1[MAXLENGTH];
int coefficient2[MAXLENGTH];
int index2[MAXLENGTH];
int outco[MAXLENGTH];
int outin[MAXLENGTH];


int insert(int outco[],int outin[],int num,int co,int in);
int main()
{
    int num1=0;
    int num2=0;
    
    int co,in;
    char ch;
    do
    {
        scanf("%d%d%c",&co,&in,&ch);
        coefficient1[num1]=co;
        index1[num1]=in;
        num1++;
    }while(ch!='\n');
    do
    {
        scanf("%d%d%c",&co,&in,&ch);
        coefficient2[num2]=co;
        index2[num2]=in;
        num2++;
    }while(ch!='\n');
    
    int num=num1;
    for(int i=0;i<num2;i++)
    {
        if(i==0)
        {
            for(int j=0;j<num1;j++)
            {
                outco[j]=coefficient1[j]*coefficient2[i];
                outin[j]=index1[j]+index2[i];
            }
        }
        else
        {
            for(int j=0;j<num1;j++)
            {
                num=insert(outco,outin,num,coefficient1[j]*coefficient2[i],index1[j]+index2[i]);
            }
        }
    }
    
    
    for(int i=0;i<num;i++)
    {
        printf("%d %d ",outco[i],outin[i]);
    }
    return 0;
}

int insert(int outco[],int outin[],int num,int co,int in)
{
    int i;
    for(i=0;i<num;i++)
    {
        if(outin[i]=in) // @@ [This is an assignment instead of a comparison. It should be '==' to check equality. Using '=' assigns 'in' to 'outin[i]' and always evaluates to true if 'in' is non-zero, causing incorrect behavior.]
        {
            outco[i]+=co;
            break;
        }
        else
        {
            continue;
        }
    }
    
    if(i==num)
    {
        if(in>outin[0])
        {
            for(int j=num;j>=1;j--)
            {
                outin[j]=outin[j-1];
                outco[j]=outco[j-1];
            }
            outin[0]=in;
            outco[0]=co;
        }
        else
        {
            int j;
            for(j=0;j<num-1;j++)
            {
                if(outin[j]>in&&outin[j+1]<in)
                {
                    for(int m=num;m>=j+2;m--)
                    {
                        outin[m]=outin[m-1];
                        outco[m]=outco[m-1];
                    }
                    outin[j+1]=in;
                    outco[j+1]=co;
                    break;
                }
                else
                {
                    continue;
                }
            }
            if(j==num-1)
            {
                outin[num]=in;
                outco[num]=co;
            }
        }
        return num+1;
    }
    else
    {
        return num;
    }
}