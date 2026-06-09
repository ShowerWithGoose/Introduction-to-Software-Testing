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
    str[++i]='\0'; // @@ [This line incorrectly modifies the original string `str` by setting an extra null terminator beyond the copied part, which corrupts the string. It should only set `newstr[i] = '\0';`]
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
    printf("%se%d",Cen,dot1-dot2); // @@ [When the normalized number has only one digit (e.g., "9."), the program outputs "9.e-1" instead of "9e-1". The decimal point should be omitted if there's only one significant digit and no fractional part. The logic does not handle this case correctly.]
    return 0;
}