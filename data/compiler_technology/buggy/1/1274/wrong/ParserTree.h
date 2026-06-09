#pragma once
#ifndef FKBianYi_PARSER_TREE_H
#define FKBianYi_PARSER_TREE_H

#include <string>
#include <vector>
#include <map>
#include "GraItem.h"
#include "Token.h"
#include "MyFileStream.h"
class ParserTreeNode {
public:
	bool isTerminalSymbol;
	TokenType tokenType;
	string tokenWord;
	GraItem graItem;
	vector<ParserTreeNode> children;

	ParserTreeNode(bool isTerminalSymbol, TokenType tokenType = TokenType::None, string tokenWord = "", GraItem graitem = GraItem::Unknown)
		: isTerminalSymbol(isTerminalSymbol), tokenType(tokenType), tokenWord(tokenWord), graItem(graitem) {}

	ParserTreeNode() {
		isTerminalSymbol = false;
		tokenType = None;
		tokenWord = "";
		graItem = GraItem::Unknown;
	}

	void AddChild(ParserTreeNode child) {
		children.push_back(child);
	}
};
extern ParserTreeNode parserTreeRoot;
inline void PrintParserTree(ParserTreeNode node) {
	if (!node.isTerminalSymbol) {
		for (auto child : node.children) {
			PrintParserTree(child);
		}
		if (node.graItem != GraItem::BType && node.graItem != GraItem::Decl && node.graItem != GraItem::BlockItem)
			fileout << GraItem_Str.find(node.graItem)->second << endl;
	}
	else {
		if (node.tokenType == TokenType::STRCON) fileout << type_code2str.at(node.tokenType) + ' ' + '"' + node.tokenWord + '"' << endl;
		else if (node.tokenType == TokenType::CHRCON) fileout << type_code2str.at(node.tokenType) + ' ' + '\'' + node.tokenWord + '\'' << endl;
		else fileout << type_code2str.at(node.tokenType) << ' ' << node.tokenWord << endl;
	}
}
#endif