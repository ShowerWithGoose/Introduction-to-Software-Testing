package frontend;

import frontend.syntaxTree.Node;
import frontend.type.GrammarType;
import frontend.type.LexType;

public class Parser {
    private int lineNum;
    private TokenList tokens;
    private ErrorList errors = ErrorList.getErrorList();

    public Parser(TokenList tokens) {
        this.tokens = tokens;
        this.lineNum = 1;
    }

    public boolean verifyTerminal(LexType type) {
        return tokens.getThis().getLexType() == type;
    }

    public boolean isExp() {
        return verifyTerminal(LexType.LPARENT) || verifyTerminal(LexType.IDENFR) || verifyTerminal(LexType.INTCON) ||
                verifyTerminal(LexType.CHRCON) || verifyTerminal(LexType.PLUS) || verifyTerminal(LexType.MINU) ||
                verifyTerminal(LexType.NOT);
    }

    public void handleTerminal(Node node, LexType correctType) {
        Token token = tokens.getThis();
        lineNum = token.getLineNum();
        Node termiNode = new Node(token);
        //System.out.println(termiNode.getToken().getLexType().toString());

        if (correctType != termiNode.getToken().getLexType()) {
            if (correctType == LexType.SEMICN) {
                errors.getErrors().add(new Error(tokens.getErrLine(), "i"));
                System.out.println(tokens.getErrLine()+" "+token.getTokenValue()+" i");
            } else if (correctType == LexType.RPARENT) {
                errors.getErrors().add(new Error(tokens.getErrLine(), "j"));
                System.out.println(tokens.getErrLine()+" "+token.getTokenValue()+" j");
            } else if (correctType == LexType.RBRACK) {
                errors.getErrors().add(new Error(tokens.getErrLine(), "k"));
                System.out.println(tokens.getErrLine()+" "+token.getTokenValue()+"k");
            }
            return;
        }
        tokens.goNext();
        node.add(termiNode);
    }

    public Node handleCompUnit() {
        Node node = new Node(GrammarType.COMPUNIT);
        while (true) {
            if (tokens.preview(1).getLexType() == LexType.MAINTK) {
                node.add(handleMainFuncDef());
                break;
            } else if (tokens.preview(2).getLexType() == LexType.LPARENT) {
                node.add(handleFuncDef());
            } else {
                node.add(handleDecl());
            }
        }
        return node;
    }

    public Node handleFuncDef() {
        Node node = new Node(GrammarType.FUNCDEF);
        node.add(handleFuncType());
        handleTerminal(node, LexType.IDENFR);
        handleTerminal(node, LexType.LPARENT);
        if (verifyTerminal(LexType.INTTK) || verifyTerminal(LexType.CHARTK)) {
            node.add(handleFuncFParams());
        }
        handleTerminal(node, LexType.RPARENT);
        node.add(handleBlock());
        return node;
    }

    public Node handleFuncType() {
        Node node = new Node(GrammarType.FUNCTYPE);
        LexType tmpType = tokens.getThis().getLexType();
        if (tmpType == LexType.VOIDTK) {
            handleTerminal(node, LexType.VOIDTK);
        } else if (tmpType == LexType.INTTK) {
            handleTerminal(node, LexType.INTTK);
        } else if (tmpType == LexType.CHARTK) {
            handleTerminal(node, LexType.CHARTK);
        }
        return node;
    }

    public Node handleFuncFParams() {
        Node node = new Node(GrammarType.FUNCFPARAMS);
        node.add(handleFuncFParam());
        while(verifyTerminal(LexType.COMMA)) {
            handleTerminal(node, LexType.COMMA);
            node.add(handleFuncFParam());
        }
        return node;
    }

    public Node handleFuncFParam() {
        Node node = new Node(GrammarType.FUNCFPARAM);
        node.add(handleBType());
        handleTerminal(node, LexType.IDENFR);
        if (verifyTerminal(LexType.LBRACK)) {
            handleTerminal(node, LexType.LBRACK);
            handleTerminal(node, LexType.RBRACK);
        }
        return node;
    }

