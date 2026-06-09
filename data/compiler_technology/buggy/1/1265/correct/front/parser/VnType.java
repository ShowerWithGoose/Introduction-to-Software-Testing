package front.parser;

import front.lexer.Token;
import front.lexer.TokenType;

import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * 非终结符类型枚举类
 */
public enum VnType {
    BType(false, List.of(Set.of(TokenType.INTTK, TokenType.CHARTK))),
    ConstDecl(true, List.of(Set.of(TokenType.CONSTTK))),
    VarDef(true, List.of(Set.of(TokenType.IDENFR))),
    VarDecl(true, List.of(BType.first)),
    ConstDef(true, List.of(Set.of(TokenType.IDENFR))),
    Decl(false, List.of(ConstDecl.first, VarDecl.first)),
    FuncType(true, List.of(Set.of(TokenType.VOIDTK, TokenType.INTTK, TokenType.CHARTK))),
    FuncDef(true, List.of(FuncType.first)),
    MainFuncDef(true, List.of(Set.of(TokenType.INTTK))),
    CompUnit(true, List.of(Decl.first, FuncDef.first, MainFuncDef.first)),
    UnaryOp(true, List.of(Set.of(TokenType.PLUS, TokenType.MINU, TokenType.NOT))),
    Number(true, List.of(Set.of(TokenType.INTCON))),
    Character(true, List.of(Set.of(TokenType.CHRCON))),
    LVal(true, List.of(Set.of(TokenType.IDENFR))),
    PrimaryExp(true, List.of(LVal.first, Number.first, Character.first, Set.of(TokenType.LPARENT))),
    UnaryExp(true, List.of(PrimaryExp.first, UnaryOp.first, Set.of(TokenType.IDENFR))),
    MulExp(true, List.of(UnaryExp.first)),
    AddExp(true, List.of(MulExp.first)),
    ConstExp(true, List.of(AddExp.first)),
    ConstInitVal(true, List.of(ConstExp.first, Set.of(TokenType.LBRACE, TokenType.STRCON))),
    Exp(true, List.of(AddExp.first)),
    InitVal(true, List.of(Exp.first, Set.of(TokenType.LBRACE, TokenType.STRCON))),
    FuncFParam(true, List.of(BType.first)),
    FuncFParams(true, List.of(FuncFParam.first)),
    Block(true, List.of(Set.of(TokenType.LBRACE))),
    Stmt(true, List.of(LVal.first, Exp.first, Block.first, Set.of(TokenType.SEMICN, TokenType.IFTK, TokenType.FORTK, TokenType.BREAKTK, TokenType.CONTINUETK, TokenType.RETURNTK, TokenType.PRINTFTK))),
    BlockItem(false, List.of(Decl.first, Stmt.first)),
    ForStmt(true, List.of(LVal.first)),
    RelExp(true, List.of(AddExp.first)),
    EqExp(true, List.of(RelExp.first)),
    LAndExp(true, List.of(EqExp.first)),
    LOrExp(true, List.of(LAndExp.first)),
    Cond(true, List.of(LOrExp.first)),
    FuncRParams(true, List.of(Exp.first));
    /**
     * 是否需要输出
     */
    private boolean printable;
    /**
     * 非终结符的 FIRST
     */
    private Set<TokenType> first;

    /**
     * 构造方法
     *
     * @param printable 是否需要输出
     * @param listSet   传入的 FIRST 信息
     */
    VnType(boolean printable, List<Set<TokenType>> listSet) {
        this.printable = printable;
        this.first = new HashSet<>();
        for (Set<TokenType> set : listSet) {
            first.addAll(set);
        }
    }

    /**
     * token 是否在 FIRST 中
     *
     * @param token 需要检验的 token
     * @return 检验结果
     */
    public boolean inFirst(Token token) {
        return token != null && first.contains(token.getTokenType());
    }

    /**
     * 获取 Vn 是否需要输出
     *
     * @return 是否需要输出
     */
    public boolean isPrintable() {
        return printable;
    }
}
