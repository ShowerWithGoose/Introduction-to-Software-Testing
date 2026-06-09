package frontend.Parser.Class;

import java.util.ArrayList;

public class LAndExp {
    // LAndExp â†’ EqExp LAndExp'
    private EqExp eqExp;
    private LAndExpTemp lAndExpTemp;

    public LAndExp(EqExp eqExp, LAndExpTemp lAndExpTemp, ArrayList<String> outputList) {
        this.eqExp = eqExp;
        this.lAndExpTemp = lAndExpTemp;
        outputList.add("<LAndExp>");
    }

    public LAndExp(EqExp eqExp, ArrayList<String> outputList) {
        this.eqExp = eqExp;
        outputList.add("<LAndExp>");
    }
}
