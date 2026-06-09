package frontend.IRBuilder.structure;

import frontend.syntax.Ast;

public class InitExp extends Value{
    public final Ast.Exp exp;
    public InitExp(Ast.Exp exp) {
        super();
        this.exp = exp;
    }
}
