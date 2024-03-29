{**************************************************
	深圳华视电子读写设备有限公司 
	    版权所有 (c) 2007.04
 
	By: 吴为龙 Kim.Wu 
	Tel: 0755-26955558
	Http://www.chinaidcard.com
***************************************************}


unit UCVR;

interface

uses
  Windows, Messages, SysUtils, Variants, Classes, Graphics, Controls, Forms,
  Dialogs, StdCtrls, ExtCtrls, ComCtrls, jpeg;

type
  TForm2 = class(TForm)
    Panel1: TPanel;
    EditName: TEdit;
    EdSex: TEdit;
    EdBday: TEdit;
    EdAddr: TEdit;
    EdMZ: TEdit;
    Label11: TLabel;
    Label9: TLabel;
    Label10: TLabel;
    Label12: TLabel;
    Label13: TLabel;
    Label14: TLabel;
    EdID: TEdit;
    EdDep: TEdit;
    EdVld: TEdit;
    EdNewAddr: TEdit;
    Label66: TLabel;
    Label65: TLabel;
    Label67: TLabel;
    Panel2: TPanel;
    Image2: TImage;
    Button50: TButton;
    Button49: TButton;
    ComboBox11: TComboBox;
    Label70: TLabel;
    ComboBox9: TComboBox;
    Label68: TLabel;
    TimerRedo: TTimer;
    StatusBar1: TStatusBar;
    Btnclose: TButton;
    Timer1: TTimer;
    Panel3: TPanel;
    Image1: TImage;
    procedure Button49Click(Sender: TObject);
    procedure Button50Click(Sender: TObject);
    procedure BtncloseClick(Sender: TObject);
    procedure FormKeyDown(Sender: TObject; var Key: Word;
      Shift: TShiftState);
    procedure FormShow(Sender: TObject);
    procedure Timer1Timer(Sender: TObject);
  private
    { Private declarations }
     procedure EmptyEditCV;
     procedure ChangeDateChina( sInput:string; var sOutput:string );
     procedure ChangeDateDot( sInput:string; var sOutput:string );
     procedure Delay(DT:DWORD);
  public
    { Public declarations }
  end;
    ChA256 = array[0..255] of char;
var
  Form2: TForm2;
  isStoped: Boolean;
implementation
   uses CVRDLL;
{$R *.dfm}

procedure TForm2.Delay(DT:DWORD);
// 延迟函数
var
   TT:DWORD;
begin
   TT:=Gettickcount();
   while Gettickcount()-TT<DT DO
     Application.ProcessMessages;
end;

procedure TForm2.Button49Click(Sender: TObject);
//  读第二代身份证
var
  iRet, iPort, iTimeOut :integer;
  TimeCurr, TimeDelay:int64;

  iFileHandle,iFileLength: Integer;
  Buffer: PWideChar;
    
  sWZ :WideString;
  sDisp, iniFileName:string;
  ChPeople :ChA256;

  ID: Cardinal	;
  
  szGet :array[0..70] of char;
  iLenGet:integer;
