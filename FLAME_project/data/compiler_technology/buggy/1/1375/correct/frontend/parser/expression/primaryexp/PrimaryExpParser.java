package frontend.parser.expression.primaryexp;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;

import java.util.ArrayList;

public class PrimaryExpParser {
    public TokenListIterator iterator;
    public ArrayList<Token> error_tokens;
    /* PrimaryExp Attributes */
    public PrimaryExpEle primaryExpEle;

    public PrimaryExpParser(TokenListIterator iterator, ArrayList<Token> error_tokens) {
        this.error_tokens = error_tokens;
        this.iterator = iterator;
    }

    public PrimaryExp parsePrimaryExp() {
        Token token = this.iterator.readNextToken();
        if (token.type.equals(TokenType.LPARENT)) { // '('
            this.iterator.unReadToken(1);
            PrimaryExpExpParser primaryExpExpParser = new PrimaryExpExpParser(this.iterator,this.error_tokens);
            this.primaryExpEle = primaryExpExpParser.parsePrimaryExpExp();
        } else if (token.type.equals(TokenType.IDENFR)) { // IDENFR
            this.iterator.unReadToken(1);
            LValParser lvalParser = new LValParser(this.iterator,this.error_tokens);
            this.primaryExpEle = lvalParser.parseLVal();
        } else if (token.type.equals(TokenType.INTCON)) { // INT
            this.iterator.unReadToken(1);
            NumberParser numberParser = new NumberParser(this.iterator,this.error_tokens);
            this.primaryExpEle = numberParser.parseNumber();
        }
        else if (token.type.equals(TokenType.CHRCON)) {
            this.iterator.unReadToken(1);
            CharacterParser characterParser = new CharacterParser(this.iterator,this.error_tokens);
            this.primaryExpEle = characterParser.parseCharacter();
        }
        PrimaryExp primaryExp = new PrimaryExp(this.primaryExpEle);
        return primaryExp;
    }
}
