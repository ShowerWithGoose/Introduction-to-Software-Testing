package frontend.parser.declaration.constant.constinitval;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.expression.ConstExp;
import frontend.parser.expression.ConstExpParser;

import java.util.ArrayList;

public class ConstInitValMultiParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* ConstInitMulti Attributes */
    public Token leftBrace = null; // '{'
    public ConstExp first = null; // MAY exist
    public ArrayList<Token> commas = new ArrayList<>(); // MAY exist
    public ArrayList<ConstExp> constExps = new ArrayList<>(); // MAY exist
    public Token rightBrace = null; // '}'

    public ConstInitValMultiParser(TokenListIterator iterator,ArrayList<Token> error_tokens) {
        this.iterator = iterator;
        this.error_tokens = error_tokens;
    }

    public ConstInitValMulti parseConstInitValMulti() {
        this.leftBrace = this.iterator.readNextToken();
        if (!this.leftBrace.type.equals(TokenType.LBRACE)) {
            System.out.println("EXPECT LBRACE HERE");
        }
        Token token = this.iterator.readNextToken();
        if (!token.type.equals(TokenType.RBRACE)) {
            this.iterator.unReadToken(1);
            ConstExpParser constExpParser = new ConstExpParser(this.iterator,this.error_tokens);
            this.first = constExpParser.parseConstExp();
            token = this.iterator.readNextToken();
            while (token.type.equals(TokenType.COMMA)) { // ','
                this.commas.add(token);
                ConstExpParser constExpParser1 = new ConstExpParser(this.iterator,this.error_tokens);
                this.constExps.add(constExpParser1.parseConstExp());
                token = this.iterator.readNextToken();
            }
            this.iterator.unReadToken(1);
        } else {
            this.iterator.unReadToken(1);
        }
        this.rightBrace = this.iterator.readNextToken();
        ConstInitValMulti constInitValMulti = new ConstInitValMulti(this.leftBrace,
                this.first, this.commas, this.constExps, this.rightBrace);
        return constInitValMulti;
    }
}
