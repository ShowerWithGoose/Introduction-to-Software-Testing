package frontend.Parser.Exp;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

import java.util.ArrayList;

//RelExp â†’ AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
public class RelExpParser {
    private TokenListReader reader;
    private AddExp first = null;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<AddExp> others = new ArrayList<>();

    public RelExpParser(TokenListReader reader) {
        this.reader = reader;
    }
    public RelExp parseRelExp() {
        this.ops = new ArrayList<>();
        this.others = new ArrayList<>();
        AddExpParser addExpParser = new AddExpParser(this.reader);
        first = addExpParser.parseAddExp();
        Token token = this.reader.getnextToken();
        while(token.getType().equals(TokenType.LSS)||token.getType().equals(TokenType.GRE)||token.getType().equals(TokenType.LEQ)||token.getType().equals(TokenType.GEQ)) {
            this.ops.add(token);
            this.others.add(addExpParser.parseAddExp());
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        return new RelExp(this.first, this.ops, this.others);
    }

}
