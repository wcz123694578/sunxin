# MFC ��Ϣӳ��

- ����VC6�����򵼴�����Ϣ��Ӧ�ĺ�������������ע�ͺ괴������ԭ������
  ```cpp
  protected:
	  //{{AFX_MSG(CEx5_MFCView)
	  afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	  //}}AFX_MSG
	  DECLARE_MESSAGE_MAP()
  ```
  Ȼ�����Դ�ļ�����һ�������������Ϣӳ�������
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
  ���ž���ʵ����Ϣ��Ӧ�����ˡ�
2. CDC
  - ��hdc�����ķ�װ
  - `CDC *pdc = GetDC();`
  - `ReleaseDC(pdc);`

3. ClientDC

4. FromHandle
  - ����ָ��CBrushָ��
  - ��������óɿջ�ˢ����
    ```cpp
       ClientDC dc(this);

       CBrush *pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
       CBrush *pOldBrush = dc.SelectObject(pBrush);
    ```
    SelectObject(pBrush)����Ҫ���滻�Ļ�ˢ��ָ�룬Ҳ����֮ǰ�Ļ�ˢ��ָ�롣ͬʱҲ�����ڵĻ�ˢ���ó����ڵĻ�ˢ��
