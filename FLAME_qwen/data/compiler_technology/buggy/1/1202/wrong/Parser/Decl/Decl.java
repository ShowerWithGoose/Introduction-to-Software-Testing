package Parser.Decl;

import Parser.Syntax;

public class Decl implements Syntax {

    private String name;
    private Syntax declSyntax;

    public Decl(Syntax syntax) {
        this.name = getName();
        this.declSyntax = syntax;
    }

    @Override
    public String getName() {
        return "<Decl>";
    }

    @Override
    public String syntaxOutput() {
        return declSyntax.syntaxOutput();
    }
}
