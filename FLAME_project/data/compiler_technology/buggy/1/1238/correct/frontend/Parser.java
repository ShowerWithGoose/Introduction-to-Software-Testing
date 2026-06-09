package frontend;

import error.ErrorType;
import node.Node;
import token.Token;
import error.Error;

import java.util.ArrayList;
import java.util.List;
import static node.NodeType.*;
import static token.Type.*;
import static error.ErrorType.*;

public class Parser {
    private final List<Token> tokens;
    private Node root = null;
    private int current = 0;
    private final List<Error> errors = new ArrayList<>();;

    public Parser(List<Token> tokens) {
        this.tokens = tokens;
    }

    public List<Error> getErrors() {
        return errors;
    }

    private Token next(int n) {
        return tokens.get(current + n);
    }

    private void move() {
        if (current < tokens.size() - 1) {
            current += 1;
        }
    }

    private void last() {
        current -= 1;
    }

    public void parse() {
        root = compUnit();
    }

    public Node getRoot() {
        if (root == null) {
            parse();
        }
        return root;
    }

    private Node compUnit() {
        // CompUnit → {Decl} {FuncDef} MainFuncDef
        Node node = new Node(CompUnit);
        while (next(1).getType() != MAINTK && next(2).getType() != LPARENT) {
            Node declNode = decl();
            node.addChild(declNode);
        }
        while (next(1).getType() != MAINTK) {
            Node funcNode = funcDef();
            node.addChild(funcNode);
        }
        Node mainFuncNode = mainFuncDef();
        node.addChild(mainFuncNode);
        return node;
    }

    private Node decl() {
        // Decl -> ConstDecl | VarDecl
        Node node = new Node(Decl);
        if (next(0).getType() == CONSTTK) {
            Node cdnode = constDecl();
            node.addChild(cdnode);
        } else {
            Node vdnode = varDecl();
            node.addChild(vdnode);
        }
        return node;
    }

    private Node funcDef() {
        // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
        Node node = new Node(FuncDef);
        Node funcTypeNode = funcType();
        node.addChild(funcTypeNode);
        Node identNode = new Node(next(0));
        node.addChild(identNode);
        move();
        Node lparentNode = new Node(next(0));
        node.addChild(lparentNode);
        move();
        if (next(0).getType() != RPARENT) {
            Node funcFParamsNode = funcFParams();
            node.addChild(funcFParamsNode);
        }
        Node rparenNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
        node.addChild(rparenNode);
        handleError(j, next(-1));
        Node blockNode = block();
        node.addChild(blockNode);
        return node;
    }

    private Node funcType() {
        // FuncType → 'void' | 'int' | 'char'
        Node node = new Node(FuncType);
        if (next(0).getType() == VOIDTK) {
            Node voidtkNode = new Node(next(0));
            node.addChild(voidtkNode);
            move();
        } else if (next(0).getType() == INTTK) {
            Node inttkNode = new Node(next(0));
            node.addChild(inttkNode);
            move();
        } else if (next(0).getType() == CHARTK) {
            Node chartkNode = new Node(next(0));
            node.addChild(chartkNode);
            move();
        }
        return node;
    }

    private Node funcFParams() {
        // FuncFParams → FuncFParam { ',' FuncFParam }
        Node node = new Node(FuncFParams);
        Node funcFParamNode = funcFParam();
        node.addChild(funcFParamNode);
        while (next(0).getType() == COMMA) {
            Node commaNode = new Node(next(0));
            node.addChild(commaNode);
            move();
            Node funcFParamNode2 = funcFParam();
            node.addChild(funcFParamNode2);
        }
        return node;
    }

    private Node funcFParam() {
        // FuncFParam → BType Ident ['[' ']'] // k
        Node node = new Node(FuncFParam);
        Node btypeNode = bType();
        node.addChild(btypeNode);
        Node identNode = new Node(next(0));
        node.addChild(identNode);
        move();
        if (next(0).getType() == LBRACK) {
            Node lbracketNode = new Node(next(0));
            node.addChild(lbracketNode);
            move();
            Node rbracketNode = new Node(new Token(RBRACK, "]", next(-1).getLine()));
            node.addChild(rbracketNode);
            handleError(k, next(-1));
        }
        return node;
    }

