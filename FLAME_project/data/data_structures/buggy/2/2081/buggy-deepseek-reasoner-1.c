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
char str[100000]; // @@ Duplicate global variable definition; this will cause a compilation error because `str` is already defined on line 3.
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
    if(pre=='*'||pre=='/') // @@ The condition is too restrictive; the last term (stored in `temp`) should always be added to `ret`, regardless of the last operator. For '+' and '-', `temp` holds the last number but is not added here, causing missing results.
       ret+=temp;
    if(count<=1) // @@ This condition is incorrect; it adds `num` again for a single number but fails to handle multiple numbers correctly. The final result should be computed solely by adding `temp` to `ret` unconditionally.
        ret+=num;
    printf("%d",ret);
    return 0;
}