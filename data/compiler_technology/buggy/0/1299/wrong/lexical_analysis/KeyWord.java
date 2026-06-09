package lexical_analysis;
import java.util.HashMap;

public class KeyWord {
    public static HashMap<String, String> keyWordMap = new HashMap<>(){{
        put("Ident", "IDENFR");
        put("IntConst", "INTCON");
        put("StringConst", "STRCON");
        put("CharConst", "CHRCON");
        put("main", "MAINTK");
        put("const", "CONSTTK");
        put("int", "INTTK");
        put("char", "CHARTK");
        put("break", "BREAKTK");
        put("continue", "CONTINUETK");
        put("if", "IFTK");
        put("else", "ELSETK");
        put("!", "NOT");
        put("&&", "AND");
        put("||", "OR");
        put("for", "FORTK");
        put("getint", "GETINTTK");
        put("getchar", "GETCHARTK");
        put("printf", "PRINTFTK");
        put("return", "RETURNTK");
        put("+", "PLUS");
        put("-", "MINU");
        put("void", "VOIDTK");
        put("*", "MULT");
        put("/", "DIV");
        put("%", "MOD");
        put("<", "LSS");
        put("<=", "LEQ");
        put(">", "GRE");
        put(">=", "GEQ");
        put("==", "EQL");
        put("!=", "NEQ");
        put("=", "ASSIGN");
        put(";", "SEMICN");
        put(",", "COMMA");
        put("(", "LPARENT");
        put(")", "RPARENT");
        put("[", "LBRACK");
        put("]", "RBRACK");
        put("{", "LBRACE");
        put("}", "RBRACE");
    }};
}
