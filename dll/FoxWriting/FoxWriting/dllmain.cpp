// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "stdafx.h"
#include "FoxWriting.h"

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        {
            { // Ӧ�� vs2015 ���� sprintf ���� d3d8.lib �Ҳ��� _sprintf ������
                char f__kInline[1];
                sprintf(f__kInline, "");
            }

            // Initializing GMAPI library
            DWORD result = 0;
            gmapi = gm::CGMAPI::Create(&result);

            // Check the initialization
            if (result == gm::GMAPI_INITIALIZATION_FAILED)
            {
                MessageBox(NULL, L"Unable to initialize GMAPI.", NULL, MB_SYSTEMMODAL | MB_ICONERROR);
                return FALSE;
            }

            // ��ʼ�� GDI+
            Gdiplus::GdiplusStartupInput gdiplusStartupInput;
            Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);
            // �õ���Ļ�ܶȣ��������� pt <-> px
            HDC dc = GetDC(0);
            xdpi = GetDeviceCaps(dc, LOGPIXELSX);
            ydpi = GetDeviceCaps(dc, LOGPIXELSY);
        }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
        break;
    case DLL_PROCESS_DETACH:
        // ���ﲻ��shutdown������Ϸ�������ԭ����
        //Gdiplus::GdiplusShutdown(m_gdiplusToken);
        break;
    }
    return TRUE;
}