    public Node handleBType() {
        Node node = new Node(GrammarType.BTYPE);
        if (verifyTerminal(LexType.INTTK)) {
            handleTerminal(node, LexType.INTTK);
        } else if (verifyTerminal(LexType.CHARTK)) {
            handleTerminal(node, LexType.CHARTK);
        }
        return node;
    }

    public Node handleBlock() {
        Node node = new Node(GrammarType.BLOCK);
        handleTerminal(node, LexType.LBRACE);
        //System.out.println(tokens.getThis().getLexType().toString());
        while(!verifyTerminal(LexType.RBRACE)) {
            node.add(handleBlockItem());
            //System.out.println("1111"+tokens.getThis().getLineNum());
        }
        handleTerminal(node, LexType.RBRACE);
        return node;
    }

    public Node handleBlockItem() {
        Node node = new Node(GrammarType.BLOCKITEM);
        if (verifyTerminal(LexType.CONSTTK) || verifyTerminal(LexType.INTTK) || verifyTerminal(LexType.CHARTK)) {
            node.add(handleDecl());
        } else {
            node.add(handleStmt());
        }
        return node;
    }

    public Node handleDecl() {
        Node node = new Node(GrammarType.DECL);
        if (verifyTerminal(LexType.CONSTTK)) {
            node.add(handleConstDecl());
        } else {
            node.add(handleVarDecl());
        }
        return node;
    }

    public Node handleConstDecl() {
        Node node = new Node(GrammarType.CONSTDECL);
        handleTerminal(node, LexType.CONSTTK);
        node.add(handleBType());
        node.add(handleConstDef());
        while(verifyTerminal(LexType.COMMA)) {
            handleTerminal(node, LexType.COMMA);
            node.add(handleConstDef());
        }
        handleTerminal(node, LexType.SEMICN);
        return node;
    }

    public Node handleConstDef() {
        Node node = new Node(GrammarType.CONSTDEF);
        handleTerminal(node, LexType.IDENFR);
        if (verifyTerminal(LexType.LBRACK)) {
            handleTerminal(node, LexType.LBRACK);
            node.add(handleConstExp());
            handleTerminal(node, LexType.RBRACK);
        }
        handleTerminal(node, LexType.ASSIGN);
        node. add(handleConstInitVal());
        return node;
    }

    public Node handleConstExp() {
        Node node = new Node(GrammarType.CONSTEXP);
        node.add(handleAddExp());
        return node;
    }

    public Node handleConstInitVal() {
        Node node = new Node(GrammarType.CONSTINITVAL);
        if (verifyTerminal(LexType.STRCON)) {
            handleTerminal(node, LexType.STRCON);
        } else if (verifyTerminal(LexType.LBRACE)) {
            handleTerminal(node, LexType.LBRACE);
            if (!verifyTerminal(LexType.RBRACE)) {
                node.add(handleConstExp());
                while(verifyTerminal(LexType.COMMA)) {
                    handleTerminal(node, LexType.COMMA);
                    node.add(handleConstExp());
                }
            }
            handleTerminal(node, LexType.RBRACE);
        } else {
            node.add(handleConstExp());
        }
        return node;
    }

    public Node handleVarDecl() {
        Node node = new Node(GrammarType.VARDECL);
        node.add(handleBType());
        node.add(handleVarDef());
        while(verifyTerminal(LexType.COMMA)) {
            handleTerminal(node, LexType.COMMA);
            node.add(handleVarDef());
        }
        handleTerminal(node, LexType.SEMICN);
        return node;
    }

    public Node handleVarDef() {
        Node node = new Node(GrammarType.VARDEF);
        handleTerminal(node, LexType.IDENFR);
        if (verifyTerminal(LexType.LBRACK)) {
            handleTerminal(node, LexType.LBRACK);
            node.add(handleConstExp());
            handleTerminal(node, LexType.RBRACK);
        }
        if (verifyTerminal(LexType.ASSIGN)) {
            handleTerminal(node, LexType.ASSIGN);
            node.add(handleInitVal());
        }
        return node;
    }

