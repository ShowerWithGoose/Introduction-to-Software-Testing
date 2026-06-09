package frontend.parser.decl.constdecl;

import frontend.TokenIterator;
import frontend.parser.decl.StringConst;
import frontend.parser.decl.constdecl.constinitval.ConstInitValNode;
import frontend.parser.decl.constdecl.constinitval.MyMultiConstInitVal;
import frontend.parser.exp.ConstExp;
import nodes.SyntaxNode;
import nodes.TokenType;

// ConstInitVal == > ConstExp | MyMultiConstInitVal | StringConst
public class ConstInitVal implements SyntaxNode {
    private static String name = "<ConstInitVal>";
    private TokenIterator tokens;
    private ConstInitValNode constInitValNode;

    public ConstInitVal(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return constInitValNode.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        TokenType type = tokens.next().getType();
        tokens.stepBack(1);
        switch (type) {
            case LBRACE:
                constInitValNode = new MyMultiConstInitVal(tokens);
                break;
            case STRCON:
                constInitValNode = new StringConst(tokens);
                break;
            default:
                constInitValNode = new ConstExp(tokens);
                break;
        }
        return constInitValNode.parse();
    }

}
