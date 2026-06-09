#include<stdio.h>
#include<string.h>
char a[100],b[100],c[100];
int num[100];
int main()
{
    int i,j=0,k,d=0,flag=0,sum=1,h=1,z,p,q=0,g,m=0,n,summ=0,v,d1=0,o;
    gets(a);
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=' '){
		b[j]=a[i];
		j++;
        }
	}
    for(k=0;k<strlen(b);k++)
    {
        if(b[k]=='+'||b[k]=='-'||b[k]=='*'||b[k]=='/')
        {
            flag=1;
            sum=1;
            h=1;
            d=0;
            c[q++]=b[k];
            while(b[k-h]>='0'&&b[k-h]<='9'&&k>=h)
                {
                    sum=1;
                    for(p=0;p<h-1;p++)
                    {
                        sum*=10;
                    }
                    d+=(b[k-h]-'0')*sum;
                    h++;
                }
                num[m++]=d;
        }
    } 
    if(flag==0)
    {
        for(z=0;z<strlen(a)-1;z++)
        {
            printf("%c",a[z]);
        }
        return 0;
    }
    sum=1;
    v=j-2;
    o=0;
        while(b[v-o]>='0'&&b[v-o]<='9')
        {
            sum=1;
            for(p=0;p<o;p++)
                    {
                        sum*=10;
                    }
                    d1+=(b[v-o]-'0')*sum;
                    o++;
        }
    num[m]=d1;
    for(g=0;g<strlen(c);g++)
   {
       if(c[g]=='*')
       {
           num[g+1]=num[g]*num[g+1];
           num[g]=0;
       }
       else if(c[g]=='/')
       {
           num[g+1]=num[g]/num[g+1];
           num[g]=0;
       }
       else if(c[g]=='-')
       {
           num[g+1]=-num[g+1];
       }
   }
   
    for(n=0;n<=m;n++)
    {
        summ+=num[n];
    }
    printf("%d",summ);
    return 0;
}
