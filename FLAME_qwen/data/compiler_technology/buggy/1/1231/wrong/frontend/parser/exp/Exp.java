package frontend.parser.exp;

import frontend.TokenIterator;
import frontend.parser.decl.vardecl.InitValNode;

/* 
表达式		    Exp            ==> AddExp 
*/
public class Exp implements InitValNode {
    private static String name = "<Exp>";
    private TokenIterator tokens;

    private AddExp addExp;

    public Exp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return addExp.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        addExp = new AddExp(tokens);
        if (addExp.parse()) {
            return true;
        }
        return false;
    }

}
