
#include <string>

class Converter {
public:
  Converter() {};

  string add(a, b) {
    string instr = "/* Expand: " + a + " + " + b + " */";
    instr += " movq %[a],%%rax\n\t";
    instr += " movq $1,%%rbx\n\t";
    instr += " addq %%rbx,%%rax\n\t";
    instr += " movq %%rax,%[a]\n\t";
    return instr;
  }
};
