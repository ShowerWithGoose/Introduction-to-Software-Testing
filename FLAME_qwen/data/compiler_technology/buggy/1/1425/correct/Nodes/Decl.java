package Nodes;/**
 * @Description:
 * @author
 * @date 2024/9/28 18:57
 */
import java.util.*;
import Token.*;
import Utils.IO;
import frontend.*;
/**
 * @author:
 * TODO  
 * 2024/9/28 18:57
 */
public class Decl {
//    Decl â†’ ConstDecl | VarDecl
    private ConstDecl constDecl;
    private VarDecl varDecl;

    public Decl(ConstDecl constDecl, VarDecl varDecl) {
        this.constDecl = constDecl;
        this.varDecl = varDecl;
    }

    public void print(){
        if(constDecl!=null){
            constDecl.print();
        }
        else if(varDecl!=null){
            varDecl.print();
        }

    }

    public ConstDecl getConstDecl() {
        return constDecl;
    }

    public VarDecl getVarDecl() {
        return varDecl;
    }
}
