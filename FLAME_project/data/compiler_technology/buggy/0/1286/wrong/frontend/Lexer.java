package frontend;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * @Author:
 * @Date: 2024/9/24 10:39
 */
public class Lexer {
    private static Lexer instance;    //词法分析器类单例模式
    private String source;  //源程序字符串
    private char curPos;    //当前字符串位置指针
    private String token;   //解析单词值
    private LexType lexType;    //解析单词类型
    private Map<String,LexType> reserveWords;   //保留字表(暂未用)
    private int lineNum;    //当前行号
    private int number; //解析数值
    private boolean isCorrect=true;
    private int falseLineNumber;
    private char falseType;
    private List<Token> tokens = new ArrayList<>();
    private Lexer(){    //单例模式
        reserveWords = new HashMap<>();
        reserveWords.put("main", LexType.MAINTK);
        reserveWords.put("const", LexType.CONSTTK);
        reserveWords.put("int", LexType.INTTK);
        reserveWords.put("char", LexType.CHARTK);
        reserveWords.put("break", LexType.BREAKTK);
        reserveWords.put("continue", LexType.CONTINUETK);
        reserveWords.put("if", LexType.IFTK);
        reserveWords.put("else", LexType.ELSETK);
        reserveWords.put("for", LexType.FORTK);
        reserveWords.put("getint", LexType.GETINTTK);
        reserveWords.put("getchar", LexType.GETCHARTK);
        reserveWords.put("printf", LexType.PRINTFTK);
        reserveWords.put("return", LexType.RETURNTK);
        reserveWords.put("void", LexType.VOIDTK);
    }
    public static Lexer getInstance(){
        if(instance == null)
        {
            instance = new Lexer();
        }
        return instance;
    }
    public void init(File file) throws IOException{
        source = new String(Files.readAllBytes(Paths.get(file.getPath())));
        curPos=0;
        lineNum=1;
    }
    public boolean next(){    //处理下一个单词
        if(curPos >= source.length())   //读取完成
            return false;

        while(curPos < source.length() &&
                (Character.isWhitespace(source.charAt(curPos)) || source.charAt(curPos)=='\n'))
        {
            if (source.charAt(curPos)=='\n')
                lineNum++;
            curPos++;
        }

        if (curPos>=source.length())
            return false;

        //处理标识符、数字或符号
        StringBuilder tokenBuilder = new StringBuilder();
        char curChar = source.charAt(curPos);


        if(isNonDigit(curChar)){    //处理标识符或保留字
            while(curPos < source.length() &&
                    (isNonDigit(source.charAt(curPos)) || Character.isDigit(source.charAt(curPos)))){
                tokenBuilder.append(source.charAt(curPos));
                curPos++;
            }
            token = tokenBuilder.toString();
            lexType = identifyLexType(token);
        }else if (Character.isDigit(curChar)){  //处理数字常量
            while(curPos < source.length() && Character.isDigit(source.charAt(curPos))){
                tokenBuilder.append(source.charAt(curPos));
                curPos++;
            }
            token = tokenBuilder.toString();
            //number = Integer.parseInt(token); //大数大于Integer限制
            lexType = LexType.INTCON;
        }else if(curChar == '\''){   //处理字符常量
            tokenBuilder.append(curChar);
            curPos++;   //跳过起始单引号
            if(curPos < source.length()){
                char charValue = source.charAt(curPos);
                tokenBuilder.append(charValue);
                curPos++;
                if(charValue == '\\'){  //处理转义字符
                    if(curPos < source.length()){
                        tokenBuilder.append(source.charAt(curPos));
                        curPos++;
                    }
                }
                if (curPos < source.length())
                    tokenBuilder.append(source.charAt(curPos));
                token =tokenBuilder.toString();
                lexType = LexType.CHRCON;
                curPos++;
            }
        }else if(curChar == '\"'){   //处理字符串常量
            tokenBuilder.append(curChar);
            curPos++;   //先将第一个"获取
            while(curPos < source.length() && source.charAt(curPos) != '\"'){
                tokenBuilder.append(source.charAt(curPos));
                curPos++;
            }
            tokenBuilder.append(source.charAt(curPos));
            token = tokenBuilder.toString();
            lexType = LexType.STRCON;
            curPos++;   //跳出双引号区域
        }else if(curChar == '/'){ //处理注释
            curPos++;
            if(curPos < source.length() && source.charAt(curPos) == '/'){
                //第二个也是/，为单行注释
                while(curPos < source.length() && source.charAt(curPos) != '\n'){
                    //跳过注释内容
                    curPos++;
                }
                if(curPos < source.length()){   //得到'\n'或直接结束
                    curPos++;
                    lineNum++;  //单行注释末尾的\n
                }
            }else if(curPos < source.length() && source.charAt(curPos) == '*'){
                //读得/*，跨行注释
                curPos++;
                while(curPos < source.length()){
                    while(curPos < source.length() && source.charAt(curPos) != '*'){
                        if(source.charAt(curPos) == '\n')
                            lineNum++;
                        curPos++;
                    }
                    while(curPos < source.length() && source.charAt(curPos) == '*'){
                        curPos++;
                    }
                    if(curPos < source.length() && source.charAt(curPos) == '/'){
                        curPos++;
                        break;
                    }
                }
            }else{
                token = "/";
                lexType = identifyLexType(token);
                return true;
            }
            return instance.next();
        } else { //处理符号
            switch (curChar){
                case '>':
                    curPos++;
                    if(curPos < source.length() && source.charAt(curPos) == '='){
                        token = ">=";
                        curPos++;
                    }else{
                        token = ">";
                    }break;
                case '<':
                    curPos++;
                    if(curPos < source.length() && source.charAt(curPos) == '='){
                        token = "<=";
                        curPos++;
                    }else{
                        token = "<";
                    }break;
                case '=':
                    curPos++;
                    if(curPos < source.length() && source.charAt(curPos) == '='){
                        token = "==";
                        curPos++;
                    }else{
                        token = "=";
                    }break;
                case '!':
                    curPos++;
                    if(curPos < source.length() && source.charAt(curPos) == '='){
                        token = "!=";
                        curPos++;
                    }else{
                        token = "!";
                    }break;
                case '&':
                    curPos++;
                    if(curPos < source.length() && source.charAt(curPos) == '&'){
                        token = "&&";
                        curPos++;
                    }else{
                        token = "&";
                        isCorrect=false;
                        falseLineNumber=lineNum;
                        falseType='a';
                    }break;
                case '|':
                    curPos++;
                    if(curPos < source.length() && source.charAt(curPos) == '|'){
                        token = "||";
                        curPos++;
                    }else{
                        token = "|";
                        isCorrect=false;
                        falseLineNumber=lineNum;
                        falseType='a';
                    }break;
                default: token=String.valueOf(curChar);curPos++;break;
            }
            lexType = identifyLexType(token);
        }
        return true;
    }

