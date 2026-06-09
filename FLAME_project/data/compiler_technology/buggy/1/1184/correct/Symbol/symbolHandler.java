package Symbol;

import node.*;

import java.util.ArrayList;
import java.util.Iterator;

public class symbolHandler {
    private TreeNode compUnitNode;
    private SignalList cur;
    private SignalList begin;
    private ArrayList<tokenError> errors;
    public static int circle = 0;
    public static int layer = 0;

    public symbolHandler(TreeNode compUnitNode,ArrayList<tokenError> errors) {
        this.compUnitNode = compUnitNode;
        this.cur = new SignalList(0,SignalType.NULL,null);
        this.errors = errors;
        this.begin = cur;
    }

    public void compHandler() {
        SignalList comp = new SignalList(++layer,SignalType.NULL,cur);
        cur.addSignal(comp);
        cur = comp;
        ArrayList<TreeNode> nodes = ((CompUnitNode) compUnitNode).getNodes();

        for (TreeNode n : nodes) {
            if (n instanceof DeclNode) {
                DeclHandler((DeclNode) n);
            }
            else if (n instanceof FuncDefNode) {
                FuncDefNode funcDefNode = (FuncDefNode) n;
                int type = funcDefNode.getFuncType();
                Token ident = funcDefNode.getIdent();
                SignalFunc func = new SignalFunc(ident.getIdent(),funcDefNode.getFuncFParams(),type);
                if (cur.findSignalb(ident.getIdent())) { //重复定义
                    errors.add(new tokenError(ident.getLine(), "b"));
                } else {

                    cur.addSignal(func);
                }
                SignalList fu = new SignalList(++layer,func.getType(),comp);
                cur.addSignal(fu);
                cur = fu;
                FuncDefHandler(funcDefNode);

                cur = comp;

            } else { //main
                ArrayList<TreeNode> treeNodes = ((MainFuncDefNode) n).getNodes();
                SignalList main = new SignalList(++layer,SignalType.IntFunc,cur);
                SignalList temp = cur;
                cur.addSignal(main);
                cur = main;
                BlockHandler((BlockNode) (treeNodes.get(treeNodes.size() - 1)),0);
            }
        }
    }

    public void FuncDefHandler(FuncDefNode funcDefNode) {
        ArrayList<FuncFParamNode> funcFParamNodes = funcDefNode.getFuncFParams();
        for (FuncFParamNode f : funcFParamNodes) {
            Token t = f.getIdent();
            if (cur.findSignalb(t.getIdent())) {
                errors.add(new tokenError(t.getLine(),"b"));
            } else {
                cur.addSignal(new SignalNode(t,f.getSignalType()));
            }
        }
        BlockHandler(funcDefNode.getBlock(),0);
    }

    public void BlockHandler(BlockNode blockNode,int layer_B) { // 0表示不用进入下一层，1表示进入下一层
        SignalList temp = cur;
        if (layer_B == 1) {
            SignalList l = new SignalList(++layer, SignalType.NULL,cur);
            cur.addSignal(l);
            cur = l;
        }


        ArrayList<TreeNode> treeNodes = blockNode.getNodes();
        for (TreeNode t : treeNodes) {
            if (t instanceof BlockItemNode) {
                BlockItemHandler((BlockItemNode) t);
            } else if (t instanceof Token) {
                if (((Token)t).getIdent().equals("}")) {
                    if (cur.canReturnf() && (findLast(treeNodes) != null && !isReturn(findLast(treeNodes)) || findLast(treeNodes) == null)) { //不应该报g的时候报了
                        errors.add(new tokenError(((Token)t).getLine(),"g"));
                    }
                }
            }
        }

        cur = temp;
    }

    public BlockItemNode findLast(ArrayList<TreeNode> arrayList) {
        BlockItemNode blockItemNode = null;
        for (TreeNode treeNode : arrayList) {
            if (treeNode instanceof BlockItemNode) {
                blockItemNode = (BlockItemNode) treeNode;
            }
        }
        return blockItemNode;
    }

