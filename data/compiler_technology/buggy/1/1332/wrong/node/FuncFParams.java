package node;

import token.Token;

import java.util.List;

/**
 * ClassName: FuncFParams
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 15:59
 * @Version 1.0
 */
public class FuncFParams extends Node{
    // FuncFParams => FuncFParam { ',' FuncFParam }

    public List<FuncFParam> funcFParams;
    public List<Token> commas;

    public FuncFParams(List<FuncFParam> funcFParams, List<Token> commas) {
        this.funcFParams = funcFParams;
        this.commas = commas;
        setLineNo(funcFParams);
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        if (funcFParams == null) {
            return info;
        }

        for (int i = 0; i < funcFParams.size(); i++) {
            info.append(funcFParams.get(i).getPrintInfo());
            if (commas != null && i < commas.size()) {
                info.append(commas.get(i).getPrintInfo());
            }
        }
        info.append("<FuncFParams>\n");
        return info;
    }
}
