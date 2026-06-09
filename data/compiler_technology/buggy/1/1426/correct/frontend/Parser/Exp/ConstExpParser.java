package frontend.Parser.Exp;

import frontend.TokenListReader;

public class ConstExpParser {
    private TokenListReader reader;
    private AddExp addExp;

    public ConstExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public ConstExp parseConstExp() {
        AddExpParser addExpParser = new AddExpParser(this.reader);
        this.addExp = addExpParser.parseAddExp();
        ConstExp constExp = new ConstExp(this.addExp);
        return constExp;
    }
}
