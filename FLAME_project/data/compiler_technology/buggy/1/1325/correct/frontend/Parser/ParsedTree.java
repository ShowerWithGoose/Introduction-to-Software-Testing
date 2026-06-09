package frontend.Parser;

import java.util.LinkedList;
import java.util.stream.Collectors;

public class ParsedTree {
    private final String name;

    private LinkedList<ParsedTree> subTree;

    public ParsedTree(String name, LinkedList<ParsedTree> subTree) {
        this.name = name;
        this.subTree = subTree;
    }


    @Override
    public String toString() {
        return subTree.stream()
                .map(ParsedTree::toString)
                .collect(Collectors.joining("\n", "", "\n<" + name + ">"));
    }
}
