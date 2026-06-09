package lexer;

import common.GlobalData;
import common.KeywordTable;
import enums.TokenType;
import model.Token;
import model.Tokens;
import util.Error;

import java.io.*;

public class Lexer {
    private PushbackReader pr;
    private int lineno = 1;
    private KeywordTable keywordTable = KeywordTable.getInstance();

    public Lexer(String filepath) {
//        filepath = "src/testfile.txt";
//        System.out.println(filepath);
        try {
            this.pr = new PushbackReader(new FileReader(filepath));
        } catch (FileNotFoundException e) {
            throw new RuntimeException(e);
        }
    }

    public void run() throws IOException {
        Tokens tokens = Tokens.getInstance();
        int ch;
        while((ch = pr.read()) != -1) {
            char c = (char) ch;
            pr.unread(c);
            Token token = this.next();
            if (token != null) {
                tokens.add(token);
            }
        }

    }
    private Token next() throws IOException {
        char c;
        c = getc();
        //跳过空白字符
        while(Character.isWhitespace(c)) {
            if(c == '\n') {
                lineno++;
            }
            c = getc();
        }

        //标识符
        if(Character.isLetter(c) || c == '_') {
            StringBuilder str = new StringBuilder();
            str.append(c);
            c = getc();
            while(Character.isLetter(c) || Character.isDigit(c) || c == '_') {
                str.append(c);
                c = getc();
            }
            pr.unread(c);
            String s = str.toString();
            TokenType tokenType = keywordTable.getKeywordType(s);

            //判断是否为保留关键字
            if(tokenType != null)
                return new Token(s, tokenType, lineno);
            return new Token(s, TokenType.IDENFR, lineno);
        }
        //数值常量
        else if(Character.isDigit(c)) {
            StringBuilder str = new StringBuilder();
            str.append(c);
            c = getc();
            while(Character.isDigit(c)) {
                str.append(c);
                c = getc();
            }
            pr.unread(c);
            String s = str.toString();

            return new Token(s, TokenType.INTCON, lineno);
        }
        //字符常量
        else if(c == '\'') {
            StringBuilder str = new StringBuilder();
            String s;

            str.append(c);
            c = getc();
            if(c != '\\') {
                str.append(c);
                c = getc();
                str.append(c);
            }
            else {
                str.append(c);
                c = getc();
                str.append(c);
                c = getc();
                str.append(c);
            }
            s = str.toString();
            return new Token(s, TokenType.CHRCON, lineno);
        }
        //字符串常量
        else if(c == '\"') {
            StringBuilder str = new StringBuilder();
            String s;

            str.append(c);
            c = getc();
            while(c != '\"') {
                if(c == '\\') {
                    str.append(c);
                    c = getc();
                }
                str.append(c);
                c = getc();
            }
            str.append(c);
            s = str.toString();
            return new Token(s, TokenType.STRCON, lineno);
        }
        //注释
        else if(c == '/') {
            c = getc();
            //注释//
            if(c == '/') {
                int ch;
                while((ch = pr.read()) != -1) {
                    c = (char) ch;
                    if (c == '\n'){
                        lineno++;
                        return null;
                    }
                }
            }
            //注释/**/
            else if(c == '*') {
                int ch;
                while((ch = pr.read()) != -1) {
                    c = (char) ch;
                    if (c == '*') {
                        c = getc();
                        if(c == '/')
                            return null;
                    }
                }
            }
//            else System.out.println("Lexer Error: /? -> not // or /*");
            //为除号div
            else {
                pr.unread(c);
                return new Token("/", TokenType.DIV, lineno);
            }
        }
        //其他特殊字符
        else {
            if(c == '!') {
                c = getc();
                if(c == '=')
                    return new Token("!=", TokenType.NEQ, lineno);
                else {
                    pr.unread(c);
                    return new Token("!", TokenType.NOT, lineno);
                }
            }
            else if(c == '>') {
                c = getc();
                if(c == '=')
                    return new Token(">=", TokenType.GEQ, lineno);
                else {
                    pr.unread(c);
                    return new Token(">", TokenType.GRE, lineno);
                }
            }
            else if(c == '<') {
                c = getc();
                if(c == '=')
                    return new Token("<=", TokenType.LEQ, lineno);
                else {
                    pr.unread(c);
                    return new Token("<", TokenType.LSS, lineno);
                }
            }
            else if(c == '=') {
                c = getc();
                if(c == '=')
                    return new Token("==", TokenType.EQL, lineno);
                else {
                    pr.unread(c);
                    return new Token("=", TokenType.ASSIGN, lineno);
                }
            }
            else if(c == '&') {
                c = getc();
                if(c == '&')
                    return new Token("&&", TokenType.AND, lineno);
                else {
                    pr.unread(c);
                    //输出到error.txt
                    Error.error("Lexer", lineno, 'a');
                    return new Token("&", TokenType.AND, lineno);
                }
            }
            else if(c == '|') {
                c = getc();
                if(c == '|')
                    return new Token("||", TokenType.OR, lineno);
                else {
                    pr.unread(c);
                    //输出到error.txt
                    Error.error("Lexer", lineno, 'a');
                    return new Token("|", TokenType.OR, lineno);
                }
            }
            else if(c == '+')
                return new Token("+", TokenType.PLUS, lineno);
            else if(c == '-')
                return new Token("-", TokenType.MINU, lineno);
            else if(c == '*')
                return new Token("*", TokenType.MULT, lineno);
            else if(c == '%')
                return new Token("%", TokenType.MOD, lineno);
            else if(c == ';')
                return new Token(";", TokenType.SEMICN, lineno);
            else if(c == ',')
                return new Token(",", TokenType.COMMA, lineno);
            else if(c == '(')
                return new Token("(", TokenType.LPARENT, lineno);
            else if(c == ')')
                return new Token(")", TokenType.RPARENT, lineno);
            else if(c == '[')
                return new Token("[", TokenType.LBRACK, lineno);
            else if(c == ']')
                return new Token("]", TokenType.RBRACK, lineno);
            else if(c == '{')
                return new Token("{", TokenType.LBRACE, lineno);
            else if(c == '}')
                return new Token("}", TokenType.RBRACE, lineno);
        }
        return null;
    }
    private char getc() throws IOException{
        return (char) pr.read();
    }
}