    public Node handleInitVal() {
        Node node = new Node(GrammarType.INITVAL);
        if (verifyTerminal(LexType.STRCON)) {
            handleTerminal(node, LexType.STRCON);
        } else if (verifyTerminal(LexType.LBRACE)) {
            handleTerminal(node, LexType.LBRACE);
            if (!verifyTerminal(LexType.RBRACE)) {
                node.add(handleExp());
                while(verifyTerminal(LexType.COMMA)){
                    handleTerminal(node, LexType.COMMA);
                    node.add(handleExp());
                }
            }
            handleTerminal(node, LexType.RBRACE);
        } else {
            node.add(handleExp());
        }
        return node;
    }

    public Node handleExp() {
        Node node = new Node(GrammarType.EXP);
        node.add(handleAddExp());
        return node;
    }

    public Node handleAddExp() {
        Node node = new Node(GrammarType.ADDEXP);
        node.add(handleMulExp());
        while(verifyTerminal(LexType.PLUS) || verifyTerminal(LexType.MINU)) {
            node.changeType(GrammarType.ADDEXP);
            if (verifyTerminal(LexType.PLUS)) {
                handleTerminal(node, LexType.PLUS);
            } else if (verifyTerminal(LexType.MINU)) {
                handleTerminal(node, LexType.MINU);
            }
            node.add(handleMulExp());
        }
        return node;
    }

    public Node handleMulExp() {
        Node node = new Node(GrammarType.MULEXP);
        node.add(handleUnaryExp());
        while(verifyTerminal(LexType.MULT) || verifyTerminal(LexType.DIV) || verifyTerminal(LexType.MOD)) {
            node.changeType(GrammarType.MULEXP);
            if (verifyTerminal(LexType.MULT)) {
                handleTerminal(node, LexType.MULT);
            } else if (verifyTerminal(LexType.DIV)) {
                handleTerminal(node, LexType.DIV);
            } else if (verifyTerminal(LexType.MOD)) {
                handleTerminal(node, LexType.MOD);
            }
            node.add(handleUnaryExp());
        }
        return node;
    }

    public Node handleUnaryExp() {
        Node node = new Node(GrammarType.UNARYEXP);
        if (verifyTerminal(LexType.IDENFR) && tokens.preview(1).getLexType() == LexType.LPARENT) {
            handleTerminal(node, LexType.IDENFR);
            handleTerminal(node, LexType.LPARENT);
            if (isExp()) {
                node.add(handleFuncRParams());
            }
            handleTerminal(node, LexType.RPARENT);
        } else if (verifyTerminal(LexType.PLUS) || verifyTerminal(LexType.MINU) || verifyTerminal(LexType.NOT)) {
            node.add(handleUnaryOp());
            node.add(handleUnaryExp());
        } else {
            node.add(handlePrimaryExp());
        }
        return node;
    }

    public Node handleFuncRParams() {
        Node node = new Node(GrammarType.FUNCRPARAMS);
        node.add(handleExp());
        while(verifyTerminal(LexType.COMMA)) {
            handleTerminal(node, LexType.COMMA);
            node.add(handleExp());
        }
        return node;
    }

    public Node handleUnaryOp() {
        Node node = new Node(GrammarType.UNARYOP);
        if(verifyTerminal(LexType.PLUS)) {
            handleTerminal(node, LexType.PLUS);
        } else if (verifyTerminal(LexType.MINU)) {
            handleTerminal(node, LexType.MINU);
        } else if (verifyTerminal(LexType.NOT)) {
            handleTerminal(node, LexType.NOT);
        }
        return node;
    }

    public Node handlePrimaryExp() {
        Node node = new Node(GrammarType.PRIMARYEXP);
        if (verifyTerminal(LexType.LPARENT)) {
            handleTerminal(node, LexType.LPARENT);
            node.add(handleExp());
            handleTerminal(node, LexType.RPARENT);
        } else if (verifyTerminal(LexType.INTCON)) {
            node.add(handleNumber());
        } else if (verifyTerminal(LexType.CHRCON)) {
            node.add(handleCharacter());
        } else {
            node.add(handleLVal());
        }
        return node;
    }

