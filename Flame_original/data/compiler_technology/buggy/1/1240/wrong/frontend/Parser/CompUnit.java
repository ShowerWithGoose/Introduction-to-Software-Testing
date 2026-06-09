package frontend.Parser;

import frontend.Parser.Del.Type.Decl;
import frontend.Parser.Func.Type.FuncDef;
import frontend.Parser.Func.Type.MainFuncDef;

import java.util.ArrayList;

public class CompUnit {
    // 编译单元 CompUnit → {Decl} {FuncDef} MainFuncDef
    private final ArrayList<Decl> globalVariables;
    private final ArrayList<FuncDef> functions;
    private final MainFuncDef mainFunction;

    public CompUnit(ArrayList<Decl> globalVariables, ArrayList<FuncDef> functions,
                    MainFuncDef mainFunction) {
        this.globalVariables = globalVariables;
        this.functions = functions;
        this.mainFunction = mainFunction;
    }


    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Decl decl : globalVariables) {
            sb.append(decl.toString());
        }
        for (FuncDef funcDef : functions) {
            sb.append(funcDef.toString());
        }
        sb.append(mainFunction.toString());
        sb.append("<CompUnit>\n");
        return sb.toString();
    }
}