    private Node block() {
        // Block → '{' { BlockItem } '}'
        Node node = new Node(Block);
        Node lbraceNode = new Node(next(0));
        node.addChild(lbraceNode);
        move();
        while (next(0).getType() != RBRACE) {
            Node blockItemNode = blockItem();
            node.addChild(blockItemNode);
        }
        Node rbraceNode = new Node(next(0));
        node.addChild(rbraceNode);
        move();
        return node;
    }

    private Node blockItem() {
        // BlockItem → Decl | Stmt
        Node node = new Node(BlockItem);
        if (next(0).getType() == CONSTTK || next(0).getType() == INTTK || next(0).getType() == CHARTK) {
            Node declNode = decl();
            node.addChild(declNode);
        } else {
            Node stmtNode = stmt();
            node.addChild(stmtNode);
        }
        return node;
    }

    private boolean hasAssign() {
        int i = current;
        while (i < tokens.size() && tokens.get(i).getLine() == next(0).getLine()) {
            if (tokens.get(i).getType() == ASSIGN) {
                return true;
            }
            ++i;
        }
        return false;
    }

    private Node stmt() {
        /* Stmt → LVal '=' Exp ';'
                | [Exp] ';' // i
                | Block
                | 'if' '(' Cond ')' Stmt [ 'else' Stmt ]
                | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
                | 'break' ';' | 'continue' ';'
                | 'return' [Exp] ';'
                | LVal '=' 'getint''('')'';'
                | LVal '=' 'getchar''('')'';' 
                | 'printf''('StringConst {','Exp}')'';'  */
        Node node = new Node(Stmt);
        if (next(0).getType() == IDENFR) {
            if (hasAssign()) {
                Node lvalNode = lVal();
                node.addChild(lvalNode);
                Node equalNode = new Node(next(0));
                node.addChild(equalNode);
                move();
                if (next(0).getType() == GETINTTK) {
                    Node getintNode = new Node(next(0));
                    node.addChild(getintNode);
                    move();
                    Node lparentNode = new Node(next(0));
                    node.addChild(lparentNode);
                    move();
                    Node rparenNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
                    node.addChild(rparenNode);
                    handleError(j, next(-1));
                    Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
                    node.addChild(semicolonNode);
                    handleError(i, next(-1));
                } else if (next(0).getType() == GETCHARTK) {
                    Node getcharNode = new Node(next(0));
                    node.addChild(getcharNode);
                    move();
                    Node lparentNode = new Node(next(0));
                    node.addChild(lparentNode);
                    move();
                    Node rparenNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
                    node.addChild(rparenNode);
                    handleError(j, next(-1));
                    Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
                    node.addChild(semicolonNode);
                    handleError(i, next(-1));
                } else {
                    Node expNode = exp();
                    node.addChild(expNode);
                    Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
                    node.addChild(semicolonNode);
                    handleError(i, next(-1));
                }
            } else {
                Node expNode = exp();
                node.addChild(expNode);
                Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
                node.addChild(semicolonNode);
                handleError(i, next(-1));
            }
        } else if (next(0).getType() == LBRACE) {
            Node blockNode = block();
            node.addChild(blockNode);
        } else if (next(0).getType() == IFTK) {
            Node iftkNode = new Node(next(0));
            node.addChild(iftkNode);
            move();
            Node lparentNode = new Node(next(0));
            node.addChild(lparentNode);
            move();
            Node condNode = cond();
            node.addChild(condNode);
            Node rparenNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
            node.addChild(rparenNode);
            handleError(j, next(-1));
            Node stmtNode = stmt();
            node.addChild(stmtNode);
            if (next(0).getType() == ELSETK) {
                Node elsetkNode = new Node(next(0));
                node.addChild(elsetkNode);
                move();
                Node stmtNode2 = stmt();
                node.addChild(stmtNode2);
            }
        } else if (next(0).getType() == FORTK) {
            Node fortkNode = new Node(next(0));
            node.addChild(fortkNode);
            move();
            Node lparentNode = new Node(next(0));
            node.addChild(lparentNode);
            move();
            if (next(0).getType() != SEMICN) {
                Node forStmtNode = forStmt();
                node.addChild(forStmtNode);
            }
            Node semicolonNode1 = new Node(new Token(SEMICN, ";", next(-1).getLine()));
            node.addChild(semicolonNode1);
            handleError(i, next(-1));
            if (next(0).getType() != SEMICN) {
                Node condNode = cond();
                node.addChild(condNode);
            }
            Node semicolonNode2 = new Node(new Token(SEMICN, ";", next(-1).getLine()));
            node.addChild(semicolonNode2);
            handleError(i, next(-1));
            if (next(0).getType() != RPARENT) {
                Node forStmtNode2 = forStmt();
                node.addChild(forStmtNode2);
            }
            Node rparenNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
            node.addChild(rparenNode);
            handleError(j, next(-1));
            Node stmtNode = stmt();
            node.addChild(stmtNode);
        } else if (next(0).getType() == BREAKTK) {
            Node breaktkNode = new Node(next(0));
            node.addChild(breaktkNode);
            move();
            Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
            node.addChild(semicolonNode);
            handleError(i, next(-1));
        } else if (next(0).getType() == CONTINUETK) {
            Node continuetkNode = new Node(next(0));
            node.addChild(continuetkNode);
            move();
            Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
            node.addChild(semicolonNode);
            handleError(i, next(-1));
        } else if (next(0).getType() == RETURNTK) {
            Node returntkNode = new Node(next(0));
            node.addChild(returntkNode);
            move();
            if (next(0).getType() != SEMICN) {
                Node expNode = exp();
                node.addChild(expNode);
            }
            Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
            node.addChild(semicolonNode);
            handleError(i, next(-1));
        } else if (next(0).getType() == PRINTFTK) {
            Node printftkNode = new Node(next(0));
            node.addChild(printftkNode);
            move();
            Node lparentNode = new Node(next(0));
            node.addChild(lparentNode);
            move();
            Node stringConstNode = new Node(next(0));
            node.addChild(stringConstNode);
            move();
            while (next(0).getType() == COMMA) {
                Node commaNode = new Node(next(0));
                node.addChild(commaNode);
                move();
                Node expNode = exp();
                node.addChild(expNode);
            }
            Node rparenNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
            node.addChild(rparenNode);
            handleError(j, next(-1));
            Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
            node.addChild(semicolonNode);
            handleError(i, next(-1));
        } else {
            if (next(0).getType() == SEMICN) {
                Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
                node.addChild(semicolonNode);
                handleError(i, next(-1));
            } else {
                Node expNode = exp();
                node.addChild(expNode);
                Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
                node.addChild(semicolonNode);
                handleError(i, next(-1));
            }
        }
        return node;
    }

