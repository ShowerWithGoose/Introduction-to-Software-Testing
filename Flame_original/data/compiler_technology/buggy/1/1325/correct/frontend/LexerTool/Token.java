package frontend.LexerTool;

import frontend.Parser.ParsedTree;

import java.util.HashMap;
import java.util.LinkedList;

import static frontend.LexerTool.TypeCode.*;

public class Token extends ParsedTree {

    private String stringValue;

    private int intValue;

    private int linePos;

    private TypeCode typeCode;

    private static final HashMap<TypeCode, String> type2tk = new HashMap<>();

    static {
        type2tk.put(NOT, "!");
        type2tk.put(PLUS, "+");
        type2tk.put(MINU, "-");
        type2tk.put(MULT, "*");
        type2tk.put(DIV, "/");
        type2tk.put(MOD, "%");
        type2tk.put(LSS, "<");
        type2tk.put(GRE, ">");
        type2tk.put(ASSIGN, "=");
        type2tk.put(SEMICN, ";");
        type2tk.put(COMMA, ",");
        type2tk.put(LPARENT, "(");
        type2tk.put(RPARENT, ")");
        type2tk.put(LBRACK, "[");
        type2tk.put(RBRACK, "]");
        type2tk.put(LBRACE, "{");
        type2tk.put(RBRACE, "}");

        type2tk.put(AND, "&&");
        type2tk.put(OR, "||");
        type2tk.put(LEQ, "<=");
        type2tk.put(GEQ, ">=");
        type2tk.put(EQL, "==");
        type2tk.put(NEQ, "!=");

        type2tk.put(MAINTK, "main");
        type2tk.put(CONSTTK, "const");
        type2tk.put(INTTK, "int");
        type2tk.put(CHARTK, "char");
        type2tk.put(BREAKTK, "break");
        type2tk.put(CONTINUETK, "continue");
        type2tk.put(IFTK, "if");
        type2tk.put(ELSETK, "else");
        type2tk.put(FORTK, "for");
        type2tk.put(GETINTTK, "getint");
        type2tk.put(GETCHARTK, "getchar");
        type2tk.put(PRINTFTK, "printf");
        type2tk.put(RETURNTK, "return");
        type2tk.put(VOIDTK, "void");
    }

    public Token(TypeCode typeCode, int linePos) {
        super(String.valueOf(typeCode), new LinkedList<>());
        this.typeCode = typeCode;
        this.linePos = linePos;
    }

    public Token(TypeCode typeCode, int linePos, int intValue) {
        super(String.valueOf(typeCode), new LinkedList<>());
        this.typeCode = typeCode;
        this.linePos = linePos;
        this.intValue = intValue;
    }

    public Token(TypeCode typeCode, int linePos, String stringValue) {
        super(String.valueOf(typeCode), new LinkedList<>());
        this.typeCode = typeCode;
        this.linePos = linePos;
        this.stringValue = stringValue;
    }

    public boolean isType(TypeCode typeCode) {
        return this.typeCode == typeCode;
    }

    public int getLinePos() {
        return linePos;
    }

    public TypeCode getTypeCode() {
        return typeCode;
    }

    @Override
    public String toString() {
        if (typeCode == IDENFR || typeCode == STRCON || typeCode == CHRCON) {
            return typeCode + " " + stringValue;
        } else if (typeCode == INTCON) {
            return typeCode + " " + intValue;
        } else if (typeCode == ERR) {
            return linePos + " " + stringValue;
        } else {
            return typeCode + " " + type2tk.getOrDefault(typeCode, "Invalid TypeCode");
        }
    }

}
