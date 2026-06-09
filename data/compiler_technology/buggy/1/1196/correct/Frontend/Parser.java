package Frontend;

import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;

public class Parser {
    PrintStream errout = new PrintStream("error.txt");
    PrintStream out = new PrintStream("parser.txt");
    private int curPos;
    private int preLine;
    private Lexer lexer;
    private LexType type;
    private ArrayList<String> errorTable;
    private ArrayList<String> outputTable;
    //private ArrayList<LexType> lexTypes;
    private ArrayList<Token> tokens;
    private ArrayList<String> tem = new ArrayList<>();

    public Parser(Lexer lexer) throws FileNotFoundException {
        this.lexer = lexer;
        this.curPos = 0;
        this.preLine = 0;
        errorTable = new ArrayList<>();
        outputTable = new ArrayList<>();
        this.tokens = new ArrayList<>();
    }

    public void next(){
        int f = lexer.analyze();
        if (f == -1) {
            errorTable.add(lexer.getlineNUM() + " " + "a");
        }
        while (f == -2 && !lexer.isEnd()) {
            f = lexer.analyze();
        }
        type = lexer.getLexType();
        tokens.add(lexer.getToken());
        curPos++;
    }

    public LexType preRead(int i) {
        return lexer.preRead(i);
    }

    public void addLeaf(TreeNode node) {
        // 叶子节点输出然后指向下一个
        LexType leafType = tokens.get(curPos - 1).getType();
        String leafStr = tokens.get(curPos - 1).getToken().toString();
        TreeNode leaf = new TreeNode(leafType,leafStr);
        node.addNode(leaf);
        outputTable.add(leafType + " " + leafStr);
        tem.add(leafStr);
        if (!lexer.isEnd()) {
            next();
        }
    }

    public boolean isMatch(LexType type) {
        return this.type.equals(type);
    }

    public void addOut(String s) {
        outputTable.add(s);
    }

    public void addError(Character c) {
        errorTable.add(tokens.get(curPos - 2).getLineNum() + " " + c);
    }

    public void error() {
        System.out.println("*\n     ERROR\n     *");
    }

    public void reStart(ArrayList<String> s, int pre) {
        for (int i = s.size() - 1; i >= pre; i--) {
            s.remove(i);
        }
    }

    public void reStartT(ArrayList<Token> s, int pre) {
        for (int i = s.size() - 1; i >= pre; i--) {
            s.remove(i);
        }
    }

    public void analyze() {
        next();
        CompUnit();
        System.setOut(out);
        for (String s : outputTable) {
            System.out.println(s);
        }

        System.setOut(errout);
        for (String s : errorTable) {
            System.out.println(s);
        }
    }

    //每次都是解析到叶子结点之后，在指向下一个，其余时间一直向下递归
    public TreeNode CompUnit() {
        TreeNode root = new TreeNode(ParsType.CompUnit,new ArrayList<>());
        //cosnt || int/char ? 非(
        while (!lexer.isEnd() && (isMatch(LexType.CONSTTK)
                || ((isMatch(LexType.INTTK) || isMatch(LexType.CHARTK)) && !preRead(2).equals(LexType.LPARENT)))) {
            root.addNode(Decl());
        }
        // void || int char indent (
        while(!lexer.isEnd() && (isMatch(LexType.VOIDTK)
                || ((isMatch(LexType.INTTK) || isMatch(LexType.CHARTK)) && preRead(1).equals(LexType.IDENFR) && preRead(2).equals(LexType.LPARENT)))) {
            root.addNode(FuncDef());
        }
        // int main (
        if (type == null) {
            return root;
        }
        root.addNode(MainFuncDef());
        addOut("<CompUnit>");
        return root;
        /*while (!lexer.isEnd()) {
            if (isMatch(LexType.INTTK)) {
                // int main
                if (preRead(1).equals(LexType.MAINTK)) {
                    root.addNode(MainFuncDef());
                }
                //int x = 1 || int x()
                else if (preRead(1).equals(LexType.IDENFR)) {
                    if (preRead(2).equals(LexType.ASSIGN)) {
                        root.addNode(Decl());
                    }
                    else if (preRead(2).equals(LexType.LPARENT)) {
                        root.addNode(FuncDef());
                    }
                }
                else {
                    error();
                }
            }
            // const
            else if (isMatch(LexType.CONSTTK)) {
                root.addNode(Decl());
            }
            // char a || char a()
            else if (isMatch(LexType.CHARTK)) {
                if (preRead(1).equals(LexType.IDENFR)) {
                    if (preRead(2).equals(LexType.ASSIGN)) {
                        root.addNode(Decl());
                    }
                    else if (preRead(2).equals(LexType.LPARENT)) {
                        root.addNode(FuncDef());
                    }
                }
                else {
                    error();
                }
            }
            else {
                error();
            }
        }
        addOut("<CompUnit>");
        return root;*/

    }

