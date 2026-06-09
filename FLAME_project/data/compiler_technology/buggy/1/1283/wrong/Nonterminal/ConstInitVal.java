package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;
import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - ConstInitVal
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class ConstInitVal implements Node{
    //ConstInitVal → ConstExp | '{' [ ConstExp { ',' ConstExp } ] '}' | StringConst
    public List<ConstExp> constExp;
    public Token stringConst;
    public boolean isSingle;//不是数组
    public ConstInitVal(List<ConstExp> constExp,Token stringConst,boolean isSingle){
        this.constExp=constExp;
        this.stringConst=stringConst;
        this.isSingle=isSingle;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        if(constExp.size()>0&&isSingle) constExp.get(0).output(writer);
        else if(stringConst==null){
            //'{' [ ConstExp { ',' ConstExp } ] '}'
            writer.write("LBRACE {\n");
            if(constExp.size()>0){
                constExp.get(0).output(writer);
            }
            for(int i=1;i<constExp.size();i++){
                writer.write("COMMA ,\n");
                constExp.get(i).output(writer);
            }
            writer.write("RBRACE }\n");
        }
        else{
            writer.write(stringConst.getOutput());
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.ConstInitVal));
    }
}
