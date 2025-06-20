#include "Module.hpp"
#include "Function.hpp"
#include "GlobalVariable.hpp"

#include <memory>
#include <string>

Module::Module() {
    void_ty_ = std::make_unique<Type>(Type::VoidTyID, this);
    label_ty_ = std::make_unique<Type>(Type::LabelTyID, this);
    int1_ty_ = std::make_unique<IntegerType>(1, this);
    int8_ty_ = std::make_unique<IntegerType>(8, this);
    int32_ty_ = std::make_unique<IntegerType>(32, this);
    int64_ty_ = std::make_unique<IntegerType>(64, this);
    float32_ty_ = std::make_unique<FloatType>(this);
}

Type *Module::get_void_type() { return void_ty_.get(); }
Type *Module::get_label_type() { return label_ty_.get(); }
IntegerType *Module::get_int1_type() { return int1_ty_.get(); }
IntegerType *Module::get_int8_type() { return int8_ty_.get(); }
IntegerType *Module::get_int32_type() { return int32_ty_.get(); }
IntegerType *Module::get_int64_type() { return int64_ty_.get(); }
FloatType *Module::get_float_type() { return float32_ty_.get(); }
PointerType *Module::get_int8_ptr_type() {
    return get_pointer_type(int8_ty_.get());
}
PointerType *Module::get_int32_ptr_type() {
    return get_pointer_type(int32_ty_.get());
}
// PointerType *Module::get_int64_ptr_type() {
//     return get_pointer_type(int64_ty_.get());
// }
PointerType *Module::get_float_ptr_type() {
    return get_pointer_type(float32_ty_.get());
}


PointerType *Module::get_pointer_type(Type *contained) {
    if (pointer_map_.find(contained) == pointer_map_.end()) {
        pointer_map_[contained] = std::make_unique<PointerType>(contained);
    }
    return pointer_map_[contained].get();
}

ArrayType *Module::get_array_type(Type *contained, unsigned num_elements) {
    if (array_map_.find({contained, num_elements}) == array_map_.end()) {
        array_map_[{contained, num_elements}] =
            std::make_unique<ArrayType>(contained, num_elements);
    }
    return array_map_[{contained, num_elements}].get();
}

FunctionType *Module::get_function_type(Type *retty,
                                        std::vector<Type *> &args) {
    if (not function_map_.count({retty, args})) {
        function_map_[{retty, args}] =
            std::make_unique<FunctionType>(retty, args);
    }
    return function_map_[{retty, args}].get();
}

void Module::add_function(Function *f) { function_list_.push_back(f); }
llvm::ilist<Function> &Module::get_functions() { return function_list_; }
void Module::add_global_variable(GlobalVariable *g) {
    global_list_.push_back(g);
}
llvm::ilist<GlobalVariable> &Module::get_global_variable() {
    return global_list_;
}

void Module::set_print_name() {
    for (auto &func : this->get_functions()) {
        func.set_instr_name();
    }
    return;
}

std::string Module::print() {
    set_print_name();
    std::string module_ir;
    for (auto &global_val : this->global_list_) {
        module_ir += global_val.print();
        module_ir += "\n";
    }
    for (auto &func : this->function_list_) {
        module_ir += func.print();
        module_ir += "\n";
    }
    return module_ir;
}
