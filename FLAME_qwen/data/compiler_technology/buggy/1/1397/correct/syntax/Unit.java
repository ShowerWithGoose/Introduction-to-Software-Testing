package syntax;

import org.w3c.dom.TypeInfo;

import java.util.ArrayList;

public class Unit {
    public record CompUnit(
            ArrayList<Decl> decls,
            ArrayList<FuncDef> funcDefs,
            MainFuncDef mainFuncDef
    ) {}

    public interface Decl extends BlockItem {
    }

    public record ConstDecl(
            String bType,
            ArrayList<ConstDef> constDefs
    ) implements Decl {}

    public record ConstDef(
            String ident,
            ConstExp constExp,
            ConstInitVal constInitVal
    ) {}

    public interface ConstInitVal {
    }

    public record ArrayConstInitVal(
            ArrayList<ConstExp> constExps
    ) implements ConstInitVal {}

    public record StringConst(
            String stringConst
    ) implements ConstInitVal, InitVal {}

    public record VarDecl(
            String bType,
            ArrayList<VarDef> varDefs
    ) implements Decl {}

    public record VarDef(
            String ident,
            ConstExp constExp,
            InitVal initVal
    ) {}

    public interface InitVal {
    }

    public record ArrayInitVal(
            ArrayList<Exp> exps
    ) implements InitVal {}

    public record FuncDef(
            String FuncType,
            String ident,
            FuncFParams funcFParams,
            Block block
    ) {}

    public record MainFuncDef(
            Block block
    ) {}

    public record FuncFParams(
            ArrayList<FuncFParam> funcFParams
    ) {}

    public record FuncFParam(
            String bType,
            String ident,
            boolean isArray
    ) {}

    public record Block(
            ArrayList<BlockItem> blockItems
    ) implements Stmt {}

    public interface BlockItem {
    }

    public interface Stmt extends BlockItem {
    }

    public record AssignStmt(
            LVal lVal,
            Exp exp
    ) implements Stmt {}

    public record ExpStmt(
            Exp exp
    ) implements Stmt {}

    public record IfStmt(
            Cond cond,
            Stmt thenStmt,
            Stmt elseStmt
    ) implements Stmt {}

    public record ForLoopStmt(
            ForStmt initForStmt,
            Cond cond,
            ForStmt updateForStmt,
            Stmt bodyStmt
    ) implements Stmt {}

    public record BreakStmt(

    ) implements Stmt {}

    public record ContinueStmt(

    ) implements Stmt {}

    public record ReturnStmt(
            Exp exp
    ) implements Stmt {}

    public record GetIntStmt(
            LVal lVal
    ) implements Stmt {}

    public record GetCharStmt(
            LVal lVal
    ) implements Stmt {}

    public record PrintfStmt(
            String stringConst,
            ArrayList<Exp> exps
    ) implements Stmt {}

    public record ForStmt(
            LVal lVal,
            Exp exp
    ) {}

    public interface Exp extends InitVal {
    }

    public interface Cond {
    }

    public record LVal(
            String ident,
            Exp exp
    ) implements PrimaryExp {}

    public interface PrimaryExp extends SingleUnaryExp {
    }

    public record BracePrimaryExp(
            Exp exp
    ) implements PrimaryExp {}

    public record Number(
            int number
    ) implements PrimaryExp {}

    public record Character(
            char character
    ) implements PrimaryExp {}

    public record UnaryExp(
            ArrayList<String> unaryOps,
            SingleUnaryExp singleUnaryExp
    ) {}

    public interface SingleUnaryExp {
    }

    public record FuncCall(
            String ident,
            FuncRParams funcRParams
    ) implements SingleUnaryExp {}

    public record FuncRParams(
            ArrayList<Exp> exps
    ) {}

    public record MulExp(
            ArrayList<UnaryExp> unaryExps,
            ArrayList<String> ops
    ) {}

    public record AddExp(
            ArrayList<MulExp> mulExps,
            ArrayList<String> ops
    ) implements Exp, ConstExp {}

    public record RelExp(
            ArrayList<AddExp> addExps,
            ArrayList<String> ops
    ) {}

    public record EqExp(
            ArrayList<RelExp> relExps,
            ArrayList<String> ops
    ) {}

    public record LAndExp(
            ArrayList<EqExp> eqExps
    ) {}

    public record LOrExp(
            ArrayList<LAndExp> lAndExps
    ) implements Cond {}

    public interface ConstExp extends ConstInitVal {
    }
}
