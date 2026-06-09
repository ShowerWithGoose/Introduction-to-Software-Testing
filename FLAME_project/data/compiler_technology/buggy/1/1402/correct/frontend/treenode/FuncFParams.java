package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import static frontend.executor.Parser.writeParser;

// 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
public class FuncFParams {
    public String nodeName;
    public List<FuncFParam> funcFParamList = new ArrayList<>();
    public List<Token> commaTokenList = new ArrayList<>();

    public FuncFParams(String nodeName, List<FuncFParam> funcFParamList, List<Token> commaTokenList) {
        this.nodeName = nodeName;
        this.funcFParamList = funcFParamList;
        this.commaTokenList = commaTokenList;
    }

    public void print() throws IOException {
        funcFParamList.get(0).print();
        if (!commaTokenList.isEmpty()) {
            for (int i = 1; i < funcFParamList.size(); i++) {
                writeParser(commaTokenList.get(i - 1).getTypeAndContent());
                funcFParamList.get(i).print();
            }
        }
        writeParser(nodeName);
    }
}
