#include<stdio.h>
int numb[1000]={0}; 
char ss[1000]={};
int main()
{
    char s[1000];
    gets(s); // @@ [Using `gets` is unsafe and may cause compilation errors or warnings in modern compilers; it was removed in C11 standard.]
    int a=0,j=0,k=0,i,ans;
    for(i=0;s[i]!='=';i++)
    {
        if((s[i]>='0')&&(s[i]<='9'))
        {
            a=a*10+(s[i]-'0'); 
        }
        else if((s[i]=='+')||(s[i]=='-')||(s[i]=='*')||(s[i]=='/'))
        {
            numb[j++]=a;
            a=0; 
            ss[k++]=s[i]; 
        }
    }
    numb[j]=a;
    j++;
    if(k==0)
        printf("%d",a);
    else
    {
        for(i=0;i<k;i++)
        {
            if(ss[i]=='/')
            {
                numb[i+1]=numb[i]/numb[i+1];
                numb[i]=0;
                if(i!=0)
                {
                    ss[i]==ss[i-1]; // @@ [This uses `==` (comparison) instead of `=` (assignment), so the operator is not updated correctly.]
                }
                else
                {
                    ss[i]== '+'; // @@ [Same error: should use `=` for assignment, not `==`.]
                }
            }
            else if(ss[i]=='*')
            {
                numb[i+1]=numb[i]*numb[i+1];
                numb[i]=0;
                if(i!=0)
                {
                    ss[i]==ss[i-1]; // @@ [Again, using `==` instead of `=` leads to no assignment being performed.]
                }
                else
                {
                    ss[i]== '+'; // @@ [Same mistake: needs assignment `=`, not comparison `==`.]
                }
            }
        }
        ans=numb[0];
        for(i=0;i<k;i++)
        {
            if(ss[i]=='-')
            {
                ans=ans-numb[i+1];
            }
            else
            {
                ans=ans+numb[i+1];
            }
        }
        printf("%d",ans);
    }
    return 0;
}