package node;

import token.Token;

import java.io.IOException;
import java.util.List;

import static utils.IO.writeParser;

// 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
public class InitVal {
    private String nodeName;
    private Token lbraceToken;
    private List<Exp> expList;
    private List<Token> commaTokenList;
    private Token rbraceToken;
    private Token stringToken;

    public InitVal(String nodeName, Token lbraceToken, List<Exp> expList, List<Token> commaTokenList, Token rbraceToken, Token stringToken) {
        this.nodeName = nodeName;
        this.lbraceToken = lbraceToken;
        this.expList = expList;
        this.commaTokenList = commaTokenList;
        this.rbraceToken = rbraceToken;
        this.stringToken = stringToken;
    }

    // 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public void print() throws IOException {
        if (lbraceToken != null) { //是'{' [ Exp { ',' Exp } ] '}'
            writeParser(lbraceToken.toString());
            if (!expList.isEmpty()) { //中括号内不为空
                expList.get(0).print();
                if (!commaTokenList.isEmpty()) { //花括号内不为空
                    for (int i = 1; i < expList.size(); i++) {
                        writeParser(commaTokenList.get(i - 1).toString());
                        expList.get(i).print();
                    }
                }
            }
            writeParser(rbraceToken.toString());
        } else if (stringToken != null) { //是StringConst
            writeParser(stringToken.toString());
        } else { //是Exp
            expList.get(0).print();
        }
        writeParser(nodeName);
    }
}