    // Decl不输出
    public TreeNode Decl() {
        TreeNode decl = new TreeNode(ParsType.Decl,new ArrayList<>());
        if (isMatch(LexType.CONSTTK)) {
            decl.addNode(ConstDecl());
        }
        else if (isMatch(LexType.INTTK) || isMatch(LexType.CHARTK)) {
            decl.addNode(VarDecl());
        }
        else {
            error();
        }
        return decl;
    }

    public TreeNode ConstDecl() {
        TreeNode constdecl = new TreeNode(ParsType.ConstDecl,new ArrayList<>());
        if(isMatch(LexType.CONSTTK)) {
            addLeaf(constdecl);
        }
        else {
            error();
        }
        constdecl.addNode(BType());
        constdecl.addNode(ConstDef());
        while(isMatch(LexType.COMMA)) {
            addLeaf(constdecl);
            constdecl.addNode(ConstDef());
        }
        SemicnJudge(constdecl);
        addOut("<ConstDecl>");
        return constdecl;
    }

    // BType不输出
    public TreeNode BType() {
        TreeNode btype = new TreeNode(ParsType.BType,new ArrayList<>());
        if (isMatch(LexType.INTTK) || isMatch(LexType.CHARTK)) {
            addLeaf(btype);
        }
        else {
            error();
        }
        return btype;
    }

    public TreeNode ConstDef() {
        TreeNode constdef = new TreeNode(ParsType.ConstDef,new ArrayList<>());
        if (isMatch(LexType.IDENFR)) {
            addLeaf(constdef);
        }
        // 是否数组
        if (isMatch(LexType.LBRACK)) {
            addLeaf(constdef);
            constdef.addNode(ConstExp());
            RbrackJudege(constdef);
        }
        if (isMatch(LexType.ASSIGN)) {
            addLeaf(constdef);
        }
        constdef.addNode(ConstInitVal());
        addOut("<ConstDef>");
        return constdef;
    }

    public TreeNode ConstInitVal() {
        TreeNode constinitval = new TreeNode(ParsType.ConstInitVal,new ArrayList<>());
        if (isMatch(LexType.STRCON)) {
            addLeaf(constinitval);
        }
        else if (isMatch(LexType.LBRACE)) {
            addLeaf(constinitval);
            if (isMatch(LexType.RBRACE)) {
                addLeaf(constinitval);
            }
            else {
                constinitval.addNode(ConstExp());
                while(isMatch(LexType.COMMA)) {
                    addLeaf(constinitval);
                    constinitval.addNode(ConstExp());
                }
                if (isMatch(LexType.RBRACE)) {
                    addLeaf(constinitval);
                }
                else {
                    error();
                }
            }
        }
        else {
            constinitval.addNode(ConstExp());
        }
        addOut("<ConstInitVal>");
        return constinitval;
    }

    public TreeNode VarDecl() {
        TreeNode vardecl = new TreeNode(ParsType.VarDecl,new ArrayList<>());
        vardecl.addNode(BType());
        vardecl.addNode(VarDef());
        while(isMatch(LexType.COMMA)) {
            addLeaf(vardecl);
            vardecl.addNode(VarDef());
        }
        SemicnJudge(vardecl);
        addOut("<VarDecl>");
        return vardecl;
    }

