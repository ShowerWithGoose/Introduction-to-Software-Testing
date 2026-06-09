#include <stdio.h>
#include <string.h>
int main()
{
   int i=0,j=0,k=0,p=0,q=0,m=0,n=0,length=0,length1=0,length2=0,re1=0,b[1000],step=0;
   char a[1000],s[1000];
   gets(s);
   length=strlen(s);
   while(i<length){
    if(s[i]==' '||s[i]=='='){
        i++;
        continue;                   //不记录表达式中所有的空格
    }
    if('0'<=s[i]&&s[i]<='9'){
        if(s[i+1]<'0'||s[i+1]>'9'){
            b[p]=s[i]-'0';
            step=1;                                          //个位数
        }
        else if('0'<=s[i+1]&&s[i+1]<='9'&&(s[i+2]<'0'||s[i+2]>'9')){      //两位数
            b[p]=(s[i]-'0')*10+(s[i+1]-'0');
            step=2;
        }
        else if('0'<=s[i+1]&&s[i+1]<='9'&&'0'<=s[i+2]&&s[i+2]<='9'&&(s[i+3]<'0'||s[i+3]>'9')){
            b[p]=(s[i]-'0')*100+(s[i+1]-'0')*10+(s[i+2]-'0');
            step=3;
        }
        else if('0'<=s[i+1]&&s[i+1]<='9'&&'0'<=s[i+2]&&s[i+2]<='9'&&'0'<=s[i+3]&&s[i+3]<='9'&&(s[i+4]<'0'||s[i+4]>'9')){
            b[p]=(s[i]-'0')*1000+(s[i+1]-'0')*100+(s[i+2]-'0')*10+(s[i+3]-'0');
            step=4;
        }
        else if('0'<=s[i+1]&&s[i+1]<='9'&&'0'<=s[i+2]&&s[i+2]<='9'&&'0'<=s[i+3]&&s[i+3]<='9'&&'0'<=s[i+4]&&s[i+4]<='9'&&(s[i+5]<'0'||s[i+5]>'9')){
            b[p]=(s[i]-'0')*10000+(s[i+1]-'0')*1000+(s[i+2]-'0')*100+(s[i+3]-'0')*10+(s[i+4]-'0');
            step=5;
        }
        else if('0'<=s[i+1]&&s[i+1]<='9'&&'0'<=s[i+2]&&s[i+2]<='9'&&'0'<=s[i+3]&&s[i+3]<='9'&&'0'<=s[i+4]&&s[i+4]<='9'&&'0'<=s[i+5]&&s[i+5]<='9'&&(s[i+6]<'0'||s[i+6]>'9')){
            b[p]=(s[i]-'0')*100000+(s[i+1]-'0')*10000+(s[i+2]-'0')*1000+(s[i+3]-'0')*100+(s[i+4]-'0')*10+(s[i+5]-'0');
            step=6;
        }
        i+=step;
        p++;
    }                                    //将表达式中所有单个的数字字符转换成数字存入另一个数字数组中
   if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
        a[j]=s[i];
        i++;
        j++;
    }                    //将表达式中计算符号存入另一个数组中
   }
   length1=j;//2
   length2=p;//3
   i=0;

   for(k=0;k<length1;k++){
    if(a[k]=='*'){
        re1=b[k]*b[k+1];
        b[k]=re1;
        for(m=k;m<length1;m++){
            a[m]=a[m+1];
        }
        for(m=k+1;m<length2;m++){
            b[m]=b[m+1];
        }
        i++;

        length1--;
        length2--;
        k--;

    }
    else if(a[k]=='/'){
        re1=b[k]/b[k+1];
        b[k]=re1;
        for(m=k;m<length1;m++){
            a[m]=a[m+1];
        }
        for(m=k+1;m<length2;m++){
            b[m]=b[m+1];
        }
        i++;

        length1--;
        length2--;
        k--;
    }
    //length1--;
   }



   while(length1>0){
    if(a[0]=='+'){
        b[0]=b[0]+b[1];
        for(n=0;n<length1;n++){
            a[n]=a[n+1];
        }
        for(m=1;m<length2;m++){
            b[m]=b[m+1];
        }

        length1--;
        length2--;

    }
    else if(a[0]=='-'){
        b[0]=b[0]-b[1];
        for(n=0;n<length1;n++){
            a[n]=a[n+1];
        }
        for(m=1;m<length2;m++){
            b[m]=b[m+1];
        }

        length1--;
        length2--;

    }
    //length1--;
   }
   printf("%d",b[0]);
   return 0;
}



