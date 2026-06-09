package frontend.parser.exp;

import frontend.TokenIterator;
import frontend.parser.decl.constdecl.constinitval.ConstInitValNode;

//常量表达式		ConstExp 		==> AddExp 注：使用的 Ident 必须是常量 
public class ConstExp implements ConstInitValNode {
    private static String name = "<ConstExp>";
    private TokenIterator tokens;

    private AddExp addExp;

    public ConstExp(TokenIterator tokens) {
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
