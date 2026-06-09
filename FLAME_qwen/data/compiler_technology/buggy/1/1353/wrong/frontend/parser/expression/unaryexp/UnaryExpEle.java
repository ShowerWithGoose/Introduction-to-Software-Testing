package frontend.parser.expression.unaryexp;

import frontend.parser.SyntaxNode;

/**
 * UnaryExp 一元表达式基类接口
 * <PrimaryExp> | <Ident> '(' [<FuncRParams> ')' | <UnaryOp> <UnaryExp>
 * 由于UnaryExp的分支较多，所以采用接口形式来表示每一种分支
 * 但统一接受到UnaryExp类中
 */
public interface UnaryExpEle extends SyntaxNode {
}
