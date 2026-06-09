#include<stdio.h>
#include<stdlib.h>

#define DEFAULT_MAX_SIZE (100)

struct string{
	char* buffer;
	int max_size;
	int size;
};

void create_string(struct string* str,int MAX_SIZE);
void create_string_for_a_range(struct string* str,char l,char r);
void destroy_string(struct string* str);
void create_string_from_read_buffer(struct string* str);
void realloc_string_buffer(struct string* str,int RE_SIZE);
void print(struct string* str);

int get_type(char c){
	if('0'<=c&&c<='9')return 0;
	if('a'<=c&&c<='z')return 1;
	return 2;
}

int main(){
	struct string s;
	create_string_from_read_buffer(&s);
	
	for(int i=0;i<s.size;i++){
		if(s.buffer[i]=='-'&&
		   get_type(s.buffer[i-1])==get_type(s.buffer[i+1])&&
		   s.buffer[i-1]<s.buffer[i+1]){
		   	char l=s.buffer[i-1]+1;
		   	char r=s.buffer[i+1]-1;
			for(char j=l;j<=r;j++){
				printf("%c",j);
			}
		}else printf("%c",s.buffer[i]);
	}
	//free : ignore to speed up
	return 0;
}

void create_string(struct string* str,int MAX_SIZE){
	str->max_size=(MAX_SIZE?MAX_SIZE:DEFAULT_MAX_SIZE);
	str->size=0;
	str->buffer=(char*)malloc(sizeof(char)*str->max_size);
}
void destroy_string(struct string* str){
	free(str->buffer);
}
void create_string_for_a_range(struct string* str,char l,char r){
	str->max_size=(int)(r-l+1);
	str->buffer=(char*)malloc(sizeof(char)*str->max_size);
	for(char i=l;i<=r;i++)
		str->buffer[str->size++]=i;
}
void create_string_from_read_buffer(struct string* str){
	str->max_size=DEFAULT_MAX_SIZE;
	str->size=0;
	str->buffer=(char*)malloc(sizeof(char)*str->max_size);
	char c=getchar();
	while(c!=EOF){
		str->buffer[str->size++]=c;
		c=getchar();
		if(str->size==str->max_size){
			realloc_string_buffer(str,str->max_size*2);
		}
	}
}
void realloc_string_buffer(struct string* str,int RE_SIZE){
	char* old_buffer=str->buffer;
	char* new_buffer=(char*)malloc(sizeof(char)*RE_SIZE);
	memcpy(new_buffer,old_buffer,str->size);
	str->max_size=RE_SIZE;
	str->buffer=new_buffer;
	free(old_buffer);
}

