package frontend;
import java.util.List;
import java.util.ArrayList;

public class SyntaxAnalyzer {
    private List<Token> tokens;      // 存储词法分析结果
    private int currentTokenIndex;   // 当前分析的词法单元索引
    private List<Token> errors;      // 存储错误信息
    private TreeNode root;            // 语法树根节点

    public SyntaxAnalyzer(List<Token> tokens) {
        this.tokens = tokens;
        this.currentTokenIndex = 0;
        this.errors = new ArrayList<>();
        this.root = new TreeNode("<CompUnit>", false, new Token("", "", 0));  // 初始化语法树根节点
    }

    public TreeNode analyze() {
        CompUnit();  // 开始分析编译单元
        return root;  // 返回构建的语法树
    }

    private void CompUnit() {
        while (currentTokenIndex < tokens.size()) {
            if (tokens.get(currentTokenIndex).getType().equals("CONSTTK")) {
                root.addChild(Decl());
            } else if (tokens.get(currentTokenIndex).getType().equals("VOIDTK")) {
                root.addChild(FuncDef());
            } else {
                if (tokens.get(currentTokenIndex).getType().equals("INTTK")) {
                    if (tokens.get(currentTokenIndex + 1).getType().equals("MAINTK")) {
                        root.addChild(MainFuncDef());
                    } else if (tokens.get(currentTokenIndex + 1).getType().equals("IDENFR")){
                        if (tokens.get(currentTokenIndex + 2).getType().equals("LPARENT")) {
                            root.addChild(FuncDef());
                        } else {
                            root.addChild(Decl());
                        }
                        //不包含的错误/////////////////////////////////////
                    }
                    //不包含的错误/////////////////////////////////////
                } else if (tokens.get(currentTokenIndex).getType().equals("CHARTK")) {
                    if (tokens.get(currentTokenIndex + 1).getType().equals("IDENFR")){
                        if (tokens.get(currentTokenIndex + 2).getType().equals("LPARENT")) {
                            root.addChild(FuncDef());
                        } else{
                            root.addChild(Decl());
                        }
                        //不包含的错误/////////////////////////////////////
                    }
                    //不包含的错误/////////////////////////////////////
                }
                //不包含的错误/////////////////////////////////////
            }
        }
    }

    private TreeNode Decl() {
        TreeNode declNode = new TreeNode("<Decl>", false, new Token("", "", 0));
        if (tokens.get(currentTokenIndex).getType().equals("CONSTTK")) {
            declNode.addChild(ConstDecl());
        } else {
            declNode.addChild(VarDecl());
        }
        return declNode;
    }

