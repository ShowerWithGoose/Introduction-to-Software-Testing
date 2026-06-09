package frontend.Parser.Exp;

import frontend.Error;
import frontend.Lexer.LexType;
import frontend.Lexer.TokenList;
import frontend.Parser.Exp.Type.*;
import frontend.Parser.Exp.Type.SameExp.*;
import frontend.Parser.Exp.Type.Character;
import frontend.Parser.Exp.Type.Number;

import java.util.ArrayList;

public class ExpParser {
    private final TokenList tokens;
    private final Error errorLog;

    public ExpParser(TokenList tokens, Error errorLog) {
        this.tokens = tokens;
        this.errorLog = errorLog;
    }

    // LVal → Ident ['[' Exp ']']
    public LVal parserLVal() {
        LexType now = tokens.getAndMove();
        LexType next = tokens.getToken();
        if (next.getType() != LexType.TokenType.LBRACK) {
            return new LVal(now, null, null);
        }
        ArrayList<LexType> brace = new ArrayList<>();
        brace.add(tokens.getAndMove());
        Exp exp = parserExp();
        if (tokens.getToken().getType() == LexType.TokenType.RBRACK) {
            brace.add(tokens.getAndMove());
        } else {
            errorLog.add(tokens.getlastToken(1).getLine(), 'k');
            brace.add(null);
        }
        return new LVal(now, exp, brace);
    }

    // Exp --> AddExp
    public Exp parserExp() {
        return new Exp(parserAddExp());
    }

    // constExp --> AddExp
    public constExp parserConstExp() {
        return new constExp(parserAddExp());
    }

    // AddExp → MulExp {('+' | '−') MulExp}
    public AddExp parserAddExp() {
        ArrayList<MulExp> exps = new ArrayList<>();
        MulExp mulExp = parseMulExp();
        exps.add(mulExp);
        ArrayList<LexType> ops = new ArrayList<>();
        LexType token = tokens.getToken();
        while (token.getType() == LexType.TokenType.PLUS ||
                token.getType() == LexType.TokenType.MINU) {
            ops.add(tokens.getAndMove());
            exps.add(parseMulExp());
            token = tokens.getToken();
        }
        return new AddExp(exps, ops);
    }

    // MulExp → UnaryExp {('*' | '/' | '%') UnaryExp}
    public MulExp parseMulExp() {
        ArrayList<UnaryExp> exps = new ArrayList<>();
        UnaryExp unaryExp = parseUnaryExp();
        exps.add(unaryExp);
        ArrayList<LexType> ops = new ArrayList<>();
        LexType token = tokens.getToken();
        while (token.getType() == LexType.TokenType.MULT ||
                token.getType() == LexType.TokenType.DIV ||
                token.getType() == LexType.TokenType.MOD) {
            ops.add(tokens.getAndMove());
            exps.add(parseUnaryExp());
            token = tokens.getToken();
        }
        return new MulExp(exps, ops);
    }

    // UnaryExp → PrimaryExp | FuncExp | UnaryOp UnaryExp
    public UnaryExp parseUnaryExp() {
        LexType token = tokens.getToken();
        if (token.getType() == LexType.TokenType.PLUS ||
                token.getType() == LexType.TokenType.MINU ||
                token.getType() == LexType.TokenType.NOT) {
            UnaryOp unaryOp = new UnaryOp(tokens.getAndMove());
            return new UnaryExp(unaryOp, parseUnaryExp());
        }
        if (tokens.getToken().getType() == LexType.TokenType.IDENFR) {
            tokens.forward(1);
            token = tokens.getToken();
            tokens.retreat(1);
            if (token.getType() == LexType.TokenType.LPARENT) {
                return new UnaryExp(null, parseFuncExp());
            }
        }
        return new UnaryExp(null, parsePrimaryExp());
    }

    // PrimaryExp → BraceExp | LVal | Number | Character
    public PrimaryExp parsePrimaryExp() {
        LexType token = tokens.getToken();
        if (token.getType() == LexType.TokenType.LPARENT) {
            return new PrimaryExp(parseBraceExp());
        } else if (token.getType() == LexType.TokenType.IDENFR) {
            return new PrimaryExp(parserLVal());
        } else if (token.getType() == LexType.TokenType.INTCON) {
            return new PrimaryExp(parseNumber());
        } else if (token.getType() == LexType.TokenType.CHRCON) {
            return new PrimaryExp(parseChar());
        } else {
            System.out.println("error");
            return null;
        }
    }

