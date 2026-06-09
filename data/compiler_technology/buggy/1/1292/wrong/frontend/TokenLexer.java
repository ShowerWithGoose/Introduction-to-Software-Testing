package frontend;

import java.util.ArrayList;

public class TokenLexer {
    private ArrayList<String> arr = new ArrayList<>();         //储存输入的字符串组
    private int lineNum;
    private State state;
    private int curPos;
    private char cur;
    private StringBuilder sb = null;
    private ArrayList<Token> tokens = new ArrayList<>();

    public TokenLexer(ArrayList<String> arr) {
        this.arr = arr;
        this.lineNum = 0;
        this.curPos = 0;
        this.state = State.START;
    }

    enum State {
        START, INTCON, STRCON, CHRCON, OPERATOR, NOTE, NOTES, SPACE, END,
    }

    public ArrayList<Token> getTokens() {
        return tokens;
    }

    public void peek() {
        while (lineNum < arr.size() && curPos >= arr.get(lineNum).length()) {
            curPos = 0;
            lineNum += 1;
        }
        if (lineNum >= arr.size()) {
            state = State.END;
            return;
        }
        //System.out.println(curPos);
        cur = arr.get(lineNum).charAt(curPos);
        curPos += 1;
    }

    public void tokenScan() {
        while (lineNum < arr.size()) {
            if (state == State.END) {
                break;
            }
            parse();
        }
    }

    public void parse() {
        switch (state) {
            case START : {
                sb = new StringBuilder();
                peek();
                if (lineNum >= arr.size()) {
                    break;
                } else if (Character.isWhitespace(cur)) {
                    state = State.SPACE;
                    break;
                } else if (Character.isAlphabetic(cur) || cur == '_') {
                    sb.append(cur);
                    while (curPos < arr.get(lineNum).length() &&
                            (Character.isAlphabetic(arr.get(lineNum).charAt(curPos))
                                    || Character.isDigit(arr.get(lineNum).charAt(curPos))
                                    || arr.get(lineNum).charAt(curPos) == '_')) {
                        peek();
                        sb.append(cur);
                    }
                    reserve();
                    break;
                } else if (Character.isDigit(cur)) {
                    sb.append(cur);
                    while (curPos < arr.get(lineNum).length() && Character.isDigit(arr.get(lineNum).charAt(curPos))) {
                        peek();
                        sb.append(cur);
                    }
                    state = State.INTCON;
                    break;
                } else if (cur == '\"') {
                    sb.append(cur);
                    while (curPos < arr.get(lineNum).length() && arr.get(lineNum).charAt(curPos) != '\"') {
                        peek();
                        sb.append(cur);
                        if (cur == '\\') {
                            peek();
                            sb.append(cur);
                        }
                    }
                    peek();
                    sb.append(cur);
                    state = State.STRCON;
                    break;
                } else if (cur == '\'') {
                    sb.append(cur);
                    while (curPos < arr.get(lineNum).length() && arr.get(lineNum).charAt(curPos) != '\'') {
                        peek();
                        sb.append(cur);
                        if (cur == '\\') {
                            peek();
                            sb.append(cur);
                        }
                    }
                    peek();
                    sb.append(cur);
                    state = State.CHRCON;
                    break;
                } else if (cur == '/') {
                    if (curPos < arr.get(lineNum).length() && arr.get(lineNum).charAt(curPos) == '/') {
                        peek();
                        state = State.NOTE;
                        break;
                    } else if (curPos < arr.get(lineNum).length() && arr.get(lineNum).charAt(curPos) == '*') {
                        peek();
                        state = State.NOTES;
                        break;
                    } else {
                        Token token = new Token("/", lineNum + 1, LexType.DIV);
                        //token.printOut();
                        tokens.add(token);
                        state = State.START;
                        break;
                    }
                } else {
                    sb.append(cur);
                    if (curPos < arr.get(lineNum).length() && !Character.isDigit(arr.get(lineNum).charAt(curPos))
                            && !Character.isAlphabetic(arr.get(lineNum).charAt(curPos))
                            && arr.get(lineNum).charAt(curPos) != '_' && cur != '(' && cur != '[' && cur != '{'
                            && cur != ')' && cur != '}' && cur != ']' && cur != ';' && cur != ','
                            && arr.get(lineNum).charAt(curPos) != '\"' && arr.get(lineNum).charAt(curPos) != '\''
                            && arr.get(lineNum).charAt(curPos) != '(' && arr.get(lineNum).charAt(curPos) != '['
                            && arr.get(lineNum).charAt(curPos) != '+' && arr.get(lineNum).charAt(curPos) != '-'
                            && arr.get(lineNum).charAt(curPos) != '{' && !Character.isWhitespace(arr.get(lineNum).charAt(curPos))) {
                        peek();
                        sb.append(cur);
                    }
                    state = State.OPERATOR;
                    //System.out.println(sb.toString());
                    break;
                }
            }
            case INTCON: {
                Token token = new Token(sb.toString(), lineNum + 1, LexType.INTCON);
                //token.printOut();
                tokens.add(token);
                state = State.START;
                break;
            }
            case STRCON: {
                Token token = new Token(sb.toString(), lineNum + 1, LexType.STRCON);
                //token.printOut();
                tokens.add(token);
                state = State.START;
                break;
            }
            case CHRCON: {
                Token token = new Token(sb.toString(), lineNum + 1, LexType.CHRCON);
                //token.printOut();
                tokens.add(token);
                state = State.START;
                break;
            }
            case OPERATOR: {
                operate();
                break;
            }
            case NOTE: {
                lineNum += 1;
                curPos = 0;
                state = State.START;
                break;
            }
            case NOTES: {
                while (true) {
                    if (curPos < arr.get(lineNum).length() && cur == '*' && arr.get(lineNum).charAt(curPos) == '/') {
                        state = State.START;
                        peek();
                        break;
                    }
                    peek();
                }
                break;
            }
            case SPACE: {
                while (curPos < arr.get(lineNum).length() && Character.isWhitespace(arr.get(lineNum).charAt(curPos))) {
                    peek();
                }
                state = State.START;
                break;
            }
            case END: break;
        }
    }

