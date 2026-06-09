package frontend;

import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;

public class Lexer {
    private final ArrayList<String> source;
    private final HashMap<String, LexType> reserveWords;
    private Integer curPos;
    private Character current;
    private StringBuilder token;
    private Integer lineNum;
    private State state;

    public Lexer() {
        this.source = readSource();
        this.reserveWords = reserveInit();
        state = State.Start;
        token = new StringBuilder();
        curPos = 0;
        lineNum = 1;
        lexerScan();
    }

    enum State {
        Start, Digit, NonDigit, Operation, LineCom, StrCon, CharCon, BlkCom
    }

    private void lexerScan() {
        peekChar();
        while (!fileEnded()) {
            lexerParse();
        }
    }

    private void lexerParse() {
        switch (state) {
            case Start:  {
                if (Character.isDigit(current)) {
                    state = State.Digit;
                    token.append(current);
                }
                else if (Character.isAlphabetic(current) || current.equals('_')){
                    state = State.NonDigit;
                    token.append(current);
                    peekChar();
                }
                else if (current.equals(' ')
                        || current.equals('\r')
                        || current.equals('\t')
                        || current.equals('\n')) {
                    peekChar();
                    break;
                }
                else {
                    state = State.Operation;
                }
                break;
            }
            case Digit: {
                while (Character.isDigit(peekChar())) {
                    token.append(current);
                }
                tokenOut(LexType.INTCON,Long.valueOf(token.toString()), token.toString());
                break;
            }
            case NonDigit: {
                while (Character.isDigit(current)
                        || Character.isAlphabetic(current) || current.equals('_')) {
                    token.append(current);
                    peekChar();
                }
                tokenOut(reserve(token.toString()), null, token.toString());
                break;
            }
            case Operation: {
                OperParse();
                break;
            }
            case LineCom: {
                peekChar();
                while (!current.equals('\n')) {
                    peekChar();
                }
                state = State.Start;
                break;
            }
            case BlkCom: {
                boolean done = false, half = false;
                while (!done && current != null) {
                    peekChar();
                    if (half && current.equals('/')) {
                        done = true;
                    }
                    else {
                        half = false;
                    }
                    if (current.equals('*')) {
                        half = true;
                    }
                }
                peekChar();
                state = State.Start;
                break;
            }
            case StrCon: {
                while (!peekChar().equals('"')) {
                    token.append(current);
                    if (current.equals('\\')) {
                        //Ampersand
                        token.append(peekChar());
                    }
                }
                tokenOut(LexType.STRCON, null, "\"" + token.toString() + "\"");
                peekChar();
                break;
            }
            case CharCon: {
                while (!peekChar().equals('\'')) {
                    token.append(current);
                    if (current.equals('\\')) {
                        //Ampersand
                        token.append(peekChar());
                    }
                }
                tokenOut(LexType.CHRCON, null, "'" + token.toString() + "'"); // TODO: value error
                peekChar();
                break;
            }
        }
    }

