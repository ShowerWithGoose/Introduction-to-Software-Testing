/********************************************************************************
 * @FileName     : Decl.java
 * @Author       :
 * @Description  : 声明
 * @Notice       :  Decl -> ConstDecl | VarDecl
 * @Time         : 2024-10-13 16:43
 * @Version      : 0.0
 ********************************************************************************/

package node;

public class Decl implements ASTNode{
    // Decl -> ConstDecl | VarDecl
    private ConstDecl constDecl;
    private VarDecl varDecl;

    public Decl(ConstDecl constDecl, VarDecl varDecl) {
        this.constDecl = constDecl;
        this.varDecl = varDecl;
    }

    @Override
    public void printInfo() {
        if (constDecl != null) {
            constDecl.printInfo();
        } else {
            varDecl.printInfo();
        }
    }
}
