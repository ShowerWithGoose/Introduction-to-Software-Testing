package Nonterminal;

import Grammar.Grammar;
import Lexer.Token;

import java.io.BufferedWriter;
import java.io.IOException;
import java.util.List;

/**
 * <p>Project: Compiler - InitVal
 * <p>Powered by berry On 2024-09-28
 *
 * @author
 * @version 1.0
 */
public class InitVal implements Node{
    //InitVal → Exp | '{' [ Exp { ',' Exp } ] '}' | StringConst
    public List<Exp> exp;
    public Token stringConst;
    public boolean isSingle;//不是数组
    public InitVal(List<Exp> exp,Token stringConst,boolean isSingle){
        this.exp=exp;
        this.stringConst=stringConst;
        this.isSingle=isSingle;
    }
    @Override
    public void output(BufferedWriter writer) throws IOException {
        if(exp.size()>0&&isSingle) exp.get(0).output(writer);
        else if(stringConst==null){
            writer.write("LBRACE {\n");
            for(int i=0;i<exp.size();i++){
                if(i!=0) writer.write("COMMA ,\n");
                exp.get(i).output(writer);
            }
            writer.write("RBRACE }\n");
        }
        else{
            writer.write(stringConst.getOutput());
        }
        writer.write(Grammar.nodeOutput.get(Nodetype.InitVal));
    }
}
