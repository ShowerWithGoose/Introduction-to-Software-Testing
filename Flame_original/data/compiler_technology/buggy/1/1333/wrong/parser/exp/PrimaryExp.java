package parser.exp;

public class PrimaryExp implements SimpleUnaryExp {
    private final PrimaryExpForm primaryExpForm;

    public PrimaryExp(PrimaryExpForm primaryExpForm) {
        this.primaryExpForm = primaryExpForm;
    }

    public String toString() {
        return this.primaryExpForm.toString() + "<PrimaryExp>\n";
    }
}