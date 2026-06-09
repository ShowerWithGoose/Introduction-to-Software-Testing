package frontend;

import java.util.ArrayList;

public class AST {
    public CompUnit compUnit;

    public AST(CompUnit compUnit) {
        this.compUnit = compUnit;
    }

    // CompUnit → {Decl} {FuncDef} MainFuncDef
    public static class CompUnit {
        private ArrayList<Decl> decls = new ArrayList<>();
        private ArrayList<FuncDef> funcDefs = new ArrayList<>();
        private MainFuncDef mainFuncDef = null;

        public CompUnit() {
        }

        public void addDecl(Decl decl) {
            decls.add(decl);
        }

        public void addFuncDef(FuncDef funcDef) {
            funcDefs.add(funcDef);
        }

        public void setMainFuncDef(MainFuncDef mainFuncDef) {
            this.mainFuncDef = mainFuncDef;
        }

        public ArrayList<Decl> getDecls() {
            return decls;
        }

        public ArrayList<FuncDef> getFuncDefs() {
            return funcDefs;
        }

        public MainFuncDef getMainFuncDef() {
            return mainFuncDef;
        }

        public String getType() {
            return "<CompUnit>";
        }
    }

    // Decl -> ConstDecl | VarDecl
    public static class Decl {
        private ConstDecl constDecl;
        private VarDecl varDecl;

        public Decl(ConstDecl constDecl) {
            this.constDecl = constDecl;
            this.varDecl = null;
        }

        public Decl(VarDecl varDecl) {
            this.varDecl = varDecl;
            this.constDecl = null;
        }

        public ConstDecl getConstDecl() {
            return constDecl;
        }

        public VarDecl getVarDecl() {
            return varDecl;
        }

        public String getType() {
            return "<Decl>";
        }
    }

    // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    public static class ConstDecl {
        private BType bType;
        private ArrayList<ConstDef> constDefs;

        public ConstDecl(BType bType, ArrayList<ConstDef> constDefs) {
            this.bType = bType;
            this.constDefs = constDefs;
        }

        public BType getBType() {
            return bType;
        }

        public ArrayList<ConstDef> getConstDefs() {
            return constDefs;
        }

