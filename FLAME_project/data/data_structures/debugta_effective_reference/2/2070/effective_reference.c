//
//  main.c
//  testsqure3
//
//  Created by  on 2021/9/22.
//  Copyright Â© 2021 . All rights reserved.
//

#include<stdio.h>
#include<string.h>


int main()
{
    char s[10000],s0[10000];
    int l[10000]={0};
    int f[10000]={0};
    int num[10000]={0};
    int jj[10000]={0};
    int num0[10000]={0};
    gets(s0);   
    int j=0;
    for(int i=0;s0[i]!='\0';i++)
    {
        if(s0[i]!=' ')
        {
            s[j]=s0[i];
            j++;
        }
    }
    s[j]='\0';
    for(int i=0,k=0;s[i]!='=';i++)
    {
        if(s[i]=='*')
            f[k]=3,k++,l[i]=1;
        else if (s[i]=='/')
            f[k]=4,k++,l[i]=1;
        else if (s[i]=='+')
            f[k]=1,k++,l[i]=1;
        else if (s[i]=='-')
            f[k]=2,k++,l[i]=1;
    }
    j=0;
	for(int i=0;s[i]!='=';i++)
    {
        if(l[i]!=1)
        {
            num[j]=num[j]*10+s[i]-'0';
            
            if(l[i+1]==1)
                j++;
        }
       
    }
    
    int x=num[0];
    for(int i=0,k=0;i<=j;i++)
    {
        if(f[i]>2)
        {
            if(f[i]==3)
                x*=num[i+1];
            else if(f[i]==4)
                x/=num[i+1];
        }
        else if(f[i]<=2)
        {
            num0[k]=x;
            if(f[i]==1)
                jj[k]=1;
            else if(f[i]==2)
                jj[k]=2;
            x=num[i+1];
            k++;
        }
        else if(f[i]==0&&f[i-1]<=2)
        {
        	num0[k]=num[i];
		}
    }
    int anwser=num0[0];
    for(int i=0;i<=j;i++)
    {
		if(jj[i]==1)
            anwser+=num0[i+1];
        else if(jj[i]==2)
            anwser-=num0[i+1];
    }
    printf("%d",anwser);
    
    return 0;
}