    public boolean isReturn(BlockItemNode blockItemNode) {
        if (blockItemNode.getNode() instanceof StmtNode) {
            StmtNode stmtNode = (StmtNode) (blockItemNode.getNode());
            ArrayList<TreeNode> treeNodes = stmtNode.getNodes();
            TreeNode first = treeNodes.get(0);
            if (first instanceof  Token) {
                if (((Token)first).getIdent().equals("return")) {
                    return true;
                }
            }
        }
        return  false;
    }

    public void BlockItemHandler(BlockItemNode blockItemNode) {
        if (blockItemNode.getNode() instanceof DeclNode) {
            DeclHandler((DeclNode) (blockItemNode.getNode()));
        } else {
            StmtHandler((StmtNode) (blockItemNode.getNode()));
        }
    }

    public void StmtHandler(StmtNode stmtNode) {
        ArrayList<TreeNode> treeNodes = stmtNode.getNodes();
        TreeNode first = treeNodes.get(0);
        if (first instanceof ExpNode) {
            ExpHandler((ExpNode) first);
        }
        else if (first instanceof LValNode) {
            LValHandler(stmtNode.getLVal());
            Token token = stmtNode.getLVal().getIdent();
            if (cur.findIdentType(token.getIdent()).equals(SignalType.ConstIntArray) ||
                    cur.findIdentType(token.getIdent()).equals(SignalType.ConstCharArray) ||
                    cur.findIdentType(token.getIdent()).equals(SignalType.ConstInt) ||
                    cur.findIdentType(token.getIdent()).equals(SignalType.ConstChar) || token.getTokenType().equals(TokenType.CHRCON) || token.getTokenType().equals(TokenType.INTCON) || token.getTokenType().equals(TokenType.STRCON)) {
                errors.add(new tokenError(token.getLine(),"h"));
            }
            if (stmtNode.getExp() != null) {
                ExpHandler(stmtNode.getExp());
            }
        } else if (first instanceof BlockNode) {
            BlockHandler((BlockNode) first,1);
        }else if (first instanceof Token) {
            Token token = (Token) first;
            if (token.getIdent().equals("if")) {
                //TODO
                if (stmtNode.getCond() != null) {
                    CondHandler(stmtNode.getCond());
                }
                if (stmtNode.getStmt1() != null) {
                    StmtHandler(stmtNode.getStmt1());
                }
                if (stmtNode.getStmt2() != null) {
                    StmtHandler(stmtNode.getStmt2());
                }
            } else if (token.getIdent().equals("for")) {
                if (stmtNode.getForStmt1() != null) {
                    ForStmtHandler(stmtNode.getForStmt1());
                }
                if (stmtNode.getCond() != null) {
                    CondHandler(stmtNode.getCond());
                }
                if (stmtNode.getForStmt2() != null) {
                    ForStmtHandler(stmtNode.getForStmt2());
                }
                circle++;
                StmtHandler((StmtNode) (treeNodes.get(treeNodes.size() - 1)));
                circle--;
            }
            else if (token.getIdent().equals("break") || token.getIdent().equals("continue")) {
                if (circle == 0) {
                    errors.add(new tokenError(token.getLine(),"m"));
                }
            } else if (token.getIdent().equals("return")) {

                if (treeNodes.size() > 1 && (treeNodes.get(1) instanceof  ExpNode)) {
                    ExpHandler((ExpNode) (treeNodes.get(1)));
                }

                if (!cur.canReturn() &&treeNodes.size() > 2 && getExpType((ExpNode) (treeNodes.get(1))) != -1) {
                    errors.add(new tokenError(token.getLine(),"f"));
                }
                cur.setReturned();
            } else if (token.getIdent().equals("printf")) {
                ArrayList<Integer> ans = StringConstHandler((Token) (treeNodes.get(2)));
                ArrayList<Integer> ans_t = new ArrayList<>();
                for (int i = 3;i < treeNodes.size();i++) {
                    if (treeNodes.get(i) instanceof ExpNode) {
                        ExpHandler((ExpNode) (treeNodes.get(i)));
                        ans_t.add(getExpType((ExpNode) (treeNodes.get(i))));
                    }
                }


                if (ans_t.size() != ans.size()) {
                    errors.add(new tokenError(token.getLine(),"l"));
                    return;
                }

                for (int i = 0;i < ans.size();i++) {
                    if (ans_t.get(i) != ans.get(i)) {
                        if (ans.get(i) == 0 && ans_t.get(i) == 3) {
                            continue;
                        }
                        if (ans.get(i) == 3 && ans_t.get(i) == 0) {
                            continue;
                        }
                        errors.add(new tokenError(token.getLine(),"l"));
                        return;
                    }
                }
            }

        }
    }

