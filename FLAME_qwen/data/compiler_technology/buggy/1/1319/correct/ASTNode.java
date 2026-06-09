import java.io.BufferedWriter;
import java.io.IOException;

public abstract class ASTNode {
    public abstract <T> T accept(ASTVisitor<T> visitor) throws IOException;
}


interface ASTVisitor<T> {
    T visitNumber(NumberNode node) throws IOException;

    T visitBlock(BlockNode blockNode) throws IOException;

    T visitCompUnit(CompUnitNode compUnitNode) throws IOException;

    T visitDecl(DeclNode declNode) throws IOException;

    T visitFuncDef(FuncDefNode funcDefNode) throws IOException;

    T visitBType(BTypeNode bTypeNode) throws IOException;

    T visitCond(CondNode condNode) throws IOException;

    T visitConstDef(ConstDefNode constDefNode) throws IOException;

    T visitConstExp(ConstExpNode constExpNode) throws IOException;

    T visitEqExp(EqExpNode eqExpNode) throws IOException;

    T visitExp(ExpNode expNode) throws IOException;

    T visitForStmt(ForStmtNode forStmtNode) throws IOException;

    T visitVarDef(VarDefNode varDefNode) throws IOException;

    T visitFuncFParam(FuncFParamNode funcFParamNode) throws IOException;

    T visitFuncFParams(FuncFParamsNode funcFParamsNode) throws IOException;

    T visitLAndExp(LAndExpNode lAndExpNode) throws IOException;

    T visitLOrExp(LOrExpNode lOrExpNode) throws IOException;

    T visitLVal(LValNode lValNode) throws IOException;

    T visitMainFuncDef(MainFuncDefNode mainFuncDefNode) throws IOException;

    T visitMulExp(MulExpNode mulExpNode) throws IOException;

    T visitRelExp(RelExpNode relExpNode) throws IOException;

    T visitUnaryOp(UnaryOpNode unaryOpNode) throws IOException;

    T visitVarDecl(VarDeclNode varDeclNode) throws IOException;

    T visitConstDecl(ConstDeclNode constDeclNode) throws IOException;

    T visitFuncRParams(FuncRParamsNode funcRParamsNode) throws IOException;

    T visitAddExp(AddExpNode addExpNode) throws IOException;

    T visitCharacter(char ch) throws IOException;

    T visitDeclBlock(DeclBlock declBlock) throws IOException;

    T visitStmtBlock(StmtBlock stmtBlock) throws IOException;

    T visitStringConst(StringConst stringConst) throws IOException;

    T visitArrayConst(ArrayConst arrayConst) throws IOException;

    T visitNumberConst(NumberConst numberConst) throws IOException;

    T visitNumberVal(NumberVal numberVal) throws IOException;

    T visitArrayVal(ArraryVal arraryVal) throws IOException;

    T visitStringVal(StringVal stringVal) throws IOException;

    T visitCharExp(CharExp charExp) throws IOException;

    T visitNumberExp(NumberExp numberExp) throws IOException;

    T visitLvalExp(LvalExp lvalExp) throws IOException;

    T visitParentExp(ParentExp parentExp) throws IOException;

    T visitPrimaryUExp(PrimaryUExp primaryUExp) throws IOException;

    T visitIdentUExp(IdentUExp identUExp) throws IOException;

    T visitUUExp(UUExp uuExp) throws IOException;

    T visitPrintStmt(PrintStmt printStmt) throws IOException;

    T visitAssignStmt(AssignStmt assignStmt) throws IOException;

    T visitExpStmt(ExpStmt expStmt) throws IOException;

    T visitBlockStmt(BlockStmt blockStmt) throws IOException;

    T visitIfStmt(IfStmt ifStmt) throws IOException;

    T visitFORStmt(ForStmt forStmt) throws IOException;

    T visitBreakStmt(BreakStmt breakStmt) throws IOException;

