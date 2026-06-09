package frontend;

import java.util.ArrayList;

public class Parser {
    private ArrayList<Token> tokenList;
    private int tokenIndex = 0;  //当前正在处理的token索引

    public Parser(ArrayList<Token> tokenList) {
        this.tokenList = tokenList;
    }

    public BranchNode compUnit() {
        BranchNode parent = new BranchNode(UnitType.COMPUNIT);
        while (!tokenList.get(tokenIndex + 2).getType().equals(TokenType.LPARENT)) {
            BranchNode child1 = decl();
            connect(parent, child1);
        }
        while (!tokenList.get(tokenIndex + 1).getType().equals(TokenType.MAINTK)) {
            BranchNode child2 = funcDef();
            connect(parent, child2);
        }
        BranchNode child3 = mainFuncDef();
        connect(parent, child3);
        return null;
    }

    public BranchNode decl() {
        BranchNode parent = new BranchNode(UnitType.DECL);
        BranchNode child;
        if (tokenList.get(tokenIndex).getType().equals(TokenType.CONSTTK)) {
            child = constDecl();
        }
        else {
            child = varDecl();
        }
        connect(parent, child);
        return parent;
    }

    public BranchNode constDecl() {
        BranchNode parent = new BranchNode(UnitType.CONSTDECL);
        LeafNode child1 = createLeafNode();
        connect(parent, child1);
        BranchNode child2 = bType();
        connect(parent, child2);
        BranchNode child3 = constDef();
        connect(parent, child3);
        while (tokenList.get(tokenIndex).getType().equals(TokenType.COMMA)) {
            LeafNode child4 = createLeafNode();
            connect(parent, child4);
            BranchNode child5 = constDef();
            connect(parent, child5);
        }
        LeafNode child6 = createLeafNode();
        connect(parent, child6);
        return parent;
    }

    public BranchNode bType() {
        BranchNode parent = new BranchNode(UnitType.BTYPE);
        LeafNode child = createLeafNode();
        connect(parent, child);
        return parent;
    }