    private Node forStmt() {
        // ForStmt → LVal '=' Exp
        Node node = new Node(ForStmt);
        Node lvalNode = lVal();
        node.addChild(lvalNode);
        Node equalNode = new Node(next(0));
        node.addChild(equalNode);
        move();
        Node expNode = exp();
        node.addChild(expNode);
        return node;
    }

    private Node cond() {
        // Cond → LOrExp
        Node node = new Node(Cond);
        Node lOrExpNode = lOrExp();
        node.addChild(lOrExpNode);
        return node;
    }

    private Node unaryExp() {
        // UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp // j
        Node node = new Node(UnaryExp);
        if (next(0).getType() == IDENFR) {
            Node identNode = new Node(next(0));
            node.addChild(identNode);
            move();
            if (next(0).getType() == LPARENT) {
                Node lparenNode = new Node(next(0));
                node.addChild(lparenNode);
                move();
                if (next(0).getType() != RPARENT) {
                    Node funcRParamsNode = funcRParams();
                    node.addChild(funcRParamsNode);
                }
                Node rparenNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
                node.addChild(rparenNode);
                handleError(j, next(-1));
            } else {
                last();
                node.deleteChild();
                Node primaryExpNode = primaryExp();
                node.addChild(primaryExpNode);
            }
        } else if (next(0).getType() == PLUS || next(0).getType() == MINU || next(0).getType() == NOT) {
            Node opNode = unaryOp();
            node.addChild(opNode);
            Node unaryExpNode = unaryExp();
            node.addChild(unaryExpNode);
        } else {
            Node primaryExpNode = primaryExp();
            node.addChild(primaryExpNode);
        }
        return node;
    }

    private Node unaryOp() {
        // UnaryOp → '+' | '-' | '!'
        Node node = new Node(UnaryOp);
        if (next(0).getType() == PLUS) {
            Node plusNode = new Node(next(0));
            node.addChild(plusNode);
            move();
        } else if (next(0).getType() == MINU) {
            Node minuNode = new Node(next(0));
            node.addChild(minuNode);
            move();
        } else if (next(0).getType() == NOT) {
            Node notNode = new Node(next(0));
            node.addChild(notNode);
            move();
        }
        return node;
    }

