package fronened.Parser;

import fronened.Lexer.Error;
import fronened.Lexer.ErrorList;
import fronened.Lexer.Token;
import fronened.Lexer.TokenIterator;

public class FuncDef {
    private FuncType funcType;
    private Token ident;
    private Token lParent;
    private FuncFParams funcFParams;
    private Token rParent;
    private Block block;

    public FuncDef(FuncType funcType, Token ident, Token lParent, FuncFParams funcFParams, Token rParent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = funcFParams;
        this.rParent = rParent;
        this.block = block;
    }

    public String print() {
        StringBuilder sb = new StringBuilder();
        sb.append(funcType.print());
        sb.append(ident.print());
        sb.append(lParent.print());
        if (funcFParams != null) {
            sb.append(funcFParams.print());
        }
        if (rParent != null) {
            sb.append(rParent.print());
        }
        sb.append(block.print());
        sb.append("<FuncDef>\n");
        return sb.toString();
    }

    public static FuncDef parse(TokenIterator iterator) {
        FuncType funcType = FuncType.parse(iterator);
        Token ident = iterator.next();
        Token lParent = iterator.next();
        FuncFParams funcFParams = null;
        Token rParent = null;
        Token token = iterator.next();
        if (token.getType().equals(Token.Type.INTTK) || token.getType().equals(Token.Type.CHARTK)) {
            iterator.back();
            funcFParams = FuncFParams.parse(iterator);
        }
        else {
            iterator.back();
        }
        token = iterator.next();
        if (token.getType().equals(Token.Type.RPARENT)) {
            rParent = token;
        }
        else {
            iterator.back();
            Error error = new Error(iterator.now_line(), 'j');
            ErrorList.addError(error);
        }
        Block block = Block.parse(iterator);
        return new FuncDef(funcType, ident, lParent, funcFParams, rParent, block);
    }

}
