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
  AnsiString DLLFileName;//DLL�ļ�����������·��
  AnsiString dllfilename;//dll�ļ�����������˵�������װ�ĸ�DLL�ļ���
  HINSTANCE API_hd;//Dll�����
  int Icdev;//�򿪴��ڵ��豸�����

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
  AnsiString _TermbName; //����
  AnsiString _TermbSex;  //�Ա�
  AnsiString _TermbBirthDate;  //��������
  AnsiString _TermbNation;  //����
  AnsiString _TermbAddress;  //��ַ
  AnsiString _TermbNumber;  //���֤����
  AnsiString _TermbStartDate;  // ��Ч��ʼ����
  AnsiString _TermbEndDate;  // ��Ч��������
  AnsiString _TermbUnit;  //ǩ������
  TDateTime _ReadTime;
  int _ComPort;
  int _ComRate;

};
#endif
