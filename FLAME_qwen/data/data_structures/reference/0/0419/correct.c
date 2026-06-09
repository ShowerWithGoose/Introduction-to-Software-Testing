#include <stdio.h>
#include <string.h>
char arr[1000];
int main()
{
    gets(arr);
    int Len=strlen(arr);


    int i;
    for(i=0;i<Len;i++)
    {

        int j=1;
        if(arr[i]!='-')
            printf("%c",arr[i]);


        else if(arr[i-1]>='A' && arr[i+1]<='Z')
        {

            while(arr[i-1]+j<arr[i+1])
            {
                printf("%c",arr[i-1]+j);
                j++;
            }

        }
        else if(arr[i-1]>='a'&&arr[i+1]<='z')
        {
            while(arr[i-1]+j<arr[i+1])
            {
                printf("%c",arr[i-1]+j);
                j++;
            }
        }
        else if(arr[i-1]>='0'&&arr[i+1]<='9')
        {
            while(arr[i-1]+j<arr[i+1])
            {
                printf("%c",arr[i-1]+j);
                j++;
            }
        }
        else printf("%c",arr[i]);

    }



    return 0;
}





