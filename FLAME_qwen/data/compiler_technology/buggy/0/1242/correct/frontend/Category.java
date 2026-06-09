package frontend;

import java.util.Scanner;

public enum Category {

    IDENFR("[_A-Za-z]+[0-9]?",false),
    INTCON("[1-9][0-9]+|[0-9]",false),
    STRCON("\\\"([^\\\\\\\'\\\"]|(\\\\[abtnvf\\\"\\\'\\\\0]))*\\\"",false),
    ASTRCON("\\\"([^\\\"\\\'\\\\]|\\\\n)*\\\"",false),
    CHRCON("\\\'([^\\\\\\\'\\\"]|(\\\\[abtnvf\\\"\\\'\\\\0]))\\\'",false),
    MAINTK("main",true),
    CONSTTK("const",true),
    INTTK("int",true),
    CHARTK("char",true),
    BREAKTK("break",true),
    CONTINUETK("continue",true),
    IFTK("if",true),
    ELSETK("else",true),
    NOT("!",false),
    AND("&&",false),
    OR("||",false),
    FORTK("for",true),
    GETINTTK("getint",true),
    GETCHARTK("getchar",true),
    PRINTFTK("printf",true),
    RETURNTK("return",true),
    PLUS("+",false),
    MINU("-",false),
    VOIDTK("void",true),
    MULT("*",false),
    DIV("/",false),
    MOD("%",false),
    LSS("<",false),
    LEQ("<=",false),
    GRE(">",false),
    GEQ(">=",false),
    EQL("==",false),
    NEQ("!=",false),
    ASSIGN("=",false),
    SEMICN(";",false),
    COMMA(",",false),
    LPARENT("(",false),
    RPARENT(")",false),
    LBRACK("[",false),
    RBRACK("]",false),
    LBRACE("{",false),
    RBRACE("}",false);

    private final String value;

    private final boolean reserved;
    Category(String value,boolean reserved) {
        this.value = value;
        this.reserved = reserved;
    }

    public String GetValue() {
        return this.value;
    }




    public static class Main {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
            String line = scanner.nextLine();
            System.out.println(line);
            char a = line.charAt(0);
            System.out.println((int)a);
            for (Category category : Category.values()) {
                System.out.println(category.GetValue());
            }
        }
    }
}
