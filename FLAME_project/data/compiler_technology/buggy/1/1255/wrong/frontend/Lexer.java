package frontend;

import token.Token;
import token.TokenCode;
import error.Error;
import error.ErrorSave;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Lexer {
    private String fileStr;
    private static HashMap<String, TokenCode> str2tokenCode = new HashMap<>();
    private HashMap<TokenCode, ArrayList<Token>> sortTokens = new HashMap<>();
    int pos = 0;
    int lineNum = 1;


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

    public void read(File file) {
        try {
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


    public Token nextToken()  {
        while (pos < fileStr.length()) {
            if (fileStr.charAt(pos) == '/' && fileStr.charAt(pos + 1) == '/') {
                pos += 2;
                while (fileStr.charAt(pos) != '\n') {
                    pos++;
                }
            } else if (fileStr.charAt(pos) == '/' && fileStr.charAt(pos + 1) == '*') {
                pos += 2;
                while (fileStr.charAt(pos) != '*' || fileStr.charAt(pos + 1) != '/') {
                    pos++;
                }
                pos += 2;
            } else if (Character.isAlphabetic(fileStr.charAt(pos)) || fileStr.charAt(pos) == '_') {
                String s = parseAlp();
                TokenCode tc = str2tokenCode.get(s);
                if (tc != null)
                    return record(lineNum,tc,s);
                else
                    return record(lineNum, TokenCode.IDENFR, s);
            } else if (isLogicSign()) { //包括！=
                String s = parseLogicSign();
                TokenCode tc = str2tokenCode.get(s);
                if (tc != null) {
                    return record(lineNum, tc, s);
                }
                else {
                    errorRecord(lineNum,"a",s);
                    if (s.compareTo("|") == 0)
                        return record(lineNum, TokenCode.OR,"||");
                    else
                        return record(lineNum, TokenCode.AND,"&&");
                }
            } else if (Character.isDigit(fileStr.charAt(pos))) {
                String s = parseDigit();
                return record(lineNum, TokenCode.INTCON,s);
            } else if (isCompareSign()) { //包括=
                String s = parseCompareSign();
                TokenCode tc = str2tokenCode.get(s);
                return record(lineNum,tc,s);
            } else if (fileStr.charAt(pos) == '\"') {
                String s = parseStr();
                return record(lineNum, TokenCode.STRCON,s);
            } else if (fileStr.charAt(pos) == '\'') {
                String s = parseChar();
                return record(lineNum, TokenCode.CHRCON,s);
            } else if (isOtherSign()) {
                String s = String.valueOf(fileStr.charAt(pos));
                TokenCode tc = str2tokenCode.get(s);
                pos++;
                return record(lineNum,tc,s);
            } else if (fileStr.charAt(pos) == '\n') {
                pos++;
                lineNum++;
            } else {
                pos++;
            }
        }
        return null;
    }

    public boolean isLogicSign() {
        return fileStr.charAt(pos) == '&' || fileStr.charAt(pos) == '|' || fileStr.charAt(pos) == '!';
    }


    public Token record(int lineNum, TokenCode tc, String s) {
        sortTokens.computeIfAbsent(tc,k -> new ArrayList<>());
        Token token = new Token(lineNum,s,tc);
        sortTokens.get(tc).add(token);
        return token;
    }

    public void errorRecord(int lineNum, String type, String s) {
        ErrorSave.getErrors().add(new Error(lineNum,type,s));
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
            if (fileStr.charAt(pos) == '\\') {
                sb.append(fileStr.charAt(pos));
                sb.append(fileStr.charAt(pos + 1));
                pos += 2;
            } else {
                sb.append(fileStr.charAt(pos));
                pos++;
            }
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
            if (fileStr.charAt(pos) == '\\') {
                sb.append(fileStr.charAt(pos));
                sb.append(fileStr.charAt(pos + 1));
                pos += 2;
            } else {
                sb.append(fileStr.charAt(pos));
                pos++;
            }
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

//    public void output() throws IOException {
//        if (ErrorSave.getErrors().size() != 0) {
//            for (Error error : ErrorSave.getErrors()) {
//                errorFileWriter.write(error.toString() + "\n");
//            }
//        } else {
//            for (Token token : tokens) {
//                fileWriter.write(token.toString() + "\n");
//            }
//        }
//    }
}
