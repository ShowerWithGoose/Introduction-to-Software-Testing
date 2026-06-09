public class Token {
    private final Type type;
    private final String content;
    private final int line;

    private final Cate cate;
    public Token(Type type ,String content,int line) {
        this.line = line;
        this.type = type;
        this.content = content;

         if(type == Type.KEYWORD) {
            this.cate = Cate.KEY_WORD;
        }
        else if(type == Type.SEMICN||type == Type.COMMA||type == Type.LBRACE
        ||type == Type.RBRACE || type== Type.LPARENT||type==Type.RPARENT||
        type== Type.LBRACK ||type==Type.RBRACK) {
            this.cate = Cate.BREAK;
        }
        else if(type == Type.INTCON ||type == Type.STRCON || type == Type.CHRCON) {
            this.cate = Cate.CON;
        }
        else {
            this.cate = Cate.OPERATOR;
        }
    }

    public enum Type {
        KEYWORD,INTCON,IDENFR,STRCON,CHRCON,
        AND,NOT,OR,PLUS,MINU,MULT,DIV,MOD,LSS,LEQ,GRE,GEQ,
        EQL,NEQ,ASSIGN,SEMICN,COMMA,LPARENT,RPARENT,LBRACK,RBRACK,
        LBRACE,RBRACE,NAME
    }

    public enum Cate {
        ERROR,KEY_WORD,CON,OPERATOR,BREAK
    }
    public Type getType() {
        return this.type;
    }

    public String getContent() {
        return this.content;
    }

    public String getCate() {
        return cate.toString();
    }

    public int getLine() {
        return this.line;
    }
}
