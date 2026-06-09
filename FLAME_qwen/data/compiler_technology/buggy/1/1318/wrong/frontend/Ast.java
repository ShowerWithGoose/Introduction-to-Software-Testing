package frontend;

import utils.File;

import java.util.ArrayList;

public class Ast {
    private final ArrayList<CompUnit> units;
    private final ArrayList<String> lines = new ArrayList<>();

    public Ast(ArrayList<CompUnit> units) {
        assert units != null;
        this.units = units;
    }

    public void print() {
        for (CompUnit compUnit : this.units) {
            compUnit.print(this);
        }
        File.WriteFile("parser.txt", this.lines);
    }

    //CompUnit → {Decl} {FuncDef} MainFuncDef
    public static class CompUnit {
        private final ArrayList<Decl> decls;
        private final ArrayList<FuncDef> funcDefs;
        private final FuncDef mainFuncDef;

        public CompUnit(ArrayList<Decl> decls, ArrayList<FuncDef> funcDefs, FuncDef mainFuncDef) {
            this.decls = decls;
            this.funcDefs = funcDefs;
            this.mainFuncDef = mainFuncDef;
        }

        public void print(Ast ast) {
            for (Decl decl : this.decls) {
                decl.print(ast);
            }
            for (FuncDef funcDef : this.funcDefs) {
                funcDef.print(ast);
            }
            this.mainFuncDef.print(ast);
            ast.addLine("<CompUnit>");
        }

    }

    // Decl → ['const'] BType Def {',' Def} ';'
    // 不实现BType，由各个类自己存储
    public static class Decl {
        public boolean constant;
        public TokenType bType;
        public ArrayList<Def> defs;

        public Decl(boolean constant, TokenType bType, ArrayList<Def> defs) {
            this.constant = constant;
            this.bType = bType;
            this.defs = defs;
        }

        public void print(Ast ast) {
            if (this.constant) {
                ast.addLine(TokenType.CONSTTK);
            }
            ast.addLine(this.bType);
            this.defs.get(0).print(ast);
            for (int i = 1; i < this.defs.size(); ++i) {
                ast.addLine(TokenType.COMMA);
                this.defs.get(i).print(ast);
            }
            ast.addLine(TokenType.SEMICN);
            ast.addLine(constant ? "<ConstDecl>" : "<VarDecl>");
        }
    }

    // Def -> Ident {'[' ConstExp ']'} ['=' (Const)InitVal]
    //ConstDef和VarDef合并为Def
    public static class Def {
        public Token ident;
        public ConstExp exp;
        public InitVal init;
        public boolean constant;

        public Def(Token ident, ConstExp exp, InitVal init, boolean constant) {
            this.ident = ident;
            this.exp = exp;
            this.init = init;
            this.constant = constant;
        }

        public Def(Token ident, ConstExp exp, boolean constant) {
            this.ident = ident;
            this.exp = exp;
            this.init = null;
            this.constant = constant;
        }

        public void print(Ast ast) {
            ast.addLine(this.ident);
            if (this.exp != null) {
                ast.addLine(TokenType.LBRACK);
                this.exp.print(ast);
                ast.addLine(TokenType.RBRACK);
            }
            if (this.init != null) {
                ast.addLine(TokenType.ASSIGN);
                this.init.print(ast);
            }
            ast.addLine(constant ? "<ConstDef>" : "<VarDef>");
        }

    }

    // InitVal -> (Const)Exp | '{' [ (Const)Exp { ',' (Const)Exp } ] '}' | StringConst
    public static class InitVal {
        public ArrayList<Exp> exps = new ArrayList<>();
        public ArrayList<ConstExp> constExps;
        public Token stringConst;
        public boolean constant;

        public InitVal(Exp exp, boolean constant) {
            this.exps.add(exp);
            this.constant = constant;
        }

        public InitVal(ArrayList<Exp> exps, boolean constant) {
            this.exps = exps;
            this.constant = constant;
        }

