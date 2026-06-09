package frontend.parser.expression.unaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.primaryexp.PrimaryExpParser;

import java.util.ArrayList;

public class UnaryExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    public UnaryExpEle unaryExpEle = null;
    public UnaryExpParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }
    public UnaryExp parseUnaryExp() {
        Token first = this.iterator.readNextToken();
        Token second = this.iterator.readNextToken();
        if (isIdentFirst(first, second)) {
            this.iterator.unReadToken(2);
            UnaryExpFuncParser unaryExpFuncParser = new UnaryExpFuncParser(this.iterator,this.error_tokens);
            this.unaryExpEle = unaryExpFuncParser.parseUnaryFuncExp();
        } else if (isPrimaryExpFirst(first)) {
            this.iterator.unReadToken(2);
            PrimaryExpParser primaryExpParser = new PrimaryExpParser(this.iterator,this.error_tokens);
            this.unaryExpEle = primaryExpParser.parsePrimaryExp();
        } else if (isUnaryFirst(first)) {
            this.iterator.unReadToken(2);
            UnaryExpOpParser unaryExpOpParser = new UnaryExpOpParser(this.iterator,this.error_tokens);
            this.unaryExpEle = unaryExpOpParser.parseUnaryExpOp();
        }
        UnaryExp unaryExp = new UnaryExp(this.unaryExpEle);
        return unaryExp;
    }
    public boolean isPrimaryExpFirst(Token first) {
        return first.type.equals(TokenType.LPARENT) ||
                first.type.equals(TokenType.IDENFR) ||
                first.type.equals(TokenType.INTCON) ||
                first.type.equals(TokenType.CHRCON);
    }
    public boolean isIdentFirst(Token first, Token second) {
        return first.type.equals(TokenType.IDENFR) &&
                second.type.equals(TokenType.LPARENT);
    }

    public boolean isUnaryFirst(Token first) {
        return first.type.equals(TokenType.PLUS) ||
                first.type.equals(TokenType.MINU) ||
                first.type.equals(TokenType.NOT);
    }

}
