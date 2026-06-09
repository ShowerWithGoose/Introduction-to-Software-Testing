package Lexer;

/**
 * <p>Project: Compiler - Token
 * <p>Powered by berry On 2024-09-20
 *
 * @author
 * @version 1.0
 */
public class Token {
    public enum Type{
        //类别码(单词名称),42个
        IDENFR("Ident"),//Type t=Type.IDENFR;System.out.print(t);打印单词名称
        ELSETK("else"),
        VOIDTK("void"),
        SEMICN(";"),
        INTCON("IntConst"),
        NOT("!"),
        MULT("*"),
        COMMA(","),
        STRCON("StringConst"),
        AND("&&"),
        DIV("/"),
        LPARENT("("),
        RPARENT(")"),
        CHRCON("CharConst"),
        OR("||"),
        MOD("%"),
        LBRACK("["),
        RBRACK("]"),
        MAINTK("main"),
        FORTK("for"),
        CONSTTK("const"),
        GETINTTK("getint"),
        LEQ("<="),
        LSS("<"),
        LBRACE("{"),
        RBRACE("}"),
        INTTK("int"),
        GETCHARTK("getchar"),
        GRE(">"),
        GEQ(">="),
        EQL("=="),
        BREAKTK("break"),
        CONTINUETK("continue"),
        IFTK("if"),
        PLUS("+"),
        NEQ("!="),
        ASSIGN("="),
        MINU("-"),
        PRINTFTK("printf"),
        RETURNTK("return"),
        CHARTK("char"),
        NONE("none");//不是保留字返回NONE
        private String value;

        Type(String value) {
            this.value = value;
        }

        public String getValue() {
            return value;
        }
    }
    public Type type;
    public String content;
    public int lineno;
    public long digitnum;
    public Token(Type type,String content, int lineno) {
        this.content = content;
        this.lineno = lineno;
        this.digitnum = -1;//初始化-1说明不是digit
        this.type = type;
    }
    public String getOutput(){
        return type+" "+content+"\n";
    }
}
