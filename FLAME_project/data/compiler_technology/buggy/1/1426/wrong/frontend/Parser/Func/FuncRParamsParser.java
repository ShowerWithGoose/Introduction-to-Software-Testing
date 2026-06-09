package frontend.Parser.Func;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.Exp;
import frontend.Parser.Exp.ExpParser;

import java.util.ArrayList;

//FuncRParams â†’ Exp { ',' Exp }
public class FuncRParamsParser {
    private TokenListReader reader;
    private Exp first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<Exp> exps = new ArrayList<>();

    public FuncRParamsParser(TokenListReader reader) {
        this.reader = reader;
    }

    public FuncRParams parseFuncRParams() {
        ExpParser expParser = new ExpParser(this.reader);
        first = expParser.parseExp();
        Token token = this.reader.getnextToken();
        while(token.getType().equals(TokenType.COMMA))
        {
            this.commas.add(token);
            this.exps.add(expParser.parseExp());
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        FuncRParams funcRParams = new FuncRParams(this.first, this.commas, this.exps);
        return funcRParams;
    }

}
