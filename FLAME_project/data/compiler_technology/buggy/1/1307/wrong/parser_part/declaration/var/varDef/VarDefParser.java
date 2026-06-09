package parser_part.declaration.var.varDef;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.Ident;
import parser_part.IdentParser;
import parser_part.declaration.BType;
import parser_part.declaration.var.initVal.InitVal;
import parser_part.declaration.var.initVal.InitValParser;
import parser_part.expression.ConstExp;
import parser_part.expression.ConstExpParser;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class VarDefParser {
    private TokenList tokenList;
    private ArrayList<Token> leftBrackets;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBrackets;
    private SymbolList symbolList;
    private BType bType;

    public VarDefParser(TokenList tokenList, SymbolList symbolList, BType bType) {
        this.tokenList = tokenList;
        leftBrackets = new ArrayList<>();
        constExps = new ArrayList<>();
        rightBrackets = new ArrayList<>();
        this.symbolList = symbolList;
        this.bType = bType;
    }

    public VarDef parseVarDef() {
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        Token token = tokenList.getNextToken();
        Token assign;
        InitVal initVal;
        while (token != null && token.getType() == Token.TokenType.LBRACK) {
            leftBrackets.add(token);
            ConstExpParser constExpParser = new ConstExpParser(tokenList, symbolList);
            constExps.add(constExpParser.parseConstExp());
            token = tokenList.getNextToken();
            /* handle lack right bracket error*/
            if (token.getType() != Token.TokenType.RBRACK && Debug.status) {
                //System.err.println("expect right bracket in parseConstDef");
                tokenList.moveBack(2);
                ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_RIGHT_BRACK));
            }
            rightBrackets.add(token);
            token = tokenList.getNextToken();
        }
        addSymbol(ident);
        if (token != null && token.getType() == Token.TokenType.ASSIGN) {
            assign = token;
            InitValParser initValParser = new InitValParser(tokenList, symbolList);
            initVal = initValParser.parseInitVal();
            return new VarDef(ident, leftBrackets, constExps,
                    rightBrackets, assign, initVal);
        } else {
            tokenList.moveBack(1);
            return new VarDef(ident, leftBrackets, constExps, rightBrackets, null, null);
        }
    }

    public void addSymbol(Ident ident) {
        Symbol.SymbolType symbolType = null;
        int array = leftBrackets.size();
        if (bType.isInt()) {
            if (leftBrackets.isEmpty()) {
                symbolType = Symbol.SymbolType.Int;
            } else if (leftBrackets.size() == 1) {
                symbolType = Symbol.SymbolType.IntArray;
            }
        } else if (bType.isChar()){
            if (leftBrackets.isEmpty()) {
                symbolType = Symbol.SymbolType.Char;
            } else if (leftBrackets.size() == 1) {
                symbolType = Symbol.SymbolType.CharArray;
            }
        }
        Symbol symbol = new Symbol(ident.getLineIndex(), ident.getName(), symbolType, array);
        symbol.setFieldNumber(symbolList.getFieldNumber());
        // check error
        if (symbolList.containSymbol(symbol) && Debug.status) {
            ErrorList.addError(new Error(ident.getLineIndex(), Error.ErrorType.REPEAT_DECLARE));
        } else {
            symbolList.addSymbol(symbol);
        }
    }
}
