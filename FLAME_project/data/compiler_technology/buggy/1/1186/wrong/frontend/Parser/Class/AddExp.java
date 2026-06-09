package frontend.Parser.Class;

import java.util.ArrayList;

public class AddExp {
    // AddExp â†’ MulExp AddExp'
    private MulExp mulExp;
    public AddExpTemp addExpTemp;

    public AddExp(MulExp mulExp, ArrayList<String> outputList) {
        this.mulExp = mulExp;
        outputList.add("<AddExp>");
    }

    public AddExp(MulExp mulExp, AddExpTemp addExpTemp, ArrayList<String> outputList) {
        this.mulExp = mulExp;
        this.addExpTemp = addExpTemp;
        outputList.add("<AddExp>");
    }
}
