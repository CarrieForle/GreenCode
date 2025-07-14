# Barcode-screenshot

A [Greenshot](https://github.com/greenshot/greenshot/) 
helper to scan barcodes. Only Windows is supported.

Barcode-screenshot allows you to scan barcodes 
such as QR codes from the screenshot, and save 
the decoded text into the clipboard. 

# Supported Formats

Barcode-screenshot can scan barcodes in following formats

| Linear product  | Linear industrial | Matrix             |
|-----------------|-------------------|--------------------|
| UPC-A           | Code 39           | QR Code            |
| UPC-E           | Code 93           | Micro QR Code      |
| EAN-8           | Code 128          | rMQR Code          |
| EAN-13          | Codabar           | Aztec              |
| DataBar         | DataBar Expanded  | DataMatrix         |
| DataBar Limited | DX Film Edge      | PDF417             |
|                 | ITF               | MaxiCode (partial) |

# Install

Download the latest version from the Release page. 
Save it somewhere safe.
Open Greenshot and configure external commands. 
Supply "Barcode Scanner" in "name" field
and Barcode-screenshot's location in "Command" field
Click "Save".

Reopen Greenshot to apply the changes.

# Usage

Do a screenshot and click "Barcode Scanner". 
The decoded text should be in the clipboard 
and you can paste it (Ctrl+V).

You can also use it as a standalone program. 
By launching Barcode-screenshot in the terminal
and passing the location of a barcode image,
the decoded text will be set in the clipboard.

For example
```pwsh
.\barcode-scanner.exe barcode.png
```

If Barcode-screenshot detects multiple barcodes,
it will choose the first one it detected. It's 
therefore recommended that only 1 barcode is 
presented in a given image/screenshot.

If it did not work, it means the program did 
not detect any barcode.

# Build

Follow the instruction from [zxing-cpp](https://github.com/zxing-cpp/zxing-cpp) 
to build ZXing static library. 
You should produce a `libZXing.a` from the said
instruction and move it into `src/zxing` if 
it wasn't there already. Then run `build.ps1`.
The binary will be built in `build/`.

```pwsh
.\build.ps1
```