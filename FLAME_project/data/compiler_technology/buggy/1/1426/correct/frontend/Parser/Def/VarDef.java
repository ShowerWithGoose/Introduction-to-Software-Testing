package frontend.Parser.Def;

import frontend.Parser.Output;

//变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '='
//InitVal // 包含普通常量、一维数组定义
public class VarDef implements Output {
    private final String name = "<VarDef>";
    private VarDefInf varDefInf;

    public VarDef(VarDefInf varDefInf) {
        this.varDefInf = varDefInf;
    }

    @Override
    public String Parser_Output() {
        StringBuilder sb = new StringBuilder();
        sb.append(this.varDefInf.Parser_Output());
        sb.append(this.name + "\n");
        return sb.toString();
    }
}
