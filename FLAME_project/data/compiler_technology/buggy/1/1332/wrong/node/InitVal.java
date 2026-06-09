package node;

import token.Token;

import java.util.List;

/**
 * ClassName: InitVal
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 15:41
 * @Version 1.0
 */
public class InitVal extends Node{
    // InitVal => Exp | '{' Exp {',' Exp} '}' | StringConst

    public List<Exp>exps;

    public Token lbrace;
    public List<Token> commas;
    public Token rbrace;

    public Token stringConst;

    public InitVal(List<Exp> exps) {
        this.exps = exps;
        setLineNo(exps);
    }

    public InitVal(Token lbrace, List<Exp> exps, List<Token> commas, Token rbrace) {
        this.lbrace = lbrace;
        this.exps = exps;
        this.commas = commas;
        this.rbrace = rbrace;
        setLineNo(lbrace);
    }

    public InitVal(Token stringConst) {
        this.stringConst = stringConst;
        setLineNo(stringConst);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        if (lbrace != null) {
            info.append(lbrace.getPrintInfo());
            for (int i = 0; i < exps.size(); i++) {
                info.append(exps.get(i).getPrintInfo());
                if (i < commas.size()) {
                    info.append(commas.get(i).getPrintInfo());
                }
            }
            info.append(rbrace.getPrintInfo());
        } else if (stringConst != null) {
            info.append(stringConst.getPrintInfo());
        } else {
            info.append(exps.get(0).getPrintInfo());
        }
        info.append("<InitVal>\n");
        return info;
    }
}
