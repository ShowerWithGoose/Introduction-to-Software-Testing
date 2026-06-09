package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;

import java.util.ArrayList;

public class UnaryExpOpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* UnaryExpOp Attributes */
    public UnaryOp unaryOp;
    public UnaryExp unaryExp;

    public UnaryExpOpParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public UnaryExpOp parseUnaryExpOp() {
        UnaryOpParser unaryOpParser = new UnaryOpParser(this.iterator,this.error_tokens);
        this.unaryOp = unaryOpParser.parseUnaryOp();
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.iterator,this.error_tokens);
        this.unaryExp = unaryExpParser.parseUnaryExp();
        UnaryExpOp unaryExpOp = new UnaryExpOp(this.unaryOp, this.unaryExp);
        return unaryExpOp;
    }
}
