package frontend.Parser.Val;


import frontend.Parser.Exp.Exp;

public class InitValExp implements InitValInf {
    private Exp exp;

    public InitValExp(Exp exp) {
        this.exp = exp;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(exp.Parser_Output());
        return sb.toString();
    }
}