    T visitContinueStmt(ContinueStmt continueStmt) throws IOException;

    T visitRenturnStmt(ReturnStmt returnStmt) throws IOException;

    T visitIntStmt(IntStmt intStmt) throws IOException;

    T visitCharStmt(CharStmt charStmt) throws IOException;

    T visitFuncType(FuncTypeNode funcTypeNode) throws IOException;
}

class ASTPrinter implements ASTVisitor<String> {
    BufferedWriter bw;

    public ASTPrinter(BufferedWriter bw){
        this.bw = bw;
    }

    @Override
    public String visitNumber(NumberNode node) throws IOException {
        bw.write("INTCON " + node.getValue() + "\n");
        bw.write("<Number>\n");
        return null;
    }

    @Override
    public String visitBlock(BlockNode blockNode) throws IOException {
        bw.write("LBRACE {\n" );
        if (blockNode.blockItems != null)
            for (BlockItemNode blockItemNode : blockNode.blockItems)
                blockItemNode.accept(this);
        bw.write("RBRACE }\n" );

        bw.write("<Block>\n");
        return null;
    }

    @Override
    public String visitCompUnit(CompUnitNode compUnitNode) throws IOException {
        if (compUnitNode.decls != null)
            for (DeclNode declNode : compUnitNode.decls){
                declNode.accept(this);
            }

        if (compUnitNode.funcDefs != null)
            for (FuncDefNode funcDefNode : compUnitNode.funcDefs){
                funcDefNode.accept(this);
            }
        compUnitNode.mainFuncDef.accept(this);
        bw.write("<CompUnit>");
        bw.close();
        return null;
    }

    @Override
    public String visitDecl(DeclNode declNode) throws IOException {
        if (declNode.getConstdecl() != null)
            declNode.getConstdecl().accept(this);
        else
            declNode.getVardecl().accept(this);
        //bw.write("<Decl>\n");
        return null;
    }

    @Override
    public String visitFuncDef(FuncDefNode funcDefNode) throws IOException {
        switch (funcDefNode.getFuncType().getType()){
            case "int":
                bw.write("INTTK int\n");
                break;
            case "char":
                bw.write("CHARTK char\n");
                break;
            case "void":
                bw.write("VOIDTK void\n");
                break;
        }
        bw.write("<FuncType>\n");

        bw.write("IDENFR " + funcDefNode.getIdentifier() + "\n");

        bw.write("LPARENT (\n");
        if (funcDefNode.getParams() != null){
            funcDefNode.getParams().accept(this);
        }
        bw.write("RPARENT )\n");

        funcDefNode.getBlock().accept(this);
        bw.write("<FuncDef>\n");
        return null;
    }

    @Override
    public String visitBType(BTypeNode bTypeNode) throws IOException {
        if (bTypeNode.getF().equals("int"))
            bw.write("INTTK int\n");
        else
            bw.write("CHARTK char\n");
        //bw.write("<BType>\n");
        return null;
    }

    @Override
    public String visitCond(CondNode condNode) throws IOException {
        condNode.getlOrExpNode().accept(this);
        bw.write("<Cond>\n");
        return null;
    }

    @Override
    public String visitConstDef(ConstDefNode constDefNode) throws IOException {
        bw.write("IDENFR " + constDefNode.getIdent() + "\n");

        if (constDefNode.getConstexp() != null) {
            bw.write("LBRACK [\n");
            constDefNode.getConstexp().accept(this);
            bw.write("RBRACK ]\n");
        }

        bw.write("ASSIGN =\n");
        constDefNode.getConstintval().accept(this);

        bw.write("<ConstDef>\n");
        return null;
    }

    @Override
    public String visitConstExp(ConstExpNode constExpNode) throws IOException {
        constExpNode.getAddExpNode().accept(this);
        bw.write("<ConstExp>\n");
        return null;
    }

