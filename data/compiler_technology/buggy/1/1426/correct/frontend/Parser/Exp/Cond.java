package frontend.Parser.Exp;
import frontend.Parser.Output;

//条件表达式 Cond → LOrExp // 存在即可
public class Cond implements Output {
    private final String name = "<Cond>";
    private LOrExp lOrExp;

    public Cond(LOrExp lOrExp) {
        this.lOrExp = lOrExp;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(lOrExp.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
