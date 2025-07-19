# GreenCode

A [Greenshot](https://github.com/greenshot/greenshot/) 
helper to scan barcodes. Only Windows is supported.

GreenCode allows you to scan barcodes 
such as QR codes from the screenshot/image, and save 
the decoded text into the clipboard. 

# Supported Formats

GreenCode can scan barcodes in following formats

| Linear product  | Linear industrial | Matrix             |
|-----------------|-------------------|--------------------|
| UPC-A           | Code 39           | QR Code            |
| UPC-E           | Code 93           | Micro QR Code      |
| EAN-8           | Code 128          | rMQR Code          |
| EAN-13          | Codabar           | Aztec              |
| DataBar         | DataBar Expanded  | DataMatrix         |
| DataBar Limited | DX Film Edge      | PDF417             |
|                 | ITF               | MaxiCode (partial) |

# Install (Greenshot)

Note: It's possible to use GreenCode as a standalone program, in which case you can just download the program and start. See [Usage](#usage).

Download the latest version [here](https://github.com/CarrieForle/GreenCode/releases).
Save it somewhere safe.
Open Greenshot and configure external commands. 
Supply "Barcode" in "name" field
and GreenCode's location in "Command" field. 
Click "Save".

Reopen Greenshot to apply the changes.

# Usage

Do a screenshot and click "Barcode". 
The decoded text should be in the clipboard 
and you can paste it (Ctrl+V).

You can also use it as a standalone program by 
launching GreenCode in the terminal
and passing the location of a barcode image.
The decoded text will be set in the clipboard.

For example
```
.\GreenCode.exe barcode.png
```

Since it works by reading image location from the 
argument, it's possible to integrate into other programs 
if they support it.

If GreenCode detects multiple barcodes,
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
