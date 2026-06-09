package syntaxTree;

import token.Token;
import token.TokenType;

import java.util.ArrayList;

public class FuncDef {
    private final TokenType funcType;
    private final Token ident;
    private final ArrayList<FuncFParam> funcFParams;
    private final ArrayList<BlockItem> blockItems;

    public FuncDef(TokenType funcType, Token ident, ArrayList<FuncFParam> funcFParams,
                   ArrayList<BlockItem> blockItems) {
        this.funcType = funcType;
        this.ident = ident;
        this.funcFParams = funcFParams;
        this.blockItems = blockItems;
    }
}
