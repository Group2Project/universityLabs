object Form1: TForm1
  Left = 185
  Top = 141
  Width = 390
  Height = 450
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 24
    Top = 16
    Width = 217
    Height = 129
    TabOrder = 0
    object Label1: TLabel
      Left = 24
      Top = 24
      Width = 69
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086' '#1089#1090#1088#1086#1082':'
    end
    object Label2: TLabel
      Left = 8
      Top = 56
      Width = 87
      Height = 13
      Caption = #1050#1086#1083'-'#1074#1086' '#1089#1090#1086#1083#1073#1094#1086#1074':'
    end
    object CSpinEdit1: TCSpinEdit
      Left = 104
      Top = 16
      Width = 89
      Height = 22
      TabOrder = 0
    end
    object CSpinEdit2: TCSpinEdit
      Left = 104
      Top = 48
      Width = 89
      Height = 22
      TabOrder = 1
    end
    object Button1: TButton
      Left = 56
      Top = 88
      Width = 75
      Height = 25
      Caption = #1042#1074#1086#1076
      TabOrder = 2
      OnClick = Button1Click
    end
  end
  object StringGrid1: TStringGrid
    Left = 24
    Top = 152
    Width = 329
    Height = 249
    ColCount = 1
    FixedCols = 0
    RowCount = 1
    FixedRows = 0
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goTabs]
    TabOrder = 1
  end
  object Button4: TButton
    Left = 256
    Top = 96
    Width = 89
    Height = 33
    Caption = #1042#1099#1093#1086#1076
    TabOrder = 2
    OnClick = Button4Click
  end
  object Panel2: TPanel
    Left = 256
    Top = 16
    Width = 89
    Height = 73
    TabOrder = 3
    object Button2: TButton
      Left = 0
      Top = 0
      Width = 89
      Height = 33
      Caption = #1053#1072#1081#1090#1080
      TabOrder = 0
      OnClick = Button2Click
    end
    object Button3: TButton
      Left = 0
      Top = 40
      Width = 89
      Height = 33
      Caption = #1057#1073#1088#1086#1089
      TabOrder = 1
      OnClick = Button3Click
    end
  end
end
