package error;

public enum ErrorType {
    a, // & |
    i, // Stmt, ConstDecl, VarDecl中缺少';'
    j, // 函数调用, 函数定义, Stmt, PrimaryExp中缺少')'
    k, // 数组定义和使用中缺少']'
}
