package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExpParser;

import java.util.ArrayList;

public class ConstInitValParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* ConstInitVal Attribute */
    public ConstInitValEle constInitValEle;

    public ConstInitValParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }

    public ConstInitVal parseConstInitVal() {
        Token token = this.iterator.readNextToken();
        if (token.type.equals(TokenType.LBRACE)) { // '{'
            this.iterator.unReadToken(1);
            ConstInitValMultiParser constInitValMultiParser =
                    new ConstInitValMultiParser(this.iterator,this.error_tokens);
            this.constInitValEle = constInitValMultiParser.parseConstInitValMulti();
        } else if (token.type.equals(TokenType.STRCON)) {
            this.iterator.unReadToken(1);
            ConstInitValStringParser constInitValStringParser =
                    new ConstInitValStringParser(this.iterator,this.error_tokens);
            this.constInitValEle = constInitValStringParser.parseConstInitValString();
        } else {
            this.iterator.unReadToken(1);
            ConstExpParser constExpParser = new ConstExpParser(this.iterator,this.error_tokens);
            this.constInitValEle = constExpParser.parseConstExp();
        }
        ConstInitVal constInitVal = new ConstInitVal(this.constInitValEle);
        return constInitVal;
    }
}
