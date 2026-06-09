package parser_part.expression.unaryExpression;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.expression.Exp;
import parser_part.function.FuncRParams;
import parser_part.function.FuncRParamsParser;

import parser_part.Ident;
import parser_part.IdentParser;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class UnaryFunctionParser {
    private TokenList tokenList;
    private SymbolList symbolList;
    private int array;
    private boolean hasParam;
    private FuncRParams funcRParams;

    public UnaryFunctionParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        this.symbolList = symbolList;
        this.array = -1;
        hasParam = false;
        funcRParams = null;
    }

    public UnaryFunction parseUnaryFunction() {
        hasParam = false;
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        Token leftParent = tokenList.getNextToken();
        Token rightParent = tokenList.getNextToken();
        // check c error
        if (symbolList.hasUndefinedIdent(ident.getName()) && Debug.status) {
            ErrorList.addError(new Error(ident.getLineIndex(), Error.ErrorType.UNDECLARED_NAME));
            array = -1;
        } else {
            array = symbolList.getSymbol(ident.getName()).getArray();
        }
        // check j error
        if (rightParent.getType() == Token.TokenType.SEMICN) {
            tokenList.moveBack(2);
            ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(),
                    Error.ErrorType.LACK_RIGHT_PARENT));
            rightParent = new Token(Token.TokenType.RPARENT, ")", leftParent.getLineIndex());
        }
        if (rightParent.getType() != Token.TokenType.RPARENT) {
            hasParam = true;
            FuncRParamsParser funcRParamsParser = new FuncRParamsParser(tokenList, symbolList);
            tokenList.moveBack(1);
            funcRParams = funcRParamsParser.parseFuncRParams();
            rightParent = tokenList.getNextToken();
            //check  j error
            if (rightParent.getType() == Token.TokenType.SEMICN) {
                tokenList.moveBack(2);
                ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(),
                        Error.ErrorType.LACK_RIGHT_PARENT));
                rightParent = new Token(Token.TokenType.RPARENT, ")", leftParent.getLineIndex());
            }
            //return new UnaryFunction(ident, leftParent, funcRParams, rightParent);
        }
        checkParamCnt(ident);
        checkParamType(ident);
        Symbol symbol = symbolList.getSymbol(ident.getName());
        UnaryFunction unaryFunction = new UnaryFunction(ident, leftParent, funcRParams, rightParent, symbol == null ? null : symbol.getSymbolType());
        unaryFunction.setArray(array);
        return unaryFunction;
    }

    private void checkParamCnt(Ident ident) {
        Symbol symbol = symbolList.getSymbol(ident.getName());
        if (symbol == null) {
            return;
        }
        if ((funcRParams == null && !symbol.getParamSymbols().isEmpty()) ||
                (funcRParams != null && symbol.getParamSymbols().size() != funcRParams.getParamsCnt())) {
            ErrorList.addError(new Error(ident.getLineIndex(), Error.ErrorType.WRONG_PARAM_CNT));
        }
    }

    private void checkParamType(Ident ident) {
        Symbol symbol = symbolList.getSymbol(ident.getName());
        if (symbol == null || !hasParam) {
            return;
        }
        if (funcRParams.getParamsCnt() == symbol.getParamSymbols().size()) {
            ArrayList<Exp> exps = funcRParams.getAllExps();
            int len = symbol.getParamSymbols().size();
            for (int i = 0; i < len; i++) {
                //TODO 没有实现浮点数类型识别
                Symbol symbol1 = symbol.getParamSymbols().get(i);
                Exp exp = exps.get(i);
                int paramArray = symbol.getParamSymbols().get(i).getArray();
                int realArray = exps.get(i).getArray();

                Symbol.SymbolType expType = exp.getSymbolType();
                Symbol.SymbolType paramType = symbol1.getSymbolType();
                expType = expType.ignoreConst();
                if (realArray == -1) {
                    break;
                }
                if (paramArray != realArray ||
                        (paramArray == 1 && expType != paramType)) {
                    ErrorList.addError(new Error(ident.getLineIndex(), Error.ErrorType.WRONG_PARAM_TYPE));
                    break;
                }
            }
        }
    }
}
