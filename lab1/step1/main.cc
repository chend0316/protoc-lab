#include <iostream>
#include <google/protobuf/compiler/command_line_interface.h>
#include <google/protobuf/compiler/cpp/cpp_generator.h>

#include <c_generator.h>  // 我们需要实现的编译器后端

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
    google::protobuf::compiler::CommandLineInterface cli;

    // 官方C++编译器后端
    google::protobuf::compiler::cpp::CppGenerator cpp_generator;
    cli.RegisterGenerator("--cpp_out", &cpp_generator, "Generate C++ source and header.");

    // 我们需要实现的编译器后端
    google::protobuf::compiler::c::CGenerator c_generator;
    cli.RegisterGenerator("--c_out", &c_generator, "Generate C header.");

    return cli.Run(argc, argv);
}
