//
// Created by  on 2024-09-03.
//

#ifndef SYS_COMPILER_TYPE_H
#define SYS_COMPILER_TYPE_H

#include <string>
#include <stdexcept>
#include <vector>

namespace ir {
    // llvm Value 的类型
    // 每个类型都用缓存实现了唯一化，并重载了 == 与 != 运算符

    class Type {
    public:
        enum class TypeID {
            VoidTyID,
            LabelTyID,
            IntegerTyID,
            FloatTyID,
            FunctionTyID,
            PointerTyID,
            ArrayTyID,
        };

    public:
        // 获取类型的大小（字节）
        virtual int getSize() const = 0;

        // 转化为字符串
        virtual std::string toString() const = 0;

        // 获取类别码，注意不是直接判断是否为同一个类型。
        // 判断类型是否严格相等，可以用下面的重载运算符
        TypeID getTypeID() const { return ID; }

        // 重载 == 与 != 运算符，由于实现了类型唯一化，故而比较它们的地址即可
        bool operator==(const Type &other) const {
            return this == &other;
        }

        bool operator!=(const Type &other) const {
            return this != &other;
        }

    protected:
        explicit Type(TypeID tid) : ID(tid) {}
        ~Type() = default;

    private:
        TypeID ID;  // 种类码
    };


    class VoidType : public Type {
    public:
        static VoidType *get();

        std::string toString() const override;

        int getSize() const override { throw std::runtime_error("Cannot get size of void type"); }

    private:
        VoidType() : Type(Type::TypeID::VoidTyID) {}
    };

    class LabelType : public Type {
    public:
        static LabelType *get();

        std::string toString() const override;

        int getSize() const override { throw std::runtime_error("Cannot get size of label type"); }

    private:
        LabelType() : Type(Type::TypeID::LabelTyID) {}
    };


    class IntegerType : public Type {
    public:
        static IntegerType *get(int bits);

        std::string toString() const override;

        int getSize() const override { return bits / 8; }

    private:
        explicit IntegerType(int bits) : Type(Type::TypeID::IntegerTyID), bits(bits) {}
        int bits;  // 位宽
    };


    class FunctionType : public Type {
    public:
        static FunctionType *get(const std::vector<Type *> &formalArgs, Type *returnType);

        std::string toString() const override;

        int getSize() const override { throw std::runtime_error("Cannot get size of function type"); }

    private:
        FunctionType(const std::vector<Type *> &formalArgs, Type *returnType) :
                Type(Type::TypeID::FunctionTyID), formalArgs(formalArgs), returnType(returnType) {}
        std::vector<Type *> formalArgs;  // 参数类型
        Type *returnType;  // 返回值类型
    };


    class PointerType : public Type {
    public:
        static PointerType *get(Type *elementType);

        Type *getElementType() const { return elementType; }

        std::string toString() const override;

        int getSize() const override { return 4; }

    private:
        explicit PointerType(Type *elementType) : Type(Type::TypeID::PointerTyID), elementType(elementType) {}
        Type *elementType;  // 指向的类型
    };


    class ArrayType : public Type {
    public:
        static ArrayType *get(Type *elementType, int elementNum);

        int getElementNum() const { return elementNum; }

        Type *getElementType() const { return elementType; }

        std::vector<int> getNumList() const;

        Type *getBaseType() const;

        std::string toString() const override;

        int getSize() const override { return size; }

    private:
        explicit ArrayType(Type *elementType, int elementNum) :
        Type(Type::TypeID::ArrayTyID), elementType(elementType), elementNum(elementNum), size(elementType->getSize() * elementNum) {}

        Type *elementType;  // 基本元素类型，可以还是一个数组，将多维数组看成数组的一维数组
        int elementNum;  // 元素个数
        int size;  // 字节数
    };

} // ir

#endif //SYS_COMPILER_TYPE_H
