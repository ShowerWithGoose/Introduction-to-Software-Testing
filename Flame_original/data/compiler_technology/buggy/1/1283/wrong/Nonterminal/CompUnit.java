package Nonterminal;

import Lexer.Token;
import Grammar.Grammar;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - CompUnit
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class CompUnit implements Node{
    //CompUnit â†’ {Decl} {FuncDef} MainFuncDef
    public List<Decl> decl;
    public List<FuncDef> funcDef;
    public MainFuncDef mainFuncDef;
    public CompUnit(List<Decl> decl, List<FuncDef> funcDef, MainFuncDef mainFuncDef) {
        this.decl = decl;
        this.funcDef = funcDef;
        this.mainFuncDef = mainFuncDef;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException{
        for (Decl d : decl) {
            d.output(writer);
        }
        for (FuncDef f : funcDef) {
            f.output(writer);
        }
        mainFuncDef.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.CompUnit));
    }
}
