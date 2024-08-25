
# Custom Encryption/Decryption

This project features a custom encryption and decryption system implemented in C. This system uses various encodings to ensure data security.

## Contents

- [Description](#description)
- [How It Works](#how-it-works)
- [Illustrative Images](#illustrative-images)
- [Installation and Usage](#installation-and-usage)
- [Author](#author)

## Description

This custom encryption system employs the following encodings:

- **Binary Encoding**
- **Hexadecimal Encoding**
- **Decimal Encoding**

Random characters and the word "Hunter" are inserted to increase the complexity of the encryption.

## How It Works

### Encryption

1. **Encoding the Data:**
   - The original data is converted into binary, hexadecimal, and decimal representations based on random selection.
   - Random characters and the word "Hunter" are included in the encrypted text to add complexity.

2. **Final Result:**
   - An encrypted string is produced, with a length ranging between 30 and 64 characters, containing the encoded data and random characters.

### Decryption

1. **Removing Unnecessary Characters:**
   - Words like "Hunter" and random characters are skipped.

2. **Decoding:**
   - Encoded parts of the text are converted back into the original data using the various encodings.

## Illustrative Images

### Binary Encoding

![Binary Encoding](https://upload.wikimedia.org/wikipedia/commons/thumb/2/2e/ASCII_code.svg/1920px-ASCII_code.svg.png)

### Hexadecimal Encoding

![Hexadecimal Encoding](https://upload.wikimedia.org/wikipedia/commons/thumb/7/7e/Hexadecimal-hexadecimal.svg/1920px-Hexadecimal-hexadecimal.svg.png)

### Decimal Encoding

![Decimal Encoding](https://upload.wikimedia.org/wikipedia/commons/thumb/5/58/Decimal-to-binary_conversion_table.svg/1920px-Decimal-to-binary_conversion_table.svg.png)

## Installation and Usage

### Installation

1. Ensure that **GCC** and the **OpenSSL** library are installed on your system.

2. Compile the program using the following command:

   ```sh
   gcc -o decrypt main.c
   ```

### Usage

To run the program, use the following command:

```sh
./decrypt
```

The encrypted text is embedded in the source code, and you will see the decrypted text upon running the program.

## Author

Author: **The Hunter**
