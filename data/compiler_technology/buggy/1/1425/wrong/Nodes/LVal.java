package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 19:00
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 19:00
 */
public class LVal {
//    LVal â†’ Ident ['[' Exp ']']
    private Token ident;
    private Token lbrack;
    private Exp exp;
    private Token rbrack;

    public LVal(Token ident, Token lbrack, Exp exp, Token rbrack) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.exp = exp;
        this.rbrack = rbrack;
    }

    public void print(){
        IO.parser_output(ident.toString());
        if(lbrack!=null){
            IO.parser_output(lbrack.toString());
            exp.print();
            IO.parser_output(rbrack.toString());
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.LVal));
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLbrack() {
        return lbrack;
    }

    public Exp getExp() {
        return exp;
    }

    public Token getRbrack() {
        return rbrack;
    }
}
