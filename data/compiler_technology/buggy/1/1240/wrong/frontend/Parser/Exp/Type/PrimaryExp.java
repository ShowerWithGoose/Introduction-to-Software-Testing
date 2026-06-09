package frontend.Parser.Exp.Type;

public class PrimaryExp implements UEinterface {
    // PrimaryExp â†’ BraceExp | LVal | Number | Character
    private final PEinterface pEinterface;

    public PrimaryExp(PEinterface pEinterface) {
        this.pEinterface = pEinterface;
    }

    public int getLine() {
        return this.pEinterface.getLine();
    }

    @Override
    public String toString() {
        return pEinterface.toString() + "<PrimaryExp>\n";
    }
}
