#include<stdio.h>
#include<string.h>
char str[100000];
//int main(){
//    int i;
//    gets(str);
//    int len=strlen(str);
//    printf("%c",str[0]);
//    for(i=1;i<len;i++){
//        if(str[i]=='-'){
//            if(str[i-1]>='0'&&str[i-1]<'9'&&str[i+1]>str[i-1]&&str[i+1]<='9'){
//                for(int j=1;j<str[i+1]-str[i-1];j++)
//                    printf("%c",str[i-1]+j);
//            }
//           else if(str[i-1]>='a'&&str[i-1]<'z'&&str[i+1]>str[i-1]&&str[i+1]<='z'){
//                for(int j=1;j<str[i+1]-str[i-1];j++)
//                    printf("%c",str[i-1]+j);
//            }
//           else if(str[i-1]>='A'&&str[i-1]<'Z'&&str[i+1]>str[i-1]&&str[i+1]<='Z'){
//                for(int j=1;j<str[i+1]-str[i-1];j++)
//                    printf("%c",str[i-1]+j);
//            }
//            else
//                printf("-");
//        }
//        else
//            printf("%c",str[i]);
//    }
//    return 0;
//}
char str[100000]; // @@ duplicate declaration of 'str' causes redefinition error (compilation error)
int main(){
    gets(str);
    int i,j;
    for(i=j=0;str[i]!='\0';i++){
        if(str[i]!=' ')
            str[j++]=str[i];
    }
    int num=0,pre='+',temp=0,ret=0,count=0;
    for(i=0;str[i]!='=';i++){
        if(str[i]>='0'&&str[i]<='9'){
            sscanf(str+i,"%d",&num);
            count++;
            while(str[i]>='0'&&str[i]<='9')
                i++;
            i--;
            switch(pre){
                case '+':ret+=temp;temp=num;break;
                case '-':ret+=temp;temp=-num;break;
                case '*':temp*=num;break;
                case '/':temp/=num;break;
            }
        }
        else
            pre=str[i];
    }
    if(pre=='*'||pre=='/') // @@ logical error: should always add temp to ret regardless of last operator; missing addition for '+' and '-' leads to incorrect results
       ret+=temp;
    if(count<=1) // @@ logical error: this condition is unnecessary and can cause incorrect result when count==1 but temp already holds the number; the proper fix is to add temp unconditionally
        ret+=num;
    printf("%d",ret);
    return 0;
}