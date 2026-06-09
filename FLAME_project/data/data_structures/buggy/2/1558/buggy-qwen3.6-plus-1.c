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
            j++; // @@ The index j is incremented before storing the operator code, causing a mismatch between the number index and the operator index. For example, the first number is at num[0], but its following operator is stored at cha[1] instead of cha[0]. This misalignment causes incorrect calculations later.
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
        else if(j!=0&&(cha[i]<3)){ // @@ The variable 'i' is used here as an index for 'cha', but 'i' retains its value from the previous input parsing loop (length of string). It should likely be 'm' or another relevant index. Furthermore, the logic for shifting numbers after multiplication/division is flawed and doesn't correctly handle the sequence of operations or indices.
            num[m-j]=num[m];
            j=0;
        }
    }
    ans=num[0];
    for(i=0;cha[i]!=0;i++) // @@ The loop condition checks for cha[i]!=0. However, the end of the expression is marked by -1. If there are no operators left or if the logic above failed to clean up, this might loop incorrectly. More importantly, due to the initial indexing error, cha[0] might not correspond to the first operator correctly, or the values in cha are shifted. Also, if the previous loop modified 'num' indices, the correspondence between cha[i] and num[i+1] is broken.
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