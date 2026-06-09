#include<stdio.h>
#include<string.h>

int main()
{
    char a[10010];
    long long  num[10010],cha[10010],i=0,j=0,k=0,m=0,ans=0; // @@ num and cha arrays not initialized to zero; may contain garbage values.
    gets(a);
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]==' ')
        {
        continue; 
            
         } 
        else if(a[i]>='0'&&a[i]<='9')
        {
            num[j]=num[j]*10+a[i]-'0'; // @@ num[j] may be garbage because not reset when starting a new number.
        }
        else{
            j++; // @@ j incremented but num[j] is not reset to 0 for the next number, leading to use of uninitialized value.
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
        else if(j!=0&&(cha[i]<3)){ // @@ uses undefined variable i; should be cha[m]<3. Also the logic for shifting numbers is incorrect.
            num[m-j]=num[m];
            j=0;
        }
    }
    ans=num[0];
    for(i=0;cha[i]!=0;i++) // @@ loop condition cha[i]!=0 is never satisfied (operators are 1-4 and -1); does not skip operators other than + and -.
    {
        if(cha[i]==1)
        {
            ans=ans+num[i+1]; // @@ adds incorrectly for operators that are '*' or '/'.
        }
        else if(cha[i]==2)
        {
            ans=ans-num[i+1]; // @@ subtracts incorrectly for operators that are '*' or '/'.
        }
    }
printf("%lld",ans);
return 0;
 }