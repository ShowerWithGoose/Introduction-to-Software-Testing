package frontend.lexer;

import java.io.*;
import java.util.ArrayList;

public class TokenLexer {
    private String input;
    private InputStream inputStream;
    private TokenList tokenList;
    private ArrayList<String> lines;
    private int lineNum;
    private int location;
    private int columnNum;

    public TokenLexer(InputStream inputStream) {
        this.inputStream = inputStream;
        this.tokenList = new TokenList();
        this.lines = new ArrayList<>();
        this.lineNum = 0;
        this.columnNum = 0;
        this.location = 0;
        this.input = "";
        buildTokenList();
    }
    public void buildTokenList(){
        buildLines();//其实是build_input
        /*while (lineNum < lines.size()) {
            Token token = getNextToken();
            if(token.getType() == TokenType.END) {
                break;
            }
            tokenList.addToken(token);
        }*/
        while (this.location < input.length()) {
            if(input.charAt(location) == '\n'){
                lineNum++;
                location++;
            } else if(Character.isLetter(input.charAt(location)) ||
                    input.charAt(location) == '_'){
                //变量以及各种关键字
                StringBuilder sb = new StringBuilder();
                //location已经是下一个不属于该单词的字符位置
                do {
                    sb.append(input.charAt(location));
                    location++;
                } while (Character.isLetter(input.charAt(location)) ||
                        input.charAt(location) == '_' ||
                        Character.isDigit(input.charAt(location)));
                Token token = getWordToken(sb);//IDENT && 各种字母开头的保留字
                this.tokenList.addToken(token);

            } else if(Character.isDigit(input.charAt(location))) {
                //数字
                StringBuilder sb = new StringBuilder();
                //location已经是下一个不属于该单词的字符位置
                do {
                    sb.append(input.charAt(location));
                    location++;
                } while (Character.isDigit(input.charAt(location)));
                String string = sb.toString();
                Token token = new Token(TokenType.INTCON,lineNum+1,string);
                this.tokenList.addToken(token);
            } else if(input.charAt(location) == '"') {
                //字符串
                StringBuilder sb = new StringBuilder();
                //location已经是下一个不属于该单词的字符位置
                do {
                    sb.append(input.charAt(location));
                    location++;
                } while (input.charAt(location) != '"' || input.charAt(location - 1) == '\\');
                sb.append(input.charAt(location));
                location++;

                String string = sb.toString();
                Token token = new Token(TokenType.STRCON,lineNum+1,string);
                this.tokenList.addToken(token);
            } else if(input.charAt(location) == '\'') {
                //字符常量
                StringBuilder sb = new StringBuilder();
                //location已经是下一个不属于该单词的字符位置
                do {
                    sb.append(input.charAt(location));
                    location++;
                } while (input.charAt(location) != '\'' || input.charAt(location - 1) == '\\');
                sb.append(input.charAt(location));
                location++;

                String string = sb.toString();
                Token token = new Token(TokenType.CHRCON,lineNum+1,string);
                this.tokenList.addToken(token);

            } else if (input.charAt(location) == '!') {
                location++;
                if (input.charAt(location) == '=') {
                    location++;
                    Token token = new Token(TokenType.NEQ,lineNum+1,"!=");
                    this.tokenList.addToken(token);
                } else {
                    Token token = new Token(TokenType.NOT,lineNum+1,"!");
                    this.tokenList.addToken(token);
                }
            } else if (input.charAt(location) == '&') {
                location++;
                if (input.charAt(location) == '&') {
                    location++;
                    Token token = new Token(TokenType.AND,lineNum+1,"&&");
                    this.tokenList.addToken(token);
                } else {
                    Token token = new Token(TokenType.AND,lineNum+1,"&");
                    this.tokenList.addToken(token);
                    this.tokenList.addError(lineNum + 1);
                }
            } else if (input.charAt(location) == '|') {
                location++;
                if (input.charAt(location) == '|') {
                    location++;
                    Token token = new Token(TokenType.OR,lineNum+1,"||");
                    this.tokenList.addToken(token);
                } else {
                    Token token = new Token(TokenType.OR,lineNum+1,"|");
                    this.tokenList.addToken(token);
                    this.tokenList.addError(lineNum + 1);
                }
            } else if (input.charAt(location) == '+') {
                location++;
                Token token = new Token(TokenType.PLUS,lineNum+1,"+");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '-') {
                location++;
                Token token = new Token(TokenType.MINU,lineNum+1,"-");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '*') {
                location++;
                Token token = new Token(TokenType.MULT,lineNum+1,"*");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '/') {
                location++;
                Token token = new Token(TokenType.DIV,lineNum+1,"/");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '%') {
                location++;
                Token token = new Token(TokenType.MOD,lineNum+1,"%");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '<') {
                location++;
                if (input.charAt(location) == '=') {
                    location++;
                    Token token = new Token(TokenType.LEQ,lineNum+1,"<=");
                    this.tokenList.addToken(token);
                } else {
                    Token token = new Token(TokenType.LSS,lineNum+1,"<");
                    this.tokenList.addToken(token);
                }
            } else if (input.charAt(location) == '>') {
                location++;
                if (input.charAt(location) == '=') {
                    location++;
                    Token token = new Token(TokenType.GEQ,lineNum+1,">=");
                    this.tokenList.addToken(token);
                } else {
                    Token token = new Token(TokenType.GRE,lineNum+1,">");
                    this.tokenList.addToken(token);
                }
            }  else if (input.charAt(location) == '=') {
                location++;
                if (input.charAt(location) == '=') {
                    location++;
                    Token token = new Token(TokenType.EQL,lineNum+1,"==");
                    this.tokenList.addToken(token);
                } else {
                    Token token = new Token(TokenType.ASSIGN,lineNum+1,"=");
                    this.tokenList.addToken(token);
                }
            } else if (input.charAt(location) == ';') { //!= 在!里判断过了
                location++;
                Token token = new Token(TokenType.SEMICN,lineNum+1,";");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == ',') {
                location++;
                Token token = new Token(TokenType.COMMA,lineNum+1,",");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '(') {
                location++;
                Token token = new Token(TokenType.LPARENT,lineNum+1,"(");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == ')') {
                location++;
                Token token = new Token(TokenType.RPARENT,lineNum+1,")");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '[') {
                location++;
                Token token = new Token(TokenType.LBRACK,lineNum+1,"[");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == ']') {
                location++;
                Token token = new Token(TokenType.RBRACK,lineNum+1,"]");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '{') {
                location++;
                Token token = new Token(TokenType.LBRACE,lineNum+1,"{");
                this.tokenList.addToken(token);
            } else if (input.charAt(location) == '}') {
                location++;
                Token token = new Token(TokenType.RBRACE,lineNum+1,"}");
                this.tokenList.addToken(token);
            }


            else{//跳过其余空白符
                location++;
                //....
            }
        }
    }

