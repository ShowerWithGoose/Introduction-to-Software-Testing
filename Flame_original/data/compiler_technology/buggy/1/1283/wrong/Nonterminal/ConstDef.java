package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;

/**
 * <p>Project: Compiler - ConstDef
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class ConstDef implements Node{
    //ConstDef → Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    public Token IdentToken;
    public ConstExp constExp;
    public ConstInitVal constInitVal;
    public String type;//量的类型是int,char
    public ConstDef(Token IdentToken,ConstExp constExp,ConstInitVal constInitVal){
        this.IdentToken=IdentToken;
        this.constExp=constExp;
        this.constInitVal=constInitVal;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        writer.write(IdentToken.getOutput());
        if(constExp!=null){
            writer.write("LBRACK [\n");
            constExp.output(writer);
            writer.write("RBRACK ]\n");
        }
        writer.write("ASSIGN =\n");
        constInitVal.output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.ConstDef));
    }
}