    public void reserve() {
        String str = sb.toString();
        Token token = null;
        switch (str) {
            case "main": {
                token = new Token("main", lineNum + 1, LexType.MAINTK);
                break;
            }
            case "const": {
                token = new Token("const", lineNum + 1, LexType.CONSTTK);
                break;
            }
            case "int": {
                token = new Token("int", lineNum + 1, LexType.INTTK);
                break;
            }
            case "char": {
                token = new Token("char", lineNum + 1, LexType.CHARTK);
                break;
            }
            case "break": {
                token = new Token("break", lineNum + 1, LexType.BREAKTK);
                break;
            }
            case "continue": {
                token = new Token("continue", lineNum + 1, LexType.CONTINUETK);
                break;
            }
            case "if": {
                token = new Token("if", lineNum + 1, LexType.IFTK);
                break;
            }
            case "else": {
                token = new Token("else", lineNum + 1, LexType.ELSETK);
                break;
            }
            case "for": {
                token = new Token("for", lineNum + 1, LexType.FORTK);
                break;
            }
            case "getint": {
                token = new Token("getint", lineNum + 1, LexType.GETINTTK);
                break;
            }
            case "getchar": {
                token = new Token("getchar", lineNum + 1, LexType.GETCHARTK);
                break;
            }
            case "printf": {
                token = new Token("printf", lineNum + 1, LexType.PRINTFTK);
                break;
            }
            case "return": {
                token = new Token("return", lineNum + 1, LexType.RETURNTK);
                break;
            }
            case "void": {
                token = new Token("void", lineNum + 1, LexType.VOIDTK);
                break;
            }
            default: {
                token = new Token(str, lineNum + 1, LexType.IDENFR);
                break;
            }
        }
        //token.printOut();
        tokens.add(token);
        state = State.START;
    }

    public void operate() {
        String str = sb.toString();
        Token token = null;
        switch (str) {
            case "!" : {
                token = new Token(str, lineNum + 1, LexType.NOT);
                break;
            }
            case "&&" : {
                token = new Token(str, lineNum + 1, LexType.AND);
                break;
            }
            case "||" : {
                token = new Token(str, lineNum + 1, LexType.OR);
                break;
            }
            case "+" : {
                token = new Token(str, lineNum + 1, LexType.PLUS);
                break;
            }
            case "-" : {
                token = new Token(str, lineNum + 1, LexType.MINU);
                break;
            }
            case "*" : {
                token = new Token(str, lineNum + 1, LexType.MULT);
                break;
            }
            case "%" : {
                token = new Token(str, lineNum + 1, LexType.MOD);
                break;
            }
            case "<=" : {
                token = new Token(str, lineNum + 1, LexType.LEQ);
                break;
            }
            case "<" : {
                token = new Token(str, lineNum + 1, LexType.LSS);
                break;
            }
            case ">=" : {
                token = new Token(str, lineNum + 1, LexType.GEQ);
                break;
            }
            case ">" : {
                token = new Token(str, lineNum + 1, LexType.GRE);
                break;
            }
            case "==" : {
                token = new Token(str, lineNum + 1, LexType.EQL);
                break;
            }
            case "!=" : {
                token = new Token(str, lineNum + 1, LexType.NEQ);
                break;
            }
            case "=" : {
                token = new Token(str, lineNum + 1, LexType.ASSIGN);
                break;
            }
            case ";" : {
                token = new Token(str, lineNum + 1, LexType.SEMICN);
                break;
            }
            case "," : {
                token = new Token(str, lineNum + 1, LexType.COMMA);
                break;
            }
            case "(" : {
                token = new Token(str, lineNum + 1, LexType.LPARENT);
                break;
            }
            case ")" : {
                token = new Token(str, lineNum + 1, LexType.RPARENT);
                break;
            }
            case "[" : {
                token = new Token(str, lineNum + 1, LexType.LBRACK);
                break;
            }
            case "]" : {
                token = new Token(str, lineNum + 1, LexType.RBRACK);
                break;
            }
            case "{" : {
                token = new Token(str, lineNum + 1, LexType.LBRACE);
                break;
            }
            case "}" : {
                token = new Token(str, lineNum + 1, LexType.RBRACE);
                break;
            }
            case "&" : {
                token = new Token(str, lineNum + 1, LexType.AND);
                Error error = new Error(lineNum + 1, "a");
                ErrorList.add(error);
                break;
            }
            case "|" : {
                token = new Token(str, lineNum + 1, LexType.OR);
                Error error = new Error(lineNum + 1, "a");
                ErrorList.add(error);
                break;
            }
        }
        tokens.add(token);
        state = State.START;
    }
}
