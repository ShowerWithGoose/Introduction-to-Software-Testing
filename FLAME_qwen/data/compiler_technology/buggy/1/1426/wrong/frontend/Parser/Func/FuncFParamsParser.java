package frontend.Parser.Func;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

import java.util.ArrayList;

//FuncFParams â†’ FuncFParam { ',' FuncFParam }
public class FuncFParamsParser {
    private TokenListReader reader;
    private FuncFParam first;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();

    public FuncFParamsParser(TokenListReader reader) {
        this.reader = reader;
    }

    public FuncFParams parseFuncFParams() {
        FuncFParamParser parser = new FuncFParamParser(this.reader);
        first = parser.parseFuncFParam();
        if(first == null) {
            return null;
        }
        Token token = this.reader.getnextToken();
        while(token.getType().equals(TokenType.COMMA))
        {
            this.commas.add(token);
            this.funcFParams.add(parser.parseFuncFParam());
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        FuncFParams funcFParams = new FuncFParams(this.first, this.commas, this.funcFParams);
        return funcFParams;
    }


}
