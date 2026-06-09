#include<stdio.h>
#include<string.h>
#include<math.h>
char s[100];
char fumula[100];
int main()
{
    fgets(s,100,stdin);
    int i=0,j=0,k=0;
    int cnt=0;
    for(i=0;!(s[i]=='\0' && s[i+1]=='\0');i++)
    {
        if(s[i]!=' ')
        {
            fumula[j]=s[i];
            j++;
        }
        if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')
            cnt++;
    }
    //去除空格
    //测试
    //puts(fumula);

    int num[100]={0};
    char fuhao[100]={0};//栈从1开始
    int top=0;
    int ntop=1;
    int n=0;
    j=0;
    while(!(fumula[j]=='+' || fumula[j]=='-' || fumula[j]=='*' || fumula[j]=='/' || fumula[j]=='='))
        j++;
    //for(j=0;!(fumula[j]=='+' || fumula[j]=='-' || fumula[j]=='*' || fumula[j]=='/' || fumula[j]=='=');j++)//第一个符号位为j
    for(k=0;k<=j-1;k++)//子串位数为末减首+1
            n+=(fumula[k]-48)*pow(10,j-1-k);
    num[1]=n;
    for(i=j;fumula[i]!='\0';)//从第一个符号位开始
    {      
        n=0;
        if(fumula[i]=='=')
        {
            printf("%d\n",num[ntop]);
            break;
        }
        if(top==0)
        {
            top++;
            fuhao[top]=fumula[i];
        }
        else
        {
            flag:
            if( (fumula[i]=='*' || fumula[i]=='/') && (fuhao[top]=='+' || fuhao[top]=='-') )//优先级高于栈顶，可以入栈
            {
                top++;
                fuhao[top]=fumula[i];
            }
            else//出栈
            {   
                if(fuhao[top]=='+')
                {
                    num[ntop-1]=num[ntop]+num[ntop-1];
                }
                if(fuhao[top]=='-')
                {
                    num[ntop-1]=num[ntop-1]-num[ntop];
                }
                if(fuhao[top]=='*')
                {
                    num[ntop-1]=num[ntop]*num[ntop-1];
                }
                if(fuhao[top]=='/')
                {
                    num[ntop-1]=num[ntop-1]/num[ntop];
                }
                top--;
                ntop--;
                if(top!=0)
                    goto flag;
                else
                {
                    top++; 
                    fuhao[top]=fumula[i];
                }
                ///////////////////////////////////////////////////////////////////////////////////
            }
        }

        j=i+1; 
		while(!(fumula[j]=='+' || fumula[j]=='-' || fumula[j]=='*' || fumula[j]=='/' || fumula[j]=='='))
        	j++;
		//最终j是下一个符号位
        for(k=i+1;k<=j-1;k++)//子串位数为末减首+1
            n+=(fumula[k]-48)*pow(10,j-1-k);
        ntop++;
        num[ntop]=n;//数字入栈
        i=j;
        if(fumula[i]=='=') 
        {
        	fflag:
			if(fuhao[top]=='+')
            {
                num[ntop-1]=num[ntop]+num[ntop-1];
            }
            if(fuhao[top]=='-')
            {
                num[ntop-1]=num[ntop-1]-num[ntop];
            }
            if(fuhao[top]=='*')
            {
                num[ntop-1]=num[ntop]*num[ntop-1];
            }
            if(fuhao[top]=='/')
            {
                num[ntop-1]=num[ntop-1]/num[ntop];
            }
            top--;
            ntop--;
            if(top!=0)
            	goto fflag;
		}
    }
    //system("pause");
    return 0;
}





