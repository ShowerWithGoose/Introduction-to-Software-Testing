package Parser;

import java.util.ArrayList;

public class MainFuncDef implements Syntax {

    public String name;

    private ArrayList<Syntax> syntaxes = new ArrayList<>();

    public MainFuncDef(ArrayList<Syntax> syntaxes) {
        this.name = getName();
        this.syntaxes = syntaxes;
    }

    @Override
    public String getName() {
        return "<MainFuncDef>";
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
