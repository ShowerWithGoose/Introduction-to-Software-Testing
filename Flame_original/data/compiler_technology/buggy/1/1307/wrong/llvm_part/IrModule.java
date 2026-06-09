package llvm_part;

import llvm_part.values.IrFunction;
import llvm_part.values.IrGlobalDecl;

import java.util.ArrayList;
import java.util.LinkedList;

public class IrModule implements IrValue {
    private LinkedList<IrGlobalDecl> globalDecls;
    private LinkedList<IrFunction> functions;

    public IrModule(){
        globalDecls = new LinkedList<>();
        functions = new LinkedList<>();
    }

    public void addGlobalDecl(ArrayList<IrGlobalDecl> decls){
        globalDecls.addAll(decls);
    }

    public void addFunction(IrFunction function){
        functions.add(function);
    }
}