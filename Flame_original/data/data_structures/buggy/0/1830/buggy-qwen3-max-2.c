#include<stdio.h>
#include<string.h>
char s[100005]={},t[100005]={},len; // @@ [The variable 'len' is declared as char, but it is used to store the difference between two characters (e.g., s[i+1] - s[i-1]), which can be up to 25 or more. This may cause overflow or incorrect loop bounds since char is typically signed and limited to -128..127 or 0..255. It should be int.]
int main()
{
    gets(s); // @@ [The function 'gets' is unsafe and has been removed from modern C standards (since C11). Compilers may not support it, leading to compilation errors. It should be replaced with 'fgets'.]
    for(int i=1;s[i]!='\0';i++)
    {
        if(s[i]=='-'&&i>=1)
        {
            if(s[i-1]>='0'&&s[i-1]<='9'&&s[i+1]>='0'&&s[i+1]<='9'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [Assigning an int-sized value (difference of chars) to a char variable 'len' may truncate or misrepresent the value, especially if the difference exceeds CHAR_MAX.]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++) // @@ [If 'len' is negative due to char overflow or sign extension, this loop may behave incorrectly or not run at all. Also, 'len' includes the full range (e.g., 'a' to 'd' gives len=3), but the expansion should insert len-1 characters between them. However, the bigger issue is using char for len.]
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t);
            }
            else if(s[i-1]>='a'&&s[i-1]<='z'&&s[i+1]>='a'&&s[i+1]<='z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [Same issue: storing potentially large integer difference in a char variable.]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t);
            }
            else if(s[i-1]>='A'&&s[i-1]<='Z'&&s[i+1]>='A'&&s[i+1]<='Z'&&s[i+1]-s[i-1]>0)
            {
                strcpy(t,s+i+2);
                len=s[i+1]-s[i-1]; // @@ [Same issue: 'len' should be int, not char.]
                for(int j=i+1;j<strlen(s);j++)
                s[j]=0;
                for(int j=0;j<len;j++)
                s[i+j]=s[i-1]+j+1;
                i+=(len-1);
                strcat(s+i,t);
            }
        }
    }
    puts(s);
    return 0;
}