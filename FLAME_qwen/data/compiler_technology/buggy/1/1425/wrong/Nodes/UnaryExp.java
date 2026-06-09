package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 19:01
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 19:01
 */
public class UnaryExp {
//    UnaryExp â†’ PrimaryExp | Ident '(' [FuncRParams] ')' | UnaryOp UnaryExp
    private PrimaryExp primaryExp;
    private Token ident;
    private Token lparent;
    private Token rparent;
    private FuncRParams funcRParams;
    private UnaryOp unaryOp;
    private UnaryExp unaryExp;

    public UnaryExp(PrimaryExp primaryExp, Token ident, Token lparent, Token rparent, FuncRParams funcRParams, UnaryOp unaryOp, UnaryExp unaryExp) {
        this.primaryExp = primaryExp;
        this.ident = ident;
        this.lparent = lparent;
        this.rparent = rparent;
        this.funcRParams = funcRParams;
        this.unaryOp = unaryOp;
        this.unaryExp = unaryExp;
    }

    public void print(){
        if(primaryExp!=null){
            primaryExp.print();
        }
        else if(ident!=null){
            IO.parser_output(ident.toString());
            IO.parser_output(lparent.toString());
            if(funcRParams!=null){
                funcRParams.print();
            }
            IO.parser_output(rparent.toString());
        }
        else if(unaryOp!=null){
            unaryOp.print();
            unaryExp.print();
        }
        IO.parser_output(Parser.nodeTypes.get(NodeType.UnaryExp));
    }

    public PrimaryExp getPrimaryExp() {
        return primaryExp;
    }

    public Token getIdent() {
        return ident;
    }

    public Token getLparent() {
        return lparent;
    }

    public Token getRparent() {
        return rparent;
    }

    public FuncRParams getFuncRParams() {
        return funcRParams;
    }

    public UnaryOp getUnaryOp() {
        return unaryOp;
    }

    public UnaryExp getUnaryExp() {
        return unaryExp;
    }
}

