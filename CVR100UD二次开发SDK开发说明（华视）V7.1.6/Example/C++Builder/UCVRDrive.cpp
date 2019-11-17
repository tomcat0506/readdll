//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UCVRDrive.h"
#include "UTermb.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TTermb *Termb;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   Termb=new TTermb(""); 
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button1Click(TObject *Sender)
{
  Termb->_ComPort=this->CbBPort->ItemIndex+1;
  Termb->_ComRate=StrToInt(this->CbBBaud->Text);
  int intRet=Termb->CVRInitComm();
  if(intRet==1){
    Button1->Enabled=false;
    Button2->Enabled=true;
    Button3->Enabled=true;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  int intRet=Termb->CVRCloseComm();
  if(intRet==1){
    Button1->Enabled=true;
    Button2->Enabled=false;
    Button3->Enabled=false;
  }
}
//---------------------------------------------------------------------------
////1寸标准相片对应的大小   ,生成后替换原来的文件名称
void __fastcall TForm1::PicToStandardSize(AnsiString sPhotoFile)
{
    TJPEGImage *Jpg;
    Graphics::TBitmap *Bmp;
    TImage *img ;
   AnsiString   OutputFileName,temp,ext_name;
   int pos;
   int width=102,height=126,init_width,init_height;//1寸标准相片对应的大小
    TRect  rect;
   try
    {
       rect.Left =0;
       rect.top =0;
       rect.Right=width;
       rect.Bottom =height;
       temp=sPhotoFile;
       pos=temp.Pos(".");
       ext_name= temp.SubString(pos+1,3);
       Bmp=new   Graphics::TBitmap();
       Jpg=new  TJPEGImage();
       img=new TImage(Application);
        if(ext_name.UpperCase() =="BMP")
        {
            img->Picture->LoadFromFile(sPhotoFile) ;
            Bmp->Canvas->StretchDraw(rect,img->Picture->Bitmap);
            Bmp->Width =width;
            Bmp->Height =height;
        }
       else
         {
           //先转化成同名的BMP文件，设置成标准大小后，再设置成JPG
           Jpg->LoadFromFile(sPhotoFile);
           Bmp->Assign(Jpg);
           OutputFileName= temp.SubString(1,pos-1)+".BMP";
           Bmp->SaveToFile(OutputFileName);
            img->Picture->LoadFromFile(OutputFileName) ;
            Bmp->Canvas->StretchDraw(rect,img->Picture->Bitmap);
            Bmp->Width =width;
            Bmp->Height =height;
            Jpg->Assign(Bmp) ;
            Jpg->SaveToFile(sPhotoFile);
         }
    }
    catch(...)
    {
      Bmp->Free();
      Jpg->Free();
      img->Free() ;
    }

      Bmp->Free();
      Jpg->Free();
      img->Free() ;
}

void __fastcall TForm1::Button3Click(TObject *Sender)
{
  if(Termb->CVRAuthenticate()==1){
     if(Termb->CVRRead_Content()==1){

        this->Edit1->Text=Termb->_TermbName;
        this->Edit2->Text=Termb->_TermbSex;
        this->Edit3->Text=Termb->_TermbBirthDate;
        this->Edit4->Text=Termb->_TermbNumber;
        this->Edit5->Text=Termb->_TermbAddress;
        this->Edit6->Text=Termb->_TermbStartDate+" 至 "+Termb->_TermbEndDate;
        this->Edit7->Text=Termb->_TermbUnit;
        this->Edit8->Text=Termb->_TermbNation;
        AnsiString WZPathPic = ExtractFilePath(Application->ExeName) + "zp.bmp"; //照片
        if(FileExists(WZPathPic)){
          Image1->Picture->LoadFromFile(WZPathPic) ;
        }
      //--------------------------------------------------------------------
//      ls_GetSNo = ls_TermbName.Trim() + ls_GetSNo.Trim() ;
//      ls_SavePicFile = App_path + "\RecvFile\\" + ls_GetSNo.Trim() + ".bmp" ;
//      Image1->Picture->SaveToFile(ls_SavePicFile.c_str()) ;
//      ls_PicPath     =BmpToJpeg(ls_SavePicFile.Trim()) ;
//      PicToStandardSize(ls_PicPath) ;
     }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CbBPortKeyPress(TObject *Sender, char &Key)
{
  if(Key!=8){
    Key=0;
  }
}
//---------------------------------------------------------------------------

