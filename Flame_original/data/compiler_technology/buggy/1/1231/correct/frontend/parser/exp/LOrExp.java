package frontend.parser.exp;

import java.util.ArrayList;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 逻辑或表达式    LOrExp == >   LAndExp { '||'  LAndExp } // a
public class LOrExp implements SyntaxNode {
    private static String name = "<LOrExp>";
    private TokenIterator tokens;

    private ArrayList<Token> operaters = new ArrayList<>();
    private ArrayList<LAndExp> lAndExps = new ArrayList<>();

    public LOrExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        int len = operaters.size();
        sb.append(lAndExps.get(0).syntaxPrinter());
        sb.append(name + "\n");
        for (int i = 0; i < len; i++) {
            sb.append(operaters.get(i).syntaxPrinter());
            sb.append(lAndExps.get(i + 1).syntaxPrinter());
            sb.append(name + "\n");
        }
        return sb.toString();
    }

    @Override
    public boolean parse() {
        LAndExp lAndExp = new LAndExp(tokens);
        lAndExp.parse();
        lAndExps.add(lAndExp);

        while (tokens.hasNext()) {
            Token token = tokens.next();
            TokenType type = token.getType();
            if (!type.equals(TokenType.OR)) {
                tokens.stepBack(1);
                break;
            }
            // AddOp
            operaters.add(token);

            // AddExp
            lAndExp = new LAndExp(tokens);
            lAndExp.parse();
            lAndExps.add(lAndExp);
        }

        return true;
    }
}