        public String getType() {
            return "<ConstDecl>";
        }
    }

    // BType → 'int' | 'char'
    public static class BType {
        private String type;

        public BType(String type) {
            this.type = type;
        }

        public String getType() {
            return "<BType>";
        }
    }

    // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public static class ConstDef {
        private String ident;
        private ConstExp constExp = null;
        private ConstInitVal constInitVal;

        public ConstDef(String ident, ConstExp constExp, ConstInitVal constInitVal) {
            this.ident = ident;
            this.constExp = constExp;
            this.constInitVal = constInitVal;
        }

        public ConstDef(String ident, ConstInitVal constInitVal) {
            this.ident = ident;
            this.constInitVal = constInitVal;
        }

        public String getIdent() {
            return ident;
        }

        public ConstExp getConstExp() {
            return constExp;
        }

        public ConstInitVal getConstInitVal() {
            return constInitVal;
        }

        public String getType() {
            return "<ConstDef>";
        }
    }

    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public static class ConstInitVal {
        private ConstExp constExp = null;
        private ArrayList<ConstExp> constExps = new ArrayList<>();
        private String stringConst = null;

        public ConstInitVal(ConstExp constExp) {
            this.constExp = constExp;
        }

        public ConstInitVal(ArrayList<ConstExp> constExps) {
            this.constExps = constExps;
        }

        public ConstInitVal(String stringConst) {
            this.stringConst = stringConst;
        }

        public ConstExp getConstExp() {
            return constExp;
        }

        public ArrayList<ConstExp> getConstExps() {
            return constExps;
        }

        public String getStringConst() {
            return stringConst;
        }

        public String getType() {
            return "<ConstInitVal>";
        }
    }

    // VarDecl → BType VarDef { ',' VarDef } ';'
    public static class VarDecl {
        private BType bType;
        private ArrayList<VarDef> varDefs;

        public VarDecl(BType bType, ArrayList<VarDef> varDefs) {
            this.bType = bType;
            this.varDefs = varDefs;
        }

        public BType getBType() {
            return bType;
        }

        public ArrayList<VarDef> getVarDefs() {
            return varDefs;
        }

        public String getType() {
            return "<VarDecl>";
        }
    }

    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    public static class VarDef {
        private String ident;
        private ConstExp constExp = null;
        private InitVal initVal = null;

        public VarDef(String ident, ConstExp constExp) {
            this.ident = ident;
            this.constExp = constExp;
        }

        public VarDef(String ident, ConstExp constExp, InitVal initVal) {
            this.ident = ident;
            this.constExp = constExp;
            this.initVal = initVal;
        }

        public VarDef(String ident, InitVal initVal) {
            this.ident = ident;
            this.initVal = initVal;
        }

        public VarDef(String ident) {
            this.ident = ident;
        }

        public String getIdent() {
            return ident;
        }

        public ConstExp getConstExp() {
            return constExp;
        }

        public InitVal getInitVal() {
            return initVal;
        }

        public String getType() {
            return "<VarDef>";
        }
    }

    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public static class InitVal {
        private Exp exp = null;
        private ArrayList<Exp> exps = new ArrayList<>();
        private String stringConst = null;

        public InitVal(Exp exp) {
            this.exp = exp;
        }

        public InitVal(ArrayList<Exp> exps) {
            this.exps = exps;
        }

        public InitVal(String stringConst) {
            this.stringConst = stringConst;
        }

        public Exp getExp() {
            return exp;
        }

        public ArrayList<Exp> getExps() {
            return exps;
        }

        public String getStringConst() {
            return stringConst;
        }

        public String getType() {
            return "<InitVal>";
        }
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    public static class FuncDef {
        private FuncType funcType;
        private String ident;
        private FuncFParams funcFParams = null;
        private Block block;

        public FuncDef(FuncType funcType, String ident, Block block) {
            this.funcType = funcType;
            this.ident = ident;
            this.block = block;
        }

        public FuncDef(FuncType funcType, String ident, FuncFParams funcFParams, Block block) {
            this.funcType = funcType;
            this.ident = ident;
            this.funcFParams = funcFParams;
            this.block = block;
        }

        public FuncType getFuncType() {
            return funcType;
        }

        public String getIdent() {
            return ident;
        }

        public FuncFParams getFuncFParams() {
            return funcFParams;
        }

        public Block getBlock() {
            return block;
        }

        public String getType() {
            return "<FuncDef>";
        }
    }

    // MainFuncDef → 'int' 'main' '(' ')' Block
    public static class MainFuncDef {
        private Block block = null;

        public MainFuncDef(Block block) {
            this.block = block;
        }

        public Block getBlock() {
            return block;
        }

        public String getType() {
            return "<MainFuncDef>";
        }
    }

    // FuncType → 'int' | 'char' | 'void'
    public static class FuncType {
        private String type;

        public FuncType(String type) {
            this.type = type;
        }

        public String getType() {
            return "<FuncType>";
        }
    }

    // FuncFParams → FuncFParam { ',' FuncFParam }
    public static class FuncFParams {
        private ArrayList<FuncFParam> funcFParams;

        public FuncFParams(ArrayList<FuncFParam> funcFParams) {
            this.funcFParams = funcFParams;
        }

        public ArrayList<FuncFParam> getFuncFParams() {
            return funcFParams;
        }

        public String getType() {
            return "<FuncFParams>";
        }
    }

    // FuncFParam → BType Ident ['[' ']']
    public static class FuncFParam {
        private BType bType = null;
        private String ident = null;
        private boolean isArray = false;

        public FuncFParam(BType bType, String ident, boolean isArray) {
            this.bType = bType;
            this.ident = ident;
            this.isArray = isArray;
        }

        public BType getBType() {
            return bType;
        }

        public String getIdent() {
            return ident;
        }

        public boolean isArray() {
            return isArray;
        }

        public String getType() {
            return "<FuncFParam>";
        }
    }

    // Block → '{' { BlockItem } '}'
    public static class Block {
        private ArrayList<BlockItem> blockItems;

        public Block(ArrayList<BlockItem> blockItems) {
            this.blockItems = blockItems;
        }

        public ArrayList<BlockItem> getBlockItems() {
            return blockItems;
        }

        public String getType() {
            return "<Block>";
        }
    }

    // BlockItem → Decl | Stmt
    public static class BlockItem {
        private Decl decl = null;
        private Stmt stmt = null;

        public BlockItem(Decl decl) {
            this.decl = decl;
            this.stmt = null;
        }

        public BlockItem(Stmt stmt) {
            this.stmt = stmt;
            this.decl = null;
        }

        public Decl getDecl() {
            return decl;
        }

        public Stmt getStmt() {
            return stmt;
        }

        public String getType() {
            return "<BlockItem>";
        }
    }

    /* Stmt → LVal '=' Exp ';' // 每种类型的语句都要覆盖
            | [Exp] ';' //有无Exp两种情况
            | Block
            | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // 1.有else 2.无else
            | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt // 1. 无缺省，1种情况 2.
            ForStmt与Cond中缺省一个，3种情况 3. ForStmt与Cond中缺省两个，3种情况 4. ForStmt与Cond全部
            缺省，1种情况
            | 'break' ';' | 'continue' ';'
            | 'return' [Exp] ';' // 1.有Exp 2.无Exp
            | LVal '=' 'getint''('')'';'
            | LVal '=' 'getchar''('')'';'
            | 'printf''('StringConst {','Exp}')'';' // 1.有Exp 2.无Exp
     */
    public static class Stmt {
        private LVal lVal = null;
        private Exp exp = null;
        private Block block = null;
        private Cond cond = null;
        private Stmt stmt = null;
        private Stmt elseStmt = null;
        private ForStmt forStmt1 = null;
        private ForStmt forStmt2 = null;
        private String stop = null;
        private String StringConst = null;
        private ArrayList<Exp> exps = null;
        private int type = 0;

        // Stmt → LVal '=' Exp ';'
        public Stmt(LVal lVal, Exp exp) {
            this.lVal = lVal;
            this.exp = exp;
            this.type = 1;
        }

        // Stmt → [Exp] ';'
        public Stmt(Exp exp) {
            this.exp = exp;
            this.type = type;
        }

        // Stmt → Block
        public Stmt(Block block) {
            this.block = block;
            this.type = 3;
        }

        // Stmt → 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
        public Stmt(Cond cond, Stmt stmt) {
            this.cond = cond;
            this.stmt = stmt;
            this.type = 4;
        }

        public Stmt(Cond cond, Stmt stmt, Stmt elseStmt) {
            this.cond = cond;
            this.stmt = stmt;
            this.elseStmt = elseStmt;
            this.type = 4;
        }

        // Stmt → 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
        public Stmt(ForStmt forStmt1, Cond cond, ForStmt forStmt2, Stmt stmt) {
            this.forStmt1 = forStmt1;
            this.cond = cond;
            this.forStmt2 = forStmt2;
            this.stmt = stmt;
            this.type = 5;
        }

        // Stmt → 'break' ';' | 'continue' ';'
        public Stmt(String stop) {
            this.stop = stop;
            this.type = 6;
        }

        // Stmt → 'return' [Exp] ';'
        public Stmt(Exp exp, String ret) {
            this.exp = exp;
            this.type = 7;
        }

        /* Stmt → LVal '=' 'getint''('')'';'
                 LVal '=' 'getchar''('')'';'
         */
        public Stmt(LVal lVal, String stop) {
            this.lVal = lVal;
            this.stop = stop;
            this.type = 8;
        }

        // Stmt → 'printf''('StringConst {','Exp}')'';'
        public Stmt(String StringConst, ArrayList<Exp> exps) {
            this.StringConst = StringConst;
            this.exps = exps;
            this.type = 9;
        }

        public LVal getLVal() {
            return lVal;
        }

        public Exp getExp() {
            return exp;
        }

        public Block getBlock() {
            return block;
        }

        public Cond getCond() {
            return cond;
        }

        public Stmt getStmt() {
            return stmt;
        }

        public Stmt getElseStmt() {
            return elseStmt;
        }

        public ForStmt getForStmt1() {
            return forStmt1;
        }

        public ForStmt getForStmt2() {
            return forStmt2;
        }

        public String getStop() {
            return stop;
        }

        public String getStringConst() {
            return StringConst;
        }

        public ArrayList<Exp> getExps() {
            return exps;
        }

        public int getStmtType() {
            return type;
        }

        public String getType() {
            return "<Stmt>";
        }
    }

    // ForStmt → LVal '=' Exp
    public static class ForStmt {
        private LVal lVal = null;
        private Exp exp = null;

        public ForStmt(LVal lVal, Exp exp) {
            this.lVal = lVal;
            this.exp = exp;
        }

        public LVal getLVal() {
            return lVal;
        }

        public Exp getExp() {
            return exp;
        }

        public String getType() {
            return "<ForStmt>";
        }
    }

    // Exp → AddExp
    public static class Exp {
        private AddExp addExp;

        public Exp(AddExp addExp) {
            this.addExp = addExp;
        }

        public AddExp getAddExp() {
            return addExp;
        }

        public String getType() {
            return "<Exp>";
        }
    }

    // Cond → LOrExp
    public static class Cond {
        private LOrExp lOrExp;

        public Cond(LOrExp lOrExp) {
            this.lOrExp = lOrExp;
        }

        public LOrExp getLOrExp() {
            return lOrExp;
        }

        public String getType() {
            return "<Cond>";
        }
    }

    // LVal → Ident ['[' Exp ']']
    public static class LVal {
        private String ident;
        private Exp exp = null;

        public LVal(String ident) {
            this.ident = ident;
        }

        public LVal(String ident, Exp exp) {
            this.ident = ident;
            this.exp = exp;
        }

        public String getIdent() {
            return ident;
        }

        public Exp getExp() {
            return exp;
        }

        public String getType() {
            return "<LVal>";
        }
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character
    public static class PrimaryExp {
        private Exp exp = null;
        private LVal lVal = null;
        private Number number = null;
        private Character character = null;

        public PrimaryExp(Exp exp) {
            this.exp = exp;
        }

        public PrimaryExp(LVal lVal) {
            this.lVal = lVal;
        }

        public PrimaryExp(Number number) {
            this.number = number;
        }

        public PrimaryExp(Character character) {
            this.character = character;
        }

        public Exp getExp() {
            return exp;
        }

        public LVal getLVal() {
            return lVal;
        }

        public Number getNumber() {
            return number;
        }

        public Character getCharacter() {
            return character;
        }

        public String getType() {
            return "<PrimaryExp>";
        }
    }

    // Number → IntConst
    public static class Number {
        private long intConst;

        public Number(String intConst) {
            this.intConst = Long.parseLong(intConst);
        }

        public long getIntConst() {
            return intConst;
        }

        public String getType() {
            return "<Number>";
        }
    }

    // Character → CharConst
    public static class Character {
        private char charConst;

        public Character(String charConst) {
            this.charConst = charConst.charAt(0);
        }

        public char getCharConst() {
            return charConst;
        }

        public String getType() {
            return "<Character>";
        }
    }

    // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public static class UnaryExp {
        private PrimaryExp primaryExp = null;
        private String ident = null;
        private FuncRParams funcRParams = null;
        private UnaryOp unaryOp = null;
        private UnaryExp unaryExp = null;

        public UnaryExp(PrimaryExp primaryExp) {
            this.primaryExp = primaryExp;
        }

        public UnaryExp(String ident, FuncRParams funcRParams) {
            this.ident = ident;
            this.funcRParams = funcRParams;
        }

        public UnaryExp(String ident) {
            this.ident = ident;
        }

        public UnaryExp(UnaryOp unaryOp, UnaryExp unaryExp) {
            this.unaryOp = unaryOp;
            this.unaryExp = unaryExp;
        }

        public PrimaryExp getPrimaryExp() {
            return primaryExp;
        }

        public String getIdent() {
            return ident;
        }

        public FuncRParams getFuncRParams() {
            return funcRParams;
        }

        public UnaryOp getUnaryOp() {
            return unaryOp;
        }

        public UnaryExp getUnaryExp() {
            return unaryExp;
        }

        public String getType() {
            return "<UnaryExp>";
        }
    }

    // UnaryOp → '+' | '-' | '!'
    public static class UnaryOp {
        private String op;

        public UnaryOp(String op) {
            this.op = op;
        }

        public String getOp() {
            return op;
        }

        public String getType() {
            return "<UnaryOp>";
        }
    }

    // FuncRParams → Exp { ',' Exp }
    public static class FuncRParams {
        private ArrayList<Exp> exps;

        public FuncRParams(ArrayList<Exp> exps) {
            this.exps = exps;
        }

        public ArrayList<Exp> getExps() {
            return exps;
        }

        public String getType() {
            return "<FuncRParams>";
        }
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public static class MulExp {
        private ArrayList<UnaryExp> unaryExps;
        private ArrayList<String> ops;

        public MulExp(ArrayList<UnaryExp> unaryExps, ArrayList<String> ops) {
            this.unaryExps = unaryExps;
            this.ops = ops;
        }

        public ArrayList<UnaryExp> getUnaryExps() {
            return unaryExps;
        }

        public ArrayList<String> getOps() {
            return ops;
        }

        public void addUnaryExp(UnaryExp unaryExp) {
            unaryExps.add(unaryExp);
        }

        public void addOp(String op) {
            ops.add(op);
        }

        public String getType() {
            return "<MulExp>";
        }
    }

    // AddExp → MulExp | AddExp ('+' | '-') MulExp
    public static class AddExp {
        private ArrayList<MulExp> mulExps;
        private ArrayList<String> ops;

        public AddExp(ArrayList<MulExp> mulExps, ArrayList<String> ops) {
            this.mulExps = mulExps;
            this.ops = ops;
        }

        public ArrayList<MulExp> getMulExps() {
            return mulExps;
        }

        public ArrayList<String> getOps() {
            return ops;
        }

        public void addMulExp(MulExp mulExp) {
            mulExps.add(mulExp);
        }

        public void addOp(String op) {
            ops.add(op);
        }

        public String getType() {
            return "<AddExp>";
        }
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public static class RelExp {
        private ArrayList<AddExp> addExps;
        private ArrayList<String> ops;

        public RelExp(ArrayList<AddExp> addExps, ArrayList<String> ops) {
            this.addExps = addExps;
            this.ops = ops;
        }

        public ArrayList<AddExp> getAddExps() {
            return addExps;
        }

        public ArrayList<String> getOps() {
            return ops;
        }

        public void addAddExp(AddExp addExp) {
            addExps.add(addExp);
        }

        public void addOp(String op) {
            ops.add(op);
        }

        public String getType() {
            return "<RelExp>";
        }
    }

    // EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public static class EqExp {
        private ArrayList<RelExp> relExps;
        private ArrayList<String> ops;

        public EqExp(ArrayList<RelExp> relExps, ArrayList<String> ops) {
            this.relExps = relExps;
            this.ops = ops;
        }

        public ArrayList<RelExp> getRelExps() {
            return relExps;
        }

        public ArrayList<String> getOps() {
            return ops;
        }

        public void addRelExp(RelExp relExp) {
            relExps.add(relExp);
        }

        public void addOp(String op) {
            ops.add(op);
        }

        public String getType() {
            return "<EqExp>";
        }
    }

    // LAndExp → EqExp | LAndExp '&&' EqExp
    public static class LAndExp {
        private ArrayList<EqExp> eqExps;

        public LAndExp(ArrayList<EqExp> eqExps) {
            this.eqExps = eqExps;
        }

        public ArrayList<EqExp> getEqExps() {
            return eqExps;
        }

        public void addEqExp(EqExp eqExp) {
            eqExps.add(eqExp);
        }

        public String getType() {
            return "<LAndExp>";
        }
    }

    // LOrExp → LAndExp | LOrExp '||' LAndExp
    public static class LOrExp {
        private ArrayList<LAndExp> lAndExps;

        public LOrExp(ArrayList<LAndExp> lAndExps) {
            this.lAndExps = lAndExps;
        }

        public ArrayList<LAndExp> getLAndExps() {
            return lAndExps;
        }

        public void addLAndExp(LAndExp lAndExp) {
            lAndExps.add(lAndExp);
        }

        public String getType() {
            return "<LOrExp>";
        }
    }

    // ConstExp → AddExp
    public static class ConstExp {
        private AddExp addExp;

        public ConstExp(AddExp addExp) {
            this.addExp = addExp;
        }

        public AddExp getAddExp() {
            return addExp;
        }

        public String getType() {
            return "<ConstExp>";
        }
    }
}
