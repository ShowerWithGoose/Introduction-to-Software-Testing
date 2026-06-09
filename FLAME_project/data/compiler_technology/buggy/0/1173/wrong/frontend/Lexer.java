package frontend;//import com.sun.source.tree.IfTree;

//import javax.print.attribute.standard.MediaSize;
import java.io.*;
import java.util.*;

public class Lexer {
    public static Lexer instance;

    // 单例模式
    public static Lexer instance() {
        if (instance == null) {
            instance = new Lexer();
            instance.typeMapInit();
            try {
                instance.readSourceFile("testfile.txt");
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            //instance.readReserveFile();
        }
        return instance;
    }

    // Token2Type Map
    public Map<String, LexType> typeMap = new HashMap<>();
    public void typeMapInit() {
        typeMap.put("main", LexType.MAINTK);
        typeMap.put("const", LexType.CONSTTK);
        typeMap.put("int", LexType.INTTK);
        typeMap.put("char", LexType.CHARTK);
        typeMap.put("continue", LexType.CONTINUETK);
        typeMap.put("break", LexType.BREAKTK);
        typeMap.put("if", LexType.IFTK);
        typeMap.put("else", LexType.ELSETK);
        typeMap.put("printf", LexType.PRINTFTK);
        typeMap.put("return", LexType.RETURNTK);
        typeMap.put("getint", LexType.GETINTTK);
        typeMap.put("getchar", LexType.GETCHARTK);
        typeMap.put("for", LexType.FORTK);
        typeMap.put("!", LexType.NOT);
        typeMap.put("||", LexType.OR);
        typeMap.put("&&", LexType.AND);
        typeMap.put("+", LexType.PLUS);
        typeMap.put("-", LexType.MINU);
        typeMap.put("*", LexType.MULT);
        typeMap.put("/", LexType.DIV);
        typeMap.put("%", LexType.MOD);
        typeMap.put("void", LexType.VOIDTK);
        typeMap.put("<", LexType.LSS);
        typeMap.put("<=", LexType.LEQ);
        typeMap.put(">", LexType.GRE);
        typeMap.put(">=", LexType.GEQ);
        typeMap.put("==", LexType.EQL);
        typeMap.put("!=", LexType.NEQ);
        typeMap.put("=", LexType.ASSIGN);
        typeMap.put(";", LexType.SEMICN);
        typeMap.put(",", LexType.COMMA);
        typeMap.put("(", LexType.LPARENT);
        typeMap.put(")", LexType.RPARENT);
        typeMap.put("[", LexType.LBRACK);
        typeMap.put("]", LexType.RBRACK);
        typeMap.put("{", LexType.LBRACE);
        typeMap.put("}", LexType.RBRACE);
    }
    public boolean correctProgram = true;

    public List<String> errorBuffer = new ArrayList<>();
    public List<String> printBuffer = new ArrayList<>();

    public String source;//源程序字符串
    public int curPos;//当前字符串位置指针
    public String token;//解析单词值
    public LexType lexType;//解析单词类型
    //public ArrayList<String> reserveWords;//保留字表
    public int lineNum;//当前行号
    public int number;//解析数值

    // 读取源文件
    public void readSourceFile(String path) throws IOException {
        //BufferedReader reader = new BufferedReader(new FileReader(path));
        FileReader reader = new FileReader(path);
        curPos = 0;
        lineNum = 1;
        source = "";
        int c;
        while ((c = reader.read()) != -1) {
            source += (char)c;
        }
    }

//    public void readReserveFile(String path) throws IOException {
//        BufferedReader reader = new BufferedReader(new FileReader(path));
//        reserveWords.clear();
//        String str;
//        while ((str = reader.readLine()) != null) {
//            reserveWords.add(str);
//        }
//    }

    public void next() {
        char c;
        token = "";
        lexType = null;
        if (!havNext()){
            return;
        }
        c = getChar();
        while (isSpace(c) || isTab(c) || isEnter(c)) {
            if (isEnter(c)) {
                lineNum++;
            }
            if (!havNext()){
                return;
            }
            c = getChar();
        }
        if (isLetter(c) || isUnderLine(c)) {
            while (isDigit(c) || isLetter(c) || isUnderLine(c)) {
                token += c;
                c = getChar();
            }
            retract();
            if (reserved(token)){
                lexType = typeMap.get(token);
            }
            else {
                lexType = LexType.IDENFR;
            }
        }
        else if (isDigit(c)) {
            while (isDigit(c)) {
                token += c;
                c = getChar();
            }
            retract();
            //number = Integer.parseInt(token);
            lexType = LexType.INTCON;
        }
        else if (isDiv(c)) {
            token += c;
            c = getChar();
            if (isDiv(c)){
                token = "";
                while (c != '\n'){
                    if (!havNext()){
                        return;
                    }
                    c = getChar();
                }
                retract();
            }
            else if (isMult(c)) {
                token = "";
                do {
                    do {
                        c = getChar();
                    }
                    while (!isMult(c));
                    do {
                        c = getChar();
                        if (isDiv(c)){
                            return;
                        }
                    }
                    while (isMult(c));
                }
                while (!isMult(c));
            }
            else lexType = typeMap.get(token);
        }
        else if (isSquote(c)) {
            token += c;
            c = getChar();
            token += c;
            if (c == '\\'){
                c = getChar();
                token += c;
            }
            c = getChar();
            token += c;
            if (!isSquote(c)){
//                while (!isSquote(c)) {
//                    c = getChar();
//                }
                //error(c);
            }
            lexType = LexType.CHRCON;
        }
        else if (isDquote(c)) {
            do {
                token += c;
                c = getChar();
                if (c == '\\') {
                    token += c;
                    c = getChar();
                    if (c == '"') {
                        token += c;
                        c = getChar();
                    }
                }
            }
            while (!isDquote(c));
            token += c;
            lexType = LexType.STRCON;
        }
        else if (isAnd(c)) {
            token += c;
            c = getChar();
            if (isAnd(c)) {
                token += c;
                lexType = LexType.AND;
            }
            else {
                error('a', lineNum);
            }
        }
        else if (isOr(c)) {
            token += c;
            c = getChar();
            if (isOr(c)) {
                token += c;
                lexType = LexType.OR;
            }
            else {
                error('a', lineNum);
            }
        }
        else if (isNot(c) || isAssign(c) || isLss(c) || isGre(c)) {
            token += c;
            char tmp = getChar();
            if (isAssign(tmp)) {
                token += tmp;
            }
            else {
                retract();
            }
            lexType = typeMap.get(token);
        }
        else if (isPlus(c) || isMinu(c) ||isMult(c) || isLbrace(c) || isRbrace(c) ||
                isLbrack(c) || isRbrack(c) || isLparent(c) || isRparent(c) || isColon(c) ||
                isSemicn(c) || isComma(c) || isMod(c)) {
            token += c;
            lexType = typeMap.get(token);
        }
        else {
            //error(c);
        }

        if (!token.isEmpty()){
            printBuffer.add(lexType + " " + token);
        }
    }

//    public void getToken() {
//
//    }
//
//    public void getLexType() {
//
//    }

    public boolean reserved(String str) {
//        for (String res : reserveWords) {
//            if (res.compareTo(str) == 0) {
//                return true;
//            }
//        }
        if (typeMap.containsKey(str)) {
            return true;
        }
        return false;
    }

    public char getChar() {
        if (curPos < source.length()) {
            curPos ++;
            return source.charAt(curPos - 1);
        }
        return '\n';
    }

    public void retract() {
        curPos--;
    }

    // Estimate Character Type
    // region
    public boolean isDigit(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        return false;
    }

    public boolean isLetter(char c) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            return true;
        }
        return false;
    }

    public boolean isPlus(char c) {
        if (c == '+') {
            return true;
        }
        return false;
    }

    public boolean isMinu(char c) {
        if (c == '-') {
            return true;
        }
        return false;
    }

    public boolean isMult(char c) {
        if (c == '*') {
            return true;
        }
        return false;
    }

    public boolean isDiv(char c) {
        if (c == '/') {
            return true;
        }
        return false;
    }

    public boolean isColon(char c) {
        if (c == ':') {
            return true;
        }
        return false;
    }

    public boolean isMod(char c) {
        if (c == '%') {
            return true;
        }
        return false;
    }

    public boolean isNot(char c) {
        if (c == '!') {
            return true;
        }
        return false;
    }

    public boolean isLss(char c) {
        if (c == '<') {
            return true;
        }
        return false;
    }

    public boolean isGre(char c) {
        if (c == '>') {
            return true;
        }
        return false;
    }

    public boolean isAssign(char c) {
        if (c == '=') {
            return true;
        }
        return false;
    }

    public boolean isSemicn(char c) {
        if (c == ';') {
            return true;
        }
        return false;
    }

    public boolean isComma(char c) {
        if (c == ',') {
            return true;
        }
        return false;
    }

    public boolean isOr(char c) {
        if (c == '|') {
            return true;
        }
        return false;
    }

    public boolean isAnd(char c) {
        if (c == '&') {
            return true;
        }
        return false;
    }

    public boolean isLparent(char c) {
        if (c == '(') {
            return true;
        }
        return false;
    }

    public boolean isRparent(char c) {
        if (c == ')') {
            return true;
        }
        return false;
    }

    public boolean isLbrack(char c) {
        if (c == '[') {
            return true;
        }
        return false;
    }

    public boolean isRbrack(char c) {
        if (c == ']') {
            return true;
        }
        return false;
    }

    public boolean isLbrace(char c) {
        if (c == '{') {
            return true;
        }
        return false;
    }

    public boolean isRbrace(char c) {
        if (c == '}') {
            return true;
        }
        return false;
    }

    public boolean isUnderLine(char c) {
        if (c == '_') {
            return true;
        }
        return false;
    }

    public boolean isSpace(char c) {
        if (c == ' ') {
            return true;
        }
        return false;
    }

    public boolean isTab(char c) {
        if (c == '\t') {
            return true;
        }
        return false;
    }

    public boolean isEnter(char c) {
        if (c == '\n') {
            return true;
        }
        return false;
    }

    public boolean isDquote(char c) {
        if (c == '\"') {
            return true;
        }
        return false;
    }

    public boolean isSquote(char c) {
        if (c == '\'') {
            return true;
        }
        return false;
    }
    // endregion

    // Error handling
//    public void error(char c) {
//        //correctProgram = false;
//        System.out.println("Unexcept Error " + lineNum + " " + (int)c);
//    }

    public void error(char id, int line){
        correctProgram = false;
        switch (id){
            case 'a':
                errorBuffer.add(line + " " + id);
        }
    }

    public boolean havNext(){
        return (curPos < source.length());
    }

    public void printResult() throws IOException {
        if (correctProgram) {
            BufferedWriter writer = new BufferedWriter(new FileWriter("lexer.txt"));
            writer.write("");
            for (String str : printBuffer){
                writer.append(str + "\n");
                //System.out.println(str);
            }
            writer.flush();
        }
        else {
            BufferedWriter writer = new BufferedWriter(new FileWriter("error.txt"));
            writer.write("");
            for (String error : errorBuffer){
                writer.append(error + "\n");
            }
            writer.flush();
        }
    }
}