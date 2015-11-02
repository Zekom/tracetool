#pragma once

#include "..\..\Source\tracetool.h"

// NodeOperations dialog

class NodeOperations : public CPropertyPage
{
	DECLARE_DYNAMIC(NodeOperations)

public:
	NodeOperations();
	virtual ~NodeOperations();

   TraceNodeEx * start1 ;
   TraceNodeEx * start2 ;
   bool lastToggleBookmark ;
   bool lastToggleVisible ;


// Dialog Data
	//enum { IDD = IDD_NODEEX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
   afx_msg void OnBnClickedStart1();
   afx_msg void OnBnClickedResend();
   afx_msg void OnBnClickedSetselected();
   afx_msg void OnBnClickedStart2();
   afx_msg void OnBnClickedAppend();
   afx_msg void OnBnClickedShownode();

   afx_msg void OnBnClickedTooglebookmark();
   afx_msg void OnBnClickedTooglevisible();
};
