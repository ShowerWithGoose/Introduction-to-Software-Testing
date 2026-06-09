package parser_part.function;

import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.Ident;
import parser_part.IdentParser;
import parser_part.declaration.BType;
import parser_part.declaration.BTypeParser;
import parser_part.expression.ConstExp;
import parser_part.expression.ConstExpParser;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class FuncFParamParser {
    private TokenList tokenList;
    private ArrayList<Token> leftBrackets;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBrackets;
    private SymbolList symbolList;
    private Symbol symbol;

    public FuncFParamParser(TokenList tokenList, SymbolList symbolList) {
        this.tokenList = tokenList;
        leftBrackets = new ArrayList<>();
        constExps = new ArrayList<>();
        rightBrackets = new ArrayList<>();
        this.symbolList = symbolList;
        symbol = null;
    }

    public FuncFParam parseFuncFParam() {
        BTypeParser bTypeParser = new BTypeParser(tokenList);
        BType bType = bTypeParser.parseBType();
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        Token token = tokenList.getNextToken();
        Token leftBracket = null;
        Token rightBracket = null;
        if (token != null && token.getType() == Token.TokenType.LBRACK) {
            leftBracket = token;
            rightBracket = tokenList.getNextToken();
            //check k error
            if (rightBracket.getType() != Token.TokenType.RBRACK) {
                tokenList.moveBack(2);
                ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(),
                        Error.ErrorType.LACK_RIGHT_BRACK));
            }
            token = tokenList.getNextToken();
//            while (token.getType() == Token.TokenType.LBRACK) {
//                leftBrackets.add(token);
//                ConstExpParser constExpParser = new ConstExpParser(tokenList,symbolList);
//                constExps.add(constExpParser.parseConstExp());
//                Token right = tokenList.getNextToken();
//                rightBrackets.add(right);
//                // check k error
//                if (right.getType() != Token.TokenType.RBRACK) {
//                    tokenList.moveBack(2);
//                    ErrorList.addError(new Error(token.getLineIndex(),
//                            Error.ErrorType.LACK_RIGHT_BRACK));
//                }
//                token = tokenList.getNextToken();
//            }
        }
        tokenList.moveBack(1);
        addSymbol(ident, leftBracket, bType);
        return new FuncFParam(bType, ident, leftBracket, rightBracket,
                leftBrackets, constExps, rightBrackets);
    }

    public void addSymbol(Ident ident, Token leftBracket, BType bType) {
        int array;
        Symbol.SymbolType symbolType;
        if (leftBracket != null && leftBracket.getType() == Token.TokenType.LBRACK &&
                leftBrackets.isEmpty()) {
            array = 1;
            symbolType = bType.isChar() ? Symbol.SymbolType.CharArray : Symbol.SymbolType.IntArray;
        } else {
            array = 0;
            symbolType = bType.isChar() ? Symbol.SymbolType.Char : Symbol.SymbolType.Int;
        }
        this.symbol = new Symbol(ident.getLineIndex(), ident.getName(), symbolType, array);
        symbol.setFieldNumber(symbolList.getFieldNumber());
        if (symbolList.containSymbol(symbol)) {
            ErrorList.addError(new Error(symbol.getLineIndex(), Error.ErrorType.REPEAT_DECLARE));
        } else {
            symbolList.addSymbol(symbol);
        }
    }

    public Symbol getSymbol() {
        return symbol;
    }
}
