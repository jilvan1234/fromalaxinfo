////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2006-2012
// Created by Roman Ryltsov roman@alax.info
// 
// $Id$
//
// A permission to use the source code is granted as long as reference to 
// source website http://alax.info is retained.

#pragma once

//#include <commctrl.h>
#include <atlcrack.h>

////////////////////////////////////////////////////////////
// Notification cracking macros

#define CC_MSG_WM_COMMAND(nCode, nIdentifier, Function) \
	if(uMsg == WM_COMMAND && HIWORD(wParam)->code == nCode && LOWORD(wParam) == nIdentifier) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = Function((UINT) HIWORD(wParam), (INT) LOWORD(wParam), (HWND) lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}

#define CC_MSG_WM_NOTIFY(nCode, Structure, nIdentifier, Function) \
	if(uMsg == WM_NOTIFY && ((NMHDR*) lParam)->code == nCode && ((NMHDR*) lParam)->idFrom == nIdentifier) \
	{ \
		SetMsgHandled(TRUE); \
		lResult = Function((Structure*) lParam); \
		if(IsMsgHandled()) \
			return TRUE; \
	}

#define MSG_NM_OUTOFMEMORY(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_OUTOFMEMORY, NMHDR, nIdentifier, Function)
#define MSG_NM_CLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CLICK, NMHDR, nIdentifier, Function) // NMCLICK?
#define MSG_NM_DBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_DBLCLK, NMHDR, nIdentifier, Function)
#define MSG_NM_RETURN(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RETURN, NMHDR, nIdentifier, Function)
#define MSG_NM_RCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RCLICK, NMHDR, nIdentifier, Function) // NMCLICK?
#define MSG_NM_RDBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RDBLCLK, NMHDR, nIdentifier, Function)
#define MSG_NM_SETFOCUS(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_SETFOCUS, NMHDR, nIdentifier, Function)
#define MSG_NM_KILLFOCUS(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_KILLFOCUS, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#define MSG_NM_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMCUSTOMDRAW, nIdentifier, Function)
#define MSG_NM_HOVER(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_HOVER, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_NM_NCHITTEST(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_NCHITTEST, NMMOUSE, nIdentifier, Function)
#define MSG_NM_KEYDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_KEYDOWN, NMKEY, nIdentifier, Function)
#define MSG_NM_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
#define MSG_NM_SETCURSOR(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_SETCURSOR, NMMOUSE, nIdentifier, Function)
#define MSG_NM_CHAR(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CHAR, NMCHAR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#if (_WIN32_IE >= 0x0401)
#define MSG_NM_TOOLTIPSCREATED(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_TOOLTIPSCREATED, NMTOOLTIPSCREATED, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0401)
#if (_WIN32_IE >= 0x0500)
#define MSG_NM_LDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_LDOWN, NMHDR, nIdentifier, Function)
#define MSG_NM_RDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RDOWN, NMHDR, nIdentifier, Function)
#define MSG_NM_THEMECHANGED(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_THEMECHANGED, NMKEY, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0500)

#if !defined(NOUSER)
#endif // !defined(NOUSER)

#if !defined(NOIMAGEAPIS)
#endif // !defined(NOIMAGEAPIS)

#if !defined(NOHEADER)
#define MSG_HDN_RCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RCLICK, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#define MSG_HDN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMCUSTOMDRAW, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_HDN_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_HDN_ITEMCHANGING(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_ITEMCHANGING, NMHEADER, nIdentifier, Function)
#define MSG_HDN_ITEMCHANGED(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_ITEMCHANGED, NMHEADER, nIdentifier, Function)
#define MSG_HDN_ITEMCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_ITEMCLICK, NMHEADER, nIdentifier, Function)
#define MSG_HDN_ITEMDBLCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_ITEMDBLCLICK, NMHEADER, nIdentifier, Function)
#define MSG_HDN_DIVIDERDBLCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_DIVIDERDBLCLICK, NMHEADER, nIdentifier, Function)
#define MSG_HDN_BEGINTRACK(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_BEGINTRACK, NMHEADER, nIdentifier, Function)
#define MSG_HDN_ENDTRACK(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_ENDTRACK, NMHEADER, nIdentifier, Function)
#define MSG_HDN_TRACK(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_TRACK, NMHEADER, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#define MSG_HDN_GETDISPINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_GETDISPINFO, NMHDDISPINFO, nIdentifier, Function)
#define MSG_HDN_BEGINDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_BEGINDRAG, NMHEADER, nIdentifier, Function)
#define MSG_HDN_ENDDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_ENDDRAG, NMHEADER, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0500)
#define MSG_HDN_FILTERCHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_FILTERCHANGE, NMHEADER, nIdentifier, Function)
#define MSG_HDN_FILTERBTNCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(HDN_FILTERBTNCLICK, NMHDFILTERBTNCLICK, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0500)
#endif // !defined(NOHEADER)

