package node;

import token.Token;

import java.util.List;

/**
 * ClassName: Node
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:01
 * @Version 1.0
 */
public class Node {
    public Integer lineNo;

    public void setLineNo(Node node){
        if (node != null){
            this.lineNo = node.lineNo;
//            if (this.lineNo == 0){
//                throw new RuntimeException("lineNo is 0 when setLineNo in Node");
//            }
        }
    }

    public void setLineNo(Token token){
        if (token != null){
            this.lineNo = token.lineNo;
        }
    }

    public void setLineNo(List<?extends Node> list){
        if (list.size() > 0){
            setLineNo(list.get(0));
        }
    }
}
