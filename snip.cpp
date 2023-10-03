/*
 * DESCRIPTION: snip, command line program in C++ to remove leading and trailing
 *                   whitespace from input lines based on the script name.
 *
 * VERSION: 23.10.2
 *
 * OPTIONS:
 * -h, --help    Display this message.
 *
 * AUTHOR: Jordi Roca
 * CREATED: 2023/10/02
 *
 * GITHUB: https://github.com/jordiroca/snip
 *
 * LICENSE: See LICENSE file.
 *
 */

#include <iostream>
#include <string>
#include <algorithm>

/*
######## ##     ## ##    ##  ######  ####  #######  ##    ## ########  ######  
##       ##     ## ###   ## ##    ##  ##  ##     ## ###   ## ##       ##    ## 
##       ##     ## ####  ## ##        ##  ##     ## ####  ## ##       ##       
######   ##     ## ## ## ## ##        ##  ##     ## ## ## ## ######    ######  
##       ##     ## ##  #### ##        ##  ##     ## ##  #### ##             ## 
##       ##     ## ##   ### ##    ##  ##  ##     ## ##   ### ##       ##    ## 
##        #######  ##    ##  ######  ####  #######  ##    ## ########  ######  
*/

// Snip leading whitespace.
std::string lsnip(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    return (start == std::string::npos) ? "" : str.substr(start);
}

// Snip trailing whitespace.
std::string rsnip(const std::string& str) {
    size_t end = str.find_last_not_of(" \t\n\r");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

// Snip both
std::string snip(const std::string& str) {
    return lsnip(rsnip(str));
}

/*
##     ## ######## ##       ########
##     ## ##       ##       ##     ##
##     ## ##       ##       ##     ##
######### ######   ##       ########
##     ## ##       ##       ##
##     ## ##       ##       ##
##     ## ######## ######## ##
*/

void printHelp() {
    std::cout << "Usage: [snip|lsnip|rsnip] [OPTION]... [FILE]...\n"
              << "Snip whitespace from each line of input.\n\n"
              << "Options:\n"
              << "  -h, --help       display this help and exit\n"
              << "If no FILE, read standard input.\n";
}

/*
##     ##    ###    #### ##    ##
###   ###   ## ##    ##  ###   ##
#### ####  ##   ##   ##  ####  ##
## ### ## ##     ##  ##  ## ## ##
##     ## #########  ##  ##  ####
##     ## ##     ##  ##  ##   ###
##     ## ##     ## #### ##    ##
*/

int main(int argc, char** argv) {
    std::string scriptName = argv[0];
    // Remove path
    size_t found = scriptName.find_last_of("/\\");
    scriptName = scriptName.substr(found + 1);

    if (argc > 1 && (std::string(argv[1]) == "-h" || std::string(argv[1]) == "--help")) {
        printHelp();
        return 0;
    }

    std::string line;
    while (std::getline(std::cin, line)) {
        if (scriptName == "snip") {
            std::cout << snip(line) << "\n";
        } else if (scriptName == "lsnip") {
            std::cout << lsnip(line) << "\n";
        } else if (scriptName == "rsnip") {
            std::cout << rsnip(line) << "\n";
        } else {
            std::cerr << "Invalid script name: " << scriptName << "\n";
            return 1;
        }
    }
    return 0;
}
