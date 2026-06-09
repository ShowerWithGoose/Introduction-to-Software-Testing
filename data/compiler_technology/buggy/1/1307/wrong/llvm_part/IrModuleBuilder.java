package llvm_part;

import llvm_part.values.IrGlobalDeclBuilder;
import parser_part.CompUnit;
import parser_part.declaration.Decl;
import parser_part.function.FuncDef;
import symbol_part.SymbolList;

public class IrModuleBuilder {
    private CompUnit compUnit;
    private IrModule module;
    private SymbolList topSymbolList;

    public IrModuleBuilder(CompUnit compUnit) {
        this.compUnit = compUnit;
        this.module = new IrModule();
        topSymbolList = new SymbolList();
    }

    public IrModule buildModule() {
        for (Decl decl : compUnit.getDecls()) {
            IrGlobalDeclBuilder irGlobalDeclBuilder = new IrGlobalDeclBuilder(decl, topSymbolList);
            module.addGlobalDecl(irGlobalDeclBuilder.buildGlobalDecls());
        }
        for (FuncDef funcDef : compUnit.getFuncDefs()) {

        }
        return module;
    }
}
