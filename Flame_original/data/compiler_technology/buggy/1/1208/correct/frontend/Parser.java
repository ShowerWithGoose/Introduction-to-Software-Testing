package frontend;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.file.Files;
import java.util.*;

public class Parser {
    private final List<Token> tokens;
    private int curPos = 0;
    private Token curToken;
    private final int length;
    private final Node root;
    private final TreeMap<Integer, Character> errors;

    public Parser(List<Token> tokens, TreeMap<Integer, Character> errors) {
        this.tokens = tokens;
        this.length = tokens.size();
        this.errors = errors;
        this.root = parseCompUnit();
    }

    public Token look(int num) {
        if (curPos + num >= length) {
            return null;
        }
        return tokens.get(curPos + num);
    }

    public void next() {
        if (curPos >= length) {
            curToken = null;
        } else {
            curToken = tokens.get(curPos++);
        }
    }

    public Node parseCompUnit() {
        next();
        Node compUnit = new Node(SyntaxType.CompUnit, curToken);
        while (true) {
            if (curToken == null) {
                break;
            } else if (curToken.getType() == LexType.CONSTTK) {
                compUnit.addChildNode(parseConstDecl());
            } else if (curToken.getType() == LexType.VOIDTK) {
                compUnit.addChildNode(parseFuncDef());
            } else if (curToken.getType() == LexType.INTTK) {
                if (look(0).getType() == LexType.MAINTK) {
                    compUnit.addChildNode(parseMainFuncDef());
                } else if (look(1).getType() == LexType.LPARENT) {
                    compUnit.addChildNode(parseFuncDef());
                } else {
                    compUnit.addChildNode(parseVarDecl());
                }
            } else if (curToken.getType() == LexType.CHARTK) {
                if (look(1).getType() == LexType.LPARENT) {
                    compUnit.addChildNode(parseFuncDef());
                } else {
                    compUnit.addChildNode(parseVarDecl());
                }
            } else {
                break;
            }
        }
        return compUnit;
    }

    public Node parseConstDecl() {
        Node constDecl = new Node(SyntaxType.ConstDecl, curToken);
        constDecl.addChildNode(createEndNode());
        constDecl.addChildNode(parseBType());
        constDecl.addChildNode(parseConstDef());
        while (curToken.getType() == LexType.COMMA) {
            constDecl.addChildNode(createEndNode());
            constDecl.addChildNode(parseConstDef());
        }
        // ensure ;
        if (curToken.getType() == LexType.SEMICN) {
            constDecl.addChildNode(createEndNode());
        } else {
            errors.put(look(-2).getLineno(), 'i');
            // error;
        }
        return constDecl;
    }

    public Node parseBType() {
        Node btype = new Node(SyntaxType.BType, curToken);
        btype.addChildNode(createEndNode());
        return btype;
    }

    // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public Node parseConstDef() {
        Node constDef = new Node(SyntaxType.ConstDef, curToken);
        constDef.addChildNode(createEndNode()); // ident
        if (curToken.getType() == LexType.LBRACK) {
            constDef.addChildNode(createEndNode()); // '['
            constDef.addChildNode(parseConstExp());
            if (curToken.getType() == LexType.RBRACK) {
                constDef.addChildNode(createEndNode()); // ']'
            } else {
                errors.put(look(-2).getLineno(), 'k');
            }
        }
        constDef.addChildNode(createEndNode()); // '='
        constDef.addChildNode(parseConstInitVal());
        return constDef;
    }

    public Node parseConstExp() {
        Node constExp = new Node(SyntaxType.ConstExp, curToken);
        constExp.addChildNode(parseAddExp());
        return constExp;
    }

    public Node parseConstInitVal() {
        Node constInitVal = new Node(SyntaxType.ConstInitVal, curToken);
        if (curToken.getType() == LexType.LBRACE) {
            constInitVal.addChildNode(createEndNode());
            if (curToken.getType() != LexType.RBRACE) {
                constInitVal.addChildNode(parseConstExp());
                while (curToken.getType() == LexType.COMMA) {
                    constInitVal.addChildNode(createEndNode());
                    constInitVal.addChildNode(parseConstExp());
                }
            }
            constInitVal.addChildNode(createEndNode());
        } else if (curToken.getType() == LexType.STRCON) {
            constInitVal.addChildNode(createEndNode());
        } else {
            constInitVal.addChildNode(parseConstExp());
        }
        return constInitVal;
    }

    public Node parseVarDecl() {
        Node varDecl = new Node(SyntaxType.VarDecl, curToken);
        varDecl.addChildNode(parseBType());
        varDecl.addChildNode(parseVarDef());
        while (curToken.getType() == LexType.COMMA) {
            varDecl.addChildNode(createEndNode());
            varDecl.addChildNode(parseVarDef());
        }
        // ensure ;
        if (curToken.getType() == LexType.SEMICN) {
            varDecl.addChildNode(createEndNode());
        } else {
            errors.put(look(-2).getLineno(), 'i');
            // error;
        }
        return varDecl;
    }

    // VarDef → Ident [ '[' ConstExp ']' ] |
    //          Ident [ '[' ConstExp ']' ] '=' InitVal
    public Node parseVarDef() {
        Node varDef = new Node(SyntaxType.VarDef, curToken);
        varDef.addChildNode(createEndNode());// ident
        if (curToken.getType() == LexType.LBRACK) {
            varDef.addChildNode(createEndNode());// '['
            varDef.addChildNode(parseConstExp());// constExp
            if (curToken.getType() == LexType.RBRACK) {
                varDef.addChildNode(createEndNode());// ']'
            } else {
                errors.put(look(-2).getLineno(), 'k');
            }
        }
        if (curToken.getType() == LexType.ASSIGN) {
            varDef.addChildNode(createEndNode());
            varDef.addChildNode(parseInitVal());
        }
        return varDef;
    }

    public Node parseInitVal() {
        Node initVal = new Node(SyntaxType.InitVal, curToken);
        if (curToken.getType() == LexType.LBRACE) {
            initVal.addChildNode(createEndNode());
            if (curToken.getType() != LexType.RBRACE) {
                initVal.addChildNode(parseExp());
                while (curToken.getType() == LexType.COMMA) {
                    initVal.addChildNode(createEndNode());
                    initVal.addChildNode(parseExp());
                }
            }
            initVal.addChildNode(createEndNode());
        } else if (curToken.getType() == LexType.STRCON) {
            initVal.addChildNode(createEndNode());
        } else {
            initVal.addChildNode(parseExp());
        }
        return initVal;
    }

    public Node parseFuncDef() {
        Node funcDef = new Node(SyntaxType.FuncDef, curToken);
        funcDef.addChildNode(parseFuncType());
        funcDef.addChildNode(createEndNode()); // ident
        funcDef.addChildNode(createEndNode()); // '('
        if (curToken.getType() != LexType.RPARENT && curToken.getType() != LexType.LBRACE) {
            funcDef.addChildNode(parseFuncFParams());
        }
        if (curToken.getType() == LexType.RPARENT) {
            funcDef.addChildNode(createEndNode()); // ')'
        } else {
           errors.put(look(-2).getLineno(), 'j');
        }
        funcDef.addChildNode(parseBlock());
        return funcDef;
    }

    public Node parseFuncType() {
        Node funcType = new Node(SyntaxType.FuncType, curToken);
        funcType.addChildNode(createEndNode());
        return funcType;
    }

    public Node parseFuncFParams() {
        Node funcParams = new Node(SyntaxType.FuncFParams, curToken);
        funcParams.addChildNode(parseFuncFParam());
        while (curToken.getType() == LexType.COMMA) {
            funcParams.addChildNode(createEndNode());
            funcParams.addChildNode(parseFuncFParam());
        }
        return funcParams;
    }

    public Node parseFuncFParam() {
        Node funcFParam = new Node(SyntaxType.FuncFParam, curToken);
        funcFParam.addChildNode(parseBType());
        funcFParam.addChildNode(createEndNode()); // ident
        if (curToken.getType() == LexType.LBRACK) {
            funcFParam.addChildNode(createEndNode()); //'['
            if (curToken.getType() == LexType.RBRACK) {
                funcFParam.addChildNode(createEndNode()); //']'
            } else {
               errors.put(look(-2).getLineno(), 'k');
            }
        }
        return funcFParam;
    }

    public Node parseBlock() {
        Node block = new Node(SyntaxType.Block, curToken);
        block.addChildNode(createEndNode()); // '{'
        while (curToken != null && curToken.getType() != LexType.RBRACE) {
            block.addChildNode(parseBlockItem());
        }
        block.addChildNode(createEndNode()); // '}'
        return block;
    }

    public Node parseBlockItem() {
        Node blockItem = new Node(SyntaxType.BlockItem, curToken);
        if (curToken.getType() == LexType.CONSTTK) {
            blockItem.addChildNode(parseConstDecl());
        } else if (curToken.getType() == LexType.INTTK || curToken.getType() == LexType.CHARTK) {
            blockItem.addChildNode(parseVarDecl());
        } else {
            blockItem.addChildNode(parseStmt());
        }
        return blockItem;
    }

    public Node parseMainFuncDef() {
        Node mainFuncDef = new Node(SyntaxType.MainFuncDef, curToken);
        mainFuncDef.addChildNode(createEndNode());
        mainFuncDef.addChildNode(createEndNode());
        mainFuncDef.addChildNode(createEndNode()); // '('
        if (curToken.getType() == LexType.RPARENT) {
            mainFuncDef.addChildNode(createEndNode()); // ')'
        } else {
            errors.put(look(-2).getLineno(), 'j');
        }
        mainFuncDef.addChildNode(parseBlock());
        return mainFuncDef;
    }

    public Node parseAddExp() {
        Node addExp = new Node(SyntaxType.AddExp, curToken);
        Node left = parseMulExp();
        addExp.addChildNode(left);

        while (curToken.getType() == LexType.PLUS || curToken.getType() == LexType.MINU) {
            Node operator = new Node(SyntaxType.AddExp, addExp.getToken());
            Node op = createEndNode();
            Node right = parseMulExp();

            operator.addChildNode(addExp);
            operator.addChildNode(op);
            operator.addChildNode(right);

            addExp = operator;
        }
        return addExp;
    }

    public Node parseMulExp() {
        Node mulExp = new Node(SyntaxType.MulExp, curToken);
        Node left = parseUnaryExp();
        mulExp.addChildNode(left);

        while (curToken.getType() == LexType.MULT || curToken.getType() == LexType.DIV ||
        curToken.getType() == LexType.MOD) {
            Node operator = new Node(SyntaxType.MulExp, mulExp.getToken());
            Node op = createEndNode();
            Node right = parseUnaryExp();

            operator.addChildNode(mulExp);
            operator.addChildNode(op);
            operator.addChildNode(right);

            mulExp = operator;
        }
        return mulExp;
    }

    public Node parseUnaryExp() {
        Node unaryExp = new Node(SyntaxType.UnaryExp, curToken);
        if (curToken.getType() == LexType.LPARENT) {
            unaryExp.addChildNode(parsePExp());
        } else if (curToken.getType() == LexType.INTCON) {
            unaryExp.addChildNode(parseNumber());
        } else if (curToken.getType() == LexType.CHRCON) {
            unaryExp.addChildNode(parseCharacter());
        } else if (curToken.getType() == LexType.IDENFR) {
            if (look(0).getType() == LexType.LPARENT) {
                unaryExp.addChildNode(createEndNode()); // ident
                unaryExp.addChildNode(createEndNode()); // '('
                if (curToken.getType() != LexType.RPARENT) {
                    unaryExp.addChildNode(parseFuncRParams());
                }
                if (curToken.getType() == LexType.RPARENT) {
                    unaryExp.addChildNode(createEndNode()); // ')'
                } else {
                    errors.put(look(-2).getLineno(), 'j');
                }
            } else {
                unaryExp.addChildNode(parseLVal("Primary"));
            }
        } else if (curToken.getType() == LexType.PLUS || curToken.getType() == LexType.MINU ||
        curToken.getType() == LexType.NOT) {
            unaryExp.addChildNode(parseUnaryOp());
            unaryExp.addChildNode(parseUnaryExp());
        } else {
            // error
        }
        return unaryExp;
    }

    public Node parsePExp() {
        Node pExp = new Node(SyntaxType.PExp, curToken);
        pExp.addChildNode(createEndNode()); // '('
        pExp.addChildNode(parseExp());
        if (curToken.getType() == LexType.RPARENT) {
            pExp.addChildNode(createEndNode()); // ')'
        } else {
            errors.put(look(-2).getLineno(), 'j');
        }
        return pExp;
    }

    public Node parseLVal(String form) {
        Node lVal = (form.equals("Primary"))? new Node(SyntaxType.PLVal, curToken) :
                new Node(SyntaxType.LVal, curToken);
        lVal.addChildNode(createEndNode()); // ident
        if (curToken.getType() == LexType.LBRACK) {
            lVal.addChildNode(createEndNode()); // '['
            lVal.addChildNode(parseExp());
            if (curToken.getType() == LexType.RBRACK) {
                lVal.addChildNode(createEndNode()); // ']'
            } else {
                errors.put(look(-2).getLineno(), 'k');
            }
        }
        return lVal;
    }

    public Node parseNumber() {
        Node number = new Node(SyntaxType.Number, curToken);
        number.addChildNode(createEndNode());
        return number;
    }

    public Node parseCharacter() {
        Node character = new Node(SyntaxType.Character, curToken);
        character.addChildNode(createEndNode());
        return character;
    }

    public Node parseFuncRParams() {
        Node funcRParams = new Node(SyntaxType.FuncRParams, curToken);
        funcRParams.addChildNode(parseExp());
        while (curToken.getType() == LexType.COMMA) {
            funcRParams.addChildNode(createEndNode());
            funcRParams.addChildNode(parseExp());
        }
        return funcRParams;
    }

    public Node parseUnaryOp() {
        Node unaryOp = new Node(SyntaxType.UnaryOp, curToken);
        unaryOp.addChildNode(createEndNode());
        return unaryOp;
    }

    public Node parseExp() {
        Node exp = new Node(SyntaxType.Exp, curToken);
        exp.addChildNode(parseAddExp());
        return exp;
    }

    public Node parseStmt() {
        Node stmt = new Node(SyntaxType.Stmt, curToken);
        if (curToken.getType() == LexType.IFTK) {
            stmt.addChildNode(createEndNode()); // if
            stmt.addChildNode(createEndNode()); // '('
            stmt.addChildNode(parseCond());
            if (curToken.getType() == LexType.RPARENT) {
                stmt.addChildNode(createEndNode()); // ')'
            } else {
               errors.put(look(-2).getLineno(), 'j');
            }
            stmt.addChildNode(parseStmt());
            if (curToken.getType() == LexType.ELSETK) {
                stmt.addChildNode(createEndNode());
                stmt.addChildNode(parseStmt());
            }
            return stmt;
        }
        else if (curToken.getType() == LexType.FORTK) {
            stmt.addChildNode(createEndNode());
            stmt.addChildNode(createEndNode()); // '('
            if (curToken.getType() != LexType.SEMICN) {
                stmt.addChildNode(parseForStmt());
            }
            stmt.addChildNode(createEndNode()); // ';'
            if (curToken.getType() != LexType.SEMICN) {
                stmt.addChildNode(parseCond());
            }
            stmt.addChildNode(createEndNode()); // ';'
            if (curToken.getType() != LexType.RPARENT) {
                stmt.addChildNode(parseForStmt());
            }
            stmt.addChildNode(createEndNode()); // ')'
            stmt.addChildNode(parseStmt());
            return stmt;
        }
        else if (curToken.getType() == LexType.LBRACE) {
            stmt.addChildNode(parseBlock());
            return stmt;
        }
        else if (curToken.getType() == LexType.SEMICN) {
            stmt.addChildNode(createEndNode());
            return stmt;
        }

        else if (curToken.getType() == LexType.BREAKTK) {
            stmt.addChildNode(createEndNode());
            if (curToken.getType() == LexType.SEMICN) {
                stmt.addChildNode(createEndNode()); // ';'
            } else {
                errors.put(look(-2).getLineno(), 'i');
            }
        }
        else if (curToken.getType() == LexType.RETURNTK) {
            stmt.addChildNode(createEndNode());
            if (curToken.getType() != LexType.SEMICN) { // 这里的判断条件存疑
                stmt.addChildNode(parseExp());
            }
            if (curToken.getType() == LexType.SEMICN) {
                stmt.addChildNode(createEndNode()); // ';'
            } else {
                errors.put(look(-2).getLineno(), 'i');
            }
        }
        else if (curToken.getType() == LexType.CONTINUETK) {
            stmt.addChildNode(createEndNode());
            if (curToken.getType() == LexType.SEMICN) {
                stmt.addChildNode(createEndNode()); // ';'
            } else {
                errors.put(look(-2).getLineno(), 'i');
            }
        }
        else if (curToken.getType() == LexType.PRINTFTK) {
            stmt.addChildNode(createEndNode());
            stmt.addChildNode(createEndNode()); // '('
            stmt.addChildNode(createEndNode()); // stringConst
            while (curToken.getType() == LexType.COMMA) {
                stmt.addChildNode(createEndNode()); // ','
                stmt.addChildNode(parseExp());
            }
            if (curToken.getType() == LexType.RPARENT) {
                stmt.addChildNode(createEndNode()); // ')'
            } else {
               errors.put(look(-2).getLineno(), 'j');
            }
            if (curToken.getType() == LexType.SEMICN) {
                stmt.addChildNode(createEndNode()); // ';'
            } else {
                errors.put(look(-2).getLineno(), 'i');
            }
        }
        else {
            boolean ass = false;
            for (int i = 0; look(i).getType() != LexType.SEMICN && look(i) != null; i += 1) {
                if (look(i).getType() == LexType.ASSIGN) {
                    ass = true;
                    break;
                }
            }
            if (ass) {
                stmt.addChildNode(parseLVal(" "));
                stmt.addChildNode(createEndNode()); // '='
                if (curToken.getType() == LexType.GETINTTK || curToken.getType() == LexType.GETCHARTK) {
                    stmt.addChildNode(createEndNode()); //
                    stmt.addChildNode(createEndNode()); // '('
                    if (curToken.getType() == LexType.RPARENT) {
                        stmt.addChildNode(createEndNode()); // ')'
                    } else {
                       errors.put(look(-2).getLineno(), 'j');
                    }
                } else {
                    stmt.addChildNode(parseExp());
                }
            } else {
                stmt.addChildNode(parseExp());
            }
            if (curToken.getType() == LexType.SEMICN) {
                stmt.addChildNode(createEndNode()); // ';'
            } else {
                errors.put(look(-2).getLineno(), 'i');
            }
        }
        return stmt;
    }

    public Node parseCond() {
        Node cond = new Node(SyntaxType.Cond, curToken);
        cond.addChildNode(parseLOrExp());
        return cond;
    }

    public Node parseForStmt() {
        Node forStmt = new Node(SyntaxType.ForStmt, curToken);
        forStmt.addChildNode(parseLVal(" "));
        forStmt.addChildNode(createEndNode()); // '='
        forStmt.addChildNode(parseExp());
        return forStmt;
    }

    public Node parseLOrExp() {
        Node lOrExp = new Node(SyntaxType.LOrExp, curToken);
        Node left = parseLAndExp();
        lOrExp.addChildNode(left);

        while (curToken.getType() == LexType.OR) {
            Node operator = new Node(SyntaxType.LOrExp, lOrExp.getToken());
            Node op = createEndNode();
            Node right = parseLAndExp();

            operator.addChildNode(lOrExp);
            operator.addChildNode(op);
            operator.addChildNode(right);

            lOrExp = operator;
        }
        return lOrExp;
    }

    public Node parseLAndExp() {
        Node lAndExp = new Node(SyntaxType.LAndExp, curToken);
        Node left = parseEqExp();
        lAndExp.addChildNode(left);

        while (curToken.getType() == LexType.AND) {
            Node operator = new Node(SyntaxType.LAndExp, lAndExp.getToken());
            Node op = createEndNode();
            Node right = parseEqExp();

            operator.addChildNode(lAndExp);
            operator.addChildNode(op);
            operator.addChildNode(right);

            lAndExp = operator;
        }
        return lAndExp;
    }

    public Node parseEqExp() {
        Node eqExp = new Node(SyntaxType.EqExp, curToken);
        Node left = parseRelExp();
        eqExp.addChildNode(left);

        while (curToken.getType() == LexType.EQL || curToken.getType() == LexType.NEQ) {
            Node operator = new Node(SyntaxType.EqExp, eqExp.getToken());
            Node op = createEndNode();
            Node right = parseRelExp();

            operator.addChildNode(eqExp);
            operator.addChildNode(op);
            operator.addChildNode(right);

            eqExp = operator;
        }
        return eqExp;
    }

    public Node parseRelExp() {
        Node relExp = new Node(SyntaxType.RelExp, curToken);
        Node left = parseAddExp();
        relExp.addChildNode(left);

        while (curToken.getType() == LexType.LSS || curToken.getType() == LexType.LEQ ||
        curToken.getType() == LexType.GRE || curToken.getType() == LexType.GEQ) {
            Node operator = new Node(SyntaxType.RelExp, relExp.getToken());
            Node op = createEndNode();
            Node right = parseAddExp();

            operator.addChildNode(relExp);
            operator.addChildNode(op);
            operator.addChildNode(right);

            relExp = operator;
        }
        return relExp;
    }

    public void output() {
        if (!errors.isEmpty()) {
            return;
        }
        File file = new File("parser.txt");
        try {
            if (!file.exists()) {
                Files.createFile(file.toPath());
            }
            try (FileOutputStream fos = new FileOutputStream(file, true)) {
                root.postOrder(root);
                fos.write(root.getSb().getBytes());
            }
        } catch (IOException e) {
            e.printStackTrace();
            throw new RuntimeException("Error while writing to the file", e);
        }
    }

    private Node createEndNode() {
        Node node = new Node(curToken.getContent(), curToken);
        next();
        return node;
    }
}
