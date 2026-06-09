package frontend;

import java.io.*;
import java.util.*;

public class Lexer {
    private String source;
    private int curPos;
    private String token;
    private LexType lexType;
    private int lineNum;
    private int number;
    private boolean isCorrect = true;
    private Map<String, LexType> reserveWord = new HashMap<>();

    private List<String> tokenList = new ArrayList<>();
    private List<LexType> lexTypeList = new ArrayList<>();
    private List<Integer> lineNumList = new ArrayList<>();
    private List<Integer> errorLNList = new ArrayList<>();
    private List<Character> errorTypeList = new ArrayList<>();


    private char c;

    public static Lexer getInstance() throws IOException {
        Lexer instance = new Lexer();
        instance.init();
        return instance;
    }

    public void init() throws IOException {
        source = "";
        curPos = -1;
        token = "";
        lexType = null;
        lineNum = 1;
        number = 0;

        getSource();

        reserveWord.put("Ident", LexType.IDENFR);
        reserveWord.put("IntConst", LexType.INTCON);
        reserveWord.put("StringConst", LexType.STRCON);
        reserveWord.put("CharConst", LexType.CHRCON);
        reserveWord.put("main", LexType.MAINTK);
        reserveWord.put("const", LexType.CONSTTK);
        reserveWord.put("int", LexType.INTTK);
        reserveWord.put("char", LexType.CHARTK);
        reserveWord.put("break", LexType.BREAKTK);
        reserveWord.put("continue", LexType.CONTINUETK);
        reserveWord.put("if", LexType.IFTK);
        reserveWord.put("else", LexType.ELSETK);
        reserveWord.put("!", LexType.NOT);
        reserveWord.put("&&", LexType.AND);
        reserveWord.put("||", LexType.OR);
        reserveWord.put("for", LexType.FORTK);
        reserveWord.put("getint", LexType.GETINTTK);
        reserveWord.put("getchar", LexType.GETCHARTK);
        reserveWord.put("printf", LexType.PRINTFTK);
        reserveWord.put("return", LexType.RETURNTK);
        reserveWord.put("+", LexType.PLUS);
        reserveWord.put("-", LexType.MINU);
        reserveWord.put("void", LexType.VOIDTK);
        reserveWord.put("*", LexType.MULT);
        reserveWord.put("/", LexType.DIV);
        reserveWord.put("%", LexType.MOD);
        reserveWord.put("<", LexType.LSS);
        reserveWord.put("<=", LexType.LEQ);
        reserveWord.put(">", LexType.GRE);
        reserveWord.put(">=", LexType.GEQ);
        reserveWord.put("==", LexType.EQL);
        reserveWord.put("!=", LexType.NEQ);
        reserveWord.put("=", LexType.ASSIGN);
        reserveWord.put(";", LexType.SEMICN);
        reserveWord.put(",", LexType.COMMA);
        reserveWord.put("(", LexType.LPARENT);
        reserveWord.put(")", LexType.RPARENT);
        reserveWord.put("[", LexType.LBRACK);
        reserveWord.put("]", LexType.RBRACK);
        reserveWord.put("{", LexType.LBRACE);
        reserveWord.put("}", LexType.RBRACE);
    }

    private void getSource() throws IOException {
        String inputPath = "testfile.txt";
        FileReader reader = new FileReader(inputPath);
        int ch;
        while((ch = reader.read())!= -1){
            source += (char)ch;
        }
        //System.out.print(source);
        c = source.charAt(0);
    }

