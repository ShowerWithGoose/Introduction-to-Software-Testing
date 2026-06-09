package frontend.Parser.Func;

import frontend.Error;
import frontend.Lexer.LexType;
import frontend.Lexer.TokenList;
import frontend.Parser.Func.Type.FuncDef;
import frontend.Parser.Func.Type.FuncFParam;
import frontend.Parser.Func.Type.MainFuncDef;
import frontend.Parser.Stmt.StmtParser;

import java.util.ArrayList;

public class FuncParser {
    /*
        函数定义 FuncDef → FuncType Ident '(' [FuncFParams] ')' Block
        主函数定义 MainFuncDef → 'int' 'main' '(' ')' Block

        函数类型 FuncType → 'void' | 'int' | 'char'

        函数形参表 FuncFParams → FuncFParam { ',' FuncFParam }
        函数形参 FuncFParam → BType Ident ['[' ']']
    */
    private TokenList tokens;
    private Error errorLog;

    public FuncParser(TokenList tokens, Error errorLog)
    {
        this.tokens = tokens;
        this.errorLog = errorLog;
    }

    // FuncDef → FuncType Ident '(' [FuncFParam { ',' FuncFParam }] ')' Block
    public FuncDef parseFuncDef() {
        LexType funcType = tokens.getAndMove();
        LexType ident = tokens.getAndMove();
        ArrayList<FuncFParam> funcFParams = new ArrayList<>();
        LexType left = tokens.getAndMove();
        LexType right = tokens.getToken();
        ArrayList<LexType> seps = new ArrayList<>();
        if (right.getType() == LexType.TokenType.INTTK ||
                right.getType() == LexType.TokenType.CHARTK) {
            funcFParams.add(parseFuncFParam());
            while (tokens.getToken().getType() == LexType.TokenType.COMMA) {
                seps.add(tokens.getAndMove());
                funcFParams.add(parseFuncFParam());
            }
            right = null;
            if (tokens.getToken().getType() != LexType.TokenType.RPARENT) {
                errorLog.add(tokens.getlastToken(1).getLine(), 'j');
            }else {
                right = tokens.getAndMove();
            }
        } else if (right.getType() == LexType.TokenType.RPARENT) {
            right = tokens.getAndMove();
        } else {
            errorLog.add(left.getLine(), 'j');
            right = null;
        }
        return new FuncDef(funcType, ident, left, funcFParams, right,
                new StmtParser(tokens, errorLog).parseBlockStmt() ,seps);
    }

    public MainFuncDef parseMainFuncDef() {
        return new MainFuncDef(parseFuncDef());
    }

    // FuncFParam → BType Ident ['[' ']']
    public FuncFParam parseFuncFParam() {
        LexType BType = tokens.getAndMove();
        LexType ident = tokens.getAndMove();
        LexType token = tokens.getToken();
        ArrayList<LexType> braces = new ArrayList<>();
        if (token.getType() == LexType.TokenType.LBRACK) {
            braces.add(tokens.getAndMove());
            if (tokens.getToken().getType() == LexType.TokenType.RBRACK) {
                braces.add(tokens.getAndMove());
            } else {
                errorLog.add(token.getLine(), 'k');
                braces.add(null);
            }
        }
        return new FuncFParam(BType, ident, braces);
    }
}
