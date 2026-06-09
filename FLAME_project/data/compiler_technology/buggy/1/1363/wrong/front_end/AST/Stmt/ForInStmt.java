package front_end.AST.Stmt;

import front_end.AST.Exp.CondExp;
import front_end.AST.Node;
import front_end.symbol.SymbolManager;
//import llvm_ir.*;
//import llvm_ir.instr.JumpInstr;
import utils.SyntaxVarType;

import java.util.ArrayList;

public class ForInStmt extends Stmt {
    public ForInStmt(int startLine, int endLine, SyntaxVarType type, ArrayList<Node> children) {
        super(startLine, endLine, type, children);
    }
}