    public TreeNode VarDef() {
        TreeNode vardef = new TreeNode(ParsType.VarDef,new ArrayList<>());
        if (isMatch(LexType.IDENFR)) {
            addLeaf(vardef);
        }
        else {
            error();
        }
        if (isMatch(LexType.LBRACK)) {
            addLeaf(vardef);
            vardef.addNode(ConstExp());
            RbrackJudege(vardef);
        }
        if (isMatch(LexType.ASSIGN)) {
            addLeaf(vardef);
            vardef.addNode(InitVal());
        }
        addOut("<VarDef>");
        return vardef;
    }

    public TreeNode InitVal() {
        TreeNode initval = new TreeNode(ParsType.InitVal,new ArrayList<>());
        if (isMatch(LexType.STRCON)) {
            addLeaf(initval);
        }
        else if (isMatch(LexType.LBRACE)) {
            addLeaf(initval);
            if (isMatch(LexType.RBRACE)) {
                addLeaf(initval);
            }
            else {
                initval.addNode(Exp());
                while(isMatch(LexType.COMMA)) {
                    addLeaf(initval);
                    initval.addNode(Exp());
                }
                if (isMatch(LexType.RBRACE)) {
                    addLeaf(initval);
                }
                else {
                    error();
                }
            }
        }
        else {
            initval.addNode(Exp());
        }
        addOut("<InitVal>");
        return initval;
    }

    public TreeNode FuncDef() {
        TreeNode funcdef = new TreeNode(ParsType.FuncDef,new ArrayList<>());
        funcdef.addNode(FuncType());
        if (isMatch(LexType.IDENFR)) {
            addLeaf(funcdef);
        }
        else {
            error();
        }
        if (isMatch(LexType.LPARENT)) {
            addLeaf(funcdef);
            if (isMatch(LexType.RPARENT)) {
                addLeaf(funcdef);
            }
            // 没有右括号，直接到了block的{
            else if (isMatch(LexType.LBRACE)) {
                addError('j');
            }
            else {
                funcdef.addNode(FuncFParams());
                RparentJudge(funcdef);
            }
            funcdef.addNode(Block());
        }
        addOut("<FuncDef>");
        return funcdef;
    }

    public TreeNode MainFuncDef() {
        TreeNode mainfuncdef = new TreeNode(ParsType.MainFuncDef,new ArrayList<>());
        if (isMatch(LexType.INTTK)) {
            addLeaf(mainfuncdef);
        }
        else error();
        if (isMatch(LexType.MAINTK)) {
            addLeaf(mainfuncdef);
        }
        else error();
        if (isMatch(LexType.LPARENT)) {
            addLeaf(mainfuncdef);
        }
        else error();
        RparentJudge(mainfuncdef);
        mainfuncdef.addNode(Block());
        addOut("<MainFuncDef>");
        return mainfuncdef;
    }

    public TreeNode FuncType() {
        TreeNode functype = new TreeNode(ParsType.FuncType, new ArrayList<>());
        if (isMatch(LexType.VOIDTK) || isMatch(LexType.INTTK) || isMatch(LexType.CHARTK)) {
            addLeaf(functype);
        }
        addOut("<FuncType>");
        return functype;
    }

    public TreeNode FuncFParams() {
        TreeNode funcfparams = new TreeNode(ParsType.FuncFParams, new ArrayList<>());
        funcfparams.addNode(FuncFParam());
        while(isMatch(LexType.COMMA)) {
            addLeaf(funcfparams);
            funcfparams.addNode(FuncFParam());
        }
        addOut("<FuncFParams>");
        return funcfparams;
    }

    public TreeNode FuncFParam() {
        TreeNode funcfparam = new TreeNode(ParsType.FuncFParam, new ArrayList<>());
        BType();
        if (isMatch(LexType.IDENFR)) {
            addLeaf(funcfparam);
        }
        else error();
        if (isMatch(LexType.LBRACK)) {
            addLeaf(funcfparam);
            RbrackJudege(funcfparam);
        }
        addOut("<FuncFParam>");
        return funcfparam;
    }

