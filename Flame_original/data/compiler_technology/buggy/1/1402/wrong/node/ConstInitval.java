package node;

import token.Token;

import java.io.IOException;
import java.util.List;

import static utils.IO.writeParser;

//常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
public class ConstInitval {
    private String nodeName;
    private Token lbraceToken;
    private Token rbraceToken;
    private List<ConstExp> constExpList;
    private List<Token> commaTokenList;
    private Token stringToken;

    public ConstInitval(String nodeName, Token lbraceToken, Token rbraceToken, List<ConstExp> constExpList, List<Token> commaTokenList, Token stringToken) {
        this.nodeName = nodeName;
        this.lbraceToken = lbraceToken;
        this.rbraceToken = rbraceToken;
        this.constExpList = constExpList;
        this.commaTokenList = commaTokenList;
        this.stringToken = stringToken;
    }

    //常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public void print() throws IOException {
        if (lbraceToken != null) { // 说明是'{' [ ConstExp { ',' ConstExp } ] '}'
            writeParser(lbraceToken.toString());
            if (!constExpList.isEmpty()) {
                constExpList.get(0).print();
                if (!commaTokenList.isEmpty()) {
                    for (int i = 1; i < constExpList.size(); i++) {
                        writeParser(commaTokenList.get(i - 1).toString());
                        constExpList.get(i).print();
                    }
                }
            }
            writeParser(rbraceToken.toString());
        } else if (stringToken != null) { // 说明是StringConst
            writeParser(stringToken.toString());
        } else { // 是ConstExp
            constExpList.get(0).print();
        }
        writeParser(nodeName);
    }
}
