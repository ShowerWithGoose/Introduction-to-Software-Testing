package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:58
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:58
 */
public class ConstDef {
//    ConstDef â†’ Ident [ '[' ConstExp ']' ] '=' ConstInitVal
    private Token ident;
    private Token lbrack;
    private ConstExp constExp;
    private Token rbrack;
    private Token assign;
    private ConstInitVal constInitVal;

    public ConstDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack, Token assign, ConstInitVal constInitVal) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
        this.assign = assign;
        this.constInitVal = constInitVal;
    }

    public void print(){
        IO.parser_output(ident.toString());
        if(lbrack!=null){
            IO.parser_output(lbrack.toString());
            constExp.print();
            IO.parser_output(rbrack.toString());
        }
        IO.parser_output(assign.toString());
        constInitVal.print();
        IO.parser_output(Parser.nodeTypes.get(NodeType.ConstDef));
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLbrack() {
        return lbrack;
    }

    public ConstExp getConstExp() {
        return constExp;
    }

    public Token getRbrack() {
        return rbrack;
    }

    public Token getAssign() {
        return assign;
    }

    public ConstInitVal getConstInitVal() {
        return constInitVal;
    }
}