#if !defined(NOTOOLBAR)
#define MSG_TBN_RCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RCLICK, NMMOUSE, nIdentifier, Function)
#define MSG_TBN_RDBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RDBLCLK, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_TBN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMTBCUSTOMDRAW, nIdentifier, Function) // NMCUSTOMDRAW prior to 4.71
#else
#define MSG_TBN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMCUSTOMDRAW, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_TBN_KEYDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_KEYDOWN, NMKEY, nIdentifier, Function)
#define MSG_TBN_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
#define MSG_TBN_CHAR(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CHAR, NMCHAR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#if (_WIN32_IE >= 0x0401)
#define MSG_TBN_TOOLTIPSCREATED(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_TOOLTIPSCREATED, NMTOOLTIPSCREATED, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0401)
#if (_WIN32_IE >= 0x0500)
#define MSG_TBN_LDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_LDOWN, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0500)
#if !defined(_UNICODE)
#define MSG_TBN_GETBUTTONINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_GETBUTTONINFO, NMTOOLBAR, nIdentifier, Function)
#endif // !defined(_UNICODE)
#define MSG_TBN_BEGINDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_BEGINDRAG, NMTOOLBAR, nIdentifier, Function)
#define MSG_TBN_ENDDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_ENDDRAG, NMTOOLBAR, nIdentifier, Function)
#define MSG_TBN_BEGINADJUST(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_BEGINADJUST, NMTOOLBAR, nIdentifier, Function)
#define MSG_TBN_ENDADJUST(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_ENDADJUST, NMTOOLBAR, nIdentifier, Function)
#define MSG_TBN_RESET(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_RESET, NMHDR, nIdentifier, Function)
#define MSG_TBN_QUERYINSERT(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_QUERYINSERT, NMTOOLBAR, nIdentifier, Function)
#define MSG_TBN_QUERYDELETE(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_QUERYDELETE, NMTOOLBAR, nIdentifier, Function)
#define MSG_TBN_TOOLBARCHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_TOOLBARCHANGE, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#define MSG_TBN_DROPDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_DROPDOWN, NMTOOLBAR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_TBN_GETOBJECT(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_GETOBJECT, NMOBJECTNOTIFY, nIdentifier, Function)
#define MSG_TBN_HOTITEMCHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_HOTITEMCHANGE, NMTBHOTITEM, nIdentifier, Function)
#define MSG_TBN_DRAGOUT(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_DRAGOUT, NMTOOLBAR, nIdentifier, Function)
#define MSG_TBN_DELETINGBUTTON(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_DELETINGBUTTON, NMTOOLBAR, nIdentifier, Function)
#define MSG_TBN_GETDISPINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_GETDISPINFOA, NMTBDISPINFO, nIdentifier, Function)
#define MSG_TBN_GETINFOTIP(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_GETINFOTIPW, NMTBDISPINFO, nIdentifier, Function)
#if defined(_UNICODE)
#define MSG_TBN_GETBUTTONINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_GETBUTTONINFO, NMTOOLBAR, nIdentifier, Function)
#endif // defined(_UNICODE)
#endif // (_WIN32_IE >= 0x0400)
#if (_WIN32_IE >= 0x0500)
#define MSG_TBN_RESTORE(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_RESTORE, NMRESTORE, nIdentifier, Function)
#define MSG_TBN_SAVE(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_SAVE, NMSAVE, nIdentifier, Function)
#define MSG_TBN_INITCUSTOMIZE(nIdentifier, Function) CC_MSG_WM_NOTIFY(TBN_INITCUSTOMIZE, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0500)
#endif // !defined(NOTOOLBAR)

