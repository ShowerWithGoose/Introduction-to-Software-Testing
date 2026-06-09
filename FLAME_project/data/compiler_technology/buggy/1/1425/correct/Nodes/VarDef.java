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
public class VarDef {
//    VarDef → Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal
//    VarDef -> Ident [ '[' ConstExp ']' ] ( 空 | '=' InitVal )
    private Token ident;
    private Token lbrack;
    private ConstExp constExp;
    private Token rbrack;
    private Token asign;
    private InitVal initVal;

    public VarDef(Token ident, Token lbrack, ConstExp constExp, Token rbrack, Token asign, InitVal initVal) {
        this.ident = ident;
        this.lbrack = lbrack;
        this.constExp = constExp;
        this.rbrack = rbrack;
        this.asign = asign;
        this.initVal = initVal;
    }

    public void print(){
        IO.parser_output(ident.toString());
        if(lbrack!=null){
            IO.parser_output(lbrack.toString());
            constExp.print();
            IO.parser_output(rbrack.toString());
        }
        if(asign!=null){
            IO.parser_output(asign.toString());
            initVal.print();
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.VarDef));
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

    public Token getAsign() {
        return asign;
    }

    public InitVal getInitVal() {
        return initVal;
    }
}
