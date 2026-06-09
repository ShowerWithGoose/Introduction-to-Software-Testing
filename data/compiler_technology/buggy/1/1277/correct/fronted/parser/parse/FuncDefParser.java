package fronted.parser.parse;

import config.ErrorType;
import fronted.lexer.Lexer;
import fronted.lexer.Token;
import fronted.lexer.TokenType;
import fronted.parser.syntax.*;

import java.util.ArrayList;

public class FuncDefParser extends Parser {
    private final Lexer lexer;
    public FuncDefParser(Lexer lexer) {
        this.lexer = lexer;
    }

    // FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
    @Override
    public SynNode parse() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseFuncType());
        children.add(new SynLeaf(lexer.getAndNext())); // ident
        children.add(new SynLeaf(lexer.getAndNext())); // (
        Token t = lexer.getAndNext();
        lexer.move(-1);
        if (t.getType() == TokenType.INTTK || t.getType() == TokenType.CHARTK) { // FuncFParams
            children.add(parseFuncFParams());
        }
        t = lexer.getAndNext();
        if (t.getType() == TokenType.RPARENT) {
            children.add(new SynLeaf(t));
        } else {
            addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.j));
            lexer.move(-1);
        }
        children.add(parseBlock());
        return new SynNonLeaf(SynType.FuncDef, children);
    }

    // FuncType → 'void' | 'int' | 'char'
    public SynNode parseFuncType() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext()));
        return new SynNonLeaf(SynType.FuncType, children);
    }

    // FuncFParams → FuncFParam { ',' FuncFParam }
    public SynNode parseFuncFParams() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseFuncFParam());
        while(lexer.hasNext()) {
            Token t = lexer.getAndNext();
            if (t.getType() == TokenType.COMMA) {
                children.add(new SynLeaf(t));
                children.add(parseFuncFParam());
            } else {
                lexer.move(-1);
                break;
            }
        }
        return new SynNonLeaf(SynType.FuncFParams, children);
    }

    // 函数形参 FuncFParam → BType Ident ['[' ']'] // k
    public SynNode parseFuncFParam() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(parseBType());
        children.add(new SynLeaf(lexer.getAndNext())); // Ident
        Token t = lexer.getAndNext();
        if (t.getType() == TokenType.LBRACK) {
            children.add(new SynLeaf(t));
            t = lexer.getAndNext();
            if (t.getType() == TokenType.RBRACK) {
                children.add(new SynLeaf(t));
            } else {
                lexer.move(-1);
                addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.k));
            }
        } else {
            lexer.move(-1);
        }
        return new SynNonLeaf(SynType.FuncFParam, children);
    }

    public SynNode parseBlock() {
        BlockParser bp = new BlockParser(lexer);
        SynNode node = bp.parse();
        updateError(bp.getErrorList());
        return node;
    }

    public SynNode parseBType() {
        DeclParser dp = new DeclParser(lexer);
        SynNode node = dp.parseBType();
        updateError(dp.getErrorList());
        return node;
    }
}

/**
 * 函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block // j
 *
 * 函数类型 FuncType → 'void' | 'int' | 'char'
 *
 * 函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
 *
 * 函数形参 FuncFParam → BType Ident ['[' ']'] // k
 */