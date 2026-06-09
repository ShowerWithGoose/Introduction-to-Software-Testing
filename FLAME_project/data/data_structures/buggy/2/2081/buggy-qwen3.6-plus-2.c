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
char str[100000];
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
                case '+':ret+=temp;temp=num;break; // @@ The logic fails to handle the initial state correctly. When pre is '+', it adds the previous temp (initialized to 0) to ret, which is fine for subsequent terms, but the handling of the first term and the accumulation logic is flawed when mixed with * and /. Specifically, `temp` holds the current term being built by * or /. When a new + or - is encountered, the completed `temp` should be added to `ret`. However, the initialization `temp=0` and `pre='+'` causes the first number to be assigned to `temp` without adding anything to `ret`. This part is actually okay for the first term, but the issue lies in how `ret` is finalized.
                case '-':ret+=temp;temp=-num;break;
                case '*':temp*=num;break;
                case '/':temp/=num;break;
            }
        }
        else
            pre=str[i];
    }
    if(pre=='*'||pre=='/')
       ret+=temp; // @@ This condition is incorrect. The last term stored in `temp` must ALWAYS be added to `ret` at the end of the expression, regardless of whether the last operator was * or / or if there was no operator (single number). For example, in "1+2", pre becomes '+', temp becomes 2. The loop ends. This condition checks if pre is * or /, which is false, so ret (which is 1 from the first step? No, ret is 0. Wait. 
       // Let's trace "1+2". 
       // i=0, num=1, count=1. pre='+'. Case '+': ret+=0 (ret=0), temp=1.
       // i=1, pre='+'.
       // i=2, num=2, count=2. pre='+'. Case '+': ret+=1 (ret=1), temp=2.
       // Loop ends. pre is '+'. Condition false. ret is 1. Expected 3.
       // So the error is that the final `temp` is not added to `ret` if the last operator was + or -.
    if(count<=1)
        ret+=num; // @@ This line attempts to patch single-number cases but interferes with multi-number cases. In "1+2", count is 2, so this is skipped. The result remains 1. The correct fix is to always add `temp` to `ret` after the loop.
    printf("%d",ret);
    return 0;
}