package frontend.parser.expression.multiexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.unaryexp.UnaryExp;
import frontend.parser.expression.unaryexp.UnaryExpParser;

import java.util.ArrayList;

public class MulExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* MulExp Attributes */
    public UnaryExp first = null;
    public ArrayList<Token> operators = new ArrayList<>();
    public ArrayList<UnaryExp> operands = new ArrayList<>();

    public MulExpParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public MulExp parseMulExp() {
        this.operators = new ArrayList<>();
        this.operands = new ArrayList<>();
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.iterator,this.error_tokens);
        this.first = unaryExpParser.parseUnaryExp();
        Token token = this.iterator.readNextToken();
        while (token.type.equals(TokenType.MULT) ||
                token.type.equals(TokenType.DIV) ||
                token.type.equals(TokenType.MOD)) {
            /* token -> * / % */
            this.operators.add(token);
            UnaryExpParser unaryExpParser1 = new UnaryExpParser(this.iterator,this.error_tokens);
            this.operands.add(unaryExpParser1.parseUnaryExp());
            token = this.iterator.readNextToken();
        }
        this.iterator.unReadToken(1);
        MulExp mulExp = new MulExp(this.first, this.operators, this.operands);
        return mulExp;
    }
}
