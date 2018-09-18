#ifndef MY_PROTOBUF_COMPILER_C_GENERATOR_H
#define MY_PROTOBUF_COMPILER_C_GENERATOR_H

#include <google/protobuf/compiler/code_generator.h>

namespace google {
namespace protobuf {
namespace compiler {
namespace c {

class CGenerator : public CodeGenerator {
    public:
        CGenerator();
        ~CGenerator();

        bool Generate(const FileDescriptor* file,
                        const string& parameter,
                        GeneratorContext* generator_context,
                        string* error) const;
};

}
}
}
}

#endif /* MY_PROTOBUF_COMPILER_C_GENERATOR_H */
