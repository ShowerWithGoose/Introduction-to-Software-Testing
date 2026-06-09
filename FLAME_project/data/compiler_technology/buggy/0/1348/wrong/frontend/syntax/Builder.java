package frontend.syntax;

import type.BinaryExpType;
import frontend.lex.Lexer;
import frontend.lex.Token;
import frontend.lex.TokenList;
import frontend.lex.TokenType;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Builder {
    private static final TokenList tokenList = Lexer.tokenList;
    private static final HashMap<BinaryExpType, BinaryExpType> downMap = new HashMap<>();
    private static final HashMap<BinaryExpType, HashSet<TokenType>> permitOpMap = new HashMap<>();

    static {
        downMap.put(BinaryExpType.OR, BinaryExpType.AND);
        downMap.put(BinaryExpType.AND, BinaryExpType.EQ);
        downMap.put(BinaryExpType.EQ, BinaryExpType.REL);
        downMap.put(BinaryExpType.REL, BinaryExpType.ADD);
        downMap.put(BinaryExpType.ADD, BinaryExpType.MUL);

        permitOpMap.put(BinaryExpType.OR, new HashSet<>());
        permitOpMap.get(BinaryExpType.OR).add(TokenType.OR);
        permitOpMap.put(BinaryExpType.AND, new HashSet<>());
        permitOpMap.get(BinaryExpType.AND).add(TokenType.AND);
        permitOpMap.put(BinaryExpType.EQ, new HashSet<>());
        permitOpMap.get(BinaryExpType.EQ).add(TokenType.EQL);
        permitOpMap.get(BinaryExpType.EQ).add(TokenType.NEQ);
        permitOpMap.put(BinaryExpType.REL, new HashSet<>());
        permitOpMap.get(BinaryExpType.REL).add(TokenType.LSS);
        permitOpMap.get(BinaryExpType.REL).add(TokenType.LEQ);
        permitOpMap.get(BinaryExpType.REL).add(TokenType.GRE);
        permitOpMap.get(BinaryExpType.REL).add(TokenType.GEQ);
        permitOpMap.put(BinaryExpType.ADD, new HashSet<>());
        permitOpMap.get(BinaryExpType.ADD).add(TokenType.PLUS);
        permitOpMap.get(BinaryExpType.ADD).add(TokenType.MINU);
        permitOpMap.put(BinaryExpType.MUL, new HashSet<>());
        permitOpMap.get(BinaryExpType.MUL).add(TokenType.MULT);
        permitOpMap.get(BinaryExpType.MUL).add(TokenType.DIV);
        permitOpMap.get(BinaryExpType.MUL).add(TokenType.MOD);
    }

    public static Ast build() {
        ArrayList<Ast.CompUnit> nodes = new ArrayList<>();
        while (tokenList.hasNext()) {
            if (tokenList.checkAheadChar(2).type == TokenType.LPARENT) {
                nodes.add(buildFuncDef());
            } else {
                nodes.add(buildDecl());
            }
        }
        return new Ast(nodes);
    }

    private static Ast.FuncDef buildFuncDef() {
        Token type = tokenList.getChar();
        Token name = tokenList.getChar();
        tokenList.skipChar();
        ArrayList<Ast.FuncFParam> paramList = new ArrayList<>();
        while (tokenList.checkAheadChar(0).type != TokenType.RPARENT) {
            paramList.add(buildFuncFParam());
            if (tokenList.checkAheadChar(0).type == TokenType.COMMA) {
                tokenList.skipChar();
            }
        }
        tokenList.skipChar();
        Ast.Block block = buildBlock();
        return new Ast.FuncDef(type.type.toBasicType(), name.content, paramList, block);
    }

    private static Ast.FuncFParam buildFuncFParam() {
        Token type = tokenList.getChar();
        Token name = tokenList.getChar();
        boolean isArray = false;
        if (tokenList.checkAheadChar(0).type == TokenType.LBRACK) {
            isArray = true;
            tokenList.skipChar();
            tokenList.skipChar();
        }
        return new Ast.FuncFParam(type.type.toBasicType(), name.content, isArray);
    }

    private static Ast.Decl buildDecl() {
        ArrayList<Ast.ValueDef> valueDefList = new ArrayList<>();
        boolean isConst = false;
        if (tokenList.checkAheadChar(0).type == TokenType.CONSTTK) {
            isConst = true;
            tokenList.skipChar();
        }
        Token type = tokenList.getChar();
        valueDefList.add(buildValueDef(type, isConst));
        while (tokenList.checkAheadChar(0).type == TokenType.COMMA) {
            tokenList.skipChar();
            valueDefList.add(buildValueDef(type, isConst));
        }
        tokenList.skipChar();
        return new Ast.Decl(isConst, type.type.toBasicType(), valueDefList);
    }

    private static Ast.Block buildBlock() {
        ArrayList<Ast.BlockItem> blockItems = new ArrayList<>();
        tokenList.skipChar();
        while (tokenList.checkAheadChar(0).type != TokenType.RBRACE) {
            blockItems.add(buildBlockItem());
        }
        tokenList.skipChar();
        return new Ast.Block(blockItems);
    }

    private static Ast.Exp buildExp() {
        if (tokenList.checkAheadChar(0).type == TokenType.SEMICN) {
            return null;
        }
        return buildBinaryExp(BinaryExpType.ADD);
    }

    private static Ast.ValueDef buildValueDef(Token type, boolean isConst) {
        Token name = tokenList.getChar();
        Ast.Exp index = null;
        Ast.ValueInitVal valueInitVal = null;
        if (tokenList.checkAheadChar(0).type == TokenType.LBRACK) {
            tokenList.skipChar();
            index = buildExp();
            tokenList.skipChar();
        }
        if (isConst) {
            tokenList.skipChar();
            valueInitVal = buildValueInitVal();
        } else {
            if (tokenList.hasNext() && tokenList.checkAheadChar(0).type == TokenType.ASSIGN) {
                tokenList.skipChar();
                valueInitVal = buildValueInitVal();
            }
        }
        return new Ast.ValueDef(name.content, index, valueInitVal);

    }

    private static Ast.BlockItem buildBlockItem() {
        if (tokenList.checkAheadChar(0).type == TokenType.INTTK ||
                tokenList.checkAheadChar(0).type == TokenType.CHARTK ||
                tokenList.checkAheadChar(0).type == TokenType.CONSTTK) {
            return buildDecl();
        } else {
            return buildStmt();
        }
    }

    private static Ast.ValueInitVal buildValueInitVal() {
        //NOTICE:valueList可能为空，如用{}初始化
        ArrayList<Ast.Exp> valueList = new ArrayList<>();
        boolean isNoStringArray = false;
        if (tokenList.checkAheadChar(0).type == TokenType.LBRACE) {
            tokenList.skipChar();
            while (tokenList.checkAheadChar(0).type != TokenType.RBRACE) {
                valueList.add(buildExp());
                if (tokenList.checkAheadChar(0).type == TokenType.COMMA) {
                    tokenList.skipChar();
                }
            }
            tokenList.skipChar();
            return new Ast.ValueInitVal(false, valueList, null, true);
        } else if (tokenList.checkAheadChar(0).type == TokenType.STRCON) {
            String stringConst = tokenList.getChar().content;
            return new Ast.ValueInitVal(true, null, new Ast.StringConst(stringConst), false);
        } else {
            valueList.add(buildExp());
            return new Ast.ValueInitVal(false, valueList, null, false);
        }
    }

    private static Ast.Exp buildBinaryExp(BinaryExpType type) {
        Ast.Exp firstExp = (type == BinaryExpType.MUL) ? buildUnaryExp() : buildBinaryExp(downMap.get(type));
        ArrayList<String> opList = new ArrayList<>();
        ArrayList<Ast.Exp> expList = new ArrayList<>();
        expList.add(firstExp);
        while (tokenList.hasNext() && permitOpMap.get(type).contains(tokenList.checkAheadChar(0).type)) {
            opList.add(tokenList.getChar().content);
            expList.add((type == BinaryExpType.MUL) ? buildUnaryExp() : buildBinaryExp(downMap.get(type)));
        }
        return new Ast.BinaryExp(expList, opList);
    }

    private static Ast.Exp buildUnaryExp() {
        ArrayList<String> opList = new ArrayList<>();
        while (tokenList.checkAheadChar(0).type == TokenType.PLUS ||
                tokenList.checkAheadChar(0).type == TokenType.MINU ||
                tokenList.checkAheadChar(0).type == TokenType.NOT) {
            opList.add(tokenList.getChar().content);
        }
        Ast.PrimaryExp primaryExp;
        Token token = tokenList.checkAheadChar(0);
        if (token.type == TokenType.INTCON && !opList.isEmpty()) {
            tokenList.skipChar();
            String newToken = token.content;
            if (opList.get(opList.size() - 1).equals("-")) {
                newToken = "-" + token.content;
                opList.remove(opList.size() - 1);
            }
            primaryExp = new Ast.NumberConst(Integer.parseInt(newToken));
        } else {
            primaryExp = buildPrimaryExp();
        }
        return new Ast.UnaryExp(primaryExp, opList);
    }

    private static Ast.PrimaryExp buildPrimaryExp() {
        Token token = tokenList.checkAheadChar(0);
        if (token.type == TokenType.LPARENT) {
            tokenList.skipChar();
            Ast.Exp exp = buildExp();
            tokenList.skipChar();
            return exp;
        } else if (token.type == TokenType.INTCON) {
            tokenList.skipChar();
            return new Ast.NumberConst(Integer.parseInt(token.content));
        } else if (token.type == TokenType.CHRCON) {
            tokenList.skipChar();
            if (token.content.charAt(1) == '\\') {
                return new Ast.CharacterConst(token.content.charAt(2));
            }
            return new Ast.CharacterConst(token.content.charAt(1));
        } else if (token.type == TokenType.IDENFR && tokenList.checkAheadChar(1).type == TokenType.LPARENT) {
            return buildFuncCall();
        } else {
            return buildLVal();
        }
    }

    private static Ast.LVal buildLVal() {
        Token name = tokenList.getChar();
        Ast.Exp index = null;
        if (tokenList.checkAheadChar(0).type == TokenType.LBRACK) {
            tokenList.skipChar();
            index = buildExp();
            tokenList.skipChar();
        }
        return new Ast.LVal(name.content, index);
    }

    private static Ast.FuncCall buildFuncCall() {
        Token name = tokenList.getChar();
        tokenList.skipChar();
        ArrayList<Ast.Exp> paramList = new ArrayList<>();
        while (tokenList.checkAheadChar(0).type != TokenType.RPARENT) {
            paramList.add(buildExp());
            if (tokenList.checkAheadChar(0).type == TokenType.COMMA) {
                tokenList.skipChar();
            }
        }
        tokenList.skipChar();
        return new Ast.FuncCall(name.content, paramList);
    }

    private static Ast.Stmt buildStmt() {
        Token token = tokenList.checkAheadChar(0);
        if (token.type == TokenType.LBRACE) {
            return buildBlock();
        } else if (token.type == TokenType.IFTK) {
            return buildIf();
        } else if (token.type == TokenType.FORTK) {
            return buildFor();
        } else if (token.type == TokenType.RETURNTK) {
            return buildReturn();
        } else if (token.type == TokenType.BREAKTK) {
            return buildBreak();
        } else if (token.type == TokenType.CONTINUETK) {
            return buildContinue();
        } else if (token.type == TokenType.IDENFR) {
            return buildLValExp();
        } else if (token.type == TokenType.SEMICN) {
            tokenList.skipChar();
            return new Ast.ExpStmt(null);
        } else if (token.type == TokenType.PRINTFTK) {
            return buildPrintf();
        } else {
            Ast.Exp exp = buildExp();
            tokenList.skipChar();
            return new Ast.ExpStmt(exp);
        }
    }

    private static Ast.IfStmt buildIf() {
        tokenList.skipChar();
        tokenList.skipChar();
        Ast.Exp condition = buildBinaryExp(BinaryExpType.OR);
        tokenList.skipChar();
        Ast.Stmt thenStmt = buildStmt();
        Ast.Stmt elseStmt = null;
        if (tokenList.hasNext() && tokenList.checkAheadChar(0).type == TokenType.ELSETK) {
            tokenList.skipChar();
            elseStmt = buildStmt();
        }
        return new Ast.IfStmt(condition, thenStmt, elseStmt);
    }

    private static Ast.ForWholeStmt buildFor() {
        //NOTICE:for三个位置的null值注意认真处理
        tokenList.skipChar();
        tokenList.skipChar();
        Ast.ForStmt init = buildForStmt();
        tokenList.skipChar();
        Ast.Exp condition = null;
        if (tokenList.checkAheadChar(0).type != TokenType.SEMICN) {
            condition = buildBinaryExp(BinaryExpType.OR);
        }
        tokenList.skipChar();
        Ast.ForStmt update = buildForStmt();
        tokenList.skipChar();
        Ast.Stmt body = buildStmt();
        return new Ast.ForWholeStmt(init, condition, update, body);
    }

    private static Ast.ForStmt buildForStmt() {
        if (tokenList.checkAheadChar(0).type == TokenType.SEMICN
                || tokenList.checkAheadChar(0).type == TokenType.RPARENT) {
            return null;
        }
        Ast.LVal lVal = buildLVal();
        tokenList.skipChar();
        Ast.Exp exp = buildExp();
        return new Ast.ForStmt(lVal, exp);
    }

    private static Ast.ReturnStmt buildReturn() {
        tokenList.skipChar();
        Ast.Exp exp = null;
        if (tokenList.checkAheadChar(0).type != TokenType.SEMICN) {
            exp = buildExp();
        }
        tokenList.skipChar();
        return new Ast.ReturnStmt(exp);
    }

    private static Ast.BreakStmt buildBreak() {
        tokenList.skipChar();
        tokenList.skipChar();
        return new Ast.BreakStmt();
    }

    private static Ast.ContinueStmt buildContinue() {
        tokenList.skipChar();
        tokenList.skipChar();
        return new Ast.ContinueStmt();
    }

    private static Ast.Stmt buildLValExp() {
        for (int index = 0; index < TokenList.tokens.size(); index++) {
            if (tokenList.checkAheadChar(index).type == TokenType.ASSIGN) {
                Ast.LVal lVal = buildLVal();
                tokenList.skipChar();
                if (tokenList.checkAheadChar(0).type == TokenType.GETINTTK) {
                    tokenList.skipChar();
                    tokenList.skipChar();
                    tokenList.skipChar();
                    tokenList.skipChar();
                    return new Ast.GetintStmt(lVal);
                }
                if (tokenList.checkAheadChar(0).type == TokenType.GETCHARTK) {
                    tokenList.skipChar();
                    tokenList.skipChar();
                    tokenList.skipChar();
                    tokenList.skipChar();
                    return new Ast.GetcharStmt(lVal);
                }
                Ast.Exp exp = buildExp();
                tokenList.skipChar();
                return new Ast.Assign(lVal, exp);
            }
            if (tokenList.checkAheadChar(index).type == TokenType.SEMICN) {
                Ast.Exp exp = buildExp();
                tokenList.skipChar();
                return new Ast.ExpStmt(exp);
            }
        }
        throw new RuntimeException("理论上至少有个分号");
    }

    private static Ast.PrintStmt buildPrintf() {
        tokenList.skipChar();
        tokenList.skipChar();
        Token token = tokenList.getChar();
        if (token.type != TokenType.STRCON) {
            throw new RuntimeException("printf函数调用格式错误");
        }
        String format = token.content;
        ArrayList<String> formatItems = new ArrayList<>();
        Pattern pattern = Pattern.compile("%[cd]");
        Matcher matcher = pattern.matcher(format);
        while (matcher.find()) {
            formatItems.add(matcher.group());
        }
        ArrayList<Ast.Exp> expList = new ArrayList<>();
        boolean isFormat = false;
        while (tokenList.checkAheadChar(0).type != TokenType.RPARENT) {
            tokenList.skipChar();
            expList.add(buildExp());
            isFormat = true;
        }
        tokenList.skipChar();
        tokenList.skipChar();
        return new Ast.PrintStmt(new Ast.StringConst(format), expList, isFormat, formatItems);
    }

}
