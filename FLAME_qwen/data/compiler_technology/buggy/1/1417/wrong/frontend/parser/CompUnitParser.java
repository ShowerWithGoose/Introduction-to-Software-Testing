package frontend.parser;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenType;
import frontend.parser.declaration.Decl;
import frontend.parser.declaration.DeclParser;
import frontend.parser.function.FuncDef;
import frontend.parser.function.FuncDefParser;
import frontend.parser.function.MainFuncDef;
import frontend.parser.function.MainFuncDefParser;

import java.util.ArrayList;

// CompUnit -> { Decl } { FuncDef } MainFuncDef
// Decl -> ConstDecl | VarDecl
public class CompUnitParser {
    // tokens即词法分析产生的ArrayList
    private TokenList tokenList;
    private ArrayList<Node> nodes;

    public CompUnitParser(TokenList tokenList) {
        this.tokenList = tokenList;
        this.nodes = new ArrayList<>();
    }

    public CompUnit parseCompUnit() {
        parseDecls();
        parseFuncDefs();
        parseMainFuncDef();
        int startLine = nodes.get(0).getStarttLine();
        int endLine = nodes.get(nodes.size() - 1).getEndLine();
        CompUnit compUnit = new CompUnit(startLine, endLine, "<CompUnit>", nodes);
        return compUnit;
    }

    public void parseDecls() {
        Token first = tokenList.getNextToken();
        Token second = tokenList.getNextToken();
        while (tokenList.hasNext()) {
            Token third = tokenList.getNextToken();
            // 说明已经进入到了FuncDef或MainFuncDef的部分，不再需要parseDecls了
            if (third.getType() == TokenType.LPARENT) {
                tokenList.fallbackToken(3);
                return;
            } else {
                tokenList.fallbackToken(1);
            }
            // 判断是不是ConstDecl或VarDecl
            if ((first.getType() == TokenType.CONSTTK && (second.getType() == TokenType.INTTK || second.getType() == TokenType.CHARTK))
                    || ((first.getType() == TokenType.INTTK || first.getType() == TokenType.CHARTK) && second.getType() == TokenType.IDENFR)) {
                tokenList.fallbackToken(2);
                DeclParser declParser = new DeclParser(tokenList);
                Decl decl = declParser.parseDecl();
                this.nodes.add(decl);
            } else {
                tokenList.fallbackToken(2);
                break;
            }
            first = this.tokenList.getNextToken();
            second = this.tokenList.getNextToken();
        }
    }

    public void parseFuncDefs() {
        Token first = tokenList.getNextToken();
        Token second = tokenList.getNextToken();
        while (tokenList.hasNext()) {
            if ((first.getType() == TokenType.VOIDTK || first.getType() == TokenType.INTTK || first.getType() == TokenType.CHARTK)
                    && second.getType() == TokenType.IDENFR) {
                tokenList.fallbackToken(2);
                FuncDefParser funcDefParser = new FuncDefParser(tokenList);
                FuncDef funcDef = funcDefParser.parseFuncDef();
                this.nodes.add(funcDef);
            } else {
                tokenList.fallbackToken(2);
                break;
            }
            first = tokenList.getNextToken();
            second = tokenList.getNextToken();
        }
    }

    public void parseMainFuncDef() {
        MainFuncDefParser mainFuncDefParser = new MainFuncDefParser(tokenList);
        MainFuncDef mainFuncDef = mainFuncDefParser.parseMainFuncDef();
        this.nodes.add(mainFuncDef);
    }

}
