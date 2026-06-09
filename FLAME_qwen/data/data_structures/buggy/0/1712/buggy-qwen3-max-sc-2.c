#include<stdio.h>
#include<string.h>
#include<ctype.h>
int is_same(char a,char b)
{
    if(islower(a)>0&&islower(b)>0)
    return 1;
    else if(isupper(a)>0&&isupper(b)>0)
    return 1;
    else if(isdigit(a-'0')>0&&isdigit(b-'0')>0) // @@ [Incorrect use of isdigit: should pass the character directly, not subtract '0'. isdigit(a) and isdigit(b) are correct. Subtracting '0' converts digit char to int, but isdigit expects char. Also, for non-digit chars, this leads to undefined behavior.]
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
   
    if(a[i]=='-'&&is_same(a[i-1],a[i+1])>0) // @@ [Potential out-of-bounds access: when i=0, a[i-1] is a[-1]; when i=n-1, a[i+1] is a[n] (null terminator or beyond). This leads to undefined behavior.]
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
            for(int j=i;j<i+(a[i+1]-a[i-1]);j++) // @@ [Logic error: overwrites positions starting at index i, but original characters before '-' (like a[i-1]) are not printed in this branch. Also, output is printed mid-loop without printing the leading character (a[i-1]). The expansion should output all chars from a[i-1]+1 up to a[i+1]-1, but current logic may misalign indices and overwrite unprinted parts. Additionally, the loop bound may exceed array size.]
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
   printf("%c",a[i]);
   }
//    if(flag==1)
//    printf("%s",final);
//    else
//    printf("%s",a);
//     return 0;
}