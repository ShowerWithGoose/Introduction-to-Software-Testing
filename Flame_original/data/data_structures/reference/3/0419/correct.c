#include <stdio.h>
#include <string.h>
char arr[1000];
int main()
{
    gets(arr);
    int Len=strlen(arr);



    int position;
    for(position=0;position<Len;position++)
    {
        if(arr[position]=='.')
        {

            break;
        }
    }



    if(position==1&&arr[0]!='0')
    {
        printf("%se0",arr);
    }


    else if(position>1)
    {
        int m=position-1,i;
        printf("%c.",arr[0]);
        for(i=1;i<Len;i++)
        {
            if(arr[i]!='.')
                printf("%c",arr[i]);
        }
        printf("e%d",m);
    }


    else
    {
        int m,j,i;
        for(j=position+1;j<Len;j++)
        {
            if(arr[j]!='0')
                break;
        }
        if(j==Len-1)
        printf("%c",arr[j]);
        else
            printf("%c.",arr[j]);

        for(i=j+1;i<Len;i++)
            printf("%c",arr[i]);
        m=j-1;
        printf("e-%d",m);

    }



    return 0;
}