    public TreeNode Block() {
        TreeNode block = new TreeNode(ParsType.Block,new ArrayList<>());
        if (isMatch(LexType.LBRACE)) {
            addLeaf(block);
        }
        while(!isMatch(LexType.RBRACE)) {
            block.addNode(BlockItem());
        }
        addLeaf(block);
        addOut("<Block>");
        return block;
    }

    // 不用输出
    public TreeNode BlockItem() {
        // Decl : const | int | char | void
        TreeNode blockitem = new TreeNode(ParsType.BlockItem,new ArrayList<>());
        if (isMatch(LexType.CONSTTK) || isMatch(LexType.INTTK)
                || isMatch(LexType.CHARTK) || isMatch(LexType.VOIDTK)) {
            blockitem.addNode(Decl());
        }
        else {
            blockitem.addNode(Stmt());
        }
        return blockitem;
    }

    public TreeNode Stmt() {
        TreeNode stmt = new TreeNode(ParsType.Stmt,new ArrayList<>());
        if (isMatch(LexType.IFTK)) {
            addLeaf(stmt);
            if (isMatch(LexType.LPARENT)) {
                addLeaf(stmt);
            }
            stmt.addNode(Cond());
            RparentJudge(stmt);
            stmt.addNode(Stmt());
            if (isMatch(LexType.ELSETK)) {
                addLeaf(stmt);
                stmt.addNode(Stmt());
            }
        }
        else if (isMatch(LexType.FORTK)) {
            addLeaf(stmt);
            if (isMatch(LexType.LPARENT)) {
                addLeaf(stmt);
            }
            if (isMatch(LexType.SEMICN)) {
                addLeaf(stmt);
            }
            else {
                stmt.addNode(ForStmt());
                addLeaf(stmt);
            }
            if (isMatch(LexType.SEMICN)) {
                addLeaf(stmt);
            }
            else {
                stmt.addNode(Cond());
                addLeaf(stmt);
            }
            if (isMatch(LexType.RPARENT)) {
                addLeaf(stmt);
            }
            else {
                stmt.addNode(ForStmt());
                addLeaf(stmt);
            }
            stmt.addNode(Stmt());
        }
        else if (isMatch(LexType.BREAKTK) || isMatch(LexType.CONTINUETK)) {
            addLeaf(stmt);
            SemicnJudge(stmt);
        }
        else if (isMatch(LexType.RETURNTK)) {
            addLeaf(stmt);
            if (isMatch(LexType.SEMICN)) {
                addLeaf(stmt);
            }
            else if (isExp()){
                stmt.addNode(Exp());
                SemicnJudge(stmt);
            }
            else {
                SemicnJudge(stmt);
            }
        }
        else if (isMatch(LexType.PRINTFTK)) {
            addLeaf(stmt);
            addLeaf(stmt);
            addLeaf(stmt);
            while (isMatch(LexType.COMMA)) {
                addLeaf(stmt);
                stmt.addNode(Exp());
            }
            RparentJudge(stmt);
            SemicnJudge(stmt);
        }
        else if (isMatch(LexType.LBRACE)) {
            stmt.addNode(Block());
        }
        else {
            if (isMatch(LexType.IDENFR)) {
                // 回溯
                LexType preType = type;
                int preline = lexer.getlineNUM();
                int lexpre = lexer.getCurPos();
                int pre = curPos;
                int outSize = outputTable.size();
                int errSize = errorTable.size();
                int tokenSize = tokens.size();
                TreeNode lval = LVal(); //叶子节点在lval
                // LVal
                if (isMatch(LexType.ASSIGN)) {
                    stmt.addNode(lval);
                    addLeaf(stmt);
                    if (isMatch(LexType.GETINTTK) || isMatch(LexType.GETCHARTK)) {
                        addLeaf(stmt);
                        addLeaf(stmt);
                        RparentJudge(stmt);
                        SemicnJudge(stmt);
                    }
                    else {
                        stmt.addNode(Exp());
                        SemicnJudge(stmt);
                    }
                }
                // Exp
                else {
                    lexer.setLineNum(preline);
                    type = preType;
                    lexer.reStart(lexpre);
                    curPos = pre;
                    reStart(outputTable,outSize);
                    reStart(errorTable,errSize);
                    reStartT(tokens,tokenSize);
                    stmt.addNode(Exp());
                    SemicnJudge(stmt);
                }
            }
            else {
                if (isMatch(LexType.SEMICN)) {
                    addLeaf(stmt);
                }
                else {
                    stmt.addNode(Exp());
                    SemicnJudge(stmt);
                }
            }
        }
        addOut("<Stmt>");
        return stmt;
    }

