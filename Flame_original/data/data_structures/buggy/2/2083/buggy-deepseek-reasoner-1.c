#include<stdio.h>
#include<string.h>
#include<math.h>
int t[1000];
char p[1000];
int main (){
    char s[1000];
    
    int i,j,a=0,b=0,c=0,d=0,e=0,x=0,y=0,z=0,m=0,l,h=0,u,v,as;
    gets(s);
    for(i=j=0;s[i]!='\0';i++){
        
        if(s[i]=='+'){
        a++;
        p[h]='+';
        h++;
    }
        if(s[i]=='-')
        {
        b++;
        p[h]='-';
        h++;
    }
        if(s[i]=='*')
        {
        c++;
        p[h]='*';
        h++;
    }
        if(s[i]=='/'){
        d++;
        p[h]='/';
        h++;
    }
        if(s[i]!=32)
            s[j++]=s[i]; // @@ This line incorrectly retains the '=' character. The '=' should be treated as the end of input and not copied into the new string, otherwise subsequent parsing will fail.
}
        s[j]='\0';
        p[h]='\0';
        printf("%s\n",s);
        e=a+b+c+d;//有e+1个数
        for( l=0;s[l]!='\0';l++){
            if(s[l]=='+'||s[l]=='-'||s[l]=='*'||s[l]=='/'){
                m=l;
                break;
            }
        }
        for(m=m-1;m>=0;m--){
            x=s[m]-'0';
            y=pow(10,z);
            z++;
            t[0]+=y*x;
        }
        z=0;
        for(int p=j;p>=l;p--){ // @@ This loop iterates backward over the entire string, including the null terminator and the '=' character. It attempts to extract numbers in reverse order, which is logically incorrect. Numbers should be extracted in forward order from left to right.
            if(s[p]!='+'&&s[p]!='-'&&s[p]!='*'&&s[p]!='/'&&s[p]!='='){ // @@ The condition includes '=', but '=' is not a digit and should not be treated as part of a number. This leads to invalid conversion and wrong indexing.
                x=s[p]-'0'; // @@ When s[p] is '=' or '\0', s[p]-'0' is not a valid digit, causing erroneous integer values.
                y=pow(10,z);
                z++;
                t[e+1]+=y*x; // @@ Using e+1 as an index while e is decremented inside the else branch leads to inconsistent and incorrect placement of numbers in the t array.
            }
                else
                {
                e--;
                z=0;
            }
        }
        for(int w=0;w<h;w++){
            if(p[w]=='*'||p[w]=='/'){
                if(p[w]=='*'){
                    t[w+1]=t[w]*t[w+1];
                    t[w]=20245986;
                }
                if(p[w]=='/'){
                    t[w+1]=t[w]/t[w+1];
                    t[w]=20245986;
                }
            }
        }
        for( u=0,v=0;u<a+b+c+d+1;u++){
            if(p[u]!='*'&&p[u]!='/')
            p[v++]=p[u];
        
        
}
    for( u=0,v=0;u<a+b+c+d+1;u++){
            if(t[u]!=20245986)
            t[v++]=t[u];
        
        
}
p[v]='\0';

        for( as=0;as<a+b+1;as++){ // @@ This loop assumes that after compressing the '*' and '/' operators, the number of remaining operators is exactly a+b, but the compression may have changed the total count. Also, the indices in t[as] and t[as+1] may not correspond to the correct operands after the previous flawed number extraction.
            if(p[as]=='+'){
                t[as+1]=t[as]+t[as+1];
                
            }
            if(p[as]=='-'){
                t[as+1]=t[as]-t[as+1];
            }
        }
        printf("%d",t[a+b]); // @@ The index a+b is not guaranteed to hold the final result after the series of incorrect array manipulations. The result should be at t[0] after all operations, but this line uses a potentially invalid index.
    
}