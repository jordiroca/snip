# snip

A lightweight C++ application to remove leading and trailing whitespace from stdin, depending on the executable's name (`snip`, `lsnip`, `rsnip`).

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Additional Information](#additional-information)
- [License](#license)

## Installation

### Prerequisites

- [C++](https://en.wikipedia.org/wiki/C%2B%2B)

I am using Apple clang version 15.0.0 (clang-1500.0.40.1)

### Building from Source

Clone the repository and navigate into the project directory:

```bash
git clone https://github.com/jordiroca/snip.git
cd snip
```

Build the binaries:

```bash
g++ snip.cpp -o snip
cp snip lsnip
cp snip rsnip

# Copy the programs under your PATH:

sudo mv snip lsnip rsnip /usr/local/bin/
```

## Usage

Use the respective binary to snip input from the command line.

Examples:

### snip

Remove leading and trailing whitespace:

```bash
echo -e "  hello \n world  " | snip
```

### lsnip

Remove leading whitespace:

```bash
echo -e "  hello \n world  " | lsnip
```

### rsnip

Remove trailing whitespace:

```bash
echo -e "  hello \n world  " | rsnip
```

Note: Ensure that the name of the executable binary (`snip`, `lsnip`, `rsnip`) matches the desired snipming operation.

## Additional Information

### Contributing

Feel free to submit PRs, issues, or any other feedback! You'll be welcomed and appreciated.

### Support

For issues using `snip`, please create a [GitHub issue](https://github.com/jordiroca/snip/issues).

## License

See [LICENSE](LICENSE) for more information.