    private Token getWordToken(StringBuilder sb) {
        String string = sb.toString();
        Token token;
        if(string.equals("main")){
            token = new Token(TokenType.MAINTK,lineNum+1,string);
        } else if(string.equals("const")){
            token = new Token(TokenType.CONSTTK,lineNum+1,string);
        } else if(string.equals("int")){
            token = new Token(TokenType.INTTK,lineNum+1,string);
        } else if(string.equals("char")){
            token = new Token(TokenType.CHARTK,lineNum+1,string);
        } else if(string.equals("break")){
            token = new Token(TokenType.BREAKTK,lineNum+1,string);
        } else if(string.equals("continue")){
            token = new Token(TokenType.CONTINUETK,lineNum+1,string);
        } else if(string.equals("if")){
            token = new Token(TokenType.IFTK,lineNum+1,string);
        } else if(string.equals("else")){
            token = new Token(TokenType.ELSETK,lineNum+1,string);
        } else if(string.equals("for")){
            token = new Token(TokenType.FORTK,lineNum+1,string);
        } else if(string.equals("getint")){
            token = new Token(TokenType.GETINTTK,lineNum+1,string);
        } else if(string.equals("getchar")){
            token = new Token(TokenType.GETCHARTK,lineNum+1,string);
        } else if(string.equals("printf")){
            token = new Token(TokenType.PRINTFTK,lineNum+1,string);
        } else if(string.equals("return")){
            token = new Token(TokenType.RETURNTK,lineNum+1,string);
        } else if(string.equals("void")){
            token = new Token(TokenType.VOIDTK,lineNum+1,string);
        } else{
            token = new Token(TokenType.IDENFR,lineNum+1,string);
        }
        return token;
    }

    public void buildLines(){
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(this.inputStream));
        StringBuilder sb = new StringBuilder();
        String line;
        while (true) {
            try {
                line = bufferedReader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            if(line == null){
                break;
            }
            sb.append(line).append("\n");
            this.lines.add(line);
        }
        this.input = sb.toString();
    }

    public TokenList getTokenList() {
        return tokenList;
    }
}