    public ArrayList<Integer> StringConstHandler(Token token) { //有问题
        String ident = token.getIdent();
        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0;i < ident.length();i++) {
            if (ident.charAt(i) == '%') {
                if (i != 0 && ident.charAt(i-1) == '\\') {
                    continue;
                }
                if (ident.charAt(i+1) == 's') {
                    ans.add(2);
                } else if (ident.charAt(i+1) == 'c') {
                    ans.add(3);
                }
                else {
                    ans.add(0);
                }
            }
        }
        return ans;
    }

    public void ForStmtHandler(ForStmtNode forStmtNode) {
        LValNode lValNode = forStmtNode.getLVal();
        LValHandler(lValNode);
        Token token = lValNode.getIdent();
        if (cur.findIdentType(lValNode.getIdent().getIdent()).equals(SignalType.ConstIntArray) ||
                cur.findIdentType(lValNode.getIdent().getIdent()).equals(SignalType.ConstCharArray) ||
                cur.findIdentType(lValNode.getIdent().getIdent()).equals(SignalType.ConstInt) ||
                cur.findIdentType(lValNode.getIdent().getIdent()).equals(SignalType.ConstChar) || token.getTokenType().equals(TokenType.CHRCON) || token.getTokenType().equals(TokenType.INTCON) || token.getTokenType().equals(TokenType.STRCON)) {
            errors.add(new tokenError(lValNode.getIdent().getLine(),"h"));
        }
        ExpHandler(forStmtNode.getExp());

    }

    public void CondHandler(CondNode condNode) {
        LOrExpHandler((LOrExpNode) (condNode.getNode()));
    }

    public void LOrExpHandler(LOrExpNode lOrExpNode) {
        ArrayList<TreeNode> treeNodes = lOrExpNode.getNodes();
        for (TreeNode t : treeNodes) {
            if (t instanceof LAndExpNode) {
                LAndExpHandler((LAndExpNode) t);
            }else if (t instanceof LOrExpNode) {
                LOrExpHandler((LOrExpNode)  t);
            }
        }
    }

    public void LAndExpHandler(LAndExpNode lAndExpNode) {
        ArrayList<TreeNode> treeNodes = lAndExpNode.getNodes();
        for (TreeNode t : treeNodes) {
            if (t instanceof LAndExpNode) {
                LAndExpHandler((LAndExpNode) t);
            }else if (t instanceof EqExpNode) {
                EqExpHandler((EqExpNode) t);
            }
        }
    }

    public void EqExpHandler(EqExpNode expNode) {
        ArrayList<TreeNode> treeNodes = expNode.getNodes();
        for (TreeNode t : treeNodes) {
            if (t instanceof  RelExpNode) {
                RelExpHandler((RelExpNode) t);
            }else if (t instanceof EqExpNode) {
                EqExpHandler((EqExpNode) t);
            }
        }
    }

    public void RelExpHandler(RelExpNode relExpNode) {
        ArrayList<TreeNode> treeNodes = relExpNode.getNodes();
        for (TreeNode t : treeNodes) {
            if (t instanceof  AddExpNode) {
                AddExpHandler((AddExpNode) t);
            }else if (t instanceof RelExpNode) {
                RelExpHandler((RelExpNode) t);
            }
        }
    }

    public void DeclHandler(DeclNode declNode) {
        if (declNode.getDeclType() == 0) {
            // ConstDecl
            ConstDeclHandler((ConstDeclNode) (declNode.getNode()));
        }
        else {
            // VarDecl
            VarDeclHandler((VarDeclNode) (declNode.getNode()));
        }
    }

    public void ConstDeclHandler(ConstDeclNode constDeclNode) {
        ArrayList<ConstDefNode> constDefNodes = constDeclNode.getConstDef();
        int type = constDeclNode.getType();
        for (ConstDefNode n : constDefNodes) {
            ConstDefHandler(n,type);
        }
    }

    public ArrayList<tokenError> getErrors() {
        return errors;
    }

    public void ConstDefHandler(ConstDefNode constDefNode,int type) {
        Token ident = constDefNode.getIdent();
        if (cur.findSignalb(ident.getIdent())) {
            errors.add(new tokenError(ident.getLine(), "b"));//重复定义错误
            return;
        }
        int identType = constDefNode.getType();
        if (type == 0 && identType == 1) {
            cur.addSignal(new SignalNode(ident,SignalType.ConstIntArray));
        } else if (type == 0) {
            cur.addSignal(new SignalNode(ident,SignalType.ConstInt));
        } else if (identType == 1) {
            cur.addSignal(new SignalNode(ident,SignalType.ConstCharArray));
        } else {
            cur.addSignal(new SignalNode(ident,SignalType.ConstChar));
        }
        if (identType == 1) {
            //ConstExp
            ConstExpHandler(constDefNode.getConstExpNode());
        }

        //ConstInitVal
        ConstInitValHandler(constDefNode.getConstInitValNode());
    }

    public void ConstInitValHandler(ConstInitValNode constInitValNode) {
        if (constInitValNode == null) {
            return;
        }
        ArrayList<TreeNode> treeNodes = constInitValNode.getNodes();
        for (TreeNode tn : treeNodes) {
            if (tn instanceof ConstExpNode) {
                ConstExpHandler((ConstExpNode) tn);
            }
        }
    }

    public void AddExpHandler(AddExpNode addExpNode) {
        ArrayList<TreeNode> nodeArrayList = addExpNode.getNodes();
        for (TreeNode tn : nodeArrayList) {
            if (tn instanceof AddExpNode) {
                AddExpHandler((AddExpNode) tn);
            } else if (tn instanceof MulExpNode) {
                MulExpHandler((MulExpNode) tn);
            }
        }
    }

    public void MulExpHandler(MulExpNode mulExpNode) {
        ArrayList<TreeNode> nodeArrayList = mulExpNode.getNodes();
        for (TreeNode tn : nodeArrayList) {
            if (tn instanceof MulExpNode) {
                MulExpHandler((MulExpNode) tn);
            } else if (tn instanceof UnaryExpNode) {
                UnaryExpHandler((UnaryExpNode) tn);
            }
        }
    }

    public void UnaryExpHandler(UnaryExpNode unaryExpNode) {
        ArrayList<TreeNode> nodeArrayList = unaryExpNode.getNodes();
        if (nodeArrayList.get(0) instanceof  PrimaryExpNode) {
            PrimaryExpHandler((PrimaryExpNode) (nodeArrayList.get(0)));
        } else if (nodeArrayList.get(0) instanceof UnaryOpNode) {
            UnaryExpHandler((UnaryExpNode) (nodeArrayList.get(1)));
        } else {
            // TODO
            Token ident = (Token) (nodeArrayList.get(0));
            Signal signal = cur.findS(ident.getIdent());
            if (signal instanceof SignalFunc) {
                SignalFunc signalFunc = (SignalFunc) (signal);
                //处理形参
                ArrayList<Integer> Fparams = new ArrayList<>();
                ArrayList<Integer> Rparams = new ArrayList<>();
                ArrayList<SignalParams> params = signalFunc.getParams();
                for (SignalParams p : params) {
                    Fparams.add(p.getType());
                }

                if (nodeArrayList.size() > 2 && (nodeArrayList.get(2) instanceof FuncRParamsNode)) {
                    FuncRParamsNode funcRParamsNode = (FuncRParamsNode) (nodeArrayList.get(2));
                    ArrayList<TreeNode> nodes = funcRParamsNode.getNodes();
                    for (TreeNode t : nodes) {
                        if (t instanceof  ExpNode) {
                            ExpHandler((ExpNode) t);
                            int temp = getExpType((ExpNode) t);
                            if (temp == 3) {
                                Rparams.add(0);
                            }
                            else {
                                Rparams.add(temp);
                            }

                        }
                    }
                }

                if (Fparams.size() != Rparams.size()) {
                    errors.add(new tokenError(ident.getLine(),"d"));
                    return;
                }
                if (!Fparams.equals(Rparams)) {
                    errors.add(new tokenError(ident.getLine(),"e"));
                    return;
                }/*
                SignalList temp = cur;
                SignalList f = new SignalList(cur.getLayer() + 1, signalFunc.getType(),cur);
                cur.addSignal(f);
                cur = f;
                FuncDefHandler(findFuncDef(ident.getIdent()));
                cur = temp;*/

            } else {
                if (!cur.findSignal(ident.getIdent())) {
                    errors.add(new tokenError(ident.getLine(), "c")); //函数名未定义
                }
            }
        }
    }

    public FuncDefNode findFuncDef(String ident) {
        ArrayList<TreeNode> nodes = ((CompUnitNode) compUnitNode).getNodes();
        for (TreeNode t : nodes) {
            if (t instanceof FuncDefNode) {
                if (((FuncDefNode) t).getIdent().getIdent().equals(ident)) {
                    return ((FuncDefNode) t);
                }
            }
        }
        return null;
    }

    public int getExpType(ExpNode expNode) {
        return getAddExpType(expNode.getNode());
    }

    public int getAddExpType(AddExpNode addExpNode) {
        ArrayList<TreeNode> treeNodes = addExpNode.getNodes();
        int ans = 0;
        for (TreeNode t : treeNodes) {
            if (t instanceof AddExpNode) {
                int temp = getAddExpType((AddExpNode) t);
                if (temp == 1 || temp == 2) {
                    ans = temp;
                }
            }
            else if (t instanceof MulExpNode) {
                if (ans != 1 && ans != 2) {
                    ans = getMulExpType((MulExpNode) t);
                }
            }
        }
        return ans;
    }

    public int getMulExpType(MulExpNode mulExpNode) {
        ArrayList<TreeNode> treeNodes = mulExpNode.getNodes();
        int ans = 0;
        for (TreeNode treeNode :treeNodes) {
            if (treeNode instanceof MulExpNode) {
                int temp = getMulExpType((MulExpNode) treeNode);
                if (temp == 1 || temp == 2) {
                    ans = temp;
                }
            }
            else if (treeNode instanceof UnaryExpNode) {
                if (ans != 1 &&  ans != 2) {
                    ans = getUnaryExpType((UnaryExpNode) treeNode);
                }
            }
        }
        return ans;
    }

    public int getUnaryExpType(UnaryExpNode unaryExpNode) {
        ArrayList<TreeNode> treeNodes = unaryExpNode.getNodes();
        if (treeNodes.get(0) instanceof PrimaryExpNode) {
            return getPrimaryExpType((PrimaryExpNode) (treeNodes.get(0)));
        } else if (treeNodes.get(0) instanceof UnaryOpNode) {
            return getUnaryExpType((UnaryExpNode) (treeNodes.get(1)));
        } else {
            SignalType s = cur.findIdentType(((Token) (treeNodes.get(0))).getIdent());
            if (s.equals(SignalType.VoidFunc)) {
                return -1;
            }
            return 0;
        }
    }

    public int getPrimaryExpType(PrimaryExpNode primaryExpNode) {
        ArrayList<TreeNode> treeNodes = primaryExpNode.getNodes();
        if (treeNodes.size() > 1) {
            return getExpType((ExpNode) (treeNodes.get(1)));
        }
        else if (treeNodes.get(0) instanceof LValNode) {
            return getLValType((LValNode) (treeNodes.get(0)));
        } else {
            return 0;
        }
    }

    public int getLValType(LValNode lValNode) {
        ArrayList<TreeNode> treeNodes = lValNode.getNodes();
        Token ident = lValNode.getIdent();
        SignalType type = cur.findIdentType(ident.getIdent());
        if (type.equals(SignalType.NULL)) {
            return -1;
        } else if (type.equals(SignalType.CharArray) || type.equals(SignalType.ConstCharArray)) {
            if (treeNodes.size() == 1) {
                return 2;
            }
            return 3;
        } else if (type.equals(SignalType.IntArray) || type.equals(SignalType.ConstIntArray)) {
            if (treeNodes.size() == 1) {
                return 1;
            }
            return 0;

        } else {
            if (type.equals(SignalType.Int) || type.equals(SignalType.IntFunc) ||type.equals(SignalType.ConstInt)) {
                return 0;
            } else if (type.equals(SignalType.Char) || type.equals(SignalType.CharFunc) ||type.equals(SignalType.ConstChar)) {
                return 3;
            }
        }
        return -1;
    }

    public void PrimaryExpHandler(PrimaryExpNode primaryExpNode) {
        ArrayList<TreeNode> nodeArrayList = primaryExpNode.getNodes();
        if (nodeArrayList.get(0) instanceof LValNode) {
            LValHandler((LValNode) (nodeArrayList.get(0)));
        } else if (nodeArrayList.get(0) instanceof Token) {
            ExpHandler((ExpNode) (nodeArrayList.get(1)));
        }
    }

    public void LValHandler(LValNode lValNode) {
        Token ident = lValNode.getIdent();
        if (!cur.findSignal(ident.getIdent())) {
            errors.add(new tokenError(ident.getLine(), "c")); //未定义错误
            return;
        }
        if (lValNode.getExp() != null) {
            ExpHandler(lValNode.getExp());
        }
    }

    public void ExpHandler(ExpNode expNode) {
        AddExpHandler(expNode.getNode());
    }

    public void ConstExpHandler(ConstExpNode constExpNode) {
        AddExpHandler(constExpNode.getNode());
    }

    public void VarDeclHandler(VarDeclNode n) {
        ArrayList<TreeNode> treeNodes = n.getNodes();
        int type = n.getType();
        for (TreeNode tn : treeNodes) {
            if (tn instanceof VarDefNode) {
                VarDefHandler((VarDefNode) tn,type);
            }
        }
    }

    public SignalList getSignal() {
        return begin;
    }

    public void VarDefHandler(VarDefNode varDefNode,int type) {
        Token ident = varDefNode.getIdent();
        if (cur.findSignalb(ident.getIdent())) { //重复定义
            errors.add(new tokenError(ident.getLine(), "b"));
            return;
        }
        int identType = varDefNode.getType();
        if (type == 0 && identType == 1) {
            cur.addSignal(new SignalNode(ident,SignalType.IntArray));
        } else if (type == 0) {
            cur.addSignal(new SignalNode(ident,SignalType.Int));
        } else if (identType == 1) {
            cur.addSignal(new SignalNode(ident,SignalType.CharArray));
        } else {
            cur.addSignal(new SignalNode(ident,SignalType.Char));
        }
        if (identType == 1) {
            ConstExpHandler(varDefNode.getConstExp());
        }
        if (varDefNode.getInitVal() != null) {
            InitValHandler(varDefNode.getInitVal());
        }
    }

    public void InitValHandler(InitValNode initValNode) {
        ArrayList<TreeNode> nodeArrayList = initValNode.getNodes();
        for (TreeNode tn : nodeArrayList) {
            if (tn instanceof ExpNode) {
                ExpHandler((ExpNode) tn);
            }
        }
    }
}





