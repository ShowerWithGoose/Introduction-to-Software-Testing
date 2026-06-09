#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main()
{
    char ori[114],stoibuf[114],operators[114];
    int scan=0,write=0,opwrite=0,numwrite=0,nums[114],findnum1,findnum2;
    gets(ori);
    while(ori[scan]!=0)
    {
        if(ori[scan]!=' ')
        {
            ori[write]=ori[scan];
            write++;
        }
        scan++;
    }
    ori[write]=0;
    scan=0;
    write=0;
    while(ori[scan]!='\0')
    {
        if(ori[scan]<='9'&& ori[scan]>='0')
        {
            stoibuf[write]=ori[scan];
            write++;
        }
        else
        {
            stoibuf[write]=0;
            write=0;
            operators[opwrite++]=ori[scan];
            sscanf(stoibuf,"%d",&nums[numwrite++]);
        }
        scan++;
    }
    scan=0;
    while(operators[scan]!='=')
    {
        if(operators[scan]=='*')
        {
            findnum1=scan;
            findnum2=scan+1;
            while(nums[findnum1]==114514)
                findnum1--;
            nums[findnum1]=nums[findnum1]*nums[findnum2];
            nums[findnum2]=114514;
        }
        if(operators[scan]=='/')
        {
            findnum1=scan;
            findnum2=scan+1;
            while(nums[findnum1]==114514)
                findnum1--;
            nums[findnum1]=nums[findnum1]/nums[findnum2];
            nums[findnum2]=114514;
        }
        scan++;
    }
    scan=0;
    while(operators[scan]!='=')
    {
        if(operators[scan]=='+')
        {
            findnum1=scan;
            findnum2=scan+1;
            while(nums[findnum1]==114514)
                findnum1--;
            nums[findnum1]=nums[findnum1]+nums[findnum2];
            nums[findnum2]=114514;
        }
        if(operators[scan]=='-')
        {
            findnum1=scan;
            findnum2=scan+1;
            while(nums[findnum1]==114514)
                findnum1--;
            nums[findnum1]=nums[findnum1]-nums[findnum2];
            nums[findnum2]=114514;
        }
        scan++;
    }
    printf("%d",nums[0]);
    return 0;
}
