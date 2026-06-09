#include<stdio.h>
#include<string.h>

int main()
{
    char a[10010];
    long long  num[10010],cha[10010],i=0,j=0,k=0,m=0,ans=0;
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ')
        {
        continue; 
            
         } 
        else if(a[i]>='0'&&a[i]<='9')
        {
            num[j]=num[j]*10+a[i]-'0';
        }
        else{
            j++;
            if(a[i]=='+'){
                cha[k]=1;
            }
            else if(a[i]=='-'){
                cha[k]=2;
            }
            else if(a[i]=='*'){
                cha[k]=3;    
            }
            else if(a[i]=='/'){
                cha[k]=4;
            }
            else if(a[i]=='='){
                cha[k]=-1;
            }
            k++;
        }
    }
j=0;
for(m=0;cha[m]!=-1;m++)
{
        if(cha[m]==4||cha[m]==3)
        {
            if(cha[m]==3)
            {
                ans=num[m]*num[m+1];
                num[m+1]=ans;
            }
            else
            {
                ans=num[m]/num[m+1];
                num[m+1]=ans;
            }
            j++;            
        }
        else if(j!=0&&(cha[i]<3)){ // @@ The variable 'i' is used here but it holds the value from the previous loop (length of string), not the current index 'm'. It should be 'cha[m]<3'. Also, logic for shifting numbers after multiplication/division is flawed because it doesn't correctly handle the sequence of operations and indices when multiple * or / are present or mixed with +/-.
            num[m-j]=num[m];
            j=0;
        }
    }
    ans=num[0];
    for(i=0;cha[i]!=0;i++) // @@ The termination condition 'cha[i]!=0' is incorrect. The array 'cha' is initialized to 0 by default (global/static behavior or local garbage if not initialized, but here it's local so it's garbage unless explicitly set). However, the loop relies on 'cha' having a 0 terminator which isn't guaranteed or correctly set for the end of valid operators. It should likely check against -1 or use the count of operators. More critically, the previous loop modifies 'num' in place but doesn't correctly compact the 'cha' array or adjust indices for the subsequent addition/subtraction loop. The indices in 'num' no longer align with 'cha' after the in-place modifications in the previous loop.
    {
        if(cha[i]==1)
        {
            ans=ans+num[i+1];
        }
        else if(cha[i]==2)
        {
            ans=ans-num[i+1];
        }
    }
printf("%lld",ans);
return 0;
 }