        public InitVal(Token stringConst, boolean constant) {
            this.stringConst = stringConst;
            this.constant = constant;
        }

        public void print(Ast ast) {
            if (!this.exps.isEmpty()) {
                if (this.exps.size() == 1) {
                    this.exps.get(0).print(ast, constant);
                } else {
                    ast.addLine(TokenType.LBRACE);
                    this.exps.get(0).print(ast, constant);
                    for (int i = 1; i < this.exps.size(); ++i) {
                        ast.addLine(TokenType.COMMA);
                        this.exps.get(i).print(ast, constant);
                    }
                    ast.addLine(TokenType.RBRACE);
                }
            } else if (this.stringConst != null) {
                ast.addLine(this.stringConst);
            } else {
                ast.addLine(TokenType.LBRACE);
                ast.addLine(TokenType.RBRACE);
            }
            ast.addLine(constant ? "<ConstInitVal>" : "<InitVal>");
        }
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
    // MainFuncDef合到这，MainFuncDef → 'int' 'main' '(' ')' Block
    // FuncType → 'void' | BType 不实现
    // FuncFParams → FuncFParam {',' FuncFParam} 不实现
    public static class FuncDef {
        private final TokenType FuncType;
        private final Token ident;
        private final ArrayList<FuncFParam> funcFParams;
        private final Block block;

        public FuncDef(TokenType FuncType, Token ident, ArrayList<FuncFParam> funcFParams, Block block) {
            this.FuncType = FuncType;
            this.ident = ident;
            this.funcFParams = funcFParams;
            this.block = block;
        }

        public void print(Ast ast) {
            ast.addLine(this.FuncType);
            if (!ident.getText().equals("main")) {
                ast.addLine("<FuncType>");
                ast.addLine(this.ident);
            } else {
                ast.addLine(TokenType.MAINTK);
            }
            ast.addLine(TokenType.LPARENT);
            if (!this.funcFParams.isEmpty()) {
                this.funcFParams.get(0).print(ast);
                for (int i = 1; i < this.funcFParams.size(); ++i) {
                    ast.addLine(TokenType.COMMA);
                    this.funcFParams.get(i).print(ast);
                }
                ast.addLine("<FuncFParams>");
            }
            ast.addLine(TokenType.RPARENT);
            this.block.print(ast);
            ast.addLine(this.ident.getText().equals("main") ? "<MainFuncDef>" : "<FuncDef>");
        }
    }


    // FuncFParam → BType Ident ['[' ']']
    public static class FuncFParam {
        private final TokenType bType;
        private final Token ident;
        private final boolean isArray;

        public FuncFParam(TokenType bType, Token ident, boolean isArray) {
            this.bType = bType;
            this.ident = ident;
            this.isArray = isArray;
        }

        public void print(Ast ast) {
            ast.addLine(this.bType);
            ast.addLine(this.ident);
            if (this.isArray) {
                ast.addLine(TokenType.LBRACK);
                ast.addLine(TokenType.RBRACK);
            }
            ast.addLine("<FuncFParam>");
        }

    }

    // Block → '{' {BlockItem} '}'
    public static class Block implements Stmt {
        private final ArrayList<BlockItem> blockItems;

        public Block(ArrayList<BlockItem> blockItems) {
            this.blockItems = blockItems;
        }

        public void print(Ast ast) {
            ast.addLine(TokenType.LBRACE);
            for (BlockItem blockItem : this.blockItems) {
                blockItem.print(ast);
            }
            ast.addLine(TokenType.RBRACE);
            ast.addLine("<Block>");
        }
    }

    // BlockItem → Decl | Stmt
    public static class BlockItem {
        private final Decl decl;
        private final Stmt stmt;

        public BlockItem(Decl decl) {
            this.decl = decl;
            this.stmt = null;
        }

        public BlockItem(Stmt stmt) {
            this.decl = null;
            this.stmt = stmt;
        }

        public void print(Ast ast) {
            if (this.decl != null) {
                this.decl.print(ast);
            } else if (this.stmt != null) {
                this.stmt.print(ast);
            }
//            ast.addLine("<BlockItem>");
        }
    }