#if !defined(NOREBAR)
#if (_WIN32_IE >= 0x0300)
#define MSG_RBN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMCUSTOMDRAW, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_RBN_NCHITTEST(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_NCHITTEST, NMMOUSE, nIdentifier, Function)
#define MSG_RBN_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_RBN_HEIGHTCHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_HEIGHTCHANGE, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0400)
#define MSG_RBN_GETOBJECT(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_GETOBJECT, NMOBJECTNOTIFY, nIdentifier, Function)
#define MSG_RBN_LAYOUTCHANGED(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_LAYOUTCHANGED, NMHDR, nIdentifier, Function)
#define MSG_RBN_AUTOSIZE(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_AUTOSIZE, NMRBAUTOSIZE, nIdentifier, Function)
#define MSG_RBN_BEGINDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_BEGINDRAG, NMREBAR, nIdentifier, Function)
#define MSG_RBN_ENDDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_ENDDRAG, NMREBAR, nIdentifier, Function)
#define MSG_RBN_DELETINGBAND(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_DELETINGBAND, NMREBAR, nIdentifier, Function)
#define MSG_RBN_DELETEDBAND(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_DELETEDBAND, NMREBAR, nIdentifier, Function)
#define MSG_RBN_CHILDSIZE(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_CHILDSIZE, NMREBARCHILDSIZE, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#if (_WIN32_IE >= 0x0500)
#define MSG_RBN_CHEVRONPUSHED(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_CHEVRONPUSHED, NMREBARCHEVRON, nIdentifier, Function)
#define MSG_RBN_MINMAX(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_MINMAX, NMHDR, nIdentifier, Function) // MSDN does not specify header type
#endif // (_WIN32_IE >= 0x0500)
#if (_WIN32_WINNT >= 0x0501)
#define MSG_RBN_AUTOBREAK(nIdentifier, Function) CC_MSG_WM_NOTIFY(RBN_AUTOBREAK, NMREBARAUTOBREAK, nIdentifier, Function)
#endif // (_WIN32_WINNT >= 0x0501)
#endif // !defined(NOREBAR)

#if !defined(NOIMAGEAPIS)
#endif // !defined(NOIMAGEAPIS)

#if !defined(NOTOOLTIPS)
#if (_WIN32_IE >= 0x0300)
#define MSG_TTN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMTTCUSTOMDRAW, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#define MSG_TTN_GETDISPINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(TTN_GETDISPINFO, NMTTDISPINFO, nIdentifier, Function)
#define MSG_TTN_SHOW(nIdentifier, Function) CC_MSG_WM_NOTIFY(TTN_SHOW, NMHDR, nIdentifier, Function)
#define MSG_TTN_POP(nIdentifier, Function) CC_MSG_WM_NOTIFY(TTN_POP, NMHDR, nIdentifier, Function)
#define MSG_TTN_LINKCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(TTN_LINKCLICK, NMHDR, nIdentifier, Function)
#endif // !defined(NOTOOLTIPS)

#if !defined(NOSTATUSBAR)
#define MSG_SBN_CLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CLICK, NMMOUSE, nIdentifier, Function)
#define MSG_SBN_DBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_DBLCLK, NMMOUSE, nIdentifier, Function)
#define MSG_SBN_RCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RCLICK, NMMOUSE, nIdentifier, Function)
#define MSG_SBN_RDBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RDBLCLK, NMMOUSE, nIdentifier, Function)
#if (_WIN32_IE >= 0x0400)
#define SBN_SIMPLEMODECHANGE    (SBN_FIRST - 0)
#endif // (_WIN32_IE >= 0x0400)
#endif // !defined(NOSTATUSBAR)

#if !defined(NOMENUHELP)
#endif // !defined(NOMENUHELP)

