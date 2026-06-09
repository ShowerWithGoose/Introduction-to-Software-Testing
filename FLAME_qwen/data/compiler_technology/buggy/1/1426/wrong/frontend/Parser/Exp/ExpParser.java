package frontend.Parser.Exp;

import frontend.TokenListReader;

public class ExpParser {
    private TokenListReader reader;
    public ExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Exp parseExp(){
        AddExpParser addExpParser = new AddExpParser(this.reader);
        AddExp addExp = addExpParser.parseAddExp();
        Exp exp = new Exp(addExp);
        return exp;
    }
}
