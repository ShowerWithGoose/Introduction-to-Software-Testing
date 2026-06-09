package frontend.parser.declaration.variable.initval;

import frontend.parser.SyntaxNode;

/**
 * <InitVal> 变量初值子节点接口
 * <Exp>
 * |
 * '{' [ <Exp> { ',' <Exp> } ] '}'
 * |
 * StringConst
 */
public interface InitValEle extends SyntaxNode {
}
