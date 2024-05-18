# MFC���
1. Win32���̣�
  - ��ƴ�����
  - ע�ᴰ����
  - ���������´���
  - ��Ϣѭ��
  - ����Ϣ�͵����ڹ��̴���
2. MFC��ܣ�
  **��������ʱ��WinMain�������ӵ�������**
  - ֤������MFCԴ���ж�_tWinMain�������öϵ㣬���Դ����õ�MFC���򣬾�����ת���ո����õĶϵ㡣
    - _tWinMainʵ������һ���꣬չ��������WinMain
    - ȫ�ֱ����ڽ���WinMain֮ǰ�ͷ������ڴ�ռ䣬����C***App�Ķ�����ڽ���WinMain֮ǰ�ͳ�ʼ����
      `CEx2App theApp  // �����͹���Windows�����������ֻ��һ����`
  - ע�ᴰ��������
    ```C
      int AFXAPI AfxWinMain() {
        // ...
        pApp->InitInstance();   // ��ȡ����ָ�룬��������InitInstance����
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
        m_pMainWnd->ShowWindow(SW_SHOW);    // m_pMainWndָ������ܴ��ڵ�ָ��
        m_pMainWnd->UpdateWindow();
      }
      
    ```
  - MFC��װ����
    - ��Win32�����𣺴��ھ����CWnd�ﶨ�壬CreateEx�б�������
    - **CWnd�Ķ��󲢲������ڣ�Ψһ��ϵ��Ŧ����CWnd���ڲ��ľ����Ա������**<br/>
      ```c
      HWND�� Win32 SDK �ĸ���
      CWnd�ǽ����ڵ�ͨ�ò�������װ��ȥ��ͬʱ�����˴��ھ��
      ```
3. �ڿ�����д�����ť
  1. ��OnCreate()���д
    ```c
       /* PANIC: ���������Ǿֲ�����������OnCreateִ�����Ժ����١�����Ҫ�����ж����Ա���� */
       CButton btn
       btn.Create(...); // thisָ��ǰ������
    ```
  2. ��CMainFrame�ж���˽�е�CButton����
    ```c
      private:
        CButton m_btn;
    ```
