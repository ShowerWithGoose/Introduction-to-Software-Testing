import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class Lexer {
    static HashMap<String, String> reservedWordsMap = new HashMap<>();
    static HashMap<String, String> signMap = new HashMap<>();
    static List<Token> tokens;
    static List<ErrorToken> errorTokens;
    static BufferedReader source;
    static int pos;
    static int lineno;
    static String storage;
    static char[] content;
    static Token currentToken;
    static ErrorToken currentErrorToken;
    static boolean currentAnnotation;
    static boolean annotationState;
    static char p;

    private Lexer(){
        initialReservedWords();
        initialSignMap();
        tokens = new ArrayList<>();
        errorTokens = new ArrayList<>();
        pos = 0;
        lineno = 0;
        storage = null;
        content = new char[1024];
        currentAnnotation = false;
        annotationState = false;
    }

    private static class LexerHolder{
        private static final Lexer INSTANCE = new Lexer();
    }

    public static Lexer getInstance(){
        return LexerHolder.INSTANCE;
    }

    public static void init(BufferedReader source) {
        Lexer.source = source;
    }

    public static int read() throws IOException {
        pos++;
        if(storage==null || pos >= storage.length()){
            readLine();
        }
        if(storage==null){
            //读到文件结束
            pos = 0;
            lineno = 0;
            return -1;
        }
        if(storage.isEmpty()){
            return read();
        }
        p = storage.charAt(pos);
        if(checkSign(p)){
            if (currentAnnotation){
                readLine();
                pos--;
                currentAnnotation = false;
                return read();
            }
            else if(annotationState){
                annotationProcess();
                return read();
            }
            return 1;
        }
        if(checkInt(p)){
            return 1;
        }
        if(checkString(p)){
            return 1;
        }
        if(checkChar(p)){
            return 1;
        }
        if(checkIdent(p)){
            return 1;
        }
        return read();
    }

    public static void putToken(){
        tokens.add(currentToken);
    }

    static void readLine() throws IOException {
        pos = 0;
        lineno++;
        storage = source.readLine();
    }

    static boolean checkSign(char p) throws IOException {
        String s = String.valueOf(p);
        if(signMap.containsKey(s) || p=='&' || p=='|'){
            content[0]=p;
            pos++;
            if(pos>=storage.length()){
                pos--;
                currentToken = new Token(Token.TokenType.fromValue(signMap.get(String.valueOf(p))),String.valueOf(p),lineno);
                Arrays.fill(content,'\u0000');
                return true;
            }
            content[1]=storage.charAt(pos);
            if(checkSign(content)){
                currentToken = new Token(Token.TokenType.fromValue(signMap.get(turnString(content))),turnString(content),lineno);
            }
            else {
                pos--;
                if(checkAnnotation(content)){
                    return true;
                }
                if(errorACheck(p)){
                    Compiler.errorExists = true;
                    currentErrorToken = new ErrorToken(ErrorToken.ErrorTokenType.IllegalSign,String.valueOf(p),lineno);
                    errorTokens.add(currentErrorToken);
                }
                currentToken = new Token(Token.TokenType.fromValue(signMap.get(String.valueOf(p))),String.valueOf(p),lineno);
            }
            Arrays.fill(content,'\u0000');
            return true;
        }
        Arrays.fill(content,'\u0000');
        return false;
    }

    static boolean checkSign(char[] c){
        String s = turnString(c);
        return signMap.containsKey(s);
    }


    private static boolean checkInt(char p) {
        if(isDigit(p)){
            content[0]=p;
            int i = 1;
            while(i<1023){
                pos++;
                p = storage.charAt(pos);
                if(isDigit(p)){
                    content[i]=p;
                    i++;
                }
                else{
                    pos--;
                    break;
                }
            }
            currentToken = new Token(Token.TokenType.IntConst,turnString(content),lineno);
            Arrays.fill(content,'\u0000');
            return true;
        }
        Arrays.fill(content,'\u0000');
        return false;
    }

    private static boolean checkString(char p) {
        if(p=='\"'){
            content[0]=p;
            int i = 1;
            while(i<1023){
                pos++;
                p = storage.charAt(pos);
                content[i]=p;
                if(p!='\"'){
                    i++;
                }
                else{
                    break;
                }
            }
            currentToken = new Token(Token.TokenType.StringConst,turnString(content),lineno);
            Arrays.fill(content,'\u0000');
            return true;
        }
        Arrays.fill(content,'\u0000');
        return false;
    }

    private static boolean checkChar(char p) {
        if(p=='\''){
            content[0]=p;
            pos++;
            p = storage.charAt(pos);
            content[1]=p;
            if(p=='\\'){
                pos++;
                p = storage.charAt(pos);
                content[2]=p;
                pos++;
                p = storage.charAt(pos);
                content[3]=p;
            }
            else {
                pos++;
                p = storage.charAt(pos);
                content[2]=p;
            }
            currentToken = new Token(Token.TokenType.CharConst,turnString(content),lineno);
            Arrays.fill(content,'\u0000');
            return true;
        }
        Arrays.fill(content,'\u0000');
        return false;
    }

    private static boolean checkIdent(char p) {
        if(isIdentifierNondigit(p)){
            content[0]=p;
            int i = 1;
            while(i<1023){
                pos++;
                if(pos >= storage.length()){
                    pos--;
                    break;
                }
                p = storage.charAt(pos);
                if(isIdentifier(p)){
                    content[i]=p;
                    i++;
                }
                else{
                    pos--;
                    break;
                }
            }
            if(reservedWordsMap.containsKey(turnString(content))){
                currentToken = new Token(Token.TokenType.fromValue(reservedWordsMap.get(turnString(content))),turnString(content),lineno);
            }
            else{
                currentToken = new Token(Token.TokenType.Ident,turnString(content),lineno);
            }
            Arrays.fill(content,'\u0000');
            return true;
        }
        Arrays.fill(content,'\u0000');
        return false;
    }

    private static boolean checkAnnotation(char[] c){
        if(c[0]=='/'){
            if(c[1]=='/'){
                currentAnnotation = true;
                return true;
            }
            else if(c[1]=='*'){
                annotationState = true;
                return true;
            }
            return false;
        }
        return false;
    }

    private static void annotationProcess() throws IOException {
        while(annotationState){
            pos++;
            if(storage==null || pos >= storage.length()){
                readLine();
            }
            if(storage==null){
                //读到文件结束
                pos = 0;
                lineno = 0;
                return;
            }
            p = storage.charAt(pos);
            if(p == '*'){
                pos++;
                if(pos >= storage.length()){
                    readLine();
                }
                else{
                    p = storage.charAt(pos);
                    if(p == '/'){
                        annotationState = false;
                    }
                    else {
                        pos--;
                    }
                }
            }
        }
        return;
    }

    private static boolean isIdentifierNondigit(char p) {
        return isAlphaBeta(p) || p == '_';
    }

    private static boolean isIdentifier(char p) {
        return isAlphaBeta(p) || p == '_' || isDigit(p);
    }

    private static boolean isDigit(char p) {
        return '0' <= p && p <= '9';
    }

    private static boolean isAlphaBeta(char p) {
        return 'a' <= p && p <= 'z' || 'A' <= p && p <= 'Z';
    }

    private static String turnString(char[] content){
        StringBuilder sb = new StringBuilder();
        for (char c : content) {
            if (c != '\0') {
                sb.append(c);
            } else {
                break;
            }
        }
        return sb.toString();
    }

    static void initialReservedWords(){
        reservedWordsMap.put("main", "MAINTK");
        reservedWordsMap.put("const", "CONSTTK");
        reservedWordsMap.put("int", "INTTK");
        reservedWordsMap.put("char", "CHARTK");
        reservedWordsMap.put("break", "BREAKTK");
        reservedWordsMap.put("continue", "CONTINUETK");
        reservedWordsMap.put("if", "IFTK");
        reservedWordsMap.put("else", "ELSETK");
        reservedWordsMap.put("for", "FORTK");
        reservedWordsMap.put("getint", "GETINTTK");
        reservedWordsMap.put("getchar", "GETCHARTK");
        reservedWordsMap.put("printf", "PRINTFTK");
        reservedWordsMap.put("return", "RETURNTK");
        reservedWordsMap.put("void", "VOIDTK");
    }

    static void initialSignMap(){
        signMap.put("!","NOT");
        signMap.put("&&","AND");
        signMap.put("||","OR");
        signMap.put("+","PLUS");
        signMap.put("-","MINU");
        signMap.put("*","MULT");
        signMap.put("/","DIV");
        signMap.put("%","MOD");
        signMap.put("<","LSS");
        signMap.put("<=","LEQ");
        signMap.put(">","GRE");
        signMap.put(">=","GEQ");
        signMap.put("==","EQL");
        signMap.put("!=","NEQ");
        signMap.put("=","ASSIGN");
        signMap.put(";","SEMICN");
        signMap.put(",","COMMA");
        signMap.put("(","LPARENT");
        signMap.put(")","RPARENT");
        signMap.put("[","LBRACK");
        signMap.put("]","RBRACK");
        signMap.put("{","LBRACE");
        signMap.put("}","RBRACE");

        signMap.put(".","STRCON");
    }

    static boolean errorACheck(char p){
        return p == '&' || p == '|';
    }

    static void output(boolean f, String filePath, String errorFilePath){
        if(f){
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(errorFilePath))) {
                for (ErrorToken errorToken : errorTokens) {
                    writer.write( errorToken.toString(errorToken.lineno)+ ' ' + errorToken.type.getValue());
                    writer.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        else{
            try (BufferedWriter writer = new BufferedWriter(new FileWriter(filePath))) {
                for (Token token : tokens) {
                    writer.write( token.type.getValue() + ' ' + token.content);
                    writer.newLine();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
}
