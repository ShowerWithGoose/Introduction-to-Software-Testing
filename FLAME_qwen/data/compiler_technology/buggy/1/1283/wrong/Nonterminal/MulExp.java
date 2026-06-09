package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - MulExp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class MulExp implements Node{
    //UnaryExp | MulExp ('*' | '/' | '%') UnaryExp
    //UnaryExp{('*' | '/' | '%') UnaryExp}
    public List<UnaryExp> unaryExp;
    public List<Token> tokens;
    public MulExp(List<UnaryExp> unaryExp,List<Token> tokens){
        this.unaryExp=unaryExp;
        this.tokens=tokens;
    }
    //带{}的每个结束都要output非终结符吗
    @Override
    public void output(BufferedWriter writer) throws IOException {
        unaryExp.get(0).output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.MulExp));
        for(int i=0;i<tokens.size();i++){
            writer.write(tokens.get(i).getOutput());
            unaryExp.get(i+1).output(writer);
            writer.write(Grammar.nodeOutput.get(Nodetype.MulExp));
        }
    }
}
