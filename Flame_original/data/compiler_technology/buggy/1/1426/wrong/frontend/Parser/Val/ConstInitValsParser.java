package frontend.Parser.Val;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.Exp.ConstExp;
import frontend.Parser.Exp.ConstExpParser;

import java.util.ArrayList;

////常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' |
////StringConst // 1.常表达式初值 2.一维数组初值
public class ConstInitValsParser {
    private TokenListReader reader;
    private Token lbrace = null;
    private ConstExp first = null;
    private ArrayList<Token> commas = new ArrayList<>();
    private ArrayList<ConstExp> constExps = new ArrayList<>();
    private Token rbrace = null;

    public ConstInitValsParser(TokenListReader reader) {
        this.reader = reader;
    }

    public ConstInitVals parseConstInitVals() {
        this.commas = new ArrayList<>();
        this.constExps = new ArrayList<>();
        this.lbrace = this.reader.getnextToken();
        if(!this.lbrace.getType().equals(TokenType.LBRACE))
        {
            System.out.println("Error: invalid ConstantInitVals");
        }
        Token token = this.reader.getnextToken();
        if(!token.getType().equals(TokenType.RBRACE))
        {
            this.reader.backward(1);
            ConstExpParser parser = new ConstExpParser(this.reader);
            this.first = parser.parseConstExp();
            token = this.reader.getnextToken();
            while (token.getType().equals(TokenType.COMMA)) {
                this.commas.add(token);
                this.constExps.add(parser.parseConstExp());
                token = this.reader.getnextToken();
            }
            this.reader.backward(1);
        }
        else{
            this.reader.backward(1);
        }
        this.rbrace = this.reader.getnextToken();
        ConstInitVals constInitVals = new ConstInitVals(this.lbrace,this.first,this.commas, this.constExps,this.rbrace);

        return constInitVals;
    }
}
