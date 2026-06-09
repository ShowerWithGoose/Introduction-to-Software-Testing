package frontend;

import javax.imageio.IIOException;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

public class Lexer {

    // map映射
    HashMap<String,TokenType> IdentifierMap = new HashMap<>();
    HashMap<String,TokenType> SpecialCharMap = new HashMap<>();
    List<Token> tokenList = new ArrayList<>();
    List<Integer> errorLine = new ArrayList<>();
    private boolean existError = false;
    // 饿汉式单例
    private Lexer() {
        // 标识符
        this.IdentifierMap.put("main",TokenType.Main);
        this.IdentifierMap.put("const",TokenType.Const);
        this.IdentifierMap.put("int",TokenType.Int);
        this.IdentifierMap.put("char",TokenType.Char);
        this.IdentifierMap.put("break",TokenType.Break);
        this.IdentifierMap.put("continue",TokenType.Continue);
        this.IdentifierMap.put("if",TokenType.If);
        this.IdentifierMap.put("else",TokenType.Else);
        this.IdentifierMap.put("for",TokenType.For);
        this.IdentifierMap.put("getint",TokenType.Getint);
        this.IdentifierMap.put("getchar",TokenType.Getchar);
        this.IdentifierMap.put("printf",TokenType.Printf);
        this.IdentifierMap.put("return",TokenType.Return);
        this.IdentifierMap.put("void",TokenType.Void);
        // 特殊字符
        this.SpecialCharMap.put("!",TokenType.Not);
        this.SpecialCharMap.put("&&",TokenType.And);
        this.SpecialCharMap.put("||",TokenType.Or);
        this.SpecialCharMap.put("+",TokenType.Plus);
        this.SpecialCharMap.put("-",TokenType.Minu);
        this.SpecialCharMap.put("*",TokenType.Mult);
        this.SpecialCharMap.put("/",TokenType.Div);
        this.SpecialCharMap.put("%",TokenType.Mod);
        this.SpecialCharMap.put("<",TokenType.Lss);
        this.SpecialCharMap.put("<=",TokenType.Leq);
        this.SpecialCharMap.put(">",TokenType.Gre);
        this.SpecialCharMap.put(">=",TokenType.Geq);
        this.SpecialCharMap.put("==",TokenType.Eql);
        this.SpecialCharMap.put("!=",TokenType.Neq);
        this.SpecialCharMap.put("=",TokenType.Assign);
        this.SpecialCharMap.put(";",TokenType.Semicn);
        this.SpecialCharMap.put(",",TokenType.Comma);
        this.SpecialCharMap.put("(",TokenType.Lparent);
        this.SpecialCharMap.put(")",TokenType.Rparent);
        this.SpecialCharMap.put("[",TokenType.Lbrack);
        this.SpecialCharMap.put("]",TokenType.Rbrack);
        this.SpecialCharMap.put("{",TokenType.Lbrace);
        this.SpecialCharMap.put("}",TokenType.Rbrace);
    }
    private static final Lexer lexer = new Lexer();
    //静态工厂方法
    public static Lexer getInstance() {
        return lexer;
    }

    private String word = "";

    public void start(String testFile){
        try {
            getToken(testFile);
            if (existError) {
                String errorOutputPath = "error.txt"; // 正确的单词输出文件路径
                FileWriter errorWriter = new FileWriter(errorOutputPath, true);
                errorOutput(errorWriter, errorLine.get(0));
                errorWriter.close();
            } else {
                String stdOutputPath = "lexer.txt"; // 正确的单词输出文件路径
                FileWriter stdWriter = new FileWriter(stdOutputPath, true);
                for (int i = 0; i < tokenList.size(); i++) {
                    stdOutput(stdWriter, tokenList.get(i).getType(), tokenList.get(i).getWord());
                }
                stdWriter.close();
            }
        }catch (IOException e){}
    }

    public void getToken(String content){
        int lineNum = 1;
        for (int i = 0; i < content.length();){
            char c = content.charAt(i);
            if(c=='/'&&content.charAt(i+1)=='/'){//单行注释
                for(;i<content.length() && content.charAt(i)!='\n';i++){}
            }
            else if(c=='/'&&content.charAt(i+1)=='*'){//多行注释
                i+=2;
                for(;i+1<content.length() && (content.charAt(i)!='*' || content.charAt(i+1)!='/');i++){}
                i+=2;
            }
            else if(c=='\"'){//字符串常量
                addList();
                int j = i + 1;
                while (j<content.length() && content.charAt(j)!='\"'){
                    j++;
                }
                word = content.substring(i,j+1);
                i = j + 1;
                addList();
            }
            else if(c=='\''){//字符常量
                addList();
                if(content.charAt(i+1)=='\\'){//有转义字符
                    word=content.substring(i,i+4);
                    i+=4;
                }
                else{//非转义字符
                    word=content.substring(i,i+3);
                    i+=3;
                }
                addList();
            }
            else if(FrontStatic.isSpecialChar(c)){//一些特殊字符
                addList();
                word = String.valueOf(c);
                if(c=='&' || c=='|'){
                    if(content.charAt(i+1) != c) {
                        errorLine.add(lineNum);
                        existError = true;
                        i++;
                    }
                    else{
                        word = content.substring(i,i+2);
                        i+=2;
                    }
                }
                else if(c == '<' || c == '>' || c == '=' || c == '!'){
                    if(content.charAt(i+1)=='='){
                        word = content.substring(i,i+2);
                        i+=2;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    i++;
                }
                addList();
            }
            else if(Character.isWhitespace(c)){
                if(c=='\n'){
                    lineNum++;
                }
                addList();
                i++;
            }
            else{
                word += String.valueOf(c);
                i++;
            }
        }
    }
    public TokenType getLexType(String word){
        if(this.IdentifierMap.containsKey(word)) {
            return this.IdentifierMap.get(word);
        }
        else if(this.SpecialCharMap.containsKey(word)) {
            return this.SpecialCharMap.get(word);
        }
        else{
            if(FrontStatic.isDigit(word)){
                return TokenType.IntConst;
            }
            else if(FrontStatic.isChar(word)){
                return TokenType.CharConst;
            }
            else if(FrontStatic.isString(word)) {
                return TokenType.StringConst;
            }
            else{
                return TokenType.Ident;
            }
        }
    }
    public long getTokenValue(String word){
        if(FrontStatic.isDigit(word)) {
            return Long.parseLong(word);
        }
        else{
            return 0;
        }
    }
    public void addList(){
        if(!word.isEmpty()){
            TokenType lexType = getLexType(word);
            tokenList.add(new Token(lexType,word,getTokenValue(word)));
        }
        word = "";
    }
    public void stdOutput(FileWriter stdWriter,TokenType lexType,String token) throws IOException {
        stdWriter.write(String.format("%s %s\n",lexType.toString(),token));
    }
    public void errorOutput(FileWriter errorWriter,int lineNum) throws IOException {
        errorWriter.write(String.format("%d a",lineNum));
    }
}
