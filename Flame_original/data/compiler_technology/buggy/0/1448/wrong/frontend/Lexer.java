package frontend;

import frontend.Tools.WriteTools;

import java.io.File;
import java.util.Scanner;

public class Lexer {
    ScanTools scanTools;
    File outputFile = new File("lexer.txt");
    File errorFile = new File("error.txt");
    boolean hasError = false;

    public Lexer(String source) {
        this.scanTools = new ScanTools(source);
    }

    public void lexar() {
        outputFile.delete();
        errorFile.delete();
        while (!scanTools.bufferEmpty()) {
            scanTools.skipUseless();
            if (scanTools.getToken())
                hasError = true;
        }
        if (hasError)
            outputFile.delete();
        scanTools.close();
    }
}

class ScanTools {
    private WriteTools writeTools = new WriteTools();
    private Scanner scanner;
    private StringBuilder buffer;
    private char lastChar;
    private boolean hasLastChar = false;
    private int lineno = 1;
    private TokenTools tokenTools = new TokenTools();

    public ScanTools(String filePath) {
        buffer = new StringBuilder();
        try {
            File file = new File(filePath);
            scanner = new Scanner(file);
            while (true) {
                buffer = buffer.append(scanner.nextLine());
                if (scanner.hasNext())
                    buffer.append('\n');
                else
                    break;
            }
//            System.out.println("Scanner got:\n" + buffer);
        } catch (Exception e) {
            System.out.println("Input file " + filePath + " not found! ScanTools init failed!");
        }
    }

    // 获取下一个字符
    public char get() {
        if (buffer.length() == 0) {
            throw new IllegalStateException("No more characters to read!");
        }
        char c = buffer.charAt(0);
        buffer.deleteCharAt(0);
        lastChar = c;
        hasLastChar = true;
        return c;
    }

    // 将字符放回缓冲区
    public void unget() {
        if (!hasLastChar) {
            throw new IllegalStateException("No character to unget!");
        }
        buffer.insert(0, lastChar);
        hasLastChar = false;
        return;
    }

    // 将指定字符放回缓冲区
    public void unget(char c) {
        buffer.insert(0, c);
        hasLastChar = false;
        return;
    }

    public void close() {
        scanner.close();
        return;
    }

    public boolean bufferEmpty() {
        return buffer.length() <= 0;
    }

    public void skipUseless() {
        boolean foundC = false;
        do {
            char c = get();
            switch (c) {
                case '/':
                    char ch = get();
                    if (ch == '/') {
                        while (buffer.length() > 0 && get() != '\n') ;
                        lineno++;
                        skipUseless();
                    } else if (ch == '*') {
                        char tmp1 = get();
                        if (tmp1 == '\n')
                            lineno++;
                        char tmp2 = get();
                        if (tmp2 == '\n')
                            lineno++;
                        while (tmp1 != '*' || tmp2 != '/') {
                            tmp1 = tmp2;
                            tmp2 = get();
                            if (tmp2 == '\n')
                                lineno++;
                        }
                        skipUseless();
                    } else {
                        unget();
                        unget('/');
                        foundC = true;
                    }
                    break;
                case ' ':
                    break;
                case '\t':
                    break;
                case '\n':
                    lineno++;
                    break;
                default:
                    unget();
                    foundC = true;
                    break;
            }
        } while (!foundC);
    }

