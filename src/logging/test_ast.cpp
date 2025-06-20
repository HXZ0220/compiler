#include "ast.hpp"

#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "usage: " << argv[0] << " <cminus_file>" << std::endl;
    } else {
        printf("1");
        auto s = parse(argv[1]);
        printf("2");
        auto a = AST(s);
        printf("3");
        auto printer = ASTPrinter();
        a.run_visitor(printer);
    }
    return 0;
}
