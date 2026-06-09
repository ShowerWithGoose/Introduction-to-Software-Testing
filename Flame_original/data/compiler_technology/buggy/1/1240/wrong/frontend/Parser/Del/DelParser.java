package frontend.Parser.Del;

import frontend.Error;
import frontend.Lexer.LexType;
import frontend.Lexer.TokenList;
import frontend.Parser.Del.Type.Decl;
import frontend.Parser.Del.Type.Def;
import frontend.Parser.Del.Type.InitVal;
import frontend.Parser.Del.Type.Var;
import frontend.Parser.Exp.ExpParser;
import frontend.Parser.Exp.Type.Exp;
import frontend.Parser.Exp.Type.constExp;

import java.util.ArrayList;
import java.util.List;

public class DelParser {
    private final TokenList tokens;
    private final Error errorLog;

    public DelParser(TokenList tokenList, Error errorLog) {
        this.tokens = tokenList;
        this.errorLog = errorLog;
    }

    // Decl → ConstDecl | VarDecl
    // 常量声明 ConstDecl → 'const' BType ConstDef { ',' ConstDef } ';'
    // 变量声明 VarDecl → BType VarDef { ',' VarDef } ';'
    public Decl parseDecl() {
        LexType constToken = tokens.getToken();
        boolean isConst = false;
        if (constToken.getType() == LexType.TokenType.CONSTTK) {
            constToken = tokens.getAndMove();
            isConst = true;
        } else {
            constToken = null;
        }
        LexType Btype = tokens.getAndMove();
        ArrayList<Def> defs = new ArrayList<>();
        ArrayList<LexType> pauses = new ArrayList<>();
        Def def = parseDef(isConst);
        defs.add(def);
        LexType pause = tokens.getAndMove();
        while (pause.getType() == LexType.TokenType.COMMA) {
            pauses.add(pause);
            defs.add(parseDef(isConst));
            pause = tokens.getAndMove();
        }
        if (pause.getType() == LexType.TokenType.SEMICN) {
            return new Decl(constToken, Btype, pauses, defs, pause);
        } else {
            errorLog.add(tokens.getlastToken(2).getLine(), 'i');
            tokens.retreat(1);
            return new Decl(constToken, Btype, pauses, defs, null);
        }
    }

    // 常数定义 ConstDef → Var '=' ConstInitVal
    // 变量定义 VarDef → Var | Var '=' InitVal
    public Def parseDef(boolean isConst) {
        Var var = parseVar();
        LexType assign = tokens.getAndMove();
        if (assign.getType() == LexType.TokenType.ASSIGN) {
            return new Def(var, assign, parseInitVal(isConst), isConst);
        }
        tokens.retreat(1);
        return new Def(var);
    }

    // 常量变量 Var -> Ident [ '[' ConstExp ']' ]
    public Var parseVar() {
        LexType ident = tokens.getAndMove();
        ArrayList<LexType> braces = new ArrayList<>();
        LexType left = tokens.getAndMove();
        constExp constexp = null;
        if (left.getType() == LexType.TokenType.LBRACK) {
            constexp = new ExpParser(tokens, errorLog).parserConstExp();
            braces.add(left);
            LexType right = tokens.getAndMove();
            if (right.getType() != LexType.TokenType.RBRACK) {
                errorLog.add(tokens.getlastToken(2).getLine(), 'k');
                right = null;
                tokens.retreat(1);
            }
            braces.add(right);
        } else {
            tokens.retreat(1);
        }
        return new Var(ident, constexp, braces);
    }

    // ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    // InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public InitVal parseInitVal(boolean isConst) {
        LexType token = tokens.getAndMove();
        // 处理字符串常量
        if (token.getType() == LexType.TokenType.STRCON) {
            return new InitVal(token, isConst);
        }
        // 处理大括号初始化
        else if (token.getType() == LexType.TokenType.LBRACE) {
            return parseBraceInitVal(isConst, token);
        }
        // 处理普通表达式或常量表达式
        else {
            tokens.retreat(1); // 回退一个 token
            return isConst ? new InitVal(parseConstExps()) : new InitVal(parseExps());
        }
    }

    // 处理大括号内的初始化值
    private InitVal parseBraceInitVal(boolean isConst, LexType token) {
        ArrayList<LexType> pauses = new ArrayList<>();
        // 检查是否为闭合大括号
        if (tokens.getToken().getType() == LexType.TokenType.RBRACE) {
            LexType right = tokens.getAndMove(); // 移动到右大括号
            ArrayList<constExp> constExps = new ArrayList<>();
            List<Exp> exps = new ArrayList<>();
            return isConst ? new InitVal(token, constExps, null, right)
                    : new InitVal(token, exps, null, right);
        } else {
            // 解析大括号中的表达式
            return isConst ? new InitVal(token, parseConstExps(pauses), pauses, tokens.getAndMove())
                    : new InitVal(token, parseExps(pauses), pauses, tokens.getAndMove());
        }
    }

    // 解析常量表达式并记录分隔符
    private ArrayList<constExp> parseConstExps(ArrayList<LexType> pauses) {
        ArrayList<constExp> constExps = new ArrayList<>();
        constExp constExp = new ExpParser(tokens, errorLog).parserConstExp();
        constExps.add(constExp);
        // 继续解析直到遇到右大括号
        while (tokens.getToken().getType() != LexType.TokenType.RBRACE) {
            pauses.add(tokens.getAndMove()); // 记录分隔符
            constExp = new ExpParser(tokens, errorLog).parserConstExp();
            constExps.add(constExp);
        }
        return constExps;
    }

    // 解析普通表达式并记录分隔符
    private List<Exp> parseExps(ArrayList<LexType> pauses) {
        List<Exp> exps = new ArrayList<>();
        Exp exp = new ExpParser(tokens, errorLog).parserExp();
        exps.add(exp);
        // 继续解析直到遇到右大括号
        while (tokens.getToken().getType() != LexType.TokenType.RBRACE) {
            pauses.add(tokens.getAndMove()); // 记录分隔符
            exp = new ExpParser(tokens, errorLog).parserExp();
            exps.add(exp);
        }
        return exps;
    }

    // 解析单个常量表达式
    private ArrayList<constExp> parseConstExps() {
        ArrayList<constExp> constExps = new ArrayList<>();
        constExps.add(new ExpParser(tokens, errorLog).parserConstExp());
        return constExps;
    }

    // 解析单个普通表达式
    private List<Exp> parseExps() {
        List<Exp> exps = new ArrayList<>();
        exps.add(new ExpParser(tokens, errorLog).parserExp());
        return exps;
    }

}
