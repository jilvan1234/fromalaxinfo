////////////////////////////////////////////////////////////
// Copyright (C) Roman Ryltsov, 2008-2016
// Created by Roman Ryltsov roman@alax.info

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "MainDialog.h"

////////////////////////////////////////////////////////////
// CEnumerateAudioDevicesModule

class CEnumerateAudioDevicesModule :
	public CAtlExeModuleT<CEnumerateAudioDevicesModule>,
	public CWtlExeModuleT<CEnumerateAudioDevicesModule>
{
public:
// CEnumerateAudioDevicesModule

// CAtlExeModuleT
	CEnumerateAudioDevicesModule()
	{
		AtlTraceSetDefaultSettings();
		_W(CExceptionFilter::Initialize());
		_Z4_THIS();
	}
	~CEnumerateAudioDevicesModule()
	{
		_Z4_THIS();
		CExceptionFilter::Terminate();
	}
	HRESULT RegisterServer(BOOL bRegisterTypeLibrary = FALSE, const CLSID* pClassIdentifier = NULL)
	{
		bRegisterTypeLibrary;
		return __super::RegisterServer(FALSE, pClassIdentifier);
	}
	HRESULT UnregisterServer(BOOL bUnregisterTypeLibrary, const CLSID* pClassIdentifier = NULL)
	{
		bUnregisterTypeLibrary;
		return __super::UnregisterServer(FALSE, pClassIdentifier);
	}
	HRESULT PreMessageLoop(INT nShowCommand)
	{
		_ATLTRY
		{
			__E(AtlInitCommonControls(ICC_WIN95_CLASSES | ICC_DATE_CLASSES | ICC_COOL_CLASSES));
			//__C(CWtlExeModule::Initialize());
			__C(__super::PreMessageLoop(nShowCommand));
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
	VOID RunMessageLoop()
	{
		Lock();
		{
			CMainDialog MainDialog;
			MainDialog.DoModal();
		}
		if(GetLockCount() == 1)
		{
			m_dwTimeOut = 0L;
			m_dwPause = 0L;
		}
		Unlock();
	}
	HRESULT PostMessageLoop()
	{
		_ATLTRY
		{
			_V(__super::PostMessageLoop());
			//CWtlExeModule::Terminate();
		}
		_ATLCATCH(Exception)
		{
			_C(Exception);
		}
		return S_OK;
	}
};

////////////////////////////////////////////////////////////
// Main

CEnumerateAudioDevicesModule g_Module;

int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR pszCommandLine, int nShowCommand)
{
	return g_Module.WinMain(nShowCommand);
}
