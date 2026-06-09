package frontend;

import java.util.ArrayList;

public class Parser {
    private ArrayList<Token> tokens;
    private ArrayList<Error> errors;
    private int position;
    private Token now;
    private ArrayList<String> output;
    public Parser(ArrayList<Token> tokens, ArrayList<Error> errors) {
        this.tokens = tokens;
        this.errors = errors;
        output = new ArrayList<>();
        position = 0;
        now = tokens.get(position);
    }

    private void getNext() {
        ++position;
        if (position >= tokens.size()) {
            now = null;
        } else {
            now = tokens.get(position);
        }
    }

    private void delToken() {
        position--;
        now = tokens.get(position);
    }

    private boolean checkDecl() {
        if (now.getType() == TokenType.CONSTTK) {
            return true;
        }
        if (now.getType() != TokenType.INTTK && now.getType() != TokenType.CHARTK) {
            return false;
        }
        getNext();
        if (now.getType() != TokenType.IDENFR) {
            delToken();
            return false;
        }
        getNext();
        if (now.getType() != TokenType.LPARENT) {
            delToken();
            delToken();
            return true;
        }
        delToken();
        delToken();
        return false;
    }

    private boolean checkFunc() {
        if (now.getType() != TokenType.INTTK && now.getType() != TokenType.CHARTK && now.getType() != TokenType.VOIDTK) {
            return false;
        }
        getNext();
        if (now.getType() != TokenType.IDENFR) {
            delToken();
            return false;
        }
        delToken();
        return true;
    }


    private Node compUnitParser() {
        Node node = new Node(NodeType.CompUnit);
        while (checkDecl()) {
            node.addSon(declParser());
        }
        while (checkFunc()) {
            node.addSon(funcDefParser());
        }
        node.addSon(mainFuncDefParser());
        return node;
    }

    private Node declParser() {
        Node node = new Node(NodeType.Decl);
        if (now.getType() == TokenType.CONSTTK) {
            node.addSon(constDeclParser());
        } else {
            node.addSon(varDeclParser());
        }
        return node;
    }

