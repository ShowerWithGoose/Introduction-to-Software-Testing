package Fronted.parser.syntax;

// Cond â†’ LOrExp
public class Cond {

    private static final String name = "<Cond>";

    private LOrExp lOrExp = null;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String toString() {
        StringBuilder out = new StringBuilder();
        out.append(lOrExp);
        out.append(name).append("\n");
        return out.toString();
    }
}
