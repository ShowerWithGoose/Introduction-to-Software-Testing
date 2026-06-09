package frontend.Parser.Exp;

import frontend.Parser.ErrorHandler;
import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

import java.util.ArrayList;

//LOrExp â†’ LAndExp | LOrExp '||' LAndExp
public class LOrExpParser {
    private TokenListReader reader;
    private LAndExp first ;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<LAndExp> others = new ArrayList<>();

    public LOrExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public LOrExp parseLOrExp(){
        this.ops = new ArrayList<>();
        this.others = new ArrayList<>();
        LAndExpParser lAndExpParser = new LAndExpParser(this.reader);
        this.first = lAndExpParser.parseLAndExp();
        Token token = this.reader.getnextToken();
        while (token.getType().equals(TokenType.OR)||token.getType().equals(TokenType.ERROR)) {
            this.ops.add(token);
            if(token.getType().equals(TokenType.ERROR)){
                ErrorHandler.getInstance().reportError(token.getLine(),"a");
            }
            this.others.add(lAndExpParser.parseLAndExp());
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        LOrExp lorExp = new LOrExp(this.first, this.ops, this.others);
        return lorExp;
    }
}
