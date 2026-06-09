package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - EqExp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class EqExp implements Node{
    //RelExp | EqExp ('==' | '!=') RelExp
    //RelExp{('==' | '!=') RelExp}
    public List<RelExp> relExp;
    public List<Token> tokens;
    public EqExp(List<RelExp> relExp,List<Token> tokens){
        this.relExp=relExp;
        this.tokens=tokens;
    }
    //带{}的每个结束都要output非终结符吗
    @Override
    public void output(BufferedWriter writer) throws IOException {
        relExp.get(0).output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.EqExp));
        for(int i=0;i<tokens.size();i++){
            writer.write(tokens.get(i).getOutput());
            relExp.get(i+1).output(writer);
            writer.write(Grammar.nodeOutput.get(Nodetype.EqExp));
        }
    }
}
