#include<stdio.h>
#include<string.h>
#include<ctype.h>
int is_same(char a,char b)
{
    if(islower(a)>0&&islower(b)>0)
    return 1;
    else if(isupper(a)>0&&isupper(b)>0)
    return 1;
    else if(isdigit(a-'0')>0&&isdigit(b-'0')>0) // @@ [Incorrect use of isdigit: should pass the character directly, not subtract '0'. isdigit(a) checks if a is a digit character. Subtracting '0' converts it to integer, which may cause incorrect behavior or out-of-range values for isdigit.]
    return 1;

    else{
        return 0;
    }
}
int main()
{
   char a[100]="";
   char final[100]="";
   int flag=0;
   scanf("%s",a);
   int n=strlen(a);
   for(int i=0;i<n;i++)
   {
   
    if(a[i]=='-'&&is_same(a[i-1],a[i+1])>0)
    {
        if(a[i-1]<a[i+1])
        {
            flag=1;
            // for(int j=0;j<i;j++)
            // {
            //     final[j]=a[j];
            //     printf("%c\n",final[j]);
            // }
            int change=a[i-1]+1;
            for(int j=i;j<i+(a[i+1]-a[i-1]);j++)
            {
                final[j]=change;
                change++;
                printf("%c",final[j]);
            }
            }
            else
            printf("%c",a[i]);
   }
   else
   printf("%c",a[i]); // @@ [This prints characters one by one, but when expansion occurs, it prints the expanded part immediately without skipping the next character (a[i+1]), leading to duplication. For example, in "a-u", after printing 'a' to 't', the loop continues and later prints 'u' again because i increments normally. Also, the original '-' and surrounding logic mishandles output order and duplication.]
   }
//    if(flag==1)
//    printf("%s",final);
//    else
//    printf("%s",a);
//     return 0;
}