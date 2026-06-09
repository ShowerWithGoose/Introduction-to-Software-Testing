package frontend.parser;

import frontend.lexer.Token;
import frontend.lexer.TokenList;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.Decl;
import frontend.parser.declaration.DeclParser;
import frontend.parser.function.FuncDef;
import frontend.parser.function.FuncDefParser;
import frontend.parser.function.MainFuncDef;
import frontend.parser.function.MainFuncDefParser;

import java.util.ArrayList;

/**
 * CompUnitParser 编译单元解析器类
 * <CompUnit> -> { <Decl> } { <FuncDef> } <MainFuncDef>
 * 传入词法分析的结果TokenList进行语法分析
 */
public class CompUnitParser {
    private TokenList tokens;
    private TokenListIterator iterator;
    /* CompUnit params */
    private ArrayList<Decl> decls;
    private ArrayList<FuncDef> funcDefs;
    private MainFuncDef mainFuncDef;

    public CompUnitParser(TokenList tokens) {
        this.tokens = tokens;
        this.iterator = new TokenListIterator(this.tokens);
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        this.mainFuncDef = null;
    }

    public CompUnit parseCompUnit() {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        /* parse decls */
        parseDecls();
        /* parse FuncDefs */
        parseFuncDefs();
        /* parse MainFuncDef */
        parseMainFuncDef();

        CompUnit compUnit = new CompUnit(this.decls, this.funcDefs, this.mainFuncDef);
        return compUnit;
    }

    private void parseDecls() {
        Token first = this.iterator.next();
        Token second = this.iterator.next();
        while (this.iterator.hasNext()) {
            Token third = this.iterator.next();
            if (third.getTokenType().equals(TokenType.LPARENT)) {
                this.iterator.unRead(3);
                return;
            } else {
                this.iterator.unRead(1);
            }
            /* 预读 */
            /* first -> const && second -> int/char */
            /* first -> int/char && second -> IDENFR */
            if ((first.getTokenType().equals(TokenType.CONSTTK) && (second.getTokenType().equals(TokenType.INTTK) || second.getTokenType().equals(TokenType.CHARTK))) ||
                    ((first.getTokenType().equals(TokenType.INTTK) || first.getTokenType().equals(TokenType.CHARTK)) && second.getTokenType().equals(TokenType.IDENFR))) {
                this.iterator.unRead(2);
                DeclParser declParser = new DeclParser(this.iterator);
                this.decls.add(declParser.parseDecl());
            } else {
                this.iterator.unRead(2);
                break;
            }
            first = this.iterator.next();
            second = this.iterator.next();
        }
    }

    private void parseFuncDefs() {
        Token first = this.iterator.next();
        Token second = this.iterator.next();
        /* 预读 */
        /* first -> void/int/char && second -> IDENFR */
        while (this.iterator.hasNext()) {
            if ((first.getTokenType().equals(TokenType.INTTK) || first.getTokenType().equals(TokenType.VOIDTK) || first.getTokenType().equals(TokenType.CHARTK)) &&
                second.getTokenType().equals(TokenType.IDENFR)) {
                this.iterator.unRead(2);
                FuncDefParser funcDefParser = new FuncDefParser(this.iterator);
                this.funcDefs.add(funcDefParser.parseFuncDef());
            } else {
                this.iterator.unRead(2);
                break;
            }
            first = this.iterator.next();
            second = this.iterator.next();
        }
    }

    private void parseMainFuncDef() {
        MainFuncDefParser mainFuncDefParser = new MainFuncDefParser(this.iterator);
        this.mainFuncDef = mainFuncDefParser.parseMainFuncDef();
    }

}