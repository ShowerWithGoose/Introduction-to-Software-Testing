package frontend.Parser.Decl;

import frontend.Parser.Stmt.BlockItemInf;

public class Decl implements DeclInf, BlockItemInf {
    private final String name = "<Decl>";
    private DeclInf declInf;

    public Decl(DeclInf declInf) {
        this.declInf = declInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(declInf.Parser_Output());
        return sb.toString();
    }
}
