package node;

import token.Token;

import java.util.List;

/**
 * ClassName: ConstInitVal
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:54
 * @Version 1.0
 */
public class ConstInitVal extends Node {
    // ConstInitVal -> ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public List<ConstExp> constExps;
    // {1, 2, 3} 数组初值
    public Token lbrace;
    public Token rbrace;
    public List<Token> commas;

    // "hello world" 字符串初值
    public Token stringConst;

    // ConstInitVal -> ConstExp
    public ConstInitVal(List<ConstExp> constExps) {
        this.constExps = constExps;
        setLineNo(constExps);
    }
    // ConstInitVal -> StringConst
    public ConstInitVal(Token stringConst) {
        this.stringConst = stringConst;
        setLineNo(stringConst);
    }
    // ConstInitVal -> '{' [ ConstExp { ',' ConstExp } ] '}'
    public ConstInitVal(Token lbrace, List<ConstExp> constExps, List<Token> commas, Token rbrace) {
        this.lbrace = lbrace;
        this.constExps = constExps;
        this.commas = commas;
        this.rbrace = rbrace;
        setLineNo(lbrace);
    }

    public StringBuilder getPrintInfo() {
        StringBuilder info = new StringBuilder();
        // ConstInitVal -> '{' [ ConstExp { ',' ConstExp } ] '}'
        if (lbrace != null) {
            info.append(lbrace.getPrintInfo());
            for (int i = 0; i < constExps.size(); i++) {
                info.append(constExps.get(i).getPrintInfo());
                if (i < commas.size()) {
                    info.append(commas.get(i).getPrintInfo());
                }
            }
            info.append(rbrace.getPrintInfo());
        }
        // ConstInitVal -> StringConst
        else if (stringConst != null) {
            info.append(stringConst.getPrintInfo());
        }
        // ConstInitVal -> ConstExp
        else {
            info.append(constExps.get(0).getPrintInfo());
        }
        info.append("<ConstInitVal>\n");
        return info;
    }
}
