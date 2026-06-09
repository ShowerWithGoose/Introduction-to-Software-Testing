package frontend.lexer;
import frontend.Error;
import frontend.ErrorType;
import frontend.Printer;

import java.io.*;
import java.util.ArrayList;

public class Lexer {
    private int lineNum;
    private PushbackInputStream inputStream;
    private char curCharacter;
    private ArrayList<Token> tokenArrayList = new ArrayList<>();
    private ArrayList<Error> errorArrayList = new ArrayList<>();

    public Lexer(PushbackInputStream inputStream) throws IOException {
        this.lineNum = 1;
        this.inputStream = inputStream;
        this.curCharacter = (char)inputStream.read();
    }

    public void addToken() throws IOException {
        Token curToken = getToken();
        while(curToken != null && curToken.getType()!= TokenType.EOF) {
            tokenArrayList.add(curToken);
            curToken = getToken();
        }
    }

    public ArrayList<Token> getTokenArrayList() {
        return this.tokenArrayList;
    }

    public ArrayList<Error> getErrorArrayList() {
        return  this.errorArrayList;
    }

    //从输入流中获得一个token
    public Token getToken() throws IOException {
        StringBuilder sb = new StringBuilder();

        //TODO：跳过空白字符
        while(curCharacter == ' ' || curCharacter == '\t'
                || curCharacter == '\n') {
            //换行加行号
            if (curCharacter == '\n') {
                lineNum++;
            }
            move();
        }

        //全文结束
        if (curCharacter == '\uFFFF') {
            return new Token(TokenType.EOF, this.lineNum, "EOF");
        }

        //单字符 +  -  *  % ;  ,  (  )  {  }  [  ]
        if (isSingleCharacter(curCharacter)) {
            char c = curCharacter;
            sb.append(c);
            move();
            return new Token(getSingleCharacterType(c), this.lineNum, sb.toString());
        }

        //处理比较符号（后面可能有等号） <  <=  >  >=  !  !=  = ==
        if (isComSymbol(curCharacter)) {
            sb.append(curCharacter);
            move();
            if (curCharacter == '=') {
                sb.append(curCharacter);
                move();
            }
            return new Token(getCompareType(sb), this.lineNum, sb.toString());
        }

        //处理逻辑运算符 || 和 &&
        if (curCharacter == '|') {
            move();
            //TODO:错误处理
            if (curCharacter != '|') {
                Printer.getInstance().setHasError();
                Printer.getInstance().addError(this.lineNum, ErrorType.a);
            } else {
                move();
            }
            return new Token(TokenType.OR, this.lineNum, "||");
        } else if (curCharacter == '&') {
            move();
            //TODO:错误处理
            if (curCharacter != '&') {
                Printer.getInstance().setHasError();
                Printer.getInstance().addError(this.lineNum, ErrorType.a);
            } else {
                move();
            }
            return new Token(TokenType.AND, this.lineNum, "&&");
        }

        //处理除号与注释 /  // /*
        if (curCharacter == '/') {
            sb.append(curCharacter);
            move();
            if (curCharacter == '/') { // //
                move();
                while (curCharacter != '\n' && curCharacter != '\uFFFF') {
                    move();
                }
                move();
                lineNum++;
                return getToken();
            } else if (curCharacter == '*') { // /*
                move();
                while (true) {
                    while (curCharacter != '*') {
                        if (curCharacter == '\n') {
                            lineNum++;
                        }
                        move();
                    }
                    move();
                    if (curCharacter == '/') {
                        break;
                    }
                }
                move();
                return getToken();
            }
            return new Token(TokenType.DIV, lineNum, sb.toString());
        }

        //字符串
        //TODO:""中嵌套\"
        if (curCharacter == '"') {
            sb.append(curCharacter);
            move();
            while (curCharacter != '"') {
                sb.append(curCharacter);
                move();
            }
            sb.append(curCharacter);
            move();
            return new Token(TokenType.STRCON, lineNum, sb.toString());
        }

        //字符
        if (curCharacter == '\'') {
            sb.append(curCharacter);
            move();
            while (curCharacter != '\'') {
                sb.append(curCharacter);
                move();
            }
            sb.append(curCharacter);
            move();
            //TODO：增加对'\''的处理
            if (curCharacter == '\'') {
                sb.append(curCharacter);
                move();
            }
            return new Token(TokenType.CHRCON, lineNum, sb.toString());
        }

        //Digit
        if (Character.isDigit(curCharacter)) {
            //sb.append(curCharacter);
            while (Character.isDigit(curCharacter)) {
                sb.append(curCharacter);
                move();
            }
            return new Token(TokenType.INTCON, lineNum, sb.toString());
        }

        //保留字或标识符Ident
        if (Character.isAlphabetic(curCharacter) || curCharacter == '_') {
            sb.append(curCharacter);
            move();
            while (Character.isAlphabetic(curCharacter)
                    || curCharacter == '_' || Character.isDigit(curCharacter)) {
                sb.append(curCharacter);
                move();
            }
            return new Token(getReserveOrIdentType(sb), this.lineNum, sb.toString());
        }
        return null;
    }

    private boolean isSingleCharacter(char c) {
        return c == '+' || c == '-' || c == '*' || c == '%' || c == ';'
                || c == ',' || c == '(' || c == ')' || c == '['
                || c == ']' || c == '{' || c == '}';
    }

    private boolean isComSymbol(char c) {
        return c == '<' || c == '>' || c == '=' || c == '!';
    }

    private TokenType getSingleCharacterType(char c) {
        switch (c) {
            case '+': return TokenType.PLUS;
            case '-': return TokenType.MINU;
            case '*': return TokenType.MULT;
            case '%': return TokenType.MOD;
            case ';': return TokenType.SEMICN;
            case ',': return TokenType.COMMA;
            case '(': return TokenType.LPARENT;
            case ')': return TokenType.RPARENT;
            case '[': return TokenType.LBRACK;
            case ']': return TokenType.RBRACK;
            case '{': return TokenType.LBRACE;
            case '}': return TokenType.RBRACE;
        }
        return null;
    }

    private TokenType getCompareType(StringBuilder sb) {
        String s = sb.toString();
        switch (s) {
            case "<": return TokenType.LSS;
            case "<=": return TokenType.LEQ;
            case ">": return TokenType.GRE;
            case ">=": return TokenType.GEQ;
            case "=": return TokenType.ASSIGN;
            case "==": return TokenType.EQL;
            case "!": return TokenType.NOT;
            case "!=": return TokenType.NEQ;
        }
        return null;
    }

    private TokenType getReserveOrIdentType(StringBuilder sb) {
        String s = sb.toString();
        switch (s) {
            case "main" : return TokenType.MAINTK;
            case "const" : return TokenType.CONSTTK;
            case "int" : return TokenType.INTTK;
            case "char" : return TokenType.CHARTK;
            case "break" : return TokenType.BREAKTK;
            case "continue" : return TokenType.CONTINUETK;
            case "if" : return TokenType.IFTK;
            case "else" : return TokenType.ELSETK;
            case "for" : return TokenType.FORTK;
            case "getint" : return TokenType.GETINTTK;
            case "getchar" : return TokenType.GETCHARTK;
            case "printf" : return TokenType.PRINTFTK;
            case "return" : return TokenType.RETURNTK;
            case "void" : return TokenType.VOIDTK;
        }
        return TokenType.IDENFR;
    }

    private void move() throws IOException {
        curCharacter = (char) inputStream.read();
    }
}