#if !defined(NOTRACKBAR)
//#if (_WIN32_IE >= 0x0300)
//#define MSG_TBN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMCUSTOMDRAW, nIdentifier, Function)
//#endif // (_WIN32_IE >= 0x0300)
//#if (_WIN32_IE >= 0x0400)
//#define MSG_TBN_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
//#endif // (_WIN32_IE >= 0x0400)
#endif // !defined(NOTRACKBAR)

#if !defined(NODRAGLIST)
//#define MSG_DL_BEGINDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(DL_BEGINDRAG, DRAGLISTINFO, nIdentifier, Function)
//#define MSG_DL_DRAGGING(nIdentifier, Function) CC_MSG_WM_NOTIFY(DL_DRAGGING, DRAGLISTINFO, nIdentifier, Function)
//#define MSG_DL_DROPPED(nIdentifier, Function) CC_MSG_WM_NOTIFY(DL_DROPPED, DRAGLISTINFO, nIdentifier, Function)
//#define MSG_DL_CANCELDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(DL_CANCELDRAG, DRAGLISTINFO, nIdentifier, Function)
#endif // !defined(NODRAGLIST)

#if !defined(NOUPDOWN)
#if (_WIN32_IE >= 0x0400)
#define MSG_UDN_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_UDN_DELTAPOS(nIdentifier, Function) CC_MSG_WM_NOTIFY(UDN_DELTAPOS, NMUPDOWN, nIdentifier, Function)
#endif // !defined(NOUPDOWN)

#if !defined(NOPROGRESS)
#endif // !defined(NOPROGRESS)

#if !defined(NOHOTKEY)
#endif // !defined(NOHOTKEY)

#if !defined(NOLISTVIEW)
#if (_WIN32_IE >= 0x0400)
#define MSG_LVN_CLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CLICK, NMITEMACTIVATE, nIdentifier, Function) // NMHDR prior to 4.71
#define MSG_LVN_DBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_DBLCLK, NMITEMACTIVATE, nIdentifier, Function) // NMHDR prior to 4.71
#else
#define MSG_LVN_CLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CLICK, NMHDR, nIdentifier, Function)
#define MSG_LVN_DBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_DBLCLK, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_LVN_RETURN(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RETURN, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0400)
#define MSG_LVN_RCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RCLICK, NMITEMACTIVATE, nIdentifier, Function) // NMHDR prior to 4.71
#define MSG_LVN_RDBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RDBLCLK, NMITEMACTIVATE, nIdentifier, Function) // NMHDR prior to 4.71
#else
#define MSG_LVN_RCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RCLICK, NMHDR, nIdentifier, Function)
#define MSG_LVN_RDBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RDBLCLK, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_LVN_SETFOCUS(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_SETFOCUS, NMHDR, nIdentifier, Function)
#define MSG_LVN_KILLFOCUS(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_KILLFOCUS, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#define MSG_LVN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMLVCUSTOMDRAW, nIdentifier, Function)
#define MSG_LVN_HOVER(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_HOVER, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_LVN_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_LVN_ITEMCHANGING(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ITEMCHANGING, NMLISTVIEW, nIdentifier, Function)
#define MSG_LVN_ITEMCHANGED(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ITEMCHANGED, NMLISTVIEW, nIdentifier, Function)
#define MSG_LVN_INSERTITEM(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_INSERTITEM, NMLISTVIEW, nIdentifier, Function)
#define MSG_LVN_DELETEITEM(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_DELETEITEM, NMLISTVIEW, nIdentifier, Function)
#define MSG_LVN_DELETEALLITEMS(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_DELETEALLITEMS, NMLISTVIEW, nIdentifier, Function)
#define MSG_LVN_BEGINLABELEDIT(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_BEGINLABELEDIT, NMLVDISPINFO, nIdentifier, Function)
#define MSG_LVN_ENDLABELEDIT(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ENDLABELEDIT, NMLVDISPINFO, nIdentifier, Function)
#define MSG_LVN_COLUMNCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_COLUMNCLICK, NMLISTVIEW, nIdentifier, Function)
#define MSG_LVN_BEGINDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_BEGINDRAG, NMLISTVIEW, nIdentifier, Function)
#define MSG_LVN_BEGINRDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_BEGINRDRAG, NMLISTVIEW, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#define MSG_LVN_ODCACHEHINT(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ODCACHEHINT, NMLVCACHEHINT, nIdentifier, Function)
#define MSG_LVN_ODFINDITEM(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ODFINDITEM, NMLVFINDITEM, nIdentifier, Function)
#if (_WIN32_IE >= 0x0400)
#define MSG_LVN_ITEMACTIVATE(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ITEMACTIVATE, NMITEMACTIVATE, nIdentifier, Function) // NMHDR prior to 4.71
#else
#define MSG_LVN_ITEMACTIVATE(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ITEMACTIVATE, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_LVN_ODSTATECHANGED(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ODSTATECHANGED, NMLVODSTATECHANGE, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_LVN_HOTTRACK(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_HOTTRACK, NMLISTVIEW, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_LVN_GETDISPINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_GETDISPINFO, NMLVDISPINFO, nIdentifier, Function)
#define MSG_LVN_SETDISPINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_SETDISPINFO, NMLVDISPINFO, nIdentifier, Function)
#define MSG_LVN_KEYDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_KEYDOWN, NMLVKEYDOWN, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#define MSG_LVN_MARQUEEBEGIN(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_MARQUEEBEGIN, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_LVN_GETINFOTIP(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_GETINFOTIP, NMLVGETINFOTIP, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#if (_WIN32_WINNT >= 0x0501)
#define MSG_LVN_BEGINSCROLL(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_BEGINSCROLL, NMLVSCROLL, nIdentifier, Function)
#define MSG_LVN_ENDSCROLL(nIdentifier, Function) CC_MSG_WM_NOTIFY(LVN_ENDSCROLL, NMLVSCROLL, nIdentifier, Function)
#endif // (_WIN32_WINNT >= 0x0501)
#endif // !defined(NOLISTVIEW)