    public void next(){
        clearToken();
        while(isSpace() || isNewline() || isTab()){
            if(c == '\n'){
                lineNum++;
            }
            if(end()){
                return;
            }
            getchar();
        }
        //catToken();
        if(isLetter() || isUnderline()){
            while(isLetter() || isDigit() || isUnderline()){
                catToken();
                getchar();
            }
            retract();
            if(reserveWord.containsKey(token)){
                lexType = reserveWord.get(token);
            }else{
                lexType = LexType.IDENFR;
            }
        }
        else if(isDigit()){
            while(isDigit()){
                catToken();
                getchar();
            }
            retract();
            number = transNum();
            lexType = LexType.INTCON;
        }
        else if(isDQuotation()){
            do{
                catToken();
                getchar();
            }while(!isDQuotation());
            catToken();
            lexType = LexType.STRCON;
        }
        else if(isSQuotation()){
            do{
                catToken();
                getchar();
            }while(!isDQuotation());
            catToken();
            lexType = LexType.CHRCON;
        }
        else if(isDiv()){
            getchar();
            if(isStar()){
                do{
                    do{
                        getchar();
                    }while(!isStar());
                    do{
                        getchar();
                        if(isDiv()){
                            return;
                        }
                    }while(isStar());
                }while(!isStar());
            }
            else if(isDiv()){
                while(!isNewline()){
                    getchar();
                    if(end()){
                        return;
                    }
                }
                retract();
                return;
            }
            else{
                retract();
                catToken();
                lexType = LexType.DIV;
            }
        }
        else if(isCOP()){
            catToken();
            getchar();
            if(c == '='){
                catToken();
            }
            else {
                retract();
            }
            lexType = reserveWord.get(token);
        }
        else if(isLOP()){
            catToken();
            if(c == '!'){
                lexType = LexType.NOT;
            }
            else if(c == '&'){
                getchar();
                if(c != '&'){
                    token += '&';
                    lexType = LexType.AND;
                    errorProcess('a');
                    return;
                }else{
                    lexType = LexType.AND;
                    catToken();
                }

            }
            else if(c == '|'){
                getchar();
                if(c != '|'){
                    token += '|';
                    lexType = LexType.OR;
                    errorProcess('a');
                    return;
                }else{
                    catToken();
                    lexType = LexType.OR;
                }
            }
        }
        else if(isPR()){
            catToken();
            lexType = reserveWord.get(token);
        }
        else{
            catToken();
            lexType = reserveWord.get(token);
        }
        tokenListProcess();
    }

    private void clearToken(){
        token = "";
        getchar();
    }

    private void getchar(){
        if(curPos < source.length() - 1){
            c = source.charAt(++curPos);
        }
        else{
            c = source.charAt(curPos);
        }
    }

    private boolean isSpace(){
        return c == ' ' || c == '\r';
    }
    private boolean isNewline(){
//        if(c == '\n'){
//            lineNum++;
//        }
        return c == '\n';
    }
    private boolean isTab(){
        return c == '\t';
    }
    private boolean isLetter(){
        return Character.isLetter(c);
    }
    private boolean isDigit(){
        return Character.isDigit(c);
    }
    private boolean isUnderline(){
        return c == '_';
    }
    private void catToken(){
        token += c;
    }
    private void retract(){
        if(curPos > 0){
            c = source.charAt(--curPos);
        }
        else{
            c = source.charAt(curPos);
        }
    }
    private int transNum(){
        return Integer.parseInt(token);
    }
    private boolean isDQuotation(){
        return c == '\"';
    }
    private boolean isSQuotation(){
        return c == '\'';
    }
    private boolean isDiv(){
        return c == '/';
    }
    private boolean isStar(){
        return c =='*';
    }
    private boolean isCOP(){
        return "=<>!".indexOf(c) >= 0;
    }
    private boolean isLOP(){
        return "!&|".indexOf(c) >= 0;
    }
    private boolean isPR(){
        return "()[]{}".indexOf(c) >= 0;
    }
    public boolean end() {
        return curPos >= source.length() - 1;
    }

    public enum LexType {
        IDENFR, INTCON, STRCON, CHRCON, MAINTK, CONSTTK, INTTK, CHARTK, BREAKTK, CONTINUETK, IFTK,
        ELSETK, NOT, AND, OR, FORTK, GETINTTK, GETCHARTK, PRINTFTK, RETURNTK, PLUS, MINU,
        VOIDTK, MULT, DIV, MOD, LSS, LEQ, GRE, GEQ, EQL, NEQ, ASSIGN,
        SEMICN, COMMA, LPARENT, RPARENT, LBRACK, RBRACK, LBRACE, RBRACE
    }

    private void tokenListProcess(){
        tokenList.add(token);
        lexTypeList.add(lexType);
        lineNumList.add(lineNum);
    }

    private void errorProcess(char errorType){
        errorLNList.add(lineNum);
        errorTypeList.add(errorType);
        isCorrect = false;
    }
    public void output() throws IOException {
        int i;
        if(isCorrect){
            FileWriter lexerOutput = new FileWriter("lexer.txt");
            for(i = 0; i < tokenList.size(); i++){
                lexerOutput.write(lexTypeList.get(i) + " " + tokenList.get(i) + '\n');
                //System.out.print(lexTypeList.get(i) + " " + tokenList.get(i) + '\n');
            }
            lexerOutput.flush();
        }
        else{
            FileWriter errorOutput = new FileWriter("error.txt");
            for(i = 0; i < errorLNList.size(); i++){
                errorOutput.write(errorLNList.get(i) + " " + errorTypeList.get(i) + '\n');
            }
            errorOutput.flush();
        }
    }

}