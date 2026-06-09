package parser_part;

import lexer_part.Token;
import lexer_part.TokenList;
import parser_part.declaration.Decl;
import parser_part.declaration.DeclParser;
import parser_part.function.FuncDef;
import parser_part.function.FuncDefParser;
import parser_part.function.MainFuncDef;
import parser_part.function.MainFuncDefParser;
import symbol_part.Symbol;
import symbol_part.SymbolList;

import java.util.ArrayList;

public class CompUnitParser {
    private TokenList tokenList;
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;

    public CompUnitParser(TokenList tokenList) {
        this.tokenList = tokenList;
        decls = new ArrayList<>();
        funcDefs = new ArrayList<>();
    }

    public CompUnit parseCompUnit() {
        Token first = tokenList.getNextToken();
        Token second = tokenList.getNextToken();
        Token third = tokenList.getNextToken();
        while (second.getType() != Token.TokenType.MAINTK) {
            tokenList.moveBack(3);
            if (third.getType() == Token.TokenType.LPARENT) {
                FuncDefParser funcDefParser = new FuncDefParser(tokenList, SymbolList.sharedSymbolList);
                funcDefs.add(funcDefParser.parseFuncDef());
            } else {
                DeclParser declParser = new DeclParser(tokenList, SymbolList.sharedSymbolList);
                decls.add(declParser.parseDecl());
            }
            first = tokenList.getNextToken();
            second = tokenList.getNextToken();
            third = tokenList.getNextToken();
        }
        tokenList.moveBack(3);
        MainFuncDefParser mainFuncDefParser = new MainFuncDefParser(tokenList, SymbolList.sharedSymbolList);
        MainFuncDef mainFuncDef = mainFuncDefParser.parseMainFuncDef();
        return new CompUnit(decls, funcDefs, mainFuncDef);
    }

    public ArrayList<Decl> parseDecls() {
        Token first = tokenList.getNextToken();
        Token second = tokenList.getNextToken();
        ArrayList<Decl> decls = new ArrayList<>();
        DeclParser declParser = new DeclParser(tokenList, SymbolList.sharedSymbolList);
        while (tokenList.isNotEnd()) {
            Token token = tokenList.getNextToken();
            if (token.getType() == Token.TokenType.LPARENT) {
                tokenList.moveBack(3);
                return decls;
            }
            tokenList.moveBack(1);
            if ((first.getType() == Token.TokenType.CONSTTK &&
                    second.getType() == Token.TokenType.INTTK) ||
                    (first.getType() == Token.TokenType.INTTK &&
                            second.getType() == Token.TokenType.IDENFR) ||
                    (first.getType() == Token.TokenType.CONSTTK &&
                            second.getType() == Token.TokenType.FLOATTK) ||
                    (first.getType() == Token.TokenType.FLOATTK &&
                            second.getType() == Token.TokenType.IDENFR)) {
                tokenList.moveBack(2);
                decls.add(declParser.parseDecl());
            } else {
                tokenList.moveBack(2);
                break;
            }
            first = tokenList.getNextToken();
            second = tokenList.getNextToken();
        }
        return decls;
    }

    public ArrayList<FuncDef> parseFuncDefs() {
        Token first = tokenList.getNextToken();
        Token second = tokenList.getNextToken();
        ArrayList<FuncDef> funcDefs = new ArrayList<>();
        FuncDefParser funcDefParser = new FuncDefParser(tokenList, SymbolList.sharedSymbolList);
        while (tokenList.isNotEnd()) {
            if ((first.getType() == Token.TokenType.VOIDTK ||
                    first.getType() == Token.TokenType.INTTK ||
                    first.getType() == Token.TokenType.FLOATTK) &&
                    (second.getType() == Token.TokenType.IDENFR)) {
                tokenList.moveBack(2);
                funcDefs.add(funcDefParser.parseFuncDef());
            } else {
                tokenList.moveBack(2);
                break;
            }
            first = tokenList.getNextToken();
            second = tokenList.getNextToken();
        }
        return funcDefs;
    }

}
