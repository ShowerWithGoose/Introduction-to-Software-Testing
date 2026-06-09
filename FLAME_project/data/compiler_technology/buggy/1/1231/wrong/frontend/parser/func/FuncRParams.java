package frontend.parser.func;

import java.util.ArrayList;

import frontend.TokenIterator;
import frontend.parser.exp.Exp;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 函数实参表		FuncRParams     == > Exp { ',' Exp }
public class FuncRParams implements SyntaxNode {
    private final String name = "<FuncRParams>";
    private TokenIterator tokens;

    public FuncRParams(TokenIterator tokens) {
        this.tokens = tokens;
    }

    private ArrayList<SyntaxNode> children = new ArrayList<>();

    private ArrayList<Exp> exps = new ArrayList<>();

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        children.forEach(child -> sb.append(child.syntaxPrinter()));
        sb.append(name + "\n");
        return sb.toString();
    }

    @Override
    public boolean parse() {
        Exp exp = new Exp(tokens);
        exp.parse();
        children.add(exp);
        exps.add(exp);

        while (tokens.hasNext()) {
            Token token = tokens.next();
            if (token.getType().equals(TokenType.COMMA)) {
                children.add(token);

                exp = new Exp(tokens);
                exp.parse();
                children.add(exp);
                exps.add(exp);
            } else {
                tokens.stepBack(1);
                break;
            }
        }

        return true;
    }

}
