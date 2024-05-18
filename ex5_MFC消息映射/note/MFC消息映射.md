# MFC 消息映射

- 当用VC6的类向导创建消息响应的函数，会在类中注释宏创建函数原形声明
  ```cpp
  protected:
	  //{{AFX_MSG(CEx5_MFCView)
	  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	  //}}AFX_MSG
	  DECLARE_MESSAGE_MAP()
  ```
  然后会在源文件生成一个入口里面有消息映射入口项
  ```cpp
  BEGIN_MESSAGE_MAP(CEx5_MFCView, CView)
  	//{{AFX_MSG_MAP(CEx5_MFCView)
  	ON_WM_LBUTTONDOWN()
  	//}}AFX_MSG_MAP
  	// Standard printing commands
  	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
  	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
  	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
  END_MESSAGE_MAP()
  ```
  接着就是实现消息响应函数了。
2. CDC
  - 对hdc操作的封装
  - `CDC *pdc = GetDC();`
  - `ReleaseDC(pdc);`

3. ClientDC

4. FromHandle
  - 返回指向CBrush指针
  - 如果想设置成空画刷，就
    ```cpp
       ClientDC dc(this);

       CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
       CBrush *pOldBrush = dc.SelectObject(pBrush);
    ```
    SelectObject(pBrush)返回要被替换的画刷的指针，也就是之前的画刷的指针。同时也将窗口的画刷设置成现在的画刷。
