package frontend;

import frontend.AST.Exp.Character;
import frontend.AST.Exp.Number;
import frontend.AST.Exp.*;
import frontend.AST.Func.FuncRParams;

import java.util.ArrayList;

public class TryParser {
    private final TokenList tokens;

    public TryParser(TokenList tokens) {
        this.tokens = tokens;
    }

    // Exp → AddExp
    public Exp tryParseExp() {
        AddExp addExp = tryParseAddExp();
        if (addExp != null) {
            return new Exp(addExp);
        } else {
            return null;
        }
    }

    // AddExp → MulExp | AddExp ('+' | '−') MulExp
    public AddExp tryParseAddExp() {
        ArrayList<MulExp> mulExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        MulExp mulExp = tryParseMulExp();
        if (mulExp == null) {
            return null;
        }
        mulExps.add(mulExp);
        while (tokens.get().isOf(TokenType.PLUS, TokenType.MINU)) {
            ops.add(tokens.consume());
            mulExp = tryParseMulExp();
            if (mulExp == null) {
                return null;
            }
            mulExps.add(mulExp);
        }
        return new AddExp(mulExps, ops);
    }


    // MulExp → UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    public MulExp tryParseMulExp() {
        ArrayList<UnaryExp> unaryExps = new ArrayList<>();
        ArrayList<Token> ops = new ArrayList<>();
        UnaryExp unaryExp = tryParseUnaryExp();
        if (unaryExp == null) {
            return null;
        }
        unaryExps.add(unaryExp);
        while (tokens.get().isOf(TokenType.MULT, TokenType.DIV, TokenType.MOD)) {
            ops.add(tokens.consume());
            unaryExp = tryParseUnaryExp();
            if (unaryExp == null) {
                return null;
            }
            unaryExps.add(unaryExp);
        }
        return new MulExp(unaryExps, ops);
    }

    //  UnaryExp → PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    public UnaryExp tryParseUnaryExp() {
        if (tokens.get().isOf(TokenType.IDENFR)) {
            if (tokens.ahead(1).isOf(TokenType.LPARENT)) {
                Token ident = tokens.consumeExpect(TokenType.IDENFR);
                tokens.consumeExpect(TokenType.LPARENT);

                if (tokens.get().isOf(TokenType.RPARENT)) {
                    tokens.consume();
                    return new UnaryExp(ident);
                } else {
                    int index = tokens.getIndex();
                    Exp exp = tryParseExp();
                    if (exp == null) {
                        return new UnaryExp(ident);
                    } else {
                        if (tokens.get().isOf(TokenType.ASSIGN)) {
                            tokens.setIndex(index);
                            return new UnaryExp(ident);
                        } else {
                            tokens.setIndex(index);
                            FuncRParams funcRParams = tryParseFuncRParams();
                            if (funcRParams == null) {
                                return null;
                            }
                            tokens.consumeExpect(TokenType.RPARENT);
                            return new UnaryExp(ident, funcRParams);
                        }
                    }
                }
            } else {
                return new UnaryExp(tryParsePrimaryExp());
            }
        } else if (tokens.get().isOf(TokenType.LPARENT, TokenType.INTCON, TokenType.CHRCON)) {
            PrimaryExp primaryExp = tryParsePrimaryExp();
            if (primaryExp == null) {
                return null;
            }
            return new UnaryExp(primaryExp);
        } else if (tokens.get().isOf(TokenType.PLUS, TokenType.MINU, TokenType.NOT)) {
            UnaryOp unaryOp = tryParseUnaryOp();
            UnaryExp unaryExp = tryParseUnaryExp();
            if (unaryExp == null) {
                return null;
            }
            return new UnaryExp(unaryOp, unaryExp);
        } else {
            return null;
        }
    }

    // UnaryOp → '+' | '−' | '!'
    public UnaryOp tryParseUnaryOp() {
        if (tokens.consumeExpect(TokenType.PLUS, TokenType.MINU, TokenType.NOT) != null) {
            return new UnaryOp(tokens.get());
        }
        return null;
    }

    // PrimaryExp → '(' Exp ')' | LVal | Number | Character
    public PrimaryExp tryParsePrimaryExp() {
        switch (tokens.get().getType()) {
            case LPARENT -> {
                tokens.consume();
                Exp exp = tryParseExp();
                if (exp == null) {
                    return null;
                }
                tokens.consumeExpect(TokenType.RPARENT);
                return new PrimaryExp(exp);
            }
            case INTCON -> {
                Number number = tryParseNumber();
                if (number == null) {
                    return null;
                }
                return new PrimaryExp(number);
            }
            case CHRCON -> {
                Character character = tryParseCharacter();
                if (character == null) {
                    return null;
                }
                return new PrimaryExp(character);
            }
            case IDENFR -> {
                LVal lVal = tryParseLVal();
                if (lVal == null) {
                    return null;
                }
                return new PrimaryExp(lVal);
            }
            default -> {
                return null;
            }
        }
    }

    // LVal → Ident ['[' Exp ']']
    public LVal tryParseLVal() {
        Token ident = tokens.consumeExpect(TokenType.IDENFR);
        if (ident == null) {
            return null;
        }
        if (tokens.get().isOf(TokenType.LBRACK)) {
            tokens.consume();
            Exp exp = tryParseExp();
            if (exp == null) {
                return null;
            }
            tokens.consumeExpect(TokenType.RBRACK);
            return new LVal(ident, exp);
        } else {
            return new LVal(ident);
        }
    }

    // Number → IntConst
    public Number tryParseNumber() {
        if (tokens.get().isOf(TokenType.INTCON)) {
            return new Number(tokens.consume());
        } else {
            return null;
        }
    }

    // Character → CharConst
    public Character tryParseCharacter() {
        if (tokens.get().isOf(TokenType.CHRCON)) {
            return new Character(tokens.consume());
        } else {
            return null;
        }
    }

    // FuncRParams → Exp { ',' Exp }
    public FuncRParams tryParseFuncRParams() {
        ArrayList<Exp> exps = new ArrayList<>();
        Exp exp = tryParseExp();
        if (exp == null) {
            return null;
        }
        exps.add(exp);
        while (tokens.consumeExpect(TokenType.COMMA) != null) {
            exp = tryParseExp();
            if (exp == null) {
                return null;
            }
            exps.add(exp);
        }
        return new FuncRParams(exps);
    }
}