    @Override
    public String visitEqExp(EqExpNode eqExpNode) throws IOException {

        if (eqExpNode.getEqExpNode() != null){
            eqExpNode.getEqExpNode().accept(this);

            if (eqExpNode.getString().equals("=="))
                bw.write("EQL ==\n");
            else
                bw.write("NEQ !=\n");
        }

        eqExpNode.getRelExpNode().accept(this);
        bw.write("<EqExp>\n");
        return null;
    }

    @Override
    public String visitExp(ExpNode expNode) throws IOException {
        expNode.getAddExp().accept(this);
        bw.write("<Exp>\n");
        return null;
    }

    @Override
    public String visitForStmt(ForStmtNode forStmtNode) throws IOException {
        forStmtNode.getlValNode().accept(this);

        bw.write("ASSIGN =\n");

        forStmtNode.getExpNode().accept(this);

        bw.write("<ForStmt>\n");
        return null;
    }

    @Override
    public String visitVarDef(VarDefNode varDefNode) throws IOException {
        bw.write("IDENFR " + varDefNode.getIdent() + "\n");

        if (varDefNode.getConstExpNode() != null){
            bw.write("LBRACK [\n");
            varDefNode.getConstExpNode().accept(this);
            bw.write("RBRACK ]\n");
        }

        if (varDefNode.getInitValNode() != null){
            bw.write("ASSIGN =\n");
            varDefNode.getInitValNode().accept(this);
        }

        bw.write("<VarDef>\n");
        return null;
    }

    @Override
    public String visitFuncFParam(FuncFParamNode funcFParamNode) throws IOException {
        funcFParamNode.getbTypeNode().accept(this);

        bw.write("IDENFR " + funcFParamNode.getIdent() + "\n");

        if (funcFParamNode.getN() == 1){
            bw.write("LBRACK [\n");
            bw.write("RBRACK ]\n");
        }
        bw.write("<FuncFParam>\n");
        return null;
    }

    @Override
    public String visitFuncFParams(FuncFParamsNode funcFParamsNode) throws IOException {
        int i = 0;
        if (funcFParamsNode.getFuncFParamNodes() != null) {
            for (FuncFParamNode funcFParamNode : funcFParamsNode.getFuncFParamNodes()){
                if (i != 0)
                    bw.write("COMMA ,\n");
                funcFParamNode.accept(this);
                i++;
            }
            bw.write("<FuncFParams>\n");
        }
        return null;
    }

    @Override
    public String visitLAndExp(LAndExpNode lAndExpNode) throws IOException {
        if (lAndExpNode.getlAndExpNode() != null){
            lAndExpNode.getlAndExpNode().accept(this);
            bw.write("AND &&\n");
        }

        lAndExpNode.getEqExpNode().accept(this);
        bw.write("<LAndExp>\n");
        return null;
    }

    @Override
    public String visitLOrExp(LOrExpNode lOrExpNode) throws IOException {
        if (lOrExpNode.getlOrExpNode() != null){
            lOrExpNode.getlOrExpNode().accept(this);
            bw.write("OR ||\n");
        }

        lOrExpNode.getlAndExpNode().accept(this);
        bw.write("<LOrExp>\n");
        return null;
    }

    @Override
    public String visitLVal(LValNode lValNode) throws IOException {
        bw.write("IDENFR " + lValNode.getIdent() + "\n");

        if (lValNode.getExpNode() != null){
            bw.write("LBRACK [\n");
            lValNode.getExpNode().accept(this);
            bw.write("RBRACK ]\n");
        }

        bw.write("<LVal>\n");
        return null;
    }

    @Override
    public String visitMainFuncDef(MainFuncDefNode mainFuncDefNode) throws IOException {
        bw.write("INTTK int\n");
        bw.write("MAINTK main\n");
        bw.write("LPARENT (\n");
        bw.write("RPARENT )\n");

        mainFuncDefNode.getBlock().accept(this);
        bw.write("<MainFuncDef>\n");
        return null;
    }

