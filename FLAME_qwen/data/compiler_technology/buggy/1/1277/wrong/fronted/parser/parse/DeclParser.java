package fronted.parser.parse;

import config.ErrorType;
import fronted.lexer.Lexer;
import fronted.lexer.Token;
import fronted.lexer.TokenType;
import fronted.parser.syntax.*;

import java.util.ArrayList;

public class DeclParser extends Parser {
    private final Lexer lexer;
    public DeclParser(Lexer lexer) {
        this.lexer = lexer;
    }

    @Override
    public SynNode parse() {
        // pre-read const
        Token token = lexer.getAndNext();
        lexer.move(-1);
        if (token.getType() == TokenType.CONSTTK) {
            return parseConstDecl();
        } else {
            return parseValDecl();
        }
    }

    // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
    private SynNode parseConstDecl() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext()));
        children.add(parseBType());
        children.add(parseConstDef());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.COMMA) { // COMMA is ','
                children.add(new SynLeaf(t));
                children.add(parseConstDef());
            } else {
                lexer.move(-1);
                break;
            }
        }
        // might error
        if (lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.SEMICN) { // ;
                children.add(new SynLeaf(t));
            } else { // error
                lexer.move(-1);
                super.addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.i));
            }
        } else {
            super.addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.i));
        }
        return new SynNonLeaf(SynType.ConstDecl, children);
    }


    // 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
    private SynNode parseConstDef() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext())); // IDENTIFY

        Token t = lexer.getAndNext();
        children.add(new SynLeaf(t)); // '[' or '='
        if (t.getType() == TokenType.LBRACK) { // '['
            children.add(parseConstExp());
            Token tmp = lexer.getAndNext(); // ']' or '='
            if (tmp.getType() == TokenType.RBRACK) {
                children.add(new SynLeaf(tmp)); // add ']'
                children.add(new SynLeaf(lexer.getAndNext())); // add '='
            } else { // error
                children.add(new SynLeaf(tmp)); // add '='
                super.addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.k));
            }
        }
        children.add(parseConstInitVal());
        return new SynNonLeaf(SynType.ConstDef, children);
    }

    // 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    private SynNode parseConstInitVal() {
        Token t = lexer.getAndNext();
        ArrayList<SynNode> children = new ArrayList<>();
        if (t.getType() == TokenType.LBRACE) {
            children.add(new SynLeaf(t)); // '{'
            Token next = lexer.getAndNext();
            if (next.getType() == TokenType.RBRACE) {
                children.add(new SynLeaf(next));
            } else {
                lexer.move(-1);
                children.add(parseConstExp());
                next = lexer.getAndNext();
                while (next.getType() == TokenType.COMMA) { // {','}
                    children.add(new SynLeaf(next));
                    children.add(parseConstExp());
                    next = lexer.getAndNext();
                } // else: '}'
                children.add(new SynLeaf(next));
            }
        } else if (t.getType() == TokenType.STRCON) {
            children.add(new SynLeaf(t));
        } else { // ConstExp
            lexer.move(-1);
            children.add(parseConstExp());
        }
        return new SynNonLeaf(SynType.ConstInitVal, children);
    }

    // VarDecl → BType VarDef { ',' VarDef } ';' // i
    private SynNode parseValDecl() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseBType());
        children.add(parseValDef());
        Token t = lexer.getAndNext();
        while(t.getType() == TokenType.COMMA) {
            children.add(new SynLeaf(t));
            children.add(parseValDef());
            if (lexer.hasNext()) {
                t = lexer.getAndNext();
            } else {
                t = lexer.get();
                break;
            }
        } // out: ';'
        if (t.getType() == TokenType.SEMICN) {
            children.add(new SynLeaf(t));
        } else {
            super.addError(new ErrorSyntax(children.get(0).getChildren().get(0).getLine(), ErrorType.i));
            lexer.move(-1);
        }
        return new SynNonLeaf(SynType.VarDecl, children);
    }

    // VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
    private SynNode parseValDef() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext())); // Ident
        Token t = lexer.getAndNext();
        if (t.getType() == TokenType.LBRACK) { // might have
            children.add(new SynLeaf(t));
            children.add(parseConstExp());
            Token rt = lexer.getAndNext();
            if (rt.getType() == TokenType.RBRACK) {
                children.add(new SynLeaf(rt));
            } else {
                lexer.move(-1);
                addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.k));
            }
        } else {
            lexer.move(-1);
        }

        t = lexer.getAndNext();
        if (t.getType() == TokenType.ASSIGN) {
            children.add(new SynLeaf(t));
            children.add(parseInitVal());
        } else {
            lexer.move(-1);
        }

        return new SynNonLeaf(SynType.VarDef, children);
    }

    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    private SynNode parseInitVal() {
        ArrayList<SynNode> children = new ArrayList<>();
        Token t = lexer.getAndNext();
        if (t.getType() == TokenType.STRCON) {
            children.add(new SynLeaf(t));
        } else if (t.getType() == TokenType.LBRACE) {
            children.add(new SynLeaf(t));
            Token next = lexer.getAndNext();
            if (next.getType() == TokenType.RBRACE) { // '}'
                children.add(new SynLeaf(next));
            } else { // EXP {',' EXP} '}'
                lexer.move(-1);
                children.add(parseExp());
                next = lexer.getAndNext();
                while (next.getType() == TokenType.COMMA) {
                    children.add(new SynLeaf(next));
                    children.add(parseExp());
                    if (lexer.hasNext()) {
                        next = lexer.getAndNext();
                    } else {
                        break;
                    }
                } // out '}'
                children.add(new SynLeaf(next));
            }
        } else {
            lexer.move(-1);
            children.add(parseExp());
        }
        return new SynNonLeaf(SynType.InitVal, children);
    }

    // BType → 'int' | 'char'
    public SynNode parseBType() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext()));
        return new SynNonLeaf(SynType.BType, children);
    }

    private SynNode parseConstExp() {
        ExpParser expParser = new ExpParser(lexer);
        SynNode node = expParser.parseConstExp();
        updateError(expParser.getErrorList());
        return node;
    }

    private SynNode parseExp() {
        ExpParser expParser = new ExpParser(lexer);
        SynNode node = expParser.parse();
        updateError(expParser.getErrorList());
        return node;
    }
}

/**
 * 声明 Decl → ConstDecl | VarDecl
 * 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';' // i
 * 基本类型 BType → 'int' | 'char'
 * 常量定义 ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal // k
 * 常量初值 ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
 * 变量声明 VarDecl → BType VarDef { ',' VarDef } ';' // i
 * 变量定义 VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal // k
 * 变量初值 InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
 */