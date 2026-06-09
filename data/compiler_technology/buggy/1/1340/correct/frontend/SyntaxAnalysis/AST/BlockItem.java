package frontend.SyntaxAnalysis.AST;

public class BlockItem {
    public Decl decl;
    public Stmt stmt;
    public BlockItemType type;
    public enum BlockItemType{
        Decl,
        Stmt
    }
}
