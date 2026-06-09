package node;

/**
 * ClassName: Decl
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:02
 * @Version 1.0
 */
public class Decl extends Node{
    // Decl -> ConstDecl | VarDecl
    public ConstDecl constDecl;
    public VarDecl varDecl;

    public Decl (ConstDecl constDecl){
        this.constDecl = constDecl;
        setLineNo(constDecl);
    }

    public Decl (VarDecl varDecl){
        this.varDecl = varDecl;
        setLineNo(varDecl);
    }


    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        if(constDecl != null){
            info.append(constDecl.getPrintInfo());
        }else if (varDecl != null){
            info.append(varDecl.getPrintInfo());
        }
        return info;
    }
}
