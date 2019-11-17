//---------------------------------------------------------------------------

#ifndef UTermbH
#define UTermbH
#include <Classes.hpp>
#include <SysUtils.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include <winbase.h>
#include <StdCtrls.hpp>

//---------------------------------------------------------------------------
class TTermb{
private:
  AnsiString DLLFileName;//DLL文件名；包含了路径
  AnsiString dllfilename;//dll文件名，是用来说明该类封装哪个DLL文件。
  HINSTANCE API_hd;//Dll句柄。
  int Icdev;//打开串口的设备句柄。

   int __fastcall Get_PeopleName(AnsiString *_Data);
   int __fastcall Get_PeopleNation(AnsiString *_Data);
   int __fastcall Get_PeopleBirthday(AnsiString *_Data);
   int __fastcall Get_PeopleAddress(AnsiString *_Data);
   int __fastcall Get_PeopleIDCode(AnsiString *_Data);
   int __fastcall Get_Department(AnsiString *_Data);
   int __fastcall Get_StartDate(AnsiString *_Data);
   int __fastcall Get_EndDate(AnsiString *_Data);
   int __fastcall Get_PeopleSex(AnsiString *_Data);
public:
   __fastcall TTermb(AnsiString DllFile);
   __fastcall ~TTermb();
   int __fastcall CVRInitComm();
   int __fastcall CVRAuthenticate();
   int __fastcall CVRRead_Content();
   int __fastcall CVRCloseComm();

   int __fastcall CVRAnt(int _Mode);
  AnsiString _TermbName; //姓名
  AnsiString _TermbSex;  //性别
  AnsiString _TermbBirthDate;  //出生年月
  AnsiString _TermbNation;  //名族
  AnsiString _TermbAddress;  //地址
  AnsiString _TermbNumber;  //身份证号码
  AnsiString _TermbStartDate;  // 有效开始日期
  AnsiString _TermbEndDate;  // 有效结束日期
  AnsiString _TermbUnit;  //签发机关
  TDateTime _ReadTime;
  int _ComPort;
  int _ComRate;

};
#endif
