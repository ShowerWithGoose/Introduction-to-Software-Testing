package frontend.treenode;

import frontend.token.Token;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import static frontend.executor.Parser.writeParser;

// 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
public class ConstDecl {
    public String nodeName;
    public Token constToken,semiToken;
    public BType bType;
    public List<ConstDef> constDefList = new ArrayList<>();
    public List<Token> commaTokenList = new ArrayList<>();

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
        writeParser(constToken.getTypeAndContent());
        bType.print();
        constDefList.get(0).print();
        if (!commaTokenList.isEmpty()) {
            for(int i = 1;i<constDefList.size();i++){
                writeParser(commaTokenList.get(i-1).getTypeAndContent());
                constDefList.get(i).print();
            }
        }
        writeParser(semiToken.getTypeAndContent());
        writeParser(nodeName);
    }
}