    @Override
    public String visitMulExp(MulExpNode mulExpNode) throws IOException {
        if (mulExpNode.getMulExpNode() != null){
            mulExpNode.getMulExpNode().accept(this);
            switch (mulExpNode.getCh()){
                case '*':
                    bw.write("MULT *\n");
                    break;
                case '/':
                    bw.write("DIV /\n");
                    break;
                case '%':
                    bw.write("MOD %\n");
                    break;
            }
        }
        mulExpNode.getUnaryExpNode().accept(this);

        bw.write("<MulExp>\n");
        return null;
    }

    @Override
    public String visitRelExp(RelExpNode relExpNode) throws IOException {
        if (relExpNode.getRelExpNode() != null){
            relExpNode.getRelExpNode().accept(this);
            switch (relExpNode.getS()){
                case "<":
                    bw.write("LSS <\n");
                    break;
                case ">":
                    bw.write("GRE >\n");
                    break;
                case "<=":
                    bw.write("LEQ <=\n");
                    break;
                case ">=":
                    bw.write("GEQ >=\n");
                    break;
            }
        }
        relExpNode.getAddExpNode().accept(this);

        bw.write("<RelExp>\n");
        return null;
    }

    @Override
    public String visitUnaryOp(UnaryOpNode unaryOpNode) throws IOException {
        switch (unaryOpNode.getCh()){
            case '+':
                bw.write("PLUS +\n");
                break;
            case '-':
                bw.write("MINU -\n");
                break;
            case '!':
                bw.write("NOT !\n");
                break;
        }

        bw.write("<UnaryOp>\n");
        return null;
    }

    @Override
    public String visitVarDecl(VarDeclNode varDeclNode) throws IOException {
        varDeclNode.getbTypeNode().accept(this);

        int i = 0;
        if (varDeclNode.getVarDefNodes() != null)
            for (VarDefNode varDefNode : varDeclNode.getVarDefNodes()){
                if (i != 0)
                    bw.write("COMMA ,\n");
                varDefNode.accept(this);
                i++;
            }

        bw.write("SEMICN ;\n");
        bw.write("<VarDecl>\n");
        return null;
    }

    @Override
    public String visitConstDecl(ConstDeclNode constDeclNode) throws IOException {
        bw.write("CONSTTK const\n");

        constDeclNode.getBtype().accept(this);

        int i = 0;
        if (constDeclNode.getConstdefs() != null)
            for(ConstDefNode constDefNode: constDeclNode.getConstdefs()){
                if (i != 0)
                    bw.write("COMMA ,\n");
                constDefNode.accept(this);
                i++;
            }

        bw.write("SEMICN ;\n");
        bw.write("<ConstDecl>\n");
        return null;
    }

    @Override
    public String visitFuncRParams(FuncRParamsNode funcRParamsNode) throws IOException {
        int i = 0;
        if (funcRParamsNode.getExpList() != null){
            for (ExpNode expNode : funcRParamsNode.getExpList()){
                if (i != 0)
                    bw.write("COMMA ,\n");
                expNode.accept(this);
                i++;
            }
            bw.write("<FuncRParams>\n");
        }
        return null;
    }

    @Override
    public String visitAddExp(AddExpNode addExpNode) throws IOException {
        if (addExpNode.getAddExpNode() != null){
            addExpNode.getAddExpNode().accept(this);
            switch (addExpNode.getCh()){
                case '+':
                    bw.write("PLUS +\n");
                    break;
                case '-':
                    bw.write("MINU -\n");
                    break;
            }
        }

        addExpNode.getMulExp().accept(this);

        bw.write("<AddExp>\n");
        return null;
    }

    @Override
    public String visitCharacter(char ch) throws IOException {
        bw.write("CHRCON '" + ch +  "'\n");
        bw.write("<Character>\n");
        return null;
    }

