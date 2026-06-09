package frontend.parser.ast.exp;

public class UnaryExp {
    private String type = "<UnaryExp>";
    private UExp uExp;

    public UnaryExp(UExp uExp) {
        this.uExp = uExp;
    }

    public int getLineno() {
        return uExp.getLineno();
    }

    public String getOutput() {
        return uExp.getOutput() + type + "\n";
    }

    public String getError() {
        if (uExp.getError() == null) {
            System.out.println("Error in <UnaryExp>");
        }
        return uExp.getError();
    }
}
