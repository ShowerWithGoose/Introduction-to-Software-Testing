package frontend.parser.decl.vardecl;

import frontend.TokenIterator;
import frontend.parser.decl.StringConst;
import frontend.parser.exp.Exp;
import nodes.SyntaxNode;
import nodes.TokenType;

// 变量初值 InitVal == > Exp | MyMultiInitVal | StringConst
public class InitVal implements SyntaxNode {
    private static String name = "<InitVal>";
    private TokenIterator tokens;
    private InitValNode initValNode;

    public InitVal(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        return initValNode.syntaxPrinter() + name + "\n";
    }

    @Override
    public boolean parse() {
        TokenType type = tokens.next().getType();
        tokens.stepBack(1);
        switch (type) {
            case LBRACE:
                initValNode = new MyMultiInitVal(tokens);
                break;
            case STRCON:
                initValNode = new StringConst(tokens);
                break;
            default:
                initValNode = new Exp(tokens);
                break;
        }
        return initValNode.parse();
    }

}