    public String getToken(){    //获取读取的单词值
        return token;
    }
    public LexType getLexType(){  //获取读取的单词类型
        return lexType;
    }
    public int getLineNum(){
        return lineNum;
    }
    public int getNumber(){
        return number;
    }

    public boolean isCorrect(){
        return isCorrect;
    }

    public int getFalseLineNumber(){
        return falseLineNumber;
    }
    public char getFalseType(){
        return falseType;
    }

    public List<Token> getTokens() {
        return tokens;
    }

    private boolean isNonDigit(char curPos){
        if(curPos == '_' || (curPos >= 'a' && curPos <= 'z') || (curPos >= 'A' && curPos <= 'Z'))
            return true;
        else
            return false;
    }
    private LexType identifyLexType(String token){
        if(reserveWords.containsKey(token))
            return reserveWords.get(token); //保留字
        switch(token){
            case "!": return LexType.NOT;
            case "&&": return LexType.AND;
            case "||": return LexType.OR;
            case "+": return LexType.PLUS;
            case "-": return LexType.MINU;
            case "*": return LexType.MULT;
            case "/": return LexType.DIV;
            case "%": return LexType.MOD;
            case "<": return LexType.LSS;
            case "<=": return LexType.LEQ;
            case ">": return LexType.GRE;
            case ">=": return LexType.GEQ;
            case "==": return LexType.EQL;
            case "!=": return LexType.NEQ;
            case "=": return LexType.ASSIGN;
            case ";": return LexType.SEMICN;
            case ",": return LexType.COMMA;
            case "(": return LexType.LPARENT;
            case ")": return LexType.RPARENT;
            case "[": return LexType.LBRACK;
            case "]": return LexType.RBRACK;
            case "{": return LexType.LBRACE;
            case "}": return LexType.RBRACE;
            default: return LexType.IDENFR;
        }
    }
}