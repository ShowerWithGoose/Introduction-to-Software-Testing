//
// Created by  on 2024-09-03.
//

#include <unordered_map>
#include "Type.h"

namespace ir {
    VoidType *VoidType::get() {
        static auto *instance = new VoidType();
        return instance;
    }

    std::string VoidType::toString() const {
        return "void";
    }

    LabelType *LabelType::get() {
        static auto *instance = new LabelType();
        return instance;
    }

    std::string LabelType::toString() const {
        return "label";
    }

    IntegerType *IntegerType::get(int bits) {
        static std::unordered_map<int, IntegerType *> cache;
        auto it = cache.find(bits);
        if (it != cache.end()) {
            return it->second;
        }

        auto instance = new IntegerType(bits);
        cache[bits] = instance;
        return instance;
    }

    std::string IntegerType::toString() const {
        return "i" + std::to_string(bits);
    }

    FunctionType *FunctionType::get(const std::vector<Type *> &formalArgs, Type *returnType) {
        static std::unordered_map<std::string, FunctionType *> cache;

        // 以字符串做键实现类型唯一化缓存
        std::string key = returnType->toString() + "(";
        for (const auto &arg : formalArgs) {
            key += arg->toString() + ",";
        }
        key += ")";

        auto it = cache.find(key);
        if (it != cache.end()) {
            return it->second;
        }

        auto instance = new FunctionType(formalArgs, returnType);
        cache[key] = instance;
        return instance;
    }

    std::string FunctionType::toString() const {
        std::string ret = returnType->toString() + "(";
        for (const auto &arg : formalArgs) {
            ret += arg->toString() + ",";
        }
        ret += ")";
        return ret;
    }

    PointerType *PointerType::get(Type *elementType) {
        // todo 不知道这里会不会出bug
        static std::unordered_map<Type *, PointerType *> cache;
        auto it = cache.find(elementType);
        if (it != cache.end()) {
            return it->second;
        }

        auto instance = new PointerType(elementType);
        cache[elementType] = instance;
        return instance;
    }

    std::string PointerType::toString() const {
        return elementType->toString() + "*";
    }

    ArrayType *ArrayType::get(Type *elementType, int elementNum) {
        static std::unordered_map<std::string, ArrayType *> cache;
        std::string key = elementType->toString() + "[" + std::to_string(elementNum) + "]";
        auto it = cache.find(key);
        if (it != cache.end()) {
            return it->second;
        }

        auto instance = new ArrayType(elementType, elementNum);
        cache[key] = instance;
        return instance;
    }

    std::vector<int> ArrayType::getNumList() const {
        std::vector<int> res;
        res.push_back(elementNum);
        if (elementType->getTypeID() == Type::TypeID::ArrayTyID) {
            auto arrayType = dynamic_cast<ArrayType *>(elementType);
            res.insert(res.end(), arrayType->getNumList().begin(), arrayType->getNumList().end());
        }
        return res;
    }

    Type *ArrayType::getBaseType() const {
        Type *baseType = elementType;
        while (baseType->getTypeID() == Type::TypeID::ArrayTyID) {
            baseType = dynamic_cast<ArrayType *>(baseType)->getElementType();
        }
        return baseType;
    }

    std::string ArrayType::toString() const {
        return "[" + std::to_string(elementNum) + "x" + elementType->toString() + "]";
    }
} // ir