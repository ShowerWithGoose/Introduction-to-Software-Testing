package frontend.parser.exp.primaryexp;

import frontend.TokenIterator;
import frontend.parser.exp.unaryexp.UnaryExpNode;
import nodes.Token;
import utils.Utils;

// 基本表达式		PrimaryExp     ==> MyParenPrimaryExp | LVal | Number | Character
public class PrimaryExp implements UnaryExpNode {
    private static String name = "<PrimaryExp>";
    private TokenIterator tokens;

    public PrimaryExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    private PrimaryExpNode primaryExpNode;

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        sb.append(primaryExpNode.syntaxPrinter());
        sb.append(name + "\n");
        return sb.toString();
    }

    @Override
    public boolean parse() {
        Token token = tokens.next();
        tokens.stepBack(1);
        switch (token.getType()) {
            case LPARENT:
                primaryExpNode = new MyParenPrimaryExp(tokens);
                break;
            case IDENFR:
                primaryExpNode = new LVal(tokens);
                break;
            case INTCON:
                primaryExpNode = new Number(tokens);
                break;
            case CHRCON:
                primaryExpNode = new Character(tokens);
                break;
            default:
                Utils.aaaaAssert(false);
                break;
        }
        return primaryExpNode.parse();
    }

}