    private Node constDeclParser() {
        Node node = new Node(NodeType.ConstDecl);
        assert(now.getType() == TokenType.CONSTTK);
        node.addSon(new Node(now));
        getNext();
        node.addSon(bTypeParser());
        node.addSon(constDefParser());
        while (now.getType() == TokenType.COMMA) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(constDefParser());
        }
        if (now.getType() != TokenType.SEMICN) {
            delToken();
            errors.add(new Error(now.getLine(), "i"));
            getNext();
        } else {
            node.addSon(new Node(now));
            getNext();
        }
        return node;
    }

    private Node bTypeParser() {
        assert (now.getType() == TokenType.INTTK || now.getType() == TokenType.CHARTK);
        Node node = new Node(NodeType.BType);
        node.addSon(new Node(now));
        getNext();
        return node;
    }

    private Node constDefParser() {
        assert (now.getType() == TokenType.IDENFR);
        Node node = new Node(NodeType.ConstDef);
        node.addSon(new Node(now));
        getNext();
        if (now.getType() == TokenType.LBRACK) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(constExpParser());
            if (now.getType() != TokenType.RBRACK) {
                delToken();
                errors.add(new Error(now.getLine(), "k"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        }
        assert(now.getType() == TokenType.ASSIGN);
        node.addSon(new Node(now));
        getNext();
        node.addSon(constInitValParser());
        return node;
    }

    private Node constInitValParser() {
        Node node = new Node(NodeType.ConstInitVal);
        if (now.getType() == TokenType.STRCON) {
            node.addSon(new Node(now));
            getNext();
        } else if(now.getType() == TokenType.LBRACE) {
            node.addSon(new Node(now));
            getNext();
            if (now.getType() != TokenType.RBRACE) {
                node.addSon(constExpParser());
                while(now.getType() == TokenType.COMMA) {
                    node.addSon(new Node(now));
                    getNext();
                    node.addSon(constExpParser());
                }
            }
            node.addSon(new Node(now));
            getNext();
        } else {
            node.addSon(constExpParser());
        }
        return node;
    }

    private Node varDeclParser() {
        Node node = new Node(NodeType.VarDecl);
        node.addSon(bTypeParser());
        node.addSon(varDefParser());
        while (now.getType() == TokenType.COMMA) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(varDefParser());
        }
        if (now.getType() != TokenType.SEMICN) {
            delToken();
            errors.add(new Error(now.getLine(), "i"));
            getNext();
        } else {
            node.addSon(new Node(now));
            getNext();
        }
        return node;
    }

    private Node varDefParser() {
        assert (now.getType() == TokenType.IDENFR);
        Node node = new Node(NodeType.VarDef);
        node.addSon(new Node(now));
        getNext();
        if (now.getType() == TokenType.LBRACK) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(constExpParser());
            if (now.getType() != TokenType.RBRACK) {
                delToken();
                errors.add(new Error(now.getLine(), "k"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        }
        if (now.getType() == TokenType.ASSIGN) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(initValParser());
        }
        return node;
    }

    private Node initValParser() {
        Node node = new Node(NodeType.InitVal);
        if (now.getType() == TokenType.STRCON) {
            node.addSon(new Node(now));
            getNext();
        } else if(now.getType() == TokenType.LBRACE) {
            node.addSon(new Node(now));
            getNext();
            if (now.getType() != TokenType.RBRACE) {
                node.addSon(expParser());
                while(now.getType() == TokenType.COMMA) {
                    node.addSon(new Node(now));
                    getNext();
                    node.addSon(expParser());
                }
            }
            node.addSon(new Node(now));
            getNext();
        } else {
            node.addSon(expParser());
        }
        return node;
    }

    private Node funcDefParser() {
        Node node = new Node(NodeType.FuncDef);
        node.addSon(funcTypeParser());
        assert (now.getType() == TokenType.IDENFR);
        node.addSon(new Node(now));
        getNext();
        assert (now.getType() == TokenType.LPARENT);
        node.addSon(new Node(now));
        getNext();
        if (now.getType() == TokenType.INTTK || now.getType() == TokenType.CHARTK) {
            node.addSon(funcFParamsParser());
        }
        if (now.getType() != TokenType.RPARENT) {
            delToken();
            errors.add(new Error(now.getLine(), "j"));
            getNext();
        } else {
            node.addSon(new Node(now));
            getNext();
        }
        node.addSon(blockParser());
        return node;
    }

    private Node mainFuncDefParser() {
        Node node = new Node(NodeType.MainFuncDef);
        assert (now.getType() == TokenType.INTTK);
        node.addSon(new Node(now));
        getNext();
        assert (now.getType() == TokenType.MAINTK);
        node.addSon(new Node(now));
        getNext();
        assert (now.getType() == TokenType.LPARENT);
        node.addSon(new Node(now));
        getNext();
        if (now.getType() != TokenType.RPARENT) {
            delToken();
            errors.add(new Error(now.getLine(), "j"));
            getNext();
        } else {
            node.addSon(new Node(now));
            getNext();
        }
        node.addSon(blockParser());
        return node;
    }

    private Node funcTypeParser() {
        assert (now.getType() == TokenType.INTTK ||
                now.getType() == TokenType.VOIDTK ||
                now.getType() == TokenType.CHARTK);
        Node node = new Node(NodeType.FuncType);
        node.addSon(new Node(now));
        getNext();
        return node;
    }

    private Node funcFParamsParser() {
        Node node = new Node(NodeType.FuncFParams);
        node.addSon(funcFParamParser());
        while(now.getType() == TokenType.COMMA) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(funcFParamParser());
        }
        return node;
    }

    private Node funcFParamParser() {
        Node node = new Node(NodeType.FuncFParam);
        node.addSon(bTypeParser());
        assert (now.getType() == TokenType.IDENFR);
        node.addSon(new Node(now));
        getNext();
        if (now.getType() == TokenType.LBRACK) {
            node.addSon(new Node(now));
            getNext();
            if (now.getType() != TokenType.RBRACK) {
                delToken();
                errors.add(new Error(now.getLine(), "k"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        }
//        output.add("<ConstInitVal>\n");
        return node;
    }

    private Node blockParser() {
        Node node = new Node(NodeType.Block);
        assert (now.getType() == TokenType.LBRACE);
        node.addSon(new Node(now));
        getNext();
//        int i = 1;
        while(now.getType() != TokenType.RBRACE) {
//            System.out.println(position + " " + now.getType() + " " + now.getVal() + " " + now.getLine());
            node.addSon(blockItemParser());
//            i++;
//            if (i == 3) break;
        }
        assert (now.getType() == TokenType.RBRACE);
        node.addSon(new Node(now));
        getNext();
        return node;
    }

    private Node blockItemParser() {
        Node node = new Node(NodeType.BlockItem);
        if (now.getType() == TokenType.CONSTTK ||
                now.getType() == TokenType.INTTK ||
                now.getType() == TokenType.CHARTK) {
            node.addSon(declParser());
        } else {
            node.addSon(stmtParser());
        }
        return node;
    }

    private Node stmtParser() {
        Node node = new Node(NodeType.Stmt);
        if (now.getType() == TokenType.IFTK) {
            node.addSon(new Node(now));
            getNext();
            assert (now.getType() == TokenType.LPARENT);
            node.addSon(new Node(now));
            getNext();
            node.addSon(condParser());
            if (now.getType() != TokenType.RPARENT) {
                delToken();
                errors.add(new Error(now.getLine(), "j"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
            node.addSon(stmtParser());
            if (now.getType() == TokenType.ELSETK) {
                node.addSon(new Node(now));
                getNext();
                node.addSon(stmtParser());
            }
        } else if (now.getType() == TokenType.FORTK) {
            node.addSon(new Node(now));
            getNext();
            assert (now.getType() == TokenType.LPARENT);
            node.addSon(new Node(now));
            getNext();
            if (now.getType() != TokenType.SEMICN) {
                node.addSon(forStmtParser());
            }
            assert (now.getType() == TokenType.SEMICN);
            node.addSon(new Node(now));
            getNext();
            if (now.getType() != TokenType.SEMICN) {
                node.addSon(condParser());
            }
            assert (now.getType() == TokenType.SEMICN);
            node.addSon(new Node(now));
            getNext();
            if (now.getType() != TokenType.RPARENT) {
                node.addSon(forStmtParser());
            }
            assert (now.getType() == TokenType.RPARENT);
            node.addSon(new Node(now));
            getNext();
            node.addSon(stmtParser());
        } else if (now.getType() == TokenType.BREAKTK || now.getType() == TokenType.CONTINUETK) {
            node.addSon(new Node(now));
            getNext();
            if (now.getType() != TokenType.SEMICN) {
                delToken();
                errors.add(new Error(now.getLine(), "i"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        } else if (now.getType() == TokenType.RETURNTK) {
            node.addSon(new Node(now));
            getNext();
            if (now.getType() == TokenType.IDENFR || now.getType() == TokenType.LPARENT ||
                    now.getType() == TokenType.INTCON || now.getType() == TokenType.CHRCON ||
                    now.getType() == TokenType.PLUS || now.getType() == TokenType.MINU ||
                    now.getType() == TokenType.NOT) {
                node.addSon(expParser());
            }
            if (now.getType() != TokenType.SEMICN) {
                delToken();
                errors.add(new Error(now.getLine(), "i"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        } else if (now.getType() == TokenType.PRINTFTK) {
            node.addSon(new Node(now));
            getNext();
            assert (now.getType() == TokenType.LPARENT);
            node.addSon(new Node(now));
            getNext();
            assert (now.getType() == TokenType.STRCON);
            node.addSon(new Node(now));
            getNext();
            while(now.getType() == TokenType.COMMA) {
                node.addSon(new Node(now));
                getNext();
                node.addSon(expParser());
            }
            if (now.getType() != TokenType.RPARENT) {
                delToken();
                errors.add(new Error(now.getLine(), "j"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
            if (now.getType() != TokenType.SEMICN) {
                delToken();
                errors.add(new Error(now.getLine(), "i"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        } else if (now.getType() == TokenType.LBRACE) {
            node.addSon(blockParser());
        } else if (now.getType() == TokenType.PLUS || now.getType() == TokenType.MINU ||
                now.getType() == TokenType.NOT ||
                now.getType() == TokenType.LPARENT || now.getType() == TokenType.INTCON ||
                now.getType() == TokenType.CHRCON) {
            node.addSon(expParser());
            if (now.getType() != TokenType.SEMICN) {
                delToken();
                errors.add(new Error(now.getLine(), "i"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        } else if (now.getType() == TokenType.IDENFR) {
            getNext();
            if (now.getType() == TokenType.LPARENT) {
                delToken();
                node.addSon(expParser());
                if (now.getType() != TokenType.SEMICN) {
                    delToken();
                    errors.add(new Error(now.getLine(), "i"));
                    getNext();
                } else {
                    node.addSon(new Node(now));
                    getNext();
                }
            } else {
                delToken();
                int pos = position;
                Node lval = lValParser();
//                System.out.println(now.getType() + " " + now.getVal() + " " + now.getLine());
                if (now.getType() == TokenType.ASSIGN) {
                    node.addSon(lval);
                    node.addSon(new Node(now));
                    getNext();
                    if (now.getType() == TokenType.GETINTTK || now.getType() == TokenType.GETCHARTK) {
                        node.addSon(new Node(now));
                        getNext();
                        assert (now.getType() == TokenType.LPARENT);
                        node.addSon(new Node(now));
                        getNext();
                        if (now.getType() != TokenType.RPARENT) {
                            delToken();
                            errors.add(new Error(now.getLine(), "j"));
                            getNext();
                        } else {
                            node.addSon(new Node(now));
                            getNext();
                        }
                        if (now.getType() != TokenType.SEMICN) {
                            delToken();
                            errors.add(new Error(now.getLine(), "i"));
                            getNext();
                        } else {
                            node.addSon(new Node(now));
                            getNext();
                        }
                    } else {
                        node.addSon(expParser());
                        if (now.getType() != TokenType.SEMICN) {
                            delToken();
                            errors.add(new Error(now.getLine(), "i"));
                            getNext();
                        } else {
                            node.addSon(new Node(now));
                            getNext();
                        }
                    }
                } else {
                    position = pos;
                    now = tokens.get(position);
//                    System.out.println(now.getType() + " " + now.getVal() + " " + now.getLine());
                    node.addSon(expParser());
                    if (now.getType() != TokenType.SEMICN) {
                        delToken();
                        errors.add(new Error(now.getLine(), "i"));
                        getNext();
                    } else {
                        node.addSon(new Node(now));
                        getNext();
                    }
                }
            }
        } else if (now.getType() == TokenType.SEMICN) {
            node.addSon(new Node(now));
            getNext();
        } else {
            delToken();
            errors.add(new Error(now.getLine(), "i"));
            getNext();
        }
        return node;
    }

    private Node forStmtParser() {
        Node node = new Node(NodeType.ForStmt);
        node.addSon(lValParser());
        assert (now.getType() == TokenType.ASSIGN);
        node.addSon(new Node(now));
        getNext();
        node.addSon(expParser());
        return node;
    }

    private Node expParser() {
        Node node = new Node(NodeType.Exp);
        node.addSon(addExpParser());
        return node;
    }

    private Node condParser() {
        Node node = new Node(NodeType.Cond);
        node.addSon(lOrExpParser());
        return node;
    }

    private Node lValParser() {
        Node node = new Node(NodeType.LVal);
        node.addSon(new Node(now));
        getNext();
        if (now.getType() == TokenType.LBRACK) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(expParser());
            if (now.getType() != TokenType.RBRACK) {
                delToken();
                errors.add(new Error(now.getLine(), "k"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        }
        return node;
    }

    private Node primaryExpParser() {
        Node node = new Node(NodeType.PrimaryExp);
//        System.out.println(now.getType() + " " + now.getVal());
        if (now.getType() == TokenType.LPARENT) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(expParser());
            if (now.getType() != TokenType.RPARENT) {
                delToken();
                errors.add(new Error(now.getLine(), "j"));
                getNext();
            } else {
                node.addSon(new Node(now));
                getNext();
            }
        } else if (now.getType() == TokenType.IDENFR) {
            node.addSon(lValParser());
        } else if (now.getType() == TokenType.INTCON) {
            node.addSon(numberParser());
        } else if (now.getType() == TokenType.CHRCON) {
//            System.out.println("zzz");
            node.addSon(characterParser());
        }
        return node;
    }

    private Node numberParser() {
        assert (now.getType() == TokenType.INTCON);
        Node node = new Node(NodeType.Number);
        node.addSon(new Node(now));
        getNext();
        return node;
    }

    private Node characterParser() {
        assert (now.getType() == TokenType.CHRCON);
        Node node = new Node(NodeType.Character);
        node.addSon(new Node(now));
        getNext();
        return node;
    }

    private Node unaryExpParser() {
        Node node = new Node(NodeType.UnaryExp);
        if (now.getType() == TokenType.IDENFR) {
            getNext();
            if (now.getType() == TokenType.LPARENT) {
                delToken();
                node.addSon(new Node(now));
                getNext();
                node.addSon(new Node(now));
                getNext();
                if (now.getType() == TokenType.IDENFR || now.getType() == TokenType.LPARENT ||
                        now.getType() == TokenType.INTCON || now.getType() == TokenType.CHRCON ||
                        now.getType() == TokenType.PLUS || now.getType() == TokenType.MINU ||
                        now.getType() == TokenType.NOT) {
                    node.addSon(funcRParamsParser());
                }
                if (now.getType() != TokenType.RPARENT) {
                    delToken();
                    errors.add(new Error(now.getLine(), "j"));
                    getNext();
                } else {
                    node.addSon(new Node(now));
                    getNext();
                }
            } else {
                delToken();
                node.addSon(primaryExpParser());
            }
        } else if (now.getType() == TokenType.PLUS ||
                now.getType() == TokenType.MINU ||
                now.getType() == TokenType.NOT) {
                node.addSon(unaryOpParser());
                node.addSon(unaryExpParser());
        } else {
//            System.out.println(now.getType() + " " + now.getVal() + "bb");
            node.addSon(primaryExpParser());
        }
        return node;
    }

    private Node unaryOpParser() {
        Node node = new Node(NodeType.UnaryOp);
        node.addSon(new Node(now));
        getNext();
        return node;
    }

    private Node funcRParamsParser() {
        Node node = new Node(NodeType.FuncRParams);
        node.addSon(expParser());
        while(now.getType() == TokenType.COMMA) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(expParser());
        }
        return node;
    }

    private Node mulExpParser() {
        Node node = new Node(NodeType.MulExp);
        node.addSon(unaryExpParser());
        while (now.getType() == TokenType.MULT ||
                now.getType() == TokenType.DIV ||
                now.getType() == TokenType.MOD) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(unaryExpParser());
        }
        return node;
    }

    private Node addExpParser() {
        Node node = new Node(NodeType.AddExp);
        node.addSon(mulExpParser());
//        System.out.println(now.getType() + " " + now.getVal() + "aa");
        while (now.getType() == TokenType.PLUS ||
                now.getType() == TokenType.MINU) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(mulExpParser());
        }
        return node;
    }

    private Node relExpParser() {
        Node node = new Node(NodeType.RelExp);
        node.addSon(addExpParser());
        while (now.getType() == TokenType.LSS ||
                now.getType() == TokenType.LEQ ||
                now.getType() == TokenType.GRE ||
                now.getType() == TokenType.GEQ) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(addExpParser());
        }
        return node;
    }

    private Node eqExpParser() {
        Node node = new Node(NodeType.EqExp);
        node.addSon(relExpParser());
        while (now.getType() == TokenType.EQL ||
                now.getType() == TokenType.NEQ) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(relExpParser());
        }
        return node;
    }

    private Node lAndExpParser() {
        Node node = new Node(NodeType.LAndExp);
        node.addSon(eqExpParser());
        while (now.getType() == TokenType.AND) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(eqExpParser());
        }
        return node;
    }

    private Node lOrExpParser() {
        Node node = new Node(NodeType.LOrExp);
        node.addSon(lAndExpParser());
        while (now.getType() == TokenType.OR) {
            node.addSon(new Node(now));
            getNext();
            node.addSon(lAndExpParser());
        }
        return node;
    }

    private Node constExpParser() {
        Node node = new Node(NodeType.ConstExp);
        node.addSon(addExpParser());
        return node;
    }

    public ArrayList<String> getOutput() {
        return output;
    }

    public Node run() {
        return compUnitParser();
    }

}
