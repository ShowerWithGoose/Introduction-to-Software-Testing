package frontend.parser.func.types;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.parser.stmt.types.Block;

public class FuncDef {
    private final Token funcType, ident, lParent, rParent;
    private final FuncFParams funcFParams;
    private final Block block;
    public FuncDef(Token funcType, Token ident, Token lParent, FuncFParams funcFParams, Token rParent, Block block) {
        this.funcType = funcType;
        this.ident = ident;
        this.lParent = lParent;
        this.funcFParams = funcFParams;
        this.rParent = rParent;
        this.block = block;
    }
    public boolean isMain() {
        return ident.getType() == TokenType.MAINTK;
    }
    public Block getBlock() {
        return this.block;
    }
    public Token getIdent() {
        return this.ident;
    }
    public TokenType getFuncType() {
        return this.funcType.getType();
    }
    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(funcType);
        if (!isMain()) {
            res.append("<FuncType>\n");
        }
        res.append(ident).append(lParent);
        if (funcFParams != null) res.append(funcFParams);
        if (rParent != null) res.append(rParent);
        res.append(block);
        res.append(isMain()?"<MainFuncDef>\n":"<FuncDef>\n");
        return res.toString();
    }

    public FuncFParams getFuncFParams() {
        return this.funcFParams;
    }
}
