package frontend;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

import Token.*;
import Error.*;
public class Lexer {
    private static Lexer onlyLexer;

    private Lexer(){}
    public static Lexer getInstance(){
        if(onlyLexer == null){
            onlyLexer = new Lexer();
        }
        return onlyLexer;
    }
    String fileContent;
    int character;
    String word;
    char letter;
    int lineNum;
    boolean success;
    ArrayList<Token> tokenList = new ArrayList<Token>();
    ArrayList<error> errorList = new ArrayList<error>();
    Map<String, TokenType> reservedWord = new HashMap<>(){
        {
            put("main", TokenType.MAINTK);
            put("const", TokenType.CONSTTK);
            put("int", TokenType.INTTK);
            put("char", TokenType.CHARTK);
            put("break", TokenType.BREAKTK);
            put("continue", TokenType.CONTINUETK);
            put("if", TokenType.IFTK);
            put("else", TokenType.ELSETK);
            put("for", TokenType.FORTK);
            put("getint", TokenType.GETINTTK);
            put("getchar", TokenType.GETCHARTK);
            put("printf", TokenType.PRINTFTK);
            put("return", TokenType.RETURNTK);
            put("void", TokenType.VOIDTK);
        }
    };
    public void handle(String filepath){
        init();
        readFileContent(filepath);
        int fileLen = fileContent.length();
        for(int i = 0; i < fileLen; i++){
            clearWord();
            letter = fileContent.charAt(i);
            char next_letter = (i + 1) < fileLen ? fileContent.charAt(i+1) : '\0';
            if(isSpace(letter) || isNewline(letter) || isTab(letter)){
                if(isNewline(letter)){
                    lineNum++;
                }
                continue;
            }
            else if(isLetter(letter) || isUnserScore(letter)){
                int j = i;
                for(j = i; j < fileLen; j++){
                    letter = fileContent.charAt(j);
                    if(isLetter(letter) || isDigit(letter) || isUnserScore(letter)){
                        catWord(letter);
                    }else {
                        break;
                    }
                }
                i = j-1;
                tokenList.add(new Token(reservedWord.getOrDefault(this.word, TokenType.IDENFR), this.word, this.lineNum));
            }
            else if(isDigit(letter)){
                int j = i;
                for(j = i; j < fileLen; j++){
                    letter = fileContent.charAt(j);
                    if(isDigit(letter)){
                        catWord(letter);
                    }else {
                        break;
                    }
                }
                i = j-1;
                tokenList.add(new Token(TokenType.INTCON, this.word, lineNum));
            }
            else if(isDoubleQuote(letter)){
                int j;
                catWord(letter);
                for(j = i+1; j < fileLen; j++){
                    letter = fileContent.charAt(j);
                    if(isDoubleQuote(letter)){
                        catWord(letter);
                        i = j;
                        break;
                    }
                    catWord(letter);
                }
                tokenList.add(new Token(TokenType.STRCON, this.word, lineNum));
            }
            else if(isQuote(letter)){
                catWord(letter);//单引号
                if(next_letter == '\\'){
                    letter = fileContent.charAt(i+1);
                    catWord(letter);//cat \

                    letter = fileContent.charAt(i+2);
                    catWord(letter);//cat char

                    letter = fileContent.charAt(i+3);
                    i = i+3;
//                    catWord(letter);//cat '
//                    tokenList.add(new Token(TokenType.CHRCON, this.word, lineNum));
                }else {
                    letter = fileContent.charAt(i+1);
                    catWord(letter);//char

                    letter = fileContent.charAt(i+2);
                    i = i+2;
                }
                if(isQuote(letter)){
                    catWord(letter);
                }
                tokenList.add(new Token(TokenType.CHRCON, this.word, lineNum));
            }
            else if(isNot(letter)){
                if(isEqu(next_letter)){
                    catWord(letter);
                    catWord(next_letter);
                    i++;
                    tokenList.add(new Token(TokenType.NEQ, this.word, this.lineNum));
                }else {
                    catWord(letter);
                    tokenList.add(new Token(TokenType.NOT, this.word, lineNum));
                }
            }
            else if(isAnd(letter)){
                if(isAnd(next_letter)){
                    catWord(letter);
                    catWord(next_letter);
                    i++;
                    tokenList.add(new Token(TokenType.AND, this.word, this.lineNum));
                }else {
                    //出现&错误符号
                    this.success = false;
                    errorList.add(new error('a', this.lineNum));
                    tokenList.add(new Token(TokenType.AND, "&", this.lineNum));
                }
            }
            else if(isOr(letter)){
                if(isOr(next_letter)){
                    catWord(letter);
                    catWord(next_letter);
                    i++;
                    tokenList.add(new Token(TokenType.OR, this.word, this.lineNum));
                }else {
                    //出现|符号
                    this.success = false;
                    errorList.add(new error('a', this.lineNum));
                    tokenList.add(new Token(TokenType.OR, "|", this.lineNum));
                }

            }
            else if(isPlus(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.PLUS, this.word, this.lineNum));
            }
            else if(isMinus(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.MINU, this.word, this.lineNum));
            }
            else if(isStar(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.MULT, this.word, this.lineNum));
            }
            else if(isDivi(letter)){
                if(isDivi(next_letter)){
                    //单行注释
                    int j = i + 1;
                    while(j < fileLen && fileContent.charAt(j) != '\n'){
                        j++;
                    }
                    i = j - 1;
                }
                else if(isStar(next_letter)){
                    //多行注释
                    int j = i + 2;
                    while(j < fileLen && !isStar(fileContent.charAt(j))){
                        //状态5
                        if(isNewline(fileContent.charAt(j))){
                            lineNum++;
                        }
                        j++;
                    }
                    while(j < fileLen && isStar(fileContent.charAt(j))){
                        //状态6
                        next_letter = (j + 1) < fileLen ? fileContent.charAt(j+1) : '\0';
                        if(isDivi(next_letter)){
                            //状态7
                            i = j + 1;
                            break;
                        }
                        if(!isStar(next_letter) && !isDivi(next_letter)){
                            j++;
                            while(j < fileLen && !isStar(fileContent.charAt(j))){
                                //从状态6回到状态5
                                if(isNewline(fileContent.charAt(j))){
                                    lineNum++;
                                }
                                j++;
                            }
                            //此时j是 *,为保证j++后依然能进入到状态6，j需要-1
                            j--;
                        }
                        j++;
                    }
                }
                else {
                    //除号
                    catWord(letter);
                    tokenList.add(new Token(TokenType.DIV, this.word, this.lineNum));
                }
            }
            else if(isMod(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.MOD, this.word, this.lineNum));
            }
            else if(isLess(letter)){
                if(isEqu(next_letter)){
                    catWord(letter);
                    catWord(next_letter);
                    i++;
                    tokenList.add(new Token(TokenType.LEQ, this.word, this.lineNum));
                }else {
                    catWord(letter);
                    tokenList.add(new Token(TokenType.LSS, this.word, this.lineNum));
                }
            }
            else if(isGre(letter)){
                if(isEqu(next_letter)){
                    catWord(letter);
                    catWord(next_letter);
                    i++;
                    tokenList.add(new Token(TokenType.GEQ, this.word, this.lineNum));
                }else {
                    catWord((letter));
                    tokenList.add(new Token(TokenType.GRE, this.word, this.lineNum));
                }
            }
            else if(isEqu(letter)){
                if(isEqu(next_letter)){
                    catWord(letter);
                    catWord(next_letter);
                    i++;
                    tokenList.add(new Token(TokenType.EQL, this.word, this.lineNum));
                }else {
                    catWord(letter);
                    tokenList.add(new Token(TokenType.ASSIGN, this.word, this.lineNum));
                }
            }
            else if(isSemi(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.SEMICN, this.word, this.lineNum));
            }
            else if(isComma(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.COMMA, this.word, this.lineNum));
            }
            else if(isLpar(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.LPARENT, this.word, this.lineNum));
            }
            else if(isRpar(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.RPARENT, this.word, this.lineNum));
            }
            else if(isLbrack(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.LBRACK, this.word, this.lineNum));
            }
            else if(isRbrack(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.RBRACK, this.word, this.lineNum));
            }
            else if(isLbrace(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.LBRACE, this.word, this.lineNum));
            }
            else if(isRbrace(letter)){
                catWord(letter);
                tokenList.add(new Token(TokenType.RBRACE, this.word, this.lineNum));
            }
        }

