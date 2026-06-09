package Paser.Stmt;

import Paser.Exp.Exp;
import Paser.Node;
import Paser.TokenNode;
import Reader.Token;
import Type.SyntaxVarType;

import java.util.ArrayList;

//  'printf''('StringConst {','Exp}')'';'
public class PrintfStmt extends Stmt {
    private Token formatString;
    private ArrayList<Exp> expList;

    public PrintfStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
        // get formatString and expList;
        this.expList = new ArrayList<>();
        for (Node child : children) {
            // formatString
            if (child instanceof TokenNode && ((TokenNode) child).getToken().getType() == Token.TokenType.STRCON) {
                this.formatString = ((TokenNode) child).getToken();
            }
            // expList;
            if (child instanceof Exp) {
                this.expList.add((Exp) child);
            }
        }
    }
}
