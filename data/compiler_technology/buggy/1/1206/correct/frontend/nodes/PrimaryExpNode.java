package frontend.nodes;

import frontend.token;
import print.out;

import java.io.IOException;

/**
 * @author
 * @Description:
 * @date 2024/10/10 8:20
 */
public class PrimaryExpNode {
    //PrimaryExp → '(' Exp ')' | LVal | Number | Character
    token lparent;
    token rparent;
    ExpNode expNode;
    LvalNode lvalNode;
    NumberNode numberNode;
    CharacterNode characterNode ;
    public PrimaryExpNode(token lparent,token rparent,ExpNode expNode){
        this.lparent=lparent;
        this.rparent=rparent;
        this.expNode=expNode;
    }
    public PrimaryExpNode(LvalNode lvalNode){
        this.lvalNode=lvalNode;
    }
    public PrimaryExpNode(NumberNode numberNode){
        this.numberNode=numberNode;
    }
    public PrimaryExpNode(CharacterNode characterNode){
        this.characterNode=characterNode;
    }
    public void output() throws IOException {
        if(lparent!=null){
            out.write(lparent.toString());
            expNode.output();
            out.write(rparent.toString());
        }else if(lvalNode!=null){
            lvalNode.output();
        }else if(numberNode!=null){
            numberNode.output();
        }else if(characterNode!=null){
            characterNode.output();
        }
        out.write("<PrimaryExp>");
    }
}
