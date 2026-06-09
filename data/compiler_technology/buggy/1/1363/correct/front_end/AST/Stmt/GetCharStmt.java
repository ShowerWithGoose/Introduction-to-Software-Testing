package front_end.AST.Stmt;

import front_end.AST.Node;
import utils.SyntaxVarType;

import java.util.ArrayList;

// GetIntStmt ==> LVal '=' 'getchar''('')'';'
public class GetCharStmt extends Stmt {
    public GetCharStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }

//    @Override
//    public void checkError() {
//        // check Error h
//        LValExp lValExp = (LValExp) children.get(0);
//        if (lValExp.isConst()) {
//            Printer.addErrorMsg(lValExp.getEndLine(), ErrorType.h);
//        }
//        super.checkError();
//    }
//
//    @Override
//    public Value genIR() {
//        Value pointer = ((LValExp) children.get(0)).genIRForAssign();
//        IOInstr.GetInt value = new IOInstr.GetInt(IRBuilder.getInstance().genLocalVarName());
//        Instr instr = new StoreInstr(IRBuilder.getInstance().genLocalVarName(), value, pointer);
//        return instr;
//    }
}
