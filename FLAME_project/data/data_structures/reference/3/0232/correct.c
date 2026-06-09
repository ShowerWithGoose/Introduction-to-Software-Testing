#include<stdio.h>//后去头零，前去尾零   整数

void swap(char *a,char *b)
{
    char t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int cnt=0,l,i,j;
//    double in;
    char ans[105];
//    scanf("%lf",&in);
//    sprintf(ans,"%f",in);//f?lf?
    scanf("%s",ans);//好！可以直接以字符串输入哈哈哈
//    printf("%s\n",ans);
    l=strlen(ans);
    for(i=0;i<l;i++)
        if(ans[i]=='.') break;
    if(ans[0]=='0'&&ans[1]=='.')
    {while(ans[i-1]=='0')
    {
        swap(&ans[i],&ans[i+1]);
        i++;
        cnt--;
//345345.2346        printf("\n%s",ans);
    }
    j=0;
    while(ans[j]=='0') j++,l--;//去头零
    for(i=0;i<l;i++)
        ans[i]=ans[j++];
        ans[i]='\0';
//        printf("%d\n",l);
    }
    else
    {while(i>1)
    {
        swap(&ans[i],&ans[i-1]);
        i--;
        cnt++;
    }}
//        printf("\n%c %d ",ans[],l);
    while(ans[l-1]=='0'||ans[l-1]=='.')
    {
        if(ans[l-1]=='.')
        {
            ans[l-1]='\0';
            break;
        }
        ans[(l--)-1]='\0';
    }
    printf("%s",ans);
    printf("e%d",cnt);
    return 0;
}