    // BraceExp -> '(' Exp ')'
    public BraceExp parseBraceExp() {
        LexType token = tokens.getAndMove();
        Exp exp = parserExp();
        LexType next = tokens.getAndMove();
        if (next.getType() != LexType.TokenType.RPARENT) {
            errorLog.add(tokens.getlastToken(2).getLine(), 'j');
            next = null;
            tokens.retreat(1);
        }
        return new BraceExp(token, exp, next);
    }

    // Number → IntConst
    public Number parseNumber() {
        return new Number(tokens.getAndMove());
    }

    // Character → CharConst
    public Character parseChar() {
        return new Character(tokens.getAndMove());
    }

    // FuncExp --> Ident '(' [FuncRParams] ')'
    public FuncExp parseFuncExp() {
        LexType ident = tokens.getAndMove();
        LexType left = tokens.getAndMove();
        LexType token = tokens.getToken();
        if (token.getType() == LexType.TokenType.RPARENT) {
            token = tokens.getAndMove();
            return new FuncExp(ident, left, null, token);
        } else {
            if (token.isFirstExp()) {
                FuncRParams params = parseFuncRParams();
                LexType right = tokens.getAndMove();
                if (right.getType() != LexType.TokenType.RPARENT) {
                    errorLog.add(tokens.getlastToken(2).getLine(), 'j');
                    right = null;
                    tokens.retreat(1);
                }
                return new FuncExp(ident, left, params, right);
            } else {
                //错误处理
                errorLog.add(tokens.getlastToken(1).getLine(), 'j');
                return new FuncExp(ident, left, null, null);
            }
        }
    }

    // FuncRParams → Exp { ',' Exp }
    public FuncRParams parseFuncRParams() {
        ArrayList<Exp> exps = new ArrayList<>();
        Exp exp = parserExp();
        exps.add(exp);
        ArrayList<LexType> ops = new ArrayList<>();
        LexType token = tokens.getToken();
        while (token.getType() == LexType.TokenType.COMMA) {
            ops.add(tokens.getAndMove());
            exps.add(parserExp());
            token = tokens.getToken();
        }
        return new FuncRParams(exps, ops);
    }

    // Cond → LOrExp
    public Cond parseCond() {
        return new Cond(parseLOrExp());
    }

    // LOrExp → LAndExp { '||' LAndExp }
    public LOrExp parseLOrExp() {
        ArrayList<LAndExp> exps = new ArrayList<>();
        LAndExp exp = parseLAndExp();
        exps.add(exp);
        ArrayList<LexType> ops = new ArrayList<>();
        LexType token = tokens.getToken();
        while (token.getType() == LexType.TokenType.OR) {
            ops.add(tokens.getAndMove());
            exps.add(parseLAndExp());
            token = tokens.getToken();
        }
        return new LOrExp(exps, ops);
    }

    // LAndExp → EqExp {'&&' EqExp}
    public LAndExp parseLAndExp() {
        ArrayList<EqExp> exps = new ArrayList<>();
        EqExp exp = parseEqExp();
        exps.add(exp);
        ArrayList<LexType> ops = new ArrayList<>();
        LexType token = tokens.getToken();
        while (token.getType() == LexType.TokenType.AND) {
            ops.add(tokens.getAndMove());
            exps.add(parseEqExp());
            token = tokens.getToken();
        }
        return new LAndExp(exps, ops);
    }

    // EqExp → RelExp {('==' | '!=') RelExp}
    public EqExp parseEqExp() {
        ArrayList<RelExp> exps = new ArrayList<>();
        RelExp exp = parseRelExp();
        exps.add(exp);
        ArrayList<LexType> ops = new ArrayList<>();
        LexType token = tokens.getToken();
        while (token.getType() == LexType.TokenType.EQL ||
                token.getType() == LexType.TokenType.NEQ) {
            ops.add(tokens.getAndMove());
            exps.add(parseRelExp());
            token = tokens.getToken();
        }
        return new EqExp(exps, ops);
    }

    // RelExp → AddExp {('<' | '<=' | '>' | '>=') AddExp}
    public RelExp parseRelExp() {
        ArrayList<AddExp> exps = new ArrayList<>();
        AddExp exp = parserAddExp();
        exps.add(exp);
        ArrayList<LexType> ops = new ArrayList<>();
        LexType token = tokens.getToken();
        while (token.getType() == LexType.TokenType.LSS ||
                token.getType() == LexType.TokenType.LEQ ||
                token.getType() == LexType.TokenType.GRE ||
                token.getType() == LexType.TokenType.GEQ) {
            ops.add(tokens.getAndMove());
            exps.add(parserAddExp());
            token = tokens.getToken();
        }
        return new RelExp(exps, ops);
    }
}
