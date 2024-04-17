![C](https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=C)
# Shellcode Loader in C
💾 Information:
 * Size: 4-5kb✅

# ✨ For compilating use gcc:
```shell
gcc WindowsApi_Shellcode.c -o ux.exe -mwindows -nostdlib -nostartfiles -lkernel32 -s -Os -m32 -e _WinMain@16
```
