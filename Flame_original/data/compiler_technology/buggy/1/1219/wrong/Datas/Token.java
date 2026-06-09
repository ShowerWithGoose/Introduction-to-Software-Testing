package Datas;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

/**
 * @author
 * @Description:
 * @date 2024/9/22 13:20
 */
public class Token extends MiddleData {
    // This is the tokenList
    public static ArrayList<Token> data;
    public Token() {

    }
    public Token(TokenType tokenType, String name, int lineNumber) {
        this.tokenType = tokenType;
        this.name = name;
        this.lineNumber = lineNumber;
    }

    public enum TokenType {
        IDENFR("0"),
        INTCON("0"),
        STRCON("0"),
        CHRCON("0"),
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
        TokenType(String value) {
            this.value = value;
        }

        @Override
        public String toString() {
            return value;
        }
    }

    // Reserved Word map
//    public HashMap<String, TokenType> reserveTable;

    public TokenType tokenType;
    public String name;
    public int lineNumber;

    public static ArrayList<Token> getData() {
        return Token.data;
    }

    public static void setData(ArrayList<Token> data) {
        Token.data = data;
    }

    public static void outputLexicalResult(FileWriter writer) throws IOException {
        for (Token token : data) {
            writer.write(token.tokenType.name() + " " + token.name + "\n");
        }
    }
}
