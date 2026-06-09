package frontend.parser.exp;

import java.util.ArrayList;

import frontend.TokenIterator;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

//加减表达式 		AddExp 		==> AddExp | AddExp ('+' | '−') MulExp 
public class AddExp implements SyntaxNode {
    private static String name = "<AddExp>";
    private TokenIterator tokens;

    private ArrayList<Token> operaters = new ArrayList<>();
    private ArrayList<MulExp> mulExps = new ArrayList<>();

    public AddExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        int len = operaters.size();
        sb.append(mulExps.get(0).syntaxPrinter());
        sb.append(name + "\n");
        for (int i = 0; i < len; i++) {
            sb.append(operaters.get(i).syntaxPrinter());
            sb.append(mulExps.get(i + 1).syntaxPrinter());
            sb.append(name + "\n");
        }
        return sb.toString();
    }

    @Override
    public boolean parse() {
        MulExp mulExp = new MulExp(tokens);
        mulExp.parse();
        mulExps.add(mulExp);

        while (tokens.hasNext()) {
            Token token = tokens.next();
            TokenType type = token.getType();
            if (!type.equals(TokenType.PLUS) && !type.equals(TokenType.MINU)) {
                tokens.stepBack(1);
                break;
            }
            // MulOp
            operaters.add(token);

            // MulExp
            mulExp = new MulExp(tokens);
            mulExp.parse();
            mulExps.add(mulExp);
        }

        return true;
    }

}
