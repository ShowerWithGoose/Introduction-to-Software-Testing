package frontend.Parser.Exp;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;
import frontend.Parser.PriExp.PrimaryExpParser;

// UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
public class UnaryExpParser {
    private TokenListReader reader;
    private  UnaryExpInf unaryExpInf = null;

    public UnaryExpParser(TokenListReader reader) {
        this.reader = reader;
    }
    public UnaryExp parseUnaryExp() {
        Token first = this.reader.getnextToken();
        Token second = this.reader.getnextToken();
        if(first.getType().equals(TokenType.IDENFR) && second.getType().equals(TokenType.LPARENT)) {
            this.reader.backward(2);
            UnaryExpIdentParser unaryExpIdentParser = new UnaryExpIdentParser(this.reader);
            this.unaryExpInf = unaryExpIdentParser.parseUnaryExpIdent();
        }
        else if(first.getType().equals(TokenType.IDENFR)||first.getType().equals(TokenType.LPARENT)||first.getType().equals(TokenType.INTCON)||first.getType().equals(TokenType.CHRCON)) {
            this.reader.backward(2);
            PrimaryExpParser primaryExpParser = new PrimaryExpParser(this.reader);
            this.unaryExpInf = primaryExpParser.parsePrimaryExp();
        }
        else if(first.getType().equals(TokenType.PLUS)||first.getType().equals(TokenType.MINU)||first.getType().equals(TokenType.NOT)) {
            this.reader.backward(2);
            UnaryExpOpParser unaryExpOpParser = new UnaryExpOpParser(this.reader);
            this.unaryExpInf = unaryExpOpParser.parseUnaryExpOp();
        }
        UnaryExp unaryExp = new UnaryExp(this.unaryExpInf);
        return unaryExp;
    }
}