    private void OperParse() {
        switch (current) {
            case '!': {
                if (peekChar().equals('=')) {
                    tokenOut(LexType.NEQ, null, "!=");
                    peekChar();
                }
                else {
                    tokenOut(LexType.NOT, null, "!");
                }
                break;
            }
            case '&': {
                if (!peekChar().equals('&')) {
                    popErrorA();
                }
                else {
                    tokenOut(LexType.AND, null, "&&");
                    peekChar();
                }

                break;
            }
            case '|': {
                if (!peekChar().equals('|')) {
                    popErrorA();
                }
                else {
                    tokenOut(LexType.OR, null, "||");
                    peekChar();
                }
                break;
            }
            case '+': tokenOut(LexType.PLUS, null, "+"); peekChar(); break;
            case '-': tokenOut(LexType.MINU, null, "-"); peekChar(); break;
            case '*': tokenOut(LexType.MULT, null, "*"); peekChar(); break;
            case '/': {
                peekChar();
                if (current.equals('/')) {
                    state = State.LineCom;
                }
                else if (current.equals('*')) {
                    state = State.BlkCom;
                }
                else {
                    tokenOut(LexType.DIV, null, "/");
                }
                break;
            }
            case '%': tokenOut(LexType.MOD, null, "%"); peekChar(); break;
            case '<': {
                if (peekChar().equals('=')) {
                    tokenOut(LexType.LEQ, null, "<=");
                    peekChar();
                }
                else {
                    tokenOut(LexType.LSS, null, "<");
                }
                break;
            }
            case '>': {
                if (peekChar().equals('=')) {
                    tokenOut(LexType.GEQ, null, ">=");
                    peekChar();
                }
                else {
                    tokenOut(LexType.GRE, null, ">");
                }
                break;
            }
            case '=': {
                if (peekChar().equals('=')) {
                    tokenOut(LexType.EQL, null, "==");
                    peekChar();
                }
                else {
                    tokenOut(LexType.ASSIGN, null, "=");
                }
                break;
            }
            case ';': tokenOut(LexType.SEMICN, null, ";"); peekChar(); break;
            case ',': tokenOut(LexType.COMMA, null, ","); peekChar(); break;
            case '(': tokenOut(LexType.LPARENT, null, "("); peekChar(); break;
            case ')': tokenOut(LexType.RPARENT, null, ")"); peekChar(); break;
            case '[': tokenOut(LexType.LBRACK, null, "["); peekChar(); break;
            case ']': tokenOut(LexType.RBRACK, null, "]"); peekChar(); break;
            case '{': tokenOut(LexType.LBRACE, null, "{"); peekChar(); break;
            case '}': tokenOut(LexType.RBRACE, null, "}"); peekChar(); break;
            case '"': state = State.StrCon; break;
            case '\'': state = State.CharCon; break;
            default: peekChar(); break;
        }
    }

    private void tokenOut(LexType lexType, Long value, String str) {
        try {
            FileWriter fw = new FileWriter("lexer.txt", true);
            fw.write(new Token(lexType, value, str).toPrint() + "\n");
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
        token.setLength(0);
        state = State.Start;
    }

    private LexType reserve(String str) {
        return reserveWords.getOrDefault(str, LexType.IDENFR);
    }

    private HashMap<String, LexType> reserveInit() {
        HashMap<String, LexType> hashMap = new HashMap<>();
        hashMap.put("main", LexType.MAINTK);
        hashMap.put("const", LexType.CONSTTK);
        hashMap.put("int", LexType.INTTK);
        hashMap.put("char", LexType.CHARTK);
        hashMap.put("break", LexType.BREAKTK);
        hashMap.put("continue", LexType.CONTINUETK);
        hashMap.put("if", LexType.IFTK);
        hashMap.put("for", LexType.FORTK);
        hashMap.put("void", LexType.VOIDTK);
        hashMap.put("else", LexType.ELSETK);
        hashMap.put("getint", LexType.GETINTTK);
        hashMap.put("getchar", LexType.GETCHARTK);
        hashMap.put("printf", LexType.PRINTFTK);
        hashMap.put("return", LexType.RETURNTK);
        return hashMap;
    }

    private ArrayList<String> readSource() {
        ArrayList<String> content = new ArrayList<>();
        try{
            BufferedReader in = new BufferedReader(new FileReader("testfile.txt"));
            String lineContent;
            while((lineContent = in.readLine()) != null) {
                content.add(lineContent + "\n");
            }
        } catch (IOException e) {
            System.out.println("Input error");
            e.printStackTrace();
        }
        return content;
    }

    private boolean fileEnded() {
        return (lineNum - 1 >= source.size());
    }

    private boolean lineEnded() {
        return (curPos >= source.get(lineNum - 1).length());
    }

    private void changeLine() {
        curPos = 0;
        lineNum++;
    }

    private Character peekChar() {
        if (fileEnded()) {
            current = null;
        }
        else if (lineEnded()) {
            changeLine();
            if (fileEnded()) {
                current = null;
            }
            else current = source.get(lineNum - 1).charAt(curPos++);
        }
        else current = source.get(lineNum - 1).charAt(curPos++);
        return current;
    }

    private void popErrorA() {
        try {
            FileWriter fw = new FileWriter("error.txt", true);
            fw.write(lineNum + " a");
            fw.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
