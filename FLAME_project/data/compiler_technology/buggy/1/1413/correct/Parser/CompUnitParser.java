package Parser;

import Lexer.Token;
import Lexer.TokenListIterator;
import Parser.Func.FuncDef;
import Parser.Func.FuncDefParser;

import java.util.ArrayList;

/**
 * @Description:
 * @date 2024/10/10
 */
public class CompUnitParser {
    private ArrayList<Token> tokens;
    private TokenListIterator iterator;
    private ArrayList<Decl> decls=new ArrayList<>();
    private ArrayList<FuncDef> funcDefs=new ArrayList<>();
    private MainFuncDef mainFuncDef;

    public CompUnitParser(ArrayList<Token> tokens) {
        this.tokens = tokens;
        this.iterator = new TokenListIterator(this.tokens);
    }

    public CompUnit compUnitParse()
    {
        this.decls = new ArrayList<>();
        this.funcDefs = new ArrayList<>();
        /* parse decls */
        parseDecls();
        /* parse FuncDefs */
        parseFuncDefs();
        MainFuncDefParser mainFuncDefParser=new MainFuncDefParser(iterator);
        this.mainFuncDef=mainFuncDefParser.mainFuncDefParse();
        return new CompUnit(this.decls,this.funcDefs,this.mainFuncDef);
    }
    private void parseDecls() {
        Token first = this.iterator.readNextToken();
        Token second = this.iterator.readNextToken();
        while (this.iterator.hasNext()) {
            Token third = this.iterator.readNextToken();
            if (third.getType().equals("LPARENT")) {
                this.iterator.unReadToken(3);
                return;
            } else {
                this.iterator.unReadToken(1);
            }
            if ((first.getType().equals("CONSTTK")) || (first.getType().equals("INTTK"))||(first.getType().equals("CHARTK"))) {
                /* first -> const && second -> int */
                /* first -> int && second -> IDENFR */
                this.iterator.unReadToken(2);
                DeclParser declParser = new DeclParser(this.iterator);
                this.decls.add(declParser.declParse());
            } else {
                this.iterator.unReadToken(2);
                return;
            }
            first = this.iterator.readNextToken();
            second = this.iterator.readNextToken();
        }
    }
    private void parseFuncDefs() {
        Token first = this.iterator.readNextToken();
        Token second =this.iterator.readNextToken();
        while (this.iterator.hasNext()) {
            this.iterator.unReadToken(2);
            if ((first.getType().equals("VOIDTK") || first.getType().equals("INTTK")||first.getType().equals("CHARTK"))&&(!second.getValue().equals("main"))) {
                /* first -> int/void && second -> IDENFR */
                FuncDefParser funcDefParser = new FuncDefParser(this.iterator);
                this.funcDefs.add(funcDefParser.funcDefParse());
            } else {
                break;
            }
            first = this.iterator.readNextToken();
            second =this.iterator.readNextToken();
        }
    }
    //由于含有多组的decl，因此需要在这里写完1更方便
}
