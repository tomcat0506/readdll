program PMain;

uses
  Forms,
  CVRDLL in 'CVRDLL.pas',
  UCVR in 'UCVR.pas' {Form2};

{$R *.res}

begin
  Application.Initialize;  
  Application.CreateForm(TForm2, Form2);
  Application.Title:='���ڻ��Ӷ���֤��ʾ����';
  Application.Run;
end.