    public boolean getToken() {
        char c = get();
        boolean hasError = false;
        String token = "";
        String tokenType = "NULL";
        int tokenValue;
        if (c == '\'') {
            String constChar = "'";
            do {
                c = get();
                constChar += c;
            }
            while (c != '\'');
            token = constChar;
            tokenType = "CHRCON";
            if (token.charAt(1) == '\\') {
                switch (token.charAt(2)) {
                    case ('a'):
                        tokenValue = 7;
                        break;
                    case ('b'):
                        tokenValue = 8;
                        break;
                    case ('t'):
                        tokenValue = 9;
                        break;
                    case ('n'):
                        tokenValue = 10;
                        break;
                    case ('v'):
                        tokenValue = 11;
                        break;
                    case ('f'):
                        tokenValue = 12;
                        break;
                    case ('"'):
                        tokenValue = 34;
                        break;
                    case ('\''):
                        tokenValue = 39;
                        break;
                    case ('\\'):
                        tokenValue = 92;
                        break;
                    case ('0'):
                        tokenValue = 0;
                        break;
                }
            }
        } else if (c == '"') {
            String constString = "\"";
            do {
                c = get();
                constString += c;
            }
            while (c != '"');
            token = constString;
            tokenType = "STRCON";
        } else if (Character.isDigit(c)) {
            while (Character.isDigit(c)) {
                token += c;
                c = get();
            }
            unget();
            tokenType = "INTCON";
        } else if (c == '_' || Character.isAlphabetic(c)) {
            while (c == '_' || Character.isDigit(c) || Character.isAlphabetic(c)) {
                token += c;
                c = get();
            }
            unget();
            if (tokenTools.getType(token) != null) {
                TokenTools.tokenType result = tokenTools.getType(token);
                tokenType = result.name();
            } else {
                tokenType = "IDENFR";
            }
        } else {
            token += c;
            switch (c) {
                case (';'):
                case (','):
                case ('('):
                case (')'):
                case ('{'):
                case ('}'):
                case ('['):
                case (']'):
                case ('+'):
                case ('-'):
                case ('/'):
                case ('*'):
                case ('%'):
                    break;
                case ('|'):
                case ('&'):
                    char ch = get();
                    if (c != ch) {
                        unget();
                        token = "" + c;
                        hasError = true;
                        printToError(lineno + " a");
                        //error here
                    } else token = "" + c + ch;
                    break;
                case ('>'):
                case ('='):
                case ('<'):
                case ('!'):
                    c = get();
                    if (c == '=')
                        token += c;
                    else unget();
                    break;
                default:
                    //error here?
                    break;
            }
            if (tokenTools.getType(token) != null) {
                TokenTools.tokenType result = tokenTools.getType(token);
                tokenType = result.name();
            }
        }
        printToLexer(tokenType + ' ' + token);
        return hasError;
    }

    private void printToLexer(String s) {
        File file = new File("lexer.txt");
        boolean fileExists = file.exists();
        writeTools.setOutputPath(file, true);
        if (fileExists)
            System.out.print('\n' + s);
        else
            System.out.print(s);
        writeTools.reset();
    }

    private void printToError(String s) {
        File file = new File("error.txt");
        boolean fileExists = file.exists();
        writeTools.setOutputPath(file, true);
        if (fileExists)
            System.out.print("\n" + s);
        else
            System.out.print(s);
        writeTools.reset();
    }
}

class TokenTools {
    public enum tokenType {
        IDENFR("Ident"),
        INTCON("IntConst"),
        STRCON("StringConst"),
        CHRCON("CharConst"),
        MAINTK("main"),
        CONSTTK("const"),
        INTTK("int"),
        CHARTK("char"),
        BREAKTK("break"),
        CONTINUETK("continue"),
        IFTK("if"),
        ELSETK("else"),
        NOT("!"),
        AND("&&"),
        OR("||"),
        FORTK("for"),
        GETINTTK("getint"),
        GETCHARTK("getchar"),
        PRINTFTK("printf"),
        RETURNTK("return"),
        PLUS("+"),
        MINU("-"),
        VOIDTK("void"),
        MULT("*"),
        DIV("/"),
        MOD("%"),
        LSS("<"),
        LEQ("<="),
        GRE(">"),
        GEQ(">="),
        EQL("=="),
        NEQ("!="),
        ASSIGN("="),
        SEMICN(";"),
        COMMA(","),
        LPARENT("("),
        RPARENT(")"),
        LBRACK("["),
        RBRACK("]"),
        LBRACE("{"),
        RBRACE("}");

        private String value;

        tokenType(String value) {
            this.value = value;
        }

        @Override
        public String toString() {
            return value;
        }
    }

    public tokenType getType(String text) {
        for (tokenType t : tokenType.values()) {
            if (t.value.equals(text)) {
                return t;
            }
        }
        return null;
    }
}