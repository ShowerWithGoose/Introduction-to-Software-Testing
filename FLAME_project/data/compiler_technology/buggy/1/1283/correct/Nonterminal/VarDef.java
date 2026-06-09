package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - VarDef
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class VarDef implements Node{
    //VarDef â†’ Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
    public Token IdentToken;
    public ConstExp constExp;
    public InitVal initVal;
    public String type;
    public VarDef(Token IdentToken,ConstExp constExp,InitVal initVal){
        this.IdentToken=IdentToken;
        this.constExp=constExp;
        this.initVal=initVal;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        writer.write(IdentToken.getOutput());
        if(constExp!=null){
            writer.write("LBRACK [\n");
            constExp.output(writer);
            writer.write("RBRACK ]\n");
        }
        if(initVal!=null){
            writer.write("ASSIGN =\n");
            initVal.output(writer);
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.VarDef));
    }
}
