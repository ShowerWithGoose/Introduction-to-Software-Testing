package Parser.Decl;

import Parser.Syntax;

import java.util.ArrayList;

public class ConstDef implements Syntax {

    private String name;
    private ArrayList<Syntax> syntaxes = new ArrayList<>();

    public ConstDef(ArrayList<Syntax> syntaxes) {
        this.syntaxes = syntaxes;
        this.name = getName();
    }

    @Override
    public String getName() {
        return "<ConstDef>";
    }

    @Override
    public String syntaxOutput() {
        StringBuilder sb = new StringBuilder();
        for (Syntax syntax : syntaxes) {
            sb.append(syntax.syntaxOutput());
        }
        sb.append(getName() + "\n");
        return sb.toString();
    }
}
