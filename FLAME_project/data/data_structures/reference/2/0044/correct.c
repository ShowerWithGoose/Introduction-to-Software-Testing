#include <stdio.h>
#include <string.h>

char aaaaaa[3];
int  bbbbbb[4];
int  aaa_cnt=0;
int  bbb_cnt=0;
int ops_value(int a,int b,char ops)
{
    if(ops=='+') return (a+b);
    if(ops=='-') return (a-b);
    if(ops=='*') return (a*b);
    if(ops=='/') return (a/b);
}
void ops_merge(char c)
{
    int a,b;
    char ops;
    if(aaa_cnt==0){
        aaaaaa[aaa_cnt++]=c;
    }else if(aaa_cnt==1){
        ops=aaaaaa[aaa_cnt-1];
        if(c=='+'||c=='-'){
            a=bbbbbb[bbb_cnt-2];
            b=bbbbbb[bbb_cnt-1];
            bbbbbb[bbb_cnt-2]=ops_value(a,b,ops);
            bbb_cnt--;
            aaaaaa[aaa_cnt-1]=c;
        }else{
            if(ops=='*'||ops=='/'){
                a=bbbbbb[bbb_cnt-2];
                b=bbbbbb[bbb_cnt-1];
                bbbbbb[bbb_cnt-2]=ops_value(a,b,ops);
                bbb_cnt--;
                aaaaaa[aaa_cnt-1]=c;
            }else{ aaaaaa[aaa_cnt++]=c; }
        }
    }else{
        ops=aaaaaa[aaa_cnt-1];
        a=bbbbbb[bbb_cnt-2];
        b=bbbbbb[bbb_cnt-1];
        bbbbbb[bbb_cnt-2]=ops_value(a,b,ops);
        bbb_cnt--;
        aaa_cnt--;
        ops_merge(c);
    }
}
int main()
{
    char buf[256]={0};
    int size=0,value=0,bits=0,i;

    fgets(buf,sizeof(buf),stdin);
    size=strlen(buf);
    for (i=0; i < size; i++){
        char c=buf[i];
        if(c==' '){
            if(bits){
                bbbbbb[bbb_cnt++]=value;
                value=0;
                bits=0;
            }
        }else if(c >= '0' && c <= '9'){
            value=(value * 10) +  (c-'0');
            bits++;
        }else if(c=='+'||c=='-'||c=='*'||c=='/' )  {
            if(bits){
                bbbbbb[bbb_cnt++]=value;
                value=0;
                bits=0;
            }
            ops_merge(c);
        }else if(c=='='){
            if(bits){
                bbbbbb[bbb_cnt++]=value;
                value=0;
                bits=0;
            }
            while (aaa_cnt > 0){
                bbbbbb[bbb_cnt-2]=ops_value(bbbbbb[bbb_cnt-2],bbbbbb[bbb_cnt-1],aaaaaa[aaa_cnt-1]);
                bbb_cnt--;
                aaa_cnt--;
            }
            printf("%d\n",bbbbbb[aaa_cnt]);
            break;
        }else{
            printf("input error.\n");
            return -1;
        }
    }
    return 0;
}





