#include<stdio.h>
#include<string.h>
#include<ctype.h>
int is_same(char a,char b)
{
    if(islower(a)>0&&islower(b)>0)
    return 1;
    else if(isupper(a)>0&&isupper(b)>0)
    return 1;
    else if(isdigit(a-'0')>0&&isdigit(b-'0')>0) // @@ Error: should be `isdigit(a) && isdigit(b)`; a-'0' converts character to integer, not a character.
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
   
    if(a[i]=='-'&&is_same(a[i-1],a[i+1])>0) // @@ Error: when i==0, a[i-1] is out of bounds; when i==n-1, a[i+1] is out of bounds. Should check i>0 && i<n-1.
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
            for(int j=i;j<i+(a[i+1]-a[i-1]);j++) // @@ Error: loop includes the last character, causing duplication when later printing a[i+1] in the else branch. Should stop at `i+(a[i+1]-a[i-1])-1`.
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