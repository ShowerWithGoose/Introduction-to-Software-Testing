package parser.exp;

import java.util.ArrayList;

public class LOrExp {
    private final ArrayList<LAndExp> lAndExps;

    public LOrExp(LAndExp lAndExp) {
        this.lAndExps = new ArrayList<>();
        this.lAndExps.add(lAndExp);
    }

    public void addLAndExp(LAndExp lAndExp) {
        this.lAndExps.add(lAndExp);
    }

    public String toString() {
        StringBuilder str = new StringBuilder(this.lAndExps.get(0).toString());
        str.append("<LOrExp>\n");
        for (int i = 1; i < this.lAndExps.size(); i++) {
            str.append("OR ||\n");
            str.append(this.lAndExps.get(i).toString());
            str.append("<LOrExp>\n");
        }
        return str.toString();
    }
}
