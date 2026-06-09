#include<stdio.h>
#include<string.h>
void reverse(char s[])
{
    int temp,i,j;
    for(i=0,j=strlen(s)-1; i<j; i++,j--)
    {
        temp=s[i];
        s[i]=s[j];
        s[j]=temp;
    }
}

int main()
{
    char s[105],s1[105],s2[105],s3[105];
    int i,j=0,k=2,count=1;
    scanf("%s",s);
    s2[0]='e';

    if(s[0]!='0'&&s[1]!='.')
    {
        s1[0]=s[0];
        s1[1]='.';
        s1[2]=s[1];
        for(i=2; i<strlen(s); i++)
        {
            if(s[i]!='.')
            {
                count++;
                s1[i+1]=s[i];
            }
            else break;
        }
        for(i=i+1; i<strlen(s); i++)
        {
            s1[i]=s[i];
        }
        s1[i]='\0';
        while(count>0)
        {
            s3[j++]=count%10+'0';
            count/=10;
        }
        s3[j]='\0';
        reverse(s3);
        strcat(s2,s3);
        strcat(s1,s2);
        printf("%s",s1);
    }

    else if(s[0]!='0'&&s[1]=='.')
    {
        s2[1]='0';
        s2[2]='\0';
        strcat(s,s2);
        printf("%s",s);
    }

    else
    {
        s2[1]='-';
        i=2;
        while(s[i]=='0')
        {
            i++;
            count++;
        }

        if(s[i+1]=='\0')
        {
            s1[0]=s[i];
            s1[1]='\0';
            while(count>0)
            {
                s3[j++]=count%10+'0';
                count/=10;
            }
            s3[j]='\0';
            reverse(s3);
            strcat(s2,s3);
            strcat(s1,s2);
            printf("%s",s1);
        }
        else
        {
            s1[0]=s[i];
            s1[1]='.';
            for(i=i+1; i<strlen(s); i++)
            {
                s1[k++]=s[i];
            }
            s1[k]='\0';
            while(count>0)
            {
                s3[j++]=count%10+'0';
                count/=10;
            }
            s3[j]='\0';
            reverse(s3);
            strcat(s2,s3);
            strcat(s1,s2);
            printf("%s",s1);
        }
    }

    return 0;
}


