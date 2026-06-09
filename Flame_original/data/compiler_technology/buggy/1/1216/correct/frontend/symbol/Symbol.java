package frontend.symbol;

import frontend.lexer.Token;

import java.util.ArrayList;

public class Symbol {
    private final SymbolType type;
    private final int scope;
    private final Token token;
    private final ArrayList<SymbolType> paramTypes = new ArrayList<>();

    /**
     * 符号类构造函数
     * @param scope 符号所在的作用域
     * @param token 符号对应单词
     * @param type 符号类型
     */
    public Symbol(int scope, Token token, SymbolType type) {
        this.scope = scope;
        this.type = type;
        this.token = token;
    }
    public void addParam(SymbolType paramType) {
        this.paramTypes.add(paramType);
    }
    public int getParamNum() {
        return this.paramTypes.size();
    }

    /**
     * 获取符号类型
     * @return 符号的类型
     */
    public SymbolType getType() {
        return this.type;
    }
    @Override
    public String toString() {
        return String.format("%d %s %s\n", scope, token.getName(), type);
    }

    public String getName() {
        return this.token.getName();
    }
}
