package frontend.treenode;

import frontend.token.Token;

import java.io.IOException;
import java.util.List;

import static frontend.executor.Parser.writeParser;

// 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
public class InitVal {
    public String nodeName;
    public Token lbraceToken, rbraceToken, stringToken;
    public List<Exp> expList;
    public List<Token> commaTokenList;

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
            writeParser(lbraceToken.getTypeAndContent());
            if (!expList.isEmpty()) { //中括号内不为空
                expList.get(0).print();
                if (!commaTokenList.isEmpty()) { //花括号内不为空
                    for (int i = 1; i < expList.size(); i++) {
                        writeParser(commaTokenList.get(i - 1).getTypeAndContent());
                        expList.get(i).print();
                    }
                }
            }
            writeParser(rbraceToken.getTypeAndContent());
        } else if (stringToken != null) { //是StringConst
            writeParser(stringToken.getTypeAndContent());
        } else { //是Exp
            expList.get(0).print();
        }
        writeParser(nodeName);
    }
}
