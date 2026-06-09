package parser_part.declaration.constance;

import error_part.Debug;
import error_part.Error;
import error_part.ErrorList;
import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.Ident;
import parser_part.IdentParser;
import parser_part.declaration.BType;
import parser_part.expression.ConstExp;
import parser_part.expression.ConstExpParser;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class ConstDefParser {
    private TokenList tokenList;
    private ArrayList<Token> leftBrackets;
    private ArrayList<ConstExp> constExps;
    private ArrayList<Token> rightBrackets;
    private SymbolList symbolList;
    private BType bType;

    public ConstDefParser(TokenList tokenList,SymbolList symbolList,BType bType) {
        this.tokenList = tokenList;
        leftBrackets = new ArrayList<>();
        constExps = new ArrayList<>();
        rightBrackets = new ArrayList<>();
        this.symbolList = symbolList;
        this.bType = bType;
    }

    public ConstDef parseConstDef() {
        IdentParser identParser = new IdentParser(tokenList);
        Ident ident = identParser.parseIdent();
        Token assign = null;
        Token token = tokenList.getNextToken();
        while (token.getType() == Token.TokenType.LBRACK) {
            ConstExpParser constExpParser = new ConstExpParser(tokenList,symbolList);
            leftBrackets.add(token);
            constExps.add(constExpParser.parseConstExp());
            Token rightBracket = tokenList.getNextToken();
            /* handle lack right bracket error*/
            if (rightBracket.getType() != Token.TokenType.RBRACK && Debug.status) {
                //System.err.println("expect right bracket in parseConstDef");
                tokenList.moveBack(2);
                ErrorList.addError(new Error(tokenList.getNextToken().getLineIndex(), Error.ErrorType.LACK_RIGHT_BRACK));
            }
            rightBrackets.add(rightBracket);
            token = tokenList.getNextToken();
        }
        assign = token;
        if (assign.getType() != Token.TokenType.ASSIGN) {
            System.err.println("expect assign in parseConstDef");
        }
        ConstInitValParser constInitValParser = new ConstInitValParser(tokenList,symbolList);
        ConstInitVal constInitVal = constInitValParser.parseConstInitVal();
        /* add symbol */
        addSymbol(ident);
        return new ConstDef(ident, leftBrackets, constExps, rightBrackets, assign, constInitVal);
    }

    public void addSymbol(Ident ident) {
        Symbol.SymbolType symbolType = null;
        int array = leftBrackets.size();
        if (bType.isInt()) {
            if (leftBrackets.isEmpty()) {
                symbolType = Symbol.SymbolType.ConstInt;
            } else if (leftBrackets.size() == 1) {
                symbolType = Symbol.SymbolType.ConstIntArray;
            }
        } else if (bType.isChar()){
            if (leftBrackets.isEmpty()) {
                symbolType = Symbol.SymbolType.ConstChar;
            } else if (leftBrackets.size() == 1) {
                symbolType = Symbol.SymbolType.ConstCharArray;
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
