package front.parser;

import front.lexer.Token;
import front.lexer.TokenType;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

/**
 * 非终结符类型枚举类
 */
public enum VnType {
    BType(false, List.of(
            List.of(Set.of(TokenType.INTTK, TokenType.CHARTK))
    )),
    ConstDecl(true, List.of(
            List.of(Set.of(TokenType.CONSTTK)),
            List.of(BType.front.get(0))
    )),
    VarDef(true, List.of(
            List.of(Set.of(TokenType.IDENFR)),
            List.of(Set.of(TokenType.LBRACK, TokenType.ASSIGN))
    )),
    VarDecl(true, List.of(
            List.of(BType.front.get(0)),
            List.of(VarDef.front.get(0))
    )),
    ConstDef(true, List.of(
            List.of(Set.of(TokenType.IDENFR))
    )),
    Decl(false, List.of(
            List.of(ConstDecl.front.get(0), VarDecl.front.get(0)),
            List.of(ConstDecl.front.get(1), VarDecl.front.get(1)),
            List.of(ConstDef.front.get(0), VarDef.front.get(1), Set.of(TokenType.COMMA, TokenType.SEMICN))
    )),
    FuncType(true, List.of(
            List.of(Set.of(TokenType.VOIDTK, TokenType.INTTK, TokenType.CHARTK))
    )),
    FuncDef(true, List.of(
            List.of(FuncType.front.get(0)),
            List.of(Set.of(TokenType.IDENFR)),
            List.of(Set.of(TokenType.LPARENT))
    )),
    MainFuncDef(true, List.of(
            List.of(Set.of(TokenType.INTTK))
    )),
    CompUnit(true, List.of(
            List.of(Decl.front.get(0), FuncDef.front.get(0), MainFuncDef.front.get(0))
    )),
    UnaryOp(true, List.of(
            List.of(Set.of(TokenType.PLUS, TokenType.MINU, TokenType.NOT))
    )),
    Number(true, List.of(
            List.of(Set.of(TokenType.INTCON))
    )),
    Character(true, List.of(
            List.of(Set.of(TokenType.CHRCON))
    )),
    LVal(true, List.of(
            List.of(Set.of(TokenType.IDENFR))
    )),
    PrimaryExp(true, List.of(
            List.of(LVal.front.get(0), Number.front.get(0), Character.front.get(0), Set.of(TokenType.LPARENT))
    )),
    UnaryExp(true, List.of(
            List.of(PrimaryExp.front.get(0), UnaryOp.front.get(0), Set.of(TokenType.IDENFR))
    )),
    MulExp(true, List.of(
            List.of(UnaryExp.front.get(0))
    )),
    AddExp(true, List.of(
            List.of(MulExp.front.get(0))
    )),
    ConstExp(true, List.of(
            List.of(AddExp.front.get(0))
    )),
    ConstInitVal(true, List.of(
            List.of(ConstExp.front.get(0), Set.of(TokenType.LBRACE, TokenType.STRCON))
    )),
    Exp(true, List.of(
            List.of(AddExp.front.get(0))
    )),
    InitVal(true, List.of(
            List.of(Exp.front.get(0), Set.of(TokenType.LBRACE, TokenType.STRCON))
    )),
    FuncFParam(true, List.of(
            List.of(BType.front.get(0))
    )),
    FuncFParams(true, List.of(
            List.of(FuncFParam.front.get(0))
    )),
    Block(true, List.of(
            List.of(Set.of(TokenType.LBRACE))
    )),
    Stmt(true, List.of(
            List.of(LVal.front.get(0), Exp.front.get(0), Block.front.get(0), Set.of(TokenType.SEMICN, TokenType.IFTK, TokenType.FORTK, TokenType.BREAKTK, TokenType.RETURNTK, TokenType.PRINTFTK))
    )),
    BlockItem(false, List.of(
            List.of(Decl.front.get(0), Stmt.front.get(0))
    )),
    ForStmt(true, List.of(
            List.of(LVal.front.get(0))
    )),
    RelExp(true, List.of(
            List.of(AddExp.front.get(0))
    )),
    EqExp(true, List.of(
            List.of(RelExp.front.get(0))
    )),
    LAndExp(true, List.of(
            List.of(EqExp.front.get(0))
    )),
    LOrExp(true, List.of(
            List.of(LAndExp.front.get(0))
    )),
    Cond(true, List.of(
            List.of(LOrExp.front.get(0))
    )),
    FuncRParams(true, List.of(
            List.of(Exp.front.get(0))
    ));
    /**
     * 是否需要输出
     */
    private boolean printable;
    /**
     * 非终结符的 FIRST,
     * SECOND,
     * ...
     */
    private List<Set<TokenType>> front;

    /**
     * 构造方法
     *
     * @param printable   是否需要输出
     * @param listListSet 传入的 front 信息
     */
    VnType(boolean printable, List<List<Set<TokenType>>> listListSet) {
        this.printable = printable;
        this.front = new ArrayList<>();
        for (List<Set<TokenType>> listSet : listListSet) {
            Set<TokenType> tokenTypes = new HashSet<>();
            for (Set<TokenType> set : listSet) {
                tokenTypes.addAll(set);
            }
            this.front.add(tokenTypes);
        }
    }

    /**
     * token 是否在 Front(index) 中，注意 index 从 1 开始
     *
     * @param token 需要检验的 token
     * @param index 索引
     * @return 检验结果
     */
    public boolean inFront(Token token, int index) {
        return token != null && front.get(index - 1).contains(token.getTokenType());
    }

    public static void main(String[] args) {
        System.out.println("| Unit          | FIRST                                                        | SECOND | THIRD |\n" +
                "| ------------- | ------------------------------------------------------------ | ------ | ----- |");
        for (VnType vnType : values()) {
            System.out.print("|" + vnType.name() + "|");
            for (int i = 0; i < 3; i++) {
                if (i < vnType.front.size()) {
                    System.out.print(vnType.front.get(i));
                }
                System.out.print("|");
            }
            System.out.println();
        }
    }
}
