# REMCOM – SAS Comment Remover

**Because sometimes you just want the code without the chatter.**

SAS Comment Remover – Clean SAS Code in Seconds
The SAS Comment Remover is a lightweight, blazing-fast C++ command-line utility (REMCOM) designed to strip every type of comment from your SAS programs — including inline comments, macro comments, and block comments.
Whether you’re preparing SAS code for production, scrubbing years of legacy SAS scripts, or simply allergic to stray asterisks and slashes, the SAS Comment Remover leaves you with nothing but pure, uncompromised SAS code.
Built for speed and accuracy, the SAS Comment Remover ensures your SAS files are clean, consistent, and ready for analysis or deployment.

---

## Features

* Removes:

  * Standard SAS comments (`* comment;`)
  * Block comments (`/* comment */`)
  * Macro comments (`%* comment;`)
* Preserves:

  * All executable code
  * Whitespace and formatting
  * Your sanity
* Works on **any plain text SAS source file**

---

## Usage

```bash
remcom -i <input file> -o <output file>
```

### Example

```bash
remcom -i my_sas_code.sas -o my_sas_code_clean.sas
```

### Options

| Option         | Description                     |
| -------------- | ------------------------------- |
| `-h`, `--help` | Show help and usage information |
| `-i <file>`    | Specify input SAS file          |
| `-o <file>`    | Specify output SAS file         |

---

## Build Instructions

This is a standard C++ program. Compile it with any modern compiler:

### Windows (MSVC / Visual Studio)

```bash
cl remcom.cpp
```

### Linux / macOS (g++)

```bash
g++ -std=c++11 remcom.cpp -o remcom
```

---

## Why Remove Comments?

* **Cleaner diffs** – Comments can make it harder to spot real code changes.
* **Confidentiality** – Sometimes comments leak more than they should.
* **Preperation** for a Code Analysis Tool.
* **Aesthetic preference** – Minimalists unite.
* **Just because you can** – No judgment.

---

## Limitations

* This tool does not evaluate whether comments are *valuable*—it removes them all without remorse.
* Designed specifically for SAS syntax; other languages may produce unexpected results (or hilarity).

---

## License

© 2020 Data Centric Systems LLC
Licensed under the MIT License.

---

## Author

**Jimmy James**

> “I’m not against comments… I just think code should speak for itself.”

---

If you want, I can also make you a **matching fun ASCII banner** for this README so it stands out on GitHub without looking unprofessional. Would you like me to create that?
