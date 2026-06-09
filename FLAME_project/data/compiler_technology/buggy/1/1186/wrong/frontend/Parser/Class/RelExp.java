package frontend.Parser.Class;

import java.util.ArrayList;

public class RelExp {
    // RelExp â†’ AddExp RelExp'
    private AddExp addExp;
    private RelExpTemp relExpTemp;

    public RelExp(AddExp addExp, RelExpTemp relExpTemp, ArrayList<String> outputList) {
        this.addExp = addExp;
        this.relExpTemp = relExpTemp;
        outputList.add("<RelExp>");
    }

    public RelExp(AddExp addExp, ArrayList<String> outputList) {
        this.addExp = addExp;
        outputList.add("<RelExp>");
    }
}
