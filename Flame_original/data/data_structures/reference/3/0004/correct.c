# include<stdio.h>
int main()
{
    char decimal[105]={'\0'};
    gets(decimal);
    int i=1;
    for(;decimal[i]!='.';i++);
    if(i==1)//1....
    {
        if(decimal[0]!='0')
            printf("%se0", decimal);
        else//0....
        {
            int j =2;
            for(;decimal[j]=='0';j++);
            printf("%c",decimal[j]);
            if(decimal[j+1]!='\0')
            printf(".%s",decimal+j+1);
            else;
            printf("e-%d",j-1);
        }
    }
    else//1234....
    {
        decimal[i]='\0';
        printf("%c.%s%se%d",decimal[0],decimal+1,decimal+i+1,i-1);
    }
    return 0;
}

