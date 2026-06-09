package Paser.Stmt;

import Paser.Exp.Exp;
import Paser.Node;
import Paser.TokenNode;
import Reader.Token;
import Symbol.SymbolManager;
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

    @Override
    public void createSymbolTable() {
        String s = ((TokenNode) children.get(2)).getToken().getDescription();
        int size = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s.charAt(i) == '%' && s.charAt(i + 1) == 'd') {
                size++;
            } else if (s.charAt(i) == '%' && s.charAt(i + 1) == 'c') {
                size++;
            }
        }
        int expSize = 0;
        for (int i = 4; i < children.size(); i += 2) {
            if (children.get(i) instanceof Exp) {
                expSize++;
            }
        }
        if (size != expSize) {
            SymbolManager.err += startLine + " l\n";// printf参数个数��匹配
        }
        super.createSymbolTable();
    }
}
