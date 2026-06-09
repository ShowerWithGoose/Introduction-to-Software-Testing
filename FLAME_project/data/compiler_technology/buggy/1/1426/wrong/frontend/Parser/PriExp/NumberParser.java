package frontend.Parser.PriExp;

import frontend.TokenListReader;
import frontend.Parser.solid.IntConst;
import frontend.Parser.solid.IntConstParser;

public class NumberParser {
    private TokenListReader reader;
    public NumberParser(TokenListReader reader) {
        this.reader = reader;
    }

    public Number parseNumber() {
        IntConstParser intConstParser = new IntConstParser(this.reader);
        IntConst intConst = intConstParser.parseIntConst();
        Number number = new Number(intConst);
        return number;
    }
}