    private TreeNode ConstDecl() {
        TreeNode constDeclNode = new TreeNode("<ConstDecl>", false, new Token("", "", 0));
        TreeNode constNode = new TreeNode("CONSTTK", true, tokens.get(currentTokenIndex));
        constDeclNode.addChild(constNode);
        currentTokenIndex++;
        constDeclNode.addChild(BType());
        constDeclNode.addChild(ConstDef());
        while (currentTokenIndex < tokens.size() && tokens.get(currentTokenIndex).getType().equals("COMMA")) {
            TreeNode commaNode = new TreeNode("COMMA", true, tokens.get(currentTokenIndex));
            constDeclNode.addChild(commaNode);
            currentTokenIndex++;
            constDeclNode.addChild(ConstDef());
        }
        if (tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
            TreeNode semicNode = new TreeNode("SEMICN", true, tokens.get(currentTokenIndex));
            constDeclNode.addChild(semicNode);
            currentTokenIndex++;
        } else {
            errors.add(new Token("i", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
        }
        return constDeclNode;
    }

    private TreeNode BType() {
        TreeNode bTypeNode = new TreeNode("<BType>", false, new Token("", "", 0));
        if (tokens.get(currentTokenIndex).getType().equals("INTTK") || tokens.get(currentTokenIndex).getType().equals("CHARTK")) {
            bTypeNode.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        }
        return bTypeNode;
    }

    private TreeNode ConstDef() {
        TreeNode constDefNode = new TreeNode("<ConstDef>", false, new Token("", "", 0));
        constDefNode.addChild(new TreeNode("IDENFR", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        if (tokens.get(currentTokenIndex).getType().equals("LBRACK")) {
            TreeNode lbrackNode = new TreeNode("LBRACK", true, tokens.get(currentTokenIndex));
            constDefNode.addChild(lbrackNode);
            currentTokenIndex++;
            constDefNode.addChild(ConstExp());
            if (tokens.get(currentTokenIndex).getType().equals("RBRACK")) {
                TreeNode rbrackNode = new TreeNode("RBRACK", true, tokens.get(currentTokenIndex));
                constDefNode.addChild(rbrackNode);
                currentTokenIndex++;
            } else {
                errors.add(new Token("k", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            }
        }
        constDefNode.addChild(new TreeNode("ASSIGN", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        constDefNode.addChild(ConstInitVal());
        return constDefNode;
    }

    private TreeNode ConstInitVal() {
        TreeNode constInitValNode = new TreeNode("<ConstInitVal>", false, new Token("", "", 0));
        if (tokens.get(currentTokenIndex).getType().equals("STRCON")) {
            constInitValNode.addChild(new TreeNode("STRCON", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        } else if (tokens.get(currentTokenIndex).getType().equals("LBRACE")) {
            constInitValNode.addChild(new TreeNode("LBRACE", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (!tokens.get(currentTokenIndex).getType().equals("RBRACE")) {
                constInitValNode.addChild(ConstExp());
                while (currentTokenIndex < tokens.size() && tokens.get(currentTokenIndex).getType().equals("COMMA")) {
                    constInitValNode.addChild(new TreeNode("COMMA", true, tokens.get(currentTokenIndex)));
                    currentTokenIndex++;
                    constInitValNode.addChild(ConstExp());
                }
            }
            constInitValNode.addChild(new TreeNode("RBRACE", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        } else {
            constInitValNode.addChild(ConstExp());
        }
        return constInitValNode;
    }

    private TreeNode VarDecl() {
        TreeNode varDeclNode = new TreeNode("<VarDecl>", false, new Token("", "", 0));
        varDeclNode.addChild(BType());
        varDeclNode.addChild(VarDef());
        while (currentTokenIndex < tokens.size() && tokens.get(currentTokenIndex).getType().equals("COMMA")) {
            varDeclNode.addChild(new TreeNode("COMMA", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            varDeclNode.addChild(VarDef());
        }
        if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
            errors.add(new Token("i", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
        } else {
            varDeclNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        }
        return varDeclNode;
    }

    private TreeNode VarDef() {
        TreeNode varDefNode = new TreeNode("<VarDef>" , false, new Token("", "", 0));
        varDefNode.addChild(new TreeNode("IDENFR", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        if (tokens.get(currentTokenIndex).getType().equals("LBRACK")) {
            varDefNode.addChild(new TreeNode("LBRACK", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;  // consume '['
            varDefNode.addChild(ConstExp());
            if (tokens.get(currentTokenIndex).getType().equals("RBRACK")) {
                varDefNode.addChild(new TreeNode("RBRACK", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            } else {
                errors.add(new Token("k", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            }
        }
        if (tokens.get(currentTokenIndex).getType().equals("ASSIGN")) {
            varDefNode.addChild(new TreeNode("ASSIGN", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            varDefNode.addChild(InitVal());
        }
        return varDefNode;
    }

    private TreeNode InitVal() {
        TreeNode initValNode = new TreeNode("<InitVal>", false, new Token("", "", 0));
        if (tokens.get(currentTokenIndex).getType().equals("STRCON")) {
            initValNode.addChild(new TreeNode("STRCON", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        } else if (tokens.get(currentTokenIndex).getType().equals("LBRACE")) {
            initValNode.addChild(new TreeNode("LBRACE", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (!tokens.get(currentTokenIndex).getType().equals("RBRACE")) {
                initValNode.addChild(Exp());
                while (currentTokenIndex < tokens.size() && tokens.get(currentTokenIndex).getType().equals("COMMA")) {
                    initValNode.addChild(new TreeNode("COMMA", true, tokens.get(currentTokenIndex)));
                    currentTokenIndex++;
                    initValNode.addChild(Exp());
                }
            }
            initValNode.addChild(new TreeNode("RBRACE", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        } else {
            initValNode.addChild(Exp());
        }
        return initValNode;
    }

    private TreeNode FuncDef() {
        TreeNode funcDefNode = new TreeNode("<FuncDef>", false, new Token("", "", 0));
        funcDefNode.addChild(FuncType());
        funcDefNode.addChild(new TreeNode("IDENFR", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        funcDefNode.addChild(new TreeNode("LPARENT", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
            if (tokens.get(currentTokenIndex).getType().equals("LBRACE")) {
                errors.add(new Token("j", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            } else {
                funcDefNode.addChild(FuncFParams());
                if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                    errors.add(new Token("j", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
                } else {
                    funcDefNode.addChild(new TreeNode("RPARENT", true, tokens.get(currentTokenIndex)));
                    currentTokenIndex++;
                }
            }
        } else {
            funcDefNode.addChild(new TreeNode("RPARENT", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        }
        funcDefNode.addChild(Block());
        return funcDefNode;
    }

    private TreeNode MainFuncDef() {
        TreeNode mainFuncNode = new TreeNode("<MainFuncDef>", false, new Token("", "", 0));
        mainFuncNode.addChild(new TreeNode("INTTK", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        mainFuncNode.addChild(new TreeNode("MAINTK", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        dealRp(mainFuncNode);
        mainFuncNode.addChild(Block());
        return mainFuncNode;
    }

    private TreeNode FuncType() {
        TreeNode funcTypeNode = new TreeNode("<FuncType>", false, new Token("", "", 0));
        funcTypeNode.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        return funcTypeNode;
    }

    private TreeNode FuncFParams() {
        TreeNode funcFParams = new TreeNode("<FuncFParams>", false, new Token("", "", 0));
        funcFParams.addChild(FuncFParam());
        while (tokens.get(currentTokenIndex).getType().equals("COMMA")) {
            funcFParams.addChild(new TreeNode("COMMA", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            funcFParams.addChild(FuncFParam());
        }
        return funcFParams;
    }

    private TreeNode FuncFParam() {
        TreeNode funcFParam = new TreeNode("<FuncFParam>", false, new Token("", "", 0));
        funcFParam.addChild(BType());
        funcFParam.addChild(new TreeNode("IDENFR", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        if (tokens.get(currentTokenIndex).getType().equals("LBRACK")) {
            funcFParam.addChild(new TreeNode("LBRACK", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (tokens.get(currentTokenIndex).getType().equals("RBRACK")) {
                funcFParam.addChild(new TreeNode("RBRACK", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            } else {
                errors.add(new Token("k", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            }
        }
        return funcFParam;
    }

    private TreeNode Block() {
        TreeNode blockNode = new TreeNode("<Block>", false, new Token("", "", 0));
        blockNode.children.add(new TreeNode("LBRACE", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        while (!tokens.get(currentTokenIndex).getType().equals("RBRACE")) {
            blockNode.addChild(BlockItem());
        }
        blockNode.addChild(new TreeNode("RBRACE", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        return blockNode;
    }

    private TreeNode BlockItem() {
        TreeNode blockItemNode = new TreeNode("<BlockItem>", false, new Token("", "", 0));
        if (tokens.get(currentTokenIndex).getType().equals("CONSTTK") ||
                tokens.get(currentTokenIndex).getType().equals("INTTK") ||
                tokens.get(currentTokenIndex).getType().equals("CHARTK")) {
            blockItemNode.addChild(Decl());
        } else {
            blockItemNode.addChild(Stmt());
        }
        return blockItemNode;
    }

    private TreeNode Stmt() {
        TreeNode stmtNode = new TreeNode("<Stmt>", false, new Token("", "", 0));
        if (tokens.get(currentTokenIndex).getType().equals("LBRACE")) {
            stmtNode.addChild(Block());
        } else if (tokens.get(currentTokenIndex).getType().equals("IFTK")) {
            stmtNode.addChild(new TreeNode("IFTK", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            stmtNode.addChild(new TreeNode("LPARENT", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            stmtNode.addChild(Cond());
            if (tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                stmtNode.addChild(new TreeNode("RPARENT", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            } else {
                errors.add(new Token("j", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            }
            stmtNode.addChild(Stmt());
            if (tokens.get(currentTokenIndex).getType().equals("ELSETK")) {
                stmtNode.addChild(new TreeNode("ELSETK", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
                stmtNode.addChild(Stmt());
            }
        } else if (tokens.get(currentTokenIndex).getType().equals("FORTK")) {
            stmtNode.addChild(new TreeNode("FORTK", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            stmtNode.addChild(new TreeNode("LPARENT", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                stmtNode.addChild(ForStmt());
            }
            stmtNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                stmtNode.addChild(Cond());
            }
            stmtNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                stmtNode.addChild(ForStmt());
            }
            stmtNode.addChild(new TreeNode("RPARENT", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            stmtNode.addChild(Stmt());
        } else if (tokens.get(currentTokenIndex).getType().equals("BREAKTK") ||
                tokens.get(currentTokenIndex).getType().equals("CONTINUETK")) {
            stmtNode.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                errors.add(new Token("i", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            } else {
                stmtNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            }
        } else if (tokens.get(currentTokenIndex).getType().equals("RETURNTK")) {
            stmtNode.addChild(new TreeNode("RETURNTK", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                if (tokens.get(currentTokenIndex).getType().equals("PLUS") || tokens.get(currentTokenIndex).getType().equals("MINU") ||
                        tokens.get(currentTokenIndex).getType().equals("NOT") || tokens.get(currentTokenIndex).getType().equals("LPARENT") ||
                        tokens.get(currentTokenIndex).getType().equals("IDENFR") || tokens.get(currentTokenIndex).getType().equals("INTCON") ||
                        tokens.get(currentTokenIndex).getType().equals("CHRCON")) {
                    stmtNode.addChild(Exp());
                    if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                        errors.add(new Token("i", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
                    } else {
                        stmtNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
                        currentTokenIndex++;
                    }
                } else {
                    errors.add(new Token("i", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
                }
            } else {
                stmtNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            }
        } else if (tokens.get(currentTokenIndex).getType().equals("PRINTFTK")) {
            stmtNode.addChild(new TreeNode("PRINTFTK", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            stmtNode.addChild(new TreeNode("LPARENT", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            stmtNode.addChild(new TreeNode("STRCON", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            while (tokens.get(currentTokenIndex).getType().equals("COMMA")) {
                stmtNode.addChild(new TreeNode("COMMA", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
                stmtNode.addChild(Exp());
            }
            if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                errors.add(new Token("j", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            } else {
                stmtNode.addChild(new TreeNode("RPARENT", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            }
            if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                errors.add(new Token("i", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            } else {
                stmtNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            }
        } else if (tokens.get(currentTokenIndex).getType().equals("IDENFR")) {
            int currentTokenIndex1 = currentTokenIndex;
            TreeNode lvalNode = LVal();
            if (tokens.get(currentTokenIndex).getType().equals("ASSIGN")) {
                stmtNode.addChild(lvalNode);
                stmtNode.addChild(new TreeNode("ASSIGN", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
                if (tokens.get(currentTokenIndex).getType().equals("GETINTTK") ||
                        tokens.get(currentTokenIndex).getType().equals("GETCHARTK")){
                    stmtNode.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
                    currentTokenIndex++;
                    dealRp(stmtNode);
                } else {
                    stmtNode.addChild(Exp());
                }
                if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
                    errors.add(new Token("i", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
                } else {
                    stmtNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
                    currentTokenIndex++;
                }
            } else {
                currentTokenIndex = currentTokenIndex1;
                dealExp(stmtNode);
            }
        } else {
            dealExp(stmtNode);
        }
        return stmtNode;
    }

    private void dealExp(TreeNode stmtNode) {
        if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
            stmtNode.addChild(Exp());
        }
        if (!tokens.get(currentTokenIndex).getType().equals("SEMICN")) {
            errors.add(new Token("i", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
        } else {
            stmtNode.addChild(new TreeNode("SEMICN", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        }
    }

    private void dealRp(TreeNode stmtNode) {
        stmtNode.addChild(new TreeNode("LPARENT", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
            errors.add(new Token("j", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
        } else {
            stmtNode.addChild(new TreeNode("RPARENT", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
        }
    }

    private TreeNode ForStmt() {
        TreeNode forStmtNode = new TreeNode("<ForStmt>", false, new Token("", "", 0));
        forStmtNode.addChild(LVal());
        forStmtNode.addChild(new TreeNode("ASSIGN", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        forStmtNode.addChild(Exp());
        return forStmtNode;
    }

    private TreeNode Exp() {
        TreeNode expNode = new TreeNode("<Exp>", false, new Token("", "", 0));
        expNode.addChild(AddExp());
        return expNode;
    }

    private TreeNode Cond() {
        TreeNode condNode = new TreeNode("<Cond>", false, new Token("", "", 0));
        condNode.addChild(LOrExp());
        return condNode;
    }

    private TreeNode LVal() {
        TreeNode lValNode = new TreeNode("<LVal>", false, new Token("", "", 0));
        lValNode.addChild(new TreeNode("IDENFR", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        if (tokens.get(currentTokenIndex).getType().equals("LBRACK")) {
            lValNode.addChild(new TreeNode("LBRACK", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            lValNode.addChild(Exp());
            if (tokens.get(currentTokenIndex).getType().equals("RBRACK")) {
                lValNode.addChild(new TreeNode("RBRACK", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            } else {
                errors.add(new Token("k", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            }
        }
        return lValNode;
    }

    private TreeNode PrimaryExp() {
        TreeNode primaryExpNode = new TreeNode("<PrimaryExp>", false, new Token("", "", 0));
        if (tokens.get(currentTokenIndex).getType().equals("LPARENT")) {
            primaryExpNode.addChild(new TreeNode("LPARENT", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            primaryExpNode.addChild(Exp());
            if (tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                primaryExpNode.addChild(new TreeNode("RPARENT", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            } else {
                errors.add(new Token("j", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            }
        } else if (tokens.get(currentTokenIndex).getType().equals("IDENFR")) {
            primaryExpNode.addChild(LVal());
        } else if (tokens.get(currentTokenIndex).getType().equals("INTCON")) {
            primaryExpNode.addChild(Number());
        } else {
            primaryExpNode.addChild(Character());
        }
        return primaryExpNode;
    }

    private TreeNode Number() {
        TreeNode numberNode = new TreeNode("<Number>", false, new Token("", "", 0));
        numberNode.addChild(new TreeNode("INTCON", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        return numberNode;
    }

    private TreeNode Character() {
        TreeNode characterNode = new TreeNode("<Character>", false, new Token("", "", 0));
        characterNode.addChild(new TreeNode("CHRCON", true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        return characterNode;
    }

    private TreeNode UnaryExp() {
        TreeNode unaryExpNode = new TreeNode("<UnaryExp>", false, new Token("", "", 0));
        if (tokens.get(currentTokenIndex).getType().equals("PLUS") ||
                tokens.get(currentTokenIndex).getType().equals("MINU") ||
                tokens.get(currentTokenIndex).getType().equals("NOT")){
            unaryExpNode.addChild(UnaryOp());
            unaryExpNode.addChild(UnaryExp());
        } else if (tokens.get(currentTokenIndex).getType().equals("IDENFR") &&
                tokens.get(currentTokenIndex + 1).getType().equals("LPARENT")) {
            unaryExpNode.addChild(new TreeNode("IDENFR", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            unaryExpNode.addChild(new TreeNode("LPARENT", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                if (tokens.get(currentTokenIndex).getType().equals("PLUS") || tokens.get(currentTokenIndex).getType().equals("MINU") ||
                        tokens.get(currentTokenIndex).getType().equals("NOT") || tokens.get(currentTokenIndex).getType().equals("LPARENT") ||
                        tokens.get(currentTokenIndex).getType().equals("IDENFR") || tokens.get(currentTokenIndex).getType().equals("INTCON") ||
                        tokens.get(currentTokenIndex).getType().equals("CHRCON")) {
                    unaryExpNode.addChild(FuncRParams());
                } else {
                    errors.add(new Token("j", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
                }
            }
            if (!tokens.get(currentTokenIndex).getType().equals("RPARENT")) {
                errors.add(new Token("j", " ", tokens.get(currentTokenIndex - 1).getLineNum()));
            } else {
                unaryExpNode.addChild(new TreeNode("RPARENT", true, tokens.get(currentTokenIndex)));
                currentTokenIndex++;
            }
        } else {
            unaryExpNode.addChild(PrimaryExp());
        }
        return unaryExpNode;
    }

    private TreeNode UnaryOp() {
        TreeNode opNode = new TreeNode("<UnaryOp>", false, new Token("", "", 0));
        opNode.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
        currentTokenIndex++;
        return opNode;
    }

    private TreeNode FuncRParams() {
        TreeNode funcRParamsNode = new TreeNode("<FuncRParams>", false, new Token("", "", 0));
        funcRParamsNode.addChild(Exp());
        while (tokens.get(currentTokenIndex).getType().equals("COMMA")) {
            funcRParamsNode.addChild(new TreeNode("COMMA", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            funcRParamsNode.addChild(Exp());
        }
        return funcRParamsNode;
    }

    private TreeNode MulExp() {
        TreeNode multiExpNode = new TreeNode("<MulExp>", false, new Token("", "", 0));
        multiExpNode.addChild(UnaryExp());
        while (tokens.get(currentTokenIndex).getType().equals("MULT") ||
                tokens.get(currentTokenIndex).getType().equals("DIV") ||
                tokens.get(currentTokenIndex).getType().equals("MOD")){
            TreeNode mulExpNode2 = new TreeNode("<MulExp>", false, new Token("", "", 0));
            mulExpNode2.addChild(multiExpNode);
            mulExpNode2.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            mulExpNode2.addChild(UnaryExp());
            multiExpNode = mulExpNode2;
        }
        return multiExpNode;
    }

    private TreeNode AddExp() {
        TreeNode addExpNode = new TreeNode("<AddExp>", false, new Token("", "", 0));
        addExpNode.addChild(MulExp());
        while (tokens.get(currentTokenIndex).getType().equals("PLUS") ||
                tokens.get(currentTokenIndex).getType().equals("MINU")){
            TreeNode addExpNode2 = new TreeNode("<AddExp>", false, new Token("", "", 0));
            addExpNode2.addChild(addExpNode);
            addExpNode2.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            addExpNode2.addChild(MulExp());
            addExpNode = addExpNode2;
        }
        return addExpNode;
    }

    private TreeNode RelExp() {
        TreeNode relExpNode = new TreeNode("<RelExp>", false, new Token("", "", 0));
        relExpNode.addChild(AddExp());
        while (tokens.get(currentTokenIndex).getType().equals("LSS") ||
                tokens.get(currentTokenIndex).getType().equals("GRE") ||
                tokens.get(currentTokenIndex).getType().equals("GEQ") ||
                tokens.get(currentTokenIndex).getType().equals("LEQ")){
            TreeNode relExpNode2 = new TreeNode("<RelExp>", false, new Token("", "", 0));
            relExpNode2.addChild(relExpNode);
            relExpNode2.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            relExpNode2.addChild(AddExp());
            relExpNode = relExpNode2;
        }
        return relExpNode;
    }

    private TreeNode EqExp() {
        TreeNode eqExpNode = new TreeNode("<EqExp>", false, new Token("", "", 0));
        eqExpNode.addChild(RelExp());
        while (tokens.get(currentTokenIndex).getType().equals("EQL") ||
                tokens.get(currentTokenIndex).getType().equals("NEQ")){
            TreeNode eqExpNode2 = new TreeNode("<EqExp>", false, new Token("", "", 0));
            eqExpNode2.addChild(eqExpNode);
            eqExpNode2.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            eqExpNode2.addChild(RelExp());
            eqExpNode = eqExpNode2;
        }
        return eqExpNode;
    }

    private TreeNode LAndExp() {
        TreeNode andExpNode = new TreeNode("<LAndExp>", false, new Token("", "", 0));
        andExpNode.addChild(EqExp());
        while (tokens.get(currentTokenIndex).getType().equals("AND") ||
                tokens.get(currentTokenIndex).getType().equals("errorA1")){
            if (!tokens.get(currentTokenIndex).getType().equals("AND")) {
                errors.add(new Token("a", " ", tokens.get(currentTokenIndex).getLineNum()));
            }
            TreeNode andExpNode2 = new TreeNode("<LAndExp>", false, new Token("", "", 0));
            andExpNode2.addChild(andExpNode);
            andExpNode2.addChild(new TreeNode("AND", true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            andExpNode2.addChild(EqExp());
            andExpNode = andExpNode2;
        }
        return andExpNode;
    }

    private TreeNode LOrExp() {
        TreeNode orExpNode = new TreeNode("<LOrExp>", false, new Token("", "", 0));
        orExpNode.addChild(LAndExp());
        while (tokens.get(currentTokenIndex).getType().equals("OR") ||
                tokens.get(currentTokenIndex).getType().equals("errorA2")){
            if (!tokens.get(currentTokenIndex).getType().equals("OR")) {
                errors.add(new Token("a", " ", tokens.get(currentTokenIndex).getLineNum()));
            }
            TreeNode orExpNode2 = new TreeNode("<LOrExp>", false, new Token("", "", 0));
            orExpNode2.addChild(orExpNode);
            orExpNode2.addChild(new TreeNode(tokens.get(currentTokenIndex).getType(), true, tokens.get(currentTokenIndex)));
            currentTokenIndex++;
            orExpNode2.addChild(LAndExp());
            orExpNode = orExpNode2;
        }
        return orExpNode;
    }

    private TreeNode ConstExp() {
        TreeNode constExpNode = new TreeNode("<ConstExp>", false, new Token("", "", 0));
        constExpNode.addChild(AddExp());
        return constExpNode;
    }

    public List<Token> getErrors() {
        return errors;
    }

}