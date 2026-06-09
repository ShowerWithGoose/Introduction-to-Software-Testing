package fronted.parser.parse;

import config.ErrorType;
import fronted.lexer.Lexer;
import fronted.lexer.Token;
import fronted.lexer.TokenType;
import fronted.parser.syntax.*;

import java.util.ArrayList;

public class CompileUnitParser extends Parser {
    private final Lexer lexer;
    public CompileUnitParser(Lexer lexer) {
        this.lexer = lexer;
    }

    @Override
    public SynNode parse() {
        // CompUnit â†’ {Decl} {FuncDef} MainFuncDef
        ArrayList<SynNode> decls = parseDecl();

        ArrayList<SynNode> funcs = parseFunc();

        SynNode mainFuncDef = parseMain();

        // merge
        for (SynNode func : funcs) {
            decls.add(func);
        }
        decls.add(mainFuncDef);

        return new SynNonLeaf(SynType.CompUnit, decls);
    }

    /**
     * if found (int main()) or (type IDENTIDIFIER ( )
     * @return
     */
    private ArrayList<SynNode> parseDecl() {
        ArrayList<SynNode> res = new ArrayList<>();
        while (true) {
            Token t = null;
            for (int i = 0; i < 3; i++) { // pre-read
                if (lexer.hasNext()) {
                    t = lexer.getAndNext();
                } else {
                    lexer.move(-i);
                    break;
                }
            }
            lexer.move(-3);
            if (t == null || t.getType() == TokenType.LPARENT) {
                break;
            }
            // must a Decl
            DeclParser declParser = new DeclParser(lexer);
            res.add(declParser.parse());
            updateError(declParser.getErrorList());
        }
        return res;
    }

    private ArrayList<SynNode> parseFunc() {
        ArrayList<SynNode> res = new ArrayList<>();
        while(true) {
            Token t = null;
            for (int i = 0; i < 2; i++) { // pre-read
                if (lexer.hasNext()) {
                    t = lexer.getAndNext();
                } else {
                    lexer.move(-i);
                    break;
                }
            }
            lexer.move(-2);
            if (t.getType() == TokenType.MAINTK) {
                break;
            } else {
                // must a FuncDef
                FuncDefParser funcDefParser = new FuncDefParser(lexer);
                res.add(funcDefParser.parse());
                updateError(funcDefParser.getErrorList());
            }
        }
        return res;
    }

    // int main ( ) Block
    private SynNode parseMain() {
        ArrayList<SynNode> children = new ArrayList<>();
        children.add(new SynLeaf(lexer.getAndNext())); // int
        children.add(new SynLeaf(lexer.getAndNext())); // main
        children.add(new SynLeaf(lexer.getAndNext())); // (
        Token t = lexer.get();
        if (t.getType() == TokenType.RPARENT) {
            children.add(new SynLeaf(t)); // )
            lexer.move(1);
        } else {
            addError(new ErrorSyntax(children.get(0).getLine(), ErrorType.j));
        }
        BlockParser bp = new BlockParser(lexer);
        children.add(bp.parse());
        updateError(bp.getErrorList());
        return new SynNonLeaf(SynType.MainFuncDef, children);
    }
}
