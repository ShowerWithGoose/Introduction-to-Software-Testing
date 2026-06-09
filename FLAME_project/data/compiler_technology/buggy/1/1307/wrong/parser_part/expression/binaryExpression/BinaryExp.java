package parser_part.expression.binaryExpression;

import lexer_part.Token;
import parser_part.expression.Computable;
import parser_part.expression.unaryExpression.UnaryExp;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class BinaryExp<T extends Computable> implements Computable {
    protected T first;
    protected ArrayList<Token> ops;
    protected ArrayList<T> expressions;
    private final String name;
    private int computeVal;

    public BinaryExp(T first, ArrayList<Token> ops, ArrayList<T> expressions, String name) {
        this.first = first;
        this.ops = ops;
        this.expressions = expressions;
        this.name = name;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder(first.toString());
        sb.append(name).append("\n");
        if (ops.size() == expressions.size()) {
            int len = expressions.size();
            for (int i = 0; i < len; i++) {
                sb.append(ops.get(i).toString());
                sb.append(expressions.get(i).toString());
                sb.append(name).append("\n");
            }
        }
        return sb.toString();
    }

    public T getFirst() {
        return first;
    }

    public int compute(SymbolList symbolList) {
        int ans = 0;
        Token op = ops.get(0);
        // MulExp
        if (first instanceof UnaryExp unaryExp) {
            ans = unaryExp.compute(symbolList);
            for (int i = 0; i < ops.size(); i++) {
                if (ops.get(i).getType() == Token.TokenType.MULT) {
                    ans *= expressions.get(i).compute(symbolList);
                } else if (ops.get(i).getType() == Token.TokenType.DIV) {
                    ans /= expressions.get(i).compute(symbolList);
                } else if (ops.get(i).getType() == Token.TokenType.MOD) {
                    ans %= expressions.get(i).compute(symbolList);
                }
            }
        }
        // AddExp
        else if (first instanceof MulExp mulExp) {
            ans = mulExp.compute(symbolList);
            for (int i = 0; i < ops.size(); i++) {
                if (ops.get(i).getType() == Token.TokenType.PLUS) {
                    ans += expressions.get(i).compute(symbolList);
                } else if (ops.get(i).getType() == Token.TokenType.MINU) {
                    ans -= expressions.get(i).compute(symbolList);
                }
            }
        }
        return ans;
    }

    @Override
    public Symbol.SymbolType getSymbolType() {
        return first.getSymbolType();
    }
}
