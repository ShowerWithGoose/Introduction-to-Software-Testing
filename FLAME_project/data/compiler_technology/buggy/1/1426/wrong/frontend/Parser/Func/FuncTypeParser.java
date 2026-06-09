package frontend.Parser.Func;

import frontend.Token;
import frontend.TokenListReader;
import frontend.TokenType;

public class FuncTypeParser {
    private TokenListReader reader;
    private FuncTypeInf funcTypeInf;

    public FuncTypeParser(TokenListReader reader) {
        this.reader = reader;
    }

    public FuncType parseFuncType() {
        Token token = this.reader.getnextToken();
        if (token.getType().equals(TokenType.VOIDTK)) {
            this.funcTypeInf = new FunTypeVoid(token);
        } else if (token.getType().equals(TokenType.INTTK)) {
            this.funcTypeInf = new FunTypeInt(token);
        }else if (token.getType().equals(TokenType.CHARTK)) {
            this.funcTypeInf = new FuncTypeChar(token);
        }else {
            System.out.println("error: invalid FuncType");
        }
        FuncType funcType = new FuncType(this.funcTypeInf);
        return funcType;
    }

}
