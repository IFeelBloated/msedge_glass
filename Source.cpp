#include <string>
#include <windows.h>

auto wmain(int argc, const wchar_t** argv)->int {
    using namespace std::literals;
    auto si = STARTUPINFO{ .cb = sizeof(STARTUPINFO), .dwFlags = STARTF_USESHOWWINDOW, .wShowWindow = SW_HIDE };
    auto pi = PROCESS_INFORMATION{};
    auto cmd = L"msedge_internal.exe --disable-windows10-custom-titlebar"s;
    for (auto x = 1; x < argc; ++x)
        if (argv[x] != L"--disable-windows10-custom-titlebar"sv)
            cmd += L" "s + argv[x];
    CreateProcess(nullptr, cmd.data(), nullptr, nullptr, false, CREATE_NO_WINDOW, nullptr, nullptr, &si, &pi);
}