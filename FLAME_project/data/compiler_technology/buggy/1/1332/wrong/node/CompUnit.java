package node;

import java.util.List;

/**
 * ClassName: CompUnit
 * Package: node
 * Description:
 *
 * @Author
 * @Create 2024/10/4 10:01
 * @Version 1.0
 */
public class CompUnit extends Node{
    // CompUnit -> {Decl} {FuncDef} MainFuncDef
    public List<Decl>decls;
    public List<FuncDef>funcDefs;
    public MainFuncDef mainFuncDef;

    public CompUnit(List<Decl> decls, List<FuncDef> funcDefs, MainFuncDef mainFuncDef) {
        this.decls = decls;
        this.funcDefs = funcDefs;
        this.mainFuncDef = mainFuncDef;
        if(decls != null && decls.size() > 0 && decls.get(0) != null){
            this.lineNo = decls.get(0).lineNo;
        }else if (funcDefs != null && funcDefs.size() > 0 && funcDefs.get(0) != null) {
            this.lineNo = funcDefs.get(0).lineNo;
        }else if (mainFuncDef != null){
            this.lineNo = mainFuncDef.lineNo;
        }
    }

    public StringBuilder getPrintInfo(){
        StringBuilder info = new StringBuilder();
        if(decls != null){
            for (Decl decl : decls) {
                if (decl == null){
                    throw new RuntimeException("decl is null when invoke getPrintInfo in CompUnit");
                }
                else{
                    info.append(decl.getPrintInfo());
                }
            }
        }
        if(funcDefs != null){
            for(FuncDef funcDef : funcDefs){
                if (funcDef == null){
                    throw new RuntimeException("funcDef is null when invoke getPrintInfo in CompUnit");
                }
                else{
                    info.append(funcDef.getPrintInfo());
                }
            }
        }

        if (mainFuncDef == null){
            // 如果使用一些没有主函数的测试代码，需要注意这里会报错，因为默认必须有主函数
            throw new RuntimeException("mainFuncDef is null when invoke getPrintInfo in CompUnit");
        }else{
            info.append(mainFuncDef.getPrintInfo());
        }
        info.append("<CompUnit>\n");
        return info;
    }
}
