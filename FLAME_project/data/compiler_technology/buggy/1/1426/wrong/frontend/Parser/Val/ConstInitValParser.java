package frontend.Parser.Val;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.ConstExpParser;
import frontend.Parser.solid.StringConstParser;

//常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |
//StringConst
public class ConstInitValParser {
    private TokenListReader reader;
    private ConstInitValInf constInitValInf;

    public ConstInitValParser(TokenListReader reader) {
        this.reader = reader;
    }

    public ConstInitVal parseConstInitVal() {
        Token token = this.reader.getnextToken();
        if(token.getType().equals(TokenType.STRCON)){
            this.reader.backward(1);
            StringConstParser stringConstParser = new StringConstParser(this.reader);
            this.constInitValInf = stringConstParser.parseStringConst();
        }
        else if(token.getType().equals(TokenType.LBRACE)){
            this.reader.backward(1);
            ConstInitValsParser constInitValsParser = new ConstInitValsParser(this.reader);
            this.constInitValInf = constInitValsParser.parseConstInitVals();
        }
        else{
            this.reader.backward(1);
            ConstExpParser constExpParser = new ConstExpParser(this.reader);
            this.constInitValInf = constExpParser.parseConstExp();
        }
        ConstInitVal constInitVal = new ConstInitVal(this.constInitValInf);
        return constInitVal;
    }

}
