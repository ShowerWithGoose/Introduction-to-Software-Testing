package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

//变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
public class VarDecl {
    private String nodeName;
    private BType bType;
    private List<VarDef> varDefList = new ArrayList<>();
    private List<Token> commaTokenList = new ArrayList<>();
    private Token semiToken;

    public VarDecl(String nodeName, BType bType, List<VarDef> varDefList, List<Token> commaTokenList, Token semiToken) {
        this.nodeName = nodeName;
        this.bType = bType;
        this.varDefList = varDefList;
        this.commaTokenList = commaTokenList;
        this.semiToken = semiToken;
    }

    //变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
    public void print() throws IOException {
        bType.print();
        varDefList.get(0).print();
        if (!commaTokenList.isEmpty()) {
            for (int i = 1; i < varDefList.size(); i++) {
                writeParser(commaTokenList.get(i - 1).toString());
                varDefList.get(i).print();
            }
        }
        writeParser(semiToken.toString());
        writeParser(nodeName);
    }
}