#if !defined(NOTREEVIEW)
#define MSG_TVN_CLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CLICK, NMHDR, nIdentifier, Function)
#define MSG_TVN_DBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_DBLCLK, NMHDR, nIdentifier, Function)
#define MSG_TVN_RETURN(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RETURN, NMHDR, nIdentifier, Function)
#define MSG_TVN_RCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RCLICK, NMHDR, nIdentifier, Function)
#define MSG_TVN_RDBLCLK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RDBLCLK, NMHDR, nIdentifier, Function)
#define MSG_TVN_SETFOCUS(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_SETFOCUS, NMHDR, nIdentifier, Function)
#define MSG_TVN_KILLFOCUS(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_KILLFOCUS, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0300)
#define MSG_TVN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMTVCUSTOMDRAW, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#if (_WIN32_IE >= 0x0400)
#define MSG_TVN_SETCURSOR(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_SETCURSOR, NMMOUSE, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_TVN_SELCHANGING(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_SELCHANGING, NMTREEVIEW, nIdentifier, Function)
#define MSG_TVN_SELCHANGED(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_SELCHANGED, NMTREEVIEW, nIdentifier, Function)
#define MSG_TVN_GETDISPINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_GETDISPINFO, NMTVDISPINFO, nIdentifier, Function)
#define MSG_TVN_SETDISPINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_SETDISPINFO, NMTVDISPINFO, nIdentifier, Function)
#define MSG_TVN_ITEMEXPANDING(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_ITEMEXPANDING, NMTREEVIEW, nIdentifier, Function)
#define MSG_TVN_ITEMEXPANDED(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_ITEMEXPANDED, NMTREEVIEW, nIdentifier, Function)
#define MSG_TVN_BEGINDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_BEGINDRAG, NMTREEVIEW, nIdentifier, Function)
#define MSG_TVN_BEGINRDRAG(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_BEGINRDRAG, NMTREEVIEW, nIdentifier, Function)
#define MSG_TVN_DELETEITEM(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_DELETEITEM, NMTREEVIEW, nIdentifier, Function)
#define MSG_TVN_BEGINLABELEDIT(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_BEGINLABELEDIT, NMTVDISPINFO, nIdentifier, Function)
#define MSG_TVN_ENDLABELEDIT(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_ENDLABELEDIT, NMTVDISPINFO, nIdentifier, Function)
#define MSG_TVN_KEYDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_KEYDOWN, NMTVKEYDOWN, nIdentifier, Function)
#if (_WIN32_IE >= 0x0400)
#define MSG_TVN_GETINFOTIP(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_GETINFOTIP, NMTVGETINFOTIP, nIdentifier, Function)
#define MSG_TVN_SINGLEEXPAND(nIdentifier, Function) CC_MSG_WM_NOTIFY(TVN_SINGLEEXPAND, NMTREEVIEW, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#endif // !defined(NOTREEVIEW)

