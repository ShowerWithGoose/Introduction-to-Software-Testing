package AST;

import java.io.IOException;
import java.util.ArrayList;
import IO.*;
public class PrintfStmt extends ASTNode{

    ASTNodes type = ASTNodes.PrintfStmt;

    Integer printLine;
    StringConst stringConst;
    ArrayList<ExprNode> exps;

    public PrintfStmt(Integer printLine, StringConst stringConst, ArrayList<ExprNode> exps) {
        this.printLine =printLine;
        this.stringConst = stringConst;
        this.exps = exps;
    }

    public ASTNodes getType() {
        return type;
    }

    public ArrayList<ExprNode> getExps() {
        return exps;
    }

    public StringConst getStringConst() {
        return stringConst;
    }

//    public void findErrorOf_i() {
//        ArrayList<String> formatChars = this.stringConst.getFormatChars();
//        int exprNum = exps.size();
//        if (formatChars.size() != exprNum) {
//            errorMessage.addError(new error("PrintfStmt", printLine, "l"));
//        }
//    }


    public Integer getPrintLine() {
        return printLine;
    }

    
    public void postOrderTraversal(IO io) throws IOException {
//        findErrorOf_i();
        io.getParserWriter().write("PRINTFTK printf\n");
        io.getParserWriter().write("LPARENT (\n");
        stringConst.postOrderTraversal(io);
        for (ExprNode e : exps) {
            io.getParserWriter().write("COMMA ,\n");
            e.postOrderTraversal(io);
        }
        io.getParserWriter().write("RPARENT )\n");
        io.getParserWriter().write("SEMICN ;\n");
    }

    public void postOrderNoPrint() {
//        findErrorOf_i();
        stringConst.postOrderNoPrint();
        for (ExprNode e : exps) {
            e.postOrderNoPrint();
        }
    }


}
