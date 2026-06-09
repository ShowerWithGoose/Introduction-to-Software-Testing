package frontend.expression.primaryexp;

import frontend.TokenListIterator;
import frontend.terminal.CharConst;
import frontend.terminal.CharConstParser;

/**
 * 解析器: Character (字符常量)
 * 对应文法: Character → CharConst
 *
 * 解析过程：
 * 1. 解析 CharConst（字符常量）。
 */
public class CharacterParser {
    private final TokenListIterator iterator;

    public CharacterParser(TokenListIterator iterator) {
        this.iterator = iterator;
    }

    public Character parseCharacter() {
        // 使用 CharConstParser 解析字符常量
        CharConstParser charConstParser = new CharConstParser(this.iterator);
        CharConst charConst = charConstParser.parseCharConst();

        // 构建并返回 Character 对象
        return new Character(charConst);
    }
}
