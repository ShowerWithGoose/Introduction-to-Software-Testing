package frontend.parser.cst;

import java.math.BigInteger;

public class NumberNode extends CSTNode {
    public static final NumberNode Zero = new NumberNode(BigInteger.ZERO);
    public static final NumberNode Infinity = new NumberNode(new BigInteger("9223372036854775807"));

    private BigInteger num;

    @Override
    public void addChild(CSTNode node) {
        super.addChild(node);
        if (node instanceof TokenNode) {
            String content = ((TokenNode) node).getContent();
            this.num = new BigInteger(content);
        }
    }

    public NumberNode(){}

    public NumberNode(BigInteger num) {
        this.num = num;
    }
}