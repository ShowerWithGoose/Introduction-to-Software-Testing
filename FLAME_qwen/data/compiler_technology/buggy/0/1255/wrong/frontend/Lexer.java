package frontend;

import Token.Token;
import Token.TokenCode;
import Error.Error;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Objects;
import java.util.Scanner;

public class Lexer {
    private String fileStr;
    private FileWriter fileWriter;
    private FileWriter errorFileWriter;
    private static HashMap<String, TokenCode> str2tokenCode = new HashMap<>();
    private HashMap<TokenCode, ArrayList<Token>> sortTokens = new HashMap<>();
    private ArrayList<Token> tokens = new ArrayList<>();
    private ArrayList<Error> errors = new ArrayList<>();
    private boolean explainWrap = false;
    private boolean explainSin = false;
    int pos = 0;


    public Lexer() {
        str2tokenCode.put("main", TokenCode.MAINTK);
        str2tokenCode.put("const", TokenCode.CONSTTK);
        str2tokenCode.put("int", TokenCode.INTTK);
        str2tokenCode.put("char", TokenCode.CHARTK);
        str2tokenCode.put("break", TokenCode.BREAKTK);
        str2tokenCode.put("continue", TokenCode.CONTINUETK);
        str2tokenCode.put("if", TokenCode.IFTK);
        str2tokenCode.put("else", TokenCode.ELSETK);
        str2tokenCode.put("!", TokenCode.NOT);
        str2tokenCode.put("&&", TokenCode.AND);
        str2tokenCode.put("||", TokenCode.OR);
        str2tokenCode.put("for", TokenCode.FORTK);
        str2tokenCode.put("getint", TokenCode.GETINTTK);
        str2tokenCode.put("getchar", TokenCode.GETCHARTK);
        str2tokenCode.put("printf", TokenCode.PRINTFTK);
        str2tokenCode.put("return", TokenCode.RETURNTK);
        str2tokenCode.put("+", TokenCode.PLUS);
        str2tokenCode.put("-", TokenCode.MINU);
        str2tokenCode.put("void", TokenCode.VOIDTK);
        str2tokenCode.put("*", TokenCode.MULT);
        str2tokenCode.put("/", TokenCode.DIV);
        str2tokenCode.put("%", TokenCode.MOD);
        str2tokenCode.put("<", TokenCode.LSS);
        str2tokenCode.put("<=", TokenCode.LEQ);
        str2tokenCode.put(">", TokenCode.GRE);
        str2tokenCode.put(">=", TokenCode.GEQ);
        str2tokenCode.put("==", TokenCode.EQL);
        str2tokenCode.put("!=", TokenCode.NEQ);
        str2tokenCode.put("=", TokenCode.ASSIGN);
        str2tokenCode.put(";", TokenCode.SEMICN);
        str2tokenCode.put(",", TokenCode.COMMA);
        str2tokenCode.put("(", TokenCode.LPARENT);
        str2tokenCode.put(")", TokenCode.RPARENT);
        str2tokenCode.put("[", TokenCode.LBRACK);
        str2tokenCode.put("]", TokenCode.RBRACK);
        str2tokenCode.put("{", TokenCode.LBRACE);
        str2tokenCode.put("}", TokenCode.RBRACE);
    }

