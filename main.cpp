#include <iostream>
#include <csignal>
#include <thread>
#include <chrono>

// 信号处理函数
static void SigHandler(int32_t signum) 
{
    std::cout << "Signal Received Handler: " << signum << std::endl;
    std::cout << "Cleaning up and exiting..." << std::endl;
    // 这里可以添加你的清理逻辑
    exit(signum);
}

// 信号设置函数
static void SigSetup(void) 
{
    struct sigaction action;
    std::ignore = sigemptyset(&action.sa_mask);
    action.sa_handler = &SigHandler;
    action.sa_flags = 0;

    std::ignore = sigaction(SIGINT, &action, nullptr);
    std::ignore = sigaction(SIGTERM, &action, nullptr);
    std::ignore = sigaction(SIGQUIT, &action, nullptr);
    std::ignore = sigaction(SIGHUP, &action, nullptr);
}

int main() 
{
    // 设置信号处理
    SigSetup();

    std::cout << "Press Ctrl+C to terminate..." << std::endl;

    // 模拟程序持续运行
    while (true) 
    {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Program is running..." << std::endl;
    }

    return 0;
}
