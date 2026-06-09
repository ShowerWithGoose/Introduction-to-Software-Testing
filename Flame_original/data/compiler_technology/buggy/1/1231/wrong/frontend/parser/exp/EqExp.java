package frontend.parser.exp;

import java.util.ArrayList;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

public class EqExp implements SyntaxNode {

    private static String name = "<EqExp>";
    private TokenIterator tokens;

    private ArrayList<Token> operaters = new ArrayList<>();
    private ArrayList<RelExp> relExps = new ArrayList<>();

    public EqExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        int len = operaters.size();
        sb.append(relExps.get(0).syntaxPrinter());
        sb.append(name + "\n");
        for (int i = 0; i < len; i++) {
            sb.append(operaters.get(i).syntaxPrinter());
            sb.append(relExps.get(i + 1).syntaxPrinter());
            sb.append(name + "\n");
        }
        return sb.toString();
    }

    @Override
    public boolean parse() {
        RelExp relExp = new RelExp(tokens);
        relExp.parse();
        relExps.add(relExp);

        while (tokens.hasNext()) {
            Token token = tokens.next();
            TokenType type = token.getType();
            if (!type.equals(TokenType.EQL) && !type.equals(TokenType.NEQ)) {
                tokens.stepBack(1);
                break;
            }
            // RelOp
            operaters.add(token);

            // RelExp
            relExp = new RelExp(tokens);
            relExp.parse();
            relExps.add(relExp);
        }

        return true;
    }
}