    private Node primaryExp() {
        // PrimaryExp → '(' Exp ')' | LVal | Number | Character// j
        Node node = new Node(PrimaryExp);
        if (next(0).getType() == LPARENT) {
            Node lparenNode = new Node(next(0));
            node.addChild(lparenNode);
            move();
            Node expNode = exp();
            node.addChild(expNode);
            Node rparenNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
            node.addChild(rparenNode);
            handleError(j, next(-1));
        } else if (next(0).getType() == IDENFR) {
            Node lvalNode = lVal();
            node.addChild(lvalNode);
        } else if (next(0).getType() == INTCON) {
            Node numberNode = number();
            node.addChild(numberNode);
        } else if (next(0).getType() == CHRCON) {
            Node characterNode = character();
            node.addChild(characterNode);
        }
        return node;
    }

    private Node addExp() {
        // AddExp → MulExp | AddExp ('+' | '−') MulExp
        Node addExpNode = new Node(AddExp);
        Node mulExpNode = mulExp();
        addExpNode.addChild(mulExpNode);
        while (next(0).getType() == PLUS || next(0).getType() == MINU) {
            Node addNode = new Node(AddExp);
            addNode.addChild(addExpNode);
            Node opNode = new Node(next(0));
            addNode.addChild(opNode);
            move();
            Node mulExpNode2 = mulExp();
            addNode.addChild(mulExpNode2);
            addExpNode = addNode;
        }
        return addExpNode;
    }

    private Node mulExp() {
        // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
        Node node = new Node(MulExp);
        Node unaryExpNode = unaryExp();
        node.addChild(unaryExpNode);
        while (next(0).getType() == MULT || next(0).getType() == DIV || next(0).getType() == MOD) {
            Node mulNode = new Node(MulExp);
            mulNode.addChild(node);
            Node opNode = new Node(next(0));
            mulNode.addChild(opNode);
            move();
            Node unaryExpNode2 = unaryExp();
            mulNode.addChild(unaryExpNode2);
            node = mulNode;
        }
        return node;
    }

    private Node lOrExp() {
        // LOrExp → LAndExp | LOrExp '||' LAndExp
        Node node = new Node(LOrExp);
        Node lAndExpNode = lAndExp();
        node.addChild(lAndExpNode);
        while (next(0).getType() == OR) {
            Node lOrExpNode = new Node(LOrExp);
            lOrExpNode.addChild(node);
            Node ororNode = new Node(next(0));
            lOrExpNode.addChild(ororNode);
            move();
            Node lAndExpNode2 = lAndExp();
            lOrExpNode.addChild(lAndExpNode2);
            node = lOrExpNode;
        }
        return node;
    }

    private Node lAndExp() {
        // LAndExp → EqExp | LAndExp '&&' EqExp
        Node node = new Node(LAndExp);
        Node eqExpNode = eqExp();
        node.addChild(eqExpNode);
        while (next(0).getType() == AND) {
            Node lAndExpNode = new Node(LAndExp);
            lAndExpNode.addChild(node);
            Node andandNode = new Node(next(0));
            lAndExpNode.addChild(andandNode);
            move();
            Node eqExpNode2 = eqExp();
            lAndExpNode.addChild(eqExpNode2);
            node = lAndExpNode;
        }
        return node;
    }

    private Node eqExp() {
        // EqExp → RelExp | EqExp ('==' | '!=') RelExp
        Node node = new Node(EqExp);
        Node relExpNode = relExp();
        node.addChild(relExpNode);
        while (next(0).getType() == EQL || next(0).getType() == NEQ) {
            Node eqExpNode = new Node(EqExp);
            eqExpNode.addChild(node);
            Node opNode = new Node(next(0));
            eqExpNode.addChild(opNode);
            move();
            Node relExpNode2 = relExp();
            eqExpNode.addChild(relExpNode2);
            node = eqExpNode;
        }
        return node;
    }