    @Override
    public String visitDeclBlock(DeclBlock declBlock) throws IOException {
        declBlock.getDeclNode().accept(this);
        //bw.write("<BlockItem>\n");
        return null;
    }

    @Override
    public String visitStmtBlock(StmtBlock stmtBlock) throws IOException {
        stmtBlock.getStmtNode().accept(this);
        //bw.write("<BlockItem>\n");
        return null;
    }

    @Override
    public String visitStringConst(StringConst stringConst) throws IOException {
        bw.write("STRCON " + stringConst.getS() + "\n");

        bw.write("<ConstInitVal>\n");
        return null;
    }

    @Override
    public String visitArrayConst(ArrayConst arrayConst) throws IOException {
        int i = 0;
        bw.write("LBRACE {\n");
        if (arrayConst.getConstexps() != null)
            for (ConstExpNode constExpNode : arrayConst.getConstexps()){
                if (i != 0)
                    bw.write("COMMA ,\n");
                constExpNode.accept(this);
                i++;
            }
        bw.write("RBRACE }\n");

        bw.write("<ConstInitVal>\n");
        return null;
    }

    @Override
    public String visitNumberConst(NumberConst numberConst) throws IOException {
        numberConst.getConstexp().accept(this);
        bw.write("<ConstInitVal>\n");
        return null;
    }

    @Override
    public String visitNumberVal(NumberVal numberVal) throws IOException {
        numberVal.getExpNode().accept(this);
        bw.write("<InitVal>\n");
        return null;
    }

    @Override
    public String visitArrayVal(ArraryVal arraryVal) throws IOException {
        int i = 0;
        bw.write("LBRACE {\n");
        if (arraryVal.getExpNodes() != null)
            for (ExpNode expNode : arraryVal.getExpNodes()){
                if (i != 0)
                    bw.write("COMMA ,\n");
                expNode.accept(this);
                i++;
            }
        bw.write("RBRACE }\n");

        bw.write("<InitVal>\n");
        return null;
    }

    @Override
    public String visitStringVal(StringVal stringVal) throws IOException {
        bw.write("STRCON " + stringVal.getString() + "\n");

        bw.write("<InitVal>\n");
        return null;
    }

    @Override
    public String visitCharExp(CharExp charExp) throws IOException {
        bw.write("CHRCON " + charExp.getCh() + "\n");
        bw.write("<Character>\n");
        bw.write("<PrimaryExp>\n");
        return null;
    }

    @Override
    public String visitNumberExp(NumberExp numberExp) throws IOException {
        bw.write("INTCON " + numberExp.getA() + "\n");
        bw.write("<Number>\n");

        bw.write("<PrimaryExp>\n");
        return null;
    }

    @Override
    public String visitLvalExp(LvalExp lvalExp) throws IOException {
        lvalExp.getlValNode().accept(this);

        bw.write("<PrimaryExp>\n");
        return null;
    }

    @Override
    public String visitParentExp(ParentExp parentExp) throws IOException {
        bw.write("LPARENT (\n");
        parentExp.getExpNode().accept(this);
        bw.write("RPARENT )\n");

        bw.write("<PrimaryExp>\n");
        return null;
    }

    @Override
    public String visitPrimaryUExp(PrimaryUExp primaryUExp) throws IOException {
        primaryUExp.getPrimaryExpNode().accept(this);

        bw.write("<UnaryExp>\n");
        return null;
    }

    @Override
    public String visitIdentUExp(IdentUExp identUExp) throws IOException {
        bw.write("IDENFR " + identUExp.getIdent() + "\n");
        bw.write("LPARENT (\n");
        if (identUExp.getFuncRParams() != null){
            identUExp.getFuncRParams().accept(this);
        }
        bw.write("RPARENT )\n");

        bw.write("<UnaryExp>\n");
        return null;
    }

    @Override
    public String visitUUExp(UUExp uuExp) throws IOException {
        uuExp.getUnaryOpNode().accept(this);
        uuExp.getUnaryExpNode().accept(this);

        bw.write("<UnaryExp>\n");
        return null;
    }

