package frontend.parser;

import frontend.DataType;
import frontend.ir.constValue.ConstInt;
import frontend.lexer.Token;

import java.util.ArrayList;

public class Ast {
    public ArrayList<CompUnit> nodes;

    public Ast(ArrayList<CompUnit> nodes) {
        this.nodes = nodes;
    }

    public interface CompUnit {
    }

    // Decl -> ['const'] BType Def {',' Def} ';'
    public static class Decl extends BlockItem implements CompUnit{
        private final boolean isConst;
        private final DataType bType;
        public final ArrayList<Def> defs;

        public Decl(boolean isConst, DataType bType, ArrayList<Def> defs) {
            this.isConst = isConst;
            this.bType = bType;
            this.defs = defs;
        }

        public boolean isConst() {
            return isConst;
        }

        public DataType getbType() {
            return bType;
        }

        public ArrayList<Def> getDefs() {
            return defs;
        }
    }
    public static class Def {
        private final DataType bType;
        private final Token ident;
        private final Exp index;
        private final InitValue initValue;

        public Def(DataType type, Token ident, Exp index, InitValue initValue) {
            this.bType = type;
            this.ident = ident;
            this.index = index;
            this.initValue = initValue;
        }

        public DataType getbType() {
            return bType;
        }

        public Token getIdent() {
            return ident;
        }

        public Exp getIndex() {
            return index;
        }

        public InitValue getInit() {
            return initValue;
        }
    }
    public static class Exp extends PrimaryExp {
//        boolean checkConst();
//        ConstInt getConstInt();
    }

    public static class InitValue {
        private final boolean isString;
        private final ArrayList<Exp> valueList;
        private final StringConst stringConst;
        private final boolean isSimpleArray;

        public InitValue(boolean isString, ArrayList<Exp> valueList, StringConst stringConst, boolean isSimpleArray) {
            this.isString = isString;
            this.valueList = valueList;
            this.stringConst = stringConst;
            this.isSimpleArray = isSimpleArray;
        }

        public boolean isString() {
            return isString;
        }

        public ArrayList<Exp> getValueList() {
            return valueList;
        }

        public StringConst getStringConst() {
            return stringConst;
        }

        public boolean isSimpleArray() {
            return isSimpleArray;
        }
    }

    /*
    * anon: 是否有存在的必要
    * */
    public static class StringConst {
        private final String string;

        public StringConst(String string) {
            this.string = string;
        }

        public String getString() {
            return string;
        }
    }

    // FuncDef -> FuncType Ident '(' [FuncFParams] ')' Block
    // FuncFParams -> FuncFParam {',' FuncFParam}
    public static class FuncDef implements CompUnit{
        private final DataType funcType;
        public final Token funcName;
        private final ArrayList<FuncFParam> params;
        public final Block block;

        public FuncDef(DataType funcType, Token funcName, ArrayList<FuncFParam> params, Block block) {
            this.funcType = funcType;
            this.funcName = funcName;
            this.params = params;
            this.block = block;
        }

        public DataType getFuncType() {
            return funcType;
        }

        public Token getFuncName() {
            return funcName;
        }

        public ArrayList<FuncFParam> getParams() {
            return params;
        }

        public Block getBlock() {
            return block;
        }
    }


    public static class FuncFParam implements CompUnit{
        private final DataType bType;
        private final Token varName;
        private final boolean isArray;

        public FuncFParam(DataType bType, Token varName, boolean isArray) {
            this.bType = bType;
            this.varName = varName;
            this.isArray = isArray;
        }

        public DataType getbType() {
            return bType;
        }

        public Token getVarName() {
            return varName;
        }

        public boolean isArray() {
            return isArray;
        }
    }

    public static class Block extends Stmt implements CompUnit {
        private final ArrayList<BlockItem> items;
        public Block(ArrayList<BlockItem> items) {
            this.items = items;
        }

        public ArrayList<BlockItem> getItems() {
            return items;
        }
    }
    // BlockItem -> Decl | Stmt
    public static class BlockItem {
    }
    public static class Stmt extends BlockItem{
    }
    public static class Assign extends Stmt {
        private final LVal lVal;
        private final Exp exp;

        public Assign(LVal lVal, Exp exp) {
            this.lVal = lVal;
            this.exp = exp;
        }

        public LVal getlVal() {
            return lVal;
        }

        public Exp getExp() {
            return exp;
        }
    }
    public static class ExpStmt extends Stmt {
        private final Exp exp;

        public ExpStmt(Exp exp) {
            this.exp = exp;
        }

        public Exp getExp() {
            return exp;
        }
    }

    public static class IfStmt extends Stmt {
        private final Exp cond;
        private final Stmt thenStmt;
        private final Stmt elseStmt;
        public IfStmt(Exp cond, Stmt thenStmt, Stmt elseStmt) {
            this.cond = cond;
            this.thenStmt = thenStmt;
            this.elseStmt = elseStmt;
        }

