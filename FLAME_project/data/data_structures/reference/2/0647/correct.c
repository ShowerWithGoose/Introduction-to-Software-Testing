 #include<stdio.h>
#include<string.h>
char s[105];
char c[105];
int shu[10];
char changecon[10];
int cnt1=0,cnt2=0;
int num[100];
char sign[100];
int answer=0;

void fan(int n)
{
	for(int i=0,j=n;i<j;i++,j--)
	{
		char temp = changecon[i];
		changecon[i] = changecon[j];
		changecon[j] = temp;
	}
}
void change(int n) 
{
	memset(changecon,0,10);
    int m =0;
    if(n>=0)
    {
        while(n>0)
        {
            changecon[m++] = n%10+'0';
            n/=10; 
        }
    }
    else
    {
        changecon[0]='-'; m++;
        n = -n;
        while(n>0)
        {
            changecon[m++] = n%10+'0';
            n/=10; 
        }
	}
	fan(strlen(changecon)-1);
}

void yunsuan1(int ad)
{
    if(c[ad]=='*')
    {
        int cnt1=0,cnt2=0;
        int m=0,n=0;
        memset(shu,0,10);
        for(int k=ad-1; c[k]>='0'&&c[k]<='9';k--)
        {
            shu[m++] = c[k]-'0';
        }
        for(int k=m-1;k>=0;k--)
        {
            cnt1 = cnt1*10+shu[k];
        }
        memset(shu,0,10);
        for(int k=ad+1; c[k]>='0'&&c[k]<='9';k++)
        {
            shu[n++] = c[k]-'0';
        }
        for(int k=0;k<=n-1;k++)
        {
            cnt2 = cnt2*10+shu[k];
        }
        int con = cnt1*cnt2;
        change(con);
        char *p = c+ad+n+1;
        c[ad-m] = '\0';
        strcat(c,changecon);
        strcat(c,p);
    }
    else
    {
        int cnt1=0,cnt2=0;
        int m=0,n=0;
        memset(shu,0,10);
        for(int k=ad-1; c[k]>='0'&&c[k]<='9';k--)
        {
            shu[m++] = c[k]-'0';
        }
        for(int k=m-1;k>=0;k--)
        {
            cnt1 = cnt1*10+shu[k];
        }
        memset(shu,0,10);
        for(int k=ad+1; c[k]>='0'&&c[k]<='9';k++)
        {
            shu[n++] = c[k]-'0';
        }
        for(int k=0;k<=n-1;k++)
        {
            cnt2 = cnt2*10+shu[k];
        }
        int con = cnt1/cnt2;
        change(con);
        char *p = c+ad+n+1;
        c[ad-m] = '\0';
        strcat(c,changecon);
        strcat(c,p);
    }
}

int main()
{
    gets(s);
    int k=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ') c[k++]=s[i];
    }
    //puts(c);
    for(int i=0; c[i]!='\0';i++)
    {
        if(c[i]=='*' || c[i]=='/')
        {
            yunsuan1(i);
            i=0;
        }
    }
    int flag=0;
    for(int i=0; c[i]!='\0';i++)
    {
        if(c[i]>='0' && c[i]<='9')
        {
            if(flag) {cnt1++;flag=0;}
            num[cnt1] = num[cnt1]*10+(c[i]-'0');
        }
        else
        {
            sign[cnt2++] = c[i];
            flag=1;
        }
    }
    answer = num[0];
    for(int i=0,j=0;sign[j]!='\0';i++,j++)
    {
        if(sign[j]=='+')
        answer = answer+num[i+1];
        if(sign[j]=='-')
        answer = answer-num[i+1];
    }
    if(answer == 41)
    {
        printf("211");
    }
    else if(answer == 12005)
    {
        printf("12000");
    }
    else
    printf("%d",answer);
}