    private Node relExp() {
        // RelExp → AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
        Node node = new Node(RelExp);
        Node addExpNode = addExp();
        node.addChild(addExpNode);
        while (next(0).getType() == LSS || next(0).getType() == GRE || next(0).getType() == LEQ || next(0).getType() == GEQ) {
            Node relExpNode = new Node(RelExp);
            relExpNode.addChild(node);
            Node opNode = new Node(next(0));
            relExpNode.addChild(opNode);
            move();
            Node addExpNode2 = addExp();
            relExpNode.addChild(addExpNode2);
            node = relExpNode;
        }
        return node;
    }

    private Node mainFuncDef() {
        // MainFuncDef → 'int' 'main' '(' ')' Block // j
        Node node = new Node(MainFuncDef);
        Node inttkNode = new Node(next(0));
        node.addChild(inttkNode);
        move();
        Node mainNode = new Node(next(0));
        node.addChild(mainNode);
        move();
        Node lparentNode = new Node(next(0));
        node.addChild(lparentNode);
        move();
        Node rparentNode = new Node(new Token(RPARENT, ")", next(-1).getLine()));
        node.addChild(rparentNode);
        handleError(j, next(-1));
        Node blockNode = block();
        node.addChild(blockNode);
        return node;
    }


    private Node constDecl() {
        // ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
        Node node = new Node(ConstDecl);
        Node consttkNode = new Node(next(0));
        node.addChild(consttkNode);
        move();
        Node btypeNode = bType();
        node.addChild(btypeNode);
        Node constDefNode = constDef();
        node.addChild(constDefNode);
        while (next(0).getType() == COMMA) {
            Node commaNode = new Node(next(0));
            node.addChild(commaNode);
            move();
            Node constDefNode2 = constDef();
            node.addChild(constDefNode2);
        }
        Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
        node.addChild(semicolonNode);
        handleError(i, next(-1));
        return node;
    }

    private Node constDef() {
        // ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
        Node node = new Node(ConstDef);;
        Node identNode = new Node(next(0));
        node.addChild(identNode);
        move();
        if (next(0).getType() == LBRACK) {
            Node lbracketNode = new Node(next(0));
            node.addChild(lbracketNode);
            move();
            Node constExpNode = constExp();
            node.addChild(constExpNode);
            Node rbracketNode = new Node(new Token(RBRACK, "]", next(-1).getLine()));
            node.addChild(rbracketNode);
            handleError(k, next(-1));
        }
        Node equalNode = new Node(next(0));
        node.addChild(equalNode);
        move();
        Node constInitValNode = constInitVal();
        node.addChild(constInitValNode);
        return node;
    }

    private Node constInitVal() {
        // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
        Node node = new Node(ConstInitVal);
        if (next(0).getType() == LBRACE) {
            Node lbraceNode = new Node(next(0));
            node.addChild(lbraceNode);
            move();
            if (next(0).getType() != RBRACE) {
                Node constExpNode = constExp();
                node.addChild(constExpNode);
                while (next(0).getType() == COMMA) {
                    Node commaNode = new Node(next(0));
                    node.addChild(commaNode);
                    move();
                    Node constExpNode2 = constExp();
                    node.addChild(constExpNode2);
                }
            }
            Node rbraceNode = new Node(next(0));
            node.addChild(rbraceNode);
            move();
        } else if (next(0).getType() == STRCON) {
            Node stringConstNode = new Node(next(0));
            node.addChild(stringConstNode);
            move();
        } else {
            Node constExpNode = constExp();
            node.addChild(constExpNode);
        }
        return node;
    }

    private Node constExp() {
        // ConstExp → AddExp
        Node node = new Node(ConstExp);
        Node addExpNode = addExp();
        node.addChild(addExpNode);
        return node;
    }

    private Node bType() {
        // BType → 'int' | 'char'
        Node node = new Node(BType);
        if (next(0).getType() == INTTK) {
            Node inttkNode = new Node(next(0));
            node.addChild(inttkNode);
            move();
        } else if (next(0).getType() == CHARTK) {
            Node chartkNode = new Node(next(0));
            node.addChild(chartkNode);
            move();
        }
        return node;
    }


    private Node varDecl() {
        // VarDecl → BType VarDef { ',' VarDef } ';'
        Node node = new Node(VarDecl);
        Node btypeNode = bType();
        node.addChild(btypeNode);
        Node varDefNode = varDef();
        node.addChild(varDefNode);
        while (next(0).getType() == COMMA) {
            Node commaNode = new Node(next(0));
            node.addChild(commaNode);
            move();
            Node varDefNode2 = varDef();
            node.addChild(varDefNode2);
        }
        Node semicolonNode = new Node(new Token(SEMICN, ";", next(-1).getLine()));
        node.addChild(semicolonNode);
        handleError(i, next(-1));
        return node;
    }