    public Node handleNumber() {
        Node node = new Node(GrammarType.NUMBER);
        handleTerminal(node, LexType.INTCON);
        return node;
    }

    public Node handleCharacter() {
        Node node = new Node(GrammarType.CHARACTER);
        handleTerminal(node, LexType.CHRCON);
        return node;
    }

    public Node handleLVal() {
        Node node = new Node(GrammarType.LVAL);
        handleTerminal(node, LexType.IDENFR);
        if (verifyTerminal(LexType.LBRACK)) {
            handleTerminal(node, LexType.LBRACK);
            node.add(handleExp());
            handleTerminal(node, LexType.RBRACK);
        }
        return node;
    }

    public Node handleStmt() {
        Node node = new Node(GrammarType.STMT);
        if (verifyTerminal(LexType.LBRACE)) {
            node.add(handleBlock());
        } else if (verifyTerminal(LexType.IFTK)) {
            handleTerminal(node, LexType.IFTK);
            handleTerminal(node, LexType.LPARENT);
            node.add(handleCond());
            handleTerminal(node, LexType.RPARENT);
            node.add(handleStmt());
            if (verifyTerminal(LexType.ELSETK)) {
                handleTerminal(node, LexType.ELSETK);
                node.add(handleStmt());
            }
        } else if (verifyTerminal(LexType.FORTK)) {
            handleTerminal(node, LexType.FORTK);
            handleTerminal(node, LexType.LPARENT);
            if (!verifyTerminal(LexType.SEMICN)) {
                node.add(handleForStmt());
            }
            handleTerminal(node, LexType.SEMICN);
            if (!verifyTerminal(LexType.SEMICN)) {
                node.add(handleCond());
            }
            handleTerminal(node, LexType.SEMICN);
            if (!verifyTerminal(LexType.RPARENT)) {
                node.add(handleForStmt());
            }
            handleTerminal(node, LexType.RPARENT);
            node.add(handleStmt());
        } else if (verifyTerminal(LexType.BREAKTK)) {
            handleTerminal(node, LexType.BREAKTK);
            handleTerminal(node, LexType.SEMICN);
        } else if (verifyTerminal(LexType.CONTINUETK)) {
            handleTerminal(node, LexType.CONTINUETK);
            handleTerminal(node, LexType.SEMICN);
        } else if (verifyTerminal(LexType.RETURNTK)) {
            handleTerminal(node, LexType.RETURNTK);
            if (isExp()) {
                node.add(handleExp());
            }
            handleTerminal(node, LexType.SEMICN);
        } else if (verifyTerminal(LexType.PRINTFTK)) {
            handleTerminal(node, LexType.PRINTFTK);
            handleTerminal(node, LexType.LPARENT);
            handleTerminal(node, LexType.STRCON);
            while(verifyTerminal(LexType.COMMA)) {
                handleTerminal(node, LexType.COMMA);
                node.add(handleExp());
            }
            handleTerminal(node, LexType.RPARENT);
            handleTerminal(node, LexType.SEMICN);
        } else if (isExp()) {
            int pos = tokens.mark();
            int errPos = errors.getErrors().size();
            Node tryNode = handleExp();
            if (verifyTerminal(LexType.SEMICN)) {
                node.add(tryNode);
                handleTerminal(node, LexType.SEMICN);
            } else {
                if (tokens.preview(1).getLexType() == LexType.GETINTTK) {
                    tokens.backtrack(pos);
                    if (errors.getErrors().size()>errPos) {
                        errors.getErrors().subList(errPos, errors.getErrors().size()).clear();
                    }
                    node.add(handleLVal());
                    handleTerminal(node, LexType.ASSIGN);
                    handleTerminal(node, LexType.GETINTTK);
                    handleTerminal(node, LexType.LPARENT);
                    handleTerminal(node, LexType.RPARENT);
                    handleTerminal(node, LexType.SEMICN);
                } else if (tokens.preview(1).getLexType() == LexType.GETCHARTK) {
                    tokens.backtrack(pos);
                    if (errors.getErrors().size()>errPos) {
                        errors.getErrors().subList(errPos, errors.getErrors().size()).clear();
                    }
                    node.add(handleLVal());
                    handleTerminal(node, LexType.ASSIGN);
                    handleTerminal(node, LexType.GETCHARTK);
                    handleTerminal(node, LexType.LPARENT);
                    handleTerminal(node, LexType.RPARENT);
                    handleTerminal(node, LexType.SEMICN);
                } else {
                    tokens.backtrack(pos);
                    if (errors.getErrors().size()>errPos) {
                        errors.getErrors().subList(errPos, errors.getErrors().size()).clear();
                    }
                    node.add(handleLVal());
                    handleTerminal(node, LexType.ASSIGN);
                    node.add(handleExp());
                    handleTerminal(node, LexType.SEMICN);
                }
            }
        } else {
            handleTerminal(node, LexType.SEMICN);
        }
        return node;
    }

