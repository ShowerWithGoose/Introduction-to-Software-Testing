package frontend.Parser.expression.unaryexp;

import frontend.Lexer.TokenListManager;

import frontend.Error;
import java.util.ArrayList;

public class ParserOfUnaryOpExp {
    private TokenListManager tokenListManager;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;
    private ArrayList<Error> errors;
    public ParserOfUnaryOpExp(TokenListManager tokenListManager) {
        this.tokenListManager = tokenListManager;
    }
    public UnaryOpExp parseUnaryOpExp(){
        this.errors = new ArrayList<>();
        ParserOfUnaryOp parserOfUnaryOp = new ParserOfUnaryOp(tokenListManager);
        this.unaryOp = parserOfUnaryOp.parseUnaryOp();
        ParserOfUnaryExp parserOfUnaryExp = new ParserOfUnaryExp(tokenListManager);
        this.unaryExp = parserOfUnaryExp.parseUnaryExp();
        this.errors.addAll(parserOfUnaryExp.getErrors());
        return new UnaryOpExp(this.unaryOp, this.unaryExp);
    }

    public ArrayList<Error> getErrors() {
        return this.errors;
    }
}
