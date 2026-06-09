package frontend.parser.ast.exp;

public class PrimaryExp implements UExp {
    private String type = "<PrimaryExp>";
    private PExp pExp;

    public PrimaryExp(PExp pExp) {
        this.pExp = pExp;
    }

    public int getLineno() {
        return pExp.getLineno();
    }

    public String getOutput() {
        return pExp.getOutput() + type + "\n";
    }

    public String getError() {
        String tmp = pExp.getError();
        return tmp;
    }
}
