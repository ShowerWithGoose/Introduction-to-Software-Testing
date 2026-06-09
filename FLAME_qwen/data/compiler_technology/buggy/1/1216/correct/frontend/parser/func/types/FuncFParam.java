package frontend.parser.func.types;

import frontend.lexer.Token;
import frontend.lexer.TokenType;
import frontend.symbol.Symbol;
import frontend.symbol.SymbolType;

import java.util.Objects;

public class FuncFParam {
    private final Token bType, ident;
    private Token lBrack = null, rBrack = null;
    public FuncFParam(Token bType, Token ident) {
        this.bType = bType;
        this.ident = ident;
    }
    public FuncFParam(Token bType, Token ident, Token lBrack, Token rBrack) {
        this.bType = bType;
        this.ident = ident;
        this.lBrack = lBrack;
        this.rBrack = rBrack;
    }
    public SymbolType getSymbolType() {
        SymbolType type;
        if (Objects.requireNonNull(this.bType.getType()) == TokenType.INTTK) {
            if (rBrack == null) type = SymbolType.Int;
            else type = SymbolType.IntArray;
        } else {
            if (rBrack == null) type = SymbolType.Char;
            else type = SymbolType.CharArray;
        }
        return type;
    }
    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append(bType).append(ident);
        if (lBrack != null) {
            res.append(lBrack).append(rBrack == null ? "":rBrack);
        }
        res.append("<FuncFParam>\n");
        return res.toString();
    }

    public Token getIdent() {
        return this.ident;
    }
}
