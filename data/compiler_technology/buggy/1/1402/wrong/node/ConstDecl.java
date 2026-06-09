package node;

import token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static utils.IO.writeParser;

// 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
public class ConstDecl {
    private String nodeName;
    private Token constToken;
    private BType bType;
    private List<ConstDef> constDefList = new ArrayList<>();
    private List<Token> commaTokenList = new ArrayList<>();
    private Token semiToken;

    public ConstDecl(String nodeName, Token constToken, BType bType, List<ConstDef> constDefList, List<Token> commaTokenList, Token semiToken) {
        this.nodeName = nodeName;
        this.constToken = constToken;
        this.bType = bType;
        this.constDefList = constDefList;
        this.commaTokenList = commaTokenList;
        this.semiToken = semiToken;
    }

    // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    public void print() throws IOException {
        writeParser(constToken.toString());
        bType.print();
        constDefList.get(0).print();
        if (!commaTokenList.isEmpty()) {
            for(int i = 1;i<constDefList.size();i++){
                writeParser(commaTokenList.get(i-1).toString());
                constDefList.get(i).print();
            }
        }
        writeParser(semiToken.toString());
        writeParser(nodeName);
    }
}
