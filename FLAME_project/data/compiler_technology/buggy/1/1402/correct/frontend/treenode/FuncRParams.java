package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static frontend.executor.Parser.writeParser;

public class FuncRParams {
    public String nodeName;
    public List<Exp> expList = new ArrayList<>();
    public List<Token> commaTokenList = new ArrayList<>();

    public FuncRParams(String nodeName, List<Exp> expList, List<Token> commaTokenList) {
        this.nodeName = nodeName;
        this.expList = expList;
        this.commaTokenList = commaTokenList;
    }

    // 函数实参表 FuncRParams → Exp { ',' Exp }
    public void print() throws IOException {
        expList.get(0).print();
        if (!commaTokenList.isEmpty()) {
            for (int i = 1; i < expList.size(); i++) {
                writeParser(commaTokenList.get(i - 1).getTypeAndContent());
                expList.get(i).print();
            }
        }
        writeParser(nodeName);
    }
}
