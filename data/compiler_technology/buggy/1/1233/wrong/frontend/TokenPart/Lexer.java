package frontend.TokenPart;

import frontend.ErrorPart.Error;
import frontend.ErrorPart.ErrorList;
import frontend.ErrorPart.ErrorType;
import frontend.ParserPart.CompileUnit;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Lexer {
    private ArrayList<String> lines;//input处理的结果
    private String inputLine;//输入
    private TokenList tokenList;
    private int lineNum;//标识token第几行
    private int positionNum;//用来记录处在inputLine中的位置
    private Boolean isFail;//表示是否语法出错
    private ArrayList<Integer> failLine;//记录错误的行号
    private CompileUnit compileUnit;//用于最后输出
    public Lexer(ArrayList<String> lines,String inputLine){
        this.lines = lines;
        this.inputLine = inputLine;
        tokenList = new TokenList();
        lineNum = 1;
        positionNum = 0;
        isFail = false;
        failLine = new ArrayList<>();
        compileUnit = null;
        initProcess();
    }
    public void initProcess(){
        //遍历整个inputLine然后把各种token装入我们的tokenList中
        while (positionNum < inputLine.length()){
            //拿到了curToken
            char curToken = inputLine.charAt(positionNum);
            //进行分类
            if (isBegin(curToken)){
                //如果是字母类型的开头，需要分类
                String temLetter = getLetter();
                sortLetter(temLetter);
            } else if (Character.isDigit(curToken)) {
                //如果是数字类型的开头
                String temNum = getNumber();
                Token token = new Token(TokenType.INTCON,temNum,lineNum);
                tokenList.addToken(token);
            } else if (curToken == '"') {
                //如果是双引号开头，需要匹配双引号
                positionNum++;
                StringBuilder sb = new StringBuilder();
                sb.append('"');
                while (inputLine.charAt(positionNum) != '"' || inputLine.charAt(positionNum - 1) == '\\'){
                    sb.append(inputLine.charAt(positionNum));
                    positionNum++;
                }
                sb.append('"');
                positionNum++;
                Token token = new Token(TokenType.STRCON, sb.toString(), lineNum);
                tokenList.addToken(token);
            } else if (curToken == '\'') {
                //如果是单引号开头，需要匹配单引号
                positionNum++;
                StringBuilder sb = new StringBuilder();
                sb.append('\'');
                while (inputLine.charAt(positionNum) != '\'' || inputLine.charAt(positionNum - 1) == '\\'){
                    sb.append(inputLine.charAt(positionNum));
                    positionNum++;
                }
                sb.append('\'');
                positionNum++;
                Token token = new Token(TokenType.CHRCON, sb.toString(), lineNum);
                tokenList.addToken(token);
            } else if (curToken == '!') {
                //如果是感叹号开头，需要分类来区分!和!=
                positionNum++;
                char nextToken = inputLine.charAt(positionNum);
                if (nextToken == '='){
                    Token token = new Token(TokenType.NEQ,"!=",lineNum);
                    tokenList.addToken(token);
                    positionNum++;
                }else {
                    Token token = new Token(TokenType.NOT,"!",lineNum);
                    tokenList.addToken(token);
                }
            } else if (curToken == '&') {
                //如果是和符号开头，需要分类来区分&&和error
                positionNum++;
                char nextToken = inputLine.charAt(positionNum);
                if (nextToken == '&'){
                    Token token = new Token(TokenType.AND,"&&",lineNum);
                    tokenList.addToken(token);
                    positionNum++;
                }else {
                    isFail = true;
                    failLine.add(lineNum);
                    Error error = new Error(ErrorType.a,lineNum);
                    ErrorList.addError(error);
                }
            } else if (curToken == '|') {
                //如果是或符号开头，需要分类来区分||和error
                positionNum++;
                char nextToken = inputLine.charAt(positionNum);
                if (nextToken == '|'){
                    Token token = new Token(TokenType.OR,"||",lineNum);
                    tokenList.addToken(token);
                    positionNum++;
                }else {
                    isFail = true;
                    failLine.add(lineNum);
                    Error error = new Error(ErrorType.a,lineNum);
                    ErrorList.addError(error);
                }
            } else if (curToken == '+') {
                //如果是加号开头
                Token token = new Token(TokenType.PLUS,"+",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '-') {
                //如果是减号开头
                Token token = new Token(TokenType.MINU,"-",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '*') {
                //如果是乘号开头
                Token token = new Token(TokenType.MULT,"*",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '/') {
                //如果是除号开头，需要分类
                positionNum++;
                char nextToken = inputLine.charAt(positionNum);
                if (nextToken == '/'){
                    //单行注释
                    positionNum++;
                    while (inputLine.charAt(positionNum) != '\n'){
                        positionNum++;
                    }
                    //lineNum++;
                } else if (nextToken == '*') {
                    //多行注释
                    positionNum++;
                    while (inputLine.charAt(positionNum) != '*' || inputLine.charAt(positionNum + 1) != '/'){
                        if (inputLine.charAt(positionNum) == '\n'){
                            lineNum++;
                        }
                        positionNum++;
                    }
                    positionNum = positionNum + 2;
                } else {
                    //除号
                    Token token = new Token(TokenType.DIV,"/",lineNum);
                    tokenList.addToken(token);
                }
            } else if (curToken == '%') {
                //如果是除余号开头
                Token token = new Token(TokenType.MOD,"%",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '<') {
                //如果是小于开头，需要分类区分<和<=
                positionNum++;
                char nextToken = inputLine.charAt(positionNum);
                if (nextToken == '='){
                    Token token = new Token(TokenType.LEQ,"<=",lineNum);
                    tokenList.addToken(token);
                    positionNum++;
                }else {
                    Token token = new Token(TokenType.LSS,"<",lineNum);
                    tokenList.addToken(token);
                }
            } else if (curToken == '>') {
                //如果是大于开头，需要分类区分>和>=
                positionNum++;
                char nextToken = inputLine.charAt(positionNum);
                if (nextToken == '='){
                    Token token = new Token(TokenType.GEQ,">=",lineNum);
                    tokenList.addToken(token);
                    positionNum++;
                }else {
                    Token token = new Token(TokenType.GRE,">",lineNum);
                    tokenList.addToken(token);
                }
            } else if (curToken == '=') {
                //如果是等于开头，需要分类区分=和==
                positionNum++;
                char nextToken = inputLine.charAt(positionNum);
                if (nextToken == '='){
                    Token token = new Token(TokenType.EQL,"==",lineNum);
                    tokenList.addToken(token);
                    positionNum++;
                }else {
                    Token token = new Token(TokenType.ASSIGN,"=",lineNum);
                    tokenList.addToken(token);
                }
            } else if (curToken == ';') {
                //如果是分号开头
                Token token = new Token(TokenType.SEMICN,";",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == ',') {
                //如果是逗号开头
                Token token = new Token(TokenType.COMMA,",",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '(') {
                //如果是左扩号开头，需要匹配右括号
                Token token = new Token(TokenType.LPARENT,"(",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == ')') {
                //如果是左扩号开头，需要匹配右括号
                Token token = new Token(TokenType.RPARENT,")",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '[') {
                //如果是左方扩号开头，需要匹配右方括号
                Token token = new Token(TokenType.LBRACK,"[",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == ']') {
                //如果是左扩号开头，需要匹配右括号
                Token token = new Token(TokenType.RBRACK,"]",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '{') {
                //如果是左大扩号开头，需要匹配右大括号
                Token token = new Token(TokenType.LBRACE,"{",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '}') {
                //如果是左扩号开头，需要匹配右括号
                Token token = new Token(TokenType.RBRACE,"}",lineNum);
                tokenList.addToken(token);
                positionNum++;
            } else if (curToken == '\n') {
                //如果是换行符
                lineNum++;
                positionNum++;
            }else {
                //如果是空格
                positionNum++;
            }
        }

    }
    public String getNumber(){
        //用来获取数字
        StringBuilder sb = new StringBuilder();
        while (positionNum < inputLine.length() && Character.isDigit(inputLine.charAt(positionNum))){
            sb.append(inputLine.charAt(positionNum));
            positionNum++;
        }
        return sb.toString();
    }
    public String getLetter(){
        //用来获取字母
        StringBuilder sb = new StringBuilder();
        while (positionNum < inputLine.length() && isBegin(inputLine.charAt(positionNum))){
            sb.append(inputLine.charAt(positionNum));
            positionNum++;
        }
        return sb.toString();
    }
    public String getMid(){
        //用来获取Ident中间部分
        StringBuilder sb = new StringBuilder();
        while (positionNum < inputLine.length() && isMid(inputLine.charAt(positionNum))){
            sb.append(inputLine.charAt(positionNum));
            positionNum++;
        }
        return sb.toString();
    }
    public void sortLetter(String letter){
        if (letter.equals("main")){
            Token token = new Token(TokenType.MAINTK,"main",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("const")) {
            Token token = new Token(TokenType.CONSTTK,"const",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("int")) {
            Token token = new Token(TokenType.INTTK,"int",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("char")) {
            Token token = new Token(TokenType.CHARTK,"char",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("break")) {
            Token token = new Token(TokenType.BREAKTK,"break",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("continue")) {
            Token token = new Token(TokenType.CONTINUETK,"continue",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("if")) {
            Token token = new Token(TokenType.IFTK,"if",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("else")) {
            Token token = new Token(TokenType.ELSETK,"else",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("for")) {
            Token token = new Token(TokenType.FORTK,"for",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("getint")) {
            Token token = new Token(TokenType.GETINTTK,"getint",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("getchar")) {
            Token token = new Token(TokenType.GETCHARTK,"getchar",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("printf")) {
            Token token = new Token(TokenType.PRINTFTK,"printf",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("return")) {
            Token token = new Token(TokenType.RETURNTK,"return",lineNum);
            tokenList.addToken(token);
        } else if (letter.equals("void")) {
            Token token = new Token(TokenType.VOIDTK,"void",lineNum);
            tokenList.addToken(token);
        }else {
            //Letter属于Ident，需要匹配后面是否有数字
            String temNum="";
            if (isMid(inputLine.charAt(positionNum))){
                temNum = getMid();
            }
            Token token = new Token(TokenType.IDENFR,letter+temNum,lineNum);
            tokenList.addToken(token);
        }
    }
    public void printResult(){
        //先判断是否是错误的
        if (ErrorList.hasError()){
            //结果是错误的
                try (PrintWriter writer = new PrintWriter("error.txt")) {
                    writer.print(ErrorList.finalOut());
                } catch (IOException e) {
                    e.printStackTrace();
                }
        }else {
            //结果是正确的
                try (PrintWriter writer = new PrintWriter("parser.txt")) {
                    writer.print(compileUnit.toString());
                } catch (IOException e) {
                    e.printStackTrace();
                }
        }
    }
    public boolean isBegin(Character character){
        return Character.isLetter(character) | (character == '_');
    }
    public boolean isMid(Character character){
        return Character.isLetter(character) | (character == '_') | Character.isDigit(character);
    }
    public TokenList getTokenList(){
        return tokenList;
    }
    public void setCompileUnit(CompileUnit compileUnit){
        this.compileUnit = compileUnit;
    }
}
