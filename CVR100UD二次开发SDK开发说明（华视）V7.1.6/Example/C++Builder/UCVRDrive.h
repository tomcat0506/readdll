//---------------------------------------------------------------------------

#ifndef UCVRDriveH
#define UCVRDriveH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>

//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TGroupBox *GroupBox1;
        TImage *Image1;
        TLabel *Label1;
        TEdit *Edit1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TEdit *Edit3;
        TEdit *Edit4;
        TLabel *Label4;
        TEdit *Edit5;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *Edit6;
        TEdit *Edit7;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *Edit8;
        TLabel *Label9;
        TComboBox *CbBPort;
        TLabel *Label10;
        TComboBox *CbBBaud;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall CbBPortKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
        void __fastcall PicToStandardSize(AnsiString sPhotoFile);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
