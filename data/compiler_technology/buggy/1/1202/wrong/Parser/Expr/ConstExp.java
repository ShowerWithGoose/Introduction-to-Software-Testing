package Parser.Expr;

import Parser.Syntax;

import java.util.ArrayList;

public class ConstExp implements Syntax {

    private String name;
    private ArrayList<Syntax> syntaxes = new ArrayList<>();

    public ConstExp(ArrayList<Syntax> syntaxes) {
        this.name = getName();
        this.syntaxes = syntaxes;
    }

    @Override
    public String getName() {
        return "<ConstExp>";
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
