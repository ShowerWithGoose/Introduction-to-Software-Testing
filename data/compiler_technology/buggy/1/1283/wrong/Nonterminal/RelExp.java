package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - RelExp
 * <p>Powered by berry On 2024-09-29
 *
 * @author
 * @version 1.0
 */
public class RelExp implements Node{
    //AddExp | RelExp ('<' | '>' | '<=' | '>=') AddExp
    //AddExp{('<' | '>' | '<=' | '>=') AddExp}
    public List<AddExp> addExp;
    public List<Token> tokens;
    public RelExp(List<AddExp> addExp,List<Token> tokens){
        this.addExp=addExp;
        this.tokens=tokens;
    }
    //带{}的每个结束都要output非终结符吗
    @Override
    public void output(BufferedWriter writer) throws IOException {
        addExp.get(0).output(writer);
        writer.write(Grammar.nodeOutput.get(Nodetype.RelExp));
        for(int i=0;i<tokens.size();i++){
            writer.write(tokens.get(i).getOutput());
            addExp.get(i+1).output(writer);
            writer.write(Grammar.nodeOutput.get(Nodetype.RelExp));
        }
    }
}