    // Stmt -> AssignStmt | ExpStmt | BlockStmt | IfStmt | ForStmt | BreakStmt | ContinueStmt | ReturnStmt | GetStmt | PrintStmt
    public interface Stmt {
        void print(Ast ast);
    }

    // AssignStmt -> LVal '=' Exp ';'
    public static class AssignStmt implements Stmt {
        private final LVal lVal;
        private final Exp exp;
        private final boolean isFor;

        public AssignStmt(LVal lVal, Exp exp, boolean isFor) {
            super();
            this.lVal = lVal;
            this.exp = exp;
            this.isFor = isFor;
        }

        @Override
        public void print(Ast ast) {
            this.lVal.print(ast);
            ast.addLine(TokenType.ASSIGN);
            this.exp.print(ast);
            if (isFor) {
                ast.addLine("<ForStmt>");
            } else {
                ast.addLine(TokenType.SEMICN);
                ast.addLine("<Stmt>");
            }
        }
    }

    // ExpStmt -> Exp ';'
    public static class ExpStmt implements Stmt {
        private final Exp exp;

        public ExpStmt(Exp exp) {
            this.exp = exp;
        }

        @Override
        public void print(Ast ast) {
            if (this.exp != null) {
                this.exp.print(ast);
            }
            ast.addLine(TokenType.SEMICN);
            ast.addLine("<Stmt>");
        }
    }

    // BlockStmt -> Block
    public static class BlockStmt implements Stmt {
        private final Block block;

        public BlockStmt(Block block) {
            this.block = block;
        }

        @Override
        public void print(Ast ast) {
            this.block.print(ast);
            ast.addLine("<Stmt>");
        }
    }

    // IfStmt -> 'if' '(' Cond ')' Stmt ['else' Stmt]
    public static class IfStmt implements Stmt {
        private final Cond cond;
        private final Stmt thenStmt;
        private final Stmt elseStmt;

        public IfStmt(Cond cond, Stmt thenStmt, Stmt elseStmt) {
            this.cond = cond;
            this.thenStmt = thenStmt;
            this.elseStmt = elseStmt;
        }

        @Override
        public void print(Ast ast) {
            ast.addLine(TokenType.IFTK);
            ast.addLine(TokenType.LPARENT);
            this.cond.print(ast);
            ast.addLine(TokenType.RPARENT);
            this.thenStmt.print(ast);
            if (this.elseStmt != null) {
                ast.addLine(TokenType.ELSETK);
                this.elseStmt.print(ast);
            }
            ast.addLine("<Stmt>");
        }
    }

    // ForStmt -> 'for' '(' [AssignStmt] ';' [Cond] ';' [AssignStmt] ')' Stmt
    public static class ForStmt implements Stmt {
        private final AssignStmt init;
        private final Cond cond;
        private final AssignStmt update;
        private final Stmt stmt;

        public ForStmt(AssignStmt init, Cond cond, AssignStmt update, Stmt stmt) {
            this.init = init;
            this.cond = cond;
            this.update = update;
            this.stmt = stmt;
        }

        @Override
        public void print(Ast ast) {
            ast.addLine(TokenType.FORTK);
            ast.addLine(TokenType.LPARENT);
            if (this.init != null) {
                this.init.print(ast);
            }
            ast.addLine(TokenType.SEMICN);
            if (this.cond != null) {
                this.cond.print(ast);
            }
            ast.addLine(TokenType.SEMICN);
            if (this.update != null) {
                this.update.print(ast);
            }
            ast.addLine(TokenType.RPARENT);
            this.stmt.print(ast);
            ast.addLine("<Stmt>");
        }
    }

    // BreakStmt -> 'break' ';'
    public static class BreakStmt implements Stmt {
        @Override
        public void print(Ast ast) {
            ast.addLine(TokenType.BREAKTK);
            ast.addLine(TokenType.SEMICN);
            ast.addLine("<Stmt>");
        }
    }

