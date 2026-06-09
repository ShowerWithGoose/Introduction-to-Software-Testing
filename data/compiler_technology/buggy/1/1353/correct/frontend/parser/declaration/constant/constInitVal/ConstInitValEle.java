package frontend.parser.declaration.constant.constInitVal;

import frontend.parser.SyntaxNode;

/**
 * <ConstInitVal> 子节点接口
 * <ConstExp>
 * |
 * '{' [ <ConstExp> { ',' <ConstExp> } '}'
 * |
 * <StringConst>
 */
public interface ConstInitValEle extends SyntaxNode {
}
