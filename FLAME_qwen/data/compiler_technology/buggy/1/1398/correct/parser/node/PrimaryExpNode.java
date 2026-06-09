package parser.node;

import lexer.Token;
import parser.NodeType;

public class PrimaryExpNode {
    int choose;
    /*    PrimaryExp â†’ '(' Exp ')' | LVal | Number | Character// j
          choose1: '(' Exp ')'
          choose2: LVal
          choose3: Number
          choose4: Character
     */
    Token lParentTK, rParentTK;
    ExpNode expNode;
    LValNode lValNode;
    NumberNode numberNode;
    CharacterNode characterNode;

    public PrimaryExpNode(int choose, Token lParentTK, Token rParentTK, ExpNode expNode) {
        this.choose = choose;
        this.lParentTK = lParentTK;
        this.rParentTK = rParentTK;
        this.expNode = expNode;
    }

    public PrimaryExpNode(int choose, NumberNode numberNode) {
        this.choose = choose;
        this.numberNode = numberNode;
    }

    public PrimaryExpNode(int choose, CharacterNode characterNode) {
        this.choose = choose;
        this.characterNode = characterNode;
    }

    public PrimaryExpNode(int choose, LValNode lValNode) {
        this.choose = choose;
        this.lValNode = lValNode;
    }

    public void print() {
        switch (choose)
        {
            case 1:
            {
                lParentTK.print();
                expNode.print();
                rParentTK.print();
                break;
            }
            case 2:
                lValNode.print();
                break;
            case 3:
                numberNode.print();
                break;
            case 4:
                characterNode.print();
                break;
            default:
                System.out.println("error in primaryExp");
        }
        System.out.println(NodeType.PrimaryExp);
    }
}
