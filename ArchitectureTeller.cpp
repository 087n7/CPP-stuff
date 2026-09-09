#include <iostream>
#include <string>
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/utsname.h>
#endif

#ifndef PROCESSOR_ARCHITECTURE_ARM
#define PROCESSOR_ARCHITECTURE_ARM 5
#endif

#ifndef PROCESSOR_ARCHITECTURE_IA64
#define PROCESSOR_ARCHITECTURE_IA64 6
#endif

#ifndef PROCESSOR_ARCHITECTURE_AMD64
#define PROCESSOR_ARCHITECTURE_AMD64 9
#endif

#ifndef PROCESSOR_ARCHITECTURE_ARM64
#define PROCESSOR_ARCHITECTURE_ARM64 12
#endif

#ifndef PROCESSOR_ARCHITECTURE_RISCV64
#define PROCESSOR_ARCHITECTURE_RISCV64 13
#endif

std::string getNormalizedArchitecture() {

#ifdef _WIN32
    SYSTEM_INFO sysInfo{};
    GetNativeSystemInfo(&sysInfo);
    switch (sysInfo.wProcessorArchitecture) {
        case PROCESSOR_ARCHITECTURE_AMD64:
            return "x86_64";
        case PROCESSOR_ARCHITECTURE_INTEL:
            return "x86";
        case PROCESSOR_ARCHITECTURE_ARM64:
            return "aarch64";
        case PROCESSOR_ARCHITECTURE_ARM:
            return "arm";
        case PROCESSOR_ARCHITECTURE_IA64:
            return "ia64";
        case PROCESSOR_ARCHITECTURE_RISCV64:
            return "riscv64";
        default:
            return "unknown";
    }
#else
    utsname sys_info{};
    if (uname(&sys_info) != 0) {
        return "unknown";
    }
    std::string arch = sys_info.machine;

    if (arch == "x86_64" ||
        arch == "amd64" ||
        arch == "AMD64") {
        return "x86_64";
    }

    if (arch == "i386" ||
        arch == "i486" ||
        arch == "i586" ||
        arch == "i686" ||
        arch == "x86") {
        return "x86";
    }

    if (arch == "aarch64" ||
        arch == "arm64" ||
        arch == "ARM64") {
        return "aarch64";
    }

    if (arch.rfind("arm", 0) == 0 ||
        arch.rfind("ARM", 0) == 0) {
        return "arm";
    }

    if (arch == "riscv64" ||
        arch == "riscv64gc") {
        return "riscv64";
    }

    if (arch == "riscv32" ||
        arch == "riscv32gc") {
        return "riscv32";
    }

    if (arch == "ppc64le") {
        return "ppc64le";
    }

    if (arch == "ppc64" ||
        arch == "powerpc64") {
        return "ppc64";
    }

    if (arch == "ppc" ||
        arch == "powerpc" ||
        arch == "powerpcspe") {
        return "ppc";
    }

    if (arch == "mips64" ||
        arch == "mips64el" ||
        arch == "mips64n32") {
        return "mips64";
    }

    if (arch == "mips" ||
        arch == "mipsel") {
        return "mips";
    }

    if (arch == "s390x") {
        return "s390x";
    }

    if (arch == "s390") {
        return "s390";
    }

    if (arch == "sparc64") {
        return "sparc64";
    }

    if (arch == "sparc" ||
        arch == "sparcv8") {
        return "sparc";
    }

    if (arch == "ia64") {
        return "ia64";
    }

    if (arch == "alpha") {
        return "alpha";
    }

    if (arch == "parisc64") {
        return "parisc64";
    }

    if (arch == "parisc" ||
        arch == "hppa") {
        return "hppa";
    }

    if (arch == "m68k") {
        return "m68k";
    }

    if (arch == "sh4" ||
        arch == "sh") {
        return "sh";
    }

    if (arch == "loongarch64") {
        return "loongarch64";
    }

    if (arch == "loongarch32") {
        return "loongarch32";
    }

    if (arch == "wasm32") {
        return "wasm32";
    }

    if (arch == "wasm64") {
        return "wasm64";
    }

    if (arch == "e2k") {
        return "e2k";
    }

    if (arch == "arc") {
        return "arc";
    }

    if (arch == "arc64") {
        return "arc64";
    }

    if (arch == "or1k" ||
        arch == "openrisc") {
        return "openrisc";
    }

    if (arch == "blackfin") {
        return "blackfin";
    }

    if (arch == "xtensa") {
        return "xtensa";
    }

    if (arch == "microblaze") {
        return "microblaze";
    }

    return arch;
#endif
}

bool is64BitArchitecture(const std::string& arch) {
    return
        arch == "x86_64" ||
        arch == "aarch64" ||
        arch == "riscv64" ||
        arch == "ppc64" ||
        arch == "ppc64le" ||
        arch == "mips64" ||
        arch == "s390x" ||
        arch == "sparc64" ||
        arch == "ia64" ||
        arch == "parisc64" ||
        arch == "loongarch64" ||
        arch == "wasm64" ||
        arch == "arc64";
}

bool is32BitArchitecture(const std::string& arch) {
    return
        arch == "x86" ||
        arch == "arm" ||
        arch == "riscv32" ||
        arch == "ppc" ||
        arch == "mips" ||
        arch == "s390" ||
        arch == "sparc" ||
        arch == "hppa" ||
        arch == "loongarch32" ||
        arch == "wasm32" ||
        arch == "arc" ||
        arch == "openrisc" ||
        arch == "blackfin" ||
        arch == "xtensa" ||
        arch == "microblaze";
}

int main() {
    std::string architecture = getNormalizedArchitecture();
    std::cout << "Detected Architecture: "
              << architecture << "\n";
    if (is64BitArchitecture(architecture)) {
        std::cout << "YES: Supported 64-bit architecture.\n";
        return 0;
    } else if (is32BitArchitecture(architecture)) {
        std::cout << "YES: Supported 32-bit architecture.\n";
        return 0;
    }
    if (architecture == "m68k" ||
        architecture == "alpha" ||
        architecture == "e2k" ||
        architecture == "sh") {
        std::cout << "YES: Supported architecture.\n";
        return 0;
    }
    std::cout << "NO: Unsupported architecture.\n";
    return 1;
}
