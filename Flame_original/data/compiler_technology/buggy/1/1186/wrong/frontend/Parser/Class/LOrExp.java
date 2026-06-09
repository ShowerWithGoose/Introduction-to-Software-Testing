package frontend.Parser.Class;

import java.util.ArrayList;

public class LOrExp {
    // LOrExp â†’ LAndExp LOrExp'
    private LAndExp lAndExp;
    private LOrExpTemp lOrExpTemp;

    public LOrExp(LAndExp lAndExp, LOrExpTemp lOrExpTemp, ArrayList<String> outputList) {
        this.lAndExp = lAndExp;
        this.lOrExpTemp = lOrExpTemp;
        outputList.add("<LOrExp>");
    }

    public LOrExp(LAndExp lAndExp, ArrayList<String> outputList) {
        this.lAndExp = lAndExp;
        outputList.add("<LOrExp>");
    }
}
