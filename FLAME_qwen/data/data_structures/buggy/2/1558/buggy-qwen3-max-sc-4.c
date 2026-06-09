#include<stdio.h>
#include<string.h>

int main()
{
    char a[10010];
    long long  num[10010],cha[10010],i=0,j=0,k=0,m=0,ans=0;
    gets(a); // @@ [Using `gets` is unsafe and deprecated; it was removed in C11 standard and may cause compilation errors with modern compilers]
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
        else if(j!=0&&(cha[i]<3)){ // @@ [Using uninitialized or incorrect index `i` instead of `m`; `i` is not updated in this loop and may be out of bounds]
            num[m-j]=num[m];
            j=0;
        }
    }
    ans=num[0];
    for(i=0;cha[i]!=0;i++) // @@ [`cha` array may not be null-terminated; loop condition should check against valid operator range or known length, not `!=0`]
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