    public TreeNode ForStmt() {
        TreeNode forstmt = new TreeNode(ParsType.ForStmt, new ArrayList<>());
        forstmt.addNode(LVal());
        addLeaf(forstmt);
        forstmt.addNode(Exp());
        addOut("<ForStmt>");
        return forstmt;
    }

    public boolean isExp() {
        return isMatch(LexType.LPARENT) || isMatch(LexType.IDENFR)
                || isMatch(LexType.INTCON) || isMatch(LexType.CHRCON)
                || isMatch(LexType.PLUS) || isMatch(LexType.MINU) || isMatch(LexType.NOT);
    }

    public TreeNode Exp() {
        TreeNode exp = new TreeNode(ParsType.Exp,new ArrayList<>());
        exp.addNode(AddExp());
        addOut("<Exp>");
        return exp;
    }

    public TreeNode Cond() {
        TreeNode cond = new TreeNode(ParsType.Cond,new ArrayList<>());
        cond.addNode(LOrExp());
        addOut("<Cond>");
        return cond;
    }

    public TreeNode LVal() {
        TreeNode lval = new TreeNode(ParsType.LVal,new ArrayList<>());
        addLeaf(lval);
        if (isMatch(LexType.LBRACK)) {
            addLeaf(lval);
            lval.addNode(Exp());
            RbrackJudege(lval);
        }
        addOut("<LVal>");
        return lval;
    }

    public TreeNode PrimaryExp() {
        TreeNode primaryexp = new TreeNode(ParsType.PrimaryExp,new ArrayList<>());
        if (isMatch(LexType.LPARENT)) {
            addLeaf(primaryexp);
            primaryexp.addNode(Exp());
            RparentJudge(primaryexp);
        }
        else if (isMatch(LexType.INTCON)) {
            primaryexp.addNode(Number());
        }
        else if (isMatch(LexType.CHRCON)) {
            primaryexp.addNode(Character());
        }
        else {
            primaryexp.addNode(LVal());
        }
        addOut("<PrimaryExp>");
        return primaryexp;
    }

    public TreeNode Number() {
        TreeNode number = new TreeNode(ParsType.Number,new ArrayList<>());
        addLeaf(number);
        addOut("<Number>");
        return number;
    }

    public TreeNode Character() {
        TreeNode character = new TreeNode(ParsType.Character,new ArrayList<>());
        addLeaf(character);
        addOut("<Character>");
        return character;
    }

    public TreeNode UnaryExp() {
        TreeNode unaryexp = new TreeNode(ParsType.UnaryExp,new ArrayList<>());
        if (isMatch(LexType.PLUS) || isMatch(LexType.MINU) || isMatch(LexType.NOT)) {
            unaryexp.addNode(UnaryOp());
            unaryexp.addNode(UnaryExp());
        }
        else if (isMatch(LexType.IDENFR) && preRead(1).equals(LexType.LPARENT)) {
            addLeaf(unaryexp);
            addLeaf(unaryexp);
            if (!isMatch(LexType.RPARENT) && isExp()) {
                unaryexp.addNode(FuncRParams());
            }
            RparentJudge(unaryexp);
        }
        else {
            unaryexp.addNode(PrimaryExp());
        }
        addOut("<UnaryExp>");
        return unaryexp;
    }

