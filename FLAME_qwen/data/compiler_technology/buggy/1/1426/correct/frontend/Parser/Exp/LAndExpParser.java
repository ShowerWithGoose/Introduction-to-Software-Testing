package frontend.Parser.Exp;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

import java.util.ArrayList;

//LAndExp â†’ EqExp | LAndExp '&&' EqExp
public class LAndExpParser {
    private TokenListReader reader;
    private EqExp first ;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<EqExp> others = new ArrayList<>();

    public LAndExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public LAndExp parseLAndExp(){
        this.ops = new ArrayList<>();
        this.others = new ArrayList<>();
        EqExpParser eqExpParser = new EqExpParser(this.reader);
        this.first = eqExpParser.parseEqExp();
        Token token = this.reader.getnextToken();
        // error!
        while (token.getType().equals(TokenType.AND)||token.getType().equals(TokenType.ERROR)) {
            this.ops.add(token);
            if(token.getType().equals(TokenType.ERROR)){
                ErrorHandler.getInstance().reportError(token.getLine(),"a");
            }
            this.others.add(eqExpParser.parseEqExp());
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        LAndExp landExp = new LAndExp(this.first, this.ops, this.others);
        return landExp;
    }

}
