package frontend;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Lexer {

    private List<Token> tokenList = new ArrayList<>();
    private List<ErrorType> errorList = new ArrayList<>();
    private boolean existError = false;
    private static final Lexer lexer = new Lexer();
    //静态工厂方法
    public static Lexer getInstance() {
        return lexer;
    }

    private String word = "";

    private int lineNum = 1;
    public List<Token> getTokenList() {
        return tokenList;
    }
    public List<ErrorType> getErrorList() {
        return errorList;
    }
    public void start(String testFile){
        getToken(testFile);
//        try {
//            if (existError) {
//                String errorOutputPath = "error.txt"; // 正确的单词输出文件路径
//                FileWriter errorWriter = new FileWriter(errorOutputPath, true);
//                for(int i = 0; i< errorList.size(); i++){
//                    errorList.get(i).printError(errorWriter);
//                }
//                errorWriter.close();
//            } else {
//                String stdOutputPath = "lexer.txt"; // 正确的单词输出文件路径
//                FileWriter stdWriter = new FileWriter(stdOutputPath, true);
//                for (int i = 0; i < tokenList.size(); i++) {
//                    tokenList.get(i).print(stdWriter);
//                    stdWriter.write(String.format("%d\n\n",tokenList.get(i).getLineNum()));
//                }
//                stdWriter.close();
//            }
//        }catch (IOException e){}
    }

    public void getToken(String content){
        for (int i = 0; i < content.length();){
            char c = content.charAt(i);
            if(c=='/'&&content.charAt(i+1)=='/'){//单行注释
                addList();
                for(;i<content.length() && content.charAt(i)!='\n';i++){}
            }
            else if(c=='/'&&content.charAt(i+1)=='*'){//多行注释
                addList();
                i+=2;
                for(;i+1<content.length() && (content.charAt(i)!='*' || content.charAt(i+1)!='/');i++){
                    if(content.charAt(i)=='\n'){
                        lineNum++;
                    }
                }
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
                        errorList.add(new ErrorType(lineNum, "a" , tokenList.size()));
                        existError = true;
                        word = String.format("%c%c",c,c);
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
                addList();
                if(c=='\n'){
                    lineNum++;
                }
                i++;
            }
            else{
                word += String.valueOf(c);
                i++;
            }
        }
        addList();
    }
    public TokenType getLexType(String word){
        if(TokenType.IdentifierMap.containsKey(word)) {
            return TokenType.IdentifierMap.get(word);
        }
        else if(TokenType.SpecialCharMap.containsKey(word)) {
            return TokenType.SpecialCharMap.get(word);
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
            return -1;
        }
    }
    public void addList(){
        if(!word.isEmpty()){
            TokenType lexType = getLexType(word);
            tokenList.add(new Token(lexType,word,getTokenValue(word),lineNum));
        }
        word = "";
    }
}
