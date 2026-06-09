package frontend.Parser.Exp.Type;

public class UnaryExp implements UEinterface{
    // UnaryExp â†’ PrimaryExp | FuncExp | UnaryOp UnaryExp
    private final UnaryOp op;
    private final UEinterface uEinterface;

    public UnaryExp(UnaryOp op, UEinterface uEinterface) {
        this.op = op;
        this.uEinterface = uEinterface;
    }

    public int getLine() {
        return uEinterface.getLine();
    }

    @Override
    public String toString() {
        if(op == null) {
            return uEinterface + "<UnaryExp>\n";
        }
        return op.toString() + uEinterface + "<UnaryExp>\n";
    }
}