#if !defined(NOUSEREXCONTROLS)
#if (_WIN32_IE >= 0x0400)
#define MSG_CBEN_SETCURSOR(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_SETCURSOR, NMMOUSE, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_CBEN_INSERTITEM(nIdentifier, Function) CC_MSG_WM_NOTIFY(CBEN_INSERTITEM, NMCOMBOBOXEX, nIdentifier, Function)
#define MSG_CBEN_DELETEITEM(nIdentifier, Function) CC_MSG_WM_NOTIFY(CBEN_DELETEITEM, NMCOMBOBOXEX, nIdentifier, Function)
#define MSG_CBEN_BEGINEDIT(nIdentifier, Function) CC_MSG_WM_NOTIFY(CBEN_BEGINEDIT, NMHDR, nIdentifier, Function)
#define MSG_CBEN_ENDEDIT(nIdentifier, Function) CC_MSG_WM_NOTIFY(CBEN_ENDEDIT, NMCBEENDEDIT, nIdentifier, Function)
#if (_WIN32_IE >= 0x0400)
#define MSG_CBEN_GETDISPINFO(nIdentifier, Function) CC_MSG_WM_NOTIFY(CBEN_GETDISPINFO, NMCOMBOBOXEX, nIdentifier, Function)
#define MSG_CBEN_DRAGBEGIN(nIdentifier, Function) CC_MSG_WM_NOTIFY(CBEN_DRAGBEGIN, NMCBEDRAGBEGIN, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#endif // !defined(NOUSEREXCONTROLS)

#if !defined(NOTABCONTROL)
#define MSG_TCN_CLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CLICK, NMHDR, nIdentifier, Function)
#define MSG_TCN_RCLICK(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RCLICK, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0400)
#define MSG_TCN_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_TCN_KEYDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(TCN_KEYDOWN, NMTCKEYDOWN, nIdentifier, Function)
#define MSG_TCN_SELCHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(TCN_SELCHANGE, NMHDR, nIdentifier, Function)
#define MSG_TCN_SELCHANGING(nIdentifier, Function) CC_MSG_WM_NOTIFY(TCN_SELCHANGING, NMHDR, nIdentifier, Function)
#if (_WIN32_IE >= 0x0400)
#define MSG_TCN_GETOBJECT(nIdentifier, Function) CC_MSG_WM_NOTIFY(TCN_GETOBJECT, NMOBJECTNOTIFY, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#if (_WIN32_IE >= 0x0500)
#define MSG_TCN_FOCUSCHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(TCN_FOCUSCHANGE, NMHDR, nIdentifier, Function) // MSDN does not specify header type
#endif // (_WIN32_IE >= 0x0500)
#endif // !defined(NOTABCONTROL)

#if !defined(NOANIMATE)
#define MSG_ACN_START(nIdentifier, Function) CC_MSG_WM_COMMAND(ACN_START, nIdentifier, Function)
#define MSG_ACN_STOP(nIdentifier, Function) CC_MSG_WM_COMMAND(ACN_STOP, nIdentifier, Function)
#endif // !defined(NOANIMATE)

