package frontend.parser.declaration;

import frontend.parser.SyntaxNode;
import frontend.parser.statement.blockitem.BlockItemEle;

public class Decl implements BlockItemEle {
    public final String name = "<Decl>";
    public DeclEle declEle;
    public Decl(DeclEle declEle) {
        this.declEle = declEle;
    }
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.declEle.syntaxOutput());
        return sb.toString();
    }
    public int my_line_num(){
        return this.declEle.my_line_num();
    }
}
