package exeptions;

import frontend.parser.decl.types.Def;
import frontend.parser.expr.types.LVal;
import frontend.parser.func.types.FuncDef;
import frontend.parser.func.types.FuncFParam;
import frontend.parser.func.types.FuncFParams;
import frontend.parser.stmt.types.Stmt;

public class ErrorHandler {
    public static Error RedefinedToken(Def def) {
        return new Error(ErrorType.REDEFINED_TOKEN, def.getIdent().getLine());
    }
    public static Error RedefinedToken(FuncFParam param) {
        return new Error(ErrorType.REDEFINED_TOKEN, param.getIdent().getLine());
    }
    public static Error RedefinedToken(FuncDef funcDef) {
        return new Error(ErrorType.REDEFINED_TOKEN, funcDef.getIdent().getLine());
    }
    public static Error UndefinedToken(LVal lVal) {
        return new Error(ErrorType.UNDEFINED_TOKEN, lVal.getIdent().getLine());
    }
    public static Error MisMatchParamCount(FuncDef funcDef) {
        return new Error(ErrorType.MISMATCH_PARAM_COUNT, funcDef.getIdent().getLine());
    }
    public static Error MisMatchParamType(FuncDef funcDef) {
        return new Error(ErrorType.MISMATCH_PARAM_TYPE, funcDef.getIdent().getLine());
    }
    public static Error IllegalReturn(Stmt returnStmt) {
        if (returnStmt.getReturnTK() != null)
            return new Error(ErrorType.ILLEGAL_RETURN, returnStmt.getReturnTK().getLine());
        System.err.println("ErrorHandler: IllegalReturn get a stmt that is not a returnStmt");
        return null;
    }
    public static Error MissReturn(FuncDef funcDef) {
        return new Error(ErrorType.MISS_RETURN, funcDef.getBlock().getRBrace().getLine());
    }
    public static Error ModifyConst(LVal lVal) {

        return new Error(ErrorType.MODIFY_CONST, lVal.getIdent().getLine());
    }
    public static Error MisMatchPrintf(Stmt stmt) {
        if (stmt.getPrintTK() != null)
            return new Error(ErrorType.MISMATCH_PRINTF, stmt.getPrintTK().getLine());
        System.err.println("ErrorHandler: MisMatchPrintf get a stmt that is not a printfStmt");
        return null;
    }
    public static Error IllegalBreakContinue(Stmt stmt) {
        if (stmt.getBreakContinueTK() != null)
            return new Error(ErrorType.ILLEGAL_BREAK_CONTINUE, stmt.getBreakContinueTK().getLine());
        System.err.println("ErrorHandler: IllegalBreakContinue get a stmt that is not a breakContinueStmt");
        return null;
    }
}
