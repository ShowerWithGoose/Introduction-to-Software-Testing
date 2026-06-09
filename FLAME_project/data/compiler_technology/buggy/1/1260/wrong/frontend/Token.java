package frontend;

import java.io.FileWriter;
import java.io.IOException;

public class Token {
    enum LexType {
        MAINTK("main"), CONSTTK("const"),
        INTTK("int"), CHARTK("char"),
        BREAKTK("break"), CONTINUETK("continue"),
        IFTK("if"), ELSETK("else"),
        FORTK("for"), GETINTTK("getint"),
        GETCHARTK("getchar"), PRINTFTK("printf"),
        RETURNTK("return"), VOIDTK("void"),
        IDENFR(""), MOD("%"),
        INTCON(""),STRCON(""),
        CHRCON(""),
        PLUS("+"), MINU("-"),
        MULT("*"), DIV("/"),

        LEQ("<="), LSS("<"),
        GEQ(">="), GRE(">"),
        ASSIGN("="), EQL("=="),
        NEQ("!="), NOT("!"),
        SEMICN(";"), COMMA(","),
        LPARENT("("), RPARENT(")"),
        LBRACK("["), RBRACK("]"),
        LBRACE("{"), RBRACE("}"),
        AND("&&"), OR("||");
        private String name;
        LexType(String name){
            this.name = name;
        }
        LexType(){}

        public String getName() {
            return name;
        }
        public void setName(String name) {
            this.name = name;
        }
        public static LexType fromTypeName(String typeName) {
            for (LexType type : LexType.values()) {
                if (type.getName().equals(typeName)) {
                    return type;
                }
            }
            return IDENFR;
        }
    }
    String content;
    int lineNum;
    LexType type;
    public Token(StringBuilder content, int lineNum) {
        this.content = content.toString();
        this.lineNum = lineNum;
        this.type = LexType.fromTypeName(content.toString());
    }

    public Token(LexType type, StringBuilder content, int lineNum) {
        this.type = type;
        this.content = content.toString();
        this.lineNum = lineNum;
    }

    public LexType getType() {
        return type;
    }

    public String getContent() {
        return content.toString();
    }
    public void print(){
        try (FileWriter fw = new FileWriter("parser.txt",true)){
            fw.write(this.type.toString() + " "+ this.getContent() + "\n");
        }catch (IOException e) {
            e.printStackTrace();
        }
    }
}