//        tokenList.add(new Token(TokenType.TK_EOF, "", this.lineNum));

        if(success){
            printFile("lexer.txt", success);
        }else {
            printFile("error.txt", success);
        }

    }

    public ArrayList<Token> getTokenList(){
        return this.tokenList;
    }

    void init(){
        this.fileContent = "";
        this.character = 0;
        this.word = "";
        this.letter = '\0';
        this.lineNum = 1;
        this.success = true;
    }

    void printFile(String filepath, boolean success){
        if(success){
            try{
                BufferedWriter writer = new BufferedWriter(new FileWriter(filepath));
                for(Token token : tokenList){
                    //
//                    System.out.print(token.toString());
                    //
                    writer.write(token.toString());
                }
                writer.close();
            }catch (IOException err){
                System.out.print(err);
            }
        }else {
            try{
                BufferedWriter writer = new BufferedWriter(new FileWriter(filepath));
                for(error err : errorList){
                    //
//                    System.out.print(err.toString());
                    //
                    writer.write(err.toString());
                }
                writer.close();
            }catch (IOException err){
                System.out.println(err);
            }
        }

    }
    void readFileContent(String filepath){
        try{
            BufferedReader reader = new BufferedReader(new FileReader(filepath));
            StringBuffer sbf = new StringBuffer();
            while((character = reader.read()) != -1) {
                sbf.append((char)character);
            }
            this.fileContent = sbf.toString();
            reader.close();
        }catch (IOException err){
            System.out.println(err);
        }
    }

    boolean isSpace(char c){
        return c == ' ';
    }

    boolean isNewline(char c){
        return c == '\n';
    }

    boolean isTab(char c){
        return c == '\t';
    }

    boolean isLetter(char c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    }

    boolean isDigit(char c){
        return (c >= '0' && c <= '9');
    }

    boolean isComma(char c){
        return c == ',';
    }

    boolean isSemi(char c){
        return c == ';';
    }

    boolean isEqu(char c){
        return c == '=';
    }

    boolean isPlus(char c){
        return c == '+';
    }

    boolean isMinus(char c){
        return c == '-';
    }

    boolean isDivi(char c){
        return c == '/';
    }

    boolean isStar(char c){
        return c == '*';
    }

    boolean isLpar(char c){
        return c == '(';
    }

    boolean isRpar(char c){
        return c == ')';
    }

    boolean isLbrack(char c){
        return c == '[';
    }

    boolean isRbrack(char c){
        return c ==']';
    }

    boolean isLbrace(char c){
        return c == '{';
    }

    boolean isRbrace(char c){
        return c == '}';
    }



    boolean isUnserScore(char c){
        return c == '_';
    }

    boolean isNot(char c){
        return c == '!';
    }

    boolean isDoubleQuote(char c){
        return c == '\"';
    }

    boolean isQuote(char c){
        return c == '\'';
    }

    boolean isAnd(char c){
        return c == '&';
    }

    boolean isOr(char c){
        return c == '|';
    }

    boolean isMod(char c){
        return c == '%';
    }

    boolean isLess(char c){
        return c == '<';
    }

    boolean isGre(char c){
        return c == '>';
    }

    void catWord(char c){
        this.word = this.word + c;
    }

    void clearWord(){
        this.word = "";
    }





}
