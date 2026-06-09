package frontend.parser.exp.unaryexp;

import java.util.ArrayList;

import frontend.TokenIterator;
import nodes.SyntaxNode;

//	MyOpUnaryExp          == > UnaryOp UnaryExp
public class MyOpUnaryExp implements UnaryExpNode {
    private TokenIterator tokens;
    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public MyOpUnaryExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        return sb.toString();
    }

    @Override
    public boolean parse() {
        unaryOp = new UnaryOp(tokens);
        unaryOp.parse();
        children.add(unaryOp);

        unaryExp = new UnaryExp(tokens);
        unaryExp.parse();
        children.add(unaryExp);

        return true;
    }

}
