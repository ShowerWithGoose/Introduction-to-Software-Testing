package frontend.parser;

import frontend.lexer.Token;
import frontend.lexer.TokenListIterator;
import frontend.lexer.TokenType;
import frontend.parser.declaration.Decl;
import frontend.parser.declaration.DeclParser;
import frontend.parser.function.FuncDef;
import frontend.parser.function.FuncDefParser;
import frontend.parser.function.MainFuncDef;
import frontend.parser.function.MainFuncDefParser;

import java.util.ArrayList;
public class CompUnitParser {
    public ArrayList<Token> tokens;
    public ArrayList<Token> error_tokens;
    public TokenListIterator iterator;
    public ArrayList<Decl> decls;
    public ArrayList<FuncDef> funcDefs;
    public MainFuncDef mainFuncDef;
    public CompUnitParser(ArrayList<Token> tokens, ArrayList<Token> error_tokens) {
        this.tokens = tokens;
        this.error_tokens = error_tokens;
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
    public void parseDecls() {
        Token first = this.iterator.readNextToken();
        Token second = this.iterator.readNextToken();
        while (this.iterator.hasNext()) {
            Token third = this.iterator.readNextToken();
            if (third.type.equals(TokenType.LPARENT)) {
                this.iterator.unReadToken(3);
                return;
            } else {
                this.iterator.unReadToken(1);
            }
            if ((first.type.equals(TokenType.CONSTTK) &&
                    second.type.equals(TokenType.INTTK)) ||
                    (first.type.equals(TokenType.CONSTTK) &&
                            second.type.equals(TokenType.CHARTK)) ||
                    (first.type.equals(TokenType.INTTK) &&
                            second.type.equals(TokenType.IDENFR)) ||
                    (first.type.equals(TokenType.CHARTK) &&
                            second.type.equals(TokenType.IDENFR))) {
                /* first -> const && second -> int
                /* first -> const && second -> char
                /* first -> int && second -> IDENFR */
                /* first -> char && second -> IDENFR */
                this.iterator.unReadToken(2);
                DeclParser declParser = new DeclParser(this.iterator,this.error_tokens);
                this.decls.add(declParser.parseDecl());
            } else {
                this.iterator.unReadToken(2);
                break;
            }
            first = this.iterator.readNextToken();
            second = this.iterator.readNextToken();
        }
    }

    public void parseFuncDefs() {
        Token first = this.iterator.readNextToken();
        Token second = this.iterator.readNextToken();
        while (this.iterator.hasNext()) {
            if ((first.type.equals(TokenType.INTTK) ||
                    first.type.equals(TokenType.VOIDTK)||
                    first.type.equals(TokenType.CHARTK)) &&
                    second.type.equals(TokenType.IDENFR)) {
                /* first -> int/void/char && second -> IDENFR */
                this.iterator.unReadToken(2);
                FuncDefParser funcDefParser = new FuncDefParser(this.iterator,this.error_tokens);
                this.funcDefs.add(funcDefParser.parseFuncDef());
            } else {
                this.iterator.unReadToken(2);
                break;
            }
            first = this.iterator.readNextToken();
            second = this.iterator.readNextToken();
        }
    }
    public void parseMainFuncDef() {
        MainFuncDefParser mainFuncDefParser = new MainFuncDefParser(this.iterator,this.error_tokens);
        this.mainFuncDef = mainFuncDefParser.parseMainFuncDef();
    }


}
