package frontend.SyntaxTree;

import java.util.ArrayList;

public class LOrExp {
    private ArrayList<LAndExp> lAndExps;

    public LOrExp() {
        lAndExps = new ArrayList<>();
    }

    public void addLAndExp(LAndExp lAndExp) {
        lAndExps.add(lAndExp);
    }

}
