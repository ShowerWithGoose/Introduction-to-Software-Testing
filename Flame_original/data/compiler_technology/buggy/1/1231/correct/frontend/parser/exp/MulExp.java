package frontend.parser.exp;

import java.util.ArrayList;

import frontend.TokenIterator;
import frontend.parser.exp.unaryexp.UnaryExp;
import nodes.SyntaxNode;
import nodes.Token;
import nodes.TokenType;

// 乘除模表达式  MulExp  == >  UnaryExp { ('*' | '/' | '%')  UnaryExp }
public class MulExp implements SyntaxNode {
    private static String name = "<MulExp>";
    private TokenIterator tokens;

    private ArrayList<Token> operaters = new ArrayList<>();
    private ArrayList<UnaryExp> unaryExps = new ArrayList<>();

    public MulExp(TokenIterator tokens) {
        this.tokens = tokens;
    }

    @Override
    public String syntaxPrinter() {
        StringBuilder sb = new StringBuilder();
        int len = operaters.size();
        sb.append(unaryExps.get(0).syntaxPrinter());
        sb.append(name + "\n");
        for (int i = 0; i < len; i++) {
            sb.append(operaters.get(i).syntaxPrinter());
            sb.append(unaryExps.get(i + 1).syntaxPrinter());
            sb.append(name + "\n");
        }

        return sb.toString();
    }

    @Override
    public boolean parse() {
        UnaryExp unaryExp = new UnaryExp(tokens);
        unaryExp.parse();
        unaryExps.add(unaryExp);

        while (tokens.hasNext()) {
            Token token = tokens.next();
            TokenType type = token.getType();
            if (!type.equals(TokenType.MULT) && !type.equals(TokenType.DIV)
                    && !type.equals(TokenType.MOD)) {
                tokens.stepBack(1);
                break;
            }
            // UnaryOp
            operaters.add(token);

            // UnaryExp
            unaryExp = new UnaryExp(tokens);
            unaryExp.parse();
            unaryExps.add(unaryExp);
        }

        return true;
    }

}
