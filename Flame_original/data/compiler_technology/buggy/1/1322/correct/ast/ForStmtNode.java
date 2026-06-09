package ast;

import IO.IO;
import enum_package.NodeType;
import frontend.Token;
import frontend.Parser;

public class ForStmtNode {
    // ForStmt → LVal '=' Exp
    public LValNode lVal;
    public Token assign; // 指向 '=' 的叶节点
    public ExpNode exp;

    public ForStmtNode(LValNode lVal, Token assign, ExpNode exp) {
        this.lVal = lVal; // 保存左值
        this.assign = assign; // 设置 '='
        this.exp = exp; // 保存表达式
    }

    public void print() {
        lVal.print();
        IO.write(assign.toString());
        exp.print();
        IO.write(Parser.nodeTypeLabel.get(NodeType.ForStmt));
    }
}
