package frontend.Parser.Exp;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

import java.util.ArrayList;

// EqExp â†’ RelExp | EqExp ('==' | '!=') RelExp
public class EqExpParser {
    private TokenListReader reader;
    private RelExp first = null;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<RelExp> others = new ArrayList<>();

    public EqExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public EqExp parseEqExp() {
        this.ops = new ArrayList<>();
        this.others = new ArrayList<>();
        RelExpParser relExpParser = new RelExpParser(this.reader);
        this.first = relExpParser.parseRelExp();
        Token token = this.reader.getnextToken();
        while (token.getType().equals(TokenType.EQL)||token.getType().equals(TokenType.NEQ)) {
            this.ops.add(token);
            this.others.add(relExpParser.parseRelExp());
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        EqExp eqExp = new EqExp(this.first, this.ops, this.others);
        return eqExp;
    }


}
