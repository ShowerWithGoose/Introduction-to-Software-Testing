package frontend.parser.ast.exp;

public class ConstExp {
    private String type = "<ConstExp>";
    private AddExp addExp;

    public ConstExp(AddExp addExp) {
        this.addExp = addExp;
    }

    public int getLineno() {
        return addExp.getLineno();
    }

    public String getOutput() {
        return addExp.getOutput() + type + "\n";
    }

    public String getError() {
        return addExp.getError();
    }
}
