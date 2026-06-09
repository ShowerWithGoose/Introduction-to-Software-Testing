package frontend.Parser.Class;

import frontend.Lexer.Token;

import java.util.ArrayList;

public class ConstDecl extends Decl {
    // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    private final BType bType;
    private final ArrayList<ConstDef> constDefs;
    public ConstDecl(BType bType, ArrayList<ConstDef> constDefs,ArrayList<String> outputList) {
        this.bType = bType;
        this.constDefs = constDefs;
        outputList.add("<ConstDecl>");
        super.printName(outputList);
    }
}
