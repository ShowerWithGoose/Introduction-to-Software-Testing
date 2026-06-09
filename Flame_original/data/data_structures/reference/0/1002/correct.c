#include <stdio.h>
#include <string.h>

int main()
{
    char str[2005],s[2005];
    gets(str);
    int i=0,j,k=0,flag=0;
    for(i=0;i< strlen(str);i++,k++)
    {
        if(str[i]=='-'){
            if(str[i+1]-str[i-1]>1&&(((str[i-1]>='0'&&str[i-1]<='9')&&(str[i+1]>='0'&&str[i+1]<='9'))||((str[i-1]>='a'&&str[i-1]<='z')&&(str[i+1]>='a'&&str[i+1]<='z'))||((str[i-1]>='A'&&str[i-1]<='Z')&&
                                                                                                                                                                          (str[i+1]>='A'&&str[i+1]<='Z'))))
                for(j=1;str[i+1]-str[i-1]-j>0;j++) s[k++]=str[i-1]+j,flag=1;
            else   s[k]=str[i];
        }
        else s[k]=str[i];
        if(flag==1) k--,flag=0;
    }
    s[k]='\0';
    puts(s);
    return 0;

}