        public Exp getCond() {
            return cond;
        }

        public Stmt getThenStmt() {
            return thenStmt;
        }

        public Stmt getElseStmt() {
            return elseStmt;
        }
    }

    public static class LoopStmt extends Stmt {
        private final Stmt beginStmt;
        private final Exp cond;
        private final Stmt endStmt;
        private final Stmt bodyStmt;
        public LoopStmt(ForStmt beginStmt, Exp cond, ForStmt endStmt, Stmt bodyStmt) {
            this.beginStmt = beginStmt;
            this.cond = cond;
            this.endStmt = endStmt;
            this.bodyStmt = bodyStmt;
        }

        public Stmt getBeginStmt() {
            return beginStmt;
        }

        public Exp getCond() {
            return cond;
        }

        public Stmt getEndStmt() {
            return endStmt;
        }

        public Stmt getBodyStmt() {
            return bodyStmt;
        }
    }

    /*
    * anon：有必要？
    * */
    public static class ForStmt extends Assign {
        public ForStmt(LVal lVal, Exp exp) {
            super(lVal, exp);
        }
    }
    public static class BreakStmt extends Stmt {
    }
    public static class ContinueStmt extends Stmt {
    }
    public static class ReturnStmt extends Stmt {
        private final Exp returnExp;

        public ReturnStmt(Exp returnExp) {
            this.returnExp = returnExp;
        }

        public Exp getReturnExp() {
            return returnExp;
        }
    }
    public static class GetIntStmt extends Stmt {
        private final LVal lVal;

        public GetIntStmt(LVal lVal) {
            this.lVal = lVal;
        }

        public LVal getlVal() {
            return lVal;
        }
    }
    public static class GetCharStmt extends Stmt {
        private final LVal lVal;

        public GetCharStmt(LVal lVal) {
            this.lVal = lVal;
        }

        public LVal getlVal() {
            return lVal;
        }
    }
    public static class PrintfStmt extends Stmt {
        private final StringConst stringConst;
        private final ArrayList<Exp> exps;

        public PrintfStmt(StringConst stringConst, ArrayList<Exp> exps) {
            this.stringConst = stringConst;
            this.exps = exps;
        }

        public StringConst getStringConst() {
            return stringConst;
        }

        public ArrayList<Exp> getExps() {
            return exps;
        }
    }
    // Init -> Exp | InitArray | StringConst
    // Exp -> BinaryExp | UnaryExp

    // BinaryExp: Arithmetic, Relation, Logical
    // BinaryExp -> UnaryExp { Op UnaryExp }, calc from left to right
    public static class BinaryExp extends Exp {
        private final ArrayList<Exp> exps;
        private final ArrayList<String> ops;

        public BinaryExp(ArrayList<Exp> exps, ArrayList<String> ops) {
            this.exps = exps;
            this.ops = ops;
        }

        public ArrayList<Exp> getExps() {
            return exps;
        }

        public ArrayList<String> getOps() {
            return ops;
        }
    }

    // UnaryExp -> {UnaryOp} PrimaryExp
    public static class UnaryExp extends Exp {
        private final PrimaryExp primaryExp;
        private final ArrayList<String> ops;

        public UnaryExp(PrimaryExp primaryExp, ArrayList<String> ops) {
            this.primaryExp = primaryExp;
            this.ops = ops;
        }

        public PrimaryExp getPrimaryExp() {
            return primaryExp;
        }

        public ArrayList<String> getOps() {
            return ops;
        }
    }

    // PrimaryExp -> Call | '(' Exp ')' | LVal | Number | Character
    public static class PrimaryExp {
    }

    // LVal -> Ident ['[' Exp ']']
    public static class LVal extends PrimaryExp {
        private final Token ident;
        private final Exp exp;

        public LVal(Token ident, Exp exp) {
            this.ident = ident;
            this.exp = exp;
        }

        public Token getIdent() {
            return ident;
        }

        public Exp getExp() {
            return exp;
        }
    }
    public static class Number extends PrimaryExp {
        private final Token number;

        public Number(Token number) {
            this.number = number;
        }

        public Token getNumber() {
            return number;
        }
    }
    public static class Character extends PrimaryExp {
        private final Token character;

        public Character(Token character) {
            this.character = character;
        }

        public Token getCharacter() {
            return character;
        }
    }
    public static class Call extends PrimaryExp {
        private final Token ident;
        private final ArrayList<Exp> params;

        public Call(Token ident, ArrayList<Exp> params) {
            this.ident = ident;
            this.params = params;
        }

        public Token getIdent() {
            return ident;
        }

        public ArrayList<Exp> getParams() {
            return params;
        }
    }
}
