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
    ```C
      int AFXAPI AfxWinMain() {
        // ...
        pApp->InitInstance();   // 获取子类指针，调用子类InitInstance函数
        // ...
      }

      BOOL CEx2App::InitInstance()  {
        CSingleDocTemplate* pDocTemplate;
      	pDocTemplate = new CSingleDocTemplate(
	    	IDR_MAINFRAME,
	    	  RUNTIME_CLASS(CEx2Doc),
	    	  RUNTIME_CLASS(CMainFrame),       // main SDI frame window
	    	  RUNTIME_CLASS(CEx2View));
	      AddDocTemplate(pDocTemplate);

        // ...
        if (!pDocTemplate)
          return FALSE;
        AddDocTemplate(pDocTemplate);
        // ...
        m_pMainWnd->ShowWindow(SW_SHOW);    // m_pMainWnd指向程序框架窗口的指针
        m_pMainWnd->UpdateWindow();
      }
      
    ```
  - MFC封装窗口
    - 和Win32的区别：窗口句柄在CWnd里定义，CreateEx中保存句柄。
    - **CWnd的对象并不代表窗口，唯一联系的纽带是CWnd类内部的句柄成员变量。**<br/>
      ```c
      HWND是 Win32 SDK 的概念
      CWnd是将窗口的通用操作都封装进去，同时保存了窗口句柄
      ```
3. 在框架类中创建按钮
  1. 在OnCreate()最后写
    ```c
       /* PANIC: 这样定义是局部变量，会在OnCreate执行完以后销毁。所以要在类中定义成员变量 */
       CButton btn
       btn.Create(...); // this指向当前父窗口
    ```
  2. 在CMainFrame中定义私有的CButton对象
    ```c
      private:
        CButton m_btn;
    ```
