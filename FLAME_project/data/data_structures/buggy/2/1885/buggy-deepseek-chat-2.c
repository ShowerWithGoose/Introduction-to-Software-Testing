#include<stdio.h>
int numb[1000]={0}; 
char ss[1000]={};
int main()
{
    char s[1000];
    gets(s);
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
                    ss[i]==ss[i-1]; // @@ [This line uses == (comparison) instead of = (assignment), so it does not actually change ss[i]. The intent is to propagate the previous operator after division, but the logic is flawed; it should not modify ss[i] at all because the operator array should remain unchanged for correct addition/subtraction later.]
                }
                else
                {
                    ss[i]=='+'; // @@ [Same issue: == is used instead of =, and even if corrected, changing the operator to '+' is incorrect because it loses the original operator information needed for later steps.]
                }
            }
            else if(ss[i]=='*')
            {
                numb[i+1]=numb[i]*numb[i+1];
                numb[i]=0;
                if(i!=0)
                {
                    ss[i]==ss[i-1]; // @@ [Same as above: == instead of =, and the logic of propagating the previous operator is incorrect.]
                }
                else
                {
                    ss[i]=='+'; // @@ [Same as above: == instead of =, and changing to '+' is wrong.]
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
                ans=ans+numb[i+1]; // @@ [This treats all non-minus operators as plus, but after the flawed modification of ss[i] in the previous loop, some operators may have been incorrectly changed, leading to wrong addition/subtraction. Additionally, the original logic for handling multiplication and division is incorrect because it modifies the operator array in a way that does not correctly preserve the order of operations.]
            }
        }
        printf("%d",ans);
    }
    return 0;
}