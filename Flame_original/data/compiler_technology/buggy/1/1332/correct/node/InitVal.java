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
    // InitVal => Exp | '{' [Exp {',' Exp}] '}' | StringConst

    public Exp exp;

    public Token lbrace;
    public List<Exp>exps;
    public List<Token> commas;
    public Token rbrace;

    public Token stringConst;

    public InitVal(Exp exp) {
        this.exp = exp;
        setLineNo(exp);
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
        // InitVal => Exp | '{' [Exp {',' Exp}] '}' | StringConst
        StringBuilder info = new StringBuilder();
        if (lbrace != null) {
            info.append(lbrace.getPrintInfo());
            if(exps != null){
                for (int i = 0; i < exps.size(); i++) {
                    info.append(exps.get(i).getPrintInfo());
                    if (i < commas.size()) {
                        info.append(commas.get(i).getPrintInfo());
                    }
                }
            }
            info.append(rbrace.getPrintInfo());
        } else if (stringConst != null) {
            info.append(stringConst.getPrintInfo());
        } else {
            info.append(exp.getPrintInfo());
        }
        info.append("<InitVal>\n");
        return info;
    }
}
