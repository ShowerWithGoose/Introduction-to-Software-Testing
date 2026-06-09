package syntacticanalysis.node.expression;

import syntacticanalysis.node.singal.NumberTk;

public class PrimaryExp3 extends PrimaryExp {
    private String name = "<PrimaryExp>";
    private NumberTk numberTk;

    public PrimaryExp3(NumberTk numberTk) {
        this.numberTk = numberTk;
    }

    @Override
    public String syntaxOutput() {
        return numberTk.syntaxOutput() + "\n" + name;
    }
}