    @Override
    public String visitPrintStmt(PrintStmt printStmt) throws IOException {
        bw.write("PRINTFTK printf\n");
        bw.write("LPARENT (\n");
        bw.write("STRCON " + printStmt.getString() + "\n");

        if (printStmt.getExpNodes() != null)
            for (ExpNode expNode : printStmt.getExpNodes()){
                bw.write("COMMA ,\n");
                expNode.accept(this);
            }
        bw.write("RPARENT )\n");

        bw.write("SEMICN ;\n");
        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitAssignStmt(AssignStmt assignStmt) throws IOException {
        assignStmt.getLval().accept(this);

        bw.write("ASSIGN =\n");

        assignStmt.getExp().accept(this);
        bw.write("SEMICN ;\n");
        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitExpStmt(ExpStmt expStmt) throws IOException {
        if (expStmt.getExp() != null)
            expStmt.getExp().accept(this);

        bw.write("SEMICN ;\n");
        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitBlockStmt(BlockStmt blockStmt) throws IOException {
        blockStmt.getBlock().accept(this);

        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitIfStmt(IfStmt ifStmt) throws IOException {
        bw.write("IFTK if\n");
        bw.write("LPARENT (\n");

        ifStmt.getCond().accept(this);
        bw.write("RPARENT )\n");

        ifStmt.getStmtNode1().accept(this);

        if (ifStmt.getStmtNode2() != null){
            bw.write("ELSETK else\n");
            ifStmt.getStmtNode2().accept(this);
        }

        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitFORStmt(ForStmt forStmt) throws IOException {
        bw.write("FORTK for\n");
        bw.write("LPARENT (\n");

        if (forStmt.getForStmt() != null)
            forStmt.getForStmt().accept(this);
        bw.write("SEMICN ;\n");

        if (forStmt.getCond() != null)
            forStmt.getCond().accept(this);
        bw.write("SEMICN ;\n");

        if (forStmt.getForStmt2() != null)
            forStmt.getForStmt2().accept(this);
        bw.write("RPARENT )\n");

        forStmt.getStmt().accept(this);

        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitBreakStmt(BreakStmt breakStmt) throws IOException {
        bw.write("BREAKTK break\n");
        bw.write("SEMICN ;\n");
        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitContinueStmt(ContinueStmt continueStmt) throws IOException {
        bw.write("CONTINUETK continue\n");
        bw.write("SEMICN ;\n");
        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitRenturnStmt(ReturnStmt returnStmt) throws IOException {
        bw.write("RETURNTK return\n");
        if (returnStmt.getExp() != null)
            returnStmt.getExp().accept(this);
        bw.write("SEMICN ;\n");

        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitIntStmt(IntStmt intStmt) throws IOException {
        intStmt.getLval().accept(this);

        bw.write("ASSIGN =\n");
        bw.write("GETINTTK getint\n");
        bw.write("LPARENT (\n");
        bw.write("RPARENT )\n");
        bw.write("SEMICN ;\n");
        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitCharStmt(CharStmt charStmt) throws IOException {
        charStmt.getLval().accept(this);

        bw.write("ASSIGN =\n");
        bw.write("GETCHARTK getchar\n");
        bw.write("LPARENT (\n");
        bw.write("RPARENT )\n");
        bw.write("SEMICN ;\n");
        bw.write("<Stmt>\n");
        return null;
    }

    @Override
    public String visitFuncType(FuncTypeNode funcTypeNode) throws IOException {
        switch (funcTypeNode.getType()){
            case "void":
                bw.write("VOIDTK void\n");
                break;
            case "int":
                bw.write("INTTK int\n");
                break;
            case "char":
                bw.write("CHARTK char\n");
                break;
        }
        bw.write("<FuncType>\n");
        return null;
    }
}

