package frontend.Parser.Func.Type;

public class MainFuncDef {
    // MainFuncDef â†’ 'int' 'main' '(' ')' Block
    private final FuncDef funcDef;

    public MainFuncDef(FuncDef funcDef) {
        this.funcDef = funcDef;
    }

    @Override
    public String toString() {
        return funcDef.print(true) + "<MainFuncDef>\n";
    }
}
