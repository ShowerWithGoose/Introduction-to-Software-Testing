package frontend.Parser.Exp;

import frontend.TokenListReader;

public class UnaryExpOpParser {
    private TokenListReader reader;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExpOpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public UnaryExpOp parseUnaryExpOp()
    {
        UnaryOpParser unaryOpParser = new UnaryOpParser(this.reader);
        this.unaryOp = unaryOpParser.parseUnaryOp();
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.reader);
        this.unaryExp = unaryExpParser.parseUnaryExp();
        UnaryExpOp unaryExpOp = new UnaryExpOp(this.unaryOp, this.unaryExp);
        return unaryExpOp;
    }

}