    public void read(File file,FileWriter fileWriter,FileWriter fileWriter1) {
        try {
            this.fileWriter = fileWriter;
            this.errorFileWriter = fileWriter1;
            Scanner scanner = new Scanner(file);
            StringBuilder sb = new StringBuilder();
            while (scanner.hasNextLine()) {
                sb.append(scanner.nextLine());
                sb.append('\n');
            }
            scanner.close();
            fileStr = sb.toString();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public void compile()  {
        int lineNum = 1;
        while (pos < fileStr.length()) {
            if (fileStr.charAt(pos) == '/' && fileStr.charAt(pos + 1) == '/' && !explainSin && !explainWrap) {
                pos += 2;
                explainSin = true;
            } else if (fileStr.charAt(pos) == '/' && fileStr.charAt(pos + 1) == '*' && !explainSin && !explainWrap) {
                pos += 2;
                explainWrap = true;
            } else if (fileStr.charAt(pos) == '*' && fileStr.charAt(pos + 1) == '/') {
                pos += 2;
                explainWrap = false;
            } else if (Character.isAlphabetic(fileStr.charAt(pos)) || fileStr.charAt(pos) == '_') {
                String s = parseAlp();
                TokenCode tc = str2tokenCode.get(s);
                record(lineNum, Objects.requireNonNullElse(tc, TokenCode.IDENFR), s);
            } else if (isLogicSign()) { //包括！=
                String s = parseLogicSign();
                TokenCode tc = str2tokenCode.get(s);
                if (tc != null)
                    record(lineNum, tc, s);
                else {
                    if (s.compareTo("|") == 0)
                        record(lineNum, TokenCode.OR,"||");
                    else
                        record(lineNum, TokenCode.AND,"&&");
                    errorRecord(lineNum,"a",s);
                }
            } else if (Character.isDigit(fileStr.charAt(pos))) {
                String s = parseDigit();
                record(lineNum, TokenCode.INTCON,s);
            } else if (isCompareSign()) { //包括=
                String s = parseCompareSign();
                TokenCode tc = str2tokenCode.get(s);
                record(lineNum,tc,s);
            } else if (fileStr.charAt(pos) == '\"') {
                String s = parseStr();
                record(lineNum, TokenCode.STRCON,s);
            } else if (fileStr.charAt(pos) == '\'') {
                String s = parseChar();
                record(lineNum, TokenCode.CHARCON,s);
            } else if (isOtherSign()) {
                String s = String.valueOf(fileStr.charAt(pos));
                TokenCode tc = str2tokenCode.get(s);
                pos++;
                record(lineNum,tc,s);
            } else if (fileStr.charAt(pos) == '\n') {
                pos++;
                explainSin = false;
                lineNum++;
            } else {
                pos++;
            }
        }
    }

    public boolean isLogicSign() {
        return fileStr.charAt(pos) == '&' || fileStr.charAt(pos) == '|' || fileStr.charAt(pos) == '!';
    }


    public void record(int lineNum, TokenCode tc, String s) {
        if (explainSin || explainWrap) {
            return;
        }
        sortTokens.computeIfAbsent(tc,k -> new ArrayList<>());
        Token token = new Token(lineNum,s,tc);
        sortTokens.get(tc).add(token);
        tokens.add(token);
    }

    public void errorRecord(int lineNum, String type, String s) {
        if (explainSin || explainWrap) {
            return;
        }
        errors.add(new Error(lineNum,type,s));
    }
    
    public String parseAlp() {
        StringBuilder sb = new StringBuilder();
        while (Character.isAlphabetic(fileStr.charAt(pos)) || Character.isDigit(fileStr.charAt(pos))
                || fileStr.charAt(pos) == '_') {
            sb.append(fileStr.charAt(pos));
            pos++;
        }
        return sb.toString();
    }

    public String parseLogicSign() {
        if (fileStr.charAt(pos) == '&') {
            if (pos + 1 < fileStr.length() && fileStr.charAt(pos + 1) == '&') {
                pos += 2;
                return "&&";
            } else {
                pos += 1;
                return "&";
            }
        } else if (fileStr.charAt(pos) == '|') {
            if (pos + 1 < fileStr.length() && fileStr.charAt(pos + 1) == '|') {
                pos += 2;
                return "||";
            } else {
                pos += 1;
                return "|";
            }
        } else {
            if (pos + 1 < fileStr.length() && fileStr.charAt(pos + 1) == '=') {
                pos += 2;
                return "!=";
            } else {
                pos += 1;
                return "!";
            }
        }
    }

    public String parseDigit() {
        StringBuilder sb = new StringBuilder();
        while (Character.isDigit(fileStr.charAt(pos))) {
            sb.append(fileStr.charAt(pos));
            pos++;
        }
        return sb.toString();
    }

    public boolean isCompareSign() {
        return fileStr.charAt(pos) == '>' || fileStr.charAt(pos) == '='
                || fileStr.charAt(pos) == '<';
    }

    public String parseCompareSign() {
        if (pos + 1 < fileStr.length() && fileStr.charAt(pos + 1) == '=') {
            pos += 2;
            return fileStr.charAt(pos - 2) + "=";
        } else {
            pos += 1;
            return String.valueOf(fileStr.charAt(pos - 1));
        }
    }

    public String parseStr() {
        StringBuilder sb = new StringBuilder();
        pos++;
        sb.append('\"');
        while (fileStr.charAt(pos) != '\"') {
            sb.append(fileStr.charAt(pos));
            pos++;
        }
        pos++;
        sb.append('\"');
        return sb.toString();
    }

    public String parseChar() {
        StringBuilder sb = new StringBuilder();
        pos++;
        sb.append('\'');
        while (fileStr.charAt(pos) != '\'') {
            sb.append(fileStr.charAt(pos));
            pos++;
        }
        pos++;
        sb.append('\'');
        return sb.toString();
    }

    public boolean isOtherSign() {
        char c = fileStr.charAt(pos);
        return c == '+' || c == '-' || c == '*' || c == '/' || c == '%'
                || c == ';' || c == ','
                || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}';
    }

    public void output() throws IOException {
        if (errors.size() != 0) {
            for (Error error : errors) {
                errorFileWriter.write(error.toString() + "\n");
            }
        } else {
            for (Token token : tokens) {
                fileWriter.write(token.toString() + "\n");
            }
        }
    }
}
