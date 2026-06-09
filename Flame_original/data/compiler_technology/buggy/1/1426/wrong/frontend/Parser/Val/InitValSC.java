package frontend.Parser.Val;

import frontend.Parser.solid.StringConst;

public class InitValSC implements InitValInf {
    private StringConst sc;

    public InitValSC(StringConst sc){
        this.sc = sc;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.sc.Parser_Output());
        return sb.toString();
    }
}
