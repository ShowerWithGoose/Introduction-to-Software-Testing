package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - AddExp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class AddExp implements Node{
    //MulExp | AddExp ('+' | '−') MulExp
    //MulExp{('+' | '−') MulExp}
    public List<MulExp> mulExp;
    public List<Token> tokens;
    public AddExp(List<MulExp> mulExp,List<Token> tokens){
        this.mulExp=mulExp;
        this.tokens=tokens;
    }
    //带{}的每个结束都要output非终结符吗
    @Override
    public void output(BufferedWriter writer) throws IOException {
        mulExp.get(0).output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.AddExp));
        for(int i=0;i<tokens.size();i++){
            writer.write(tokens.get(i).getOutput());
            mulExp.get(i+1).output(writer);
            writer.write(Grammar.nodeOutput.get(Nodetype.AddExp));
        }
    }
}
