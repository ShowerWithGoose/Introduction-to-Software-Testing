package parser.exp;

import java.util.ArrayList;

public class LAndExp {
    private final ArrayList<EqExp> eqExps;

    public LAndExp(EqExp eqExp) {
        this.eqExps = new ArrayList<>();
        this.eqExps.add(eqExp);
    }

    public void addEqExp(EqExp eqExp) {
        this.eqExps.add(eqExp);
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.eqExps.get(0).toString());
        str.append("<LAndExp>\n");
        for (int i = 1; i < this.eqExps.size(); i++) {
            str.append("AND &&\n");
            str.append(this.eqExps.get(i).toString());
            str.append("<LAndExp>\n");
        }
        return str.toString();
    }
}
