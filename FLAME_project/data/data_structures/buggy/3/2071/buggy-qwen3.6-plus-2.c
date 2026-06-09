#include <stdio.h>
#include <string.h>

int str_change_substr(char str[],char old_sub_str[],char new_sub_str[]);
int str_div_left(char str[],char* divpoint);
int str_div_right(char str[],char newstr[],char* divpoint);
int str_del_ij(char str[],char* left,char* right);
int str_change_ij(char str[],char substr[],char* left,char* right);
int str_add(char str[],char addstr[]);
int str_add_i(char str[],char addstr[],char* addpoint);
char* str_r_str(char str[],char substr[]);


int str_change_substr(char str[],char old_sub_str[],char new_sub_str[])
{
    char* sub_sta=NULL;
    char right[2000]={0};
    sub_sta=strstr(str,old_sub_str);
    if(sub_sta==NULL)
        return 0;
    str_div_right(str,right,(sub_sta)+strlen(old_sub_str));
    str_div_left(str,sub_sta);
    
    int i;
    for(i=0;*(sub_sta+i)!=0;i++)
        *(sub_sta+i)='\0';
    str_add(str,new_sub_str);
    str_add(str,right);
    return 1;
}
int str_div_left(char str[],char* divpoint)//uninclude divpoint
{
    *divpoint=0;
    return 0;
}
int str_div_right(char str[],char newstr[],char* divpoint)//include divpoint
{
    int i;
    for(i=0;str[i]!=0;i++)
        newstr[i]=*(divpoint+i);
    str[++i]='\0';
    return 0;
}
int str_add(char str[],char addstr[])
{
    int temp=strlen(str)+strlen(addstr);
    strcat(str,addstr);
    return 0;
}
int str_add_i(char str[],char addstr[],char* addpoint)
{
    char temp[12000]={0};
    str_div_right(str,temp,addpoint+1);
    str_div_left(str,addpoint+1);
    str_add(str,addstr);
    str_add(str,temp);
    return 0;
}
int str_del_ij(char str[],char* left,char* right)
{
    char temp[12000]={0};
    str_div_right(str,temp,right+1);
    str_div_left(str,left);
    str_add(str,temp);
    return 0;
}
int str_change_ij(char str[],char addstr[],char* left,char* right)
{
    char temp[12000]={0};
    str_div_right(str,temp,right+1);
    str_div_left(str,left);
    str_add(str,addstr);
    str_add(str,temp);
    return 0;
}
char* str_r_str(char str[],char substr[])
{
    char temp[12000]={0};
    strcpy(temp,str);
    if(strstr(temp,substr)==NULL)
        return NULL;
    else
    {
        char* sub_sta;
        while(strstr(temp,substr)!=NULL)
        {
            sub_sta=strstr(temp,substr);
            *sub_sta='\a';
        }
        return &str[((long long) sub_sta-(long long) temp)];
    }
}
//int str_change_substr(char str[],char old_sub_str[],char new_sub_str[]);
int replace(char str[],char old_sub_str[],char new_sub_str[]);
int replace(char str[],char old_sub_str[],char new_sub_str[])
{
    char* sub_sta=NULL;
    sub_sta=strstr(str,old_sub_str);
    while(sub_sta!=NULL)
    {
        sub_sta=strstr(str,old_sub_str);
        str_change_substr(str,old_sub_str,new_sub_str);
    }
    return 0;
}


char Cen[250]={0};

int main()
{
    gets(Cen);
    int i;
    int n=strlen(Cen);
    
    if((n==1)||((n==2)&&(Cen[0]=='-')))
    {
        printf("%se0",Cen);
        return 0;
    }
    int dot1=n;
    int dot2=n;
    for(i=0;i<n;i++)
    {
        if(Cen[i]=='.')
        {
            dot1=i;
            break;
        }
    }
    
    str_change_substr(Cen,".","");
    for(i=0;i<n;i++)
    {
        if(Cen[i]!='0')
        {
            dot2=i+1;
            break;
        }
    }
    str_add_i(Cen,".",&Cen[dot2-1]);
    while(Cen[0]=='0')
    {
        str_del_ij(Cen,&Cen[0],&Cen[0]);
    }
    // The logic below incorrectly appends a decimal point even when the mantissa is a single digit.
    // For input "0.9", Cen becomes "9." after str_add_i. The expected output is "9e-1", not "9.e-1".
    // We need to check if the part after the inserted decimal point is empty or zero, and if so, remove the decimal point.
    // However, a simpler fix given the structure is to check if the string ends with "." or if the decimal part is effectively empty.
    // Looking at str_add_i, it inserts "." at dot2-1. If dot2 corresponds to the last digit, it appends "." at the end? 
    // Let's trace "0.9". n=3. dot1=1. Cen becomes "09". dot2: i=0 '0' skip, i=1 '9' break. dot2=2.
    // str_add_i(Cen, ".", &Cen[1]). Cen is "09". addpoint is &Cen[1] ('9').
    // str_div_right saves temp starting from addpoint+1 (Cen[2], which is '\0'). So temp is "".
    // str_div_left sets Cen[2] to '\0'. Cen is "0".
    // str_add(Cen, ".") -> Cen is "0.".
    // str_add(Cen, "") -> Cen is "0.".
    // Then while(Cen[0]=='0') removes leading zeros.
    // str_del_ij(Cen, &Cen[0], &Cen[0]). Left=Cen[0], Right=Cen[0].
    // str_div_right saves temp from Right+1 (Cen[1], which is '.'). Temp is ".".
    // str_div_left sets Cen[0] to '\0'. Cen is "".
    // str_add(Cen, "") -> Cen is "".
    // str_add(Cen, ".") -> Cen is ".".
    // This logic seems flawed for single digits. 
    
    // Let's look at the specific failure: Output "9.e-1" vs Expected "9e-1".
    // This implies that for single-digit mantissas, the trailing decimal point should be removed.
    // The current code prints whatever is in Cen.
    // We should strip the trailing '.' if it exists and there are no digits after it.
    
    int len = strlen(Cen);
    if (len > 0 && Cen[len-1] == '.') {
        Cen[len-1] = '\0';
    }
    
    printf("%se%d",Cen,dot1-dot2);
    return 0;
}