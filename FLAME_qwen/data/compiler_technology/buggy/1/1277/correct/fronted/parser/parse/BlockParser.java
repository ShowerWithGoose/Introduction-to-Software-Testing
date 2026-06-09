package fronted.parser.parse;

import config.ErrorType;
import fronted.lexer.Lexer;
import fronted.lexer.Token;
import fronted.lexer.TokenType;
import fronted.parser.syntax.*;

import java.util.ArrayList;

public class BlockParser extends Parser {
    private final Lexer lexer;
    public BlockParser(Lexer lexer) {
        this.lexer = lexer;
    }

    // Block → '{' { BlockItem } '}'
    @Override
    public SynNode parse() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext())); // {
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.RBRACE) {
                children.add(new SynLeaf(t));
                break;
            } else {
                lexer.move(-1);
                children.add(parseBlockItem());
            }
        }
        // must end with }, hasNext is False
        if (!lexer.hasNext()) {
            children.add(new SynLeaf(lexer.getAndNext())); // }
        }
        return new SynNonLeaf(SynType.Block, children);
    }

    // BlockItem → Decl | Stmt
    public SynNode parseBlockItem() {
        ArrayList<SynNode> children = new ArrayList<>();
        Token t = lexer.getAndNext();
        lexer.move(-1);
        if (t.getType() == TokenType.CONSTTK || t.getType() == TokenType.INTTK || t.getType() == TokenType.CHARTK) {
            DeclParser declParser = new DeclParser(lexer);
            children.add(declParser.parse());
            updateError(declParser.getErrorList());
        } else {
            children.add(parseStmt());
        }
        return new SynNonLeaf(SynType.BlockItem, children);
    }

    // signal: 'if', 'for', 'break', 'continue', 'return', 'printf'
    // differ: LVal, Exp
    public SynNode parseStmt() {
        ArrayList<SynNode> children;
        Token t = lexer.getAndNext();
        lexer.move(-1);
        if (t.getType() == TokenType.IFTK) {
            children = parseIfStmt();
        } else if (t.getType() == TokenType.FORTK) {
            children = parseFottkStmt();
        } else if (t.getType() == TokenType.BREAKTK || t.getType() == TokenType.CONTINUETK) {
            children = parseBreakContinueStmt();
        } else if (t.getType() == TokenType.RETURNTK) {
            children = parseReturnStmt();
        } else if (t.getType() == TokenType.PRINTFTK) {
            children = parsePrintfStmt();
        } else if (t.getType() == TokenType.LBRACE) {
            children = new ArrayList<>();
            children.add(parse());
        } else {
            children = parseHead();
        }
        return new SynNonLeaf(SynType.Stmt, children);
    }

    // 语句 ForStmt → LVal '=' Exp
    public SynNode parseForStmt() {
        ArrayList<SynNode> children = new ArrayList<>();
        ExpParser expParser = new ExpParser(lexer);
        children.add(expParser.parseLVal());
        children.add(new SynLeaf(lexer.getAndNext()));
        children.add(expParser.parse());
        return new SynNonLeaf(SynType.ForStmt, children);
    }

    // Cond → LOrExp
    public SynNode parseCond() {
        ArrayList<SynNode> children = new ArrayList<>();
        ExpParser expParser = new ExpParser(lexer);
        children.add(expParser.parseLOrExp());
        updateError(expParser.getErrorList());
        return new SynNonLeaf(SynType.Cond, children);
    }


    // 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
    public ArrayList<SynNode> parseIfStmt() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext())); // if
        children.add(new SynLeaf(lexer.getAndNext())); // (
        children.add(parseCond()); // Cond
        Token t = lexer.getAndNext();
        if (t.getType() == TokenType.RPARENT) {
            children.add(new SynLeaf(t));
        } else {
            lexer.move(-1);
            addError(new ErrorSyntax(children.get(0).getLeaf().getLine(), ErrorType.j));
        }
        children.add(parseStmt());
        t = lexer.getAndNext();
        if (t.getType() == TokenType.ELSETK) {
            children.add(new SynLeaf(t));
            children.add(parseStmt());
        } else {
            lexer.move(-1);
        }
        return children;
    }

    // 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
    public ArrayList<SynNode> parseFottkStmt() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext())); // for
        children.add(new SynLeaf(lexer.getAndNext())); // (
        Token t = lexer.getAndNext();
        if (t.getType() == TokenType.SEMICN) {
            children.add(new SynLeaf(t));
        } else {
            lexer.move(-1);
            children.add(parseForStmt());
            children.add(new SynLeaf(lexer.getAndNext()));
        }
        t = lexer.getAndNext();
        if (t.getType() == TokenType.SEMICN) {
            children.add(new SynLeaf(t));
        } else {
            lexer.move(-1);
            children.add(parseCond());
            children.add(new SynLeaf(lexer.getAndNext()));
        }
        t = lexer.getAndNext();
        if (t.getType() == TokenType.RPARENT) {
            children.add(new SynLeaf(t));
        } else {
            lexer.move(-1);
            children.add(parseForStmt());
            children.add(new SynLeaf(lexer.getAndNext()));
        }
        children.add(parseStmt());
        return children;
    }

    // break' ';' // i
    public ArrayList<SynNode> parseBreakContinueStmt() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext()));
        Token t = lexer.getAndNext();
        if (t.getType() == TokenType.SEMICN) {
            children.add(new SynLeaf(t));
        } else {
            lexer.move(-1);
            addError(new ErrorSyntax(children.get(0).getLeaf().getLine(), ErrorType.i));
        }
        return children;
    }


    // 'return' [Exp] ';' // i
    public ArrayList<SynNode> parseReturnStmt() {
        // TODO
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext()));
        Token t = lexer.getAndNext();
        if (t.getType() == TokenType.SEMICN) {
            children.add(new SynLeaf(t));
        } else {
            lexer.move(-1);
            if (isExp(lexer)) {
                ExpParser expParser = new ExpParser(lexer);
                children.add(expParser.parse());
                updateError(expParser.getErrorList());

                t = lexer.getAndNext();
                if (t.getType() == TokenType.SEMICN) {
                    children.add(new SynLeaf(t));
                } else {
                    lexer.move(-1);
                    addError(new ErrorSyntax(children.get(0).getLeaf().getLine(), ErrorType.i));
                }
            } else {
                addError(new ErrorSyntax(children.get(0).getLeaf().getLine(), ErrorType.i));
            }
        }
        return children;
    }

    // 'printf''('StringConst {','Exp}')'';' // i j
    public ArrayList<SynNode> parsePrintfStmt() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext())); // printf
        children.add(new SynLeaf(lexer.getAndNext())); // (
        children.add(new SynLeaf(lexer.getAndNext())); // StringCon
        Token t = null;
        while (lexer.hasNext()) {
            t = lexer.getAndNext();
            if (t.getType() == TokenType.COMMA) {
                children.add(new SynLeaf(t));
                ExpParser expParser = new ExpParser(lexer);
                children.add(expParser.parse());
                updateError(expParser.getErrorList());
            } else {
                lexer.move(-1);
                break;
            }
        } // out: ), ;, 'unexpected'
        t = lexer.getAndNext();
        if (t.getType() == TokenType.RPARENT) {
            children.add(new SynLeaf(t));
        } else {
            lexer.move(-1);
            addError(new ErrorSyntax(children.get(0).getLeaf().getLine(), ErrorType.j));
        }

        t = lexer.getAndNext();
        if (t.getType() == TokenType.SEMICN) {
            children.add(new SynLeaf(t));
        } else {
            lexer.move(-1);
            addError(new ErrorSyntax(children.get(0).getLeaf().getLine(), ErrorType.i));
        }
        return children;
    }

    // [Exp] ';' // i ==> Exp;, ;, Exp(i)
    // LVal '=' Exp ';' // i
    // LVal '=' 'getint''('')'';' // i j
    // LVal '=' 'getchar''('')'';' // i j
    public ArrayList<SynNode> parseHead() {
        ArrayList<SynNode> children = new ArrayList<>();
        ExpParser expParser = new ExpParser(lexer);
        SynNode root = expParser.parse();
        updateError(expParser.getErrorList());
        root = analyseExpLVal(root);
        if (root.getType() != SynType.EMPTY) {
            children.add(root);
        }
        if (root.getType() == SynType.LVal) {
            children.add(new SynLeaf(lexer.getAndNext())); // =
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.GETCHARTK || t.getType() == TokenType.GETINTTK) {
                children.add(new SynLeaf(t));
                children.add(new SynLeaf(lexer.getAndNext())); // (
                t = lexer.getAndNext();
                if (t.getType() == TokenType.RPARENT) { // )
                    children.add(new SynLeaf(t));
                } else {
                    lexer.move(-1);
                    addError(new ErrorSyntax(children.get(1).getLeaf().getLine(), ErrorType.j));
                }
                t = lexer.getAndNext();
                if (t.getType() == TokenType.SEMICN) {
                    children.add(new SynLeaf(t));
                } else {
                    lexer.move(-1);
                    addError(new ErrorSyntax(children.get(1).getLeaf().getLine(), ErrorType.i));
                }
            } else { // Exp; // i
                lexer.move(-1);
                ExpParser expParser2 = new ExpParser(lexer);
                children.add(expParser2.parse());
                updateError(expParser2.getErrorList());
                t = lexer.getAndNext();
                if (t.getType() == TokenType.SEMICN) {
                    children.add(new SynLeaf(t));
                } else {
                    lexer.move(-1);
                    addError(new ErrorSyntax(children.get(1).getLeaf().getLine(), ErrorType.i));
                }
            }
        } else { // Exp(done) ; // i
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.SEMICN) {
                children.add(new SynLeaf(t));
            } else {
                lexer.move(-2);
                addError(new ErrorSyntax(lexer.get().getLine(), ErrorType.i));
                lexer.move(1);
            }
        }
        return children;
    }

    // differ LVal & Exp
    /*
        Exp -> AddExp -> MulExp -> UnaryExp -> PrimaryExp -> LVal
     */
    public SynNode analyseExpLVal(SynNode root) {
        ArrayList<SynNode> children = root.getChildren();
        if (children.size() == 1 && children.get(0).getType() == SynType.AddExp) {
            children = children.get(0).getChildren();
        } else {
            return root;
        }
        if (children.size() == 1 && children.get(0).getType() == SynType.MulExp) {
            children = children.get(0).getChildren();
        } else {
            return root;
        }
        if (children.size() == 1 && children.get(0).getType() == SynType.UnaryExp) {
            children = children.get(0).getChildren();
        } else {
            return root;
        }
        if (children.size() == 1 && children.get(0).getType() == SynType.PrimaryExp) {
            children = children.get(0).getChildren();
        } else {
            return root;
        }
        Token t = lexer.get();
        if (children.size() == 1 && children.get(0).getType() == SynType.LVal && t.getType() == TokenType.ASSIGN) {
            return children.get(0);
        } else if (children.size() == 1 && children.get(0).getType() == SynType.EMPTY) {
            return children.get(0);
        } else {
            return root;
        }
    }
}

/**
 * 语句块 Block → '{' { BlockItem } '}'
 * 语句块项 BlockItem → Decl | Stmt
 * 语句 Stmt →
 * LVal '=' Exp ';' // i
 * | [Exp] ';' // i ==> Exp;, ;, Exp(i)
 * | Block  /sim FIRST ~ '{'
 * | 'if' '(' Cond ')' Stmt [ 'else' Stmt ] // j
 * | 'for' '(' [ForStmt] ';' [Cond] ';' [ForStmt] ')' Stmt
 * | 'break' ';' | 'continue' ';' // i
 * | 'return' [Exp] ';' // i
 * | LVal '=' 'getint''('')'';' // i j
 * | LVal '=' 'getchar''('')'';' // i j
 * | 'printf''('StringConst {','Exp}')'';' // i j
 *
 * 条件表达式 Cond → LOrExp
 *
 * 核心为区分LVal & Exp, 可以直接当成EXP去匹配，对因为有推导Exp ==> LVal，
 * 对于返回结果递归搜索树，判断是否为LVal，视情况砍树重构为LVal结构即可
 */