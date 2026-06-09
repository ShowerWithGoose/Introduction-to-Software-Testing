package fronened.Parser;

import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class Decl {
    private ConstDecl constDecl;
    private VarDecl varDecl;


    public Decl(ConstDecl constDecl, VarDecl varDecl) {
        this.constDecl = constDecl;
        this.varDecl = varDecl;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        if (constDecl != null) {
            sb.append(constDecl.print());
        }
        if (varDecl != null) {
            sb.append(varDecl.print());
        }
        return sb.toString();
    }

    public static Decl parse(TokenIterator iterator) {
        Token token = iterator.next();
        ConstDecl constDecl = null;
        VarDecl varDecl = null;
        if (token.getType().equals(Token.Type.CONSTTK)) {
            iterator.back();
            constDecl = ConstDecl.parser(iterator);
        }
        else {
            iterator.back();
            varDecl = VarDecl.parse(iterator);
        }
        return new Decl(constDecl, varDecl);
    }
}
