package frontend.Lexer;

import java.util.HashMap;

/**
 * @author
 * @Description:
 * @date 2024/10/4 1:49
 */
public class TokenType {
    public static HashMap<String, String> tokenMap;
    public static HashMap<String, String> keyWord;
    public TokenType(){
        tokenMap = new HashMap<>();
        tokenMap.put("ident", "IDENFR");
        tokenMap.put("int const", "INTCON");
        tokenMap.put("string const", "STRCON");
        tokenMap.put("char const", "CHRCON");
        tokenMap.put("main", "MAINTK");
        tokenMap.put("const", "CONSTTK");
        tokenMap.put("int", "INTTK");
        tokenMap.put("char", "CHARTK");
        tokenMap.put("break", "BREAKTK");
        tokenMap.put("continue", "CONTINUETK");
        tokenMap.put("if", "IFTK");
        tokenMap.put("else", "ELSETK");
        tokenMap.put("!", "NOT");
        tokenMap.put("&&", "AND");
        tokenMap.put("||", "OR");
        tokenMap.put("for", "FORTK");
        tokenMap.put("getint", "GETINTTK");
        tokenMap.put("getchar", "GETCHARTK");
        tokenMap.put("printf", "PRINTFTK");
        tokenMap.put("return", "RETURNTK");
        tokenMap.put("+", "PLUS");
        tokenMap.put("-", "MINU");
        tokenMap.put("void", "VOIDTK");
        tokenMap.put("*", "MULT");
        tokenMap.put("/", "DIV");
        tokenMap.put("%", "MOD");
        tokenMap.put("<", "LSS");
        tokenMap.put("<=", "LEQ");
        tokenMap.put(">", "GRE");
        tokenMap.put(">=", "GEQ");
        tokenMap.put("==", "EQL");
        tokenMap.put("!=", "NEQ");
        tokenMap.put("=", "ASSIGN");
        tokenMap.put(";", "SEMICN");
        tokenMap.put(",", "COMMA");
        tokenMap.put("(", "LPARENT");
        tokenMap.put(")", "RPARENT");
        tokenMap.put("[", "LBRACK");
        tokenMap.put("]", "RBRACK");
        tokenMap.put("{", "LBRACE");
        tokenMap.put("}", "RBRACE");

        keyWord = new HashMap<>();
        keyWord.put("main", "MAINTK");
        keyWord.put("const", "CONSTTK");
        keyWord.put("int", "INTTK");
        keyWord.put("char", "CHARTK");
        keyWord.put("break", "BREAKTK");
        keyWord.put("continue", "CONTINUETK");
        keyWord.put("if", "IFTK");
        keyWord.put("else", "ELSETK");
        keyWord.put("for", "FORTK");
        keyWord.put("getint", "GETINTTK");
        keyWord.put("getchar", "GETCHARTK");
        keyWord.put("printf", "PRINTFTK");
        keyWord.put("return", "RETURNTK");
        keyWord.put("void", "VOIDTK");
    }

//    public HashMap<String, String> getTokenMap() {
//        return this.tokenMap;
//    }
}