    public BranchNode constDef() {
        BranchNode parent = new BranchNode(UnitType.CONSTDEF);
        LeafNode child1 = createLeafNode();
        connect(parent, child1);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.LBRACK)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = constExp();
            connect(parent, child3);
            LeafNode child4 = createLeafNode();
            connect(parent, child4);
        }
        LeafNode child5 = createLeafNode();
        connect(parent, child5);
        BranchNode child6 = constInitVal();
        connect(parent, child6);
        return parent;
    }

    public BranchNode constInitVal() {
        BranchNode parent = new BranchNode(UnitType.CONSTINITVAL);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.LBRACE)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            if (!tokenList.get(tokenIndex).getType().equals(TokenType.RBRACE)) {
                BranchNode child2 = constExp();
                connect(parent, child2);
                while (tokenList.get(tokenIndex).getType().equals(TokenType.COMMA)) {
                    LeafNode child3 = createLeafNode();
                    connect(parent, child3);
                    BranchNode child4 = constExp();
                    connect(parent, child4);
                }
            }
            LeafNode child5 = createLeafNode();
            connect(parent, child5);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.STRCON)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
        }
        else {
            BranchNode child1 = constExp();
            connect(parent, child1);
        }
        return parent;
    }

    public BranchNode varDecl() {
        BranchNode parent = new BranchNode(UnitType.VARDECL);
        BranchNode child1 = bType();
        connect(parent, child1);
        BranchNode child2 = varDef();
        connect(parent, child2);
        while (tokenList.get(tokenIndex).getType().equals(TokenType.COMMA)) {
            LeafNode child3 = createLeafNode();
            connect(parent, child3);
            BranchNode child4 = varDef();
            connect(parent, child4);
        }
        LeafNode child5 = createLeafNode();
        connect(parent, child5);
        return parent;
    }

    public BranchNode varDef() {
        BranchNode parent = new BranchNode(UnitType.VARDEF);
        LeafNode child1 = createLeafNode();
        connect(parent, child1);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.LBRACK)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = constExp();
            connect(parent, child3);
            LeafNode child4 = createLeafNode();
            connect(parent, child4);
        }
        if (tokenList.get(tokenIndex).getType().equals(TokenType.ASSIGN)) {
            LeafNode child5 = createLeafNode();
            connect(parent, child5);
            BranchNode child6 = initVal();
            connect(parent, child6);
        }
        return parent;
    }

    public BranchNode initVal() {
        BranchNode parent = new BranchNode(UnitType.INITVAL);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.LBRACE)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            if (!tokenList.get(tokenIndex).getType().equals(TokenType.RBRACE)) {
                BranchNode child2 = exp();
                connect(parent, child2);
                while (tokenList.get(tokenIndex).getType().equals(TokenType.COMMA)) {
                    LeafNode child3 = createLeafNode();
                    connect(parent, child3);
                    BranchNode child4 = exp();
                    connect(parent, child4);
                }
            }
            LeafNode child5 = createLeafNode();
            connect(parent, child5);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.STRCON)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
        }
        else {
            BranchNode child1 = exp();
            connect(parent, child1);
        }
        return parent;
    }

    public BranchNode funcDef() {
        BranchNode parent = new BranchNode(UnitType.FUNCDEF);
        BranchNode child1 = funcType();
        connect(parent, child1);
        LeafNode child2 = createLeafNode();
        connect(parent, child2);
        LeafNode child3 = createLeafNode();
        connect(parent, child3);
        if (!tokenList.get(tokenIndex).getType().equals(TokenType.RBRACE)) {
            BranchNode child4 = funcParams();
            connect(parent, child4);
        }
        LeafNode child4 = createLeafNode();
        connect(parent, child4);
        BranchNode child5 = block();
        connect(parent, child5);
        return parent;
    }

    public BranchNode mainFuncDef() {
        BranchNode parent = new BranchNode(UnitType.MAINFUNCDEF);
        LeafNode child1 = createLeafNode();
        connect(parent, child1);
        LeafNode child2 = createLeafNode();
        connect(parent, child2);
        LeafNode child3 = createLeafNode();
        connect(parent, child3);
        LeafNode child4 = createLeafNode();
        connect(parent, child4);
        BranchNode child5 = block();
        connect(parent, child5);
        return parent;
    }

    public BranchNode funcType() {
        BranchNode parent = new BranchNode(UnitType.FUNCTYPE);
        LeafNode child = createLeafNode();
        connect(parent, child);
        return parent;
    }

    public BranchNode funcParams() {
        BranchNode parent = new BranchNode(UnitType.FUNCFPARAM);
        BranchNode child1 = funcParam();
        connect(parent, child1);
        while (tokenList.get(tokenIndex).getType().equals(TokenType.COMMA)) {
            LeafNode child2 =  createLeafNode();
            connect(parent, child2);
            BranchNode child3 = funcParam();
            connect(parent, child3);
        }
        return parent;
    }

    public BranchNode funcParam() {
        BranchNode parent = new BranchNode(UnitType.FUNCFPARAM);
        BranchNode child1 = bType();
        connect(parent, child1);
        LeafNode child2 = createLeafNode();
        connect(parent, child2);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.LBRACK)) {
            LeafNode child3 = createLeafNode();
            connect(parent, child3);
            LeafNode child4 = createLeafNode();
            connect(parent, child4);
        }
        return parent;
    }

    public BranchNode block() {
        BranchNode parent = new BranchNode(UnitType.BLOCK);
        LeafNode child1 = createLeafNode();
        connect(parent, child1);
        while (!tokenList.get(tokenIndex).getType().equals(TokenType.RBRACE)) {
            BranchNode child2 = blockItem();
            connect(parent, child2);
        }
        LeafNode child3 = createLeafNode();
        connect(parent, child3);
        return parent;
    }

    public BranchNode blockItem() {
        BranchNode parent = new BranchNode(UnitType.BLOCKITEM);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.CONSTTK)
        || tokenList.get(tokenIndex).getType().equals(TokenType.INTTK)
        || tokenList.get(tokenIndex).getType().equals(TokenType.CHARTK)) {
            BranchNode child = decl();
            connect(parent, child);
        }
        else {
            BranchNode child = stmt();
            connect(parent, child);
        }
        return parent;
    }

    public BranchNode stmt() {
        BranchNode parent = new BranchNode(UnitType.STMT);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.LBRACE)) {
            BranchNode child = block();
            connect(parent, child);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.IFTK)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = cond();
            connect(parent, child3);
            LeafNode child4 = createLeafNode();
            connect(parent, child4);
            BranchNode child5 = stmt();
            connect(parent, child5);
            if (tokenList.get(tokenIndex).getType().equals(TokenType.ELSETK)) {
                LeafNode child6 = createLeafNode();
                connect(parent, child6);
                BranchNode child7 = stmt();
                connect(parent, child7);
            }
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.FORTK)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            if (!tokenList.get(tokenIndex).getType().equals(TokenType.SEMICN)) {
                BranchNode child3 = forStmt();
                connect(parent, child3);
            }
            LeafNode child4 = createLeafNode();
            connect(parent, child4);
            if (!tokenList.get(tokenIndex).getType().equals(TokenType.SEMICN)) {
                BranchNode child5 = cond();
                connect(parent, child5);
            }
            LeafNode child6 = createLeafNode();
            connect(parent, child6);
            if (!tokenList.get(tokenIndex).getType().equals(TokenType.RPARENT)) {
                BranchNode child7 = forStmt();
                connect(parent, child7);
            }
            LeafNode child8 = createLeafNode();
            connect(parent, child8);
            BranchNode child9 = stmt();
            connect(parent, child9);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.BREAKTK)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.CONTINUETK)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.RETURNTK)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            if (!tokenList.get(tokenIndex).getType().equals(TokenType.SEMICN)) {
                BranchNode child2 = exp();
                connect(parent, child2);
            }
            LeafNode child3 = createLeafNode();
            connect(parent, child3);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.PRINTFTK)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            LeafNode child3 = createLeafNode();
            connect(parent, child3);
            while (tokenList.get(tokenIndex).getType().equals(TokenType.COMMA)) {
                LeafNode child4 = createLeafNode();
                connect(parent, child4);
                BranchNode child5 = exp();
                connect(parent, child5);
            }
            LeafNode child6 = createLeafNode();
            connect(parent, child6);
            LeafNode child7 = createLeafNode();
            connect(parent, child7);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.IDENFR)) { //不确定
            BranchNode child1 = lVal();
            connect(parent, child1);
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            if (tokenList.get(tokenIndex).getType().equals(TokenType.GETINTTK)
                    || tokenList.get(tokenIndex).getType().equals(TokenType.GETCHARTK)) {
                LeafNode child3 = createLeafNode();
                connect(parent, child3);
                LeafNode child4 = createLeafNode();
                connect(parent, child4);
                LeafNode child5 = createLeafNode();
                connect(parent, child5);
            }
            else {
                BranchNode child3 = exp();
                connect(parent, child3);
            }
            LeafNode child6 = createLeafNode();
            connect(parent, child6);
        }
        else {
            if (tokenList.get(tokenIndex).getType().equals(TokenType.SEMICN)) {
                BranchNode child1 = exp();
                connect(parent, child1);
            }
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
        }
        return parent;
    }

    public BranchNode forStmt() {
        BranchNode parent = new BranchNode(UnitType.FORSTMT);
        BranchNode child1 = lVal();
        connect(parent, child1);
        LeafNode child2 = createLeafNode();
        connect(parent, child2);
        BranchNode child3 = exp();
        connect(parent, child3);
        return parent;
    }

    public BranchNode exp() {
        BranchNode parent = new BranchNode(UnitType.EXP);
        BranchNode child = addExp();
        connect(parent, child);
        return parent;
    }

    public BranchNode cond() {
        BranchNode parent = new BranchNode(UnitType.COND);
        BranchNode child = lOrExp();
        connect(parent, child);
        return parent;
    }

    public BranchNode lVal() {
        BranchNode parent = new BranchNode(UnitType.LVAL);
        LeafNode child1 = createLeafNode();
        connect(parent, child1);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.LBRACK)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = exp();
            connect(parent, child3);
            LeafNode child4 = createLeafNode();
            connect(parent, child4);
        }
        return parent;
    }

    public BranchNode primaryExp() {
        BranchNode parent = new BranchNode(UnitType.PRIMARYEXP);
        if (tokenList.get(tokenIndex).getType().equals(TokenType.LPARENT)) {
            LeafNode child1 = createLeafNode();
            connect(parent, child1);
            BranchNode child2 = exp();
            connect(parent, child2);
            LeafNode child3 = createLeafNode();
            connect(parent, child3);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.INTCON)) {
            BranchNode child = number();
            connect(parent, child);
        }
        else if (tokenList.get(tokenIndex).getType().equals(TokenType.CHRCON)) {
            BranchNode child = character();
            connect(parent, child);
        }
        else {
            BranchNode child = lVal();
            connect(parent, child);
        }
        return parent;
    }

    public BranchNode number() {
        BranchNode parent = new BranchNode(UnitType.NUMBER);
        LeafNode child = createLeafNode();
        connect(parent, child);
        return parent;
    }

    public BranchNode character() {
        BranchNode parent = new BranchNode(UnitType.CHARACTER);
        LeafNode child = createLeafNode();
        connect(parent, child);
        return parent;
    }

    public BranchNode unaryExp() {
        BranchNode parent = new BranchNode(UnitType.UNARYEXP);
        LeafNode child = createLeafNode();
        connect(parent, child);
        return parent;
    }

    public BranchNode funcRParams() {
        BranchNode parent = new BranchNode(UnitType.FUNCRPARAMS);
        BranchNode child1 = exp();
        connect(parent, child1);
        while (tokenList.get(tokenIndex).getType().equals(TokenType.COMMA)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = exp();
            connect(parent, child3);
        }
        return parent;
    }

    public BranchNode mulExp() {
        BranchNode parent = new BranchNode(UnitType.MULEXP);
        BranchNode child1 = unaryExp();
        connect(parent, child1);
        while(tokenList.get(tokenIndex).getType().equals(TokenType.MULT)
        || tokenList.get(tokenIndex).getType().equals(TokenType.DIV)
        || tokenList.get(tokenIndex).getType().equals(TokenType.MOD)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = unaryExp();
            connect(parent, child3);
        }
        return parent;
    }

    public BranchNode addExp() {
        BranchNode parent = new BranchNode(UnitType.ADDEXP);
        BranchNode child1 = mulExp();
        connect(parent, child1);
        while(tokenList.get(tokenIndex).getType().equals(TokenType.PLUS)
                || tokenList.get(tokenIndex).getType().equals(TokenType.MINU)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = mulExp();
            connect(parent, child3);
        }
        return parent;
    }

    public BranchNode relExp() {
        BranchNode parent = new BranchNode(UnitType.RELEXP);
        BranchNode child1 = addExp();
        connect(parent, child1);
        while(tokenList.get(tokenIndex).getType().equals(TokenType.LSS)
                || tokenList.get(tokenIndex).getType().equals(TokenType.LEQ)
                || tokenList.get(tokenIndex).getType().equals(TokenType.GRE)
                || tokenList.get(tokenIndex).getType().equals(TokenType.GEQ)){
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = addExp();
            connect(parent, child3);
        }
        return parent;
    }

    public BranchNode eqExp() {
        BranchNode parent = new BranchNode(UnitType.EQEXP);
        BranchNode child1 = relExp();
        connect(parent, child1);
        while(tokenList.get(tokenIndex).getType().equals(TokenType.EQL)
                || tokenList.get(tokenIndex).getType().equals(TokenType.NEQ)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = relExp();
            connect(parent, child3);
        }
        return parent;
    }

    public BranchNode lAndExp() {
        BranchNode parent = new BranchNode(UnitType.LANDEXP);
        BranchNode child1 = eqExp();
        connect(parent, child1);
        while(tokenList.get(tokenIndex).getType().equals(TokenType.AND)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = eqExp();
            connect(parent, child3);
        }
        return parent;
    }

    public BranchNode lOrExp() {
        BranchNode parent = new BranchNode(UnitType.LANDEXP);
        BranchNode child1 = lAndExp();
        connect(parent, child1);
        while(tokenList.get(tokenIndex).getType().equals(TokenType.OR)) {
            LeafNode child2 = createLeafNode();
            connect(parent, child2);
            BranchNode child3 = lAndExp();
            connect(parent, child3);
        }
        return parent;
    }

    public BranchNode constExp() {
        BranchNode parent = new BranchNode(UnitType.CONSTEXP);
        BranchNode child = addExp();
        connect(parent, child);
        return parent;
    }

    public void connect(BranchNode parent, Node child) {
        parent.addChild(child);
        child.setParent(parent);
    }

    public LeafNode createLeafNode() {
        LeafNode leafNode = new LeafNode(tokenList.get(tokenIndex));
        tokenIndex++;
        return leafNode;
    }
}
