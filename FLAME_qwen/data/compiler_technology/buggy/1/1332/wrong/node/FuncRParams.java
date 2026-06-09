package node;

import token.Token;

import java.util.List;

/**
 * ClassName: FuncRParams
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 11:32
 * @Version 1.0
 */
public class FuncRParams extends Node{
    // FuncRParams -> Exp {, Exp}

    public List<Exp> exps;
    public List<Token> commas;

    public FuncRParams(List<Exp> exps, List<Token> commas) {
        this.exps = exps;
        this.commas = commas;
        setLineNo(exps);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();

        if(exps == null){ // 说明没有实参，也就不需要这个节点
            return info;
        }

        for (int i = 0; i < exps.size(); i++) {
            info.append(exps.get(i).getPrintInfo());
            if (commas != null && i < commas.size()) {
                info.append(commas.get(i).getPrintInfo());
            }
        }
        info.append("<FuncRParams>\n");
        return info;
    }
}
