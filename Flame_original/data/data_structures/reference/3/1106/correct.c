#include<stdio.h>
#include<string.h>
int main()
{
    char input[128],output[256];
    int i,j;
    scanf("%s",input);
    if(input[0]!='0')
    {
        for(i=1;input[i]!='\0';i++)
            output[i+1]=input[i];
        output[i+1]='\0';
        output[1]='.';
        output[0]=input[0];
        for(i=2;output[i]!='\0';i++)
        {
            if(output[i]=='.')
            {
                for(j=i;output[j]!='\0';j++)
                {
                    output[j]=output[j+1];
                }
                break;
            }
        }
        printf("%se%d",output,i-2);
    }
    else
    {
        for(i=2;input[i]=='0';i++);
        output[0]=input[i++];
        if(input[i]!='\0')
        {
            output[1]='.';
            j=2;
        }
        else j=1;
        for(int k=i;input[k]!='\0';k++)
        {
            output[j++]=input[k];
        }
        output[j]='\0';
        printf("%se-%d",output,i-2);
    }
    return 0;
}


