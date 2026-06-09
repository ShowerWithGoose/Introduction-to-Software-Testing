#include<stdio.h>
int main()
{
    char s[105],temp;
    int i,j=0;
    gets(s);
    if(s[0]!='0')
    {
        for(i=0; s[i]!='.'; i++)
            j++;
        for(; i>1; i--)
        {
            temp=s[i];
            s[i]=s[i-1];
            s[i-1]=temp;
        }
        for(i=0; s[i]!='\0'; i++);

        s[i]='e';
        if(j-1>=0&&j-1<=9)
        {
            s[i+1]=j-1+'0';
            s[i+2]='\0';
        }
        else
        {
            s[i+1]=(j-1)/10+'0';
            s[i+2]=(j-1)%10+'0';
            s[i+3]='\0';
        }
        for(i=0; s[i]!='\0'; i++)
            printf("%c",s[i]);
    }
    if(s[0]=='0')
    {
        for(i=0; s[i]<'1'||s[i]>'9'; i++)
            j++;
        for(i=1; i<j; i++)
        {
            temp=s[i+1];
            s[i+1]=s[i];
            s[i]=temp;
        }
        if(s[j+1]=='\0')
        {
            if(j-1>=0&&j-1<=9)
            {
                s[j]='e';
                s[j+1]='-';
                s[j+2]=j-1+'0';
                s[j+3]='\0';
            }
            else
            {
                s[j]='e';
                s[j+1]='-';
                s[j+2]=(j-1)/10+'0';
                s[j+3]=(j-1)%10+'0';
                s[j+4]='\0';
            }
        }
        else
        {
            for(i=0; s[i]!='\0'; i++);
            if(j-1>=0&&j-1<=9)
            {
                s[i]='e';
                s[i+1]='-';
                s[i+2]=j-1+'0';
                s[i+3]='\0';
            }
            else
            {
                s[i]='e';
                s[i+1]='-';
                s[i+2]=(j-1)/10+'0';
                s[i+3]=(j-1)%10+'0';
                s[i+4]='\0';
            }
        }
        for(i=j-1; s[i]!='\0'; i++)
            printf("%c",s[i]);
    }
    return 0;
}

