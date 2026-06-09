package Utils;

import Driver.Config;
import Driver.Driver;

public class Token {
    private Type type;
    private String content;
    private Long intNum = null;
    private int line;
    private String Tag;

    public Token(String content, int line) {
        this.content = content;
        this.line = line;
        this.type = switch(content) {
            case "main" -> Type.MAINTK;
            case "const" -> Type.CONSTTK;
            case "int" -> Type.INTTK;
            case "char" -> Type.CHARTK;
            case "break" -> Type.BREAKTK;
            case "continue" -> Type.CONTINUETK;
            case "if" -> Type.IFTK;
            case "else" -> Type.ELSETK;
            case "for" -> Type.FORTK;
            case "getint" -> Type.GETINTTK;
            case "getchar" -> Type.GETCHARTK;
            case "printf" -> Type.PRINTFTK;
            case "return" -> Type.RETURNTK;
            case "void" -> Type.VOIDTK;
            case "+" -> Type.PLUS;
            case "-" -> Type.MINU;
            case "*" -> Type.MULT;
            case "/" -> Type.DIV;
            case "%" -> Type.MOD;
            case "<" -> Type.LSS;
            case "<=" -> Type.LEQ;
            case ">" -> Type.GRE;
            case ">=" -> Type.GEQ;
            case "==" -> Type.EQL;
            case "!=" -> Type.NEQ;
            case "=" -> Type.ASSIGN;
            case ";" -> Type.SEMICN;
            case "," -> Type.COMMA;
            case "(" -> Type.LPARENT;
            case ")" -> Type.RPARENT;
            case "[" -> Type.LBRACK;
            case "]" -> Type.RBRACK;
            case "{" -> Type.LBRACE;
            case "}" -> Type.RBRACE;
            case "!" -> Type.NOT;
            case "&&" -> Type.AND;
            case "||" -> Type.OR;
            default -> {
                if (content.matches("[0-9]+")) {
                    this.intNum = Long.parseLong(content);
                    yield Type.INTCON;
                } else if (content.matches("[a-zA-Z_][a-zA-Z_0-9]*")) {
                    yield Type.IDENFR;
                } else if (content.matches("\".*\"")) {
                    yield Type.STRCON;
                } else if (content.matches("//.*") || content.matches("/\\*.*\\*/")) {
                    yield Type.COMMENT;
                } else if (content.matches("'(.|\\\\.)'")) {
                    this.intNum = Long.valueOf((int)content.charAt(1));
                    yield Type.CHRCON;
                } else {
                    // Config.PRINT_TOKENS = false;
                    if (content.equals("|")) {
                        Driver.errorRecord.addError(line, "a");
                        yield Type.OR;
                    } else if (content.equals("&")) {
                        Driver.errorRecord.addError(line, "a");
                        yield Type.AND;
                    }
                    // System.err.println("Line " + line + " > Unknown token: " + content);
                    yield Type.UNKNOWN;
                }
            }
        };
    }

    @Override
    public String toString() {
        if (this.type.equals(Type.UNKNOWN)) {
            System.err.println("Line " + line + " > Unknown token: " + content);
            Config.CONTINUE = false;
            return "";
        } else if (this.type.equals(Type.TAG)) {
            return "<" + this.Tag + ">";
        } return this.type + " " + content;
    }

    public Type getType() { return type; }

    public Object getValue() {
        switch(type) {
            case IDENFR -> { return content; }
            case INTCON -> { return intNum; }
            case STRCON -> { return content; }
            case CHRCON -> { return intNum; }
            default -> { return null; }
        }
    }

    public static enum Type {
        IDENFR,      // ident
        INTCON,      // IntConst
        CHRCON,      // CharConst
        STRCON,      // FormatString
        MAINTK,      // main
        CONSTTK,     // const
        INTTK,       // int
        CHARTK,      // char
        BREAKTK,     // break
        CONTINUETK,  // continue
        IFTK,        // if
        ELSETK,      // else
        NOT,         // !
        AND,         // &&
        OR,          // ||
        FORTK,       // for
        GETINTTK,    // getint
        GETCHARTK,   // getchar
        PRINTFTK,    // printf
        RETURNTK,    // return
        PLUS,        // +
        MINU,        // -
        VOIDTK,      // void
        MULT,        // *
        DIV,         // /
        MOD,         // %
        LSS,         // <
        LEQ,         // <=
        GRE,         // >
        GEQ,         // >=
        EQL,         // ==
        NEQ,         // !=
        ASSIGN,      // =
        SEMICN,      // ;
        COMMA,       // ,
        LPARENT,     // (
        RPARENT,     // )
        LBRACK,      // [
        RBRACK,      // ]
        LBRACE,      // {
        RBRACE,      // }
        COMMENT,     // ...
        TAG,         // Tag
        UNKNOWN
    }
}
