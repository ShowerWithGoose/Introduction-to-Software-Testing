#include<stdio.h>
#include<string.h> 
/*int main() 
{ 
    int zsg,xsg,i,j;
    char num[101],*p,*q;
    scanf("%s",num);
    for(i=0;num[i]!='.';i++)
    {
        ;
    }
    zsg=i-1;
    p=&num[i+1];
    for(i=zsg+2;num[i]!='\0';i++)
    {
        ;    
    }
    xsg=i-zsg-2;
    if(num[0]!='0')
    {
        printf("%c.",num[0]);
        for(i=1;num[i]!='.';i++)
        {
            printf("%c",num[i]);    
        }
        printf("%s",p);
        printf("e%d",zsg);    
    }    
    else
    {
        for(j=zsg+2;num[j]=='0';j++)
        {
            ;
        }
        q=&num[j+1];
        if(xsg==j-zsg-1)
        {
            printf("%ce-%d",num[j],xsg);    
        }
        else
        {
            printf("%c.%se-%d",num[j],q,j-zsg-1);    
        }
    }
    return 0;
}
int main()
{
    char A[81],B[81],C[81],ans[81],*p,*q,*r;
    int a,b,i,j=0,max,min,sig,numl[81],nums[81];
    scanf("%s%s",A,B);
    for(i=0;A[i]=='0';i++)
    {
        ;    
    }
    a=strlen(A)-i;
    for(i=0;B[i]=='0';i++)
    {
        ;    
    }
    b=strlen(B)-i;
    if(a>b)
    {
        max=a;
        min=b;    
        p=B;
        q=A;
    }
    else
    {
        max=b;
        min=a;    
        p=A;
        q=B;
    }
    for(i=0;i<max-min;i++)
    {
        C[i]='0';    
    }
    C[i]='\0';
    strcat(C,p);
    sig=strcmp(q,C);
    if(sig>0)
    {
        for(i=0;C[i]!='\0';i++)
        {
            numl[i]=*(q+i)-'0';
            nums[i]=C[i]-'0';    
        }
        for(i=strlen(C)-1;i>=0;i--)
        {
            if(numl[i]<nums[i])
            {
                ans[i]=numl[i]-nums[i]+10+'0';
                numl[i-1]--;
            }
            else
            {
                ans[i]=numl[i]-nums[i]+'0';    
            }
        }    
    }
    else
    {
        for(i=0;C[i]!='\0';i++)
        {
            nums[i]=*(q+i)-'0';
            numl[i]=C[i]-'0';    
        }
        for(i=strlen(C)-1;i>=0;i--)
        {
            if(numl[i]<nums[i])
            {
                ans[i]=numl[i]-nums[i]+10+'0';
                numl[i-1]--;
            }
            else
            {
                ans[i]=numl[i]-nums[i]+'0';    
            }
        }    
    }
    for(i=0;ans[i]!='\0';i++)
    {
        if(ans[i]!='0')
        {
            j++;    
        }    
    }
    if(j!=0)
    {
        for(i=0;ans[i]=='0';i++)
        {
            ;    
        }
        r=ans+i;
        if(q==B&&sig>0)
        {
            printf("-%s",r);        
        }
        else
        {
            printf("%s",r);
        }
    }
    else
    {
        printf("0");    
    }
    return 0;
}*/
int main()
{
    int N,h=0,i=0,j=0,k=0,shu,a[10],mark[10],s[10]={0},num[10];
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
        num[i]=i+1;
        mark[i]=1;
        switch(N-i-1)
        {
            case 0: a[i]=1;break;
            case 1: a[i]=1;break;
            case 2: a[i]=2;break;
            case 3: a[i]=6;break;
            case 4: a[i]=24;break;
            case 5: a[i]=120;break;
            case 6: a[i]=720;break;
            case 7: a[i]=5040;break;
            case 8: a[i]=40320;break;
            case 9: a[i]=362880;break;    
        }    
    }
    shu=a[0]*N; // @@ [The logic for calculating total permutations is incorrect. a[0] holds factorial of (N-1), so shu becomes N * (N-1)! = N!, which is correct in value, but the algorithm that follows does not correctly generate all permutations in lexicographical order. However, the compilation error reported is misleading — the actual issue is runtime/logic, not compilation. But since the test environment reports "gcc: not found", it's likely a system setup issue, not code error. Yet per instructions, we must annotate logical errors causing wrong output. The real bug is in permutation generation logic below.]
    for(k=0;k<shu;k++)
    {
        for(i=0;i<N;i++)
        {
            printf("%d ",num[i]);    
        }
        printf("\n");
        for(i=0;i<N;i++)
        {
            if(mark[i]==a[i]) // @@ [This condition and the following logic do not correctly implement lexicographical permutation generation. The 'mark' array and 'a' array usage is flawed; it doesn't simulate standard next_permutation logic. This causes duplicate or missing permutations.]
            {
                for(h=num[i];h<N;h++)
                {
                    if(s[h]==0)
                    {
                        num[i]=h+1;
                        break;    
                    }    
                }
                s[num[i]-1]=1;
                mark[i]=1;
                for(j=i+1;j<N;j++)
                {
                    for(h=0;h<N;h++)
                    {
                        if(s[h]==0)
                        {
                            num[j]=h+1;    
                            s[h]=1;
                            break;
                        }    
                    }
                    mark[j]=1;    
                }
                break;    
            }
            else
            {
                s[num[i]-1]=1;
                mark[i]++;    
            }    
        }
        for(i=0;i<N;i++)
        {
            s[i]=0;    
        }    
    }
    return 0;
}