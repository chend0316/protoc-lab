
#include <hi_generator.h>
#include <iostream>

#include <google/protobuf/descriptor.h>
#include <google/protobuf/io/printer.h>
#include <google/protobuf/io/zero_copy_stream.h>

using std::cout;
using std::endl;

namespace google {
namespace protobuf {
namespace compiler {
namespace hi {

// replace `search' suffix in `s' to `replace'
string ReplaceSuffix(string s, string search, string replace) {
    if (s.substr(s.length() - search.length(), search.length()) == search) {
        return s.substr(0, s.length() - search.length()) + replace;
    }
    return s;
}

HiGenerator::HiGenerator() {}
HiGenerator::~HiGenerator() {}

bool HiGenerator::Generate(const FileDescriptor* file,
                            const string& parameter,
                            GeneratorContext* context,
                            string* error) const {
    string filename = file->name();
    string output_filename = ReplaceSuffix(filename, ".proto", ".txt");  // 文件名proto后缀替换为txt，这样xxx.proto的生成物就是xxx.txt

    std::unique_ptr<io::ZeroCopyOutputStream> output(context->Open(output_filename));
    GOOGLE_CHECK(output.get());
    io::Printer printer(output.get(), '$');  // 指定$符号作为模板变量的定界符（delimitation）

    printer.Print("Hello $file$!\n", "file", filename);  // file是一个模板变量，file变量的值是`filename'
    // 假设filename变量现在是"person.proto"，那么这里会被替换为"Hello person.proto!\n"

    for (int i = 0; i < file->message_type_count(); i++) {
        const Descriptor *message = file->message_type(i);
        printer.Print("Hello $message$!\n", "message", message->full_name());
    }

    return true;
}

}
}
}
}