#if !defined(NOMONTHCAL)
#if (_WIN32_IE >= 0x0400)
#define MSG_MCN_RELEASEDCAPTURE(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_RELEASEDCAPTURE, NMHDR, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0400)
#define MSG_MCN_SELCHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(MCN_SELCHANGE, NMSELCHANGE, nIdentifier, Function)
#define MSG_MCN_GETDAYSTATE(nIdentifier, Function) CC_MSG_WM_NOTIFY(MCN_GETDAYSTATE, NMDAYSTATE, nIdentifier, Function)
#define MSG_MCN_SELECT(nIdentifier, Function) CC_MSG_WM_NOTIFY(MCN_SELECT, NMSELCHANGE, nIdentifier, Function)
#endif // !defined(NOMONTHCAL)

#if !defined(NODATETIMEPICK)
#define MSG_DTN_SETFOCUS(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_SETFOCUS, NMHDR, nIdentifier, Function)
#define MSG_DTN_KILLFOCUS(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_KILLFOCUS, NMHDR, nIdentifier, Function)
#define MSG_DTN_DATETIMECHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(DTN_DATETIMECHANGE, NMDATETIMECHANGE, nIdentifier, Function)
#define MSG_DTN_USERSTRING(nIdentifier, Function) CC_MSG_WM_NOTIFY(DTN_USERSTRINGW, NMDATETIMESTRING, nIdentifier, Function)
#define MSG_DTN_WMKEYDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(DTN_WMKEYDOWNA, NMDATETIMEWMKEYDOWN, nIdentifier, Function)
#define MSG_DTN_FORMAT(nIdentifier, Function) CC_MSG_WM_NOTIFY(DTN_FORMATA, NMDATETIMEFORMAT, nIdentifier, Function)
#define MSG_DTN_FORMATQUERY(nIdentifier, Function) CC_MSG_WM_NOTIFY(DTN_FORMATQUERYW, NMDATETIMEFORMATQUERY, nIdentifier, Function)
#define MSG_DTN_DROPDOWN(nIdentifier, Function) CC_MSG_WM_NOTIFY(DTN_DROPDOWN, NMHDR, nIdentifier, Function)
#define MSG_DTN_CLOSEUP(nIdentifier, Function) CC_MSG_WM_NOTIFY(DTN_CLOSEUP, NMHDR, nIdentifier, Function)
#endif // !defined(NODATETIMEPICK)

#if !defined(NOIPADDRESS)
#define MSG_IPN_FIELDCHANGED(nIdentifier, Function) CC_MSG_WM_NOTIFY(IPN_FIELDCHANGED, NMIPADDRESS, nIdentifier, Function)
#endif // !defined(NOIPADDRESS)

#if !defined(NOPAGESCROLLER)
#endif // !defined(NOPAGESCROLLER)

#if !defined(NONATIVEFONTCTL)
#endif // !defined(NONATIVEFONTCTL)

#if !defined(NOBUTTON)
#if (_WIN32_IE >= 0x0300)
#define MSG_BCN_CUSTOMDRAW(nIdentifier, Function) CC_MSG_WM_NOTIFY(NM_CUSTOMDRAW, NMCUSTOMDRAW, nIdentifier, Function)
#endif // (_WIN32_IE >= 0x0300)
#define MSG_BCN_HOTITEMCHANGE(nIdentifier, Function) CC_MSG_WM_NOTIFY(BCN_HOTITEMCHANGE, NMBCHOTITEM, nIdentifier, Function)
#endif // !defined(NOBUTTON)

#if !defined(NOSTATIC)
#endif // !defined(NOSTATIC)

#if !defined(NOEDIT)
#endif // !defined(NOEDIT)

#if !defined(NOLISTBOX)
#endif // !defined(NOLISTBOX)

#if !defined(NOCOMBOBOX)
#endif // !defined(NOCOMBOBOX)

#if !defined(NOSCROLLBAR)
#endif // !defined(NOSCROLLBAR)

#if !defined(NOMUI)
#endif // !defined(NOMUI)

#if !defined(NOTRACKMOUSEEVENT)
#endif // !defined(NOTRACKMOUSEEVENT)

#if !defined(NOFLATSBAPIS)
#endif // !defined(NOFLATSBAPIS)
