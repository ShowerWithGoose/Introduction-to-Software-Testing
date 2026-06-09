package frontend.Lexer;
import frontend.Token.Token;
import frontend.Token.TokenType;
import frontend.Wrong;


import java.io.*;
import java.util.ArrayList;



public class Lexer {
    public ArrayList<Token> tokens; //所有单词

    public int lineno; //行号
    private InputStream input; //输入流
    private String currentToken; //当前单词

    private TokenType tokenType; //当前单词类型

    private int currentChar; //当前字母
    private int lastChar; //上一个字母

    private int wrongLine;

    private ArrayList<Wrong> wrongs;



    public Lexer(InputStream in, ArrayList<Wrong> wrongs) {
        tokens = new ArrayList<>();
        lineno=1;
        input = in;
        currentToken = "";
        tokenType = null;
        currentChar = -1;
        lastChar = -1;
        wrongLine = -1;
        this.wrongs=wrongs;
        getToken();
        if(wrongLine!=-1){
            Wrong wrong = new Wrong("a",wrongLine);
            wrongs.add(wrong);
        }
    }

    //下一个字符
    public int getChar() {
        if (lastChar != -1) {
            currentChar = lastChar;
            lastChar = -1;
        } else {
            try {
                currentChar = input.read();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return currentChar;
    }

    //上一个字符
    public int ungetChar(){
        lastChar = currentChar;
        return lastChar;
    }

    //
    public void getToken() {

        while(getChar()!=-1){
            if(currentChar == '}'){
                currentToken += (char)currentChar;
            }else if(currentChar == '{'){
                currentToken += (char)currentChar;
            }else if(currentChar == ']'){
                currentToken += (char)currentChar;
            }else if(currentChar == '['){
                currentToken += (char)currentChar;
            }else if(currentChar == ')'){
                currentToken += (char)currentChar;
            }else if(currentChar == '('){
                currentToken += (char)currentChar;
            }else if(currentChar == ','){
                currentToken += (char)currentChar;
            }else if(currentChar == ';'){
                currentToken += (char)currentChar;
            }else if(currentChar == '='){
                currentToken += (char)currentChar;
                if(getChar() == '='){
                    currentToken += (char)currentChar;
                }else{
                    ungetChar();
                }
            }else if(currentChar == '!'){
                currentToken += (char)currentChar;
                if(getChar() == '='){
                    currentToken += (char)currentChar;
                }else {
                    ungetChar();
                }

            }else if(currentChar == '>'){
                currentToken += (char)currentChar;
                if(getChar() == '='){
                    currentToken += (char)currentChar;
                }else{
                    ungetChar();
                }
            }else if(currentChar == '<'){
                currentToken += (char)currentChar;
                if(getChar() == '='){
                    currentToken += (char)currentChar;
                }else{
                    ungetChar();
                }
            }else if(currentChar == '%'){
                currentToken += (char)currentChar;
            }else if(currentChar == '/'){
                currentToken += (char)currentChar;
                getChar();
                if(currentChar == '/'){
                    while(getChar()!='\n'){
                        if(currentChar == -1)
                            break;
                    }
                    lineno++;
                    currentToken = "";
                    continue;
                }else if(currentChar == '*'){
                    while(getChar()!=-1){
                        if(currentChar=='*'){
                            getChar();
                            if(currentChar=='/'){
                                break;
                            }else{
                                if(currentChar == '\n'){
                                    lineno ++;
                                }
                                ungetChar();
                            }
                        }else if(currentChar=='\n'){
                            lineno ++;
                        }
                    }
                    currentToken = "";
                    continue;
                }
                ungetChar();
            }else if(currentChar == '*'){
                currentToken += (char)currentChar;
            }else if(currentChar == '-'){
                currentToken += (char)currentChar;
            }else if(currentChar == '+'){
                currentToken += (char)currentChar;
            }else if(currentChar == '|'){
                currentToken += (char)currentChar;
                if(getChar() == '|'){
                    currentToken += (char)currentChar;
                }else{
                    //error
                    wrongLine = lineno;
                    tokenType = TokenType.OR;
                    ungetChar();
                }
            }else if(currentChar == '&'){
                currentToken += (char)currentChar;
                if(getChar() == '&'){
                    currentToken += (char)currentChar;
                }else{
                    //error
                    wrongLine = lineno;
                    tokenType = TokenType.AND;
                    ungetChar();
                }
            }else if(Character.isLetter(currentChar) || currentChar == '_'){
                currentToken += (char)currentChar;
                getChar();
                while(Character.isLetter(currentChar) || currentChar == '_' || Character.isDigit(currentChar)){
                    currentToken += (char)currentChar;
                    getChar();
                }
                ungetChar();
                if(TokenType.getType(currentToken)!=null){
                    //是保留字
                }else{
                    tokenType=TokenType.IDENFR;
                }

            }else if(Character.isDigit(currentChar)){
                currentToken += (char)currentChar;
                getChar();
                while(Character.isDigit(currentChar)){
                    currentToken += (char)currentChar;
                    getChar();
                }
                ungetChar();
                tokenType=TokenType.INTCON;

            }else if(currentChar == 34){
                currentToken += (char)currentChar;
                getChar();
                while((currentChar >= 32 && currentChar <=126)||(currentChar >=7 && currentChar <=12) || currentChar == 0){
                    if(currentChar == 34){
                        break;
                    }else if(currentChar == 92) {//转义字符
                        currentToken += (char)currentChar;
                        getChar();
                    }
                    currentToken += (char)currentChar;
                    getChar();
                }
                if(currentChar == 34){
                    currentToken += (char)currentChar;
                    tokenType=TokenType.STRCON;
                }else{
                    ungetChar();
                    //error
                }
            }else if(currentChar == 39){
                currentToken += (char)currentChar;
                getChar();
                while((currentChar >= 32 && currentChar <=126)||(currentChar >=7 && currentChar <=12) || currentChar == 0){
                    if(currentChar == 39){
                        break;
                    }else if(currentChar == 92) {//转义字符
                        currentToken += (char)currentChar;
                        getChar();
                    }
                    currentToken += (char)currentChar;
                    getChar();
                }
                if(currentChar == 39){
                    currentToken += (char)currentChar;
                    tokenType=TokenType.CHRCON;
                }else{
                    ungetChar();
                    //error
                }

            }else if(currentChar == '\n'){
                lineno++;
                continue;
            }else{
                continue;
            }
            if (tokenType==null)
                tokenType = tokenType.getType(currentToken);
            Token token = new Token(tokenType ,currentToken,lineno);
            tokens.add(token);
            //初始化
            currentToken="";
            tokenType=null;
        }
    }

    public void printTokens(String rightPath,String wrongPath) throws FileNotFoundException {
        if(wrongLine==-1){
            OutputStream out = new BufferedOutputStream(new FileOutputStream(rightPath));
            PrintWriter writer = new PrintWriter(out);
            for(Token token : tokens){
                writer.println(token.type.toString()+" "+token.content);
            }
            writer.flush();
            writer.close();
        }
    }

    //判断是否到达最终一行

};
