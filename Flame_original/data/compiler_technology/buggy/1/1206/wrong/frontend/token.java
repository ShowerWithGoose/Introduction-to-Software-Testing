package frontend;

/**
 * @author
 * @Description:
 * @date 2024/9/23 10:19
 */
public class token {

    public enum Type {//类型的枚举类
        IDENFR,      // Ident
        IFTK,        // if
        ELSETK,      // else
        VOIDTK,      // void
        SEMICN,      // ;
        INTCON,      // IntConst
        NOT,         // !
        MULT,        // *
        COMMA,       // ,
        STRCON,      // StringConst
        AND,         // &&
        DIV,         // /
        LPARENT,     // (
        CHRCON,      // CharConst
        OR,          // ||
        MOD,         // %
        RPARENT,     // )
        MAINTK,      // main
        FORTK,       // for
        LSS,         // <
        LBRACK,      // [
        CONSTTK,     // const
        GETINTTK,    // getint
        LEQ,         // <=
        RBRACK,      // ]
        INTTK,       // int
        GETCHARTK,   // getchar
        GRE,         // >
        GEQ,         // >=
        LBRACE,      // {
        RBRACE,      // }
        RETURNTK,    // return
        BREAKTK,     // break
        PRINTFTK,    // printf
        EQL,         // ==
        CONTINUETK,  // continue
        CHARTK,      // char
        PLUS,        // +
        NEQ,         // !=
        MINU,        // -
        ASSIGN,      // =
        disable

    }
    public enum wrongType{
        a,b,c,d,e,f,g,h,i,j,k,l,m,none
    }
    public Type type;//字符类型
    public String content;//内容
    public String src;//所在文件位置
    public int lineno;//行号
    public boolean wrong;//是否错误
    public wrongType wType;//错误类型
    public token(Type assign, String s,int lineno) {
        this.type=assign;
        this.content=s;
        this.lineno=lineno;
        this.wrong=false;
        this.wType=wrongType.none;
    }
    public token(Type assign, String s,int lineno,boolean w,wrongType wt) {
        this.type=assign;
        this.content=s;
        this.lineno=lineno;
        this.wrong=w;
        this.wType=wt;
    }

    @Override
   // public String toString() { return this.type + " " + this.content+" "+this.lineno+' '+this.wrong+" "+this.wType; }
    public String toString() { return this.type + " " + this.content; }
}
