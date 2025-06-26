#include <windows.h>
#include <iostream>
#include <chrono>
#include <thread>

void LogData(){
    for (int i = 0; i < 10; i++){
        MEMORYSTATUSEX memStatus;
        SYSTEM_INFO sysInfo;
        GetSystemInfo(&sysInfo);
        printf("oem id: %u\n", sysInfo.dwOemId);
        printf("no of processors: %d\n", sysInfo.dwNumberOfProcessors);
        printf("page size: %u\n", sysInfo.dwPageSize);
        printf("Processor type: %u\n", sysInfo.dwProcessorType); 
        printf("Minimum application address: %lx\n", sysInfo.lpMinimumApplicationAddress); 
        printf("Maximum application address: %lx\n", sysInfo.lpMaximumApplicationAddress); 
        printf("Active processor mask: %u\n", sysInfo.dwActiveProcessorMask); 

        std::this_thread::sleep_for(std::chrono::seconds(5));
    }
    
}
int main(){
    
    std::thread second(LogData);
    second.join();
    std::cin.get();
}