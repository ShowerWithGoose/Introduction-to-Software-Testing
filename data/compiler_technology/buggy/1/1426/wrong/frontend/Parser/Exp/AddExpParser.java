package frontend.Parser.Exp;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

import java.util.ArrayList;

//AddExp → MulExp | AddExp ('+' | '−') MulExp
public class AddExpParser {
    private TokenListReader reader;
    private MulExp first;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<MulExp> others = new ArrayList<>();

    public AddExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public AddExp parseAddExp() {
        this.ops = new ArrayList<>();
        this.others = new ArrayList<>();
        MulExpParser mulExpParser = new MulExpParser(this.reader);
        this.first = mulExpParser.parseMulExp();
        Token token = this.reader.getnextToken();
        while(token.getType().equals(TokenType.PLUS)||token.getType().equals(TokenType.MINU))
        {
            this.ops.add(token);
            this.others.add(mulExpParser.parseMulExp());
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        AddExp addExp = new AddExp(this.first, this.ops, this.others);
        return addExp;
    }

}
