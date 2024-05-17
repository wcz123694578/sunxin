# MFC框架
1. Win32流程：
  - 设计窗口类
  - 注册窗口类
  - 产生、更新窗口
  - 消息循环
  - 将消息送到窗口过程处理
2. MFC框架：
  **编译链接时将WinMain函数链接到程序中**
  - 证明：在MFC源码中对_tWinMain函数设置断点，调试创建好的MFC程序，就能跳转到刚刚设置的断点。
    - _tWinMain实际上是一个宏，展开来就是WinMain
    - 全局变量在进入WinMain之前就分配了内存空间，所以C***App的对象就在进入WinMain之前就初始化了
      `CEx2App theApp  // 创建和管理Windows程序对象，有且只有一个。`
  - 注册窗口类流程
    ```
      /* WINMAIN.CPP */
      int AFXAPI AfxWinMain() {
        // ...
        pApp->InitInstance();
        // ...
      }

      /* 自己的 */
    ```
