package frontend.parser.exp;

import java.util.ArrayList;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 逻辑与表达式     LAndExp == >   EqExp { '&&'  EqExp } // a
public class LAndExp implements SyntaxNode {
    private static String name = "<LAndExp>";
    private TokenIterator tokens;

    private ArrayList<Token> operaters = new ArrayList<>();
    private ArrayList<EqExp> eqExps = new ArrayList<>();

    public LAndExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        int len = operaters.size();
        sb.append(eqExps.get(0).syntaxPrinter());
        sb.append(name + "\n");
        for (int i = 0; i < len; i++) {
            sb.append(operaters.get(i).syntaxPrinter());
            sb.append(eqExps.get(i + 1).syntaxPrinter());
            sb.append(name + "\n");
        }
        return sb.toString();
    }

    @Override
    public boolean parse() {
        EqExp eqExp = new EqExp(tokens);
        eqExp.parse();
        eqExps.add(eqExp);

        while (tokens.hasNext()) {
            Token token = tokens.next();
            TokenType type = token.getType();
            if (type != TokenType.AND) {
                tokens.stepBack(1);
                break;
            }
            // EqOp
            operaters.add(token);

            // EqExp
            eqExp = new EqExp(tokens);
            eqExp.parse();
            eqExps.add(eqExp);
        }

        return true;
    }

}
