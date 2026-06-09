#include<stdio.h>
#include<string.h>
#include<ctype.h>
char isvalid(char a,char b)
{
    if(isdigit(a)&&isdigit(b)&&a<b) return 1;
    if(isupper(a)&&isupper(b)&&a<b) return 1;
    if(islower(a)&&islower(b)&&a<b) return 1;
    return 0;
}
int main()
{
    char input[512],output[512];
    int i,j;
    scanf("%s",input);
    for(i=0,j=0;input[i+2]!='\0';i++)
    {
        if(input[i+1]=='-'&&isvalid(input[i],input[i+2]))
        {
            for(char tmp=input[i];tmp<input[i+2];tmp++)
            {
                output[j++]=tmp;
            }
            i++;
        }
        else output[j++]=input[i];
    }
    output[j++]=input[i++];
    output[j++]=input[i++];
    output[j++]=input[i++];
    printf("%s",output);
    return 0;
}