    public Node handleCond() {
        Node node = new Node(GrammarType.COND);
        node.add(handleLOrExp());
        return node;
    }

    public Node handleLOrExp() {
        Node node = new Node(GrammarType.LOREXP);
        node.add(handleLAndExp());
        while(verifyTerminal(LexType.OR)) {
            node.changeType(GrammarType.LOREXP);
            handleTerminal(node, LexType.OR);
            node.add(handleLAndExp());
        }
        return node;
    }

    public Node handleLAndExp() {
        Node node = new Node(GrammarType.LANDEXP);
        node.add(handleLEqExp());
        //Caution!!!!!!
        //System.out.println(tokens.getThis().getTokenValue());
        while(verifyTerminal(LexType.AND)) {
            node.changeType(GrammarType.LANDEXP);
            handleTerminal(node, LexType.AND);
            node.add(handleLEqExp());
        }
        return node;
    }

    public Node handleLEqExp() {
        Node node = new Node(GrammarType.EQEXP);
        node.add(handleRelExp());
        while(verifyTerminal(LexType.EQL) || verifyTerminal(LexType.NEQ)) {
            node.changeType(GrammarType.EQEXP);
            if (verifyTerminal(LexType.EQL)) {
                handleTerminal(node, LexType.EQL);
            } else {
                handleTerminal(node, LexType.NEQ);
            }
            node.add(handleRelExp());
        }
        return node;
    }

    public Node handleRelExp() {
        Node node = new Node(GrammarType.RELEXP);
        node.add(handleAddExp());
        while(verifyTerminal(LexType.LSS) || verifyTerminal(LexType.GRE) || verifyTerminal(LexType.LEQ)
        || verifyTerminal(LexType.GEQ)) {
            node.changeType(GrammarType.RELEXP);
            if (verifyTerminal(LexType.LSS)) {
                handleTerminal(node, LexType.LSS);
            } else if (verifyTerminal(LexType.GRE)) {
                handleTerminal(node, LexType.GRE);
            } else if (verifyTerminal(LexType.LEQ)) {
                handleTerminal(node, LexType.LEQ);
            } else {
                handleTerminal(node, LexType.GEQ);
            }
            node.add(handleAddExp());
        }
        return node;
    }

    public Node handleForStmt() {
        Node node = new Node(GrammarType.FORSTMT);
        node.add(handleLVal());
        handleTerminal(node, LexType.ASSIGN);
        node.add(handleExp());
        return node;
    }

    public Node handleMainFuncDef() {
        Node node = new Node(GrammarType.MAINFUNCDEF);
        handleTerminal(node, LexType.INTTK);
        handleTerminal(node, LexType.MAINTK);
        handleTerminal(node, LexType.LPARENT);
        handleTerminal(node, LexType.RPARENT);
        //System.out.println(tokens.getThis().getLexType().toString());
        node.add(handleBlock());
        return node;
    }
}
