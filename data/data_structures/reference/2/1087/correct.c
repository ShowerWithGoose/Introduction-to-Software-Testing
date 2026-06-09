#include <stdio.h>
int judge(char s)
{
 
   
       if(s>='0'&&s<='9')
       return 0;
       else 
       return 1;
   
}
int num[1000];
int main()
{
    int i=0,m=0;
    int j=0,k=0;
    int ans=0;
    
    char fuhao[1000];
    char a[1000],s[1000];
    gets(a);
    // 去掉空格
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]!=' ')
       s[j++]=a[i];
    }
    //把数字翻译出来
    for(int i=0;s[i]!='\0';i++)
    {
       if(judge(s[i])==0)
        {
            int temp=0;
            
            
            while(judge(s[i])==0)
            {
                temp=10*temp+s[i]-'0';
                i++;
            }
            num[k++]=temp;
            i--;
        }
        if (judge(s[i])==1)
        {
           fuhao[m++]=s[i];
        }
        
    }
   // for (int i = 0; s[i]!='\0'; i++)
   // {
   //    printf("%d",num[i]);
   //    printf(" ");

   // }
   // printf("\n");
    for(int i=0;fuhao[i]!='=';i++)
    {
        if (fuhao[i]=='*')
        {
           num[i+1]=num[i+1]*num[i];
           num[i]=0;
        }
        else if (fuhao[i]=='/')
        {
           num[i+1]=num[i]/num[i+1];
           num[i]=0;
        }
        else if (fuhao[i]=='-')
        {
           
           num[i+1]=0-num[i+1];
        }
    }

    for(int i=0;s[i]!='\0';i++)
   
   { ans+=num[i];
   // printf("%d",num[i]);
   // printf(" ");
   }
  
    printf("%d",ans);
    
    
  

   return 0;

}
