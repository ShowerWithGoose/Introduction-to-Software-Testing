package frontend.Parser.declaration.constant;

import frontend.Lexer.Token;
import frontend.Parser.GrammarNode;
import frontend.Parser.expression.ConstExp;

import java.util.ArrayList;

public class ConstExpArray implements GrammarNode {
    private Token lBrace;
    private ConstExp firstConstExp;
    private ArrayList<Token> commas;
    private ArrayList<ConstExp> constExps;
    private Token rBrace;

    public ConstExpArray(Token lBrace, ConstExp firstConstExp,Token rBrace, ArrayList<Token> commas, ArrayList<ConstExp> constExps) {
        this.lBrace = lBrace;
        this.firstConstExp = firstConstExp;
        this.commas = commas;
        this.constExps = constExps;
        this.rBrace = rBrace;
    }

    public String grammarOutput(){
        StringBuilder sb = new StringBuilder();
        sb.append(lBrace.grammarOutput());
        if(firstConstExp != null){
            sb.append(firstConstExp.grammarOutput());
            if(commas != null && constExps != null && commas.size() == constExps.size()){
                for(int i = 0; i < constExps.size(); i++){
                    sb.append(commas.get(i).grammarOutput());
                    sb.append(constExps.get(i).grammarOutput());
                }
            }
        }
        sb.append(rBrace.grammarOutput());
        return sb.toString();
    }
}
