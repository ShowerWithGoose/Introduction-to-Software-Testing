package frontend.parser.expression.primaryexp;

import frontend.parser.SyntaxNode;
/**
 * PrimaryExp 基本表达式基类接口
 * '(' <Exp> ')' | <LVal> | <Number> | <Character>
 * 由于PrimaryExp的分支较多，所以采用接口形式来表示每一种分支
 * 但统一接受到PrimaryExp类中
 */
public interface PrimaryExpEle extends SyntaxNode {
}
