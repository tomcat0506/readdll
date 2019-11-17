//---------------------------------------------------------------------------

#include "UTermb.h"

#pragma hdrstop

//---------------------------------------------------------------------------
__fastcall TTermb::TTermb(AnsiString DllFile){
  dllfilename="Termb.dll";
  DLLFileName=Trim(DllFile);
  if(FileExists(DLLFileName)==false){
    if(DLLFileName==""){
      DLLFileName=ExtractFilePath(Application->ExeName)+dllfilename ;
    }
    if(FileExists(DLLFileName)==false){
      ShowMessage("���ļ������ڣ�"+DllFile+"����Ҳ�Ҳ���Ĭ�ϵĿ��ļ���"+DLLFileName+"��");
    }
  }
  API_hd=LoadLibrary(DLLFileName.c_str());
}

__fastcall TTermb::~TTermb(){
  this->CVRCloseComm();
  if(API_hd!=NULL){
    try{
     FreeLibrary(API_hd);
    }catch(...){
      try{
        FreeLibrary(API_hd);
      }catch(Exception *Err){
        throw Exception("�ͷſ���ִ���"+Err->Message);
      }
    }
  }else{
    try{
      FreeLibrary(API_hd);
    }catch(...){
    }
  }

}

int __fastcall TTermb::CVRInitComm(){
  int Result=-1;
  int (*CVR_InitComm)(int Port) ;
  (FARPROC)CVR_InitComm=GetProcAddress(API_hd,"CVR_InitComm"); //��ȡ������ַ
  Result=CVR_InitComm(_ComPort);
  Sleep(10);
  return Result;
}

int __fastcall TTermb::CVRAuthenticate(){
  int Result=-1;
  int (*CVR_Authenticate)() ;
  (FARPROC)CVR_Authenticate=GetProcAddress(API_hd,"CVR_Authenticate"); //��ȡ������ַ
  Result =CVR_Authenticate() ;
  Sleep(301);
  return Result;
}

int __fastcall TTermb::CVRRead_Content(){
  int Result=-1;
  int (*CVR_Read_Content)(int Active) ;
  (FARPROC)CVR_Read_Content=GetProcAddress(API_hd,"CVR_Read_Content"); //��ȡ������ַ
  Result =CVR_Read_Content(4);
  Sleep(100);
  
  this->Get_PeopleName(&_TermbName);       //����
  this->Get_PeopleSex(&_TermbSex);        //�Ա�
  this->Get_PeopleNation(&_TermbNation);     //����
  this->Get_PeopleBirthday(&_TermbBirthDate);  //��������
  this->Get_PeopleAddress(&_TermbAddress);    //��ַ
  this->Get_PeopleIDCode(&_TermbNumber);     //���֤����
  this->Get_Department(&_TermbUnit);       //ǩ������
  this->Get_StartDate(&_TermbStartDate);       // ��Ч����
  this->Get_EndDate(&_TermbEndDate);
  _ReadTime=Now();
  return Result;
}

int __fastcall TTermb::CVRCloseComm(){
  int Result=-1;
  int (*CVR_CloseComm)() ;
  (FARPROC)CVR_CloseComm=GetProcAddress(API_hd,"CVR_CloseComm"); //��ȡ������ַ
  Result =CVR_CloseComm();
  return Result;
}
int __fastcall TTermb::Get_PeopleName(AnsiString *_Data){
  int Result=-1;
  int (*GetPeopleName)(char *, int *);
  (FARPROC)GetPeopleName=GetProcAddress(API_hd,"GetPeopleName");
  char *strTmp;
  int strLen=30;
  strTmp=(char*)malloc(30);
  memset(strTmp,0,30);
  Result=GetPeopleName(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);
  return Result;
}

int __fastcall TTermb::Get_PeopleNation(AnsiString *_Data){
  int Result=-1;
  int (*GetPeopleNation)(char *, int *);
  char *strTmp;
  int strLen=4;
  strTmp=(char*)malloc(4);
  memset(strTmp,0,4);
  (FARPROC)GetPeopleNation=GetProcAddress(API_hd,"GetPeopleNation");
  Result=GetPeopleNation(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);  
  return Result;
}

int __fastcall TTermb::Get_PeopleBirthday(AnsiString *_Data){
  int Result=-1;
  int  (*GetPeopleBirthday)(char *, int *);
  char *strTmp;
  int strLen=16;
  strTmp=(char*)malloc(16);
  memset(strTmp,0,6);
  (FARPROC)GetPeopleBirthday=GetProcAddress(API_hd,"GetPeopleBirthday");
  Result=GetPeopleBirthday(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);
  return Result;
}

int __fastcall TTermb::Get_PeopleAddress(AnsiString *_Data){
  int Result=-1;
  int  (*GetPeopleAddress)(char *, int *);
  char *strTmp;
  int strLen=70;
  strTmp=(char*)malloc(70);
  memset(strTmp,0,70);
  (FARPROC)GetPeopleAddress=GetProcAddress(API_hd,"GetPeopleAddress");
  Result=GetPeopleAddress(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);
  return Result;
}

int __fastcall TTermb::Get_PeopleIDCode(AnsiString *_Data){
  int Result=-1;
  int  (*GetPeopleIDCode)(char *, int *);
  char *strTmp;
  int strLen=36;
  strTmp=(char*)malloc(36);
  memset(strTmp,0,36);
  (FARPROC)GetPeopleIDCode=GetProcAddress(API_hd,"GetPeopleIDCode");
  Result=GetPeopleIDCode(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);
  return Result;
}

int __fastcall TTermb::Get_Department(AnsiString *_Data){
  int Result=-1;
  int  (*GetDepartment)(char *, int *);
  char *strTmp;
  int strLen=30;
  strTmp=(char*)malloc(30);
  memset(strTmp,0,30);
  (FARPROC)GetDepartment=GetProcAddress(API_hd,"GetDepartment");
  Result=GetDepartment(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);
  return Result;
}

int __fastcall TTermb::Get_StartDate(AnsiString *_Data){
  int Result=-1;
  int  (*GetStartDate)(char *, int *);
  char *strTmp;
  int strLen=16;
  strTmp=(char*)malloc(16);
  memset(strTmp,0,16);
  (FARPROC)GetStartDate=GetProcAddress(API_hd,"GetStartDate");
  Result=GetStartDate(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);
  return Result;
}

int __fastcall TTermb::Get_EndDate(AnsiString *_Data){
  int Result=-1;
  int  (*GetEndDate)(char *, int *);
  char *strTmp;
  int strLen=16;
  strTmp=(char*)malloc(16);
  memset(strTmp,0,16);
  (FARPROC)GetEndDate=GetProcAddress(API_hd,"GetEndDate");
  Result=GetEndDate(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);
  return Result;
}

int __fastcall TTermb::Get_PeopleSex(AnsiString *_Data){
  int Result=-1;
  int  (*GetPeopleSex)(char *, int *);
  char *strTmp;
  int strLen=2;
  strTmp=(char*)malloc(2);
  memset(strTmp,0,2);
  (FARPROC)GetPeopleSex=GetProcAddress(API_hd,"GetPeopleSex");
  Result=GetPeopleSex(strTmp,&strLen);
  *_Data= _Data->sprintf("%s",strTmp);
  return Result;
}

int __fastcall TTermb::CVRAnt(int _Mode){
  int Result=-1;
  int  (*CVR_Ant)(int );
  (FARPROC)CVR_Ant=GetProcAddress(API_hd,"CVR_Ant");
  Result=CVR_Ant(_Mode);
  return Result;
}

#pragma package(smart_init)