begin
    isStoped:=false;
    TimerRedo.Enabled:=false;
    Button49.Enabled:=false;
    Btnclose.Enabled:=false;
    iPort := strtoint(ComboBox9.Text) ;
    iTimeOut := strtoint(ComboBox11.Text);

    iRet:=CVR_InitComm(iPort);     //
    if iRet<>1  then
    begin
        StatusBar1.Panels.Items[1].Text := '打开串口出错';
        self.Update;
        Button49.Enabled:=true;
        Btnclose.Enabled:=true;
        CVR_CloseComm();            //
        exit;
    end
    else
    begin
        GetManuID(@ID);    //20080610 Add By Kim  
        StatusBar1.Panels.Items[1].Text := '请放卡，按 Esc 键停止读卡！ ，ID:'+inttostr(ID);
    end;
    self.Update;

    TimeCurr := GetTickCount();
    TimeDelay := iTimeOut * 1000;
    while True do
    begin   
        iRet := CVR_Authenticate();    //
        if iRet =1 then
           break;   
        if ( GetTickCount()-TimeCurr > TimeDelay ) then
        begin
            StatusBar1.Panels.Items[1].Text := '放卡超时';
            self.Update;
            Button49.Enabled:=true;
            Btnclose.Enabled:=true;
            CVR_CloseComm();          //
            exit;
        end;
        Delay(200);
        if isStoped then
        begin
           StatusBar1.Panels.Items[1].Text := '用户已取消读卡';
           self.Update;     
           CVR_CloseComm();           //
           exit;
        end;
    end;
    
    self.Update;
    iRet := CVR_Read_Content(1);      //
    CVR_CloseComm();                  //
    if iRet<>1 then
    begin
        StatusBar1.Panels.Items[1].Text := '读基本信息出错';
        self.Update;
        Button49.Enabled:=true;
        Btnclose.Enabled:=true;
        exit;
    end;

    StatusBar1.Panels.Items[1].Text := '读卡资料成功';
    self.Update;                                                    
                                                                    
    //------------------------------------------------------------------显示资料         

    try
      //-----测试 GetXXX() 系列函数
      {GetPeopleName(@szGet[0], @iLenGet);
      showmessage(trim(string(szGet)));

      zeromemory(@szGet[0], 70);
      GetPeopleSex(@szGet[0], @iLenGet);
      showmessage(string(szGet));

      zeromemory(@szGet[0], 70);
      GetPeopleNation(@szGet[0], @iLenGet);
      showmessage(string(szGet));

      zeromemory(@szGet[0], 70);
      GetPeopleBirthday(@szGet[0], @iLenGet);
      showmessage(string(szGet));

      zeromemory(@szGet[0], 70);
      GetPeopleAddress(@szGet[0], @iLenGet);
      showmessage(trim(string(szGet)));

      zeromemory(@szGet[0], 70);
      GetPeopleIDCode(@szGet[0], @iLenGet);
      showmessage(string(szGet));    }

      //------------------------------------
      
      iniFileName:=ExtractFilePath(Application.ExeName) + 'ICINIT.INI';
      iFileHandle := FileOpen(ExtractFilePath(Application.ExeName) +'wz.txt', fmOpenRead);
      iFileLength := FileSeek(iFileHandle,0,2);
      FileSeek(iFileHandle,0,0);
      Buffer := PWideChar(AllocMem(iFileLength +2));
      FileRead(iFileHandle, Buffer^, iFileLength);
      FileClose(iFileHandle);
      sWZ:=WideChartostring(buffer);

       EditName.Text:=copy(sWZ,1,15);  //姓名

       delete(sWZ,1,15);
       if (copy(sWZ,1,1)='1') then     //性别
          EdSex.Text:='男'
       else
          EdSex.Text:='女';

       delete(sWZ,1,1);                //民族
       sDisp:='';
       sDisp:=copy(sWZ,1,2);
       GetPrivateProfileStringA('PEOPLE',PChar(sDisp),'',ChPeople,33,PChar(iniFileName));
       EdMZ.Text:= string(ChPeople);

       delete(sWZ,1,2);                //出生
       sDisp:='';
       ChangeDateChina(copy(sWZ,1,8),sDisp);
       EdBday.Text:=sDisp;

       delete(sWZ,1,8);               //住址
       EdAddr.Text:=copy(sWZ,1,35);

       delete(sWZ,1,35);              //身份证号
       EdID.Text:=copy(sWZ,1,18);

       delete(sWZ,1,18);              //签发机关
       EdDep.Text:=copy(sWZ,1,15);

       sDisp:='';                     //有效期限
       delete(sWZ,1,15);
       ChangeDateDot(copy(sWZ,1,16),sDisp);
       EdVld.Text:=sDisp;

       delete(sWZ,1,16);              //最新住址
       EdNewAddr.Text:=copy(sWZ,1,35);

                                     //显示照片
       Image2.Picture.LoadFromFile(ExtractFilePath(Application.ExeName) +'zp.bmp');
       Image2.Visible := TRUE;

       windows.Beep(2800,200);
       StatusBar1.Panels.Items[1].Text := '身份信息显示完毕';
       self.Update;
    finally
       FreeMem(Buffer);
    end;

    Button49.Enabled:=true;
    Btnclose.Enabled:=true;
    TimerRedo.Enabled:=true;
    //--------------------------------------------------------------------显示完毕

end;

procedure TForm2.ChangeDateChina( sInput:string; var sOutput:string );
var
   sYY, sMM, sDD :string;
begin
     //如 19760816
     sYY:=copy(sInput,1,4);
     sMM:=copy(sInput,5,2);
     sDD:=copy(sInput,7,2);
     sOutput:=Format('%s%s%s%s%s%s',[sYY,'年',sMM,'月',sDD,'日']);
end;

procedure TForm2.ChangeDateDot( sInput:string; var sOutput:string );
var
   sYY, sMM, sDD :string;
   sYY2, sMM2, sDD2 :string;
begin
     // 2004070120240701
     sYY:=copy(sInput,1,4);
     sMM:=copy(sInput,5,2);
     sDD:=copy(sInput,7,2);

     sYY2:=copy(sInput,9,4);
     sMM2:=copy(sInput,13,2);
     sDD2:=copy(sInput,15,2);
     sOutput:=Format('%s%s%s%s%s',[sYY,'.',sMM,'.',sDD]);
     sOutput:=sOutput+'-'+Format('%s%s%s%s%s',[sYY2,'.',sMM2,'.',sDD2]);
end;

procedure TForm2.Button50Click(Sender: TObject);
begin
    isStoped:=true;
    EmptyEditCV;
    Button49.Enabled:=true;
    Btnclose.Enabled:=true;
    TimerRedo.Enabled:=false;
end;

procedure TForm2.EmptyEditCV;
begin
    EditName.Clear;
    EdSex.Clear;
    EdMZ.Clear;
    EdBday.Clear;
    EdAddr.Clear;
    EdID.Clear;
    EdDep.Clear;
    EdVld.Clear;
    EdNewAddr.Clear;
    Image2.Visible:=false;
end;

procedure TForm2.BtncloseClick(Sender: TObject);
begin
   close;
end;

procedure TForm2.FormKeyDown(Sender: TObject; var Key: Word;
  Shift: TShiftState);
begin
    if key=VK_ESCAPE then
       Button50Click(sender); 
end;

procedure TForm2.FormShow(Sender: TObject);
var
  S:AnsiString;
begin
   S := FormatDateTime('yyyy"年"mm"月"dd"日"   ddd', Now);
   StatusBar1.Panels.Items[0].Text :=  S;
   StatusBar1.Panels.Items[1].Text := '等待测试';
   StatusBar1.Panels.Items[2].Text := FormatDateTime('tt', Now);
end;

procedure TForm2.Timer1Timer(Sender: TObject);
var
    S:AnsiString;
begin
    StatusBar1.Panels.Items[2].Text := FormatDateTime('tt', Now);
    S := FormatDateTime('yyyy"年"mm"月"dd"日"   ddd', Now);
    StatusBar1.Panels.Items[0].Text :=  S;
    self.Update;
end;

end.
