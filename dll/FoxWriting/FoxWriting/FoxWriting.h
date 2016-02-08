#ifdef FOXWRITING_EXPORTS
#define FOXWRITING_API __declspec(dllexport)
#else
#define FOXWRITING_API __declspec(dllimport)
#endif

#ifndef __FOXWRITING_H__
#define __FOXWRITING_H__

#include <vector>

typedef struct
{
    gm::GMTEXTURE backupTexture;
    int spriteWidth;
    int spriteHeight;
} SpriteBackup;

typedef struct
{
    gm::ISprite* workingSprite;
    LPDIRECT3DDEVICE8 device;
    int spriteIndex;
    SpriteBackup sprBackup;
} FWorkbench;

typedef struct _MesauredLine
{
    int start;
    int end;
    float width;
    float height;

    _MesauredLine(int s, int e, float w, float h): start(s), end(e), width(w), height(h)
    {
    }
} MeasuredLine;

typedef struct
{
    float width;
    float height;
    std::vector<MeasuredLine> lines;
} MeasuredString;

extern gm::CGMAPI* gmapi;
extern ULONG_PTR m_gdiplusToken;
extern INT xdpi;
extern INT ydpi;
extern FWorkbench workbench;

extern "C"
{
    // ��ʼ�� FowWriting, sprite �ǹ������飬���л��ƶ��ڸþ��������
    FOXWRITING_API DOUBLE FWInit(DOUBLE sprite, DOUBLE argList);
    FOXWRITING_API DOUBLE FWReleaseCache();
    FOXWRITING_API DOUBLE FWCleanup();
    // ���ö��߳����ֻ���
    FOXWRITING_API DOUBLE FWThreadingConfig(DOUBLE maxThread, DOUBLE linePreThread);
    // ���������ַ�����
    FOXWRITING_API DOUBLE FWSetEncoding(LPCSTR CPName);
    FOXWRITING_API DOUBLE FWSetEncodingEx(DOUBLE codePage);
    // ע������
    FOXWRITING_API DOUBLE FWAddFont(LPCSTR name, DOUBLE pt, DOUBLE style);
    FOXWRITING_API DOUBLE FWAddFontFromFile(LPCSTR ttf, DOUBLE pt, DOUBLE style);
    FOXWRITING_API DOUBLE FWDeleteFont(DOUBLE font);
    // Ԥ��������
    FOXWRITING_API DOUBLE FWPreloadFont(DOUBLE font, DOUBLE from, DOUBLE to);
    // ��������ƫ��
    FOXWRITING_API DOUBLE FWSetFontOffset(DOUBLE font, DOUBLE xOffset, DOUBLE yOffset);
    // ��������
    FOXWRITING_API DOUBLE FWSetFont(DOUBLE font);
    // ���ö��뷽ʽ
    FOXWRITING_API DOUBLE FWSetHAlign(DOUBLE align);
    FOXWRITING_API DOUBLE FWSetVAlign(DOUBLE align);
    // �Ƿ����������ض���
    FOXWRITING_API DOUBLE FWEnablePixelAlignment(DOUBLE enable);
    // �����м��
    FOXWRITING_API DOUBLE FWSetLineSpacing(DOUBLE sep);
    // ���㳤��
    FOXWRITING_API DOUBLE FWStringWidth(LPCSTR str);
    FOXWRITING_API DOUBLE FWStringHeight(LPCSTR str);
    FOXWRITING_API DOUBLE FWStringWidthEx(LPCSTR str, DOUBLE sep, DOUBLE w);
    FOXWRITING_API DOUBLE FWStringHeightEx(LPCSTR str, DOUBLE sep, DOUBLE w);
    // ���ֻ���
    FOXWRITING_API DOUBLE FWDrawText(DOUBLE x, DOUBLE y, LPCSTR str);
    FOXWRITING_API DOUBLE FWDrawTextEx(DOUBLE x, DOUBLE y, LPCSTR str);

    FOXWRITING_API DOUBLE FWDrawTextTransformed(DOUBLE x, DOUBLE y, LPCSTR str);
    FOXWRITING_API DOUBLE FWDrawTextTransformedEx(DOUBLE x, DOUBLE y, LPCSTR str);

    FOXWRITING_API DOUBLE FWDrawTextColor(DOUBLE x, DOUBLE y, LPCSTR str);
    FOXWRITING_API DOUBLE FWDrawTextColorEx(DOUBLE x, DOUBLE y, LPCSTR str);

    FOXWRITING_API DOUBLE FWDrawTextTransformedColor(DOUBLE x, DOUBLE y, LPCSTR str);
    FOXWRITING_API DOUBLE FWDrawTextTransformedColorEx(DOUBLE x, DOUBLE y, LPCSTR str);
};

#endif
