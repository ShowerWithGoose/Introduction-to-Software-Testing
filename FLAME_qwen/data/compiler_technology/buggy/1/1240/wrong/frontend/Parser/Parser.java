package frontend.Parser;

import frontend.Error;
import frontend.Lexer.LexType;
import frontend.Lexer.TokenList;
import frontend.Parser.Del.DelParser;
import frontend.Parser.Del.Type.Decl;
import frontend.Parser.Func.FuncParser;
import frontend.Parser.Func.Type.FuncDef;
import frontend.Parser.Func.Type.MainFuncDef;

import java.util.ArrayList;

public class Parser {
    // CompUnit â†’ {Decl} {FuncDef} MainFuncDef
    private TokenList tokens;
    private Error errorLog;

    public Parser(TokenList tokens){
        this.tokens = tokens;
        this.errorLog = new Error();
    }

    public Error getErrorLog()
    {
        return errorLog;
    }

    public CompUnit parseCompUnit() {
        LexType first = tokens.getAndMove();
        LexType second = tokens.getToken();
        tokens.retreat(1);
        ArrayList<Decl> decls = new ArrayList<>();
        while (!tokens.isEnd()) {
            if (isDeclStart(first, second)) {
                decls.add(new DelParser(tokens, errorLog).parseDecl());
            } else {
                break;
            }
            first = tokens.getAndMove();
            second = tokens.getToken();
            tokens.retreat(1);
        }
        MainFuncDef mainFunction = null;
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        while (!tokens.isEnd()) {
            if (isMainFuncStart(first, second)) {
                mainFunction = new FuncParser(tokens, errorLog).parseMainFuncDef();
                break;
            } else {
                funcDefs.add(new FuncParser(tokens, errorLog).parseFuncDef());
            }
            first = tokens.getAndMove();
            second = tokens.getToken();
            tokens.retreat(1);
        }
        return new CompUnit(decls, funcDefs, mainFunction);
    }

    private boolean isDeclStart(LexType first, LexType second) {
        tokens.forward(2);
        LexType third = tokens.getToken();
        tokens.retreat(2);
        return (first.getType() == LexType.TokenType.CONSTTK &&
                (second.getType() == LexType.TokenType.INTTK || second.getType() == LexType.TokenType.CHARTK)) ||
                ((first.getType() == LexType.TokenType.INTTK || first.getType() == LexType.TokenType.CHARTK) &&
                        second.getType() == LexType.TokenType.IDENFR &&
                        third.getType() != LexType.TokenType.LPARENT);
    }

    private boolean isMainFuncStart(LexType first, LexType second) {
        return first.getType() == LexType.TokenType.INTTK && second.getType() == LexType.TokenType.MAINTK;
    }
}
