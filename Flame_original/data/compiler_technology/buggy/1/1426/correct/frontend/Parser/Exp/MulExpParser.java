package frontend.Parser.Exp;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

import java.util.ArrayList;

//MulExp â†’ UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
public class MulExpParser {
    private TokenListReader reader;
    private UnaryExp first;
    private ArrayList<Token> ops = new ArrayList<>();
    private ArrayList<UnaryExp> others = new ArrayList<>();

    public MulExpParser(TokenListReader reader) {
        this.reader = reader;
    }

    public MulExp parseMulExp() {
        this.ops = new ArrayList<>();
        this.others = new ArrayList<>();
        UnaryExpParser unaryExpParser = new UnaryExpParser(this.reader);
        this.first = unaryExpParser.parseUnaryExp();
        Token token = this.reader.getnextToken();
        while (token.getType().equals(TokenType.MULT) ||
                token.getType().equals(TokenType.DIV) ||
                token.getType().equals(TokenType.MOD)) {
            this.ops.add(token);
            this.others.add(unaryExpParser.parseUnaryExp());
            token = this.reader.getnextToken();
        }
        this.reader.backward(1);
        MulExp mulExp = new MulExp(this.first, this.ops, this.others);
        return mulExp;
    }
}
