#include<stdio.h>
#include<string.h>
int a[51],b[51],c[51],d[51],e[51],f[51];//a是未计算式按序提取的数，b是二级运算后按序提取的数,c是各个*在第几个数后以此类推：/+-

int main()
{
    char s[101],ch[101];     //s是原始输入，ch是去除空格的串.
    int ans1=0,ans2=0;
    gets(s);
    for(int i=0,j=0;i<strlen(s);i++){
        if(s[i]!=' '&&s[i]!='='){
            ch[j]=s[i];
            j++;
        }
    }                               //去除空格，
    for(int i=0,j=0;i<=strlen(ch);i++){
        if(ch[i]>='0'&&ch[i]<='9'&&ans1==0){
            ans1=ch[i]-'0';
        }
        else if(ch[i]>='0'&&ch[i]<='9'){
            ans1=ans1*10+ch[i]-'0';
        }
        else {
            a[j++]=ans1;
            ans1=0;
        }
    }                                //a赋值完毕

    for(int i=0,j=0,k=0,l=0,m=0,n=0;i<strlen(ch);i++){
        if(ch[i]=='*'){
            c[k++]=j+1;
            j++;
        }
        else if(ch[i]=='/'){
            d[l++]=j+1;
            j++;
        }
        else if(ch[i]=='+'){
            e[m++]=j+1;
            j++;
        }
        else if(ch[i]=='-'){
            f[n++]=j+1;
            j++;
        }
    }
    for(int i=0,j=0;c[i]!=0||d[j]!=0;){
        if(c[i]<d[j]&&c[i]!=0){
            ans1=a[c[i]-1];ans2=a[c[i]];a[c[i]-1]=0;
            ans1=ans1*ans2;
            a[c[i]]=ans1;
            i++;
        }
        else if(c[i]>d[j]&&d[j]!=0){
            ans1=a[d[j]-1];ans2=a[d[j]];a[d[j]-1]=0;
            ans1=ans1/ans2;
            a[d[j]]=ans1;
            j++;
        }
        else if(c[i]==0){
            ans1=a[d[j]-1];ans2=a[d[j]];a[d[j]-1]=0;
            ans1=ans1/ans2;
            a[d[j]]=ans1;
            j++;
        }
        else if(d[j]==0){
            ans1=a[c[i]-1];ans2=a[c[i]];a[c[i]-1]=0;
            ans1=ans1*ans2;
            a[c[i]]=ans1;
            i++;
        }
    }                           //二级运算完毕
    for(int i=0,j=0;i<51;i++){
        if(a[i]!=0){
            b[j]=a[i];
            j++;
        }
    }                           //b赋值完毕
    ans1=b[0];
    for(int i=0,j=0,k=0;b[i+1]!=0;i++){
        ans2=b[i+1];
        if(e[j]<f[k]&&e[j]!=0){
            ans1=ans1+ans2;
            j++;
        }
        else if(e[j]>f[k]&&f[k]!=0){
            ans1=ans1-ans2;
            k++;
        }
        else if(f[k]==0){
            ans1=ans1+ans2;
            j++;
        }
        else if(e[j]==0){
            ans1=ans1-ans2;
            k++;
        }
    }
    printf("%d",ans1);

    return 0;
}

