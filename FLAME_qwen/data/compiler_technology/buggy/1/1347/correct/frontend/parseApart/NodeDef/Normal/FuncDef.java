package frontend.parseApart.NodeDef.Normal;

import frontend.LexType;
import frontend.Token;
import frontend.parseApart.NodeDef.Block;

import java.util.ArrayList;

public class FuncDef {

    private LexType lexType;
    private String name;
    private int line;
    private ArrayList<FuncFParam> funcFParams = new ArrayList<>();
    private Block block;

    public FuncDef() {}

    public void setBlock(Block block) {
        this.block = block;
    }

    public void setLexType(LexType lexType) {
        this.lexType = lexType;
    }

    public void setFuncFParams(FuncFParam funcFParam) {
        this.funcFParams.add(funcFParam);
    }

    public void setNameAndLine(Token token) {
        this.line = token.getLine();
        this.name = token.getName();
    }

    public String returnSymbolType() {
        String string = "<FuncDef>";
        return string;
    }
}
