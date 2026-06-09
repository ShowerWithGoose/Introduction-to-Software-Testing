package frontend;

import java.io.*;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;

public class Lexer {
    public static String[] type_code = new String[10000];
    public static String[] word = new String[10000];
    public static int[] error_line = new int[10000];
    public static String[] error_code = new String[10000];
    public static int j=0;
    public static int k=0;
    public static int lexer(String content) throws IOException {
        int err=0;
        int line=1;
        for (int i=0;i<content.length();i++){
            StringBuilder sb = new StringBuilder();
            if(content.charAt(i)=='\n'){
                line++;
            }
            if(content.charAt(i)=='_'||Character.isLetter(content.charAt(i))){
                sb.append(content.charAt(i));
                i++;
                while(i<content.length()&&(content.charAt(i)=='_'||Character.isLetter(content.charAt(i))||Character.isDigit(content.charAt(i)))){
                    sb.append(content.charAt(i));
                    i++;
                }
                word[j] = sb.toString();
                if(word[j].equals("main")){
                    type_code[j]="MAINTK";
                } else if (word[j].equals("const")) {
                    type_code[j]="CONSTTK";
                } else if (word[j].equals("int")) {
                    type_code[j]="INTTK";
                } else if (word[j].equals("char")) {
                    type_code[j]="CHARTK";
                } else if (word[j].equals("break")) {
                    type_code[j]="BREAKTK";
                } else if (word[j].equals("continue")) {
                    type_code[j]="CONTINUETK";
                } else if (word[j].equals("if")) {
                    type_code[j]="IFTK";
                } else if (word[j].equals("else")) {
                    type_code[j]="ELSETK";
                } else if (word[j].equals("for")) {
                    type_code[j]="FORTK";
                } else if (word[j].equals("getint")) {
                    type_code[j]="GETINTTK";
                } else if (word[j].equals("getchar")) {
                    type_code[j]="GETCHARTK";
                } else if (word[j].equals("printf")) {
                    type_code[j]="PRINTFTK";
                } else if (word[j].equals("return")) {
                    type_code[j] = "RETURNTK";
                } else if (word[j].equals("void")) {
                    type_code[j] = "VOIDTK";
                }else {
                    type_code[j] = "IDENFR";
                }
                j++;
                i--;
            }
            else if(Character.isDigit(content.charAt(i))){
                sb.append(content.charAt(i));
                i++;
                while(i<content.length()&&Character.isDigit(content.charAt(i))){
                    sb.append(content.charAt(i));
                    i++;
                }
                word[j] = sb.toString();
                type_code[j]="INTCON";
                j++;
                i--;
            }
            else if(content.charAt(i)=='"'){
                i++;
                sb.append('"');
                while(i<content.length()&&content.charAt(i)!='"'){
                    sb.append(content.charAt(i));
                    i++;
                }
                sb.append('"');
                word[j] = sb.toString();
                type_code[j]="STRCON";
                j++;
            }
            else if(content.charAt(i)=='\''){
                i++;
                sb.append('\'');
                while(i<content.length()&&content.charAt(i)!='\''){
                    sb.append(content.charAt(i));
                    i++;
                }
                sb.append('\'');
                word[j] = sb.toString();
                type_code[j]="CHRCON";
                j++;
            }
            else if(content.charAt(i)=='!'){
                if(i+1<content.length()&&content.charAt(i+1)=='='){
                    i++;
                    word[j]="!=";
                    type_code[j]="NEQ";
                    j++;
                }
                else{
                    word[j]="!";
                    type_code[j]="NOT";
                    j++;
                }
            }
            else if(content.charAt(i)=='&'){
                i++;
                if(content.charAt(i)=='&'){
                    word[j]="&&";
                    type_code[j]="AND";
                    j++;
                }
                else{
                    err=1;
                    error_line[k]=line;
                    error_code[k]="a";
                    k++;
                }
            }
            else if(content.charAt(i)=='|'){
                i++;
                if(content.charAt(i)=='|'){
                    word[j]="||";
                    type_code[j]="OR";
                    j++;
                }
                else{
                    err=1;
                    error_line[k]=line;
                    error_code[k]="a";
                    k++;
                }
            }
            else if(content.charAt(i)=='+'){
                word[j]="+";
                type_code[j]="PLUS";
                j++;
            }
            else if(content.charAt(i)=='-'){
                word[j]="-";
                type_code[j]="MINU";
                j++;
            }
            else if(content.charAt(i)=='*'){
                word[j]="*";
                type_code[j]="MULT";
                j++;
            }
            else if(content.charAt(i)=='/'){
                i++;
                if(content.charAt(i)=='/'){
                    i++;
                    while(i<content.length()&&content.charAt(i)!='\n'){
                        i++;
                    }
                    line++;
                }
                else if(content.charAt(i)=='*'){
                    i++;
                    while(i+1<content.length()&&(content.charAt(i)!='*'||content.charAt(i+1)!='/')){
                        if(content.charAt(i)=='\n'){
                            line++;
                        }
                        i++;
                    }
                    i++;
                }
                else{
                    word[j]="/";
                    type_code[j]="DIV";
                    j++;
                }
            }
            else if(content.charAt(i)=='%'){
                word[j]="%";
                type_code[j]="MOD";
                j++;
            }
            else if(content.charAt(i)=='<'){
                if(i+1<content.length()&&content.charAt(i+1)=='='){
                    i++;
                    word[j]="<=";
                    type_code[j]="LEQ";
                    j++;
                }
                else{
                    word[j]="<";
                    type_code[j]="LSS";
                    j++;
                }
            }
            else if(content.charAt(i)=='>'){
                if(i+1<content.length()&&content.charAt(i+1)=='='){
                    i++;
                    word[j]=">=";
                    type_code[j]="GEQ";
                    j++;
                }
                else{
                    word[j]=">";
                    type_code[j]="GRE";
                    j++;
                }
            }
            else if(content.charAt(i)=='='){
                if(i+1<content.length()&&content.charAt(i+1)=='='){
                    i++;
                    word[j]="==";
                    type_code[j]="EQL";
                    j++;
                }
                else{
                    word[j]="=";
                    type_code[j]="ASSIGN";
                    j++;
                }
            }
            else if(content.charAt(i)==';'){
                word[j]=";";
                type_code[j]="SEMICN";
                j++;
            }
            else if(content.charAt(i)==',') {
                word[j] = ",";
                type_code[j] = "COMMA";
                j++;
            }
            else if(content.charAt(i)=='('){
                word[j]="(";
                type_code[j]="LPARENT";
                j++;
            }
            else if(content.charAt(i)==')'){
                word[j]=")";
                type_code[j]="RPARENT";
                j++;
            }
            else if(content.charAt(i)=='['){
                word[j]="[";
                type_code[j]="LBRACK";
                j++;
            }
            else if(content.charAt(i)==']'){
                word[j]="]";
                type_code[j]="RBRACK";
                j++;
            }
            else if(content.charAt(i)=='{'){
                word[j]="{";
                type_code[j]="LBRACE";
                j++;
            }
            else if(content.charAt(i)=='}'){
                word[j]="}";
                type_code[j]="RBRACE";
                j++;
            }
        }
        if(err==0) {
            return 0;
        }
        else{
            return 1;
        }
    }
}
