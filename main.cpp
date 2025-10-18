#include <unistd.h>
#include <string>
#include <cstring>

int main(int argc, const char** argv)
{
    int i=0;
    std::string command;

    while (argv[++i])
    {
        // Get a pointer to this token
        const char *arg = argv[i];
        
        // Does this token need quotes around it?
        bool needs_quote =  (arg[0] != '\'' && arg[0] != '\"' && strchr(arg, ' '));

        // If this isn't the first token, append a space
        if (i > 1) command += " ";

        // Append this token to our command
        if (needs_quote)
            command = command + "\"" + arg  + "\"";
        else
            command = command + arg;
    }

    // Run the command
    int rc = system(command.c_str());

    // Hand the return-code to the shell
    exit(rc >> 8);
}