    // ContinueStmt -> 'continue' ';'
    public static class ContinueStmt implements Stmt {
        @Override
        public void print(Ast ast) {
            ast.addLine(TokenType.CONTINUETK);
            ast.addLine(TokenType.SEMICN);
            ast.addLine("<Stmt>");
        }
    }

    // ReturnStmt -> 'return' [Exp] ';'
    public static class ReturnStmt implements Stmt {
        private final Exp exp;

        public ReturnStmt(Exp exp) {
            this.exp = exp;
        }

        @Override
        public void print(Ast ast) {
            ast.addLine(TokenType.RETURNTK);
            if (this.exp != null) {
                this.exp.print(ast);
            }
            ast.addLine(TokenType.SEMICN);
            ast.addLine("<Stmt>");
        }
    }

    // GetStmt -> LVal '=' 'getint''('')''; | LVal '=' 'getchar''('')'';'
    public static class GetStmt implements Stmt {
        private final LVal lVal;
        private final TokenType type;

        public GetStmt(LVal lVal, TokenType type) {
            this.lVal = lVal;
            this.type = type;
        }

        @Override
        public void print(Ast ast) {
            this.lVal.print(ast);
            ast.addLine(TokenType.ASSIGN);
            ast.addLine(this.type);
            ast.addLine(TokenType.LPARENT);
            ast.addLine(TokenType.RPARENT);
            ast.addLine(TokenType.SEMICN);
            ast.addLine("<Stmt>");
        }
    }

    // PrintStmt -> 'printf''('StringConst {','Exp}')'';'
    public static class PrintStmt implements Stmt {
        private final Token stringConst;
        private final ArrayList<Exp> exps;

        public PrintStmt(Token stringConst, ArrayList<Exp> exps) {
            this.stringConst = stringConst;
            this.exps = exps;
        }

        @Override
        public void print(Ast ast) {
            ast.addLine(TokenType.PRINTFTK);
            ast.addLine(TokenType.LPARENT);
            ast.addLine(this.stringConst);
            if (!this.exps.isEmpty()) {
                for (Exp exp : this.exps) {
                    ast.addLine(TokenType.COMMA);
                    exp.print(ast);
                }
            }
            ast.addLine(TokenType.RPARENT);
            ast.addLine(TokenType.SEMICN);
            ast.addLine("<Stmt>");
        }
    }

    // Exp → AddExp
    public static class Exp {
        private final AddExp addExp;

        public Exp(AddExp addExp) {
            this.addExp = addExp;
        }

        public void print(Ast ast, boolean constant) {
            this.addExp.print(ast);
            ast.addLine(constant ? "<ConstExp>" : "<Exp>");
        }

        public Ast.LVal getLVal() {
            return this.addExp.mulExps.get(0).unaryExps.get(0).primaryExp.lVal;
        }

        public void print(Ast ast) {
            this.addExp.print(ast);
            ast.addLine("<Exp>");
        }
    }


    // Cond → LOrExp
    public static class Cond {
        private final LOrExp lOrExp;

        public Cond(LOrExp lOrExp) {
            this.lOrExp = lOrExp;
        }

        public void print(Ast ast) {
            this.lOrExp.print(ast);
            ast.addLine("<Cond>");
        }
    }

    // LVal → Ident {'[' Exp ']'}
    public static class LVal {
        private final Token ident;
        private final ArrayList<Exp> exps;

        public LVal(Token ident, ArrayList<Exp> exps) {
            this.ident = ident;
            this.exps = exps;
        }

        public void print(Ast ast) {
            ast.addLine(this.ident);
            for (Exp exp : this.exps) {
                ast.addLine(TokenType.LBRACK);
                exp.print(ast);
                ast.addLine(TokenType.RBRACK);
            }
            ast.addLine("<LVal>");
        }
    }

    //PrimaryExp → '(' Exp ')' | LVal | Number | Character
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

