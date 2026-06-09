package FrontEnd;

import java.util.HashMap;

public class Token {
    private String tokenClass="";
    private String oringinStr="";
    private String tokenCode="";
    private Long intValue;
    private int lineNum;
    //get typeCode from type
    private static HashMap<String, String> CodeMap=new HashMap<>();
    /*Init CodeMap*/
    static{
        // 将所有的标识符和值放入HashMap中
        CodeMap.put("Ident", "IDENFR");
        CodeMap.put("else", "ELSETK");
        CodeMap.put("void", "VOIDTK");
        CodeMap.put(";", "SEMICN");
        CodeMap.put("IntConst", "INTCON");
        CodeMap.put("!", "NOT");
        CodeMap.put("*", "MULT");
        CodeMap.put(",", "COMMA");
        CodeMap.put("StringConst", "STRCON");
        CodeMap.put("&&", "AND");
        CodeMap.put("/", "DIV");
        CodeMap.put("(", "LPARENT");
        CodeMap.put("CharConst", "CHRCON");
        CodeMap.put("||", "OR");
        CodeMap.put("%", "MOD");
        CodeMap.put(")", "RPARENT");
        CodeMap.put("main", "MAINTK");
        CodeMap.put("for", "FORTK");
        CodeMap.put("<", "LSS");
        CodeMap.put("[", "LBRACK");
        CodeMap.put("const", "CONSTTK");
        CodeMap.put("getint", "GETINTTK");
        CodeMap.put("<=", "LEQ");
        CodeMap.put("]", "RBRACK");
        CodeMap.put("int", "INTTK");
        CodeMap.put("getchar", "GETCHARTK");
        CodeMap.put(">", "GRE");
        CodeMap.put("{", "LBRACE");
        CodeMap.put("char", "CHARTK");
        CodeMap.put("printf", "PRINTFTK");
        CodeMap.put(">=", "GEQ");
        CodeMap.put("}", "RBRACE");
        CodeMap.put("break", "BREAKTK");
        CodeMap.put("return", "RETURNTK");
        CodeMap.put("==", "EQL");
        CodeMap.put("continue", "CONTINUETK");
        CodeMap.put("+", "PLUS");
        CodeMap.put("!=", "NEQ");
        CodeMap.put("if", "IFTK");
        CodeMap.put("-", "MINU");
        CodeMap.put("=", "ASSIGN");
    }

    public Token(String origin,int lineNum,String tokenClass)
    {
        this.oringinStr=origin;
        this.lineNum=lineNum;
        this.tokenClass=tokenClass;
        this.tokenCode=CodeMap.get(this.tokenClass);
        if(this.tokenClass.equals("IntConst"))
        {
            this.intValue=Long.parseLong(oringinStr);
        }
    }
    public int getLineNum()
    {
        return this.lineNum;
    }
    public String getOringinStr()
    {
        return this.oringinStr;
    }
    public String getTokenClass()
    {
        return this.tokenClass;
    }
    public String getTokenCode()
    {
        return this.tokenCode;
    }
}
