#include<stdio.h>
#include<string.h>
int judge(char x, char y)
{
    if((x>='a'&&x<='z')||(y>='a'&&y<='z'))
        return 1;
    if((x>='A'&&x<='Z')||(y>='A'&&y<='Z'))
        return 1;
    if((x>='0'&&x<='9')||(y>='0'&&y<='9'))
        return 1;
    else 
        return 0; // @@ [The judge function incorrectly returns 1 if either character is in a valid range, rather than checking if both are of the same type and valid. This causes mixed-type cases like 'B-e' to be considered expandable.]
}
int main()
{
    char first[1500];
    int len;
    gets(first); // @@ [Using gets() is unsafe and deprecated; however, the main logical error is elsewhere. More critically, the loop below does not validate that both surrounding characters are of the same category (e.g., both lowercase), nor does it check that the right character is greater than the left.]
    len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if((first[i]=='-')&&judge(first[i+1], first[i-1])) // @@ [This condition uses the flawed judge() function and also accesses first[i-1] when i=0 (undefined behavior). Additionally, it doesn't ensure that both characters are of the same type (e.g., both digits) or that first[i+1] > first[i-1]. For input "B-e", 'B' is uppercase and 'e' is lowercase — different types — so no expansion should occur, but judge() returns 1 because each is in some valid range, leading to incorrect expansion.]
        {
            for(int k=1;k<first[i+1]-first[i-1];k++) // @@ [This loop runs even when first[i+1] <= first[i-1], which could cause negative or zero iterations, but more importantly, it expands across type boundaries (like 'B' to 'e'), producing garbage output. Also, if first[i+1] < first[i-1], the loop condition becomes positive due to unsigned char promotion, causing massive unintended output (as seen in the test case).]
            printf("%c",first[i-1]+k);
        }
        else
        printf("%c",first[i]);        
    }
    return 0;
}