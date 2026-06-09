package assist;

import java.util.ArrayList;

public class Node {
    public enum SyntaxType{
        CompUnit, ConstDecl, ConstDef, ConstInitVal, VarDecl, VarDef, InitVal,
        FuncDef, MainFuncDef, FuncType, FuncFParams, FuncFParam, Block, Stmt, ForStmt,
        Exp, Cond, LVal, PrimaryExp, Number, Character, UnaryExp, UnaryOp, FuncRParams,
        MulExp, AddExp, RelExp, EqExp, LAndExp, LOrExp, ConstExp, Private, LeafType
    } //Private类型是自定义的，文法中并没有

    protected int startLine;
    protected int endLine;
    protected SyntaxType type;
    protected ArrayList<Node> children = new ArrayList<>();

    public SyntaxType getType() {
        return this.type;
    }

    public void setStartLine(int startLine) {
        this.startLine = startLine;
    }

    public int getStartLine() {
        return startLine;
    }

    public void setEndLine(int endLine) {
        this.endLine = endLine;
    }

    public int getEndLine() {
        return endLine;
    }

    public void addChildNode(Node child) {
        this.children.add(child);
    }
    public ArrayList<Node> getChildren() { return this.children; }
}
