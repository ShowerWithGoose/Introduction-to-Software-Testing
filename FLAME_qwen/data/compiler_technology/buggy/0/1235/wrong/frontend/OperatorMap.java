package frontend;

import java.util.HashMap;

public class OperatorMap {
    private static final HashMap<String, String>  OPERATORS = new HashMap<>();

    static {
        OPERATORS.put("!", "NOT");
        OPERATORS.put("&&", "AND");
        OPERATORS.put("||", "OR");
        OPERATORS.put("+", "PLUS");
        OPERATORS.put("-", "MINU");
        OPERATORS.put("*", "MULT");
        OPERATORS.put("/", "DIV");
        OPERATORS.put("%", "MOD");
        OPERATORS.put("<", "LSS");
        OPERATORS.put("<=", "LEQ");
        OPERATORS.put(">", "GRE");
        OPERATORS.put(">=", "GEQ");
        OPERATORS.put("==", "EQL");
        OPERATORS.put("!=", "NEQ");
        OPERATORS.put("=", "ASSIGN");
        OPERATORS.put(";", "SEMICN");
        OPERATORS.put(",", "COMMA");
        OPERATORS.put("(", "LPARENT");
        OPERATORS.put(")", "RPARENT");
        OPERATORS.put("[", "LBRACK");
        OPERATORS.put("]", "RBRACK");
        OPERATORS.put("{", "LBRACE");
        OPERATORS.put("}", "RBRACE");
    }
    public OperatorMap(){
    }
    public String getOperatorType(String keyword){
        return OPERATORS.get(keyword);
    }

    public boolean isOperator(String word){
        return OPERATORS.containsKey(word);
    }
}
