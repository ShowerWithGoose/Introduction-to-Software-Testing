package frontend.Parser.Exp;

import frontend.TokenListReader;

public class CondParser {
    private TokenListReader reader;
    public CondParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Cond parseCond() {
        LOrExpParser lorExpParser = new LOrExpParser(this.reader);
        LOrExp lorExp = lorExpParser.parseLOrExp();
        Cond cond = new Cond(lorExp);
        return cond;
    }
}
