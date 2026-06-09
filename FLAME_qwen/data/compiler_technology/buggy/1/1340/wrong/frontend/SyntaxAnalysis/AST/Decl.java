package frontend.SyntaxAnalysis.AST;

public class Decl {
    public DeclType declType;
    public  ConstDecl constDecl;
    public VarDecl varDecl;

    public enum DeclType{
        constDecl,
        varDecl
    }
}
