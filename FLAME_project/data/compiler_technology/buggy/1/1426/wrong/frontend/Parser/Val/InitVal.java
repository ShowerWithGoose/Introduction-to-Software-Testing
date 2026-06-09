package frontend.Parser.Val;

import frontend.Parser.Output;

//变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst // 1.表达式初值
//2.一维数组初值
public class InitVal implements Output {
    private final String name = "<InitVal>";
    private InitValInf initValInf;

    public InitVal(InitValInf initValInf) {
        this.initValInf = initValInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(initValInf.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
