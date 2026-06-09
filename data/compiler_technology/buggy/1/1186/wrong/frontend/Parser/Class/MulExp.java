package frontend.Parser.Class;

import java.util.ArrayList;

public class MulExp {
    // MulExp â†’ UnaryExp MulExp'
    private UnaryExp unaryExp;
    private MulExpTemp mulExpTemp;

    public MulExp(UnaryExp unaryExp, ArrayList<String> outputList) {
        this.unaryExp = unaryExp;
        outputList.add("<MulExp>");
    }

    public MulExp(UnaryExp unaryExp, MulExpTemp mulExpTemp, ArrayList<String> outputList) {
        this.unaryExp = unaryExp;
        this.mulExpTemp = mulExpTemp;
        outputList.add("<MulExp>");
    }
}
