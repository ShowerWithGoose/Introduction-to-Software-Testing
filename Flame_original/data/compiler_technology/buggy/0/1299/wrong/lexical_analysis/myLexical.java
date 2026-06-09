package lexical_analysis;

import java.io.IOException;
import java.util.ArrayList;
import fileController.fileController;
import saver.Saver;
import Error.MyError;

public class myLexical {
    private char c;
    private String token;
    private int nowLine;
    private boolean oneLineComment;
    private boolean multiLineComment;
    private boolean ifError;
    private ArrayList<Token> tokenList;
    private ArrayList<MyError> errorList;

    public myLexical() throws IOException{
        fileController.setRead("testfile.txt");
        this.token = "";
        this.nowLine = 1;
        this.oneLineComment = false;
        this.multiLineComment = false;
        this.tokenList = Saver.tokenList;
        this.errorList = Saver.ErrorList;
        getNewCh();
        lexicalAnalyzer();
    }
    private boolean isNowComment(){
        return oneLineComment || multiLineComment;
    }
    private void getNewCh() throws IOException{
        c = fileController.readAChar();
        if(c == '\n') nowLine += 1;
    }
    public void lexicalAnalyzer() throws IOException{
        while(c != '\uFFFF'){
            token = "";
            // 去除空白符号
            if(Character.isSpaceChar(c)){
                getNewCh();
            }
            // 除号或者注释
            else if(c == '/'){
                if(isNowComment()){
                    getNewCh();
                    continue;
                }
                token += c;
                getNewCh();
                if(c == '/'){
                    oneLineComment = true;
                    getNewCh();
                }
                else if(c == '*'){
                    multiLineComment = true;
                    getNewCh();
                }
                else{
                    tokenList.add(new Token("DIV", token, nowLine));
                }
            }
            // 乘号或者多行注释
            else if(c == '*'){
                token += c;
                getNewCh();
                if(multiLineComment){
                    if(c == '/') {
                        multiLineComment = false;
                        getNewCh();
                    }
                }
                else{
                    if(!isNowComment())
                        tokenList.add(new Token("MULT", token, nowLine));
                }
            }
            else if(c == '\n'){
                oneLineComment = false;
                getNewCh();
            }
            else if(isNowComment()){
                getNewCh();
            }
            // 标识符
            else if(Character.isLetter(c) || c == '_'){
                while(Character.isLetter(c) || Character.isDigit(c) || c == '_'){
                    token += c;
                    getNewCh();
                }
                String tempType = "IDENFR";
                if(KeyWord.keyWordMap.containsKey(token)){
                    tempType = KeyWord.keyWordMap.get(token);
                }
                tokenList.add(new Token(tempType, token, nowLine));
            }
            // 数字：必须先处理标识符再处理数字才能区分标识符和数
            else if(Character.isDigit(c)){
                while(Character.isDigit(c)){
                    token += c;
                    getNewCh();
                }
                tokenList.add(new Token("INTCON", token, nowLine));
            }
            else if(c == '"'){
                do {
                    token += c;
                    getNewCh();
                }while(c != '"' && c != '\n');
                if(c == '"') {
                    token += c;
                    getNewCh();
                }
                tokenList.add(new Token("STRCON", token, nowLine));
            }
            else if(c == '\''){
                token += c;
                getNewCh();
                token += c;
                getNewCh();
                token += c;
                getNewCh();
                tokenList.add(new Token("CHRCON", token, nowLine));
            }
            else if(c == '>' || c == '<' || c == '=' || c == '!'){
                token += c;
                getNewCh();
                if(c == '='){
                    token += c;
                    getNewCh();
                }
                String tempType = KeyWord.keyWordMap.get(token);
                tokenList.add(new Token(tempType, token, nowLine));
            }
            else if(c == '&' || c == '|'){
                char lastCh = c;
                token += c;
                getNewCh();
                if(c != lastCh){
                    this.ifError = true;
                    Saver.ifError = true;
                    errorList.add(new MyError('a', nowLine));
                }
                else{
                    String tempType = KeyWord.keyWordMap.get(token);
                    tokenList.add(new Token(tempType, token, nowLine));
                    getNewCh();
                }
            }
            else if(c == '+' || c == '-' || c == '%' || c == ';' || c == ','
                    || c == '{' || c == '}' || c == '[' || c == ']' || c == '(' || c == ')'){
                token += c;
                getNewCh();
                tokenList.add(new Token(KeyWord.keyWordMap.get(token), token, nowLine));
            }
            else{
                getNewCh();
            }
        }
        fileController.closeRead();
    }
    public void printLexicalRes() throws IOException {
        if(this.ifError){
            fileController.setWrite("error.txt");
            errorList.forEach(error -> fileController.printALine(error.errorInformation()));
        }
        else{
            fileController.setWrite("lexer.txt");
            tokenList.forEach(token -> fileController.printALine(token.tokenInformation()));
        }
        fileController.closeWrite();
    }
}
