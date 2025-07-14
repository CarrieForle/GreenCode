#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "zxing/core/src/ReadBarcode.h"
#include <string>
#include <windows.h>

int main(int argc, char **argv) {
    if (argc <= 1) {
        return 1;
    }

    const char *filename = argv[1];
    int width, height, n;
    unsigned char *data = stbi_load(filename, &width, &height, &n, 0);

    if (data == NULL) {
        return 1;
    }

    auto image = ZXing::ImageView(data, width, height, ZXing::ImageFormat::RGB);
    auto options = ZXing::ReaderOptions().setFormats(ZXing::BarcodeFormat::Any);
    auto barcodes = ZXing::ReadBarcodes(image, options);

    if (barcodes.size() <= 0) {
        return 1;
    }

    ZXing::Barcode barcode = barcodes[0];
    std::string text = barcode.text();
    std::wstring wtext;
    wtext.resize(MultiByteToWideChar(CP_UTF8, 0, text.c_str(), text.size() + 1, NULL, 0));
    MultiByteToWideChar(CP_UTF8, 0, text.data(), text.size(), wtext.data(), wtext.size());

    auto hMem = GlobalAlloc(GMEM_MOVEABLE, sizeof(wchar_t) * wtext.size());

    if (!hMem) {
        return 1;
    }

    memcpy(GlobalLock(hMem), wtext.c_str(), sizeof(wchar_t) * wtext.size());
    GlobalUnlock(hMem);

    if (!OpenClipboard(GetActiveWindow())) {
        return 1;
    }

    EmptyClipboard();
    SetClipboardData(CF_UNICODETEXT, hMem);
    CloseClipboard();
    GlobalFree(hMem);
    stbi_image_free(data);

    return 0;
} 