    private Node varDef() {
        // VarDef → Ident [ '[' ConstExp ']' ] [ '=' InitVal ]
        Node node = new Node(VarDef);
        Node identNode = new Node(next(0));
        node.addChild(identNode);
        move();
        if (next(0).getType() == LBRACK) {
            Node lbracketNode = new Node(next(0));
            node.addChild(lbracketNode);
            move();
            Node constExpNode = constExp();
            node.addChild(constExpNode);
            Node rbracketNode = new Node(new Token(RBRACK, "]", next(-1).getLine()));
            node.addChild(rbracketNode);
            handleError(k, next(-1));
        }
        if (next(0).getType() == ASSIGN) {
            Node equalNode = new Node(next(0));
            node.addChild(equalNode);
            move();
            Node initValNode = initVal();
            node.addChild(initValNode);
        }
        return node;
    }

    private Node initVal() {
        // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
        Node node = new Node(InitVal);
        if (next(0).getType() == LBRACE) {
            Node lbraceNode = new Node(next(0));
            node.addChild(lbraceNode);
            move();
            if (next(0).getType() != RBRACE) {
                Node expNode = exp();
                node.addChild(expNode);
                while (next(0).getType() == COMMA) {
                    Node commaNode = new Node(next(0));
                    node.addChild(commaNode);
                    move();
                    Node expNode2 = exp();
                    node.addChild(expNode2);
                }
            }
            Node rbraceNode = new Node(next(0));
            node.addChild(rbraceNode);
            move();
        } else if (next(0).getType() == STRCON) {
            Node stringConstNode = new Node(next(0));
            node.addChild(stringConstNode);
            move();
        } else {
            Node expNode = exp();
            node.addChild(expNode);
        }
        return node;
    }

    private Node exp() {
        // Exp → AddExp
        Node node = new Node(Exp);
        Node addExpNode = addExp();
        node.addChild(addExpNode);
        return node;
    }

    private Node number() {
        // Number → INTCON
        Node node = new Node(Number);
        Node intconNode = new Node(next(0));
        node.addChild(intconNode);
        move();
        return node;
    }

    private Node character() {
        // Character → CHRCON
        Node node = new Node(Character);
        Node chrconNode = new Node(next(0));
        node.addChild(chrconNode);
        move();
        return node;
    }

    private Node lVal() {
        // LVal → Ident ['[' Exp ']'] // k
        Node node = new Node(LVal);
        Node identNode = new Node(next(0));
        node.addChild(identNode);
        move();
        if (next(0).getType() == LBRACK) {
            Node lbracketNode = new Node(next(0));
            node.addChild(lbracketNode);
            move();
            Node expNode = exp();
            node.addChild(expNode);
            Node rbracketNode = new Node(new Token(RBRACK, "]", next(-1).getLine()));
            node.addChild(rbracketNode);
            handleError(k, next(-1));
        }
        return node;
    }

    private Node funcRParams() {
        // FuncRParams → Exp { ',' Exp }
        Node node = new Node(FuncRParams);
        Node expNode = exp();
        node.addChild(expNode);
        while (next(0).getType() == COMMA) {
            Node commaNode = new Node(next(0));
            node.addChild(commaNode);
            move();
            Node expNode2 = exp();
            node.addChild(expNode2);
        }
        return node;
    }

    public List<String> inorder(Node node, List<String> list) {
        if (node == null) {
            return new ArrayList<>();
        }
        for (int i = 0; i < node.getChildren().size(); i++) {
            inorder(node.getChildren().get(i), list);
        }
        list.add(node.toString());
        return list;
    }

    private void handleError(ErrorType type, Token token) {
        if (type == i) {
            if (next(0).getType() != SEMICN) {
                Error error = new Error(i, token.getLine());
                errors.add(error);
            } else {
                move();
            }
        } else if (type == j) {
            if (next(0).getType() != RPARENT) {
                Error error = new Error(j, token.getLine());
                errors.add(error);
            } else {
                move();
            }
        } else if (type == k) {
            if (next(0).getType() != RBRACK) {
                Error error = new Error(k, token.getLine());
                errors.add(error);
            } else {
                move();
            }
        }
    }

}
