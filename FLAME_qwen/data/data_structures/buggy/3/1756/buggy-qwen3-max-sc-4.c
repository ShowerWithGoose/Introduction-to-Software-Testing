#include<stdio.h>
#include<string.h>
char a[1005];
int main()
{
    int sum,flag=0,b,c,d;
    gets(a); // @@ [Using 'gets' is unsafe and deprecated; it was removed in C11 and causes compilation errors with modern compilers. Use 'fgets' instead.]
    for(int i=0;i<strlen(a);i++)
    {    
        if(flag==0&&a[i]!='0'&&a[i]!='.')
        {
            flag=1;
            b=i;
        }
        if(a[i]=='.')
        {
            c=i;
        }
    }
//    i=strlen(a)
//    while(i>0&&a[i]==0)
//    {
//        
//    }
    for(int i=strlen(a)-1;i>c;i--) // @@ [If the input has no decimal point, 'c' remains uninitialized, leading to undefined behavior when used here.]
    {
        if(a[i]!='0'&&a[i]!='.')
        {
            d=i;
            break;
        }
    }
    //printf("%d",d);
    if(flag==1)
    {
        for(int i=b;i<=b+d;i++) // @@ [The loop condition 'i<=b+d' is incorrect; 'd' is an absolute index, not a length. This leads to out-of-bounds access or wrong output.]
        {
            if(i==b+1&&i!=strlen(a))
            printf(".");
            //printf("$");
            if(a[i]!='.')
            printf("%c",a[i]);
        }
        int p;
        if(a[0]=='0')
        p=c-b;
        else
        p=c-b-1;
        if(p>=0)
        printf("e%d\n",p);
        else
        {
            p=-p;
            printf("e-%d\n",p);
        }
        
    }
    else
    printf("0e0\n");
}