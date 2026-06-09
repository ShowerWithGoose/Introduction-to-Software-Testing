package fronted.parser.declaration;

import fronted.lexer.TokenList;
import fronted.lexer.TokenType;

public class Decl {
    //Decl â†’ ConstDecl | VarDecl

    private ConstDecl constDecl;

    private VarDecl varDecl;

    private int type;

    public Decl(ConstDecl constDecl) {
        this.constDecl = constDecl;
        this.varDecl = null;
        this.type = 1 ;
    }

    public Decl(VarDecl varDecl) {
        this.constDecl = null;
        this.varDecl = varDecl;
        this.type = 2;
    }

    @Override
    public String toString() {
        if (type == 1) {
            return constDecl.toString();
        } else {
            return varDecl.toString();
        }
    }

    public static Decl parse(TokenList list) {
        if (list.now().getType().equals(TokenType.Type.CONSTTK)) {
            return new Decl(ConstDecl.parse(list));
        } else {
            return new Decl(VarDecl.parse(list));
        }
    }
}
