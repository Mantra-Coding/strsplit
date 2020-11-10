<!-- Add badges here -->
<p>
<img alt="GitHub contributors" src="https://img.shields.io/github/contributors/Mantra-Coding/strsplit">
<img alt="GitHub issues" src="https://img.shields.io/github/issues-raw/Mantra-Coding/strsplit">
<img alt="GitHub" src="https://img.shields.io/github/license/Mantra-Coding/strsplit">
</p>

<p align="center">
<h1 align="center">strsplit</h1>
  <p align="center">
    Split a string into an array with ease ― in C
    <br />
    <a href="https://github.com/Mantra-Coding/strsplit/issues">Report Bug</a>
    ·
    <a href="https://github.com/Mantra-Coding/strsplit/issues">Request Feature</a>
  </p>
</p>

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [TODO](#todo)
- [Contributing](#contributing)
- [License](#license)

## Installation

1. Clone the repo

```sh
> git clone https://github.com/Mantra-Coding/strsplit
```

2. Move `strsplit.c` and `strsplit.h` into your project folder

## Usage

strsplit's signature is

```c
char** strsplit(char* string, char delimiter, int* length);
```

Where `char* string` is the string you want to split, `char delimiter` is the delimiter to separate strings and `int* length` is a pointer which will be the length of the resulting array.

```c
// Example: split a const string passed as parameter
#include "strsplit.h"

int main() {
	int words;
	char** split = strsplit("split this string into an array of strings", ' ', &words);
	for (int i = 0; i < words; i++) {
		printf("%s\n", split[i]);
	}
	/* Output:
	split
	this
	string
	into
	an
	array
	of
	strings
	*/
}

```

## TODO

- [x] Edge cases
  - [x] Handling of first position and-or last position delimiters in the input string.
  - [x] Support escape characters
  - [x] Handling consecutive double delimiters
- [x] Add Header File
- [x] Optimize performance (aka :wave: realloc)
- [ ] Error handling
- [x] Add license

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are greatly appreciated.

1. Fork the Project
2. Create your Feature Branch (git checkout -b feature/AmazingFeature)
3. Commit your Changes (git commit -m 'Add some AmazingFeature')
4. Push to the Branch (git push origin feature/AmazingFeature)
5. Open a Pull Reques

## License

Distributed under the MIT License. See `LICENSE` for more information.
