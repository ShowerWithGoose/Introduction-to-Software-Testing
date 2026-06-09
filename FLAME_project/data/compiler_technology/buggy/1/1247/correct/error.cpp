#include "error.h"

#include<algorithm>
#include<cstdio>
#include<cstdlib>

void f_panic(const char *file,int line){
    fprintf(stderr,"Error on %s:%d\n",file,line);
    exit(1);
}

std::vector<Error>errors;

bool cmp(const Error &e1,const Error &e2){
    return e1.line<e2.line;
}

bool printErrors(const char *fn){
    FILE *fp=fopen(fn,"w");
    if(fp){
        std::sort(errors.begin(),errors.end(),cmp);
        for(const Error &error:errors){
            fprintf(fp,"%d %c\n",error.line,error.ecode);
        }
        fclose(fp);
        return true;
    }
    return false;
}
