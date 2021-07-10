﻿#include "utils.h"
#include <cassert>
#include <Windows.h> // For Win32 API

namespace lxd {
	std::wstring GetPathOfExe() {
        // Get filename with full path for current process EXE
        wchar_t filename[MAX_PATH];
        DWORD result = ::GetModuleFileName(
            nullptr,    // retrieve path of current process .EXE
            filename,
            _countof(filename)
        );
        assert(result);

        return filename;
	}

	std::wstring GetDirOfExe() {
        auto exe = GetPathOfExe();
        auto offset = exe.rfind('\\');
        assert(offset);

        return exe.substr(0, offset);
	}

    std::wstring GetExeName() {
        auto exe = GetPathOfExe();
        auto slash = exe.rfind('\\');
        auto dot = exe.rfind(L".exe");
        assert(slash && dot);
        assert(slash < dot && dot < exe.size());
        return exe.substr(slash + 1, dot - slash - 1);
    }
}