    public TreeNode UnaryOp() {
        TreeNode unaryop = new TreeNode(ParsType.UnaryOp,new ArrayList<>());
        addLeaf(unaryop);
        addOut("<UnaryOp>");
        return unaryop;
    }

    public TreeNode FuncRParams() {
        TreeNode funcrparams = new TreeNode(ParsType.FuncRParams,new ArrayList<>());
        funcrparams.addNode(Exp());
        while (isMatch(LexType.COMMA)) {
            addLeaf(funcrparams);
            funcrparams.addNode(Exp());
        }
        addOut("<FuncRParams>");
        return funcrparams;
    }

    public TreeNode MulExp() {
        TreeNode mulexp = new TreeNode(ParsType.MulExp,new ArrayList<>());
        // 从UnaryExp出来补一个Mul
        mulexp.addNode(UnaryExp());
        while (isMatch(LexType.MULT) || isMatch(LexType.DIV) || isMatch(LexType.MOD)) {
            addOut("<MulExp>");
            addLeaf(mulexp);
            mulexp.addNode(UnaryExp());
        }
        addOut("<MulExp>");
        return mulexp;
    }

    public TreeNode AddExp() {
        TreeNode addexp = new TreeNode(ParsType.AddExp,new ArrayList<>());
        addexp.addNode(MulExp());
        while (isMatch(LexType.PLUS) || isMatch(LexType.MINU)) {
            addOut("<AddExp>");
            addLeaf(addexp);
            addexp.addNode(MulExp());
        }
        addOut("<AddExp>");
        return addexp;
    }

    public TreeNode RelExp() {
        TreeNode relexp = new TreeNode(ParsType.RelExp,new ArrayList<>());
        relexp.addNode(AddExp());
        while (isMatch(LexType.GRE) || isMatch( LexType.GEQ)
                || isMatch(LexType.LSS) || isMatch(LexType.LEQ)) {
            addOut("<RelExp>");
            addLeaf(relexp);
            relexp.addNode(AddExp());
        }
        addOut("<RelExp>");
        return relexp;
    }

    public TreeNode EqExp() {
        TreeNode eqexp = new TreeNode(ParsType.EqExp,new ArrayList<>());
        eqexp.addNode(RelExp());

        while (isMatch(LexType.EQL) || isMatch(LexType.NEQ)) {
            addOut("<EqExp>");
            addLeaf(eqexp);
            eqexp.addNode(RelExp());
        }
        addOut("<EqExp>");
        return eqexp;
    }

    public TreeNode LAndExp() {
        TreeNode landexp = new TreeNode(ParsType.LAndExp,new ArrayList<>());
        landexp.addNode(EqExp());

        while (isMatch(LexType.AND)) {
            addOut("<LAndExp>");
            addLeaf(landexp);
            landexp.addNode(EqExp());
        }
        addOut("<LAndExp>");
        return landexp;
    }

    public TreeNode LOrExp() {
        TreeNode lorexp = new TreeNode(ParsType.LOrExp,new ArrayList<>());
        lorexp.addNode(LAndExp());

        while (isMatch(LexType.OR)) {
            addOut("<LOrExp>");
            addLeaf(lorexp);
            lorexp.addNode(LAndExp());
        }
        addOut("<LOrExp>");
        return lorexp;
    }

    public TreeNode ConstExp() {
        TreeNode constexp = new TreeNode(ParsType.ConstExp,new ArrayList<>());
        constexp.addNode(AddExp());
        addOut("<ConstExp>");
        return constexp;
    }

    public void SemicnJudge(TreeNode node) {
        if (isMatch(LexType.SEMICN)) {
            addLeaf(node);
        }
        else {
            addError('i');
        }
    }

    public void RparentJudge(TreeNode node) {
        if (isMatch(LexType.RPARENT)) {
            addLeaf(node);
        }
        else {
            addError('j');
        }
    }

    public void RbrackJudege(TreeNode node) {
        if (isMatch(LexType.RBRACK)) {
            addLeaf(node);
        }
        else {
            addError('k');
        }
    }
}
