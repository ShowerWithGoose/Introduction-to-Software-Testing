package frontend;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


/**
 * @author
 * @Description
 * @date 2024/10/4 17:39
 */
public class Lexer {
    private String testFile;
    Integer index;
    Integer len;
    Integer lineno;
    public ArrayList<Token> tokenList = new ArrayList<>();
    public boolean haveError;
    public ArrayList<Error> errorList = new ArrayList<>();


    public void lexTestFile() {
        int haveNext;
        while (index < len){
            haveNext = next();
            if(haveNext==0){
                tokenList.add(new Token(Token.TokenType.EOF, "EOF", lineno));
                break;
            }
        }
        // log();
    }

    private char get() {
        char c;
        if(index<len){
            c=testFile.charAt(index);
            index++;
        } else {
            c=0;
        }
        return c;
    }

    private void unget() {
        if(index<=len) {
            index--;
        }
    }

    private int next(){
        int haveNext = 1;
        StringBuilder str= new StringBuilder();
        char c;
        c=get();
        while(index<=len&&Character.isWhitespace(c)){
            if(c=='\n'){
                lineno++;
            }
            c=get();
        }
        if(Character.isAlphabetic(c)||c=='_'){
            str.append(c);
            c = get();
            while (Character.isAlphabetic(c) || c == '_' || Character.isDigit(c)) {
                str.append(c);
                c = get();
            }
            unget();
            switch (str.toString()) {
                case "main" -> tokenList.add(new Token(Token.TokenType.MAINTK, str.toString(), lineno));
                case "const" -> tokenList.add(new Token(Token.TokenType.CONSTTK, str.toString(), lineno));
                case "int" -> tokenList.add(new Token(Token.TokenType.INTTK, str.toString(), lineno));
                case "char" -> tokenList.add(new Token(Token.TokenType.CHARTK, str.toString(), lineno));
                case "break" -> tokenList.add(new Token(Token.TokenType.BREAKTK, str.toString(), lineno));
                case "continue" -> tokenList.add(new Token(Token.TokenType.CONTINUETK, str.toString(), lineno));
                case "if" -> tokenList.add(new Token(Token.TokenType.IFTK, str.toString(), lineno));
                case "else" -> tokenList.add(new Token(Token.TokenType.ELSETK, str.toString(), lineno));
                case "for" -> tokenList.add(new Token(Token.TokenType.FORTK, str.toString(), lineno));
                case "getint" -> tokenList.add(new Token(Token.TokenType.GETINTTK, str.toString(), lineno));
                case "getchar" -> tokenList.add(new Token(Token.TokenType.GETCHARTK, str.toString(), lineno));
                case "printf" -> tokenList.add(new Token(Token.TokenType.PRINTFTK, str.toString(), lineno));
                case "return" -> tokenList.add(new Token(Token.TokenType.RETURNTK, str.toString(), lineno));
                case "void" -> tokenList.add(new Token(Token.TokenType.VOIDTK, str.toString(), lineno));
                default -> tokenList.add(new Token(Token.TokenType.IDENFR, str.toString(), lineno));
            }
        } else if (Character.isDigit(c)) {
            str.append(c);
            c=get();
            while (Character.isDigit(c)){
                str.append(c);
                c=get();
            }
            unget();
            tokenList.add(new Token(Token.TokenType.INTCON, str.toString(), lineno));
        } else if (c=='\"') {
            str.append(c);
            c=get();
            while (c!='\"'){
                str.append(c);
                c=get();
            }
            str.append(c);
            tokenList.add(new Token(Token.TokenType.STRCON, str.toString(), lineno));
        } else if (c=='\'') {
            str.append(c);
            c=get();
            while (c!='\''){
                str.append(c);
                c=get();
            }
            str.append(c);
            tokenList.add(new Token(Token.TokenType.CHRCON, str.toString(), lineno));
        } else if (c=='!') {
            str.append(c);
            c=get();
            if(c=='='){
                str.append(c);
                tokenList.add(new Token(Token.TokenType.NEQ, str.toString(), lineno));
            }else {
                unget();
                tokenList.add(new Token(Token.TokenType.NOT, str.toString(), lineno));
            }
        } else if (c=='&') {
            str.append(c);
            c=get();
            if(c!='&'){
                unget();
                haveError=true;
                errorList.add(new Error(lineno, 'a'));
            }
            str.append(c);
            tokenList.add(new Token(Token.TokenType.AND, str.toString(), lineno));
        } else if (c=='|') {
            str.append(c);
            c=get();
            if(c!='|'){
                unget();
                haveError=true;
                errorList.add(new Error(lineno, 'a'));
            }
            str.append(c);
            tokenList.add(new Token(Token.TokenType.OR, str.toString(), lineno));
        } else if (c=='+') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.PLUS, str.toString(), lineno));
        } else if (c=='-') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.MINU, str.toString(), lineno));
        } else if (c=='*') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.MULT, str.toString(), lineno));
        } else if (c=='/') {
            str.append(c);
            c=get();
            if(c=='/'){
                c=get();
                while(index<=len && c!='\n'){
                    c=get();
                }
                if(c=='\n') {
                    lineno++;
                }
            } else if (c=='*') {
                c=get();
                while(index<=len){
                    if(c=='\n'){
                        lineno++;
                    }else if (c=='*'){
                        c=get();
                        if(c=='/'){
                            break;
                        }else{
                            unget();
                        }
                    }
                    c=get();
                }
            }else {
                unget();
                tokenList.add(new Token(Token.TokenType.DIV, str.toString(), lineno));
            }
        } else if (c=='%') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.MOD, str.toString(), lineno));
        } else if (c=='<') {
            str.append(c);
            c=get();
            if(c=='='){
                str.append(c);
                tokenList.add(new Token(Token.TokenType.LEQ, str.toString(), lineno));
            }else{
                unget();
                tokenList.add(new Token(Token.TokenType.LSS, str.toString(), lineno));
            }
        } else if (c=='>') {
            str.append(c);
            c=get();
            if(c=='='){
                str.append(c);
                tokenList.add(new Token(Token.TokenType.GEQ, str.toString(), lineno));
            }else{
                unget();
                tokenList.add(new Token(Token.TokenType.GRE, str.toString(), lineno));
            }
        }  else if (c=='=') {
            str.append(c);
            c=get();
            if(c=='='){
                str.append(c);
                tokenList.add(new Token(Token.TokenType.EQL, str.toString(), lineno));
            }else{
                unget();
                tokenList.add(new Token(Token.TokenType.ASSIGN, str.toString(), lineno));
            }
        } else if (c==';') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.SEMICN, str.toString(), lineno));
        } else if (c==',') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.COMMA, str.toString(), lineno));
        } else if (c=='(') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.LPARENT, str.toString(), lineno));
        } else if (c==')') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.RPARENT, str.toString(), lineno));
        } else if (c=='[') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.LBRACK, str.toString(), lineno));
        } else if (c==']') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.RBRACK, str.toString(), lineno));
        } else if (c=='{') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.LBRACE, str.toString(), lineno));
        } else if (c=='}') {
            str.append(c);
            tokenList.add(new Token(Token.TokenType.RBRACE, str.toString(), lineno));
        } else {
            if(c=='\n'){
                lineno++;
            }
            haveNext=0;
        }
        return haveNext;
    }

    private void log(){
        if(haveError){
//            System.out.println("输出错误文件中");
            try {
                String path="./error.txt";
                File file=new File(new File(path).getCanonicalPath());
                file.delete();
                if (!file.exists()) {
                    file.getParentFile().mkdirs();
                    file.createNewFile();
                }
                FileWriter writer=new FileWriter(file,true);
                for(Error error: errorList)
                    writer.write(error.toString()+"\n");
                writer.close();
            }catch (IOException e){
                System.out.println("File operation failed");
            }
        }else{
//            System.out.println("输出词法分析文件中");
            try {
                String path="./lexer.txt";
                File file=new File(new File(path).getCanonicalPath());
                file.delete();
                if (!file.exists()) {
                    file.getParentFile().mkdirs();
                    file.createNewFile();
                }
                FileWriter writer=new FileWriter(file,true);
                for(Token token: tokenList)
                    if(token.getType()!= Token.TokenType.EOF)
                        writer.write(token.toString()+"\n");
                writer.close();
            }catch (IOException e){
                System.out.println("File operation failed");
            }
        }
    }

    public Lexer(){}

    public Lexer(String testFile){
        this.testFile = testFile;
        this.len = testFile.length();
        this.index = 0;
        this.lineno = 1;
        this.haveError = false;
    }

}
