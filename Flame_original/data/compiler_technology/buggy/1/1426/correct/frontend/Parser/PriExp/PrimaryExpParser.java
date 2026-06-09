package frontend.Parser.PriExp;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

//PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character
public class PrimaryExpParser {
    private TokenListReader reader;
    private PrimaryExpInf primaryExpInf;
    public PrimaryExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public PrimaryExp parsePrimaryExp() {
        Token token = this.reader.getnextToken();
        if(token.getType().equals(TokenType.LPARENT))
        {
            this.reader.backward(1);
            PrimaryExpExpParser primaryExpExpParser = new PrimaryExpExpParser(this.reader);
            this.primaryExpInf = primaryExpExpParser.parsePrimaryExpExp();
        }
        else if(token.getType().equals(TokenType.IDENFR))
        {
            this.reader.backward(1);
            LValParser lValParser = new LValParser(this.reader);
            this.primaryExpInf = lValParser.parseLVal();
        }
        else if(token.getType().equals(TokenType.INTCON))
        {
            this.reader.backward(1);
            NumberParser lValParser = new NumberParser(this.reader);
            this.primaryExpInf = lValParser.parseNumber();
        }
        else if(token.getType().equals(TokenType.CHRCON))
        {
            this.reader.backward(1);
            CharacterParser lValParser = new CharacterParser(this.reader);
            this.primaryExpInf = lValParser.parseCharacter();
        }
        PrimaryExp primaryExp = new PrimaryExp(this.primaryExpInf);
        return primaryExp;
    }

}