        public void print(Ast ast) {
            if (this.exp != null) {
                ast.addLine(TokenType.LPARENT);
                this.exp.print(ast);
                ast.addLine(TokenType.RPARENT);
            } else if (this.lVal != null) {
                this.lVal.print(ast);
            } else if (this.number != null) {
                this.number.print(ast);
            } else {
                this.character.print(ast);
            }
            ast.addLine("<PrimaryExp>");
        }
    }

    // Number → IntConst
    public static class Number {
        private final Token intConst;

        public Number(Token consume) {
            this.intConst = consume;
        }

        public void print(Ast ast) {
            ast.addLine(this.intConst);
            ast.addLine("<Number>");
        }
    }

    // Character → CharConst
    public static class Character {
        private final Token charConst;

        public Character(Token consume) {
            this.charConst = consume;
        }

        public void print(Ast ast) {
            ast.addLine(this.charConst);
            ast.addLine("<Character>");
        }
    }

    // UnaryExp → PrimaryExp | FuncCall | UnaryOp UnaryExp
    // FuncRParams → Exp {',' Exp} 不实现
    public static class UnaryExp {
        private PrimaryExp primaryExp = null;
        private FuncCall funcCall = null;
        private final ArrayList<TokenType> unaryOps;

        public UnaryExp(FuncCall funcCall) {
            this.funcCall = funcCall;
            this.unaryOps = new ArrayList<>();
        }

        public UnaryExp(PrimaryExp primaryExp) {
            this.primaryExp = primaryExp;
            this.unaryOps = new ArrayList<>();
        }

        public UnaryExp(TokenType op, UnaryExp unaryExp) {
            this.primaryExp = unaryExp.getPrimaryExp();
            this.funcCall = unaryExp.getFuncCall();
            this.unaryOps = unaryExp.getUnaryOps();
            this.unaryOps.add(0, op);
        }

        public PrimaryExp getPrimaryExp() {
            return primaryExp;
        }

        public FuncCall getFuncCall() {
            return funcCall;
        }

        public ArrayList<TokenType> getUnaryOps() {
            return unaryOps;
        }

        public void print(Ast ast) {
            for (TokenType unaryOp : this.unaryOps) {
                ast.addLine(unaryOp);
                ast.addLine("<UnaryOp>");
            }
            if (this.primaryExp != null) {
                this.primaryExp.print(ast);
            } else if (this.funcCall != null) {
                this.funcCall.print(ast);
            }
            ast.addLine("<UnaryExp>");
            for (int i = 0; i < this.unaryOps.size(); ++i) {
                ast.addLine("<UnaryExp>");
            }
        }
    }

    // FuncCall → Ident '(' [FuncRParams] ')'
    public static class FuncCall {
        private final Token ident;
        private final ArrayList<Exp> params;

        public FuncCall(Token ident, ArrayList<Exp> params) {
            this.ident = ident;
            this.params = params;
        }

