package frontend.Parser.Stmt;

import frontend.Token;
import frontend.TokenListReader;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;
import frontend.Parser.PriExp.LVal;
import frontend.Parser.PriExp.LValParser;

//ForStmt â†’ LVal '=' Exp
public class ForStmtParser {
    private TokenListReader reader;
    private LVal lVal;
    private Token equal;
    private Exp exp;

    public ForStmtParser(TokenListReader reader) {
        this.reader = reader;
    }

    public ForStmt parseForStmt() {
        LValParser lValParser = new LValParser(this.reader);
        lVal = lValParser.parseLVal();
        equal = this.reader.getnextToken();
        ExpParser expParser = new ExpParser(this.reader);
        exp = expParser.parseExp();
        return new ForStmt(this.lVal, this.equal, this.exp);
    }


}
