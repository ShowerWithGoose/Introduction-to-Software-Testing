package frontend;

import java.util.HashMap;

public enum TokenType {
    Ident("IDENFR"),
    IntConst("INTCON"),
    StringConst("STRCON"),
    CharConst("CHRCON"),
    Main("MAINTK"),
    Const("CONSTTK"),
    Int("INTTK"),
    Char("CHARTK"),
    Break("BREAKTK"),
    Continue("CONTINUETK"),
    If("IFTK"),
    Else("ELSETK"),
    Not("NOT"),
    And("AND"),
    Or("OR"),
    For("FORTK"),
    Getint("GETINTTK"),
    Getchar("GETCHARTK"),
    Printf("PRINTFTK"),
    Return("RETURNTK"),
    Plus("PLUS"),
    Minu("MINU"),
    Void("VOIDTK"),
    Mult("MULT"),
    Div("DIV"),
    Mod("MOD"),
    Lss("LSS"),
    Leq("LEQ"),
    Gre("GRE"),
    Geq("GEQ"),
    Eql("EQL"),
    Neq("NEQ"),
    Assign("ASSIGN"),
    Semicn("SEMICN"),
    Comma("COMMA"),
    Lparent("LPARENT"),
    Rparent("RPARENT"),
    Lbrack("LBRACK"),
    Rbrack("RBRACK"),
    Lbrace("LBRACE"),
    Rbrace("RBRACE");
    // map映射
    public static HashMap<String,TokenType> IdentifierMap = new HashMap<>();
    public static HashMap<String,TokenType> SpecialCharMap = new HashMap<>();
    private String value;
    public static void makeMap(){
        // 标识符
        IdentifierMap.put("main",TokenType.Main);
        IdentifierMap.put("const",TokenType.Const);
        IdentifierMap.put("int",TokenType.Int);
        IdentifierMap.put("char",TokenType.Char);
        IdentifierMap.put("break",TokenType.Break);
        IdentifierMap.put("continue",TokenType.Continue);
        IdentifierMap.put("if",TokenType.If);
        IdentifierMap.put("else",TokenType.Else);
        IdentifierMap.put("for",TokenType.For);
        IdentifierMap.put("getint",TokenType.Getint);
        IdentifierMap.put("getchar",TokenType.Getchar);
        IdentifierMap.put("printf",TokenType.Printf);
        IdentifierMap.put("return",TokenType.Return);
        IdentifierMap.put("void",TokenType.Void);
        // 特殊字符
        SpecialCharMap.put("!",TokenType.Not);
        SpecialCharMap.put("&&",TokenType.And);
        SpecialCharMap.put("||",TokenType.Or);
        SpecialCharMap.put("+",TokenType.Plus);
        SpecialCharMap.put("-",TokenType.Minu);
        SpecialCharMap.put("*",TokenType.Mult);
        SpecialCharMap.put("/",TokenType.Div);
        SpecialCharMap.put("%",TokenType.Mod);
        SpecialCharMap.put("<",TokenType.Lss);
        SpecialCharMap.put("<=",TokenType.Leq);
        SpecialCharMap.put(">",TokenType.Gre);
        SpecialCharMap.put(">=",TokenType.Geq);
        SpecialCharMap.put("==",TokenType.Eql);
        SpecialCharMap.put("!=",TokenType.Neq);
        SpecialCharMap.put("=",TokenType.Assign);
        SpecialCharMap.put(";",TokenType.Semicn);
        SpecialCharMap.put(",",TokenType.Comma);
        SpecialCharMap.put("(",TokenType.Lparent);
        SpecialCharMap.put(")",TokenType.Rparent);
        SpecialCharMap.put("[",TokenType.Lbrack);
        SpecialCharMap.put("]",TokenType.Rbrack);
        SpecialCharMap.put("{",TokenType.Lbrace);
        SpecialCharMap.put("}",TokenType.Rbrace);
    }
    TokenType(String value) {this.value = value;}

    @Override
    public String toString() {
        return value;
    }
}
