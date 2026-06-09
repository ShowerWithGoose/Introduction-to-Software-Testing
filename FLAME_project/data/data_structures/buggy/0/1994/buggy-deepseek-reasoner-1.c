#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z')) // @@ // Error: should require both x and y in same range (e.g., lowercase) and x<y
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z')) // @@ // Error: should require both x and y in same range (e.g., uppercase) and x<y
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9')) // @@ // Error: should require both x and y in same range (e.g., digits) and x<y
        return 1;
    else 
        return 0;
}
int main()
{
    char first[1500];
    int len;
    gets(first);
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ // Error: judge does not check same type or left<right; also expansion should only happen if left<right
        {
            for(int k=1;k<first[i+1]-first[i-1];k++) // @@ // Error: relies on judge being correct; loop condition does not verify left<right, causing incorrect output when left>=right
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}