        public void print(Ast ast) {
            ast.addLine(this.ident);
            ast.addLine(TokenType.LPARENT);
            if (!this.params.isEmpty()) {
                this.params.get(0).print(ast);
                for (int i = 1; i < this.params.size(); ++i) {
                    ast.addLine(TokenType.COMMA);
                    this.params.get(i).print(ast);
                }
                ast.addLine("<FuncRParams>");
            }
            ast.addLine(TokenType.RPARENT);
        }
    }

    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public static class MulExp {
        private final ArrayList<UnaryExp> unaryExps;
        private final ArrayList<TokenType> ops;

        public MulExp(ArrayList<UnaryExp> unaryExps, ArrayList<TokenType> ops) {
            this.unaryExps = unaryExps;
            this.ops = ops;
        }

        public void print(Ast ast) {
            this.unaryExps.get(0).print(ast);
            ast.addLine("<MulExp>");
            for (int i = 1; i < this.unaryExps.size(); ++i) {
                ast.addLine(this.ops.get(i - 1));
                this.unaryExps.get(i).print(ast);
                ast.addLine("<MulExp>");
            }
        }

    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    public static class AddExp {
        private final ArrayList<MulExp> mulExps;
        private final ArrayList<TokenType> ops;

        public AddExp(ArrayList<MulExp> mulExps, ArrayList<TokenType> ops) {
            this.mulExps = mulExps;
            this.ops = ops;
        }

        public void print(Ast ast) {
            this.mulExps.get(0).print(ast);
            ast.addLine("<AddExp>");
            for (int i = 1; i < this.mulExps.size(); ++i) {
                ast.addLine(this.ops.get(i - 1));
                this.mulExps.get(i).print(ast);
                ast.addLine("<AddExp>");
            }
        }
    }

    // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    public static class RelExp {
        private final ArrayList<AddExp> addExps;
        private final ArrayList<TokenType> ops;

        public RelExp(ArrayList<AddExp> addExps, ArrayList<TokenType> ops) {
            this.addExps = addExps;
            this.ops = ops;
        }

        public void print(Ast ast) {
            this.addExps.get(0).print(ast);
            ast.addLine("<RelExp>");
            for (int i = 1; i < this.addExps.size(); ++i) {
                ast.addLine(this.ops.get(i - 1));
                this.addExps.get(i).print(ast);
                ast.addLine("<RelExp>");
            }
        }
    }

    //  EqExp → RelExp | EqExp ('==' | '!=') RelExp
    public static class EqExp {
        private final ArrayList<RelExp> relExps;
        private final ArrayList<TokenType> ops;

        public EqExp(ArrayList<RelExp> relExps, ArrayList<TokenType> ops) {
            this.relExps = relExps;
            this.ops = ops;
        }

        public void print(Ast ast) {
            this.relExps.get(0).print(ast);
            ast.addLine("<EqExp>");
            for (int i = 1; i < this.relExps.size(); ++i) {
                ast.addLine(this.ops.get(i - 1));
                this.relExps.get(i).print(ast);
                ast.addLine("<EqExp>");
            }
        }
    }

    //  LAndExp → EqExp | LAndExp '&&' EqExp
    public static class LAndExp {
        private final ArrayList<EqExp> eqExps;
        private final ArrayList<TokenType> ops;

        public LAndExp(ArrayList<EqExp> eqExps, ArrayList<TokenType> ops) {
            this.eqExps = eqExps;
            this.ops = ops;
        }

        public void print(Ast ast) {
            this.eqExps.get(0).print(ast);
            ast.addLine("<LAndExp>");
            for (int i = 1; i < this.eqExps.size(); ++i) {
                ast.addLine(this.ops.get(i - 1));
                this.eqExps.get(i).print(ast);
                ast.addLine("<LAndExp>");
            }
        }
    }

    //  LOrExp → LAndExp | LOrExp '||' LAndExp
    public static class LOrExp {
        private final ArrayList<LAndExp> lAndExps;
        private final ArrayList<TokenType> ops;

        public LOrExp(ArrayList<LAndExp> lAndExps, ArrayList<TokenType> ops) {
            this.lAndExps = lAndExps;
            this.ops = ops;
        }

        public void print(Ast ast) {
            this.lAndExps.get(0).print(ast);
            ast.addLine("<LOrExp>");
            for (int i = 1; i < this.lAndExps.size(); ++i) {
                ast.addLine(this.ops.get(i - 1));
                this.lAndExps.get(i).print(ast);
                ast.addLine("<LOrExp>");
            }
        }
    }

    // ConstExp → AddExp
    public static class ConstExp {
        private final AddExp addExp;

        public ConstExp(AddExp addExp) {
            this.addExp = addExp;
        }

        public void print(Ast ast) {
            this.addExp.print(ast);
            ast.addLine("<ConstExp>");
        }
    }

    private void addLine(Token token) {
        if (token == null) {
            return;
        }
        this.lines.add(token.toString());
    }

    private void addLine(TokenType returnType) {
        this.lines.add(returnType.toString());
    }

    private void addLine(String returnType) {
        this.lines.add(returnType);
    }

}
