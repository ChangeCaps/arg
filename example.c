#include "arg.h"

struct args {
    char* input;
    char* output;

    bool  has_i;
    int   i;

    bool  has_f;
    float f;

    int c;
};

int main(int argc, const char** argv) {
    struct args args = {0};

    cmd main = cmd_new("example");
    cmd_help(main, "Example of arg library");

    arg input = cmd_arg(main, "input");
    arg_help (input, "input file");
    arg_value(input, &args.input, arg_str);

    arg out = cmd_arg(main, "output");
    arg_help (out, "output file");
    arg_usage(out, "<FILE>");
    arg_short(out, 'o');
    arg_long (out, "output");
    arg_value(out, &args.output, arg_str);

    arg i = cmd_arg(main, "i");
    arg_help (i, "some integer");
    arg_usage(i, "<INTEGER>");
    arg_short(i, 'i');
    arg_check(i, &args.has_i);
    arg_value(i, &args.i, arg_int);

    arg f = cmd_arg(main, "f");
    arg_help (f, "some float");
    arg_usage(f, "<FLOAT>");
    arg_short(f, 'f');
    arg_check(f, &args.has_f);
    arg_value(f, &args.f, arg_float);

    arg c = cmd_arg(main, "c");
    arg_help (c, "some count");
    arg_short(c, 'c');
    arg_value(c, &args.c, arg_count);

    cmd_parse(main, argc, argv);

    printf("input: %s\n", args.input);
    printf("output: %s\n", args.output);

    if (args.has_i) printf("i: %i\n", args.i);
    if (args.has_f) printf("f: %f\n", args.f);

    printf("c: %i\n", args.c);
}
