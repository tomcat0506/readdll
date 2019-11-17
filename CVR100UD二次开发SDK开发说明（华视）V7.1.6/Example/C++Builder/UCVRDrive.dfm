object Form1: TForm1
  Left = 437
  Top = 108
  Width = 411
  Height = 482
  Caption = #27979#35797#31243#24207
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label9: TLabel
    Left = 24
    Top = 34
    Width = 36
    Height = 13
    Caption = #31471#21475#65306
  end
  object Label10: TLabel
    Left = 144
    Top = 34
    Width = 36
    Height = 13
    Caption = #36895#29575#65306
  end
  object Button1: TButton
    Left = 24
    Top = 88
    Width = 75
    Height = 25
    Caption = #25171#24320
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 296
    Top = 88
    Width = 75
    Height = 25
    Caption = #20851#38381
    Enabled = False
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 168
    Top = 88
    Width = 75
    Height = 25
    Caption = #35835#20449#24687
    Enabled = False
    TabOrder = 2
    OnClick = Button3Click
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 152
    Width = 345
    Height = 273
    Caption = #36523#20221#20449#24687
    TabOrder = 3
    object Image1: TImage
      Left = 232
      Top = 16
      Width = 105
      Height = 105
      Transparent = True
    end
    object Label1: TLabel
      Left = 9
      Top = 32
      Width = 36
      Height = 13
      Caption = #22995#21517#65306
    end
    object Label2: TLabel
      Left = 9
      Top = 64
      Width = 36
      Height = 13
      Caption = #24615#21035#65306
    end
    object Label3: TLabel
      Left = 10
      Top = 98
      Width = 36
      Height = 13
      Caption = #29983#26085#65306
    end
    object Label4: TLabel
      Left = 10
      Top = 136
      Width = 75
      Height = 13
      Caption = #36523#20221#35777#21495#30721#65306' '
    end
    object Label5: TLabel
      Left = 11
      Top = 168
      Width = 36
      Height = 13
      Caption = #22320#22336#65306
    end
    object Label6: TLabel
      Left = 10
      Top = 202
      Width = 48
      Height = 13
      Caption = #26377#25928#26399#65306
    end
    object Label7: TLabel
      Left = 10
      Top = 234
      Width = 60
      Height = 13
      Caption = #31614#21457#26426#20851#65306
    end
    object Label8: TLabel
      Left = 268
      Top = 200
      Width = 36
      Height = 13
      Caption = #27665#26063#65306
    end
    object Edit1: TEdit
      Left = 51
      Top = 30
      Width = 166
      Height = 21
      ReadOnly = True
      TabOrder = 0
    end
    object Edit2: TEdit
      Left = 51
      Top = 62
      Width = 46
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 51
      Top = 94
      Width = 166
      Height = 21
      ReadOnly = True
      TabOrder = 2
    end
    object Edit4: TEdit
      Left = 87
      Top = 134
      Width = 250
      Height = 21
      ReadOnly = True
      TabOrder = 3
    end
    object Edit5: TEdit
      Left = 51
      Top = 166
      Width = 286
      Height = 21
      ReadOnly = True
      TabOrder = 4
    end
    object Edit6: TEdit
      Left = 67
      Top = 198
      Width = 198
      Height = 21
      ReadOnly = True
      TabOrder = 5
    end
    object Edit7: TEdit
      Left = 75
      Top = 230
      Width = 262
      Height = 21
      ReadOnly = True
      TabOrder = 6
    end
    object Edit8: TEdit
      Left = 307
      Top = 198
      Width = 30
      Height = 21
      ReadOnly = True
      TabOrder = 7
    end
  end
  object CbBPort: TComboBox
    Left = 64
    Top = 32
    Width = 73
    Height = 21
    ItemHeight = 13
    ItemIndex = 0
    TabOrder = 4
    Text = 'COM1'
    OnKeyPress = CbBPortKeyPress
    Items.Strings = (
      'COM1'
      'COM2'
      'COM3'
      'COM4'
      'COM5'
      'COM6'
      'COM7'
      'COm8')
  end
  object CbBBaud: TComboBox
    Left = 184
    Top = 32
    Width = 73
    Height = 21
    ItemHeight = 13
    ItemIndex = 3
    TabOrder = 5
    Text = '115200'
    OnKeyPress = CbBPortKeyPress
    Items.Strings = (
      '9600'
      '14400'
      '19200'
      '115200')
  end
end
